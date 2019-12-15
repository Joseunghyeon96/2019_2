#include "stdafx.h"
#include "UI.h"
#include "Boss.h"
#include "Hero.h"


UI::UI()
{
}


UI::~UI()
{
}

void UI::init(Hero * hero,Boss* boss)
{
	this->hero = hero;
	this->boss = boss;
	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"life.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&lifeSprite);    // load to sprite
	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"white.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&white);    // load to sprite

}

void UI::renderUI(LPD3DXSPRITE d3dspt)
{

	RECT lifeRect;
	SetRect(&lifeRect, 0, 0, 32,32);
	D3DXVECTOR3 lifeCenter(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < hero->getLife(); i++)
	{
		D3DXVECTOR3 lifePos(10 + 34*i, 900 , 0.0f);
		d3dspt->Draw(lifeSprite, &lifeRect, &lifeCenter, &lifePos, D3DCOLOR_ARGB(255, 255, 255, 255));
	}

	RECT bossHpBar;
	SetRect(&bossHpBar, 0, 0, 800, 8);
	D3DXVECTOR3 bossHpCenter(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 hpBarPos(100, 3, 0.0f);
	d3dspt->Draw(white, &bossHpBar, &bossHpCenter, &hpBarPos, D3DCOLOR_ARGB(255, 255, 0, 0));

	RECT bossHp;
	SetRect(&bossHp, 0, 0, 1, 8);
	for (int i = 0; i < boss->getLife(); i++)
	{
		D3DXVECTOR3 hpPos(100 + i, 3, 0.0f);
		d3dspt->Draw(white, &bossHp, &bossHpCenter, &hpPos, D3DCOLOR_ARGB(255, 0, 255, 0));
	}
}
