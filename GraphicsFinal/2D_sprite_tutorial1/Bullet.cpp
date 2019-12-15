#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::init(float x, float y,int power)
{
	enabled = true;
	rePaint = true;
	explosion = false;
	damage = power;
	bullets.push_back(this);
	switch (power)
	{
	case 1:
		imageSizeX = 16, imageSizeY = 16;
		speed = 15;
		break;
	case 2:
		imageSizeX = 32, imageSizeY = 32;
		speed = 12;
		break;
	case 3:
		imageSizeX = 64, imageSizeY = 64;
		speed = 10;
		break;
	}
	xPos = x;
	yPos = y;

}


void Bullet::move()
{
	if (enabled == false) return;
	if (yPos < -5) {
		destroy(this);
		return;
	}
	yPos -= speed;
}


void Bullet::update()
{
	if (explosion == true) {
		DWORD end = GetTickCount();
		if(end-start>299)
		destroy(this);
		return;
	}
	move();
}
bool Bullet::getExplosion()
{
	return explosion;
}

void Bullet::setExplosion(bool key)
{
	explosion = key;
	if(key)
		start = GetTickCount();
}
