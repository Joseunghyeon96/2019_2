#pragma once
class GameObject
{
protected:
	float xPos;
	float yPos;
	int status;
	int HP;
public:
	GameObject();
	~GameObject();

	float getXPos();
	float getYPos();
	virtual void init(float x, float y);
	virtual void update() {}
};

