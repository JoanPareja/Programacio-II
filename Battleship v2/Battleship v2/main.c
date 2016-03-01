#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "definitions.h"


int main(){
	int i, j, n, y=0, x=0, weapon=0, hits=0;
	int** sea;
	int** printable_sea;
	int ship1_x = 0, ship1_y = 0, ship1_lenght = 1, ship1_orientation = rand() % 4;
	int ship2_x = 0, ship2_y = 0, ship2_lenght = 2, ship2_orientation = rand() % 4;
	int ship3_x = 0, ship3_y = 0, ship3_lenght = 3, ship3_orientation = rand() % 4;
	int ship4_x = 0, ship4_y = 0, ship4_lenght = 4 ,ship4_orientation = rand() % 4;
	char ship1_img = 'A', ship2_img = 'B', ship3_img = 'C', ship4_img = 'D';
	char option = 'y';

	srand(time(NULL));
	
	printf("Introduce the size of the maps (nxn), (min:10x10): ");
	scanf_s("%i", &n);
	getchar();
	if (n < 10)
		n = 10;

	//Sea creation
	sea = (int**)malloc(n*sizeof(int*));
	if (sea==NULL){
		printf("Not enough memory.");
		exit(0);
	}
	for ( i = 0; i < n; i++){
		sea[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
				(*(*(sea + i) + j)) = '~';
		}
	}


	//Printable sea creation
	printable_sea = (int**)malloc(n*sizeof(int*));
	if (printable_sea == NULL){
		printf("Not enough memory.");
		exit(0);
	}
	for (i = 0; i < n; i++){
		printable_sea[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			(*(*(printable_sea + i) + j)) = '-';
		}
	}



	ship_generate(sea, ship1_x, ship1_y, ship1_orientation, ship1_lenght, n, ship1_img);
	ship_generate(sea, ship2_x, ship2_y, ship2_orientation, ship2_lenght, n, ship2_img);
	ship_generate(sea, ship3_x, ship3_y, ship3_orientation, ship3_lenght, n, ship3_img);
	ship_generate(sea, ship4_x, ship4_y, ship4_orientation, ship4_lenght, n, ship4_img);
	

	do{		
		printmap(printable_sea, n);

		if ((*(*(printable_sea + x) + y)) != '~' && (*(*(printable_sea + x) + y)) != '-' && (*(*(printable_sea + x) + y)) != (*(*(sea + x) + y))){
			printf("\nYou hit a ship!!\n");
			hits++;
		}
		else if ((*(*(printable_sea + x) + y)) == '~' && (*(*(printable_sea + x) + y)) == (*(*(sea + x) + y)))
			printf("\nYou missed.\n");

		else if ((*(*(printable_sea + x) + y)) != '~' && (*(*(printable_sea + x) + y)) == (*(*(sea + x) + y)))
			printf("\nYou already hit this ship.\n");


		printf("What do you want to do: shoot(1) scan (2):");
		scanf_s("%i", &weapon);
		getchar();

		if (weapon==1){
			printf("\nIntroduce the shoot coordinates:\nHorizontal:");
			scanf_s("%i", &x);
			getchar();
			x = x - 1;
			printf("Vertical:");
			scanf_s("%i", &y);
			getchar();
			y = y - 1;
			(*(*(printable_sea + x) + y)) = (*(*(sea + x) + y));
		}

		if (weapon == 2){
			printf("Scanning...\n");
			printmap(sea, n);
			Sleep(1000);
		}

		if (hits == 10){
			printf("Continue y/n: ");
			scanf_s("%c", &option);
			getchar();
		}
		
		system("cls");

	} while (option != n);


	//printmap(printable_sea, n);

	free(sea);
	system("pause");
	return 0;
}