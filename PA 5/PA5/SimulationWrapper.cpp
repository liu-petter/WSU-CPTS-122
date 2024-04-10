#include "SimulationWrapper.hpp"

void SimulationWrapper::run(void)
{
	MenuSelection userInput;
	int n = -1;

	do
	{
		userInput = this->displayMenu();

		switch(userInput)
		{
		case START_SIM:
			this->startSim(n);
			break;
		case SET_N:
			n = this->getSimulationLoops();
			break;
		case EXIT:
			break;
		default:
			cout << "Input Error" << endl;
		}
		system("cls");
	} while (userInput != EXIT);
}

MenuSelection SimulationWrapper::displayMenu()
{
	MenuSelection userInput;

	do
	{
		cout << "Shopping Queue Simulator" << endl << endl;
		cout << "1) Start simulation" << endl;
		cout << "2) Set number of iterations" << endl;
		cout << "3) Exit" << endl << endl;
		cout << "Input: ";

		scanf("%d", &userInput);
		system("cls");
	} while (userInput < 1 || userInput > 3);
	return userInput;
}

int SimulationWrapper::getSimulationLoops()
{
	int n = 0;
	do
	{
		cout << "Enter number of loops: ";
		cin >> n;
		system("cls");
	} while (n < 0);
	return n;
}

void SimulationWrapper::startSim(int n)
{
	int expressArrivalTime = rand() % 5 + 1, normalArrivalTime = rand() % 6 + 3, UUID = 0;
	if (n == -1)
	{	// user did not specify n
		n = getSimulationLoops();
	}

	for (int time = 0; time < n; time++)
	{	// main simulation loop
		cout << "Time: " << time << endl;

		updateLane(this->expressLane);
		updateLane(this->normalLane);

		if (time % 1440 == 0 && time != 0)
		{	// resets each day
			expressLane.~Queue();
			normalLane.~Queue();
			expressArrivalTime = rand() % 5 + 1;
			normalArrivalTime = rand() % 6 + 3;
			cout << "\tDAY RESET" << endl;
		}

		if (time != 0 && time % 10 == 0)
		{	// print lanes every 10 units of time
			cout << "	EXPRESS LANE: ";
			this->expressLane.printQueue();
			cout << endl << "	NORMAL LANE: ";
			this->normalLane.printQueue();
			cout << endl;
		}

		if (expressArrivalTime == 0)
		{	
			// add to queue
			Customer newCustomer(UUID, rand() % 5 + 1, 0);
			this->expressLane.enqueue(newCustomer);

			cout << "	Customer " << UUID << " queued into Express Lane" << endl;

			// update UUID
			UUID++;

			// generate new arrival time
			expressArrivalTime = rand() % 5 + 1;	// 1-5
		}
		if (normalArrivalTime == 0)
		{
			// add to queue
			Customer newCustomer(UUID, rand() % 6 + 3, 0);
			this->normalLane.enqueue(newCustomer);

			cout << "	Customer " << UUID << " queued into Normal Lane" << endl;

			// update UUID
			UUID++;

			// generate new arrival time
			normalArrivalTime = rand() % 6 + 3;		// 3-8
		}

		// decrement arrival times
		expressArrivalTime--;
		normalArrivalTime--;
	}
	system("pause");
}

void SimulationWrapper::updateTotalTime(Queue<Customer>& lane)
{
	Node<Customer>* pCurr = lane.getHead();

	while (pCurr != nullptr)
	{	// increase total time
		int totalTime = pCurr->getData().getTotalTime();
		Customer customer(pCurr->getData().getCustomerID(), pCurr->getData().getServiceTime(), ++totalTime);
		pCurr->setData(customer);

		pCurr = pCurr->getNextPtr();
	}
}

void SimulationWrapper::updateServiceTime(Queue<Customer>& lane)
{
	Node<Customer>* pHead = lane.getHead();
	if (pHead != nullptr)
	{
		int serviceTime = pHead->getData().getServiceTime();
		Customer temp(pHead->getData().getCustomerID(), --serviceTime, pHead->getData().getTotalTime());
		pHead->setData(temp);
	}
}

void SimulationWrapper::updateHead(Queue<Customer>& lane)
{
	Node<Customer>* pHead = lane.getHead();
	Customer customer;

	if (pHead->getData().getServiceTime() <= 0)
	{
		customer = lane.dequeue();
		cout << "	Customer " << customer.getCustomerID() << " serviced. Total Time: " << customer.getTotalTime() << endl;
	}
}

void SimulationWrapper::updateLane(Queue<Customer>& lane)
{
	if (!lane.isEmpty())
	{
		updateServiceTime(lane);
		updateTotalTime(lane);
		updateHead(lane);
	}
}