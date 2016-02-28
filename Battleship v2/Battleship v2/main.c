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
	
	enum orientation{down, up, right, left};

	ship1_orientation = rand()%4;
	for ( i = 1; i < ship1_lenght; i++){
		if (ship1_orientation == down){
			(*(*(sea + ship1_x+i) + ship1_y))='A';
		}
		if (ship1_orientation == up){
			(*(*(sea + ship1_x-i) + ship1_y))='A';
		}
		if (ship1_orientation == right){
			(*(*(sea + ship1_x) + ship1_y+i))='A';
		}
		if (ship1_orientation == left){
			(*(*(sea + ship1_x) + ship1_y-i))='A';
		}
	}
	

	//
	

	printf("Shot\nX:");
	scanf_s("%i", &x);
	getchar();
	printf("Y:");
	scanf_s("%i", &y);
	getchar();
	

	printmap(sea, n, x, y);


	free(sea);
	system("pause");
	return 0;
}