#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("What is your string\n");

    int slength = strlen(text);
    int spaces = 0;
    int punc = 0;
    float sentences = 0;
    float average_l = 0;
    float average_s = 0;

    //printf("This string is %i letters long\n", slength);

    for (int i = 0; i < slength; i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
        }
        else if (text[i] == '\'' || text[i] == ',')
        {
            punc++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
            punc++;
        }

    }

    float realLetters = slength - spaces - punc;
    float word_count = spaces + 1;

//printf("Spaces: %i\n", spaces);
//printf("Punctuation: %i\n", punc);
//printf("Real Letters: %f\n", realLetters);
//printf("Words: %f\n", word_count);
//printf("Sentences: %f\n", sentences);


    average_l = (realLetters / word_count) * 100;
    average_s = (sentences / word_count) * 100;

    //printf("Average Letters: %.2f\n", average_l);
    //printf("Average Sentences: %.2f\n", average_s);



    float coleman = (0.0588 * average_l) - (0.296 * average_s) - 15.8;
    int read = round(coleman);

    if (coleman < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", read);

    }

}
