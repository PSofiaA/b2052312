#pragma once
#include "Effect.h"
namespace TowerDefence 
{
	class Deceleration : public Effect
	{
	public:
		Deceleration() : Effect(deceleration, 5, 5, 5) {};
		void invoke(Enemy& target) override;
	};
}