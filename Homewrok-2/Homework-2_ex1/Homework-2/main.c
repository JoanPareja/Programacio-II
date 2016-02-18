#include <stdio.h>
#include <stdlib.h>


int main(){
	int a, b, c=0, i=0;
	a = 60, b = 43;
	
	while (i<b){
		c += a;
		i++;
	}

	printf("%i", c);
	system("pause");
	return 0;
}