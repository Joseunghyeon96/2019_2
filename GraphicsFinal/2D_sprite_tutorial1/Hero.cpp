#include "stdafx.h"
#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::fire()
{
}

void Hero::super_fire()
{
}

void Hero::move(int i)
{
	switch (i)
	{
	case MOVE_UP:
		yPos -= 3;
		break;

	case MOVE_DOWN:
		yPos += 3;
		break;


	case MOVE_LEFT:
		xPos -= 3;
		break;


	case MOVE_RIGHT:
		xPos += 3;
		break;

	}
}

void Hero::init(float x, float y)
{
	xPos = x;
	yPos = y;
}
