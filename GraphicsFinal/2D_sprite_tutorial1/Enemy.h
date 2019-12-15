#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
	int life;
	
public:
	Enemy();
	~Enemy();

	void init(float x, float y);
	void fire();
	void move();
	void update();
	void dead();

};

