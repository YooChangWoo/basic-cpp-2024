#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& ul, const Point& ir);
	void ShowRecInfo() const;
};
#endif