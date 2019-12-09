#include "stdafx.h"
#include "GameObject.h"
#include "Transform.h"


vector<GameObject*> GameObject::gameObjects;

GameObject::GameObject(const string& name,const char* face, GameObject* parent, const string& tag)
	: name(name),face(new char[strlen(face)+1]),tag(tag), enabled(true), parent(parent)
	,screen(Screen::getInstance()),transform(new Transform(this)) 
{
	components.clear();
	strncpy(this->face, face, strlen(face) + 1);
	this->face[strlen(face)] = '\0';
	components.push_back(transform);
}


GameObject::~GameObject()
{
}

void GameObject::traverseStart()
{
	if (enabled == false) return;

	for (auto comp : components)
	{
		comp->start();
	}
	for (auto child : children)
	{
		child->traverseStart();
	}
}

void GameObject::traverseUpdate()
{
	if (enabled == false) return;

	for (auto comp : components)
	{
		
		comp->update();
	}
	for (auto child : children)
	{
		child->traverseUpdate();

	}
}

void GameObject::traverseDraw()
{

	if (enabled == false) return;
	screen.draw(face,transform->getScale().X(), (transform->getScale()).Y(), transform->getPos());


	for (auto child : children)
	{
		child->traverseDraw();
	}
}

Transform * GameObject::getTransform()
{
	return transform;
}

void GameObject::setTransform(Transform transform)
{
	*(this->transform) = transform;
}

void GameObject::setPosition(const Vector2& pos)
{
	transform->setPos(pos);
}

void GameObject::setScale(const Vector2 & scale)
{
	transform->setScale(scale);
}

GameObject * GameObject::Find(const string & path)
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject->name == path)
			return gameObject;
	}
}

vector<GameObject *> GameObject::allFind(const string & path)
{
	vector<GameObject*> finds;

	for (auto gameObject : gameObjects)
	{
		if (gameObject->tag == path)
			finds.push_back(gameObject);
	}
	return finds;
}

void GameObject::setFace(const char * face)
{
	delete(this->face);
	this->face = new char[strlen(face) + 1];
	strncpy(this->face, face, strlen(face) + 1);
	this->face[strlen(face)] = '\0';
}

void GameObject::setParent(GameObject * parent)
{
	{
		this->parent = parent;
	}

}

void GameObject::setScore(int score)
{
	this->score = score;
}

void GameObject::destroy(GameObject * gameObject)
{
	int i = 0;
	for (auto obj : gameObjects)
	{
		if (obj == gameObject)
		{
			gameObjects.erase(gameObjects.begin()+i);
			return;
		}
		i++;
	}
}

vector<GameObject*> GameObject::getObjs()
{
	return gameObjects;
}


