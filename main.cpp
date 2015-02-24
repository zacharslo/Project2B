/*
main.cpp
Authors: Andrew Blum and Zach Sloane

Description: Word search
*/

#include "heap.cpp"
#include "grid.cpp"
#include "wordList.cpp"
#include <string>
#include <time.h>

using namespace std;

wordList findMatches(const wordList& wordl, const grid& grid1);
void search();

int main() {
	search();
	
	return 0;
}

//finds words in the grid entered in the search function.
wordList findMatches(const grid& grid1, const vector<string>& wordl) {
	return grid1.findMatches(wordl);
}

//Sorts the word list and then finds words in the user-entered grid.
void search() {
	clock_t CPUtimeStart1;
	CPUtimeStart1 = clock();
	string fileName = "input15";
	cout << "Grid file to be used: input15.txt\n";
	grid grid1 = grid(fileName);
	wordList wordl = wordList();
	
	//Keeps track of the time it takes to run sort and find match
	clock_t CPUtimeStart2;
	CPUtimeStart2 = clock();
	clock_t CPUtimeHeap;
	clock_t CPUtimeSort1;
	clock_t CPUtimeSort2;
//	clock_t CPUtimeSort3;
	clock_t CPUtimeSearch;
	clock_t Totaltime;
	
	cout << "\nConverting word list into a heap.\n";
	heap<string> wordHeap(wordl.getWordList());
	
	//save how long it took to convert to heap
	CPUtimeHeap = clock();
	
	cout << "\nSorting....\n";
	wordl.insertionSort();
	cout << "\nSorted using Insertion Sort.\n";
	
	//save how long it took to insertionsort
	CPUtimeSort1 = clock();
	
	wordl.quickSort(0, wordl.getWordList().size() - 1);
	cout << "\nSorted using Quick Sort.\n";
	
	//save how long it took to quicksort
	CPUtimeSort2 = clock();
	/*
	wordl.mergeSort(0, wordl.getWordList().size() - 1);
	cout << "\nSorted using Merge Sort.\n";
	
	//save how long it took to quicksort
	CPUtimeSort3 = clock();
	*/
	cout << "Words found in your grid:\n";
	wordList matches = findMatches(grid1, wordl.getWordList());
	
	CPUtimeSearch = clock();
	
	matches.quickSort(0, matches.getWordList().size() - 1);
	matches.printWordList();
	
	cout << "\nThe time it took to convert the word list to a heap: " << difftime(CPUtimeHeap, CPUtimeStart2);
	cout << "\nThe time it took to insertionsort the word list: " << difftime(CPUtimeSort1, CPUtimeHeap);
	cout << "\nThe time it took to quicksort the word list: " << difftime(CPUtimeSort2, CPUtimeSort1);
//	cout << "\nThe time it took to mergesort the word list: " << difftime(CPUtimeSort3, CPUtimeSort2);
	cout << "\nThe time it took to search the grid for the words in the word list: " << difftime(CPUtimeSearch, CPUtimeSort2/*CPUtimeSort3*/) << "\n";
	cout << "\nThe total time it took to heap, quicksort, insert sort, and search the grid: " << difftime(CPUtimeSearch, CPUtimeStart2) << "\n";
	cout << "\nThe total time it took run this program: " << difftime(CPUtimeSearch, CPUtimeStart1) << "\n";
	
}
