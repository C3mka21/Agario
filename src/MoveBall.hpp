#ifndef __MOVEBALL_H__
#define __MOVEBALL_H__

#include "Ball.hpp"
#include <vector>

class MoveBall : Ball
{
public:
	MoveBall(Coords, double, double, COLORREF, COLORREF);
	~MoveBall() = default;
	virtual void update() override;
};

MoveBall::MoveBall(Coords _centre, double _radius, double _v, COLORREF _line, COLORREF _fill):
		Ball(_centre, _radius, _v,_line, _fill) {}
void MoveBall::update()
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		centre.x-=v;
	}
	draw();
}
#endif
