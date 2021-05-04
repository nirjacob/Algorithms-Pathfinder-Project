#include "GlobalHeader.h"
int main(int argc, char** argv)
{
	inputHandler graph;
	graph.read(argv[1]);
	AdjacencyMatrix* adjMatrix = graph.buildAdjacencyMatrix();
	adjacencyListGraph* adjList = graph.buildAdjacencyList();
	int destination = graph.getDest();
	int source = graph.getSource();
	ofstream myfile(argv[2]);
	//Dijkstra using min heap
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	double dijkstraHeapListRes = shortestPath::dijkstraMinHeap(adjList, source, destination);
	if (dijkstraHeapListRes == INT_MAX) {
		cout << "No Route";
		return 0;
	}
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

	myfile.close();
	return 0;
}

