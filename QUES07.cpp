#include <stdio.h>
unsigned long checks;
int original_prime(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}


int improved_prime(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}


int main(void)
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    unsigned long original_count;
    unsigned long improved_count;

    int original_result, improved_result;

    printf("PRIME NUMBER OPTIMIZATION\n");
    printf("-------------------------\n");

    printf("Number\tOriginal\tImproved\n");

    for (int i = 0; i < 4; i++)
    {
        original_result = original_prime(numbers[i]);
        original_count = checks;

        improved_result = improved_prime(numbers[i]);
        improved_count = checks;

        printf("%lu\t%lu\t\t%lu\n",
               numbers[i],
               original_count,
               improved_count);

        if (original_result == improved_result)
            printf("Both results: %s\n\n",
                   original_result ? "Prime" : "Not Prime");
        else
            printf("Result mismatch!\n\n");
    }

    return 0;
}