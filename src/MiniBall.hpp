#ifndef __MINIBALL_H__
#define __MINIBALL_H__

#include "Ball.hpp"

class MiniBall : public Ball
{
public:
	MiniBall(Coords, double, COLORREF, COLORREF);
	MiniBall();
	~MiniBall() {};
	void update();
};

MiniBall::MiniBall(Coords _centre, double _radius, COLORREF _line, COLORREF _fill):
	Ball(_centre, _radius, _line, _fill) {}

MiniBall::MiniBall() {}

void MiniBall::update()
{
	if(life==true)
		draw();
}

#endif
