#pragma once
#include <string>
namespace DueItModel
{
	class Company
	{
	public:
		Company(std::string nameOfCompany = "Default Value Co.");
		~Company();
		std::string toString();
		void setCompanyName(std::string newName);
		std::string getCompanyName();

	private:
		std::string companyName;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(std::string name);
	};
};

