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
	void Company::setCompanyName(std::string newName)
	{
		companyName = newName;
	}
	std::string Company::getCompanyName()
	{
		return companyName;
	}
	void Company::setCompanyAddress(std::string newAddress)
	{
		companyAddress = newAddress;
	}
	std::string Company::getCompanyAddress()
	{
		return companyAddress;
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
