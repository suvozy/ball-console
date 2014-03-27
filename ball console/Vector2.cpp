#include "StdAfx.h"
#include "Vector2.h"

const Vector2 Vector2::Zero = Vector2();

Vector2::Vector2(const float x,const float y)
{
	X = x;
	Y = y;
}

Vector2::~Vector2()
{
}

void Vector2::operator+=(const Vector2& pVector)
{
	X += pVector.X;
	Y += pVector.Y;
}

void Vector2::operator-=(const Vector2& pVector)
{
	X -= pVector.X;
	Y -= pVector.Y;
}

void Vector2::operator*=(const float& num)
{
	X *= num;
	Y *= num;
}

void Vector2::operator/=(const float& num)
{
	X /= num;
	Y /= num;
}

void Vector2::operator=(const Vector2& pVector)
{
	X = pVector.X;
	Y = pVector.Y;
}

float Vector2::Length() const
{
	return sqrt(pow(X,2.0f) + pow(Y,2.0f));
}