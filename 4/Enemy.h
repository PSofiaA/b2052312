#pragma once
#include <vector>
using std::vector;

namespace TowerDefence
{
	class Enemy : public StatefulObject
	{
	private:
		float scale_damage;
		int speed;
		TERRAIN type;
		vector<Effect*> acting_effects;
	public:
		Enemy(int id, int hp, int mhp, int g, ObjectState state, float sd, int sp, TERRAIN t) :
			StatefulObject(id, hp, mhp, g, state), scale_damage(sd), speed(sp), type(t) {};
		
		vector<Effect*>* get_effects() const noexcept
			{   if (acting_effects.size()) return &acting_effects;
				else return nullptr};
		float get_scale_damage() const { return scale_damage; }
		int get_speed() const { return speed; }
	
		void set_scale_damage(float d) { scale_damage = d; }	
		void set_speed(int s) { speed = s; }
	
		void update();
		void take_effect(Effect&);
	};
}