#pragma once
class Borland
{
public:

	static int wherex();
	static int wherey();
	static void gotoxy(int x, int y);
	static void gotoxy(const Position* pos);
	static void gotoxy(const Position& pos);
};
