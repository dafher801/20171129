#include "BulletManager.h"

BulletManager * BulletManager::_instance = nullptr;

BulletManager::BulletManager()
{
}

BulletManager * BulletManager::Instance()
{
	if (!_instance)
		_instance = new BulletManager;

	return _instance;
}

void BulletManager::update()
{
	for (Bullet * iter : _bullets)
	{
		iter->update();

		if (iter->getPosition().getY() < 0 || iter->getPosition().getY() > 600)
		{
			deleteBullet(iter);
		}
	}
}

void BulletManager::draw()
{
	for (Bullet * iter : _bullets)
		iter->draw();
}

void BulletManager::shootBullet(Bullet * bullet)
{
	_bullets.push_back(bullet);
}

void BulletManager::deleteBullet(Bullet * bullet)
{
	for (std::vector<Bullet *>::iterator iter = _bullets.begin();
		iter != _bullets.end(); iter++)
	{
		if (*iter == bullet)
		{
			_bullets.erase(iter);
			break;
		}
	}
}

std::vector<Bullet*> BulletManager::getBullets() const
{
	return _bullets;
}
