#include <stdio.h>
#include <strings.h>

/**
 * main- prints a prompt on the screen
 *
 * Return: always 0
 */

int input(char *s,int length);

int main()
{
	char buffer[12];
	char *b = buffer;
	size_t bufsize = 12;
	size_t characters;
	
	printf("$_ ");

	characters = getline(&b,&bufsize,stdin);

	printf("%zu characters were read.\n",characters);

	printf("%s",buffer);

	return(0);
}
