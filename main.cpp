
#include "menu.h"
#include "dviz.h"

int main(void)
{
    int x=1500, y=750;
    txCreateWindow(x,y);
    txSetFillColor(TX_WHITE);
    txClear();
    check_menu();
    HDC photo=txLoadImage("papich.bmp");
    HDC photo2=txLoadImage("bonvech.bmp");
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        person p1={0,0,0,0,396,396,photo ,0.03,0.03,TX_WHITE};
        person p2={0,0,0,0,225,225,photo2 ,0.03,0.03,TX_WHITE};
        person p0={};
        box_t rt1={350,150,1350,700,3,TX_WHITE,TX_BLACK};
        ball_t b0[n];
        ball_t b1={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5.0,2,2,2,1,TX_RED,TX_BLACK,'W','A','S','D'};
        ball_t b2={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,5.0,2,2,2,1,TX_GREEN,TX_BLACK,VK_UP,VK_LEFT,VK_DOWN,VK_RIGHT};
        int i;
        for(i=0;i<n;i++)
            b0[i]={rand()%(rt1.x2-rt1.x1)+rt1.x1,rand()%(rt1.y2-rt1.y1)+rt1.y1,2,0,0,1,1,RGB(rand()%256,rand()%256,rand()%256)};
        while(!GetAsyncKeyState(VK_SPACE))
        {
            bx(rt1);
            txSetFillColor(TX_WHITE);
            txSelectFont ("Comic Sans MS", 40);
            txTextOut (150, 400, "Player 2 Green");
            txTextOut (150, 200, "Player 1 Red");
            txTextOut(150,100,"Press SPACE to restart");
            txTextOut(500,100,"Press ESCAPE+SPACE+RANDOM BUTTON to exit");
            for(i=0;i<n;i++)
            {
                eat(&b1,&b0[i],&p1);
                eat(&b2,&b0[i],&p2);
                if(b0[i].m!=0)
                {
                    shar(b0[i],p0);
                }
            }
            shar(b1,p1);
            shar(b2,p1);
            izm(&b1,rt1);
            izm(&b2,rt1);
            txSleep(1);
            eat(&b2,&b1,&p1);
            if(b1.m==0)
            {
                txClear();
                txSetFillColor(TX_WHITE);
                txSelectFont ("Comic Sans MS", 40);
                txTextOut(150,100,"Press SPACE to restart");
                txTextOut(500,100,"Press ESCAPE+SPACE+RANDOM BUTTON to exit");
                txTextOut (150, 400, "Player 2 Green");
                txTextOut (150, 200, "Player 1 Red");
                txTextOut (x/2-150, y/2-50, "Player 2 won");
                txSleep(2500);
                txClear();
                break;
            }
            eat(&b1,&b2,&p1);
            if(b2.m==0)
            {
                txClear();
                txSetFillColor(TX_WHITE);
                txSelectFont ("Comic Sans MS", 40);
                txTextOut(150,100,"Press SPACE to restart");
                txTextOut(500,100,"Press ESCAPE+SPACE+RANDOM BUTTON to exit");
                txTextOut(150, 400, "Player 2 Green");
                txTextOut(150, 200, "Player 1 Red");
                txTextOut(x/2-150, y/2-50, "Player 1 won");
                txSleep(2500);
                txClear();
                break;
            }
        }
    }

    return 0;
}



