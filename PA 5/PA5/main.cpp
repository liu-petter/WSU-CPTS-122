#include "SimulationWrapper.hpp"
#include "utils.hpp"
#include "Tests.hpp"

int main(void)
{
	srand((unsigned int)time(nullptr));	// init rand()

	Tests tests;
	tests.runTests();

	SimulationWrapper ShopSim;
	ShopSim.run();

	return 0;
}