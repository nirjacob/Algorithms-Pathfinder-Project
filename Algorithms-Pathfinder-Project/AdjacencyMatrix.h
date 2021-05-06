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
		void MakeEmptyGraph(int size);//Create empty graph with n vertices.
		bool IsAdjacent(int u, int v);//Return true if the edge (u,v) belong to the graph.
		void AddEdge(int u, int v, double c);//Add the edge (u,v) with the weight c.
		adjList GetAdjList(int u);//Return linked list of the neighbors of the vertex c.
		void RemoveEdge(int u, int v);//Remove the edge (u,v) from the graph.
		int getSize() { return this->size; };
		void setVertices(int n);
		double getWeight(int u, int v) { return this->matrix[u][v]; };

	};
}



