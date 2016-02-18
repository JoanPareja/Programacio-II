#include <stdio.h>
#include <stdlib.h>


int main(){
	int i, num = 0, min = 0;

	printf("10 numbers min.\n");
	for (i = 0; i < 10; i++){

		scanf_s("%i", &num);
		min = num;
		if (min>num)
			min = num;
	}
	printf("The min is %i: \n", min);

	system("pause");
	return 0;
}