//By Andrew Blum and Zach Sloane

#include <stdlib.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

class heap {
	public:
		heap(const vector<string> wordlist);
		string parent(const int index);
		heap left(const int index);
		heap right(const int index);
		void getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify(const int index);
		void buildMaxHeap();
		
		void initializeMinHeap();
		void minHeapify(const int index);
		void buildMinHeap();
		
		void heapsort();
		
		int size;
		
	private:
		string p;
		heap leftChild;
		heap rightChild;
		int index;
};
