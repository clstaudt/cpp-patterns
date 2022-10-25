#include <iostream>
#include <vector>

class Subject;

/*
 * Observer
 * defines an updating interface for objects that should be notified
 * of changes in a subject
 */
class Observer
{
public:
    virtual ~Observer() {}

    virtual int getState() = 0;
    virtual void update(Subject* subject) = 0;
};

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class Rider : public Observer
{  
  private:
      int observer_state;
  public:
      Rider(const int state) : 
        observer_state(state) 
      {

      }

      int getState() override
      {
          return observer_state;
      }
      void update(Subject* subject);
};

/*
 * Subject
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
class Subject
{
  private:
      std::vector<Observer*> observers;
  public:
      virtual ~Subject() {}

      void attach( Observer *observer )
      {
          observers.push_back(observer);
      }

      void detach( const int index )
      {
          observers.erase(observers.begin() + index);
      }

      void notify()
      {
          for (int i = 0; i < observers.size(); i++)
              observers.at(i)->update(this);
      }

      virtual int getState() = 0;
      virtual void setState(const int s) = 0;
};

/*
 * Concrete Subject
 * stores state that should stay consistent with the subject's
 */
class PEV : public Subject
{
  public:
    int getState() override
    {
        return subject_state;
    }

    void setState(const int s) override
    {
        subject_state = s;
    }

private:
    int subject_state;
};

void Rider::update(Subject* subject)
{
    observer_state = subject->getState();
    std::cout << "Rider state updated." << std::endl;
}

enum STATE { IDLE=0, BUSY=1, FREE=10};

int main()
{
    Rider rider1(STATE::IDLE);
    Rider rider2(STATE::IDLE);

    std::cout << "Rider 1 state: " << rider1.getState() << std::endl;
    std::cout << "Rider 2 state: " << rider2.getState() << std::endl;

    // rider1 and 2 subscribe for updates on vehicle (PEV)
    Subject* vehicle = new PEV();
    vehicle->attach(&rider1);
    vehicle->attach(&rider2);

    vehicle->setState(STATE::FREE);
    vehicle->notify();

    std::cout << "Rider 1 state: " << rider1.getState() << std::endl;

  

    std::cout << "Rider 2 state: " << rider2.getState() << std::endl;

    if(vehicle != nullptr)
      delete vehicle;
    
    return 0;
}