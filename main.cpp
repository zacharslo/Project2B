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
void search(const int alg);

int main() {
	int sort = 1; 
	
	search(sort);
	
	return 0;
}

//finds words in the grid entered in the search function.
wordList findMatches(const grid& grid1, const vector<string>& wordl) {
	return grid1.findMatches(wordl);
}

//Sorts the word list and then finds words in the user-entered grid.
void search(const int alg) {
	clock_t CPUtimeStart1;
	CPUtimeStart1 = clock();
	string fileName = "input15";
	cout << "Grid file to be used: input15.txt\n";
	cin >> fileName;
	grid grid1 = grid(fileName);
	wordList wordl = wordList();
	
	//Keeps track of the time it takes to run sort and find match
	clock_t CPUtimeStart2;
	CPUtimeStart2 = clock();
	clock_t CPUtimeSort;
	clock_t CPUtimeSearch;
	clock_t Totaltime;
	
	cout << "\nSorting....\n";
	

	//save how long it took to sort
	CPUtimeSort = clock();
	
	cout << "Words found in your grid:\n";
	wordList matches = findMatches(grid1, wordl.getWordList());
	
	CPUtimeSearch = clock();
	
	matches.quickSort(0, matches.getWordList().size() - 1);
	matches.printWordList();
	
	cout << "\nThe time it took to sort the word list: " << difftime(CPUtimeSort, CPUtimeStart2);
	cout << "\nThe time it took to search the grid for the words in the word list: " << difftime(CPUtimeSearch, CPUtimeSort) << "\n";
	cout << "\nThe total time it took to sort the word list and to search the grid for\n  the words in the word list: " << difftime(CPUtimeSearch, CPUtimeStart2) << "\n";
	cout << "\nThe total time it took run this program: " << difftime(CPUtimeSearch, CPUtimeStart1) << "\n";
	
}
