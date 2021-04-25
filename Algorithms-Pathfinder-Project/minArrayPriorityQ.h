#pragma once
namespace minArrayQ {
	struct item {
		int value;
		int key;
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

		void insert(int _value, int _key);
		item* getMin();
		item deleteMin();
	};
}