#include <stdexcept>
#include <string>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

#include "connectioninterface.h"
#include "networkconnection.h"

class Firewall : public ConnectionInterface
{
	private:
        NetworkConnection* realConnection = nullptr;
	    int allowedPorts[2] = {80, 8080}; 
	
        bool isPortAllowed(int port)
        {
            bool allowed = std::any_of(std::begin(allowedPorts), std::end(allowedPorts), [&](int i)
            {
                return i == port;
            });
            return allowed;
        }
    public:
        // Firewall(NetworkConnection* conn) : realConnection(conn) {} // apporach 1, good for testing

        void open(std::string address, int port) override
        {
            if(realConnection != nullptr)
            {
                 // better: only when you need it, substitute
                realConnection = new NetworkConnection();
            }

            if(isPortAllowed(port))
                realConnection->open(address, port);
            else
                throw std::invalid_argument("The port is not allowed: " + port);	
        }
	    void close() override
        {
            if(realConnection != nullptr)
	            realConnection->close();		
	    }
};
