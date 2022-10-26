#include <iostream>

class SelfDrivingSystem
{
    public:
        virtual void goForward() // default behaviour
        {
            std::cout << "Going forward." << std::endl;
        }

        virtual void goBackward()
        {
            std:: cout << "Going backwards." << std::endl;
        }

        virtual void turnLeft()
        {
            std::cout << "Turning left." << std::endl;
        }

        virtual void turnRight()
        {
            std::cout << "Turning right." << std::endl;
        }
};

class Car : public SelfDrivingSystem
{
    public:
        void goForward() override
        {
            std::cout << "Pushing pedal down." << std::endl;
        }
        
        void goBackward() override
        {
            std::cout << "Step on brake pedal." << std::endl;
        }

        void turnLeft() override
        {
            std::cout << "Steering left." << std::endl;
        }

        void turnRight() override
        {
            std::cout << "Steering right." << std::endl;
        }

};

class Train : public SelfDrivingSystem
{
    public:
        void goForward() override
        {
            std::cout << "moving throttle down." << std::endl;
        }
        
        void goBackward() override
        {
            std::cout << "moving throttle up." << std::endl;
        }

        void turnLeft() override
        {
            throw std::logic_error("no such function");
        }

        void turnRight() override
        {
            throw std::logic_error("no such function");
        }
};

int main()
{
    Car z4roadster;
    std::cout << "Car is " << std::endl;
    z4roadster.goForward();
    z4roadster.turnLeft();

    std::cout << "---------------" << std::endl;

    Train ice;
    std::cout << "Train is " << std::endl;
    ice.goForward();
    ice.turnLeft();

}