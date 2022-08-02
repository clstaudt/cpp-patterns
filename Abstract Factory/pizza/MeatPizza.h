#ifndef MEATPIZZA
#define MEATPIZZA

#include "../toppingfactory/PizzaToppingFactory.h"
#include "Pizza.h"
#include <iostream>

namespace abstractfactorypizza
{

	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	class MeatPizza : public Pizza
	{
	public:
		PizzaToppingFactory* ingredientFactory;

		virtual ~MeatPizza()
		{
			delete ingredientFactory;
		}

		MeatPizza(PizzaToppingFactory* ingredientFactory)
		{
			this->ingredientFactory = ingredientFactory;
		}

		void prepare() override
		{
			std::cout << "Preparing " << name << std::endl;
			dough = ingredientFactory->createDough();
			sauce = ingredientFactory->createSauce();
			cheese = ingredientFactory->createCheese();
			meat = ingredientFactory->createMeat();
		}
	};

}


#endif	//#ifndef MEATPIZZA
