#include "stdafx.h"
#include "GameObject.h"
#include "MonsterScript.h"
#include "UIScript.h"


UIScript::UIScript(GameObject* gameObject)
	:Component(gameObject), ui(new char[30 * 20]), foodNum(0),food(new string)
{
	memset(ui, ' ', 30 * 20);
	for (int i = 0; i < 19; i++)
	{
		ui[29+(30*i)] = '\n';
	}
	ui[599] = '\0';
}


UIScript::~UIScript()
{
}

void UIScript::start()
{


	foodNum = 0;
	vector<GameObject*> foods = GameObject::allFind("food");

	for (auto food : foods)
	{
		foodNum++;
	}

	*food = "Remaining food  :" + to_string(foodNum);

	vector<GameObject*> monsters = GameObject::allFind("monster");
	for (auto monster : monsters)
	{
		string* monUI = new string;
		*monUI = monster->getName() + " Score :" + to_string(static_cast<MonsterScript*>(monster->getComponent<MonsterScript>())->getScore());
		monsterUI.push_back(monUI);
	}

	
	strncpy(&ui[0], (*food).c_str(), strlen((*food).c_str()));

	int i = 0;
	for (auto monUI :monsterUI )
	{
		strncpy(&ui[90+30*i], (*monUI).c_str(), strlen((*monUI).c_str()));
		i++;
		delete monUI;
	}
	monsterUI.clear();
	gameObject->setPosition(Vector2(1, MAP_SIZE_Y + 10));
	gameObject->setFace(ui);
	gameObject->setScale(Vector2(30, 20));
}

void UIScript::update()
{
	*food = "Remaining food  :" + to_string(foodNum);

	vector<GameObject*> monsters = GameObject::allFind("monster");
	for (auto monster : monsters)
	{
		string* monUI = new string;
		*monUI = monster->getName() + " Score :" + to_string(static_cast<MonsterScript*>(monster->getComponent<MonsterScript>())->getScore());
		monsterUI.push_back(monUI);
	}


	strncpy(&ui[0], (*food).c_str(), strlen((*food).c_str()));

	int i = 0;
	for (auto monUI : monsterUI)
	{
		strncpy(&ui[90 + 30 * i], (*monUI).c_str(), strlen((*monUI).c_str()));
		i++;
		delete monUI;
	}
	monsterUI.clear();
	gameObject->setFace(ui);
}

void UIScript::decreaseFoodNum()
{
	foodNum--;
}
