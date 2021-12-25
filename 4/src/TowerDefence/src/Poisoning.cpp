#include "Deceleration.h"
namespace TowerDefence
{
	void Poisoning::invoke(Enemy& target) override
	{
		int HP = target.get_HP();
		target.set_HP(HP - this->power);
	}
}