#include <stdlib.h>
#include <iostream>
#include "MySQL_BillsDBManipulator.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


#define HOST "localhost:3306"
#define USER "root"
#define PASSWORD "mysql"
#define DB "blank"

using namespace std;

MySQL_BillsDBManipulator::MySQL_BillsDBManipulator()
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	stmt = con->createStatement();
	stmt->execute("USE " DB);
	try
	{
		stmt->execute("INSERT INTO Company(companyName, companyAddress) VALUES ('cbf', '325 side street')");
	}
	catch (sql::SQLException &e) 
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() <<
			" )" << endl;
	}

	res = stmt->executeQuery("SELECT companyName, companyAddress FROM Company ORDER BY companyAddress ASC");
	while (res->next())
	{
		cout << "Company: " << res->getString("companyName").c_str();
		cout << ", Address: " << res->getString("companyAddress").c_str() << "\n";
	}

	prep = con->prepareStatement("INSERT INTO Company(companyName, companyAddress) VALUES (?, ?)");
	try
	{
		prep->setString(1, "mcdonalds");
		prep->setString(2, "123 main street");
		prep->execute();
	}
	catch (sql::SQLException e)
	{
		cout << "ERROR: ";
		cout << e.getErrorCode() << "\n";
	}

	delete prep;
	delete res;
	delete stmt;
	delete con;
}

MySQL_BillsDBManipulator::~MySQL_BillsDBManipulator()
{
}

void MySQL_BillsDBManipulator::addCompany(Company aCompany)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	string aName = aCompany.getCompanyName().substr(0, 100);
	string anAddress = aCompany.getCompanyAddress().substr(0, 200);

	prep = con->prepareStatement("INSERT INTO Company(companyName, companyAddress) VALUES (?, ?)");
	try
	{
		prep->setString(1, aName);
		prep->setString(2, anAddress);
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}

	delete con;
	delete prep;
}

void MySQL_BillsDBManipulator::deleteCompany(Company aCompany)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("DELETE FROM Company WHERE companyName=?");
	try
	{
		prep->setString(1, aCompany.getCompanyName());
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	/*The MySQL Job and Payment tables are set to on delete cascade, so any entries with the deleted company as their foreign key 
	 *will be deleted as well, we don't need to handle it here.
	*/
	delete prep;
	delete con;
}

Company MySQL_BillsDBManipulator::readCompany(std::string aName)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;
	Company aCompany = Company();

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("SELECT companyName, companyAddress FROM Company WHERE companyName=?");
	try
	{
		prep->setString(1, "aName");
		res = prep->executeQuery();
		if (res->next())
		{
			aCompany.setCompanyName(res->getString("companyName").c_str());
			aCompany.setCompanyAddress(res->getString("companyAddress").c_str());
		}
		//else
		//{
			//The Company object retains its default values assigned at instantiation - check for this when method is used to see if nothing is returned.
		//}
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	return aCompany;

	delete prep;
	delete res;
	delete con;
}

void MySQL_BillsDBManipulator::updateCompany(Company aCompany, std::string aName)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("UPDATE Company SET companyName=?, companyAddress=? WHERE companyName=?");
	try
	{
		prep->setString(1, aCompany.getCompanyName());
		prep->setString(2, aCompany.getCompanyAddress());
		prep->setString(3, aName);
		prep->execute();
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	/*The MySQL Job and Payment tables are set to on update cascade, so any entries with the updated company as their foreign key
	*will be updated as well, we don't need to handle it here.
	*/

	delete prep;
	delete con;
}

void MySQL_BillsDBManipulator::addJob(Job aJob)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	string aName = aJob.getEmployer().getCompanyName().substr(0, 100);

	prep = con->prepareStatement("INSERT INTO Job(startTime, endTime, hours, rate, jobDay, jobMonth, jobYear, isRepeating, daysInterval, monthsInterval, companyName) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	try
	{
		prep->setInt(1, aJob.getTime());
		prep->setInt(2, aJob.getEnd());
		prep->setInt(3, aJob.getHours());
		prep->setDouble(4, aJob.getRate());
		prep->setInt(5, aJob.getDay());
		prep->setInt(6, aJob.getMonth());
		prep->setInt(7, aJob.getYear());
		prep->setBoolean(8, aJob.getIsRepeating());
		prep->setInt(9, aJob.getDaysToRepeat());
		prep->setInt(10, aJob.getMonthsToRepeat());
		prep->setString(11, aName);
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}

	delete con;
	delete prep;
}

void MySQL_BillsDBManipulator::deleteJob(Job aJob)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("DELETE FROM Job WHERE id=?");
	try
	{
		prep->setInt(1, aJob.getRowID());
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	delete prep;
	delete con;
}

Job* MySQL_BillsDBManipulator::readJob(int rowID)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;
	Job * aJob = nullptr;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("SELECT * FROM Job WHERE id=?");
	try
	{
		prep->setInt(1, rowID);
		res = prep->executeQuery();
		if (res->next())
		{
			aJob = new Job(
			res->getInt("startTime"),
			res->getInt("endTime"),
			res->getInt("jobDay"),
			res->getInt("jobMonth"),
			res->getInt("jobYear"),
			res->getBoolean("isRepeating"),
			res->getInt("daysInterval"),
			res->getInt("monthsInterval"),
			readCompany(res->getString("companyName")),
			res->getInt("hours"),
			res->getDouble("rate"));
		}
		//else aJob stays nullptr and is returned as such, must be checked for when using this method
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	return aJob;

	delete prep;
	delete res;
	delete con;
}

