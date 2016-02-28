#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"





void printmap(int** sea, int n, int x, int y){
	int i, j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (x == i&&y == j){
				printf("%c ", (*(*(sea + i) + j)));
			}
			else
				printf("\0");
		}
		printf("\n");
	}
}