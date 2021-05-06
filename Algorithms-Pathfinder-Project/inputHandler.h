#pragma once
using namespace adjListGraph;
using namespace adjMatrix;
namespace input{
	class inputHandler {
	private:
		string input;
		int dest;
		int source;
		int numOfVertices;
		int numOfEdges=0;
		int biggestVerticeNumber;
		int lowestVerticeNumber;
	public:
		void read(char* fileName);//Reads input from text file and checks its validity 
		void readLineFromInput(string tempInput, int action);
		AdjacencyMatrix* buildAdjacencyMatrix();//Builds ajacency matrix from the given input
		adjacencyListGraph* buildAdjacencyList();//Builds ajacency list from the given input
		int checkSecondNumberIndex(string str);
		int countWhiteSpaces(string str);
		void buildEdgeFromInput(int& firstVertice, int& secondVertice, double& weight);//Build edge from two given vertices and weight in the format of (u v w)
		int getDest() { return this->dest; };
		int getSource() { return this->source; };
		void updateLowestAndBiggestVertices(int firstVertice, int secondVertice);
		bool isWrongDest();//Checks that destination vertice is valid
		bool isWrongSrc();//Checks that source vertice is valid
	};
}