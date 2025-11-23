#include <iostream>
#include <string>
using namespace std;

class IEater {
public:
    virtual void eat() = 0;
    virtual ~IEater() = default;
};

class IFlyer {
public:
    virtual void fly() = 0;
    virtual ~IFlyer() = default;
};

class ISwimmer {
public:
    virtual void swim() = 0;
    virtual ~ISwimmer() = default;
};

class Dog : public IEater {
public:
    void eat() override {
        cout << "Dog is Eating\n";
    }
};

class Bird : public IEater, public IFlyer {
public:
    void eat() override {
        cout << "Bird is Eating\n";
    }
    void fly() override {
        cout << "Bird is Flying\n";
    }
};

class Fish : public IEater, public ISwimmer {
public:
    void eat() override {
        cout << "Fish is Eating\n";
    }
    void swim() override {
        cout << "Fish is Swimming\n";
    }
};

int main() {
    Dog d;
    Bird b;
    Fish f;

    d.eat();
    b.eat();
    b.fly();
    f.eat();
    f.swim();

    return 0;
}
