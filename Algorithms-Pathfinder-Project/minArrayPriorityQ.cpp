#include "GlobalHeader.h"
namespace minArrayQ {
    minArrQ::minArrQ() {
        this->minQueue = nullptr;
        this->size = 0;
    }
    void minArrQ::insert(int _value, double _key) {
        arrVertice* newItem = new arrVertice;
        newItem->verticeDistance = _key;
        newItem->verticeNumber = _value;
        newItem->currMinItem = this->minItem;
        this->size++;
        minQueue[size].verticeDistance = newItem->verticeDistance;
        minQueue[size].verticeNumber = newItem->verticeNumber;
        minQueue[size].currMinItem = newItem->currMinItem;
        if (_key < minItem->verticeDistance) {
            this->minItem = &minQueue[size];
        }
    }
    arrVertice* minArrQ::getMin() {
        return this->minItem;
    }
    arrVertice minArrQ::deleteMin() {
        arrVertice min = *(this->minItem);
        this->minItem->verticeDistance = -1;
        this->minItem->verticeNumber = -1;
        int currMinDistance =-1, minimumDistance =-1;
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (minQueue[i].verticeDistance != -1) {
                currMinDistance = minQueue[i].verticeDistance;
                if (currMinDistance < minimumDistance) {
                    minimumDistance = currMinDistance;
                    index = i;
                }
            }
        }
        minItem->currMinItem = this->minQueue[index].currMinItem;
        minItem->verticeDistance = this->minQueue[index].verticeDistance;
        minItem->verticeNumber = this->minQueue[index].verticeNumber;
        return min;
    }
    void minArrQ::decreaseKey(int place, double newKey){
        this->minQueue[place].verticeDistance = newKey;
        if(this->minItem->verticeDistance > newKey){
            this->minItem->verticeDistance = minQueue[place].verticeDistance;
            this->minItem->verticeNumber = minQueue[place].verticeNumber;
            this->minItem->currMinItem = minQueue[place].currMinItem;
        }
    }
    minArrQ::~minArrQ() {
        delete[] this->minQueue;
    }

    void minArrQ::build(int vSize, double* d) {
        this->size = vSize;
        this->minQueue = new arrVertice[vSize];
        this->minItem = new arrVertice();
        this->minItem->verticeDistance = 0;
        this->minItem->verticeNumber = d[0];
        this->minItem->currMinItem = minItem;
        for (int i = 0; i < this->size; i++) {
            minQueue[i].verticeDistance = d[i];
            minQueue[i].verticeNumber = d[i];
            minQueue[i].currMinItem = minItem;
        }
    }
    bool minArrQ::isEmpty() {
        return (size == 0);
    }

};