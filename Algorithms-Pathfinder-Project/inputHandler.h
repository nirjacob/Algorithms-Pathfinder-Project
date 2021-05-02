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
	public:
		void read(char* fileName);
		void readLineFromInput(string tempInput, int action);
		AdjacencyMatrix* buildAdjacencyMatrix();
		adjacencyListGraph* buildAdjacencyList();
		int checkSecondNumberIndex(string str);
		int countWhiteSpaces(string str);
		void buildEdgeFromInput(int& firstVertice, int& secondVertice, double& weight);
		int getDest() { return this->dest; };
		int getSource() { return this->source; };
	};
}