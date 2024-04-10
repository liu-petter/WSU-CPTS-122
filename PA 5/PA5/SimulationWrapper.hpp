#pragma once
#include "utils.hpp"
#include "Queue.hpp"
#include "Customer.hpp"

typedef enum _menuSelection
{
	START_SIM = 1,
	SET_N,
	EXIT,
} MenuSelection;

class SimulationWrapper
{
public:
	void run(void);
	MenuSelection displayMenu();	// returns input
	int getSimulationLoops();
	void startSim(int n);
	void updateTotalTime(Queue<Customer>& lane);
	void updateServiceTime(Queue<Customer>& lane);
	void updateHead(Queue<Customer>& lane);
	void updateLane(Queue<Customer>& lane);
private:
	Queue<Customer> expressLane, normalLane;
};