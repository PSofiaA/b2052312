#include "Poisoning.h"
namespace TowerDefence
{
	void Poisoning::invoke(Enemy& target)
	{
		int HP = target.get_HP();
		target.set_HP(HP - get_power());
	}
}