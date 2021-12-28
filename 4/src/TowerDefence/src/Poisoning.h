#pragma once
#include "Effect.h"
namespace TowerDefence
{
	class Poisoning : public Effect
	{
	public:
		Poisoning() : Effect(poisoning, 4, 4, 4) {};
		void invoke(Enemy& target) override;
	};
}