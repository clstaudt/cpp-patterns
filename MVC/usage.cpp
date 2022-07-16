#include <iostream>
#include "Controller.h"
#include "View.h"
#include "Model.h"

using namespace mvc;
using namespace std;

Model getModel() 
{
	Model m;
	m.setData("BMW");
	return m;
}

int main() 
{
	Model model = getModel();
	View view = View();

	// http://en.cppreference.com/w/cpp/language/lambda
	Connection c1 = model.connect([&] (const Model& mo) {
		view.display();
	});

	Controller controller = Controller(model, view);
	controller.setData("BMW X3");

	controller.update();

	return 0;
}

