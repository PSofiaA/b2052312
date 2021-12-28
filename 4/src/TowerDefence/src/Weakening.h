#pragma once
#include "Effect.h"
namespace TowerDefence
{
	class Weakening : public Effect
	{
	public:
		Weakening() : Effect(weakening, 3, 3, 3) {};
		 void invoke(Enemy& target) override;
	};
}