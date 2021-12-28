#pragma once
#include "Construction.h"
#include "Magic.h"
#include "Enemy.h"
namespace TowerDefence
{
	class MagicTrap : public Construction, public Magic
	{
	public:
		MagicTrap(int price, int x, int y, Effect* effect) : Construction(1, price, 1, ROAD, x, y, TRAP), Magic(effect) {};
		void attack(Enemy& target) override;
	};
}