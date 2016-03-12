struct Point
{
	Point();
	Point(int x, int y);
	Point(const Point& p);
	~Point();

	int x, y;

	void SetZero();
	bool IsZero() const;
	void SetPoint(int a, int b);
	void SetPoint(Point p);

	Point operator+(const Point add_point) const;
	Point operator-(const Point substract_point)const;

	void operator+=(const Point add_cont_point);
	void operator-=(const Point substract_cont_point);

	Point operator*(const Point mult_point)const;
	void operator*=(const Point mult_cont_point);

	bool operator==(Point p);
	bool operator!=(Point p);
};
