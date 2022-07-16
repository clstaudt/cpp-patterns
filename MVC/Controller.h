#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "Model.h"
#include "View.h"

namespace mvc 
{
	class Controller 
	{
		private:
			Model _model;
			View _view;
		public:
			Controller(Model model, View view);
			void setData(const std::string& data);
			void update();
	};

} 
#endif /* CONTROLLER_H */
