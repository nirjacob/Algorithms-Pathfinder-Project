#pragma once
namespace minArrayQ {
	struct arrVertice {
		int verticeNumber;
		double verticeDistance;
	};
	class minArrQ {
	private:
		arrVertice* minQueue;
		int size;
		arrVertice* minItem;
	public:
		minArrQ();
		~minArrQ();
		void build(int vSize, double* d, int source);
		void insert(int verticeNumber, double verticeDistance);
		arrVertice* getMin();
		arrVertice deleteMin();
		bool isEmpty();
		void decreaseKey(int place, double newKey,int vSize);
		void Swap(arrVertice& child, arrVertice& parent);

	};
}