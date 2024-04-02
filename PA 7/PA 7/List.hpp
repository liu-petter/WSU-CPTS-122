#include "Node.hpp"

template <class T>
class List
{
public:
	List() {mpHead = nullptr;}
	~List();

	bool insertAtFront(T newData);

private:
	Node<T>* mpHead;
};

template <class T>
List<T>::~List()
{
	Node<T>* pCurr = mpHead, *pNext = pCurr->getNext();
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