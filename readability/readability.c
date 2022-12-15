#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* This program will take a piece of text from
the user, and determine the reading level.

Coleman-Liau Index:
Index = 0.0588 * L - 0.296 * S - 15.8
L is average number of letters per 100 words.
S is average number of sentences.*/

int main(void)
{

    // Define Variables
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int grade;

    // Get input from user
    string text = get_string("Text: ");

    // Variable for string length
    int i = strlen(text);

    // Counting loop
    for (int j = 0; j < i; j++)
    {

        // Count letters
        char c = text[j];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // Count words
        if (c == ' ')
        {
            words++;
        }

        // Count sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Coleman-Liau index
    // Get average letters and sentences per 100 words
    float avgLetters = ((float)letters / (float)words) * 100;
    float avgSentences = ((float)sentences / (float)words) * 100;

    // Calculate index = 0.0588 * L - 0.296 * S - 15.8
    float index = 0.0588 * avgLetters - 0.296 * avgSentences - 15.8;
    grade = round(index);

    // Output letter, word and sentence count
    printf("\nLetters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);

    // Output Grades
    if (grade < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\nGrade: %d\n", grade);
    }

    return 0;
}