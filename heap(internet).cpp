//By Andrew Blum and Zach Sloane

#ifndef HEAP
#define HEAP

#include <stdlib.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <math.h>

using namespace std;

template<class T> class heap;

template<class T> 
class heapnode {
	friend class heap<T>;
	public :
		heapnode(T, int);
		heapnode(T, heapnode<T> *,int);
		T getdata() { return data; };
	private :
		T data;
		int mynum;
		heapnode<T> *parent;
		heapnode<T> *lchild;
		heapnode<T> *rchild;
};

template<class T> 
class heap {
	public :
		heap(T);
		~heap();

	private :
		heapnode<T> *rootptr;
		heapnode<T> *endptr;
		
		T getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify(vector<heap> A, int n);
		void buildMaxHeap();
		
		void initializeMinHeap();
		void minHeapify(const vector<heap> A, const int n);
		void buildMinHeap();
		
		void heapsort();
};

#endif
