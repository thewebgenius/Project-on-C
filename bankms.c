// PROJECT NAME: BANK MANAGMENT SYSTEM 
// B.TECH 1ST SEMESTER 
// SECTION V
// GROUP MEMBER 
// SHIVAM KUMAR SAH 
// UJWAL 
// BRIND
// SHAMI
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function prototypes
void openAccount();
void deposit();
void withdraw();
void displayDetails();

int main() {
    int choice;

    printf("=== Bank Management System ===\n");

    do {
        printf("\n1. Open Account\n2. Deposit\n3. Withdraw\n4. Display Account Details\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                openAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayDetails();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void openAccount() {
    if (numAccounts == MAX_ACCOUNTS) {
        printf("Cannot open more accounts. Maximum limit reached.\n");
        return;
    }

    struct BankAccount newAccount;
    printf("Enter Account Holder Name: ");
    scanf("%s", newAccount.accountHolder);
    newAccount.accountNumber = numAccounts + 1;
    newAccount.balance = 0.0;

    accounts[numAccounts++] = newAccount;

    printf("Account opened successfully. Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > numAccounts) {
        printf("Invalid Account Number.\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    accounts[accNum - 1].balance += amount;

    printf("Deposit successful. Updated balance: %.2f\n", accounts[accNum - 1].balance);
}

void withdraw() {
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > numAccounts) {
        printf("Invalid Account Number.\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount > accounts[accNum - 1].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[accNum - 1].balance -= amount;
        printf("Withdrawal successful. Updated balance: %.2f\n", accounts[accNum - 1].balance);
    }
}

void displayDetails() {
    int accNum;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > numAccounts) {
        printf("Invalid Account Number.\n");
        return;
    }

    struct BankAccount acc = accounts[accNum - 1];

    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.accountHolder);
    printf("Account Balance: %.2f\n", acc.balance);
}

