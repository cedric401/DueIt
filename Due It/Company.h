#pragma once
#include <string>
namespace DueItModel
{
	class Company
	{
	public:
		Company(std::string nameOfCompany);
		Company(std::string nameOfCompany = "", std::string address = "");
		~Company();
		std::string toString();
		void setCompanyName(const std::string& newName);
		std::string getCompanyName() const;
		void setCompanyAddress(const std::string& newAddress);
		std::string getCompanyAddress() const;
		bool operator==(const Company& rhs);
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(std::string name);

	private:
		std::string companyName;
		std::string companyAddress;
	};
};

