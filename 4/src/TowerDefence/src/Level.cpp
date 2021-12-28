#pragma once
#include "Level.h"
namespace TowerDefence
{
	Level::Level()
	{
		moves = 0;
		width = 5;
		height = 5;
		this->tiles = vector<vector<Tile*>>(width, vector<Tile*>(height));
		for (int i = 0; i < width; i++)  
			for (int j = 0; j < height; j++) 
			{
				this->tiles[i][j] = new Tile(NOTSTATED);
			}
		init();
	}
	Level::~Level()
	{
		for (int i = 0; i < width; i++)
			for (int j = 1; j < height; j++)
			{
				delete this->tiles[i][j];
			}
	}
	void Level::init()
	{
		this->castle = new Castle(FOREST, 0, 0);
		for (int i = 0; i < 5; i++)
			for (int j = 1; j < 3; j++)
			{
				this->tiles[i][j]->set_terrain(ROAD);
			}
		for (int i = 0; i < 5; i++)
		{
			this->tiles[i][4]->set_terrain(FOREST);
		}
		for (int i = 0; i < 4; i++)
		{
			this->tiles[i][3]->set_terrain(FIELD);
		}
		this->tiles[1][0]->set_terrain(ROAD);
		this->tiles[2][0]->set_terrain(FIELD);
		this->tiles[0][0]->set_terrain(FOREST);
		this->tiles[0][0]->set_object(this->castle);
		this->tiles[3][0]->set_terrain(FOREST);
		this->tiles[4][0]->set_terrain(FOREST);
		this->tiles[4][3]->set_terrain(FOREST);
	}

	vector<vector<Tile*>> Level::get_tiles()
	{
		return tiles;
	}
	bool Level::check_position(int x, int y) 
	{
		if (this->tiles[x][y]->get_object())
			return true;
	}
	void Level::add(Object* toset, int x, int y)
	{
		if (!check_position(x, y))
		{
			this->tiles[x][y]->set_object(toset);
		}
		else
			throw std::runtime_error("This position is taken! ");
	}
	/*void Level::levelup()
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (this->tiles[i][j]->get_object()->get_type() == CASTLE)
				{
					int gold = this->tiles[i][j]->get_object()->get_gold();

				}
			}
	}*/
	
}