#include "MorseConverter.hpp"

int main(void)
{
	MorseConverter m;
	std::ifstream morseTable, convertFile;
	morseTable.open("MorseTable.txt");
	convertFile.open("Convert.txt");

	m.runConverter(morseTable, convertFile);
	return 0;
}