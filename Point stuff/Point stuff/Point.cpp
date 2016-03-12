#include "Point.h"
#include <stdio.h>

Point::Point(){ 
	printf("HOLA\n");
}
Point::Point(int x, int y) : x(x), y(y)  //Same as this->x=x but done at the same time
{ 
	//this->x = x;
	//this->y = y;
	printf("HOLA\n");
}
Point::Point(const Point& p) : x(p.x), y(p.y) 
{ 
	printf("HOLA\n");
}
Point::~Point(){
	printf("POS ME IMMOLO\n");
}

void Point::SetZero(){
	x = 0;
	y = 0;
}
bool Point::IsZero() const {
		return x == 0 && y == 0;
	}

void Point::SetPoint(int a, int b){
		x = a;
		y = b;
	}
void Point::SetPoint(Point p){
		x = p.x;
		y = p.y;
	}
Point Point::operator+(const Point add_point) const{
		Point tmp;
		tmp.x = x + add_point.x;
		tmp.y = y + add_point.y;
		return tmp;
	}
Point Point::operator-(const Point substract_point)const{
		Point tmp;
		tmp.x = x - substract_point.x;
		tmp.y = y - substract_point.y;
		return tmp;
	}

void Point::operator+=(const Point add_cont_point){
		x = x + add_cont_point.x;
		y = y + add_cont_point.y;
	}
void Point::operator-=(const Point substract_cont_point){
		x = x - substract_cont_point.x;
		y = y - substract_cont_point.y;
	}

Point Point::operator*(const Point mult_point)const{
		Point tmp;
		tmp.x = x * mult_point.x;
		tmp.y = y * mult_point.y;
		return tmp;
	}
void Point::operator*=(const Point mult_cont_point){
		x = x * mult_cont_point.x;
		y = y * mult_cont_point.y;
	}

bool Point::operator==(Point p){
		return (x == p.x&&y == p.y);		
	}
bool Point::operator!=(Point p){
		return(x == p.x&&y == p.y);		
	}
