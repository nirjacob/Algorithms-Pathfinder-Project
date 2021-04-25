#pragma once
using namespace adjListGraph;

namespace adjMatrix {
	class AdjacencyMatrix {

	private:
		int** matrix;
		int size;

	public:
		AdjacencyMatrix() { matrix = nullptr; size = 0; };
		~AdjacencyMatrix();
		void MakeEmptyGraph(int size);
		bool IsAdjacent(int u, int v);
		void AddEdge(int u, int v, int c);
		adjList GetAdjList(int u);
		void RemoveEdge(int u, int v);

	};
}