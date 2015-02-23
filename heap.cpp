/*
Heap.cpp
Authors: Zach Sloane and Andrew Blum

*/

#include<iostream>
#include "heap.h"

using namespace std;

heap::parent(int i) {
	return int(i/2);
}

heap::left(int i) {
	return i * 2;
}

heap::right(int i){
	return i * 2 + 1;
}

heap::maxHeapify(int *a, int i) {
	int l = left(i);
	int r = right(i);
	int largest, temp;
	
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
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		
		
		maxHeapify(a, largest);	//call maxHeapify recursively
	}
	
}

heap::buildMaxHeap(int *a, int n) {
	int i;
	for (i = n/2; i >= 1; i--) {
		maxHeapify(a,i);
	}
}

