#include <iostream>

#include "View.h"

namespace mvc 
{
	void View::display() 
	{
		
	}

	void View::update(const std::string& data) 
	{
		std::cout << "Data:" << data << std::endl;
	}
} 
