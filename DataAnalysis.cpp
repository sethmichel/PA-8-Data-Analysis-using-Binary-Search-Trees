#include "DataAnalysis.h"

/*calls the other private functions*/
void DataAnalysis::RunAnalysis()
{
	/*This will read the file, insert the data into the nodes, and insert
	the nodes into the trees*/
	ProcessFile();

	/*show the contents of both trees*/
	cout << "Contents of sold BST \n\n";
	pTreeSold.InOrderTraversal();
	cout << "\nContents of purchased BST\n\n";
	pTreePurchased.InOrderTraversal();

	/*Show the data trends in both trees*/
	DisplayTrends();
}


/*Calls SplitLine() function  then InsertToCorrectTRee() function
until end of file is hit*/
void DataAnalysis::ProcessFile()
{
	fstream dataFile;
	dataFile.open("data.csv", ios::in | ios::out | ios::app);
	string line = "", transactionType = "";

	getline(dataFile, line); //garbage line
	while (!dataFile.eof())
	{
		getline(dataFile, line);
		TransactionNode *pTemp = new TransactionNode;

		//SplitLine() will assign the correct values to pTemp
		SplitLine(pTemp, line, transactionType);

		//deside which of teh two trees to insert the Transaction node
		InsertToCorrectTree(pTemp, transactionType);
	}


	dataFile.close();
}


/*Function reads one line from file and splites the line into
units, type, and transation fields*/
void DataAnalysis::SplitLine(TransactionNode *&pCurrentNode, string &line, string &transactionType)
{
	string subString = "";
	string subStringArray[3] = { "", "", "" }; //units, type, tranaction type

	int endIndex = -1, startIndex = 0, subStringArrayIndex = 0, tempNumb = 0;
	char temp = 'w';

	for (int i = 0; i < 3; i++)
	{
		while (temp != ',' && temp != '\0')
		{
			++endIndex;
			temp = line[endIndex];
		}
		//endIndex is now the index where the comma occures

		temp = 'w';
		subString = line.substr(startIndex, endIndex - startIndex);
		subStringArray[subStringArrayIndex] = subString;

		//subString now is the word ending with a \0

		if (endIndex != '\0')
		{
			startIndex = endIndex + 2;
			++endIndex;
		}
		++subStringArrayIndex;
		temp = 'w';
	}

	//assign the line data to Transaction node
	int tempUnits = stoi(subStringArray[0]);
	pCurrentNode->SetUnits(tempUnits);
	pCurrentNode->SetData(subStringArray[1]);
	transactionType = subStringArray[2];

}


/*Check if the transactionType string is "purchased" or "sold" and
assign the node to the corresponding tree's insert() function*/
void DataAnalysis::InsertToCorrectTree(TransactionNode *&pTemp, string &transactionType)
{
	if (transactionType == "Sold")
		pTreeSold.Insert(pTemp);
	else
		pTreePurchased.Insert(pTemp);
}


/*Display to the screen the purchase type and number of the most sold, least
sold, most purchased, and least purchased items*/
void DataAnalysis::DisplayTrends()
{

	cout << "****************************************\n";
	cout << "             Data Tends\n\n";

	cout << "Most purchased Item: " << pTreePurchased.GetMostTempItem() << " At " << pTreePurchased.GetMostTempUnits() << " units\n";
	cout << "Least purchased Item: " << pTreePurchased.GetLeastTempItem() << " At " << pTreePurchased.GetLeastTempUnits() << " units\n\n";

	cout << "Most sold Item: " << pTreeSold.GetMostTempItem() << " At " << pTreeSold.GetMostTempUnits() << " units\n";
	cout << "Least sold Item: " << pTreeSold.GetLeastTempItem() << " At " << pTreeSold.GetLeastTempUnits() << " units\n\n\n";

}