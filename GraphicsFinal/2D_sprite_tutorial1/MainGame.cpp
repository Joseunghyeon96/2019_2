#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::initGame()
{
}

void MainGame::update()
{
}

void MainGame::render(LPD3DXSPRITE d3dspt)
{
	RECT part;
	SetRect(&part, 0, 0, 64, 64);
	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position(hero.getXPos(), hero.getYPos(), 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite_hero, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));

	////ÃÑ¾Ë 
	if (bullet.bShow == true)
	{
		RECT part1;
		SetRect(&part1, 0, 0, 64, 64);
		D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
		D3DXVECTOR3 position1(bullet.getXPos(), bullet.getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	////Àû 
	RECT part2;
	SetRect(&part2, 0, 0, 64, 64);
	D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f);    // center at the upper-left corner

	for (int i = 0; i < ENEMY_NUM; i++)
	{

		D3DXVECTOR3 position2(enemy[i].getXPos(), enemy[i].getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_enemy, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


}
