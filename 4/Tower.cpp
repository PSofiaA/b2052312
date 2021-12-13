#include "Tower.h"
namespace TowerDefence
{
	void Tower::attack(Enemy& target) override
	{
		target.take_damage(damage);
	}
}