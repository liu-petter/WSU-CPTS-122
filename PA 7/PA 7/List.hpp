#include "Node.hpp"

template <class T>
class List
{
public:
	List() {mpHead = nullptr;}
	~List();

	bool insertAtFront(T newData);

	void setHead(Node<T>* newHead);
	Node<T>* getHead() const;

private:
	Node<T>* mpHead;
};

template <class T>
List<T>::~List()
{
	Node<T>* pCurr = mpHead, *pNext = nullptr;
	while (pCurr != nullptr)
	{
		pNext = pCurr->getNext();
		delete pCurr;
		pCurr = pNext;
	}
}

template <class T>
bool List<T>::insertAtFront(T newData)
{
	bool success = false;
	Node<T>* pMem = new Node<T>(newData);

	if (pMem != nullptr)
	{	// space allocated
		success = true;
		pMem->setNext(mpHead);
		mpHead = pMem;
	}

	return success;
}

template <class T>
void List<T>::setHead(Node<T>* newHead)
{
	mpHead = newHead;
}

template <class T>
Node<T>* List<T>::getHead() const
{
	return mpHead;
}