#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);   // Checks if a string contains only digits
char rotate(char c, int key); // Rotates a character by the given key

int main(int argc, string argv[])
{
    // Ensure the program is executed with exactly one command-line argument
    if (argc == 2 && only_digits(argv[1]))
    {
        // Convert the command-line argument (key) from string to integer
        int key = atoi(argv[1]);

        // Prompt user for plaintext input
        string plaintext = get_string("plaintext:  ");

        // Print the ciphertext label
        printf("ciphertext: ");

        // Iterate over each character in the plaintext and encrypt it
        int n = strlen(plaintext);
        for (int i = 0; i < n; i++)
        {
            printf("%c", rotate(plaintext[i], key));
        }

        // Print a newline for formatting
        printf("\n");
        return 0;
    }
    else
    {
        // Print usage message if incorrect arguments are provided
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Function to check if a string contains only digits
bool only_digits(string s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i])) // If any character is not a digit, return false
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by the given key
char rotate(char c, int key)
{
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A'; // Preserve uppercase rotation
    }
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a'; // Preserve lowercase rotation
    }
    return c; // Non-alphabetic characters remain unchanged
}
