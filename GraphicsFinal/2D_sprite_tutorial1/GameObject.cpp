#include "stdafx.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Bullet.h"

vector<Enemy*> GameObject::enemies;
vector<Bullet*> GameObject::bullets;

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

float GameObject::getXPos()
{
	return xPos;
}

float GameObject::getYPos()
{
  	return yPos;
}

void GameObject::destroy(GameObject * gameObject)
{
	gameObject->enabled = false;
	int i = 0;
	if (dynamic_cast<Enemy *>(gameObject) != nullptr)
	{
		for (auto obj : enemies)
		{
			if (obj == gameObject)
			{
				enemies.erase(enemies.begin() + i);
				delete obj;
				obj = nullptr;
				return;
			}
			i++;
		}
	}
	if (dynamic_cast<Bullet *>(gameObject) != nullptr)
	{
		for (auto obj : bullets)
		{
			if (obj == gameObject)
			{
				bullets.erase(bullets.begin() + i);
				delete obj;
				obj = nullptr;
				return;
			}
			i++;
		}
	}
}

void GameObject::init(float x, float y)
{
	enabled = true;
	xPos = x;
	yPos = y;
}

void GameObject::update()
{
}

vector<Enemy*> GameObject::getEnemies()
{
	return enemies;
}

vector<Bullet*> GameObject::getBullets()
{
	return bullets;
}
