#include "TXLib.h"

typedef struct // ball_t
{
    int x;
    int y;
    int r;
    int vx;
    int vy;
    int t;
    int m;
    COLORREF shar;
    COLORREF lin;
    int w;
    int a;
    int s;
    int d;
} ballll_t;

typedef struct // box_t
{
    int x1;
    int y1;
    int x2;
    int y2;
    int lin;
    COLORREF room;
    COLORREF wall;
    COLORREF text;
    int x;
} boxxx_t;

void izm (ballll_t* b, boxxx_t rt);
void eat(ballll_t* b, ballll_t* b1);
//////////////////////////////////

void eat(ballll_t* b, ballll_t* b1)
{
    if((b->y-b1->y)*(b->y-b1->y)+(b->x-b1->x)*(b->x-b1->x)<=pow((b->r)+(b1->r),2) && b->r>b1->r)
    {
        b1->m=0;
        b1->x=10000;
        b1->y=100000;
        b->r+=1;
    }
}

void izm (ballll_t* b, boxxx_t rt)
{
    if(b->y>=rt.y1+b->r+rt.lin)
    {
        if(GetAsyncKeyState(b->w))
        b->y-=b->vy;
    }
    else b->y+=b->t;
    if(b->y<=rt.y2-b->r-rt.lin)
    {
        if(GetAsyncKeyState(b->s))
        b->y+=b->vy;
    }
    else b->y-=b->t;
    if(b->x>=rt.x1+b->r+rt.lin)
    {
        if(GetAsyncKeyState(b->a))
        b->x-=b->vx;
    }
    else b->x+=b->t;
    if(b->x<=rt.x2-b->r-rt.lin)
    {
        if(GetAsyncKeyState(b->d))
        b->x+=b->vx;
    }
    else b->x-=b->t;
}
