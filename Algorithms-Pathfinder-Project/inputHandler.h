#pragma once
using namespace adjListGraph;
using namespace adjMatrix;
namespace input{
	class inputHandler {
	private:
		string input;
	public:
		void read(char* fileName);
		bool valid();
		AdjacencyMatrix buildAdjacencyMatrix();
		adjacencyListGraph buildAdjacencyList();
	};
}