#pragma once
using namespace adjListGraph;

namespace adjMatrix {
	class AdjacencyMatrix {

	private:
		double** matrix;
		int size;

	public:
		AdjacencyMatrix() { matrix = nullptr; size = 0; };
		~AdjacencyMatrix();
		void MakeEmptyGraph(int size);
		bool IsAdjacent(int u, int v);
		void AddEdge(int u, int v, double c);
		adjList GetAdjList(int u);
		void RemoveEdge(int u, int v);
		//void checkValidRoute();

	};
}