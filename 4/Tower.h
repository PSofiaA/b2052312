#pragma once
#include "Construction.h"
#include "Strategy.h"
namespace TowerDefence
{
	class Tower : public Construction
	{
	private:
		int damage;
		int rate_of_fire;
		Strategy* strategy;
	public: 
		void attack(Enemy& target) override
		{
			target.take_damage(damage);
		}
	};
}