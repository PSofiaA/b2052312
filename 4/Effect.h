#pragma once
#include "Enemy.h"

namespace TowerDefence
{
	enum EffectType
	{
		Weakening,
		Poisoning,
		Deceleration
	};
	class Effect
	{
	protected:
		EffectType type;
		int power;
		int duration;
		int max_duration;
	public:
		Effect(EffectType t, int p, int dur, int maxd) : type(t), power(p), duration(dur), max_duration(maxd) {};
		~Effect() {};

		EffectType get_type() const noexcept { return type; };
		int get_power() const noexcept { return power; };
		int get_duration() const noexcept { return duration; };
		int get_max_duration() const noexcept { return max_duration;  };

		void set_type(EffectType t) { type = t; };
		void set_power(int p)
		{ if (p <= 0) throw std::invalid_argument("Incorrect power!"); power = p; };
		void set_duration(int d)
		{ if (d > max_duration || d<0) throw std::invalid_argument("Incorrect duration"); duration = d; };
		void set_max_duration(int md)
		{ if (md <= 0) throw std::invalid_argument("Incorrect max duration!") max_duration = md; };

		virtual void invoke(Enemy& target) = 0;
	};
	
}