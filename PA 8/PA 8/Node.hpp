#include "includes.hpp"

class Node
{
public:
	Node(const string& newData);
	virtual ~Node();

	void setData(const string& newData);
	string getData(void) const;
	void setLeft(Node* newLeft);
	Node* getLeft(void) const;
	void setRight(Node* newRight);
	Node* getRight(void) const;

	virtual void printData() = 0;

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};