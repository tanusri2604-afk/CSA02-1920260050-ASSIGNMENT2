#include <stdio.h>

int calls = 0;

int verify_card(int disability)
{
    calls++;
    return disability;
}

int main(void)
{
    int senior, eligible, disability;
    int result;
    int i;
    int seniorFirst = 0;
    int disabilityFirst = 0;
    int bitwiseCalls = 0;

    for (i = 0; i < 1000; i++)
    {
        senior = (i % 2);
        eligible = (i % 3 == 0);
        disability = (i % 10 == 0);   
        calls = 0;

        result = (senior && eligible) || verify_card(disability);

        seniorFirst += calls;

     
        calls = 0;

        result = verify_card(disability) || (senior && eligible);

        disabilityFirst += calls;
        calls = 0;

        result = (senior & eligible) || verify_card(disability);

        bitwiseCalls += calls;
    }

    printf("Senior first calls = %d\n", seniorFirst);
    printf("Disability first calls = %d\n", disabilityFirst);
    printf("Bitwise operator calls = %d\n", bitwiseCalls);

    return 0;
}