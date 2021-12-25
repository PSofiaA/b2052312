#include "Tower.h"
namespace TowerDefence
{
	//Enemy& choose_target()
	void Tower::attack(Enemy& target) override
	{
		target.take_damage(damage);
	}
}