#ifndef MEAT
#define MEAT

#include <string>

namespace abstractfactorytoppings::meat
{

	//TODO: Create a Ham, Chicken and a Weisswurst class 
	// in the same folder
	class Meat
	{
	public:
		virtual std::string toString() = 0;
	};

}


#endif	//#ifndef MEAT
