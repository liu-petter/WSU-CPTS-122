#include "TransactionNode.hpp"

TransactionNode::TransactionNode(const string& newData, const int& newUnits) : Node(newData)
{
	this->mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{

}

int TransactionNode::getUnits(void) const
{
	return this->mUnits;
}

void TransactionNode::setUnits(const int& newUnits)
{
	this->mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout << this->mData << ": " << this->mUnits << endl;
}