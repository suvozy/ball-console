#include "StdAfx.h"
#include "Rectangle.h"

Rectangle::~Rectangle(void)
{
}


// Calculates the signed depth of intersection between two rectangles.
// returns:
// The amount of overlap between two intersecting rectangles. These
// depth values can be negative depending on which wides the rectangles
// intersect. This allows callers to determine the correct direction
// to push objects in order to resolve collisions.
// If the rectangles are not intersecting, Vector2.Zero is returned.
Vector2 Rectangle::GetIntersectionDepth(Rectangle rectB)
{
	// Calculate half sizes.
	float halfWidthA = this->width / 2.0f;
	float halfHeightA = this->height / 2.0f;
	float halfWidthB = rectB.width / 2.0f;
	float halfHeightB = rectB.height / 2.0f;

	// Calculate centers.
	Vector2 centerA = Vector2(this->x + halfWidthA, this->y + halfHeightA);
	Vector2 centerB = Vector2(rectB.x + halfWidthB, rectB.y + halfHeightB);

	// Calculate current and minimum-non-intersecting distances between centers.
	float distanceX = centerA.X - centerB.X;
	float distanceY = centerA.Y - centerB.Y;
	float minDistanceX = halfWidthA + halfWidthB;
	float minDistanceY = halfHeightA + halfHeightB;

	// If we are not intersecting at all, return (0, 0).
	if (abs(distanceX) >= minDistanceX || abs(distanceY) >= minDistanceY)
		return Vector2();

	// Calculate and return intersection depths.
	float depthX = distanceX > 0 ? minDistanceX - distanceX : -minDistanceX - distanceX;
	float depthY = distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY;
	return Vector2(depthX, depthY);
}

// Gets the position of the center of the bottom edge of the rectangle.
Vector2 Rectangle::GetBottomCenter()
{
	return Vector2(x + width / 2.0f, y);
}

bool Rectangle::Contains(Vector2 v)
{
	return x < v.X && v.X  < (x + width) && y < v.Y && v.Y  < (y + height);
}

bool Rectangle::Intersect(Rectangle rect)
{
	Vector2 d = this->GetIntersectionDepth(rect);

	return d != Vector2::Zero ? true : false;
}
