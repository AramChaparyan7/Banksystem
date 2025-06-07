#ifndef BANKSYSTEM
#define BANKSYSTEM
#include "BankAccount.h"
#include <string>
#include <cstddef>

class BankSystem {
private:
	size_t size;
	BankAccount* accounts;
public:
	BankSystem();
	~BankSystem();
	void addaccount(const std::string&, int, double);
	BankAccount* findaccount(int accountnumber);
	void transferFunds(int, int, double);
	void displayAllAcounts();
};

#endif
