#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"





void printmap(int** sea, int n){
	int i, j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%c ", (*(*(sea + i) + j)));
		}
		printf("\n");
	}
}