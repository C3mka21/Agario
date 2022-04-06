#ifndef __MOVEBALL_H__
#define __MOVEBALL_H__

#include "Ball.hpp"

class MoveBall : public Ball
{
private:
	int W;
	int A;
	int S;
	int D;
	double v;
public:
	MoveBall(Coords, double, COLORREF, COLORREF, int, int, int, int, double);
	~MoveBall() = default;
	void move();
	void update();
};

MoveBall::MoveBall(Coords _centre, double _radius, COLORREF _line, COLORREF _fill, int _W, int _A, int _S, int _D, double _v):
		 Ball(_centre, _radius, _line, _fill), W(_W), A(_A), S(_S), D(_D), v(_v) {}

void MoveBall::move()
{
	if(GetAsyncKeyState(A))
	{
		centre.x-=v;
	}
	if(GetAsyncKeyState(D))
	{
		centre.x+=v;
	}
	if(GetAsyncKeyState(S))
	{
		centre.y+=v;
	}
	if(GetAsyncKeyState(W))
	{
		centre.y-=v;
	}
}

void MoveBall::update()
{
	if(life==true)
	{
		move();
		draw();
	}
}
#endif
