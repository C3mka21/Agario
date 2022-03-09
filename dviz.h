#ifndef __DVIZ_H__
#define __DVIZ_H__
#include "TXLib.h"

const int n=500;

typedef struct // ball_t
{
    int x;
    int y;
    double r;
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

typedef struct // person
{
    int x; // положение персонажа на экране по ох
    int y; // положение персонажа на экране по оу
    int x1; // положение персонажа на источнике по ох
    int y1; // положение персонажа на источнике по оу
    int width; //длина спрайта одного персонажа
    int height; // высота спрайта одного персонажа
    HDC photo; // указатель на загруженную картинку
    double scalex; //сжатие спрайта по оси ох
    double scaley; //сжатие спрайта по оси оу
    COLORREF color; //цвет который стираеться со спрайта
}person;

void izm (ball_t* b, box_t rt);
void eat(ball_t* b, ball_t* b1,person* p);
void bx (box_t rt);
void shar(ball_t b, person p);
//////////////////////////////////

void eat(ball_t* b, ball_t* b1, person* p)
{
    if((b->y-b1->y)*(b->y-b1->y)+(b->x-b1->x)*(b->x-b1->x)<=(b->r-b1->r)*(b->r-b1->r) && b->r>b1->r)
    {
        b1->m=0;
        b1->x=10000;
        b1->y=100000;
        b->r+=0.3;
        p->scalex+=0.015;
        p->scaley+=0.015;
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

void shar(ball_t b, person p)
{
    txSetFillColor(b.shar);
    txSetColor(b.lin,b.t);
    p.x=b.x-1.2*b.r;
    p.y=b.y-1.2*b.r;
    txCircle(b.x,b.y,b.r);
    Win32::TransparentBlt (
        txDC(),
        p.x,
        p.y,
        p.width * p.scalex,
        p.height * p.scaley,
        p.photo,
        p.x1 + 100,
        p.y1,
        p.width,
        p.height,
        p.color
    );
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
