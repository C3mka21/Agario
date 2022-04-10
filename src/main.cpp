
#include "Button.hpp"
#include "Ball.hpp"
#include "MoveBall.hpp"
#include "Coords.hpp"
#include "MiniBall.hpp"
#include <vector>

#define WINDOWX 1500
#define WINDOWY 700
#define WINRATIO WINDOWX/WINDOWY

const int n = 300;

int main(void)
{
	txCreateWindow(WINDOWX,WINDOWY);
	txSetFillColor(TX_WHITE);
	txClear();
	srand(time(0));
	MoveBall first_ball ( Coords {1000,350}, 10.0, TX_BLACK, TX_RED, VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT, WINRATIO*2);
	MoveBall second_ball( Coords {300, 400}, 10.0, TX_BLACK, TX_GREEN, 'W', 'A', 'S', 'D', WINRATIO*2);
	Menu buttons ({{{WINDOWX/2 - 150, WINDOWY/2 - 50}, {WINDOWX/2 + 150, WINDOWY/2 + 25}}, TX_BLACK, TX_WHITE, "Press on this button,\n "
			"if you want to start play"}, {{{WINDOWX - 150, 10}, {WINDOWX - 50, 40}}, TX_BLACK, TX_WHITE, "INFO"});
	std:: vector <MiniBall> balls;
	for(int i = 0; i < n; i++)
	{
		 balls.push_back({Coords(rand()%WINDOWX, rand()%WINDOWY), 2.0, RGB(rand()%256,
				 rand()%256, rand()%256), RGB(rand()%256, rand()%256, rand()%256)});
	}
	while(!buttons.getPlay().pushed())
	{
		buttons.draw();
		txSleep(10);
		txClear();
	}
	txBegin();
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		for(int i = 0; i < balls.size(); i++)
		{
			balls[i].update();
			if(balls[i].check(second_ball.getCentre(), second_ball.getRadius()) == false)
			{
				second_ball.setRadius(second_ball.getRadius() + balls[i].getRadius());
				balls.erase(balls.begin() + i);
				i--;
			}
			if(balls[i].check(first_ball.getCentre(), first_ball.getRadius()) == false)
			{
				first_ball.setRadius(first_ball.getRadius() + balls[i].getRadius());
				balls.erase(balls.begin() + i);
				i--;
			}
		}
		if( first_ball.check(second_ball.getCentre(), second_ball.getRadius()) == false)
		{
			first_ball.setRadius(first_ball.getRadius() + second_ball.getRadius());
			break;
		}
		if(second_ball.check(first_ball.getCentre(), first_ball.getRadius()) == false)
		{
			second_ball.setRadius(second_ball.getRadius() + first_ball.getRadius());
			break;
		}
		first_ball.update();
		second_ball.update();
		txSleep(10);
		txClear();
	}
	txEnd();
	return 0;
}
