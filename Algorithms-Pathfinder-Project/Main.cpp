#include "GlobalHeader.h"
int main(int argc, char** argv)
{

	//~~~~~~~~~~ Test everything but bellman-ford (Matrix) ~~~~~~~~~~\\
	//~~~~~~~~~~ Add input checks DAG+Route ~~~~~~~~~~\\
	//~~~~~~~~~~ Add runtimes to file ~~~~~~~~~~\\

	inputHandler graph;
	char text[20];
	//graph.read(argv[1]);
	cin >> text;
	graph.read(text);
	//check valid input
	//make graphs
	AdjacencyMatrix* adjMatrix = graph.buildAdjacencyMatrix();
	adjacencyListGraph* adjList = graph.buildAdjacencyList();
	//check negative MAAGAL
	//check route
	//adjMatrix.checkValidRoute();
	int destination = graph.getDest();

	int source = graph.getSource();
	
	
	double bfMatrixRes = shortestPath::bellmanFord(adjMatrix, source, destination);
	double bfListRes = shortestPath::bellmanFord(adjList, source, destination);
	double dijkstraHeapMatrixRes = shortestPath::dijkstraMinHeap(adjMatrix, source, destination);
	double dijkstraHeapListRes = shortestPath::dijkstraMinHeap(adjList, source, destination);




	double dijkstraArrMatrixRes = shortestPath::dijkstraMinArray(adjMatrix, source, destination);
	double dijkstraArrListRes = shortestPath::dijkstraMinArray(adjList, source, destination);

	//ofstream outFile(argv[2]);
	//if (!outFile) {
	//	cout << "Error creating output file" << endl;
	//	exit(-1);
	//}
	//outFile.close();
	return 0;
}

