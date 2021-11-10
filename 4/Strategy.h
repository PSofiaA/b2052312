#pragma once
namespace TowerDefence
{
	class Strategy {
	private: 
		int damage;
	public:
		virtual void apply();
	};
}