#pragma once
using namespace std;

namespace adjListGraph {
        struct adjListNode {
            int destination;
            int weight;
            adjListNode* next;
        };
        struct adjList {
            adjListNode* head;
            adjListNode* tail;
        };

    class adjacencyListGraph
    {
    private:
        int numOfNodes;
        adjList* adjArray;
    public:
        adjacencyListGraph();
        ~adjacencyListGraph();
        void makeEmptyGraph(int n); //Create empty graph with n vertices.
        bool isAdjacent(int u, int v); //Return true if the edge (u,v) belong to the graph.
        adjList getAdjList(int u); //Return linked list of the neighbors of the vertex c.
        void addEdge(int u, int v, int c); //Add the edge (u,v) with the weight c.
        void removeEdge(int u, int v); //Remove the edge (u,v) from the graph.
    };
}