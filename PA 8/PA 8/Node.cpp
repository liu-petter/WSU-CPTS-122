#include "Node.hpp"

Node::Node(const string& newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node()
{
	
}

void Node::setData(const string& newData)
{
	this->mData = newData;
}

string Node::getData(void) const
{
	return this->mData;
}

void Node::setLeft(Node* newLeft)
{
	this->mpLeft = newLeft;
}

Node* Node::getLeft(void) const
{
	return this->mpLeft;
}

void Node::setRight(Node* newRight)
{
	this->mpRight = newRight;
}

Node* Node::getRight(void) const
{
	return this->mpRight;
}

void Node::printData()
{
	cout << this->mData << endl;
}