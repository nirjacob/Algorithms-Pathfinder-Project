#include "GlobalHeader.h"
minHeapPriorityQ::~minHeapPriorityQ()
{
	delete[] this->minHeap;
}
bool minHeapPriorityQ::isEmpty() {
	if (heapSize == 0) {
		return true;
	}
	else {
		return false;
	}
}
void minHeapPriorityQ::DecreaseKey(int place, double newKey) {
	minHeap[place].distance = newKey;
	while (minHeap[Parent(place)].distance > minHeap[place].distance && place != 0)
	{
		Swap(minHeap[place], minHeap[Parent(place)]);
		place = Parent(place);
	}
}
int minHeapPriorityQ::Parent(int node)
{
	return ((node - 1) / 2);
}
int minHeapPriorityQ::Left(int node)
{
	return (2 * node + 1);
}
int minHeapPriorityQ::Right(int node)
{
	return (2 * node + 2);
}

void minHeapPriorityQ::Build(int vSize, double* d){
	heapSize = vSize;
	minHeap = new vertice[heapSize];
	for (int i = 0; i < heapSize; i++) {
		minHeap[i].distance = d[i];
		minHeap[i].verticeNum = i;
	}
}
void minHeapPriorityQ::Swap(vertice& child,vertice& parent)
{
	vertice temp = child;
	child = parent;
	parent = temp;
}
void minHeapPriorityQ::FixHeap(int vertice) { //Fixes the heap that has node as root.
	int min;
	int left = Left(vertice);
	int right = Right(vertice);
	//Find maximum among nodes, left and right.
	if ((left < heapSize) && (minHeap[left].distance < minHeap[vertice].distance))
		min = left;
	else min = vertice;
	if ((right < heapSize) && (minHeap[right].distance < minHeap[min].distance))
		min = right;
	//Swap values if necessary ,and continue
	//fixing the heap towards the leaves.
	if (min != vertice) {
		Swap(minHeap[vertice], minHeap[min]);
		FixHeap(min);
	}
}
vertice minHeapPriorityQ::DeleteMin() {
	vertice min = minHeap[0];
	heapSize--;
	minHeap[0] = minHeap[heapSize];
	FixHeap(0);
	return (min);
}

