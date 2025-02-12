#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

float compute_readability(string text);
void print_results(float index);

int main(void)
{
    // Prompt the user for input text
    string text = get_string("Text: ");

    // Compute the readability index
    float index = compute_readability(text);

    // Print the grade level
    print_results(index);
}

float compute_readability(string text)
{
    int letters = 0, words = 1, sentences = 0;
    int n = strlen(text);

    // Loop through each character in the text
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Compute L and S values
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // Compute the Coleman-Liau index
    return 0.0588 * L - 0.296 * S - 15.8;
}

void print_results(float index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
