#pragma once
namespace minArrayQ {
	struct item {
		int value;
		double key;
		item* currMinItem;
	};
	class minArrQ {
	private:
		item* minQueue;
		int size;
		item* minItem;
	public:
		minArrQ();
		~minArrQ();
		void build(int vSize, double* d);
		void insert(int _value, double _key);
		item* getMin();
		item deleteMin();
		bool isEmpty();
		void decreaseKey(int place, double newKey);
	};
}