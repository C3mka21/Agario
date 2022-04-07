#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Fixture.hpp"
using namespace std;

class Button
{
private:
	AABB fixture;
	COLORREF line;
	COLORREF fill;
	string text;
public:
	Button(AABB, COLORREF, COLORREF, string);
	~Button() = default;
	bool pushed();
	void draw();
};

Button::Button(AABB _fixture, COLORREF _line, COLORREF _fill, string _text ):
		fixture(_fixture), line(_line), fill(_fill), text(_text) {}

bool Button::pushed()
{
	if(GetAsyncKeyState(VK_LBUTTON))
		if(fixture.minimum.x < txMouseX() && fixture.maximum.x > txMouseX())
			if(fixture.minimum.y < txMouseY() && fixture.maximum.y > txMouseY())
				return true;
    return false;
}

void Button::draw()
{
	txSetFillColor(fill);
	txSetColor(line);
	txSelectFont ("Comic Sans MS", 35);
	txRectangle(fixture.minimum.x, fixture.minimum.y, fixture.maximum.x, fixture.maximum.y);
	txSetFillColor(TX_BLACK);
	const char* c_text = text.c_str();
	txDrawText(fixture.minimum.x, fixture.minimum.y, fixture.maximum.x, fixture.maximum.y, c_text);

}

//---------------------------------------------------------------------------------------------------------

class Menu
{
private:
    Button play;
    Button info;
public:
    Menu(Button, Button);
    ~Menu() = default;
    void draw();
    void update();
    Button getPlay() { return play; };
};

Menu::Menu(Button _play, Button _info):
    play(_play), info(_info) {}

void Menu::draw()
{
    play.draw();
    info.draw();
}

#endif
