class Observer:
    def update(self, subject):
        pass

class Subject:
    def __init__(self):
        self._observers = []

    def attach(self, observer):
        self._observers.append(observer)

    def detach(self, observer):
        self._observers.remove(observer)

    def notify(self):
        for observer in self._observers:
            observer.update(self)

class ConcreteObserver(Observer):
    def update(self, subject):
        print("ConcreteObserver updated")

class ConcreteSubject(Subject):
    def __init__(self):
        super().__init__()
        self._state = None

    def set_state(self, state):
        self._state = state
        self.notify()

concrete_subject = ConcreteSubject()
observer = ConcreteObserver()
concrete_subject.attach(observer)
concrete_subject.set_state("new state")
