#pragma once
using namespace adjListGraph;
using namespace adjMatrix;
namespace algo {
	class shortestPath {
	public:
		static double* init(int n, int src);
		static void relax(int u, int v, double newWeight, double* d);
		static double bellmanFord(AdjacencyMatrix* G, int source, int dest);
		static double dijkstraMinArray(AdjacencyMatrix* G, int source, int dest);
		static double dijkstraMinHeap(AdjacencyMatrix* G, int source, int dest);
		static double bellmanFord(adjacencyListGraph* G, int source, int dest);
		static double dijkstraMinArray(adjacencyListGraph* G, int source, int dest);
		static double dijkstraMinHeap(adjacencyListGraph* G, int source, int dest);
	};
	
}