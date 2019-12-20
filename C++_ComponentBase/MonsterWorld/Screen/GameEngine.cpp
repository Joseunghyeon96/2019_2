#include "stdafx.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "MoveScript.h"
#include "FoodScript.h"
#include "MapScript.h"
#include "UIScript.h"
#include "RectScript.h"
#include "MonsterScript.h"



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
	auto& objs = GameObject::gameObjects;
	


	GameObject UI("UI", nullptr, "UI");
	UI.addComponent<UIScript>();
	objs.push_back(&UI);

	GameObject rect("rect", &UI, "rect");
	rect.addComponent<RectScript>();
	objs.push_back(&rect);

	GameObject map("map",nullptr,"map");
	map.addComponent<MapScript>();
	objs.push_back(&map);

	for (auto obj : objs)
	{
		obj->traverseStart();
	}

	while (!Input::GetKeyDown(KeyCode::Esc)) {
		screen.clear();
		// update		
		for (auto obj : objs)
		{
			obj->traverseUpdate();
		}
		// erase in active objects

		// draw
		for (auto obj : objs)
		{
			obj->traverseDraw();
		
		}
		screen.render();

		Sleep(1000);

		Input::EndOfFrame();
	}

	Borland::gotoxy(Vector2(20, 20));
	int i = 0;
	for (auto obj : objs)
	{
		i++;
		cout << obj->getName() << "  ";
	}
	cout<<endl;
	cout << i << endl;
	system("pause");
	return;
}
