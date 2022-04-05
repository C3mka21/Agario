

#include "Ball.hpp"
#include "MoveBall.hpp"
#include "Coords.hpp"

#define WINDOWX 1500
#define WINDOWY 700

int main(void)
{
	txCreateWindow(WINDOWX,WINDOWY);
	txSetFillColor(TX_WHITE);
	txClear();
	MoveBall first_ball({1000,350}, 15, 15, TX_BLACK, TX_RED);
	while(true)
	{
		first_ball.update();
		txSleep(25);
		txClear();
	}

	return 0;
}



