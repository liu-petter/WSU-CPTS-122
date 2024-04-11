#include "TransactionNode.hpp"

class BST
{
public:
	BST();
	~BST();

	void insert(const string& newName = "", const int& newUnits = -1);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

	Node* getRoot(void) const;
	void setRoot(Node* newRoot);

private:
	Node* mpRoot;
	void destroyTree(Node* pTree);
	void insert(const string& newName, const int& newUnits, Node*& pTree);
	void inOrderTraversal(Node* pTree);
};