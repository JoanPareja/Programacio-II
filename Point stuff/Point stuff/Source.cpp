#include "Point.h"
#include <stdio.h>

/*void set_zero(Point*);
void set_point(Point*, int, int);
void copy_point(Point*, Point);
bool point_is_zero(Point);
*/

int main(){
	{
		Point a[10];
	}
	{
	Point b(1, 2);
	Point c(b);
	}
	getchar();
	return 0;
}

/*
void set_zero(Point* p){
p->x = 0;
p->y = 0;
}

bool point_is_zero(Point p){
return p.x == 0 && p.y == 0;
}

void set_point(Point* p, int x, int y){
p->x = x;
p->y = y;
}

void copy_point(Point* p, Point p2){
p->x = p2.x;
p->y = p2.y;
}
*/