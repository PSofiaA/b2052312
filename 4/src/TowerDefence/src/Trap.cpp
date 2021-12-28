#include "Trap.h"
#include <stdexcept>
namespace TowerDefence
{
	void MagicTrap::attack(Enemy& target)
	{
		target.take_effect(*get_effect());
	}
}