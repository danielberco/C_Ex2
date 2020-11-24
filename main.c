#include "myBank.h"
#include <stdio.h>

int main() {
    char action;
    int i=0;

    while (!i) {
        printf("Hello and welcome to the bank, please choose an action :\n");
        printf("O - Open new account\n B- Check account balance\n D - Make a deposit\n W - Make a withdrawal\n C - Close the account\n I - Add an interest\n P - print information\n E - Exit the bank\n");

        int acNum;
        double amount =0, deposit =0, withdraw =0 , rate=0;

        if(scanf(" %c", &action) != 1) {
            printf("Error has been made, please try again\n");
        }
        else {
            switch (action) {
                case 'O':
                    printf("\n Please insert your amount in the acount :");
                    scanf("%lf",&amount);
                    openAcount(amount);
                    break;
                case 'B' :
                    printf("\nEnter your account number:\n");
                    scanf("%d", &acNum);
                    balance(acNum);
                    break;

                case 'D' :
                    printf("\nEnter your account number:\n");
                    scanf("%d", &acNum);
                    printf("\nEnter the amount would you like to deposit\n ");
                    scanf("%lf",&deposit);
                    depositB(acNum,deposit);
                    break;

                case 'W' :
                    printf("\nEnter your account number:\n");
                    scanf("%d", &acNum);
                    printf("\nEnter the amount would you like to withdraw\n ");
                    scanf("%lf",&withdraw);
                    withdrawB(acNum,withdraw);
                    break;

                case 'C' :
                    printf("\nEnter your account number:\n");
                    scanf("%d", &acNum);
                    closeAc(acNum);
                    break;

                case 'I' :
                    printf("\nEnter your rate of the interest:\n");
                    scanf("%d", &rate);
                    addInterest(rate);
                    break;

                case 'P':
                    printAc();
                    break;

                case 'E' :
                    exitAll();
                    i = 1;
                    break;
                default:
                    printf("Error has been made , please try again\n");

            }
        }
    }
    return 0;
}
