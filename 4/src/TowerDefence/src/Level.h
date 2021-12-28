#pragma once
#include "Tile.h"
#include "Castle.h"
#include <vector>
#include  <stdexcept>
using std::vector;
namespace TowerDefence
{	
	class Level
	{
	private:
		Castle* castle;
		int moves;
		int width, height;
		vector<vector<Tile*>> tiles;
	public:
		Level();
		~Level();
		void init();
		int get_moves() { return moves; };
		int get_width() { return width; };
		int get_height() { return height; };
		vector<vector<Tile*>> get_tiles();

		void set_moves(int m) { moves = m; };
		void set_width(int w) { width = w; };
		void set_height(int h) { height = h; };

		bool check_position(int x, int y);
		void add(Object*, int x, int y);
	};
}