#pragma once

class vertice {
public:
	int verticeNum;
	double distance;
};
class minHeapPriorityQ {
private:
	vertice* minHeap;
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
public:
	~minHeapPriorityQ();
	bool isEmpty();
	void DecreaseKey(int index, double newKey);
	void FixHeap(int node);
	void Build(int vSize, double* d);
	void Swap(vertice& child, vertice& parent);
	vertice DeleteMin();
};