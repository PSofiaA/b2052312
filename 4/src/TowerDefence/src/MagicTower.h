#pragma once
#include "Tower.h"
#include "Magic.h"
namespace TowerDefence
{
	class MagicTower : public Tower, public Magic
	{
	public:
		MagicTower(Effect* effect, int price, int x, int y) : Magic(effect), Tower(price, x, y, MAGICTOWER) {};
		void attack(Enemy& target) override;
	};
}