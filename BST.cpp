#include "BST.h"

//constructor
BST::BST(TransactionNode *passedRootNode, int passedMostTempUnits, string passedMostTempData, int passedLeastTempUnits, string passedLeastTempData)
{
	pRoot = passedRootNode;
	tempMostUnits = passedMostTempUnits;
	tempMostItem = passedMostTempData;
	tempLeastUnits = 900000; //this compares to other nodes # of units and so it needs to be greater than them to start
	tempLeastItem = passedLeastTempData;
}

//getters
Node* BST::GetPRoot()
{
	return pRoot;
}

int BST::GetMostTempUnits()
{
	return tempMostUnits;
}

string BST::GetMostTempItem()
{
	return tempMostItem;
}

int BST::GetLeastTempUnits()
{
	return tempLeastUnits;
}

string BST::GetLeastTempItem()
{
	return tempLeastItem;
}


//setters
void BST::SetPRoot(Node *&passedPRoot)
{
	pRoot = passedPRoot;
}

void BST::SetMostTempUnits(int &passedMostTempUnits)
{
	tempMostUnits = passedMostTempUnits;
}

void BST::SetMostTempItem(string &passedMostTempItem)
{
	tempMostItem = passedMostTempItem;
}

void BST::SetLeastTempUnits(int &passedLeastTempUnits)
{
	tempLeastUnits = passedLeastTempUnits;
}

void BST::SetLeastTempItem(string &passedLeastTempItem)
{
	tempLeastItem = passedLeastTempItem;
}

/*******************************
      Member Functions*/

//PUBLIC INSERT FUNCTION
void BST::Insert(TransactionNode *&pTransactionNode)
{
	//Call the private insert()
	Insert(pRoot, pTransactionNode);
}

/*dynamically allocates a TransactionNode and inserts recursively in
the correct subtree based on units variable*/
//PRIVATE INSERT FUNCTION
void BST::Insert(Node *&pCurrent, TransactionNode *&pTransactionNode)
{
	//TransitionNode *pHold = dynamic_cast <TransitionNode *> (pCurrent);
	//no matter what, pTransactionNode will be inserted here
	if (pCurrent == nullptr)
	{
		pCurrent = pTransactionNode;
	}

	//if my current tree node is less than the transaction node - go left
	else if ((dynamic_cast <TransactionNode *> (pCurrent)->GetUnits()) < pTransactionNode->GetUnits())
	{
		Insert(pCurrent->GetPRight(), pTransactionNode);
	}

	//if my current tree node is greater than the transaction node - go right
	else if ((dynamic_cast <TransactionNode *> (pCurrent)->GetUnits()) > pTransactionNode->GetUnits())
	{
		Insert(pCurrent->GetPLeft(), pTransactionNode);
	}
}

/*PUBLIC version that calls the private version*/
void BST::InOrderTraversal()
{
	InOrderTraversal(pRoot);
}

/*PRIVATE version that actually traverses through the trees*/
void BST::InOrderTraversal(Node *&pCurrent)
{
	//go left if possible
	if (pCurrent->GetPLeft() != nullptr)
	{
		InOrderTraversal(pCurrent->GetPLeft());
	}

	//print contents
	pCurrent->PrintData();

	/*This assigns the smallest/largest values in both trees to the four variables
	in class BST. Not part of the traversal, just convenient to have them here*/
	if (tempMostUnits < (dynamic_cast <TransactionNode *> (pCurrent)->GetUnits()))
	{
		tempMostUnits = (dynamic_cast <TransactionNode *> (pCurrent)->GetUnits());
		tempMostItem = pCurrent->GetData();
	}
	if (tempLeastUnits >(dynamic_cast <TransactionNode *> (pCurrent)->GetUnits()))
	{
		tempLeastUnits = (dynamic_cast <TransactionNode *> (pCurrent)->GetUnits());
		tempLeastItem = pCurrent->GetData();
	}

	//go right if possible
	if (pCurrent->GetPRight() != nullptr)
	{
		InOrderTraversal(pCurrent->GetPRight());
	}
}

/*visit each node in PostOrder() to destroy them*/
void BST::DestroyTree()
{
	/*because pRoot is type Node*, it delete will call the destructor
	of class Node*/
	delete(pRoot);
}

//destructor
BST::~BST()
{
	//cout << "Inside BST destructor\n";
	DestroyTree();
}