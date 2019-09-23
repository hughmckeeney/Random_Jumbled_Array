//Written by Hugh Mc Keeney 

//printing an array with the words jumbled, a random word from the array, and also in order

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void print(char words[12][20], int arraySize);
void jumble(char words[12][20], int arraySize);
void random_word(char words[12][20], int arraySize);

int main(void)
{
	srand(time(NULL));
	char words[12][20] = {"COMP10120", "is", "my", "favourite", "module", "and", "I", "learn", "lots", "of", "interesting", "things"};
	
	printf("Words in order:\n");
	print(words, 12);
	
	jumble(words, 12);
	printf("\nJumbled words:\n");
	print(words, 12);
	
	printf("\nRandom word:");
	random_word(words, 12);
	
	return 0;
}

void print(char words[12][20], int arraySize)
{
	int i;
	for(i = 0; i < arraySize; ++i)
	{
		printf("%s\n", *(words+ i));
	}
	return;
}

//using the fisher yates algorithim	
void jumble(char words[12][20], int arraySize)
{
	int i, j;
	char temp[20];
	
	for(i = 0; i < arraySize; i++)
	{
		j = rand()%(i+1);
        if (j!=i)
		{
			strcpy(temp, *(words+ j));
			strcpy(*(words+ j), *(words+ i));
			strcpy(*(words+ i), temp);
		}
	}
	return;
}

void random_word(char words[12][20], int arraySize)
{
	int i;
	
	i = rand()%(arraySize);
	printf(" %s", *(words+ i));
	
	return;
}
	
	