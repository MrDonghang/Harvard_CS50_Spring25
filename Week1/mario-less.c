#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);

int main(void)
{
    // Set the height variable
    int height;
    // Use do-while loop to ensure the input is an integer
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Print the pyramid
    print_pyramid(height);
}

void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print the blank spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Print the blocks
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
