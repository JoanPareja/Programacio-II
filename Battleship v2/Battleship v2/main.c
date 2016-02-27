#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definitions.h"


int main(){
	int i, j, n, y, x;
	int** sea;
	int ship1_x, ship1_y, ship1_lenght=3, ship1_orientation;

	srand(time(NULL));
	
	printf("Introduce the size of the maps (nxn): ");
	scanf_s("%i", &n);
	getchar();

	//Sea creation
	sea = (int**)malloc(n*sizeof(int*));
	if (sea==NULL){
		printf("Not enough memory.");
		exit(0);
	}
	for ( i = 0; i < n; i++){
		sea[i] = (int*)malloc(n*sizeof(int));
	}



	ship1_x = rand() % n;
	ship1_y = rand() % n;

	for ( i = 0; i < n; i++){
		for (j= 0; j < n; j++){
			if (ship1_x == i&&ship1_y == j){
				(*(*(sea + i) + j)) = 'C';
			}
			else
				(*(*(sea + i) + j)) = '~';
		}
	}
	

	ship1_orientation = rand()%4;
	for ( i = 1; i < ship1_lenght; i++){
		if (ship1_orientation == 0){
			(*(*(sea + ship1_x+i) + ship1_y))='A';
		}
		if (ship1_orientation == 1){
			(*(*(sea + ship1_x-i) + ship1_y))='A';
		}
		if (ship1_orientation == 2){
			(*(*(sea + ship1_x) + ship1_y+i))='A';
		}
		if (ship1_orientation == 3){
			(*(*(sea + ship1_x) + ship1_y-i))='A';
		}
	}
	


	printmap(sea, n);


	free(sea);
	system("pause");
	return 0;
}