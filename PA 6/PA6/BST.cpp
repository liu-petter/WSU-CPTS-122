#include "utils.hpp"
#include "BSTNode.hpp"

template <class T>
class BST
{
public:
	BST();

	void insert(T newData);

private:
	BSTNode<T>* mpRoot;

	void insert(BSTNode<T>* pTree, T newData);
};

template <class T>
BST<T>::BST()
{
	this->mpRoot = nullptr;
}

template <class T>
void BST<T>::insert(T newData)
{
	this->insert(this->mpRoot, newData);
}

template <class T>
void BST<T>::insert(BSTNode<T>* pTree, T newData)
{
	if (pTree == nullptr)
	{	// tree is empty
		this->mpRoot = new BSTNode<T>(newData);
	}
	else
	{
		if (newData < pTree->getData())
		{	// go left
			if (pTree->getLeft() == nullptr)
			{
				pTree->setLeft(new BSTNode<T>(newData));
			}
			else
			{	// go to left child
				insert(pTree->getLeft(), newData);
			}
		}
		else if (newData > pTree->getData())
		{	// go right
			if (pTree->getRight() == nullptr)
			{
				pTree->setRight(new BSTNode<T>(newData));
			}
			else
			{	// go to right child
				insert(pTree->getRight(), newData);
			}
		}
		else
		{
			cout << "duplicate value: " << newData << endl;
		}
	}
}