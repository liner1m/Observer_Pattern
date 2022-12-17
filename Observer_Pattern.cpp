#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



///
/// Observers
///

class IObserver
{
public:
	virtual void notify() = 0;
};

// ObserverA

class ObserverA : public IObserver
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

// ObserverB

class ObserverB : public IObserver
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

// ObserverAB

class ObserverAB : public ObserverA, public ObserverB
{
public:
	void notifyA() override {
		cout << "notify_A" << endl;
	}
	void notifyB() override {
		cout << "notifiy_B" << endl;
	}
};




///
/// Senders
///

class ISender
{
protected:
	IObserver* observer;

	virtual void sendEvent() = 0;

public:
	void setObserverA(ObserverA* observerA)
	{
		this->observer = observerA;
	}

	void setObserverB(ObserverB* observerB)
	{
		this->observer = observerB;
	}
};

// SenderA

class SenderA : public virtual ISender
{
private:
	void sendEvent() override
	{
		sendEventA();
	}

public:
	void sendEventA()
	{
		static_cast<ObserverA*> (observer)->notifyA();
	}
};

// SenderB

class SenderB : public virtual ISender
{
protected:
	void sendEvent() override
	{
		sendEventB();		
	}

public:
	void sendEventB()
	{
		static_cast<ObserverB*> (observer)->notifyB();
	}
};

// SenderAB

class SenderAB : public SenderA, public SenderB
{
public:
	void sendEvent() override
	{
		static_cast<ObserverA*> (observer)->notifyA();
		static_cast<ObserverB*> (observer)->notifyB();
	}
};



/// <summary>
/// /////
/// </summary>

class Game
{
public:
	Game()
	{
		SenderA senderA;
		SenderB senderB;
		SenderAB senderAB;

		ObserverA observerA;
		ObserverB observerB;
		ObserverAB observerAB;
		

		senderA.setObserverA(&observerA);
		senderA.sendEventA();

		senderA.setObserverB(&observerB);
		senderA.sendEventA();

		senderA.setObserverA(&observerAB);
		senderA.sendEventA();

		senderA.setObserverB(&observerAB);
		senderA.sendEventA();

	}
};

int main(int argc, char* argv[])
{
	Game game;	

	return 0;
}
