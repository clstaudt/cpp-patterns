#include <iostream>
#include <string>

//Car parts
class Wheel
{
    public:
        int size;
};

class Engine
{
    public:
        int ps;
};

class Body
{
    public:
        std::string shape;
};

//Final product -- a car 
class Car
{
    public:
        Wheel*   wheels[4];
        Engine*  engine;
        Body* body;
    
        void printSpecifications()
        {
            std::cout << "Body:" << body->shape << std::endl;
            std::cout << "Engine (PS):" << engine->ps << std::endl;
            std::cout << "Tire size:" << wheels[0]->size << "'" << std::endl;
        }
};

//Builder is responsible for constructing the smaller parts 
class Builder
{
    public:
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};

//Director is responsible for the whole process 
class Director
{
    Builder* builder = nullptr;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Car* getCar()
        {
            Car* car = new Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};

//Concrete Builder for Jeep SUV cars 
class SUVBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->ps = 400;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "SUV";
			return body;
        }
};

//Concrete builder for Nissan family cars 
class CityCarBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->ps = 85;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "hatchback";
			return body;
        }
};


int main()
{
    Car* car1 = nullptr; // Final product
	Car* car2 = nullptr; 

    //A director who controls the process 
    Director director;

    //Concrete builders 
    SUVBuilder suvBuilder;
    CityCarBuilder ccBuilder;

    //Build an SUV 
    std::cout << "SUV" << std::endl;
    director.setBuilder(&suvBuilder); // using SUV instance
    car1 = director.getCar();
    car1->printSpecifications();

    std::cout << std::endl;

    //Build a City Car 
    std::cout << "City Car" << std::endl;
    director.setBuilder(&ccBuilder); // using NissanBuilder instance
    car2 = director.getCar();
    car2->printSpecifications();
	
	if(car1 != nullptr)
		delete car1;

	if(car2 != nullptr)
		delete car2;

    return 0;
}