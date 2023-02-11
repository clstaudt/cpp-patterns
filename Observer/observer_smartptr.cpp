#include <iostream>
#include <vector>
#include <memory>

class Observer
{
public:
  virtual void Update(const std::shared_ptr<void>& subject) = 0;
};

class Subject
{
public:
  void Attach(const std::shared_ptr<Observer>& observer)
  {
    observers_.push_back(observer);
  }

  void Detach(const std::shared_ptr<Observer>& observer)
  {
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end())
      observers_.erase(it);
  }

  void Notify()
  {
    for (auto observer : observers_)
      observer->Update(shared_from_this());
  }

private:
  std::vector<std::shared_ptr<Observer>> observers_;
};

class ConcreteSubject : public Subject
{
public:
  void SetState(int state)
  {
    state_ = state;
    Notify();
  }

  int GetState() const
  {
    return state_;
  }

private:
  int state_;
};

class ConcreteObserver : public Observer, public std::enable_shared_from_this<ConcreteObserver>
{
public:
  ConcreteObserver(const std::shared_ptr<ConcreteSubject>& subject)
    : subject_(subject)
  {
    subject_->Attach(shared_from_this());
  }

  void Update(const std::shared_ptr<void>& subject) override
  {
    auto concrete_subject = std::dynamic_pointer_cast<ConcreteSubject>(subject);
    if (concrete_subject)
    {
      std::cout << "ConcreteObserver: Subject state is now " << concrete_subject->GetState() << std::endl;
    }
  }

private:
  std::weak_ptr<ConcreteSubject> subject_;
};

int main()
{
  auto subject = std::make_shared<ConcreteSubject>();
  auto observer = std::make_shared<ConcreteObserver>(subject);

  subject->SetState(42);

  return 0;
}
