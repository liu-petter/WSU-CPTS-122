#include "Node.hpp"

class TransactionNode : public Node
{
public:
	TransactionNode(const string& newData, const int& newUnits);
	~TransactionNode();

	int getUnits(void) const;
	void setUnits(const int& newUnits);
	void printData();

private:
	int mUnits;
};