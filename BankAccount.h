#ifndef BANKACCOUNT
#define BANKACCOUNT
#include <string>

class BankAccount{
private:
	std::string accountHolder;
	int accountNumber;
	double balance;
public:
	BankAccount();
	BankAccount(std::string str, int number, double bal);
	BankAccount(const BankAccount& other); 
	~BankAccount();
	void deposit(double amount);
	bool withdraw(double amount);
	void display();
	int getaccountNumber();
	std::string getaccountHolder();
	double getbalance();
};

#endif
