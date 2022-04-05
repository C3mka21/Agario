#ifndef __BALL_H__
#define __BALL_H__

#include <TXLib.h>
#include "Coords.hpp"

class Ball
{
protected:
    Coords centre;
    double radius;
    double v;
    COLORREF line;
    COLORREF fill;
public:
    Ball(Coords, double, double, COLORREF, COLORREF);
    virtual ~Ball() = default;
    void draw() const;
    virtual void update() = 0;
};

Ball::Ball(Coords _centre, double _radius, double _v, COLORREF _line, COLORREF _fill):
	centre(_centre), radius(_radius), v(_v), line(_line), fill(_fill) {}

void Ball::draw() const
{
	txSetFillColor(fill);
	txSetColor(line);
	txCircle(centre.x, centre.y, radius);
	txSetFillColor(TX_WHITE);
}

#endif //__BALL_H__
