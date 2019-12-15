#pragma once
#include "Singleton.h"
class Hero;
class Boss;

class UI : public SingletonBase<UI>
{

	Hero* hero;
	Boss* boss;
	LPDIRECT3DTEXTURE9 lifeSprite;
	LPDIRECT3DTEXTURE9 white;
	LPDIRECT3DTEXTURE9 backGround;
public:
	UI();
	~UI();
	void init(Hero* hero,Boss* boss);

	void renderUI(LPD3DXSPRITE d3dspt);
};

