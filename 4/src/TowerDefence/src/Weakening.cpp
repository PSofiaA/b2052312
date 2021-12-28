#include "Weakening.h"
namespace TowerDefence
{
	void Weakening::invoke(Enemy& target)
	{
		int percent = get_power();
		target.set_scale_damage(percent);
	}
}