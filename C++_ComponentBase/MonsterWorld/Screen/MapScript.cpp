#include "stdafx.h"
#include "GameObject.h"
#include "MapScript.h"


MapScript::MapScript(GameObject* gameObject)
	:Component(gameObject),map(new char[MAP_SIZE_X*MAP_SIZE_Y])
{
	memset(map, '\xFF', MAP_SIZE_X*MAP_SIZE_Y);
}


MapScript::~MapScript()
{
}

void MapScript::start()
{
	gameObject->setFace(map);
	gameObject->setPosition(Vector2(1, 1));
	gameObject->setScale(Vector2(MAP_SIZE_X, MAP_SIZE_Y));
}

void MapScript::update()
{
}
