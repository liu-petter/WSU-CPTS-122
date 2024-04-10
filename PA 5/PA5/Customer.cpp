#include "Customer.hpp"

Customer::Customer(int newCustomerID, int newServiceTime, int newTotalTime)
{	// constructor
	this->mCustomerID = newCustomerID;
	this->mServiceTime = newServiceTime;
	this->mTotalTime = newTotalTime;
}

Customer::Customer(const Customer& copy)
{	// copy constructor
	this->mCustomerID = copy.mCustomerID;
	this->mServiceTime = copy.mServiceTime;
	this->mTotalTime = copy.mTotalTime;
}

Customer::~Customer()
{	// destructor

}

int Customer::getCustomerID() const
{
	return this->mCustomerID;
}

void Customer::setCustomerID(int newCustomerID)
{
	this->mCustomerID = newCustomerID;
}

int Customer::getServiceTime() const
{
	return this->mServiceTime;
}

void Customer::setServiceTime(int newServiceTime)
{
	this->mServiceTime = newServiceTime;
}

int Customer::getTotalTime() const
{
	return this->mTotalTime;
}

void Customer::setTotalTime(int newTotalTime)
{
	this->mTotalTime = newTotalTime;
}

ostream& operator<< (ostream& lhs, Customer& rhs)
{
	lhs << "ID:" << rhs.getCustomerID() << " ST:" << rhs.getServiceTime() << " TT:" << rhs.getTotalTime();
	return lhs;
}