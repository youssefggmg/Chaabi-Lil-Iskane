#include <stdio.h>
#include <math.h>
// a global structur that holds the varaibeles that I'm going to need inside and out side the fuction
struct Loan {
    double amount;
    double interest_rate;
    int repayment_period;
};

double calculate_monthly_payment(struct Loan loan) {
    // Conver to monthly interest rate

    double monthlyInteRestrRte = loan.interest_rate / 12 / 100;
    // Convert repayment periodto months

    int num_payments = loan.repayment_period * 12;

    // Calculate monthly payment using the formula for loan amortization

    double monthly_payment = (loan.amount * monthlyInteRestrRte) / (1 - pow(1 + monthlyInteRestrRte, -num_payments));

    return monthly_payment;
}

int main() {
    int attempts = 0;
    int max_attempts = 10;
    
    while (attempts < max_attempts) {
        struct Loan loan;
        
        printf("Enter the loan amount: ");
        scanf("%lf", &loan.amount);
        
        printf("Enter the annual interest rate (between 3%% and 7%%): ");
        scanf("%lf", &loan.interest_rate);
        
        printf("Enter the repayment period in years (minimum 5 years): ");
        scanf("%d", &loan.repayment_period);
        
        if (loan.repayment_period < 5) {
            printf("Repayment period must be 5 years or more.\n");
            continue;
        }
        
        if (loan.interest_rate < 3 || loan.interest_rate > 7) {
            printf("Interest rate must be between 3%% and 7%%.\n");
            continue;
        }
        
        double monthly_payment = calculate_monthly_payment(loan);
        printf("Estimated monthly payment: $%.2f\n", monthly_payment);
        
        attempts++;
    }

    printf("Maximum number of attempts reached.\n");

    return 0;
}