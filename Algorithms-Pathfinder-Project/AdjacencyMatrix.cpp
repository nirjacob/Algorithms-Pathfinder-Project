#include "GlobalHeader.h"
namespace adjMatrix {

	AdjacencyMatrix::~AdjacencyMatrix() {
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				delete this->matrix[i];
			}
		}
		delete matrix;
	}
	void AdjacencyMatrix::MakeEmptyGraph(int size) {
		matrix = new double* [size];
		for (int i = 0; i < size; i++) {
			matrix[i] = new double[size];
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = -1;
			}
		}
	}
	bool AdjacencyMatrix::IsAdjacent(int u, int v) {
		if (matrix[u][v] != -1) {
			return true;
		}
		return false;
	}

	adjList AdjacencyMatrix::GetAdjList(int u) {
		adjacencyListGraph adjU;
		adjU.makeEmptyGraph(1);//allocate a single vertice list
		for (int i = 0; i < size; i++) {
			if (matrix[u][i] != 0) {
				adjU.addEdge(0, i, matrix[u][i]);//adds to the single vertice a list of "u"'s adjacents
			}
		}
		return adjU.getAdjList(0);
	}
	void AdjacencyMatrix::AddEdge(int u, int v, double c) {
		matrix[u][v] = c;
	}
	void AdjacencyMatrix::RemoveEdge(int u, int v) {
		matrix[u][v] = 0;
	}
	void AdjacencyMatrix::setVertices(int n){
		this->size = n;
	}
	//void checkValidRoute() {

	//}

}