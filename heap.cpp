/*
Heap.cpp
Authors: Zach Sloane and Andrew Blum

*/

#include <algorithm>
#include<iostream>
#include "heap.h"


using namespace std;

template<class T>
int heap<T>::parent(int i) {
	return (i - 1)/2;
}

template<class T>
int heap::left(int i) {
	if (i == 0){ //check that i is non-zero
		return 1;
	}
	else
		return i * 2;	
}

template<class T>
int heap::right(int i){
	if (i == 0){ //check that i is non-zero
		return 2;
	}
	else
		return i * 2 + 1;
}

template <class T>
int heap<T>::maxHeapify(int *a, int i) {
	int l = left(i);
	int r = right(i);
	int largest, temp;
	int size = a.size();
	
	if ((l <= size) &&(a[1] > a[i])){ //base case
		largest = l;
	}
	else {
		largest = i;
	}
	
	if ((r < size) && a[r] > a[largest]) {
		largest = r;
	}
	
	if (largest != i){
		//swap
		swap(a[i], a[largest]);
	/*	temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
	*/	
		
		maxHeapify(a, largest);	//call maxHeapify recursively
	}
	
}

template <class T>
int heap<T>::buildMaxHeap(int *a, int n) {
	int i;
	for (i = n/2; i >= 1; i--) {
		maxHeapify(a,i);
	}
}

template <class T> 
heap<T>::heapSort(int *a, int size) {
	size = a.size();
	
	while(size > 1) {
		swap(a[1], a[size - 1]);
		maxHeapify(a, size);
	}
}

template <class T>
heap<T>::buildMaxHeap(int *a, int n) {
	for((int i = n/2); i >= 1; i --) {
		maxHeapify(a, i);
	}
}

