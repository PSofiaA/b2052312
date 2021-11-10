#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Construction.h"
#include "castle.h"
#include "Level.h"
#include "Liar.h"

using std::string;
using std::vector;

namespace TowerDefence
{
	class Game
	{
	private:
		

	public:
		Game();
		void start(); //передать все для старта нового уровня
		void game_over();
		void new_level()
	};
}