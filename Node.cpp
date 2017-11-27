#include "Node.h"

/***********************************
constuctor, setters, getters*/

Node::Node(string passedData)
{
	data = passedData;
	pLeft = nullptr;
	pRight = nullptr;
}

string Node::GetData()
{
	return data;
}

Node*&Node::GetPLeft()
{
	return pLeft;
}

Node *&Node::GetPRight()
{
	return pRight;
}

void Node::SetData(string &passedData)
{
	data = passedData;
}

void Node::SetPLeft(Node *&passedPLeft)
{
	pLeft = passedPLeft;
}

void Node::SetPRight(Node *&passedPRight)
{
	pRight = passedPRight;
}

//Destructor
Node::~Node()
{
	//cout << "inside the Node destructor\n";
	delete(pLeft);
	delete(pRight);
}