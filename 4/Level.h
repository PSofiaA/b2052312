#pragma once
#include "Enemy.h"
#include "Liar.h"
#include "castle.h"
#include <list>
using std::list;

namespace TowerDefence
{	
	enum TERRAIN {
			ROAD, FIELD, FOREST
	};
	struct Tile {
		TERRAIN type;
		int size;

		Tile(TERRAIN b_type, int size);
		};
	class Level
	{
	private:
		int moves;
		int width, height;
		Castle* castle;
		Liar* liar;
		std::vector<Enemy*>  m_enemies;
	public:
		int get_moves() { return moves; };
		int get_width() { return width; };
		int get_height() { return height; };

		void set_moves(int m) { moves = m; };
		void set_width(int w) { width = w; };
		void set_height(int h) { height = h; };
	};
}