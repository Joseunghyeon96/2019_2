#include "stdafx.h"
#include "GameObject.h"

vector<GameObject*> GameObject::gameObjects;

GameObject::GameObject(const string & name, GameObject * parent, const string & tag)
	: name(name), tag(tag), enabled(true), parent(parent),
transform(new Transform) {
	components.clear();
	components.push_back(transform);
}


GameObject::~GameObject()
{
}

void GameObject::traverse()
{
	if (enabled == false) return;

	for (auto comp : components)
	{
		comp->update();
	}
	for (auto child : children)
	{
		child->traverse();
	}

}

Transform * GameObject::getTransform()
{
	return transform;
}

GameObject * GameObject::Find(const string & path)
{
	return nullptr;
}

void GameObject::setParent(GameObject * parent)
{
	{
		this->parent = parent;
	}

}
