//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.02 alpha, build 2]
//! @author     Copyright (C) <Артём Постников>, <2021> (<Имя> <Почта>)
//! @date       <11.10.2021>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.02 Alpha
//!
//!
//}=======================================================================

#include "TxLib.h"
#include <math.h>

int n=500;

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
    int S;
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

void bx (box_t rt);
void shar(ball_t b);
void izm (ball_t* b, box_t rt);
void eat(ball_t* b, ball_t* b1);
void menu(box_t* tb);

int main(void)
{
    //box_t tb1=
    int x=1500, y=750;
    txCreateWindow(x,y);
    txSetFillColor(TX_WHITE);
    txClear();
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        box_t rt1={350,150,1350,700,3,TX_WHITE,TX_BLACK};
        ball_t b0[n];
        ball_t b1={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5,2,2,2,1,TX_RED,TX_BLACK,'W','A','S','D'};
        ball_t b2={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5,2,2,2,1,TX_GREEN,TX_BLACK,VK_UP,VK_LEFT,VK_DOWN,VK_RIGHT};
        int i;
        for(i=0;i<n;i++)
        b0[i]={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,2,0,0,1,1,RGB(rand()%256,rand()%256,rand()%256)};
        while(!GetAsyncKeyState(VK_SPACE))
        {
            //menu(tb1);
            bx(rt1);
            txSetFillColor(TX_WHITE);
            txSelectFont ("Comic Sans MS", 40);
            txTextOut (150, 400, "Player 2 Green");
            txTextOut (150, 200, "Player 1 Red");
            //хрю хрюрюрхрю(хрюхрю.хрюхрю,хрю->хрю.хрю);
            txTextOut(150,100,"Press SPACE to restart");
            txTextOut(550,100,"Press ESCAPE + SPACE + RANDOM BUTTON to exit");
            for(i=0;i<n;i++)
            {
                eat(&b1,&b0[i]);
                eat(&b2,&b0[i]);
                if(b0[i].m!=0)
                {
                    shar(b0[i]);
                }
            }
            shar(b1);
            shar(b2);
            izm(&b1,rt1);
            izm(&b2,rt1);
            txSleep(1);
            eat(&b2,&b1);
            if(b1.m==0)
            {
                txClear();
                txSetFillColor(TX_WHITE);
                txSelectFont ("Comic Sans MS", 40);
                txTextOut(150,100,"Press SPACE to restart");
                txTextOut(550,100,"Press ESCAPE + SPACE + RANDOM BUTTON to exit");
                txTextOut (150, 400, "Player 2 Green");
                txTextOut (150, 200, "Player 1 Red");
                txTextOut (x/2-150, y/2-50, "Player 2 won");
                txSleep(1500);
                txClear();

                break;
            }
            eat(&b1,&b2);
            if(b2.m==0)
            {
                txClear();
                txSetFillColor(TX_WHITE);
                txSelectFont ("Comic Sans MS", 40);
                txTextOut(150,100,"Press SPACE to restart");
                txTextOut(550,100,"Press ESCAPE + SPACE + RANDOM BUTTON to exit");
                txTextOut (150, 400, "Player 2 Green");
                txTextOut (150, 200, "Player 1 Red");
                txTextOut (x/2-150, y/2-50, "Player 1 won");
                txSleep(1500);
                txClear();
                break;
            }
        }
    }
    return 0;
}

void menu(box_t* tb)
{
    txSetFillColor(tb->room);
    txSetColor(tb->wall,tb->lin);
    txRectangle(tb->x1,tb->y1,tb->x2,tb->y2);
    txSetColor(tb->text);
    txSelectFont ("Comic Sans MS", tb->x);
    txTextOut (tb->x2-tb->x1, tb->y2-tb->y1, "START");

}

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

