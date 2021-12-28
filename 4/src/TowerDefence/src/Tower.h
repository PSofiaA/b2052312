#pragma once
#include "Construction.h"
#include "Enemy.h"
#include "Level.h"
namespace TowerDefence
{
	class Tower : public Construction
	{
	protected:
		int damage;
		int rate_of_fire;
		//Strategy* strategy;
	public:
		Tower(int pr, int x, int y, TYPE t) : Construction(2, pr, 1, FIELD, x, y, t), damage(3), rate_of_fire(3) {};

		void attack(Enemy& target) override;
		void levelup(int gold);
		//Tile* choose_target(Level& level) override;
		//virtual Enemy& choose_target(Level* level) override;
	};
}