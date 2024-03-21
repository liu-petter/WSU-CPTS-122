#include "utils.hpp"

template <class T>
class BSTNode
{
public:
	BSTNode(T newData);

	T getData(void) const;
	void setData(T newData);

	BSTNode<T>* getLeft(void) const;
	void setLeft(BSTNode<T>* newLeft);

	BSTNode<T>* getRight(void) const;
	void setRight(BSTNode<T>* newRight);

private:
	T mData;
	BSTNode<T>* mpLeft;
	BSTNode<T>* mpRight;
};

template <class T>
BSTNode<T>::BSTNode(T newData)
{
	this->mData = newData;
	this->mpLeft = this->mpRight = nullptr;
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

template <class T>
BSTNode<T>* BSTNode<T>::getLeft(void) const
{
	return this->mpLeft;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* newLeft)
{
	this->mpLeft = newLeft;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight(void) const
{
	return this->mpRight;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* newRight)
{
	this->mpRight = newRight;
}

template <class T>
std::ostream& operator<< (std::ostream& rhs, BSTNode<T>& lhs)
{
	rhs << lhs.getData();
	return rhs;
}