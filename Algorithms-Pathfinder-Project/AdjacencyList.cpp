#include "GlobalHeader.h"
namespace adjListGraph {
    adjacencyListGraph::adjacencyListGraph() {
        this->numOfNodes = 0;
        this->adjArray = nullptr;
    }
    void adjacencyListGraph::makeEmptyGraph(int n) {
        this->adjArray = new adjList[n];
        this->numOfNodes = n;
        for(int i = 0; i < n; i++) {
            adjArray[i].head = nullptr;
            adjArray[i].tail = nullptr;        
        }
    }
    bool adjacencyListGraph::isAdjacent(int u, int v) {
        adjListNode* curr = adjArray[u].head;
        while(curr != nullptr){
            if (curr->destination == v)
                return true;
            curr = curr->next;
        }
        return false;
    }
    adjList adjacencyListGraph::getAdjList(int u) {
        return adjArray[u];
    }
    void adjacencyListGraph::addEdge(int u, int v, int c) {
        adjListNode* newNode = new adjListNode;
        newNode->destination = v;
        newNode->weight = c;
        newNode->next = adjArray[u].head;
        this->adjArray[u].head = newNode;
    }
    void adjacencyListGraph::removeEdge(int u, int v) {
        
    }
    adjacencyListGraph::~adjacencyListGraph(){
        adjListNode* curr = this->adjArray->head;
        adjListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            delete(curr);
            curr = next;
        }
        delete adjArray;
    }
}