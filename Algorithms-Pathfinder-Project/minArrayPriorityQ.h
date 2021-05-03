#pragma once
namespace minArrayQ {
	struct arrVertice {
		int verticeNumber;
		double verticeDistance;
		arrVertice* currMinItem;
	};
	class minArrQ {
	private:
		arrVertice* minQueue;
		int size;
		arrVertice* minItem;
	public:
		minArrQ();
		~minArrQ();
		void build(int vSize, double* d);
		void insert(int _value, double _key);
		arrVertice* getMin();
		arrVertice deleteMin();
		bool isEmpty();
		void decreaseKey(int place, double newKey);
	};
}