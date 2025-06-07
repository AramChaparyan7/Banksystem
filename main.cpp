#include "BankAccount.h"
#include "BankSystem.h"

int main(){
	BankSystem bank;
	bank.addaccount("James", 100, 250.0);
	bank.addaccount("John", 101, 160.0);
	bank.displayAllAcounts();
	bank.findaccount(100)->withdraw(20);
	bank.findaccount(101)->deposit(30);
	bank.transferFunds(100, 101, 150);
	bank.displayAllAcounts();
	bank.findaccount(100)->deposit(-60);
	bank.findaccount(101)->withdraw(500);
	return 0;
}
