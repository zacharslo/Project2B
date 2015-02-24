/*
Heap.cpp
Authors: Zach Sloane and Andrew Blum

*/

#ifndef HEAP_FUNCTS
#define HEAP_FUNCTS

#include <algorithm>
#include <iostream>
#include "heap.h"
#include "wordList.cpp"

using namespace std;

template<class T>
heap<T>::heap(const vector<string> wordlist) {
	
	heapsort();
}

template<class T>
int heap<T>::parent(int i) { //returns index value of parent of the string at this index
	return (i - 1)/2;
}

template<class T>
int heap<T>::left(int i) const {
	if (i == 0){ //check that i is non-zero
		return 1;
	}
	else { //returns index value of the left child of the string at this index
		return i * 2;
	}	
}

template<class T>
int heap<T>::right(int i) const {
	if (i == 0) { //check that i is non-zero
		return 2;
	}
	else { //returns index value of the right child of the string at this index
		return i * 2 + 1;
	}
}

template <class T>
void heap<T>::maxHeapify(vector<T> a, const int i) {
	int l = left(i);
	int r = right(i);
	int largest, temp;
	int size = a.size();
	
	if ((l <= size) && (a[1] > a[i])) { //base case
		largest = l;
	}
	else {
		largest = i;
	}
	
	if ((r < size) && a[r] > a[largest]) {
		largest = r;
	}
	
	if (largest != i) {
		swap(a[i], a[largest]);
		maxHeapify(a, largest);	//call maxHeapify recursively
	}
}

template <class T>
void heap<T>::initializeMaxHeap(vector<T> a, int n) {
	buildMaxHeap(a, n);
}

template <class T>
void heap<T>::buildMaxHeap(vector<T> a, int n) {
	int i;
	for (i = n/2; i >= 1; i--) {
		maxHeapify(a, i);
	}
}

template <class T>
void heap<T>::minHeapify(vector<T> *a, const int i) {
	int l = left(i);
	int r = right(i);
	int smallest, temp;
	int size = a.size();
	
	if ((l <= size) && (a[1] < a[i])) { //base case
		smallest = l;
	}
	else {
		smallest = i;
	}
	
	if ((r < size) && a[r] < a[smallest]) {
		smallest = r;
	}
	
	if (smallest != i) {
		swap(a[i], a[smallest]);
		minHeapify(a, smallest);	//call minHeapify recursively
	}
}

template <class T>
void heap<T>::initializeMinHeap(vector<T> *a, int n) {
	buildMinHeap(a, n);
}

template <class T>
void heap<T>::buildMinHeap(vector<T> *a, int n) {
	int i;
	for (i = n/2; i >= 1; i--) {
		minHeapify(a, i);
	}
}

template <class T> 
void heap<T>::heapsort() {
	int size = h.size() - 1;
	vector<T> a = h;
	buildMaxHeap(a, size);
	h = a;
}

#endif
