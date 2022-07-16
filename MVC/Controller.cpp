#include <string>

#include "Controller.h"

using namespace std;

namespace mvc 
{

	Controller::Controller(Model m, View v) 
	{	
		_model = m;
		_view = v;
	}

	void Controller::update()
	{
		_view.update(_model.getData());
	}

	void Controller::setData(const std::string& data)
	{
		_model.setData(data);
	}


} 

