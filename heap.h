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
		string left(int index);
		int left() const {return leftindex;};
		string right(int index);
		int right() const {return rightindex;};
		void getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify(int *a, const int index);
		void buildMaxHeap(int *a, int n);
		
		void initializeMinHeap();
		void minHeapify(const int index);
		void buildMinHeap(int *a, int n);
		
		void heapsort(int *a, int size);
		
		int size() const {return s;};
		
	private:
		vector<string> h;
		
		int parentindex;
		int leftindex;		//change vector<string> to heap?
		int rightindex;		//change vector<string> to heap?
		int index;
		int s;
};
