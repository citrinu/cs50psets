#include "cs50.h"
#include "stdio.h"


int main(void)
{

    int num_bricks = 0;
    bool cor_amount = false;

    do
    {
        num_bricks = get_int("What is the height?\n");

        if (num_bricks > 0 && num_bricks < 9)
        {
            //printf("Pyrmid Height: %i\n",num_bricks);
            cor_amount = true;
        }
        else
        {
            printf("NOPE");
        }
    }
    while (cor_amount == false);


    //printf("#" * num_bricks)
    //int i = 0; i < num_bricks; i++
    //int j = num_bricks; j > i; j--


    for (int i = 1; i <= num_bricks; i++)
    {
        printf("%*s", num_bricks - i, "");

        for (int j = 0; j < i; j++)
        {
            printf("%s", "#");
            //printf("\n");
        }

        printf("%s", "  ");

        for (int j = 0; j < i; j++)
        {
            printf("%s", "#");
            //printf("\n");
        }

        printf("\n");

    }

    return 0;
};
