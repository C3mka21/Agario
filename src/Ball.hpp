#ifndef __BALL_H__
#define __BALL_H__

#include <TXLib.h>
#include "Coords.hpp"

class Ball
{
protected:
    Coords centre;
    double radius;
    COLORREF line;
    COLORREF fill;
    bool life;
public:
    Ball(Coords, double, COLORREF, COLORREF);
    Ball();
    virtual ~Ball() = default;
    void draw() const;
    bool check(Coords ball, double r);
    Coords getCentre() { return centre;};
    double getRadius() { return radius;};
    void setRadius(double r) { radius=r;};
};

Ball::Ball(Coords _centre, double _radius, COLORREF _line, COLORREF _fill):
	centre(_centre), radius(_radius), line(_line), fill(_fill), life(true) {}

Ball::Ball() {}

void Ball::draw() const
{
	txSetFillColor(fill);
	txSetColor(line);
	txCircle(centre.x, centre.y, radius);
	txSetFillColor(TX_WHITE);
}

bool Ball::check(Coords ball, double r)
{
	if(distance(centre, ball) <= (r + radius)/2)
	{
		life=false;
		return false;
	}
	return true;

}

#endif //__BALL_H__
