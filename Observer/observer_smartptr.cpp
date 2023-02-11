#include <iostream>
#include <vector>
#include <memory>

class Subject;

class Observer {
 public:
  virtual void Update(std::shared_ptr<Subject> subject) = 0;
};

class Subject {
 public:
  void Attach(std::shared_ptr<Observer> observer) {
    observers_.push_back(observer);
  }

  void Detach(std::shared_ptr<Observer> observer) {
    observers_.erase(
        std::remove(observers_.begin(), observers_.end(), observer),
        observers_.end());
  }

  void Notify() {
    for (auto observer : observers_) {
      observer->Update(shared_from_this());
    }
  }

 private:
  std::vector<std::shared_ptr<Observer>> observers_;
};

class ConcreteSubject : public Subject {
 public:
  int state() const { return state_; }
  void set_state(int state) {
    state_ = state;
    Notify();
  }

 private:
  int state_;
};

class ConcreteObserver : public Observer {
 public:
  ConcreteObserver(std::shared_ptr<ConcreteSubject> subject)
      : subject_(subject) {
    subject_->Attach(shared_from_this());
  }

  void Update(std::shared_ptr<Subject> subject) override {
    auto concrete_subject = std::dynamic_pointer_cast<ConcreteSubject>(subject);
    if (concrete_subject) {
      std::cout << "ConcreteObserver: Subject's state is "
                << concrete_subject->state() << std::endl;
    }
  }

 private:
  std::shared_ptr<ConcreteSubject> subject_;
};
