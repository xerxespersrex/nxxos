#include <stdio.h>

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

int runcommand(char array[], int arraysize)
{
	return 1;
}

int main()
{
	printf(">");
	for (;;)
	{
		while ((c = getchar()) != '\n' && c != EOF && commandcounter < COMMANDMAX- 1)
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

		/*
		switch (commandreturn)
		{
		}
		*/
		
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
