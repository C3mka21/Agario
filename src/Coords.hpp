#ifndef __COORDS_H__
#define __COORDS_H__

#include <TXLib.h>
class Coords
{
public:
    double x;
    double y;

    Coords();
    Coords(double x, double y);
    Coords operator+ (const Coords& r);
    Coords operator- (const Coords& r);
    inline bool operator==(const Coords& r);
    inline bool operator!=(const Coords& r);
    inline bool operator< (const Coords& r);
    inline bool operator> (const Coords& r);
    inline bool operator<=(const Coords& r);
    inline bool operator>=(const Coords& r);
};

Coords::Coords() :
    x(), y() {}

Coords::Coords(double _x, double _y) :
    x(_x), y(_y) {}

Coords Coords::operator- (const Coords& r)
{
    Coords c = {x - r.x, y - r.y};
    return c;
}

Coords Coords::operator+ (const Coords& r)
{
    Coords c = {x + r.x, y + r.y};
    return c;
}

inline bool Coords::operator==(const Coords& r)
{
    double e = std::numeric_limits<double>::epsilon();
    return std::abs(x - r.x) <= e && std::abs(y - r.y) <= e;
}

inline bool Coords::operator!=(const Coords& r)
{
    return !(*this == r);
}

inline bool Coords::operator< (const Coords& r)
{
    double e = std::numeric_limits<double>::epsilon();
    if (x < r.x)
    {
        return true;
    }
    else if(std::abs(x - r.x) <= e)
    {
        if(y < r.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

inline bool Coords::operator> (const Coords& r)
{
    return !(*this < r) && *this != r;
}

inline bool Coords::operator<= (const Coords& r)
{
    return !(*this > r);
}

inline bool Coords::operator>= (const Coords& r)
{
    return !(*this < r);
}

double distance(Coords c1, Coords c2);

double distance(Coords c1, Coords c2)
{
    double d = sqrt(pow(c1.x - c2.x, 2.0) + pow(c1.y - c2.y, 2.0));
    return d;
}

#endif // __COORDS_H__
