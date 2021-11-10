#pragma once
#include "Enemy.h"

namespace TowerDefence
{
	class Effect
	{
	private:
		int duration;
		int max_duration;
	public: //number of effects by size of cont
		Effect(int d, int md) 
		{
			duration = d;
			max_duration = md;
		};

		int get_duration() const { return duration; };
		int get_max_duration() const { return max_duration;  };

		void set_duration(int d) { duration = d; };
		void set_max_duration(int md) { max_duration = md; };

		virtual void apply(Enemy& target) = 0;
	};
	
}