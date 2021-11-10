#pragma once
#include <vector>
using std::vector;

namespace TowerDefence
{
	enum class EnemyState
	{
		Alive,
		Dead
	};
	class Enemy
	{
	private:
		int name;//or string?
		int HP;
		int max_HP;
		int speed;
		int gold;
	
		EnemyState state; 
		vector<Effect*> acting_effects;
	public:
		 int get_name() const { return name; }
		 int get_HP() const { return HP; }
		 int get_max_HP() const { return max_HP; }
		 int get_speed() const { return speed; }
		 int get_gold()const { return gold; }

		 void set_name(int n) { name = n; }
		 void set_HP(int hp) { HP = hp; }
		 void set_max_HP(int mh) {  max_HP = mh; }
		 void set_speed(int s) { speed = s; }
		 void set_gold(int g) { gold = g; }
		
		 void update()
		 {
			 for (Effect effect: acting_effects)
			 {
				 effect.invoke(this);
				 if (effect.get_duration() == 0)
					 delete effect;
			 }
		 }
		 void take_damage();
	};
}