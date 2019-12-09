#pragma once
#include "Component.h"
class MapScript :
	public Component
{
	char* map;
public:
	MapScript(GameObject* gameObject);
	~MapScript();

	void start();
	void update();
};

