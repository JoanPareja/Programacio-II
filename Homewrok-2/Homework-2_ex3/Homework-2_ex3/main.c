#include <stdio.h>
#include <stdlib.h>

int main(){
	char option;
	int x;

	printf("Introduce one number: ");
	scanf_s("%i", &x);
	

	do
	{
		printf("Chose an option from this menu:\n a-Increment\n b-Decrement\n c-Power of two\n d-Quit\n");
		fflush(stdin);
		scanf_s("%c", &option);
		switch (option)	{
		case 'a':
			x++;
			printf("Your number is now: %i\n", x);
			break;

		case 'b':
			x--;
			printf("Your number is now: %i\n", x);
			break;

		case 'c':
			x *= x;
			printf("Your number is now: %i\n", x);
			break;

		case 'd':
			printf("Quitting...\n");
			break;

		default:
			printf("Invalid option.\n");
			break;
		}
	} while (option != 'd');
	

	system("pause");
	return 0;
}