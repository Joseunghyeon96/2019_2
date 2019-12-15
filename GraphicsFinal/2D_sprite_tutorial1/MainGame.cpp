#include "stdafx.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Hero.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Boss.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::initGame()
{
	//객체 초기화 
	hero = new Hero;
	hero->init(400, 700);

	//보스초기화 
	boss = new Boss;
	boss->init(400, -200);
}

void MainGame::renderFrame()
{

	auto& enemies = GameObject::getEnemies();
	auto& bullets = GameObject::getBullets();
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // // begin sprite drawing with transparency

	//UI 창 렌더링 


	//
	//static int frame = 21;    // start the program on the final frame
 //   if(KEY_DOWN(VK_SPACE)) frame=0;     // when the space key is pressed, start at frame 0
 //   if(frame < 21) frame++;     // if we aren't on the last frame, go to the next frame

 //   // calculate the x-position
 //   int xpos = frame * 182 + 1;

	RECT part0;
	SetRect(&part0, 0, 0, 1440, 1200);
	D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position0(0.0f, 0.0f, 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite, &part0, &center0, &position0, D3DCOLOR_ARGB(127, 255, 255, 255));


	//주인공 
	RECT part;
	SetRect(&part, 0, 0, 128, 128);
	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position = D3DXVECTOR3(hero->getXPos(), hero->getYPos(), 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite_hero, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));

	////총알 

	RECT part1;
	SetRect(&part1, 0, 0, 12, 27);
	D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
	for (Bullet* bullet : bullets) {
		D3DXVECTOR3 position1(bullet->getXPos(), bullet->getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	//보스
	RECT bossRect;
	D3DXVECTOR3 bossCenter(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 bossPos(boss->getXPos(), boss->getYPos(), 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(spriteBoss, NULL, &bossCenter, &bossPos, D3DCOLOR_ARGB(255, 255, 255, 255));

	//보스 HP
	RECT bossHpBar;
	SetRect(&bossHpBar, 0, 0, 800, 8);
	D3DXVECTOR3 bossHpCenter(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 hpBarPos(300, 3, 0.0f);
	d3dspt->Draw(sprite, &bossHpBar, &bossHpCenter, &hpBarPos, D3DCOLOR_ARGB(255, 255, 0, 0));

	RECT bossHp;
	SetRect(&bossHp, 0, 0, 1, 8);
	for (int i = 0; i < boss->getLife(); i++)
	{
		D3DXVECTOR3 hpPos(300+i, 3, 0.0f);
		d3dspt->Draw(sprite, &bossHp, &bossHpCenter, &hpPos, D3DCOLOR_ARGB(255, 0 ,255, 0));
	}

	

	////적 
	RECT part2;
	SetRect(&part2, 0, 0, 64, 64);
	D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	for (Enemy* enemy : enemies)
	{
		D3DXVECTOR3 position2(enemy->getXPos(), enemy->getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_enemy, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	d3dspt->End();    // end sprite drawing

	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);

	return;
}

void MainGame::update()
{
	//주인공 처리 
	hero->update();

	//보스
	boss->update();

	//적들 처리 
	auto& enemies = GameObject::getEnemies();
	for (Enemy* enemy : enemies)
	{
		enemy->update();
	}
	//총알 처리 
	auto& bullets = GameObject::getBullets();
	for (Bullet* bullet : bullets) {
		bullet->update();
	}

}
