#include "Vector2D.h"


Vector2D::Vector2D(void)
{
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D &rhs){
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D &rhs){
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}


Vector2D::~Vector2D(void)
{
}
