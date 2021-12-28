#pragma once
#include  <stdexcept>
#include "Enemy.h"
/*!
* @file
*/
namespace TowerDefence
{
	/*!
	* @enum Возможные типы эффектов \n
	* weakening - ослабление, скорость передвижения уменьшается на процент величины эффекта \n
	* poisoning - отравление, враг теряет количество здоровья равное величине эффекта \n
	* deceleration - замедление, урон, наносимый врагу увеличивает на процент величины эффекта \n
	*/
	enum EffectType
	{
		weakening,
		poisoning,
		deceleration
	};
	/*!
	* Класс эффекта, наносимого врагу, сооружениями класса Magic
	*/
	class Effect
	{
	protected:
		/*! 
		*Тип эффекта (ослабление, замедление или отравление)
		*/
		EffectType type;
		/* Величина эффекта
		*/
		int power;
		/*!
		*Оставшееся время действия эффекта
		*/
		int duration;
		/*! 
		* Время действия эффекта
		*/
		int max_duration;
	public:
		/*!
		* Конструктор
		*  @param t - тип эффекта \n
		*  @param p - величина эффекта\n
		*  @param dur - оставшееся время действия эффекта\n
		*  @param maxd - время действия эффекта\n
		*/
		Effect(EffectType t, int p, int dur, int maxd) : type(t), power(p), duration(dur), max_duration(maxd) {};
		~Effect() {};

		/*! 
		* Возвращает тип эффекта
		* @return элемент перечисляемого типа эффекта
		*/
		EffectType get_type() const noexcept { return type; };
		/*!
		* Возвращает величину эффекта
		*  @return int, величина эффекта
		*/
		int get_power() const noexcept { return power; };
		/*! 
		* Возвращает оставшееся время действия эффекта
		* @return int, оставшееся время действия эффекта
		*/
		int get_duration() const noexcept { return duration; };
		/*! 
		* Возвращает время действия эффекта
		* @return int, время действия эффекта
		*/
		int get_max_duration() const noexcept { return max_duration;  };

		/*!
		* Устанавливает тип эффекта
		*/
		void set_type(EffectType t) { type = t; };
		/*! 
		* Устанавливает величину эффекта
		* @throw std::invalid_argument если устанавливается нулевое либо отрицательное значение
		*/
		void set_power(int p)
		{ if (p <= 0) throw std::invalid_argument("Incorrect power!"); power = p; };
		/*! 
		* Устанавливает оставшееся время действия эффекта
		* @throw std::invalid_argument если устанавливается нулевое либо отрицательное значение
		*/
		void set_duration(int d)
		{ if (d > max_duration || d<0) throw std::invalid_argument("Incorrect duration"); duration = d; };
		/*!
		* Устанавливает время действия эффекта
		* @throw std::invalid_argument если устанавливается нулевое либо отрицательное значение
		*/
		void set_max_duration(int md)
		{
			if (md <= 0) throw std::invalid_argument("Incorrect max duration!"); max_duration = md;
		};

		/*!
		* Действие эффекта (различается в зависимости от типа эффекта)
		* @param - враг, на которого накладывается эффект
		* deceleration - уменьшает значение величины скорости врага
		* poisoning - уменьшает значение HP врага на величину эффекта
		* weakening - устанавливается значение scale_damage врага, влияющее на величину урона, наносимого врагу
		*/
		virtual void invoke(Enemy& target) = 0;
	};
	
}