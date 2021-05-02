#include "GlobalHeader.h"
namespace minArrayQ {
    minArrQ::minArrQ() {
        this->minQueue = nullptr;
        this->minItem->currMinItem = nullptr;
        this->size = 0;
    }
    void minArrQ::insert(int _value, double _key) {
        item* newItem = new item;
        newItem->key = _key;
        newItem->value = _value;
        if (_key < minItem->key) {
            this->minItem = newItem;
        }
        newItem->currMinItem = this->minItem;
        this->size++;
        minQueue[size].key = newItem->key;
        minQueue[size].value = newItem->value;
        minQueue[size].currMinItem = newItem->currMinItem;
    }
    item* minArrQ::getMin() {
        return this->minItem;
    }
    item minArrQ::deleteMin() {
        item min = *(this->minItem);
        double currMinPriority = INT_MAX;
        int currMinIndex = -1;
        for (int i = 0; i <= size; i++) {
            if (currMinPriority == this->minQueue[i].key
                && currMinIndex > -1
                && this->minQueue[currMinIndex].value > this->minQueue[i].value) {
                currMinPriority = this->minQueue[i].key;
                currMinIndex = i;
            }
            else if (currMinPriority < this->minQueue[i].key) {
                currMinPriority = this->minQueue[i].key;
                currMinIndex = i;
            }
            minItem->currMinItem = this->minQueue[currMinIndex].currMinItem;
            minItem->key= this->minQueue[currMinIndex].key;
            minItem->value= this->minQueue[currMinIndex].value;
            size--;
            return min;
        }
        return min;
    }
    void minArrQ::decreaseKey(int place, double newKey){
        this->minQueue[place].key = newKey;
        if(this->minItem->key > newKey){
            this->minItem->key = minQueue[place].key;
            this->minItem->value = minQueue[place].value;
            this->minItem->currMinItem = minQueue[place].currMinItem;
        }
    }
    minArrQ::~minArrQ() {
        delete[] this->minQueue;
    }

    void minArrQ::build(int vSize, double* d) {
        this->size = vSize;
        this->minItem->key = 0;
        this->minItem->value = d[0];
        this->minItem->currMinItem = minItem;
        for (int i = 0; i < this->size; i++) {
            minQueue[i].key = d[i];
            minQueue[i].value = d[i];
            minQueue[i].currMinItem = minItem;
        }
    }
    bool minArrQ::isEmpty() {
        return (size == 0);
    }

};