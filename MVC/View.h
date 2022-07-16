#ifndef VIEW_H
#define VIEW_H

#include "Model.h"
#include <string>

namespace mvc
{
	class View 
	{
		public:
			void display();
			void update(const std::string& data);
	};
}
#endif /* VIEW_H */
