#pragma once

#include <math.h>

class Vector2
{
public:
	float X;
	float Y;

	Vector2(const float x = 0,const float y = 0);
	~Vector2();

	Vector2 operator+(const Vector2& pVector) const;
	Vector2 operator-(const Vector2& pVector) const;
	Vector2 operator*(const float& num) const;
	Vector2 operator/(const float& num) const;
	Vector2 operator*(const Vector2& vector) const;
	Vector2 operator/(const Vector2& vector) const;
	void operator+=(const Vector2& pVector);
	void operator-=(const Vector2& pVector);
	void operator*=(const float& num);
	void operator/=(const float& num);
	void operator=(const Vector2& pVector);
	bool operator==(const Vector2& vector) const;
	bool operator!=(const Vector2& vector) const;

	float Length() const;

	static const Vector2 Zero;
};

inline bool Vector2::operator==(const Vector2& vector) const
{
	return X == vector.X && Y == vector.Y;
}

inline bool Vector2::operator!=(const Vector2& vector) const
{
	return X != vector.X || Y != vector.Y;
}

inline Vector2 Vector2::operator+(const Vector2& pVector) const
{
	return Vector2(X + pVector.X,Y + pVector.Y);
}

inline Vector2 Vector2::operator-(const Vector2& pVector) const
{
	return Vector2(X - pVector.X,Y - pVector.Y);
}

inline Vector2 Vector2::operator*(const float& num) const
{
	return Vector2(X * num,Y * num);
}

inline Vector2 Vector2::operator/(const float& num) const
{
	return Vector2(X / num,Y / num);
}

inline Vector2 Vector2::operator*(const Vector2& vector) const
{
	return Vector2(X * vector.X,Y * vector.Y);
}

inline Vector2 Vector2::operator/(const Vector2& vector) const
{
	return Vector2(X / vector.X,Y / vector.Y);
}
