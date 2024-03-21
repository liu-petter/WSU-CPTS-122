#include "utils.hpp"

template <class T>
class BSTNode
{
public:
	BSTNode(T newData);

	T getData(void) const;
	void setData(T newData);

private:
	T mData;
	BSTNode<T>* mpLeft;
	BSTNode<T>* mpRight;
};

template <class T>
BSTNode<T>::BSTNode(T newData)
{
	this->mData = newData;
}

template <class T>
T BSTNode<T>::getData(void) const
{
	return this->mData;
}

template <class T>
void BSTNode<T>::setData(T newData)
{
	this->mData = newData;
}