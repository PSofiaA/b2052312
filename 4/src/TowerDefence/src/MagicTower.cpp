#include "MagicTower.h"
namespace TowerDefence
{
	void MagicTower::attack(Enemy& target) override
	{
			target.take_damage(damage);
			target.take_effect(*get_effect());
	}
}