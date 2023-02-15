#include <iostream>
#include <vector>

class Subject;

/**
 * @brief Observer
 *
 * Defines an updating interface for objects that should be notified
 * of changes in a subject.
 */
class Observer
{
public:
    virtual ~Observer() {}

    /**
     * @brief Get the state of the observer
     *
     * @return int The state of the observer
     */
    virtual int getState() = 0;

    /**
     * @brief Update the observer with the given subject
     *
     * @param subject The subject that was updated
     */
    virtual void update(Subject* subject) = 0;
};

/**
 * @brief Concrete Observer
 *
 * Stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes.
 */
class Rider : public Observer
{
private:
    int observer_state;

public:
    /**
     * @brief Construct a new Rider object with the given state
     *
     * @param state The initial state of the rider
     */
    Rider(const int state) :
        observer_state(state)
    {

    }

    int getState() override
    {
        return observer_state;
    }

    void update(Subject* subject) override;
};

/**
 * @brief Subject
 *
 * Knows its observers and provides an interface for attaching
 * and detaching observers.
 */
class Subject
{
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}

    /**
     * @brief Attach an observer to this subject
     *
     * @param observer The observer to attach
     */
    void attach(Observer* observer)
    {
        observers.push_back(observer);
    }

    /**
     * @brief Detach an observer from this subject
     *
     * @param index The index of the observer to detach
     */
    void detach(const int index)
    {
        observers.erase(observers.begin() + index);
    }

    /**
     * @brief Notify all observers that the subject has been updated
     *
     */
    void notify()
    {
        for (int i = 0; i < observers.size(); i++)
            observers.at(i)->update(this);
    }

    /**
     * @brief Get the state of the subject
     *
     * @return int The state of the subject
     */
    virtual int getState() = 0;

    /**
     * @brief Set the state of the subject
     *
     * @param s The new state of the subject
     */
    virtual void setState(const int s) = 0;
};

/**
 * @brief Concrete Subject
 *
 * Stores state that should stay consistent with the subject's.
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

enum STATE { IDLE = 0, BUSY = 1, FREE = 10 };

int main()
{
    // Create two riders with initial state IDLE
    Rider rider1(STATE::IDLE);
    Rider rider2(STATE::IDLE);

    // Print the initial state of the riders
    std::cout << "Rider 1 state: " << rider1.getState() << std::endl;
    std::cout << "Rider 2 state: " << rider2.getState() << std::endl;

    // rider1 and 2 subscribe for updates on vehicle (PEV)
    Subject* vehicle = new PEV();
    vehicle->attach(&rider1);
    vehicle->attach(&rider2);

    // Change the state of the vehicle and notify the riders
    vehicle->setState(STATE::FREE);
    vehicle->notify();

    // Print the updated state of rider1 and rider2
    std::cout << "Rider 1 state: " << rider1.getState() << std::endl;
    std::cout << "Rider 2 state: " << rider2.getState() << std::endl;

    // Clean up the vehicle object
    if (vehicle != nullptr)
        delete vehicle;

    return 0;
}

