#pragma once

namespace TowerDefence
{
	class Magic
	{
	protected:
		Effect* effect;
	public:
		Magic(Effect* eff) : effect(eff) {};

		Effect* get_effect() { return effect; };
		void set_effect(Effect* e) { effect = e; };
	};
}