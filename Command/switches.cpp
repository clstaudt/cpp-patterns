#include <iostream>
#include <vector>
using namespace std;

const int MaxCommand = 5;

enum Receiver
{
	LIGHT = 0, FAN, DOOR, OVEN, NONE
}; 

// Command Interface
class LightSwitchCommand
{
	public:
		virtual void execute() = 0;
};
 
// Receiver Class
class Light 
{
	public:
		void turnOn() 
		{
			cout << "The light is on" << endl;
		}
		void turnOff() 
		{
			cout << "The light is off" << endl;
		}
}; 


// Command for turning on the light
class FlipUpCommand : public LightSwitchCommand 
{
	private:
		Light* theLight;
	public:
		FlipUpCommand(Light* light) : theLight(light) {}
		
		void execute()
		{
			theLight->turnOn();
		}
};
 
// Command for turning off the light
class FlipDownCommand : public LightSwitchCommand 
{
	private:
		Light* theLight;
	public:
        FlipDownCommand(Light *light) : theLight(light) {}
		
		void execute()
		{
			theLight->turnOff();
		}

};

// Invoker 
// Stores the ConcreteCommand object 
class Switch 
{
	private:
		vector<LightSwitchCommand*> mOnCommand;
		vector<LightSwitchCommand*> mOffCommand;
	
	public:
		Switch() 
			: mOnCommand(MaxCommand), mOffCommand(MaxCommand)
		{
			
		}
		
		void setCommand(Receiver id, LightSwitchCommand* onCmd, LightSwitchCommand* offCmd) 
		{
			mOnCommand[id] = onCmd;
			mOffCommand[id] = offCmd;
		}

		void onButtonPressed(Receiver id) 
		{
			mOnCommand[id]->execute();
		} 

		void offButtonPressed(Receiver id) 
		{
			mOffCommand[id]->execute();
		} 
};

// Client
int main() 
{
	// Receiver 
	Light* light = new Light;

	// concrete Command objects 
	FlipUpCommand* lightOn = new FlipUpCommand(light);
	FlipDownCommand* lightOff = new FlipDownCommand(light);

	// invoker objects
	Switch* sw = new Switch;

	// execute
	sw->setCommand(LIGHT, lightOn, lightOff);
	sw->onButtonPressed(LIGHT);
	sw->offButtonPressed(LIGHT);

	if(light != nullptr)
		delete light;
	if(lightOn != nullptr)	
		lightOn;
	if(lightOff != nullptr)
		delete lightOff;
	if(sw != nullptr)
		delete sw;

	return 0;
}