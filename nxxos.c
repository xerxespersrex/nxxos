//for printf
#include <stdio.h>

//for strcmp
#include <string.h>

#define COMMANDMAX 10000

char command[COMMANDMAX];
int commandcounter = 0;
int commandreturn = 0;
int c;

int printarray(char array[], int arraysize)
{
	int temp;
	for (temp = 0; temp < arraysize - 1; temp++)
	{
		if (array[temp] == '\0')
		{
			break;
		}
		else
		{
			printf("%c", array[temp]);
		}
	}
	return 0;
}

/*
int comparechararrays(char array1[], int array1size, char array2[], int array2size)
{
	int temp;
	for (temp = 0; temp < array1size - 1 && temp < array2size - 1; temp++)
	{
		if (array1[temp] != array2[temp])
		{
			break;
		}
		if (array2[temp] == '\0')
		{
			return TRUE;
		}
	}
	return FALSE;
}
*/

int runcommand(char array[], int arraysize)
{
	if (strcmp(command, "exit") == 0)
	{
		return 1;
	}
	return 0;
}

int main()
{
	printf(">");
	for (;;)
	{
		while ((c = getchar()) != '\n' && c != EOF && commandcounter < COMMANDMAX - 2)
		{
			if (c == '\b')
			{
				command[commandcounter] = 0;
				commandcounter--;
			}
			else
			{
				command[commandcounter] = c;
				commandcounter++;
			}
		}
		
		command[commandcounter] = '\0';

		//todo: move to runcommand()
		if (printarray(command, COMMANDMAX) == 1)
		{
			return -1;
		}
		
		commandreturn = runcommand(command, COMMANDMAX);
		
		if (commandreturn == 1)
		{
			printf("\nCommand returned value 1; exitting");
			break;
		}
		
		printf("\n>");
		commandcounter = 0;
	}
	return 0;
}
