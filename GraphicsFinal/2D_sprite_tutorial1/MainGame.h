#pragma once
#include "Singleton.h"

class Hero;
class Boss;

class MainGame 
	: public SingletonBase <MainGame>
{
	Hero* hero;
	Boss* boss;
public:
	MainGame();
	~MainGame();
	
	void initGame();
	void renderFrame();
	void update();

};

