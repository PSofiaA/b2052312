#include "Enemy.h"

namespace TowerDefence
{
	void Enemy::update()
	{
		for (auto effect : acting_effects)
		{
			effect->invoke(*this);
			if (effect->get_duration() == 0)
				delete effect;
		}
	}
	void Enemy::take_effect(Effect& effect)
	{
		this->acting_effects.push_back(effect);
	}
}