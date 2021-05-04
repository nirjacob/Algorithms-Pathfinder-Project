#include "GlobalHeader.h"
using namespace input;
void inputHandler::read(char* fileName) {
	ifstream inFile;
	string line;
	int readingIndex = 0;
	inFile.open(fileName);
	if (!inFile) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	while (!inFile.eof()) {
		if (!inFile.good()) {
			cout << "Error reading" << endl;
			exit(1);
		}
		getline(inFile, line);
		try {
			readLineFromInput(line, readingIndex);
		}
		catch (...) {
			cout << "invalid input" << endl;
			exit(1);
		}
		readingIndex++;
	}
	inFile.close();
}
void inputHandler::readLineFromInput(string tempInput, int action) {
	if (action == 0) {
		if (countWhiteSpaces(tempInput) > 1 || tempInput.find('-') != string::npos)
			throw "invalid input";
		this->numOfVertices = stoi(tempInput, nullptr, 10);
	}
	if (action == 1) {
		if (countWhiteSpaces(tempInput) > 1 || tempInput.find('-') != string::npos)
			throw "invalid input";
		this->source = stoi(tempInput, nullptr, 10) - 1;
		if (source > numOfVertices)
			throw "invalid input";
	}
	if (action == 2) {
		if (countWhiteSpaces(tempInput) > 1 || tempInput.find('-') != string::npos)
			throw "invalid input";
		this->dest = stoi(tempInput) - 1;
		if (dest > numOfVertices)
			throw "invalid input";
	}
	if (action >= 3) {
		if (countWhiteSpaces(tempInput) == 2) {
			if (tempInput.find('-') != string::npos)
				throw "invalid input";
			this->input.append(tempInput);
			this->input.append("\n");
			(this->numOfEdges)++;
		}
		else if (tempInput.size() == 0) {

		}
		else {
			throw "invalid input";
		}
	}
}
int inputHandler::checkSecondNumberIndex(string str) {
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (isspace(str.at(i)))
		{
			return i;
		}
	}
}
int inputHandler::countWhiteSpaces(string str) {
	int count = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (isspace(str.at(i)))
		{
			count++;
		}
	}
	return count;
}
void inputHandler::updateLowestAndBiggestVertices(int firstVertice, int secondVertice) {
	if (firstVertice > this->biggestVerticeNumber) {
		this->biggestVerticeNumber = firstVertice;
	}
	if (firstVertice < this->biggestVerticeNumber) {
		this->lowestVerticeNumber = firstVertice;
	}
	if (secondVertice > this->biggestVerticeNumber) {
		this->biggestVerticeNumber = secondVertice;
	}
	if (secondVertice < this->biggestVerticeNumber) {
		this->lowestVerticeNumber = secondVertice;
	}
}
bool inputHandler::isWrongDest() {
	return (dest > this->biggestVerticeNumber);
}
bool inputHandler::isWrongSrc() {
	return (source > this->biggestVerticeNumber);
}

adjacencyListGraph* inputHandler::buildAdjacencyList() {
	adjacencyListGraph* resultList = new adjacencyListGraph;
	resultList->makeEmptyGraph(this->numOfVertices);
	string tempInput = input;
	int index = 0, firstVertice, secondVertice;
	int biggestVerticeNumber = 0, lowestVerticeNumber = 0;
	double weight;
	for (int i = 0; i < this->numOfEdges; i++) {
		buildEdgeFromInput(firstVertice, secondVertice, weight);
		updateLowestAndBiggestVertices(firstVertice, secondVertice);
		resultList->addEdge(firstVertice - 1, secondVertice - 1, weight);//we chose internal logic that is zero based
	}
	input = tempInput;
	if (isWrongSrc()) {
		cout << "Wrong Source";
	}
	if (isWrongDest()) {
		cout << "Wrong Destination";
	}
	return resultList;
}

AdjacencyMatrix* inputHandler::buildAdjacencyMatrix() {
	AdjacencyMatrix* resultMatrix = new AdjacencyMatrix(this->numOfVertices);
	resultMatrix->setVertices(this->numOfVertices);
	resultMatrix->MakeEmptyGraph(this->numOfVertices);
	int index = 0, firstVertice, secondVertice;
	double weight;

	string tempInput = input;
	for (int i = 0; i < this->numOfEdges; i++) {
		buildEdgeFromInput(firstVertice, secondVertice, weight);
		resultMatrix->AddEdge(firstVertice - 1, secondVertice - 1, weight);//we chose internal logic that is zero based
	}
	input = tempInput;
	return resultMatrix;
}
void inputHandler::buildEdgeFromInput(int& firstVertice, int& secondVertice, double& weight) {
	string::size_type localIndex = 0;
	firstVertice = stoi(input, &localIndex);
	input = input.substr(localIndex);
	secondVertice = stoi(input, &localIndex);
	input = input.substr(localIndex);
	weight = stod(input, &localIndex);
	input = input.substr(localIndex);
}
