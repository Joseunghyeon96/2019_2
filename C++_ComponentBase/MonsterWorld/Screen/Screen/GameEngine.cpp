#include "stdafx.h"
#include "GameEngine.h"
#include "GameObject.h"


GameEngine* GameEngine::instance = nullptr;


GameEngine & GameEngine::getInstance()
{
	if (instance == nullptr) {
		instance = new GameEngine();
	}
	return *instance;
}

void GameEngine::mainLoop()
{

	for (auto obj : gameObjects)
	{
		obj->traverseAwake();
	}

	for (auto obj : gameObjects)
	{
		obj->traverseOnEnable();
	}

	for (auto obj : gameObjects)
	{
		obj->traverseStart();
	}

	while (!Input::GetKeyDown(KeyCode::Esc)) {
		screen.clear();
		// update		
		for (auto obj : gameObjects)
		{
			obj->traverseFixedUp();
		}

		for (auto obj : gameObjects)
		{
			obj->traverseUpdate();
		}

		for (auto obj : gameObjects)
		{
			obj->traverseLateUpdate();
		}


		// erase in active objects

		// draw

		screen.render();
		Sleep(100);

		Input::EndOfFrame();
	}
	for (auto obj : gameObjects)
	{
		obj->startOnDisable();
	}

	for (auto obj : gameObjects)
	{
		obj->startOnDestroy();
	}


	return;
}
