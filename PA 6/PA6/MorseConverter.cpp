#include "MorseConverter.hpp"

void MorseConverter::runConverter(std::ifstream& morseTable, std::ifstream& convertFile)
{
	this->initTree(morseTable);

	string line = "";
	while (getline(convertFile, line))
	{
		int index = 0;
		while (line[index] != '\0')
	 	{
			cout << this->searchTree(toupper(line[index])) << " ";
			index++;
		}
	}
}

void MorseConverter::initTree(std::ifstream& morseTable)
{
	char tempC;
	string tempM;
	for (int i = 0; i < 39; i++)
	{
		morseTable >> tempC;
		morseTable >> tempM;
		Data newNode(tempC, tempM);
		this->mSearchTree.insert(newNode);
	}
}

string MorseConverter::searchTree(char target)
{
	return this->searchTree(target, this->mSearchTree.getRoot());
}

string MorseConverter::searchTree(char target, BSTNode<Data>* pTree)
{
	string morse = "";
	if (pTree == nullptr)
	{
		return "";
	}
	else if (pTree->getData().getChar() == target)
	{	// character found
		return pTree->getData().getMorse();
	}
	else
	{
		if (pTree->getData().getChar() > target)
		{	// go to left child
			morse = searchTree(target, pTree->getLeft());
		}
		else if (pTree->getData().getChar() < target)
		{	// go to right child
			morse = searchTree(target, pTree->getRight());
		}
	}
	return morse;
}