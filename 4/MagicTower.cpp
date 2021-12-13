#include "MagicTower.h"
namespace TowerDefence
{
	void MagicTower::apply_effect(Enemy& target) override
	{
		target.take_effect(this->effect);
	}
	void MagicTower::attack(Enemy& target) override
	{
			target.take_damage(damage);
			this->apply_effect(target);
	}
}