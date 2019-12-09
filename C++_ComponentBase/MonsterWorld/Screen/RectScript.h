#pragma once
#include "Component.h"
class RectScript :
	public Component
{
	char* rect;
public:
	RectScript(GameObject* gameObject);
	~RectScript();

	void start();
};

