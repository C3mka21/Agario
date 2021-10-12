#include "TXlib.h"
#include "dviz.h"

const int n=500;

boxxx_t rt1={350,150,1350,700,3,TX_WHITE,TX_BLACK};

ballll_t b1={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5,2,2,2,1,TX_RED,TX_BLACK,'W','A','S','D'};

ballll_t b2={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5,2,2,2,1,TX_GREEN,TX_BLACK,VK_UP,VK_LEFT,VK_DOWN,VK_RIGHT};

ballll_t b0 [n];

void bx (boxxx_t rt1);
void shar(ballll_t b);
void minishar(ballll_t b0[n]);
void master();

///////////////////////////////////

void shar(ballll_t b)
{
    txSetFillColor(b.shar);
    txSetColor(b.lin,b.t);
    txCircle(b.x,b.y,b.r);
    txSetFillColor(TX_WHITE);
}

void bx (boxxx_t rt1)
{
    txSetFillColor(rt1.room);
    txSetColor(rt1.wall,rt1.lin);
    txRectangle(rt1.x1,rt1.y1,rt1.x2,rt1.y2);
    txSetFillColor(TX_WHITE);
}

void master()
{
    int i;
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        minishar(&b0[n]);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            bx(rt1);
            txSetFillColor(TX_WHITE);
            txSelectFont ("Comic Sans MS", 40);
            txTextOut (150, 400, "Player 2 Green");
            txTextOut (150, 200, "Player 1 Red");
            //��� ���������(������.������,���->���.���);
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
}

void minishar(ballll_t b0[n])
{
    for(int i=0;i<n;i++)
    {
        b0[i]={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,2,0,0,1,1,RGB(rand()%256,rand()%256,rand()%256)};
    }
}