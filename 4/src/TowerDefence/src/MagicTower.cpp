#include "MagicTower.h"
namespace TowerDefence
{
	void MagicTower::attack(Enemy& target) 
	{
			target.take_damage(damage);
			target.take_effect(*get_effect());
	}
}