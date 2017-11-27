#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;

class Node
{
protected:
	string data; //name of the item
	Node *pLeft;
	Node *pRight;

public:
	//construcor
	Node(string data = "");

	//destructor
	virtual ~Node();

	virtual void PrintData() = 0; //pure virtual, override in class TransactionNode

	//getters and setters
	string GetData();
	Node *&GetPLeft();
	Node *&GetPRight();

	void SetData(string &passedData);
	void SetPLeft(Node *&passedPLeft);
	void SetPRight(Node *&passedpRight);
};