#include <cs50.h>
#include <stdio.h>

// the main body of this procedure
int main(void)
{
    // get input variable
    string name = get_string("What's your name? ");
    // print the result
    printf("hello, %s\n", name);
}
