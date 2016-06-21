#include "Company.h"
#include <string>
#include <sstream>


namespace DueItModel
{
	Company::Company(std::string nameOfCompany)
	{
		readEntry(nameOfCompany);
	}

	Company::Company(std::string nameOfCompany, std::string address)
	{
		companyName = nameOfCompany;
		companyAddress = address;
	}

	Company::~Company()
	{
	}
	std::string Company::toString()
	{
		return "Company: " + companyName;
	}
	void Company::setCompanyName(const std::string& newName)
	{
		companyName = newName;
	}
	std::string Company::getCompanyName() const
	{
		return companyName;
	}
	void Company::setCompanyAddress(const std::string& newAddress)
	{
		companyAddress = newAddress;
	}
	std::string Company::getCompanyAddress() const
	{
		return companyAddress;
	}
	bool Company::operator==(const Company & rhs)
	{
		if (companyName == rhs.getCompanyName() && companyAddress == rhs.getCompanyAddress())
		{
			return true;
		}
		return false;
	}
	void Company::createEntry()
	{
	}
	void Company::deleteEntry()
	{
	}
	void Company::updateEntry()
	{
	}
	void Company::readEntry(std::string name)
	{
	}
};
