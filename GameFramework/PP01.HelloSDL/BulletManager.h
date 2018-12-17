#pragma once

#include "Bullet.h"

#include <vector>

class BulletManager
{
public:
	static BulletManager * Instance();

	void update();
	void draw();

	void shootBullet(Bullet * bullet);
	void deleteBullet(Bullet * bullet);

	std::vector<Bullet *> getBullets() const;

private:
	BulletManager();

	static BulletManager * _instance;

	std::vector<Bullet *> _bullets;
};