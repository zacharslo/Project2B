//By Andrew Blum and Zach Sloane

#ifndef HEAP_CLASS
#define HEAP_CLASS

#include <stdlib.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "wordList.cpp"

using namespace std;

template<class T>
class heap {
	public:
		heap(const vector<string> wordlist);
		int parent(const int index);
		int left(int index) const;
		int right(int index) const;
		void getItem(const int n) const {return h[n];};
		
		void initializeMaxHeap(vector<T> a, const int index);
		void maxHeapify(vector<T> a, const int index);
		void buildMaxHeap(vector<T> a, int n);
		
		void initializeMinHeap(vector<T> *a, const int index);
		void minHeapify(vector<T> *a, const int index);
		void buildMinHeap(vector<T> *a, const int index);
		
		void heapsort();
		
		int size() const {return h.size();};
		
	private:
		vector<T> h;
		
		int index;
};

#endif
