#pragma once
#include "Tower.h"
#include "Magic.h"
namespace TowerDefence
{
	class MagicTower : public Tower, public Magic
	{
	public:
	public:
		void attack(Enemy& target) override
		{
			target.take_damage(damage);
			target.apply_effect(effect);
		}
	};
}