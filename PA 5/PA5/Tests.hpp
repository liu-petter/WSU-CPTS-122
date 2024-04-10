#include "utils.hpp"
#include "Queue.hpp"
#include "SimulationWrapper.hpp"

class Tests
{
public:
	void runTests();
private:
	void testEnqueueOnEmpty();
	void testEnqueueOnOneNode();
	void testDequeueOnOneNode();
	void testDequeueOnTwoNodes();
	void testSimulationDay();
};