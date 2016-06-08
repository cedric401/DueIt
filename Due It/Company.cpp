#include "Company.h"
#include <string>
#include <sstream>


namespace DueItModel
{
	Company::Company(std::string nameOfCompany)
	{
		//readEntry(nameOfCompany);
		companyName = nameOfCompany;
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
	}
	std::string Company::getCompanyName()
	{
		return std::string();
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
