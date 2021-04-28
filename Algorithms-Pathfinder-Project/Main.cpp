#include "GlobalHeader.h"
int main(int argc, char** argv)
{
	inputHandler graph;
	char text[20];
	//graph.read(argv[1]);
	cin >> text;
	graph.read(text);
	//check valid input
	//make graphs
	AdjacencyMatrix adjMatrix = graph.buildAdjacencyMatrix();
	adjacencyListGraph adjList = graph.buildAdjacencyList();
	//check route
	//adjMatrix.checkValidRoute();



	//ofstream outFile(argv[2]);
	//if (!outFile) {
	//	cout << "Error creating output file" << endl;
	//	exit(-1);
	//}
	//outFile.close();
	return 0;
}

