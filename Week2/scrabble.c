#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to calculate the Scrabble score of a given string
int calculate_scores(string s);
// Function to compare scores of two players and determine the winner
void comparison(string s1, string s2);

int main(void)
{
    // Prompting both players for input words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Compare the scores of both players
    comparison(player1, player2);
}

// Function to compute the score of a given string based on Scrabble letter values
int calculate_scores(string s)
{
    // Scrabble letter values corresponding to A-Z
    int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    int n = strlen(s); // Get the length of the input string

    for (int i = 0; i < n; i++)
    {
        // Only process alphabetic characters
        if (isalpha(s[i]))
        {
            char c = toupper(s[i]); // Convert to uppercase to ensure consistency
            int rank = c - 'A';     // Map 'A'-'Z' to 0-25 index range
            score += scores[rank];  // Add the corresponding letter score
        }
    }
    return score;
}

// Function to compare two players' scores and determine the winner
void comparison(string s1, string s2)
{
    int score1 = calculate_scores(s1);
    int score2 = calculate_scores(s2);

    // Determine and print the result based on scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
