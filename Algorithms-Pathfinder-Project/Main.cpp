#include "GlobalHeader.h"
void main(int argc, char** argv)
{
	inputHandler graph;
	graph.read(argv[1]);
	if (!graph.valid()) {
		cout << "invalid input";
		exit(1);
	}
	AdjacencyMatrix adjMatrix = graph.buildAdjacencyMatrix();
	adjacencyListGraph adjList = graph.buildAdjacencyList();
	//ofstream outFile(filename);
	//if (!outFile) {
	//	cout << "Error creating output file" << endl;
	//	exit(-1);
	//}
	//outFile.close();
}

