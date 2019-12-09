#pragma once
#include "Transform.h"

class Component
{

	Transform* transform;

protected:
	GameObject* gameObject;

public:
	Component(GameObject* gameObject)
		: gameObject(gameObject),
		transform(gameObject->getTransform())
	{}

	virtual ~Component() {}

protected:
	virtual void awake() {}
	virtual void onEnable() {}
	virtual void start() {}
	virtual void fixedUpdate() {}
	virtual void update() {}
	virtual void lateUpdate() {}
	virtual void onDisable() {}
	virtual void onDestroy() {}
};

