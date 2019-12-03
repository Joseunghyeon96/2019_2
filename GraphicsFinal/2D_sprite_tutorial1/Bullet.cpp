#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::init(float x, float y)
{
	xPos = x;
	yPos = y;

}



bool Bullet::show()
{
	return bShow;

}


void Bullet::active()
{
	bShow = true;

}



void Bullet::move()
{
	yPos -= 8;
}

void Bullet::hide()
{
	bShow = false;

}