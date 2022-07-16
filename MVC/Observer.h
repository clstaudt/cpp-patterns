#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
 public:
  virtual ~Observer(){};
  virtual void update(const std::string &data = nullptr) = 0;
 // virtual void update() = 0;
};

#endif // OBSERVER_H