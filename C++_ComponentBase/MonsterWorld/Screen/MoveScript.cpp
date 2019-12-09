#include "stdafx.h"
#include "GameObject.h"
#include "Transform.h"
#include "MoveScript.h"


MoveScript::MoveScript(GameObject* gameObject)
	: Component(gameObject)
{

}


MoveScript::~MoveScript()
{
}

void MoveScript::start()
{
}

void MoveScript::update()
{
	int moveX = Random_Range(-1, 1);
	int moveY = Random_Range(-1, 1);


	Vector2 pos = gameObject->getTransform()->getPos() + Vector2(moveX,moveY);
	if (pos.X() > MAP_SIZE_X || pos.X() < 1)
		pos.x -= moveX;
	if (pos.Y() >MAP_SIZE_Y || pos.Y() < 1)
		pos.y -= moveY;
	gameObject->setPosition(pos);
}
