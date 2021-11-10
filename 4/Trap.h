#pragma once
#include "Construction.h"
#include "Magic.h"
namespace TowerDefence
{
	class MagicTrap : public Construction, public Magic
	{
	public:
	public:
		void attack(Enemy& target) override
		{
			target.apply_effect(effect);
		}
	};
}