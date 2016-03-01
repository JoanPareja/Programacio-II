#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"





void printmap(int** printable_sea, int n){
	int i, j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
				printf("%c ", (*(*(printable_sea + i) + j)));
		}
		printf("\n");
	}
}



void ship_generate(int** sea, int ship_x, int ship_y, int ship_orientation, int ship_lenght, int n, char ship_img){
	int i, ocuped=1;

	ship_x = rand() % n;
	ship_y = rand() % n;

	/*for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (ship_x == i&&ship_y == j)
				(*(*(sea + i) + j)) = 'O';
		}
	}
	*/

	enum orientation{ down, up, right, left };


	do
	{
		//Avoiding generating ships out of the map
		if ((ship_x + ship_lenght) > (n-1) || (ship_y + ship_lenght) > (n-1) || (ship_x - ship_lenght) < 0 || (ship_y - ship_lenght) < 0){
			ship_x = rand() % n;
			ship_y = rand() % n;
			ocuped = 1;
		}
		else
			ocuped = 0;
		//Avoiding ship overlap
		for (i = 0; i < ship_lenght; i++){
			if ((*(*(sea + ship_x + i) + ship_y)) != '~'){
				ship_x = rand() % n;
				ship_y = rand() % n;
				ocuped = 1;
			}
			else{
				ocuped = 0;
				i = ship_lenght;
			}
		}
		for (i = 0; i < ship_lenght; i++){
			if ((*(*(sea + ship_x - i) + ship_y)) != '~'){
				ship_x = rand() % n;
				ship_y = rand() % n;
				ocuped = 1;
			}
			else{
				ocuped = 0;
				i = ship_lenght;
			}
		}
		for (i = 0; i < ship_lenght; i++){
			if ((*(*(sea + ship_x) + ship_y + i)) != '~'){
				ship_x = rand() % n;
				ship_y = rand() % n;
				ocuped = 1;
			}
			else{
				ocuped = 0;
				i = ship_lenght;
			}
		}

		for (i = 0; i < ship_lenght; i++){
			if ((*(*(sea + ship_x) + ship_y - i)) != '~'){
				ship_x = rand() % n;
				ship_y = rand() % n;
				ocuped = 1;
			}
			else{
				ocuped = 0;
				i = ship_lenght;
			}
		}
	} while (ocuped==1);


	for (i = 0; i < ship_lenght; i++){
		if (ship_orientation == down){
			(*(*(sea + ship_x +i) + ship_y)) = ship_img;
		}
		if (ship_orientation == up){
			(*(*(sea + ship_x - i) + ship_y)) = ship_img;
		}
		if (ship_orientation == right){
			(*(*(sea + ship_x) + ship_y + i)) = ship_img;
		}
		if (ship_orientation == left){
			(*(*(sea + ship_x) + ship_y - i)) = ship_img;
		}
	}

}