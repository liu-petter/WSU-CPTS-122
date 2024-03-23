#include "utils.hpp"
#include "BST.hpp"
#include "Data.hpp"

class MorseConverter
{
public:
	void runConverter(std::ifstream& morseTable, std::ifstream& convertFile);
	string searchTree(char target);

private:
	BST<Data> mSearchTree;

	void initTree(std::ifstream& morseTable);
	string searchTree(char target, BSTNode<Data>* pTree);
};