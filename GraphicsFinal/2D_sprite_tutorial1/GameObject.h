#pragma once

class Enemy;
class Bullet;

class GameObject
{

	friend class MainGame;

protected:
	float xPos;
	float yPos;
	bool enabled;
	int status;
	int life;
	float imageSizeX;
	float imageSizeY;
	static vector<Enemy*> enemies;
	static vector<Bullet*> bullets;


public:
	GameObject();
	~GameObject();

	float getXPos();
	float getYPos();
	void setActive(bool enabled) { this->enabled = enabled; }
	float getSizeX() { return imageSizeX; }
	float getSizeY() { return imageSizeY; }
	void destroy(GameObject* gameObject);
	bool getEnabled() { return enabled; }
	virtual void decreaseLife(int x);
	virtual bool onCollision(GameObject* gameObject);
	virtual void init(float x, float y);
	virtual void update();
	static vector<Enemy*> getEnemies();
	static vector<Bullet*> getBullets();
};
