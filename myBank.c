#include "myBank.h"
#include <stdio.h>
#include <rpcndr.h>

#define AR_R 50 //array rows
#define AR_C 2 //array columns

#define AC_MIN 901
#define AC_MAX 950
double bankAc [AR_R][AR_C] = {0};

double round (double num) {
    return (int)(num*100)/100.;
}



void openAcount (double amount) {
    int count =0;
   for (int i=0; i<AR_R;i++) {
       count++;
       if (bankAc[i][0] == 0) {
           if (amount <=0 ){
               printf("Invalid number,cannot open account");
           }
           else {
               bankAc[i][0] =1;
               bankAc[i][1] = round(amount);
               printf("New account has been added, account number is : %d \n", AC_MIN + i);
           }
       }
       else {
           printf("Error has been made, please try again");
       }
       break;
   }
   if (count == AR_R)
       printf( "Error has been made : there is no space for more account , please contact the bank \n");

}





void balance (int acNum) {
    if (acNum <AC_MIN || acNum > AC_MAX) {
        printf("Error, wrong account number \n");
    }
    else {
        acNum =acNum - AC_MIN;
        if (bankAc[acNum][0] == 0) {
            printf("The account is closed for now");
        }
        else {
            printf("The balance of the account number is : %0.2d\n",AC_MIN+acNum,bankAc[acNum][1]);
        }
    }
}

void depositB (int acNum,double amount) {
    if (acNum <AC_MIN || acNum > AC_MAX) {
        printf("Error, wrong account number \n");
    }
    else {
        acNum = acNum -AC_MIN;
        if (bankAc[acNum][0] == 0)
            printf("Cannot deposit ,the account is closed.\n");
        else {
            if (amount > 0) {
                bankAc[acNum][1] += round(amount);
                printf("Deposit complete, your updated balance is: %0.21lf\n", bankAc[acNum][1]);
            }
            else {
                printf("Invalid amount, cannot deposit\n");
            }
        }
    }
}

void withdrawB (int acNum,double amount) {
    if (acNum <AC_MIN || acNum > AC_MAX) {
        printf("Error, wrong account number \n");
    }
    else {
        acNum = acNum -AC_MIN;
        if ( bankAc[acNum][0] == 0) {
            printf("Cannot deposit ,the account is closed.\n");
        }
        else {
            amount = bankAc[acNum][1] -amount;
            if (amount >=0) {
                bankAc[acNum][1] =round(amount);
                printf("Withdraw complete ,your updated balance is: %0.21lf\n", bankAc[acNum][1]);
            }
            else {
                printf("Invalid amount, cannot deposit\n");
            }
        }
    }
}

void closeAc (int acNum) {
    if (acNum <AC_MIN || acNum > AC_MAX) {
        printf("Error, wrong account number \n");
    }

    else {
        int index = acNum -AC_MIN;
        if (bankAc[acNum][0] == 0) {
            printf("Cannot deposit ,the account is closed.\n");
        }
        else {
            bankAc[index][0] = 0; // closing the account
            bankAc[index][1] = 0;
            printf("Account is closed, account number is :", acNum);
        }
    }
}

void addInterest (double rate) {
    if (rate < 0) {
        printf("Error, wrong interest");
    }
    else {
        for (int i=0; i<AR_R; i++) {
            if (bankAc[i][0] == 1) {
                bankAc[i][1] *= 1+ (rate/100.);
                bankAc[i][1] = round(bankAc[i][1]);
            }
        }
    }
}

void printAc() {
    for (int i=0; i<AR_R;i++) {
        if (bankAc[i][0] == 1) {
            printf("The balance of the account number is : %0.2d\n",AC_MIN+i,bankAc[i][1]);
        }
    }
}

void exitAll() {
    for (int i=0; i<AR_R;i++) {
        bankAc[i][0] = 0; // closing the account
        bankAc[i][1] = 0;
    }
}







