/*Seth Michel
PA 8: Data Analysis using Binary Search Trees

Desription: This program reads in data from a csv file organzied in
a way so it reads: # of units sold, what the item is, and if it was
purchased by a person or sold to a company. the program assigns
these lines of data to transactionNode.h which is inherited from
Node.h and inserts these nodes into one of two trees depending on
if the item was sold or purchased. Data trends of the items are
then found*/


#include "DataAnalysis.h"


int main()
{
	DataAnalysis DataAnalysisObject;
	DataAnalysisObject.RunAnalysis();

	return 0;
}
