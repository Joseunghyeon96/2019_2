#pragma once
#include "GameObject.h"
class EnemyBullet :
	public GameObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	void init(float x, float y);
	void move();
	void update();
	void destroy(GameObject* gameObject);
};

