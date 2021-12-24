#include "Weakening.h"
namespace TowerDefence
{
	void Weakening::invoke(Enemy& target) override
	{
		float percent = get_power();
		target.set_scale_damage(percent);
	}
}