#include "Tower.h"
#include <stdexcept>
#define LEVELUP 10
#define CONST 3
namespace TowerDefence
{
	void Tower::attack(Enemy& target)
	{
		target.take_damage(damage);
	}

	void Tower::levelup(int gold)
	{
		if (gold >= LEVELUP)
		{
			int buf = this->get_lvl();
			this->set_lvl(buf++);
			this->damage += CONST;
			this->rate_of_fire += CONST;
		}
		else
			throw std::runtime_error("Not enough money :(");
	}
	/* Enemy& Tower::choose_target(Level* level)
	{
		int tmp1, tmp2, tmp3, tmp4;
		int x = this->get_x();
		int y = this->get_y();
		int radius = this->get_radius();
		(x - radius) >= 0 ? tmp1 = (x - radius) : tmp1 = x;
		(y - radius) >= 0 ? tmp2 = (y - radius) : tmp2 = y;
		(x + radius) <= 5 ? tmp3 = (x + radius) : tmp3 = x;
		(y + radius) <= 5 ? tmp4 = (y + radius) : tmp4 = y;
		for (int i = tmp1; i < tmp3; i++)
			for (int j = tmp2; j < tmp4; j++)
			{
				if(level->get_tiles()[i][j]->get_object()->get_type() == ENEMY)
					return level->get_tiles()[i][j]->get_object();
			}
	}
	*/
}

	/*Tile* Tower::choose_target(Level* level)
	{
		int tmp1,tmp2,tmp3,tmp4;
		int x = this->get_x();
		int y = this->get_y();
		int radius = this->get_radius();
		(x - radius) >= 0 ? tmp1 = (x - radius) : tmp1 = x;
		(y - radius) >= 0 ? tmp2 = (y - radius) : tmp2 = y;
		(x + radius) <= 5 ? tmp3 = (x + radius) : tmp3 = x;
		(y + radius) <= 5 ? tmp4 = (y + radius) : tmp4 = y;
		for (int i = tmp1; i < tmp3; i++)
			for (int j = tmp2; j < tmp4; j++)
			{
				if (level.get_tiles()[i][j]->get_object()->get_type() == ENEMY)
					return level.get_tiles()[i][j];
			}
	}*/
