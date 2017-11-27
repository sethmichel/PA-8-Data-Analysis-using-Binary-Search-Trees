#include "Node.h"

//inherit from class TransactionNode
class TransactionNode : public Node
{
private:
	int units;

public:
	//constructor - nodeData is protected variable from class Node
	TransactionNode(int units = 0);

	//destructor
	~TransactionNode();

	//overrides the pure cirtual function in class Node
	void PrintData();

	//getter and setter
	int GetUnits();
	void SetUnits(int &passedUnits);
};