#include "BST.h"

class DataAnalysis
{
private:
	BST pTreeSold;
	BST pTreePurchased;

	/*function reads one line from file and splites the line into
	units, type, and transation fields*/
	void SplitLine(TransactionNode *&pCurrentNode, string &line, string &transactionType);

	/*calls the function below, and then displays the current
	contents of both BSTs; use inOrderTraversal () to display
	the trees*/
	void ProcessFile();

	/*A function that compares the transaction field and inserts
	the units and type into the appropriate tree*/
	void InsertToCorrectTree(TransactionNode *&pTemp, string &transactionType);

	/*A function that writes to the screen the trends we see in
	our tree*/
	void DisplayTrends();

public:
	void RunAnalysis(); //function to call the private functions

};

/*Don't need a destructor because I don't dynamically allocate memory
in this class*/