#include <string>
#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount() : accountHolder{"Unknown"}, accountNumber{0}, balance{0.0}{}
BankAccount::BankAccount(std::string str, int number, double bal) : accountHolder{str}, accountNumber{number}, balance{bal}{}
BankAccount::BankAccount(const BankAccount& other) : accountHolder{other.accountHolder}, accountNumber{other.accountNumber}, balance{other.balance} {
}

void BankAccount::deposit(double amount){
	if(amount<0){
		std::cout << "can't deposit negative number" << std::endl;
		return;
	}
	balance += amount;
}

bool BankAccount::withdraw(double amount){
    if(amount<0){
		std::cout << "amount is negative number" << std::endl;
		return false;
	}
	if(balance < amount){
		std::cout << "not enught balance" << std::endl;
		return false;
	}
	balance -= amount;
	return true;
}

void BankAccount::display(){
	std::cout << "acount holder is " << accountHolder << " account number is  " << accountNumber << " account balance is " << balance << std::endl;
}

int BankAccount::getaccountNumber(){
	return accountNumber;
}

std::string BankAccount::getaccountHolder(){
	return accountHolder;
}

double BankAccount::getbalance(){
	return balance;
}

BankAccount::~BankAccount(){
	accountHolder='\0';
	accountNumber=0;
	balance=0.0;
}
