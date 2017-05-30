#include <stdio.h>
#include <cs50.h>

float change;
int cents;
int coins;

int main(void)
{
    do
    {
        printf("How much change is owed: ");
        change = get_float();
    }
    while (change < 0.00);
    
    cents = change * 100;
    
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    
    printf("%i\n", coins);
}