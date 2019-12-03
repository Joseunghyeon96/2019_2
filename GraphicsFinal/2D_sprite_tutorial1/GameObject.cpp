#include "stdafx.h"
#include "GameObject.h"



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

void GameObject::init(float x, float y)
{
	xPos = x;
	yPos = y;
}
