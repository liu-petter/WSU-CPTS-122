#pragma once
#include "utils.hpp"

template <class T>
class Node
{
public:
	Node(T newData);
	Node<T>* getNextPtr() const;
	void setNextPtr(Node<T>* newNextPtr);
	T getData() const;
	void setData(T& newData);

	~Node();
private:
	Node* mpNext;
	T mData;
};

template <class T>
Node<T>::Node(T newData)
{
	this->mData = newData;
	this->mpNext = nullptr;
}

template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return this->mpNext;
}

template <class T>
void Node<T>::setNextPtr(Node<T>* newNextPtr)
{
	this->mpNext = newNextPtr;
}

template <class T>
T Node<T>::getData() const
{
	return this->mData;
}

template<class T>
inline Node<T>::~Node()
{	
	
}

template<class T>
void Node<T>::setData(T& newData)
{
	this->mData = newData;
}