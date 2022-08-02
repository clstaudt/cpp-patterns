#ifndef WEISSWURST
#define WEISSWURST

#include <string>

namespace abstractfactorytoppings::meat
{
	class Weisswurst : public Meat
	{
	public:
		std::string toString() override
		{
			return "Weisswurst";
		}
	};

}


#endif	//#ifndef WEISSWURST
