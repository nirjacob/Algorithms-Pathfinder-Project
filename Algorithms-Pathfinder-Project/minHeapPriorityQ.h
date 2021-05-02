#pragma once

class element {
public:
	int data;
	double key;
};
class minHeapPriorityQ {
private:
	element* minHeap;
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
	void Swap(element* child, element* parent);
	element DeleteMin();
};