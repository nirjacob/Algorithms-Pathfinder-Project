#include "GlobalHeader.h"
int main(int argc, char** argv)
{
	//This program gets two file names as arguments:
	//In the first argument the input should be as the following:
	//{the number of vertices in the graph}
	//{the number of the source vertex}
	//{the number of the destination file}
	//{first vertex of an edge} {second vertex of an edge} {the weight of the edge}
	//Using this file the program will find the shortest path between the source and the destination vertices.
	//The program will use dijkstra's algorithm(using minimum queue implemented a heap and as sorted array)
	//and bellman ford algorithm.
	//The program will print as output the run time of each algorithm to the file that is in the second argument.
	inputHandler graph;
	//Reads input from text file given by the first argument
	//Preforms input checks and creates a generic graph that can be built into adj list and matrix graphs.
	graph.read(argv[1]);
	//Creating the two graphs needed for the algorithms
	AdjacencyMatrix* adjMatrix = graph.buildAdjacencyMatrix();
	adjacencyListGraph* adjList = graph.buildAdjacencyList();
	int destination = graph.getDest();
	int source = graph.getSource();
	//Checks for valid route from the given source to destination
	double dijkstraHeapListRes = shortestPath::dijkstraMinHeap(adjList, source, destination);
	if (dijkstraHeapListRes == INT_MAX) {
		cout << "No Route";
		return 0;
	}
	//Create output file with the name given in the second argument
	ofstream myfile(argv[2]);
	//Dijkstra using min heap
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Adjacency Dijkstra heap " << fixed << time_taken << setprecision(9) << endl;

	//Dijkstra using array queue
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double dijkstraArrListRes = shortestPath::dijkstraMinArray(adjList, source, destination);
	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Adjacency Dijkstra array " << fixed << time_taken << setprecision(9) << endl;

	//Bellman Ford 
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double bellmanFordAdjList = shortestPath::bellmanFord(adjList, source, destination);
	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Adjacency Bellman Ford " << fixed << time_taken << setprecision(9) << endl;

	//Matrix Dijkstra heap
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double dijkstraHeapMatrixRes = shortestPath::dijkstraMinHeap(adjMatrix, source, destination);
	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Matrix Dijkstra heap " << fixed
		<< time_taken << setprecision(9);
	myfile << endl;

	//Matrix Dijkstra array
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double dijkstraArrMatrixRes = shortestPath::dijkstraMinArray(adjMatrix, source, destination);
	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Matrix Dijkstra array " << fixed << time_taken << setprecision(9);
	myfile << endl;
	
	//Matrix Bellman Ford
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double bellmanFordMatrixRes = shortestPath::bellmanFord(adjMatrix, source, destination);
	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Matrix Bellman Ford " << fixed << time_taken << setprecision(9);
	myfile << endl;

	//Closing the file
	myfile.close();
	return 0;
}

