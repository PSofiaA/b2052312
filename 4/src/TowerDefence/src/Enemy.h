#pragma once
#include <vector>
#include "StatefulObject.h"
using std::vector;
namespace TowerDefence
{
	class Effect;
	class Enemy : public StatefulObject
	{
	private:
		int scale_damage;
		int speed;
		vector<Effect*> acting_effects;
	public:
		Enemy(int id, int hp, int maxhp, int g, ObjectState state, int sp, int X, int Y) :
			StatefulObject(id, hp, maxhp, g, state, ROAD, X, Y, ENEMY), scale_damage(0), speed(sp) {};
		
		vector<Effect*> get_effects() const noexcept
		{
			return acting_effects;
		};
		int get_scale_damage() const { return scale_damage; }
		int get_speed() const { return speed; }
	
		void set_scale_damage(int d) { scale_damage = d; }
		void set_speed(int s) { speed = s; }
	
		void update();
		void take_effect(Effect&);
		void take_damage(int) override;
	};
}