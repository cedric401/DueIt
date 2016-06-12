#pragma once
#include <string>
namespace DueItModel
{
	class Company
	{
	public:
		Company(std::string nameOfCompany);
		Company(std::string nameOfCompany = "Default Value Co.", std::string address = "123 Main Street");
		~Company();
		std::string toString();
		void setCompanyName(std::string newName);
		std::string getCompanyName();
		void setCompanyAddress(std::string newAddress);
		std::string getCompanyAddress();

	private:
		std::string companyName;
		std::string companyAddress;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(std::string name);
	};
};

