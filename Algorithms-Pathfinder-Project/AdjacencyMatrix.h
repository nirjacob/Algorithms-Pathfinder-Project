#pragma once
using namespace adjListGraph;

namespace adjMatrix {
	class AdjacencyMatrix {

	private:
		double** matrix;
		int size;

	public:
		AdjacencyMatrix(int numOfVertices);
		~AdjacencyMatrix();
		void MakeEmptyGraph(int size);
		bool IsAdjacent(int u, int v);
		void AddEdge(int u, int v, double c);
		adjList GetAdjList(int u);
		void RemoveEdge(int u, int v);
		int getSize() { return this->size; };
		//void checkValidRoute();
		void setVertices(int n);
		double getWeight(int u, int v) { return this->matrix[u][v]; };

	};
}