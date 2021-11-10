#pragma once
#include <vector>
using std::vector;

namespace TowerDefence
{
	enum EnemyState
	{
		Dead,
		Alive
	};
	class Enemy
	{
	private:
	//	int name; or map
		int HP;
		int max_HP;
		int speed;
		int gold;
		TERRAIN type;
		EnemyState state; 
		vector<Effect*> acting_effects;
	public:
		// int get_name() const { return name; }
		 int get_HP() const { return HP; }
		 int get_max_HP() const { return max_HP; }
		 int get_speed() const { return speed; }
		 int get_gold()const { return gold; }

		// void set_name(int n) { name = n; }
		 void set_HP(int hp) { HP = hp; }
		 void set_max_HP(int mh) {  max_HP = mh; }
		 void set_speed(int s) { speed = s; }
		 void set_gold(int g) { gold = g; }
		
		 void update()
		 {
			 for (auto effect: acting_effects)//make constr for
			 {
				 effect->apply(*this);
				 if (effect->get_duration() == 0)
					 delete effect;
			 }
		 }
		 void take_damage(int damage); // 
		 void apply_effect(Effect* effect);
	};
}