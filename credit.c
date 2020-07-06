#include "cs50.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(void)
{

		/*
		get number from user
		find the amount of numbers
		    divive by ten until 0
		seperate numbers into an array
		*/

		//test number 4403931952377639 every other: 37351904 - 6 14 6 10 2 18 0 8

		long long numberCounter = 0; // iterates throough ccn without changing the input
		int numOfNumbers = 0; //counts number of digits
		int number_base[16]; // stores individual credit card numbers
		int hans_array[32]; // stores x * 2 for every other
		int hans_arrayTwo[32];
		string type ="";

		long long user_input = get_long_long("What is your credit card number?\n");
		numberCounter = user_input;

		while (numberCounter != 0)
		{
		    //printf("Counter: %lld\n", numberCounter);
			//printf("Amount: %i\n", numOfNumbers);
			//printf("NUMBER: %lld\n", numberCounter % 10);


		    number_base[numOfNumbers] = numberCounter % 10; //assigns ccns to array
	    	numberCounter = numberCounter / 10; // seperates the numbers
			numOfNumbers++; // increase counter for later

		}

	printf("Amount of Numbers Entered: %i\n", numOfNumbers);




		//printf("%d\n", number_base[numOfNumbers - 1]);
		if(number_base[numOfNumbers - 1] == 3)
		{
			type = "AMEX\n";
		}
		else if(number_base[numOfNumbers - 1] == 5)
		{
			type ="MASTERCARD\n";
		}
		else if(number_base[numOfNumbers - 1] == 4)
		{
			type ="VISA\n";
		}
		else
		{
			type="INVALID\n";
		}
		//printf("%s",type);








	//reset numOf
	int j = 0;

	// stores hans numbers
	for(int i = 1; i < numOfNumbers; i=i+2)
	{
	    //printf("%d\n",number_base[i]);

		hans_array[j] = (number_base[i] * 2);
		//printf("HANS: %d\n", hans_array[j]);


		j++;
	}


		for(int i = 0; i < numOfNumbers; i++)
	{
	    //printf("%d\n",number_base[i]);

		//hans_array[j] = (number_base[i] * 2);
		printf("HANS: %d\n", hans_array[i]);

	}



// working above

	int total = 0;
	int holder = 0;

	j = j - 1;
	int k = j;
	printf("J: %i \n", j);



	for(int i = 0; i <= k; i++)
		{
			do
			{
				holder = hans_array[j] % 10;
				printf("HANS ARRAY: %d\n", hans_array[j]);

				hans_array[j] = hans_array[j] / 10;

				total = total + holder;
				printf("HOLDER: %i\n", holder);
				printf("Total: %i\n", total);
				//printf("HANS ARRAY: %d\n", hans_array[j]);

			}while(hans_array[j] != 0);

			j--;
			printf("J: %i \n", j);
			printf("I: %i \n", i);

		}



	int h = 0;

	// stores second set of hans numbers
	for(int i = 0; i < numOfNumbers; i=i+2)
	{
	    printf("%d\n",number_base[i]);

		hans_arrayTwo[h] = number_base[i];
		printf("HANS TWO: %d\n", hans_arrayTwo[h]);
		total = total + hans_arrayTwo[h];
		printf("Total: %i\n", total);


		h++;
	}

	if(total % 10 == 0)
	{
		printf("%s", type);
	}


  return 0;
}
