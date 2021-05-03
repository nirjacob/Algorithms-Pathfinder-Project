#include "GlobalHeader.h"
namespace algo {

	double* shortestPath::init(int n, int src) {
		double* dist = new double[n];
		for (int i = 0; i < n; i++) {
			dist[i] = INT_MAX;
		}
		dist[src] = 0;
		return dist;
	}
	void shortestPath::relax(int u, int v, double newWeight, double* d) {
		if (d[v] > d[u] + newWeight) {
			d[v] = d[u] + newWeight;
		}
	}
	double shortestPath::bellmanFord(AdjacencyMatrix* G, int source, int dest) {
		double* distanceArray = init(G->getSize(), source);
		int numOfVertices = G->getSize();
		while (numOfVertices-1 > 0) {
			for (int i = 0; i < G->getSize(); i++) {
				for (int j = 0; j < G->getSize(); j++) {
					if (G->IsAdjacent(i, j)) {
						relax(i, j, G->getWeight(i, j), distanceArray);
					}
				}
			}
			numOfVertices--;
		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
	double shortestPath::dijkstraMinArray(AdjacencyMatrix* G, int source, int dest){
		minArrQ Q;
		double* distanceArray = init(G->getSize(), source);
		Q.build(G->getSize(), distanceArray);
		while(!Q.isEmpty()){
			arrVertice u = Q.deleteMin();
			for(int i = 0; i < G->getSize(); i++){
				if(G->IsAdjacent(u.verticeNumber, i)) {
					relax(u.verticeNumber, i, G->getWeight(u.verticeNumber, i), distanceArray);
					Q.decreaseKey(i, distanceArray[i]);
				}
			}
		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
	double shortestPath::dijkstraMinHeap(AdjacencyMatrix* G, int source, int dest) {
		minHeapPriorityQ Q;
		double* distanceArray = init(G->getSize(), source);
		Q.Build(G->getSize(), distanceArray);
		while(!Q.isEmpty()){
			vertice u = Q.DeleteMin();
			for(int i = 0; i < G->getSize(); i++){
				if(G->IsAdjacent(u.verticeNum,i)){
					relax(u.verticeNum, i, G->getWeight(u.verticeNum,i), distanceArray);
					Q.DecreaseKey(i, distanceArray[i]);
				}
			}
 		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
	double shortestPath::bellmanFord(adjacencyListGraph* G, int source, int dest) {
		double* distanceArray = init(G->getSize(), source);
		int numOfvertices = G->getSize();
		while (numOfvertices - 1 > 0) {
			for (int i = 0; i < G->getSize(); i++) {
				adjList currList = G->getAdjList(i);
				if (currList.head != nullptr) {//if the vertice has list of neighbors
					adjListNode* currVertice = currList.head;
					while (currVertice != nullptr) {
						relax(i, currVertice->destination, currVertice->weight, distanceArray);
						currVertice = currVertice->next;
					}
				}
			}
			numOfvertices--;
		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
	double shortestPath::dijkstraMinArray(adjacencyListGraph* G, int source, int dest) {
		minArrQ Q;
		double* distanceArray = init(G->getSize(), source);
		Q.build(G->getSize(), distanceArray);
		while(!Q.isEmpty()){
			arrVertice u = Q.deleteMin();
			for(int i = 0; i < G->getSize(); i++){
				if(G->isAdjacent(u.verticeNumber, i)) {
					relax(u.verticeNumber, i, G->getWeight(u.verticeNumber, i), distanceArray);
					Q.decreaseKey(i, distanceArray[i]);
				}
			}
		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
	double shortestPath::dijkstraMinHeap(adjacencyListGraph* G, int source, int dest) {
		minHeapPriorityQ Q;
		double* distanceArray = init(G->getSize(), source);
		Q.Build(G->getSize(), distanceArray);
		while (!Q.isEmpty()) {
			vertice u = Q.DeleteMin();
			for (int i = 0; i < G->getSize(); i++) {
				if (G->isAdjacent(u.verticeNum,i)) {
					relax(u.verticeNum, i, G->getWeight(u.verticeNum, i), distanceArray);
					Q.DecreaseKey(i, distanceArray[i]);
				}
			}
		}
		double res = distanceArray[dest];
		delete[] distanceArray;
		return res;
	}
}