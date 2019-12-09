#pragma once
#include "Component.h"
class UIScript :
	public Component
{

	vector<string*> monsterUI;
	int foodNum;
	string* food;
	char* ui;
public:
	UIScript(GameObject* gameObject);
	~UIScript();

	void start();
	void update();
	void decreaseFoodNum();
};

