#pragma once
#include "GameObject.h"
class Hero :
	public GameObject
{
	int power;
	DWORD shotDelayEnd;
	DWORD shotDelayStart;
public:
	Hero();
	~Hero();

	void fire();
	void super_fire();
	int getLife() { return life; }
	int getPower() { return power; }
	void move(int i);
	void init(float x, float y);
	void collisionCheck();
	void update();
};

