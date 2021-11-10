#pragma once
#include <string>
using std::string;

namespace TowerDefence
{
	class Castle
	{
	private:
		int durability;
		int max_durability;
		string name;
		int gold;
	public:
		Castle(string name, int durability, int max_durability, int gold);

		string get_name() const { return name; }
		int get_durability() const { return durability; }
		int get_max_durability() const { return max_durability; }
		int get_gold()const { return gold; }

		void set_name(string n) { name = n; }
		void set_HP(int d) { durability = d; }
		void set_max_HP(int md) { max_durability = md; }
		void set_gold(int g) { gold = g; }

		int take_damage(int damage);
	};
}