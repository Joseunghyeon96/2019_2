#include "stdafx.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Hero.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Boss.h"
#include "UI.h"

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

	ui = UI::GetSingleton();
	ui->init(hero,boss);
}

void MainGame::renderFrame()
{

	auto& enemies = GameObject::getEnemies();
	auto& bullets = GameObject::getBullets();
	auto& enemyBullets = GameObject::getEnemyBullets();
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // // begin sprite drawing with transparency


	RECT part0;
	SetRect(&part0, 0, 0, 1024, 1024);
	D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position0(0.0f, 0.0f, 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));


	//주인공 
	RECT part;
	SetRect(&part, 0, 0, 64, 64);
	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position = D3DXVECTOR3(hero->getXPos(), hero->getYPos(), 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite_hero, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));

	////총알 
	for (Bullet* bullet : bullets) {

		RECT part1;
		D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 position1(bullet->getXPos(), bullet->getYPos(), 0.0f);
		switch (bullet->getDamage())
		{

		case 1:
			SetRect(&part1, 0, 0, 16, 16);
			if (bullet->getEnabled())
				d3dspt->Draw(sprite_bullet[0], &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			SetRect(&part1, 0, 0, 32, 32);
			if (bullet->getEnabled())
				d3dspt->Draw(sprite_bullet[1], &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 3:
			SetRect(&part1, 0, 0, 64, 64);
			if (bullet->getEnabled())
				d3dspt->Draw(sprite_bullet[2], &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
	}

	//보스
	RECT bossRect;
	SetRect(&bossRect, 0, 0, 512, 256);
	D3DXVECTOR3 bossCenter(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 bossPos(boss->getXPos(), boss->getYPos(), 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(spriteBoss,&bossRect, &bossCenter, &bossPos, D3DCOLOR_ARGB(255, 255, 255, 255));

	////적 
	RECT part2;
	SetRect(&part2, 0, 0, 64, 64);
	D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	for (Enemy* enemy : enemies)
	{
		D3DXVECTOR3 position2(enemy->getXPos(), enemy->getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_enemy, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	//적 총알

	RECT eBulletRect;
	SetRect(&eBulletRect, 0, 0, 20, 20);
	D3DXVECTOR3 eBulletCenter(0.0f, 0.0f, 0.0f);
	for (EnemyBullet* eBullet : enemyBullets)
	{
		D3DXVECTOR3 eBulletPos(eBullet->getXPos(), eBullet->getYPos(), 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(enemyBullet, &eBulletRect, &eBulletCenter, &eBulletPos, D3DCOLOR_ARGB(255, 255, 255, 255));
	}

	//폭발
	RECT explosionRect;
	SetRect(&explosionRect, 0, 0, 64, 64);
	D3DXVECTOR3 explosionCenter(0.0f, 0.0f, 0.0f);
	for (Bullet* bullet : bullets) {
		D3DXVECTOR3 explosionPos(bullet->getXPos() - 32, bullet->getYPos(), 0.0f);    // position at 50, 50 with no depth
		if (bullet->getExplosion()) {
			if (bullet->getRePaint() == true) {
				d3dspt->Draw(bulletExplosion, &explosionRect, &explosionCenter, &explosionPos, D3DCOLOR_ARGB(255, 255, 255, 255));
				bullet->setRePaint(true);
			}
		}
	}

	ui->renderUI(d3dspt);

	d3dspt->End();    // end sprite drawing

	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);

	return;
}

void MainGame::Release()
{
	this->ReleaseSingleton();
	ui->ReleaseSingleton();
}

void MainGame::update()
{
	//주인공 처리 
	hero->update();

	//총알 처리 
	auto& bullets = GameObject::getBullets();
	for (Bullet* bullet : bullets) {
		bullet->update();
	}

	//보스
	boss->update();

	//적들 처리 
	auto& enemies = GameObject::getEnemies();
	for (Enemy* enemy : enemies)
	{
		enemy->update();
	}

	auto& enemyBullets = GameObject::getEnemyBullets();
	for (EnemyBullet* eBullet : enemyBullets)
	{
		eBullet->update();
	}

}
