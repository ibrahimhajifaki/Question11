#include <stdio.h>

float balance = 0.0;

void deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        printf("Deposited: %.2f\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Withdrawn: %.2f\n", amount);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}

void check_balance() {
    printf("Current Balance: %.2f\n", balance);
}

int main() {
    deposit(1000.0);
    withdraw(500.0);
    check_balance();
    return 0;
}


