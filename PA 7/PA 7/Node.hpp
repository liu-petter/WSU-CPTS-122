template <class T>
class Node
{
public:
	Node(T newData, Node<T>*newNext = nullptr);
	~Node();

	Node<T>* getNext() const;
	void setNext(Node<T>* newNext);

	T getData() const;
	void setData(T newData);

private:
	Node<T>* mpNext;
	T mData;
};

template <class T>
Node<T>::Node(T newData, Node<T>* newNext)
{
	mpNext = newNext;
	mData = newData;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return mpNext;
}

template <class T>
void Node<T>::setNext(Node<T>* newNext)
{
	mpNext = newNext;
}

template <class T>
T Node<T>::getData() const
{
	return mData;
}

template <class T>
void Node<T>::setData(T newData)
{
	mData = newData;
}