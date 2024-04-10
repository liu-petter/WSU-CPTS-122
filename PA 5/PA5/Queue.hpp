#pragma once

#include "utils.hpp"
#include "Node.hpp"

template <class T>
class Queue
{
public:
	Queue(Node<T>* newHeadPtr = nullptr, Node<T>* newTailPtr = nullptr);
	bool enqueue(T newData);// true, false
	T dequeue();
	bool isEmpty() const;
	void printQueue() const;
	Node <T>* getHead() const;

	~Queue();

private:
	Node<T>* mpHead, * mpTail;
	void destroyQueue();
};


template <class T>
Queue<T>::Queue(Node<T>* newHeadPtr, Node<T>* newTailPtr)
{
	this->mpHead = newHeadPtr;
	this->mpTail = newTailPtr;
}

template <class T>
bool Queue<T>::enqueue(T newData)
{
	Node<T>* pMem = new Node<T>(newData);
	bool success = false;
	if (pMem != nullptr)
	{
		success = true;
		if (this->mpHead == nullptr)
		{	// is first in queue
			this->mpHead = pMem;
		}
		else
		{	// connects node to next
			this->mpTail->setNextPtr(pMem);
		}
		this->mpTail = pMem;
	}
	return success;
}

template <class T>
T Queue<T>::dequeue()
{
	T data = this->mpHead->getData();
	Node<T>* pTemp = this->mpHead;
	if (this->mpHead == this->mpTail)
	{
		this->mpHead = this->mpTail = nullptr;
	}
	else
	{
		mpHead = mpHead->getNextPtr();
	}
	delete pTemp;
	return data;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return this->mpHead == nullptr;
}

template<class T>
inline Queue<T>::~Queue()
{
	destroyQueue();
}

template<class T>
inline void Queue<T>::destroyQueue()
{
	while (!this->isEmpty())
	{
		this->dequeue();
	}
}

template<class T>
void Queue<T>::printQueue() const
{
	Node<T>* pCurr = this->mpHead;
	while (pCurr != nullptr)
	{
		T data = pCurr->getData();
		cout << data << " | ";
		pCurr = pCurr->getNextPtr(); 
	}
}

template<class T>
Node<T>* Queue<T>::getHead() const
{
	return this->mpHead;
}