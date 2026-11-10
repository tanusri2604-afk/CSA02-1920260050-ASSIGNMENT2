#include <stdio.h>

int main(void)
{
    double balance, rate, repayment;
    double interest, payment, totalInterest = 0;

    int month = 0;
    int limit = 360;

    printf("Enter loan amount: ");
    scanf("%lf", &balance);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter monthly repayment: ");
    scanf("%lf", &repayment);

    if (balance <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    rate = rate / 100.0;

    if (repayment <= balance * rate)
    {
        printf("Loan cannot be repaid with this amount.\n");
        return 0;
    }

    printf("\nMonth\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.01)
    {
        if (month >= limit)
        {
            printf("Maximum repayment limit reached.\n");
            break;
        }

        month++;

        interest = balance * rate;
        totalInterest += interest;

        balance += interest;

        if (balance < repayment)
            payment = balance;
        else
            payment = repayment;

        balance -= payment;

        if (balance < 0.01)
            balance = 0;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
            month, interest, payment, balance);
    }

    if (balance == 0)
    {
        printf("\nLoan fully repaid!");
        printf("\nTotal months = %d", month);
        printf("\nTotal interest = Rs. %.2f\n", totalInterest);
    }

    return 0;
}