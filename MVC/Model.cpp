#include <string>
#include <stdexcept>
#include <functional>
#include <vector>
#include <algorithm>

#include "Model.h"

using namespace std;

namespace mvc 
{
	const string& Model::getData() const 
	{
		return this->coreData;
	}

	void Model::setData(const string& coreData) 
	{
		this->coreData = coreData;
		notify();
	}

	Connection Model::connect(Listener l)
	{
		return listeners_.insert(listeners_.end(), l);
	}

	void Model::disconnect(Connection c) 
	{
		listeners_.erase(c);
	}

	void Model::notify() const 
	{
		for (const auto& listener : listeners_)
			listener(*this);
	}

} 

