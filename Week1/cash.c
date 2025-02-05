#include <cs50.h>
#include <stdio.h>

void calculate_coin(int n);

int main(void)
{
    // Set the initial change
    int change;
    // Repeat until receive a valid value
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    // Run the function
    calculate_coin(change);
}

void calculate_coin(int n)
{
    // Set the initial value
    // Total coins
    int num = 0;
    // Temporary coins
    int coins = 0;
    // Left change
    int left = n;
    // Calculate how many coins are needed separately
    if (left >= 25)
    {
        coins = left / 25;
        num += coins;
        left -= coins * 25;
    }
    if (left >= 10)
    {
        coins = left / 10;
        num += coins;
        left -= coins * 10;
    }
    if (left >= 5)
    {
        coins = left / 5;
        num += coins;
        left -= coins * 5;
    }
    num += left;

    // Print how many coins are needed
    printf("%d\n", num);
}
