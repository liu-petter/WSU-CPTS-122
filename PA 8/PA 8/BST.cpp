#include "BST.hpp"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::~BST()
{
	this->destroyTree(this->mpRoot);
}

Node* BST::getRoot(void) const
{
	return this->mpRoot;
}

void BST::setRoot(Node* newRoot)
{
	this->mpRoot = newRoot;
}

void BST::destroyTree(Node* pTree) 
{
	if (pTree != nullptr)
	{
		this->destroyTree(pTree->getLeft());
		this->destroyTree(pTree->getRight());
		delete pTree;
	}
}

void BST::insert(const string& newName, const int& newUnits)
{
	this->insert(newName, newUnits, this->mpRoot);
}

void BST::insert(const string& newName, const int& newUnits, Node*& pTree)
{
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(newName, newUnits);
	}
	else
	{
		if (newUnits < dynamic_cast<TransactionNode*> (pTree)->getUnits())
		{
			this->insert(newName, newUnits, pTree->getLeft());
		}
		else
		{
			this->insert(newName, newUnits, pTree->getRight());
		}
	}
}

void BST::inOrderTraversal()
{
	this->inOrderTraversal(this->mpRoot);
}

void BST::inOrderTraversal(Node* pTree)
{
	if (pTree != nullptr)
	{
		this->inOrderTraversal(pTree->getLeft());
		pTree->printData();
		this->inOrderTraversal(pTree->getRight());
	}
}

TransactionNode& BST::findSmallest()
{
	TransactionNode* pCurr = dynamic_cast<TransactionNode*> (this->mpRoot);
	while (pCurr->getLeft() != nullptr)
	{
		pCurr = dynamic_cast<TransactionNode*> (pCurr->getLeft());
	}
	return *pCurr;
}
TransactionNode& BST::findLargest()
{
	TransactionNode* pCurr = dynamic_cast<TransactionNode*> (this->mpRoot);
	while (pCurr->getRight() != nullptr)
	{
		pCurr = dynamic_cast<TransactionNode*> (pCurr->getRight());
	}
	return *pCurr;
}