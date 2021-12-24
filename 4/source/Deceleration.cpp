#include "Deceleration.h"
namespace TowerDefence
{
	void Deceleration::invoke(Enemy& target) override
	{
		int speed = target.get_speed();
		int effect = speed - (speed * this->power) / 100;
		(effect <= 0 )? (target.set_speed(0)) : (target.set_speed(effect));
	}
}