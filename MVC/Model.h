#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <functional>
#include <list>

namespace mvc 
{
	class Model;

	using Listener = std::function<void(const Model&)>;
	using Connection = std::list<Listener>::iterator;

	class Model 
	{
		private:
			std::string coreData;
			std::list<Listener> listeners_;

			void notify() const;
		public:

			const std::string& getData() const;
			void setData(const std::string& name);

			Connection connect(Listener l);
			void disconnect(Connection c);
	};

} 
#endif /* MODEL_H */
