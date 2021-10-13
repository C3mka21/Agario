#ifndef __DVIZ_H__
#define __DVIZ_H__
#include "TXLib.h"

const int n=500;

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
} ball_t;

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
} box_t;

void izm (ball_t* b, box_t rt);
void eat(ball_t* b, ball_t* b1);
void bx (box_t rt);
void shar(ball_t b);
//////////////////////////////////

void eat(ball_t* b, ball_t* b1)
{
    if((b->y-b1->y)*(b->y-b1->y)+(b->x-b1->x)*(b->x-b1->x)<=pow((b->r)+(b1->r),2) && b->r>b1->r)
    {
        b1->m=0;
        b1->x=10000;
        b1->y=100000;
        b->r+=1;
    }
}

void izm (ball_t* b, box_t rt)
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

void shar(ball_t b)
{
    txSetFillColor(b.shar);
    txSetColor(b.lin,b.t);
    txCircle(b.x,b.y,b.r);
    txSetFillColor(TX_WHITE);
}

void bx (box_t rt)
{
    txSetFillColor(rt.room);
    txSetColor(rt.wall,rt.lin);
    txRectangle(rt.x1,rt.y1,rt.x2,rt.y2);
    txSetFillColor(TX_WHITE);
}

void minishar(ball_t b0[n], box_t rt)
{
    for(int i=0;i<n;i++)
    {
        b0[i]={rand()%(rt.x2-rt.x1)+rt.x1,rand()%(rt.y2-rt.y1)+rt.y1,2,0,0,1,1,RGB(rand()%256,rand()%256,rand()%256)};
    }
}
#endif
