#pragma once
#include "Tower.h"
#include "Magic.h"
namespace TowerDefence
{
	class MagicTower : public Tower, public Magic
	{
	public:
		MagicTower();
		void attack(Enemy& target) override;
}