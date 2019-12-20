#pragma once


class Component;
class Transform;

class GameObject
{
	bool		enabled;
	Screen screen;
	string		name;
	string		tag;
	GameObject* parent;
	vector<GameObject*> children;
	vector<Component*> components;
	static vector<GameObject *> gameObjects;
	friend class GameEngine;
	Transform* transform;

public:
	GameObject(const string& name, GameObject* parent = nullptr, const string& tag = "");
	~GameObject();

	void traverseStart();
	void traverseUpdate();
	void traverseDraw();
	Transform* getTransform();
	void setTransform(Transform transform);
	void setPosition(const Vector2& pos);
	void setScale(const Vector2& scale);
	string getName() const { return name; }
	static GameObject* Find(const string& path);
	void setParent(GameObject* parent);
	GameObject* getParent() { return parent; }
	void destroy(GameObject* gameObject);
	static vector<GameObject*> allFind(const string& path);
	static vector<GameObject*> getObjs();


	template<typename T>
	void addComponent() {
		T t{ this };
		if (dynamic_cast<Component*>(&t) == nullptr) {
			return;
		}

		components.push_back(new T{ this });
	}

	template<typename T>
	Component* getComponent() {
		for (auto comp : components)
		{
			if (dynamic_cast<T*>(comp) != nullptr) return comp;
		}
		return nullptr;
	}


	virtual bool isActive() { return enabled; }
	void setActive(bool flag = true) { enabled = flag; }
};


