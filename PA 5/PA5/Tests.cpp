#include "Tests.hpp"

void Tests::runTests()
{
	testEnqueueOnEmpty();
	testEnqueueOnOneNode();
	testDequeueOnOneNode();
	testDequeueOnTwoNodes();
	system("pause");
	testSimulationDay();
}

void Tests::testEnqueueOnEmpty()
{
	Queue<int> q;

	q.enqueue(1);

	cout << "testEnqueueOnEmpty(): ";
	if (q.getHead()->getData() == 1)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}

}

void Tests::testEnqueueOnOneNode()
{
	Queue<int> q;

	q.enqueue(1);
	q.enqueue(2);

	cout << "testEnqueueOnOneNode(): ";
	if (q.getHead()->getNextPtr()->getData() == 2)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}
}

void Tests::testDequeueOnOneNode()
{
	Queue<int> q;

	q.enqueue(1);

	cout << "testDequeueOnOneNode(): ";
	if (q.dequeue() == 1)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}
}

void Tests::testDequeueOnTwoNodes()
{
	Queue<int> q;

	q.enqueue(1);
	q.enqueue(2);

	cout << "testDequeueOnTwoNodes(): ";
	if (q.dequeue() == 1 && q.dequeue() == 2)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}
}

void Tests::testSimulationDay()
{
	SimulationWrapper test;

	test.startSim(1441);
	system("cls");

	cout << "testSimulationDay(): success" << endl;
	system("pause");
	system("cls");
}