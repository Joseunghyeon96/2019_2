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
	enabled = true;
	bullets.push_back(this);
	xPos = x;
	yPos = y;

}


void Bullet::move()
{
	if (yPos < -5) {
		enabled = false;
		return;
	}
	yPos -= 8;
}


void Bullet::update()
{
	if (enabled == false) {
		destroy(this);
		return;
	}
	move();
}
