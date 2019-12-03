#pragma once
#include "GameObject.h"

class Bullet
	: public GameObject
{
public:
	Bullet();
	~Bullet();

	bool bShow;

	void init(float x, float y);
	void move();
	bool show();
	void hide();
	void active();
};

