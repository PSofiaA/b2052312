#include "Enemy.h"
#pragma once
namespace TowerDefence
{
	class Weakening : public Effect
	{
	public:
		Weakening(EffectType t, int p, int dur, int maxd) : Effect(t, p, dur, maxd) {};
		void invoke(Enemy& target) override;
	};
}