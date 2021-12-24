#pragma once
#include "Construction.h"
#include "Magic.h"
namespace TowerDefence
{
	class MagicTrap : public Construction, public Magic
	{
	public:
		MagicTrap(int rad, int price, int level, int x, int y) : Construction(rad, price, level, ROAD, x, y) {};
		void attack(Enemy& target) override
		{
			target.apply_effect(effect);
		}
	};
}