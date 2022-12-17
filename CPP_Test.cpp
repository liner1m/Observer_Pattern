#include <iostream>
#include <string>
#include <vector>
#include "Vector3D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Observer
{
public:
	virtual void notify() = 0;
};


class A : public Observer
{
private:
	void notify() override {
		notifyA();
	}

public:
	virtual void notifyA()
	{
		
	}
};

class B : public Observer
{
private:
	void notify() override {
		notifyB();
	}

public:
	virtual void notifyB() 
	{
		
	}
};


class AB : public A, public B
{
public:
	void notifyA() override {
		cout << "notify_A" << endl;
	}
	void notifyB() override {
		cout << "notifiy_B" << endl;
	}
};


class Sender
{
protected:
	Observer* observer;

	virtual void sendEvent() = 0;

public:
	void setObserverA(A* observerA)
	{
		this->observer = observerA;
	}

	void setObserverB(B* observerB)
	{
		this->observer = observerB;
	}
};

class SenderA : public Sender
{
protected:
	void sendEvent() override
	{
		static_cast<A*> (observer)->notifyA();
	}
};

class Game : public SenderA
{
public:
	Game()
	{
		AB ab;
		A a;
		B b;

		this->setObserverB(&ab);
		sendEvent();

		this->setObserverB(&b);
		sendEvent();

		this->setObserverA(&ab);
		sendEvent();

		this->setObserverA(&a);
		sendEvent();
	}
};

int main()
{
	Game game;	

	return 0;
}
