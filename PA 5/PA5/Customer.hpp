#pragma once
#include "utils.hpp"

class Customer
{
public:
	Customer(int newCustomerID = -1, int newServiceTime = 0, int newTotalTime = 0);
	Customer(const Customer& copy);
	~Customer();

	int getCustomerID() const;
	void setCustomerID(int newCustomerID);
	int getServiceTime() const;
	void setServiceTime(int newServiceTime);
	int getTotalTime() const;
	void setTotalTime(int newTotalTime);

private:
	int mCustomerID;
	int mServiceTime;
	int mTotalTime;
};

ostream& operator<< (ostream& lhs, Customer& rhs);