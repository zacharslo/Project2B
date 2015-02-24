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
<<<<<<< HEAD:heap(testing).h
		string parent() const;
		heap left(const int n);
		int left() const;
		heap right(const int n);
		int right() const;
		string getItem(const int n);
		
		void initializeMaxHeap();
		void maxHeapify(vector<heap> A, int n);
		void buildMaxHeap();
		
		void initializeMinHeap();
		void minHeapify(const vector<heap> A, const int n);
		void buildMinHeap();
=======
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
>>>>>>> origin/master:heap.h
		
		void heapsort(int *a, int size);
		
<<<<<<< HEAD:heap(testing).h
		int size() const;
=======
		int size() const {return s;};
>>>>>>> origin/master:heap.h
		
	private:
		vector<string> h;
		
<<<<<<< HEAD:heap(testing).h
		int leftindex;
		int rightindex;
		int parentindex;
=======
		int parentindex;
		int leftindex;		//change vector<string> to heap?
		int rightindex;		//change vector<string> to heap?
>>>>>>> origin/master:heap.h
		int index;
		int s;
};
