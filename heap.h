


class heap {
	public:
		string parent(const int index);
		heap left(const int index);
		heap right(const int index);
		void getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify();
		void buildMaxHeap();
		
		void initializeMinHeap();
		void minHeapify();
		void buildMinHeap();
		
		void heapsort();
		
		void size();
		
	private:
		string parent;
		heap leftChild;
		heap rightChild;
		int index;
		int size;
};
