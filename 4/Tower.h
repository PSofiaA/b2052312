#pragma once
#include "Construction.h"
#include "Strategy.h"
namespace TowerDefence
{
	class Tower : public Construction
	{
	protected:
		int damage;
		int rate_of_fire;
		Strategy* strategy;
	public:
		void attack(Enemy& target) override;
	};
}