void MySQL_BillsDBManipulator::updateJob(Job aJob)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);
	string aName = aJob.getEmployer().getCompanyName().substr(0, 100);

	prep = con->prepareStatement("UPDATE Job SET startTime=?, endTime=?, hours=?, rate=?, jobDay=?, jobMonth=?, jobYear=?, isRepeating=?, daysInterval=?, monthsInterval=?, companyName=? WHERE id=?");
	try
	{
		prep->setInt(1, aJob.getTime());
		prep->setInt(2, aJob.getEnd());
		prep->setInt(3, aJob.getHours());
		prep->setDouble(4, aJob.getRate());
		prep->setInt(5, aJob.getDay());
		prep->setInt(6, aJob.getMonth());
		prep->setInt(7, aJob.getYear());
		prep->setBoolean(8, aJob.getIsRepeating());
		prep->setInt(9, aJob.getDaysToRepeat());
		prep->setInt(10, aJob.getMonthsToRepeat());
		prep->setString(11, aName);
		prep->setInt(12, aJob.getRowID());
		prep->execute();
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}

	delete prep;
	delete con;
}

void MySQL_BillsDBManipulator::addPayment(Payment aPayment)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	string aName = aPayment.getCompany().getCompanyName().substr(0, 100);
	string anAccntType = aPayment.getAccountType().substr(0, 40);

	prep = con->prepareStatement("INSERT INTO Payment(amount, dueTime, dueDay, dueMonth, dueYear, accountType, paidStatus, isRepeating, daysInterval, monthsInterval, companyName) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	try
	{
		prep->setDouble(1, aPayment.getAmount());
		prep->setInt(2, aPayment.getTime());
		prep->setInt(3, aPayment.getDay());
		prep->setDouble(4, aPayment.getMonth());
		prep->setInt(5, aPayment.getYear());
		prep->setString(6, anAccntType);
		prep->setBoolean(7, aPayment.getIsPaid());
		prep->setBoolean(8, aPayment.getIsRepeating());
		prep->setInt(9, aPayment.getDaysToRepeat());
		prep->setInt(10, aPayment.getMonthsToRepeat());
		prep->setString(11, aPayment.getCompany().getCompanyName());
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}

	delete con;
	delete prep;
}

void MySQL_BillsDBManipulator::deletePayment(Payment aPayment)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("DELETE FROM Payment WHERE id=?");
	try
	{
		prep->setInt(1, aPayment.getRowID());
		prep->execute();
	}
	catch (sql::SQLException &e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	delete prep;
	delete con;
}

Payment* MySQL_BillsDBManipulator::readPayment(int rowID)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;
	Payment * aPayment = nullptr;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	prep = con->prepareStatement("SELECT * FROM Payment WHERE id=?");
	try
	{
		prep->setInt(1, rowID);
		res = prep->executeQuery();
		if (res->next())
		{
			aPayment = new Payment(
				res->getInt("dueTime"),
				res->getInt("dueDay"),
				res->getInt("dueMonth"),
				res->getInt("dueYear"),
				res->getBoolean("isRepeating"),
				res->getInt("daysInterval"),
				res->getInt("monthsInterval"),
				readCompany(res->getString("companyName")),
				res->getDouble("amount"),
				res->getBoolean("paidStatus"),
				res->getString("accountType"));
		}
		//else aPayment stays nullptr and is returned as such, must be checked for when using this method
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}
	return aPayment;

	delete prep;
	delete res;
	delete con;
}

void MySQL_BillsDBManipulator::updatePayment(Payment aPayment)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);
	string aName = aPayment.getCompany().getCompanyName().substr(0, 100);
	string anAccntType = aPayment.getAccountType().substr(0, 40);

	prep = con->prepareStatement("UPDATE Payment SET amount=?, dueTime=?, dueDay=?, dueMonth=?, dueYear=?, accountType=?, paidStatus=?, isRepeating=?, daysInterval=?, monthsInterval=? companyName=? WHERE id=?");
	try
	{
		prep->setDouble(1, aPayment.getAmount());
		prep->setInt(2, aPayment.getTime());
		prep->setInt(3, aPayment.getDay());
		prep->setInt(4, aPayment.getMonth());
		prep->setInt(5, aPayment.getYear());
		prep->setString(6, anAccntType);
		prep->setBoolean(7, aPayment.getIsPaid());
		prep->setBoolean(8, aPayment.getIsRepeating());
		prep->setInt(9, aPayment.getDaysToRepeat());
		prep->setInt(10, aPayment.getMonthsToRepeat());
		prep->setString(11, aName);
		prep->setInt(12, aPayment.getRowID());
		prep->execute();
	}
	catch (sql::SQLException e)
	{
		printSQLError(__FUNCTION__, __LINE__, e.what(), e.getErrorCode(), e.getSQLState());
	}

	delete prep;
	delete con;
}

std::vector<Task> MySQL_BillsDBManipulator::retrieveTasksInRange(int startTime, int startDay, int startMonth, int startYear, int endTime, int endDay, int endMonth, int endYear)
{
	return std::vector<Task>();
}

void MySQL_BillsDBManipulator::printSQLError(const std::string& func, int line, const std::string& error, int errorCode, const std::string& state)
{
	cout << "# ERR: SQLException in " << __FILE__;
	cout << "(" << func << ") on line "
		<< line << endl;
	cout << "# ERR: " << error;
	cout << " (MySQL error code: " << errorCode;
	cout << ", SQLState: " << state <<
		" )" << endl;
}