#ifndef PIZZATOPPINGFACTORY
#define PIZZATOPPINGFACTORY

#include "../topings/pepperoni/Pepperoni.h"
#include "../topings/sauce/Sauce.h"
#include "../topings/veggies/Veggies.h"
#include "../toppings/cheese/Cheese.h"
#include "../toppings/clams/Clams.h"
#include "../toppings/dough/Dough.h"
#include "../toppings/meat/Meat.h"
#include <vector>

namespace abstractfactorytoppingfactory
{

	using Pepperoni = abstractfactorytopings::pepperoni::Pepperoni;
	using Sauce = abstractfactorytopings::sauce::Sauce;
	using Veggies = abstractfactorytopings::veggies::Veggies;
	using Cheese = abstractfactorytoppings::cheese::Cheese;
	using Clams = abstractfactorytoppings::clams::Clams;
	using Dough = abstractfactorytoppings::dough::Dough;
	using Meat = abstractfactorytoppings::meat::Meat;

	//TODO: Add the required method to the following interface
	class PizzaToppingFactory
	{

	public:
		virtual Dough* createDough() = 0;
		virtual Sauce* createSauce() = 0;
		virtual Cheese* createCheese() = 0;
		virtual std::vector<Veggies*> createVeggies() = 0;
		virtual Pepperoni* createPepperoni() = 0;
		virtual Clams* createClam() = 0;
		virtual Meat* createMeat() = 0;
	};

}


#endif	//#ifndef PIZZATOPPINGFACTORY
