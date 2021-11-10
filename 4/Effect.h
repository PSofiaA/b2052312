#pragma once
#include "Enemy.h"
#include <string>
using std::string; 

namespace TowerDefence
{
	class Effect
	{
	private:
		string effect_type;
		int duration;
		int max_duration;
	public:
		int get_duration() const { return duration; };
		int get_max_duration() const { return max_duration;  };

		void set_duration(int d) { duration = d; };
		void set_max_duration(int md) { max_duration = md; };

		int number_of_effects(Enemy& target);
		int apply(Enemy& target);
	};
	
}