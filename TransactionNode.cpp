#include "TransactionNode.h"

//constructor with inherited class Node variables
TransactionNode::TransactionNode(int passedUnits)
{
	units = passedUnits;
}

//getter
int TransactionNode::GetUnits()
{
	return units;
}

//setter
void TransactionNode::SetUnits(int &passedUnits)
{
	units = passedUnits;
}


/*********************************
       Member Functions*/

/*called from class BST member function InOrderTraversal()
Prints the data of the node to the screen*/
void TransactionNode::PrintData()
{
	cout << "Item: " << GetData() << "\nUnits: " << GetUnits();
	cout << "\n\n";
}


TransactionNode::~TransactionNode()
{
	//cout << "Inside TransitionNode destructor\n";
}