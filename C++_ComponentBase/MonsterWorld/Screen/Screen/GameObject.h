#pragma once
#include "Component.h"
#include "Transform.h"
class GameObject
{
	bool		enabled;
	string		name;
	string		tag;
	GameObject* parent;
	vector<Component *> components;

	static vector<GameObject *> gameObjects;

	friend class GameEngine;

	Transform* transform;

public:
	GameObject(const string& name, GameObject* parent = nullptr, const string& tag = "");
	~GameObject();


	void traverse();
	Transform* getTransform();
	static GameObject* Find(const string& path);
	void setParent(GameObject* parent);



	virtual bool isActive() { return enabled; }
	void setActive(bool flag = true) { enabled = flag; }
};

