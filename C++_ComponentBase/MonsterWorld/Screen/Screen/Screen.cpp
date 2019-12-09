#include "stdafx.h"
#include "Screen.h"



Screen* Screen::instance = nullptr;


Screen & Screen::getInstance()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	if (instance == nullptr) {
		instance = new Screen();
	}
	return *instance;

}

Screen::~Screen()
{
	if (instance) {
		delete[] canvas;
		instance = nullptr;
	}
}

void Screen::drawRect(const Position & pos, int w, int h)
{

	canvas[pos.x] = '\xDA';
	canvas[pos.x + w - 1] = '\xBF';
	memset(&canvas[pos.x + 1], '\xC4', w - 2);
	canvas[pos.x + (pos.y + (h - 1))*(width + 1)] = '\xC0';
	canvas[pos.x + (pos.y + (h - 1))*(width + 1) + w - 1] = '\xD9';
	memset(&canvas[pos.x + 1 + (pos.y + (h - 1))*(width + 1)], '\xC4', w - 2);
	for (int i = 1; i < h - 1; i++) {
		canvas[pos.x + (pos.y + i)*(width + 1)] = '\xB3';
		canvas[pos.x + w - 1 + (pos.y + i)*(width + 1)] = '\xB3';
	}

}

void Screen::draw(const char * shape, int w, int h, const Position & pos)
{
	if (!shape) return;
	for (int i = 0; i < h; i++)
	{
		strncpy(&canvas[pos.x + (pos.y + i)*(width + 1)], &shape[i*w], w);
	}
}

void Screen::render()
{
	for (int i = 0; i < height; i++)
		canvas[width + i * (width + 1)] = '\n';
	canvas[width + (height - 1) * (width + 1)] = '\0';
	Borland::gotoxy(0, 0);
	cout << canvas;
}

void Screen::clear()
{

	memset(canvas, ' ', (width + 1)*height);
	canvas[width + (height - 1)*(width + 1)] = '\0';

}
