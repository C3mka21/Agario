#ifndef __MENU_H__
#define __MENU_H__
#include "TxLib.h"

int x=1500, y=750;

typedef struct //mouse_t
{
    int x;
    int y;
    bool lmbclick;
    bool check;
} mouse_t;

mouse_t mt1 ={0,0,false,false};

typedef struct // menu_t
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
    char nazv[400000];
} menu_t;

menu_t tb1 ={x/2-100,y/2,x/2+100,y/2+100,3,TX_WHITE,TX_BLACK,TX_BLACK,40,"START"};

void menu(menu_t* tb, mouse_t* mt);
void mouseXYCLICK(mouse_t* mt);
void check_menu();

/////////////////////////////////////////
void mouseXYCLICK(mouse_t* mt)
{
    mt->x = txMouseX();
    mt->y = txMouseY();
    if(GetAsyncKeyState(VK_LBUTTON))
    {
        mt->lmbclick = true;
    }
}

void menu(menu_t* tb, mouse_t* mt)
{
    txSetFillColor(tb->room);
    txSetColor(tb->wall,tb->lin);
    txRectangle(tb->x1,tb->y1,tb->x2,tb->y2);
    txSetColor(tb->text);
    txSelectFont ("Comic Sans MS", tb->x);
    txTextOut ((tb->x2-tb->x1)/2+tb->x1-50, (tb->y2-tb->y1)/2+tb->y1-25,tb->nazv);
    if(mt->x>=tb->x1 && mt->x<=tb->x2 && mt->y>=tb->y1 && mt->y<=tb->y2 && mt->lmbclick==true)
    {
        mt->check=true;
        txClear();
    }
    else mt->lmbclick = false;
}

void check_menu()
{
    while (mt1.check==false)
    {
        mouseXYCLICK(&mt1);
        menu(&tb1,&mt1);
    }
}


#endif
