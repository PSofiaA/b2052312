#pragma once
class Deceleration: public Effect
{
public:
	Deceleration(EffectType t, int p, int dur, int maxd) : Effect(t,p,dur,maxd) {};
	void invoke(Enemy& target) override;
};