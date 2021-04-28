#include "GlobalHeader.h"
namespace minArrayQ {
    minArrQ::minArrQ() {
        this->minQueue = nullptr;
        this->minItem->currMinItem = nullptr;
        this->size = 0;
    }
    void minArrQ::insert(int _value, int _key) {
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
        int currMinPriority = INT_MAX;
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
    minArrQ::~minArrQ() {
        delete[] this->minQueue;
    }
};