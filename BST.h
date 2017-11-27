#include "TransactionNode.h"

class BST
{
private:
	Node *pRoot;

	//these 4 variables are for findint the most/least sold/purchased items
	int tempMostUnits;
	string tempMostItem;
	int tempLeastUnits;
	string tempLeastItem;

	void DestroyTree();
	void Insert(Node *&pRoot, TransactionNode *&pTransactionNode);
	void InOrderTraversal(Node *&pTree);

public:
	//constructor
	BST(TransactionNode *passedRootNode = nullptr, int tempMostUnits = 0, string tempMostItem = "", int tempLeastUnits = 900000, string tempLeastItem = "");

	//destructor - calls DestroyTree()
	~BST();

	/*public used to hide pointer information, i.e.
	won’t pass in the root of the tree into this function, only
	the private insert () function*/
	void Insert(TransactionNode *&pTransactionNode);

	void InOrderTraversal();

	//getters and setters
	Node *GetPRoot();
	int GetMostTempUnits();
	string GetMostTempItem();
	int GetLeastTempUnits();
	string GetLeastTempItem();

	void SetPRoot(Node *&passedPRoot);
	void SetMostTempUnits(int &passedMostTempUnits);
	void SetMostTempItem(string &passedMostTempItem);
	void SetLeastTempUnits(int &passedLeastTempUnits);
	void SetLeastTempItem(string &passedLeastTempItem);
};