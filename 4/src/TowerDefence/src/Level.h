#pragma once
#include "Enemy.h"
//#include "Lair.h"
#include "Castle.h"
#include "Tile.h"
using std::vector;

namespace TowerDefence
{	
	class Level
	{
	private:
		int moves;
		int width, height;
		vector<vector<Tile*>> tiles;
	public:
		int get_moves() { return moves; };
		int get_width() { return width; };
		int get_height() { return height; };

		void set_moves(int m) { moves = m; };
		void set_width(int w) { width = w; };
		void set_height(int h) { height = h; };
	};
}