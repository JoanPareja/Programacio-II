
struct Point
{
	int x, y;

	void SetZero(){
		x = 0;
		y = 0;
	}
	bool PointIsZero(){
		return x == 0 && y == 0;
	}
	void SetPoint(int a, int b){
		x = a;
		y = b;
	}
	void SetPoint(Point p){
		x = p.x;
		y = p.y;
	}
	Point operator+(const Point add_point){
		Point tmp;
		tmp.x = x + add_point.x;
		tmp.y = y + add_point.y;
		return tmp;
	}
	Point operator-(const Point substract_point){
		Point tmp;
		tmp.x = x - substract_point.x;
		tmp.y = y - substract_point.y;
		return tmp;
	}
	void operator+=(Point add_cont_point){
		x = x + add_cont_point.x;
		y = y + add_cont_point.y;
	}
	void operator-=(Point substract_cont_point){
		x = x - substract_cont_point.x;
		y = y - substract_cont_point.y;
	}
	Point operator*(const Point mult_point){
		Point tmp;
		tmp.x = x * mult_point.x;
		tmp.y = y * mult_point.y;
		return tmp;
	}
	void operator*=(Point mult_cont_point){
		x = x * mult_cont_point.x;
		y = y * mult_cont_point.y;
	}


	bool operator==(Point p){
		if (x==p.x&&y==p.y)
			return true;
		else
			return false;
	}
	bool operator!=(Point p){
		if (x == p.x&&y == p.y)
			return true;
		else
			return false;
	}
};

/*void set_zero(Point*);
void set_point(Point*, int, int);
void copy_point(Point*, Point);
bool point_is_zero(Point);
*/

int main(){
	Point p, p2, p3;
	int a=1, b=2;
	bool test = false;
	p.x = 1;
	p.y = 1;
	p2.x = 3;
	p2.y = 2;
	
	p += p2;
	
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