#pragma once
#include <string>
#include <vector>
#include "Construction.h"
#include "castle.h"
#include "Level.h"
#include "Lair.h"

using std::string;
using std::vector;

namespace TowerDefence
{
	class Game
	{
	private:
		Lair* lair;
		std::vector<Enemy*>  enemies;

	public:
		Game();
		void start(); //передать все для старта нового уровня
		void game_over();
		void new_level();

	};
}