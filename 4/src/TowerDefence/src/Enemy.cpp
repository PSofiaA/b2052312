#include "Enemy.h"
#include "Effect.h"
#include <math.h>
namespace TowerDefence
{
	void Enemy::update()
	{
		for (auto &effect : acting_effects)
		{
			effect->invoke(*this);
			if (effect->get_duration() == 0)
				delete effect;
		}
	}
	void Enemy::take_effect(Effect& effect)
	{
		this->acting_effects.push_back(&effect);
	}
	void Enemy::take_damage(int damg)
	{
		damg += round((static_cast<float>(damg * this->scale_damage)) / 100); 
		StatefulObject::take_damage(damg);
	}
}