#include "GlobalHeader.h"
minHeapPriorityQ::~minHeapPriorityQ()
{
	while (this->heapSize > 1)
	{
		this->DeleteMin();
	}
}
bool minHeapPriorityQ::isEmpty() {
	if (heapSize == 0) {
		return true;
	}
	else {
		return false;
	}
}
void minHeapPriorityQ::DecreaseKey(int place, int newKey) {
	minHeap[place].data = newKey;
	while (minHeap[Parent(place)].key > minHeap[place].key && place != 0)
	{
		Swap(&minHeap[place], &minHeap[Parent(place)]);
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

void minHeapPriorityQ::Build(int vSize, int* d){
	heapSize = vSize;
	minHeap = new element[heapSize];
	for (int i = 0; i < heapSize; i++) {
		minHeap[i].key = d[i];
		minHeap[i].data = i;
	}
}
void minHeapPriorityQ::Swap(element* child,element* parent)
{
	element* temp = child;
	child = parent;
	parent = temp;
}
void minHeapPriorityQ::FixHeap(int vertice) { //Fixes the heap that has node as root.
	int min;
	int left = Left(vertice);
	int right = Right(vertice);
	//Find maximum among nodes, left and right.
	if ((left < heapSize) && (minHeap[left].key < minHeap[vertice].key))
		min = left;
	else min = vertice;
	if ((right < heapSize) && (minHeap[right].key < minHeap[min].key))
		min = right;
	//Swap values if necessary ,and continue
	//fixing the heap towards the leaves.
	if (min != vertice) {
		Swap(&minHeap[vertice], &minHeap[min]);
		FixHeap(min);
	}
}
element minHeapPriorityQ::DeleteMin() {
	element min = minHeap[0];
	heapSize--;
	minHeap[0] = minHeap[heapSize];
	FixHeap(0);
	return (min);
}

