#pragma once
#include "GameObject.h"
class Hero :
	public GameObject
{

public:
	Hero();
	~Hero();

	void fire();
	void super_fire();
	void move(int i);
	void init(float x, float y);
	void update();
};

