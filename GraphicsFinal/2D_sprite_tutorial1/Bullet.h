#pragma once
#include "GameObject.h"

class Bullet
	: public GameObject
{

public:
	Bullet();
	~Bullet();


	void init(float x, float y);
	void move();
	void update();
};

