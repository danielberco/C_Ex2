

#ifndef MYBANK_MYBANK_H
#define MYBANK_MYBANK_H

void openAcount (double amount);

void balance (int acNum);

void depositB (int acNum,double deposit);

void withdrawB (int acNum,double withdraw);

void closeAc (int acNum);

void addInterest (double rate);

void printAc();

void exitAll();

#endif //MYBANK_MYBANK_H
