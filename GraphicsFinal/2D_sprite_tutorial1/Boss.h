#pragma once
#include "GameObject.h"
class Boss :
	public GameObject
{
	int life;
	float ySpeed;
	float xSpeed;
	DWORD easyPattern1;
public:
	Boss();
	~Boss();
	void init(float x, float y);
	void update();
	void move();
	bool hit();
	int getLife() { return life; }
	void spawnEnemy();
};

