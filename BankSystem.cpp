#include <iostream>
#include "BankSystem.h"

BankSystem::BankSystem() : accounts{nullptr} {}

BankSystem::~BankSystem(){
	if(accounts){
		delete[] accounts;
	}
}

void BankSystem::addaccount(const std::string& name, int accountnumber, double InitialBalance){
	++size;
	BankAccount* tmp = accounts;
	accounts = new BankAccount[size];
	for(int i = 0; i < size - 1; ++i){
		accounts[i] = tmp[i];
	}
	BankAccount newacc(name, accountnumber, InitialBalance);
	accounts[size - 1] = newacc;
	delete[] tmp;
	tmp = nullptr;
}

BankAccount* BankSystem::findaccount(int accountnumber){
	for(int i = 0; i < size; ++i){
		if(accounts[i].getaccountNumber() == accountnumber){
			return accounts+i;
		}
	}
	return nullptr;
}

void BankSystem::transferFunds(int sender, int reciever, double amount){
	if(amount < 0){
		std::cout << "amount is negativ " <<std::endl;
		return;
	}
	BankAccount* ptr = findaccount(sender);
	BankAccount* ptr2 = findaccount(reciever);
	if(!ptr || !ptr2) {
		return;
	}
	if(ptr->withdraw(amount)){
		ptr2->deposit(amount);
		return;
	}
	std::cout << "can't transfer" << std::endl;
}

void BankSystem::displayAllAcounts(){
	for(int i = 0; i < size; ++i){
		accounts[i].display();
	}
}
