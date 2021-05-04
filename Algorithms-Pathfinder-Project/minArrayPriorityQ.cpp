#include "GlobalHeader.h"
namespace minArrayQ {
    minArrQ::minArrQ() {
        this->minQueue = nullptr;
        this->size = 0;
        this->minItem = nullptr;
    }
    void minArrQ::insert(int verticeNumber, double verticeDistance) {
        arrVertice* newItem = new arrVertice;
        newItem->verticeDistance = verticeDistance;
        newItem->verticeNumber = verticeNumber;
        minQueue[verticeNumber].verticeDistance = newItem->verticeDistance;
        minQueue[verticeNumber].verticeNumber = newItem->verticeNumber;
    }
    arrVertice* minArrQ::getMin() {
        return this->minItem;
    }

    arrVertice minArrQ::deleteMin() {
        arrVertice min = *(this->minItem);
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (&minQueue[i] == minItem) {
                index = i;
            }
        }
        Swap(minQueue[index], minQueue[size - 1]);
        int currMinDistance = INT_MAX;
        size--;
        for (int i = 0; i < size; i++) {
            if (minQueue[i].verticeDistance < currMinDistance) {
                this->minItem = &minQueue[i];
                currMinDistance = minQueue[i].verticeDistance;
            }
        }
        if (currMinDistance == INT_MAX) {
            minItem = &minQueue[0];
        }
        return min;
    }
    void minArrQ::decreaseKey(int place, double newKey, int vSize) {
        for (int i = 0; i < size; i++) {
            if (minQueue[i].verticeNumber == place) {
                this->minQueue[i].verticeDistance = newKey;
                if (minItem->verticeDistance > newKey) {
                    minItem = &minQueue[i];
                }
            }
        }

    }

    minArrQ::~minArrQ() {
        delete[] this->minQueue;
    }

    void minArrQ::build(int vSize, double* d,int source) {
        this->size = vSize;
        this->minQueue = new arrVertice[vSize];
        this->minItem = new arrVertice();
        for (int i = 0; i < this->size; i++) {
            insert(i, d[i]);
        }
        minItem = &minQueue[source];
    }
    bool minArrQ::isEmpty() {
        return (size == 0);
    }
    void minArrQ::Swap(arrVertice& child, arrVertice& parent)
    {
        arrVertice temp = child;
        child = parent;
        parent = temp;
    }
};