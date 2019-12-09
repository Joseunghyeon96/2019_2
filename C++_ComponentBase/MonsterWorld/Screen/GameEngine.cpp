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

	GameObject rect("rect");
	rect.addComponent<RectScript>();
	objs.push_back(&rect);

	GameObject UI("UI", "", nullptr, "UI");
	UI.addComponent<UIScript>();
	objs.push_back(&UI);

	GameObject map("map");
	map.addComponent<MapScript>();
	objs.push_back(&map);

	GameObject monster("monster","M", &map,"monster");
	monster.addComponent<MonsterScript>();
	monster.addComponent<MoveScript>();
	objs.push_back(&monster);

	GameObject ghost("ghost", "G", &map, "monster");
	ghost.addComponent<MonsterScript>();
	ghost.addComponent<MoveScript>();
	objs.push_back(&ghost);

	GameObject hellBoy("hellBoy", "B", &map, "monster");
	hellBoy.addComponent<MonsterScript>();
	hellBoy.addComponent<MoveScript>();
	objs.push_back(&hellBoy);

	GameObject king("king", "K", &map, "monster");
	king.addComponent<MonsterScript>();
	king.addComponent<MoveScript>();
	objs.push_back(&king);


	for (int i = 0; i < MAP_SIZE_X*MAP_SIZE_Y; i++) {
		char* face = "\xFE";

		GameObject *food = new GameObject("food", face, &map, "food");
		food->addComponent<FoodScript>();
		objs.push_back(food);
	}

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
