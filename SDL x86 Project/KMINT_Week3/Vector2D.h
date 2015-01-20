#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(double x, double y);
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D& operator-=(const Vector2D& rhs);
	Vector2D& operator*=(const Vector2D& rhs);
	Vector2D& operator/=(const Vector2D& rhs);


	void setZero();
	bool isZero();

	double getLength();
	double getSqLength();

	void normalize();
	double dot(const Vector2D& v);

	int sign(const Vector2D& v);
	Vector2D perp(); //loodrecht

	void truncate(double max);
	double distance(const Vector2D& v);

	void reflect(const Vector2D& norm);

	Vector2D getReverse();


	virtual ~Vector2D(void);
private:
	double x;
	double y;
};

