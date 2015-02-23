//By Andrew Blum and Zach Sloane

#include <stdlib.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

template<class T>
class heap {
	public:
		heap(const vector<string> wordlist);
		int parent(const int index);
		int left(const int index);
		int right(const int index);
		void getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify(int *a, const int index);
		void buildMaxHeap();
		
		void initializeMinHeap();
		void minHeapify(const int index);
		void buildMinHeap();
		
		void heapsort();
		
		int size;
		
	private:
		string p;
		vector<string> leftChild;		//change vector<string> to heap?
		vector<string> rightChild;		//change vector<string> to heap?
		int index;
};
