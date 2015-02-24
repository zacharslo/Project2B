/*
wordList.cpp
Authors: Andrew Blum and Zach Sloane

Description: Used to read from a text file and store a list of words as a vector
*/

#ifndef WORDLIST_FUNCTS
#define WORDLIST_FUNCTS

#include "wordList.h"

//initiates wordlist
wordList::wordList() {
	readWordList("wordlist.txt");
}

//initiates wordlist (alowing custom wordlist file to be used)
wordList::wordList(const string& fileLoc) {
	readWordList(fileLoc);
}

//initiates wordlist (populates wordlist using a vector of strings)
wordList::wordList(const vector<string>& wordl) {
	words = wordl;
}

//prints out the words in the word list
void wordList::printWordList() {
	cout << words;
}

//returns the words in the word list
vector<string> wordList::getWordList() const {
	return words;
}


//sorts the words in the word list using the insertion sort method
void wordList::insertionSort() {
	string temp;
    for (int i = 1; i < words.size() - 1; i++){
        for(int j = 0; j < i; j++) {
        	if(words[j].compare(words[i]) < 0) {
        		temp = words[j];
        		words.erase(words.begin() + j);
				words.insert(words.begin() + i, temp);
			}
		}
		cout << "outside";
    }
}

//sorts the words in the word list using the quick sort method
void wordList::quickSort( const int& low, const int& high) {
	if(high - low > 1) {
		
		string pivot = words[high - 1];
		int split = low;
	
		for(int i = low; i < high; i++) {
			if(words[i].compare(pivot) < 0) {
				swap(i, split);
				split++;
			}
		}
	
		swap(high - 1, split);
	
		quickSort(low, split);
		quickSort(split + 1, high);
	}
}

//sorts the words in the word list using the merge sort method
void wordList::mergeSort() {
	int middle = words.size()/2;
	vector<string> first(middle);
	vector<string> second(words.size() - middle);
	for(int i = 0; i < first.size() - 1; i++) {
		first[i] = words[i];
	}
	int i = first.size();
	for(int j = 0; j < second.size() - 1; j++) {
		second[j] = words[i];
		i++;
	}
	int a = 0;
	int b = 0;
	vector<string> temp1 = first;
	first = merge(temp1);
	vector<string> temp2 = second;
	second = merge(temp2);
	cout << "put back together";
	for(int k = 0; k < words.size() - 1; k++) {
		if(a < first.size() - 1 && b < second.size() - 1) {
			if(first[a].compare(second[b]) < 0) {
				words[k] = first[a];
				a++;
			}
			if(first[a].compare(second[b]) >= 0) {
				words[k] = second[b];
				b++;
			}
		}
		if(a < first.size() - 1 && b >= second.size() - 1) {
			words[k] = first[a];
			a++;
		}
		if(a >= first.size() - 1 && b < second.size() - 1) {
			words[k] = second[b];
			b++;
		}
	}
}

bool wordList::binarySearch(const string& word, int start, int end) const{
    if(end < start)
        return false;
    else if (start == end)
        return word.compare(words[start]) == 0;
    
    int middle = (start + end)/2;
    int compareRes = word.compare(words[middle]);
    
    if(compareRes ==0)
        return true;
    else if(compareRes < 0)
        return binarySearch(word, start, middle);
    else
        return binarySearch(word, middle + 1, end);
}


//gets the word list from an inputted file
void wordList::readWordList(const string& fileLoc) {
	//opens word list file
	ifstream wordListFile;
	wordListFile.open(fileLoc.c_str());
	string line;
	
	//reads each line into words vector
	if(wordListFile.is_open()) {
		while(wordListFile.good()) {
			getline(wordListFile, line);
			words.push_back(line);
		}
	}
	//closes word list file
	wordListFile.close();
}


vector<string> wordList::merge(const vector<string> list) {
	vector<string> half = list;
	if(half.size() == 1) {
		return half;
	}
	cout << "1";
	int middle = half.size()/2;
	vector<string> first(middle);
	vector<string> second(words.size() - middle);
	for(int i = 0; i < first.size() - 1; i++) {
		first[i] = half[i];
	}
	int a = first.size();
	for(int j = 0; j < second.size() - 1; j++) {
		second[j] = half[a];
		a++;
	}
	cout << "2";
	a = 0;
	int b = 0;
	vector<string> temp1 = first;
	first = merge(temp1);
	vector<string> temp2 = second;
	second = merge(temp2);
	cout << "3";
	for(int k = 0; k < half.size() - 1; k++) {
		if(a < first.size() - 1 && b < second.size() - 1) {
			if(first[a].compare(second[b]) < 0) {
				half[k] = first[a];
				a++;
			}
			if(first[a].compare(second[b]) >= 0) {
				half[k] = second[b];
				b++;
			}
		}
		if(a < first.size() - 1 && b >= second.size() - 1) {
			half[k] = first[a];
			a++;
		}
		if(a >= first.size() - 1 && b < second.size() - 1) {
			half[k] = second[b];
			b++;
		}
	}
	cout << "4";
	return half;
}

//swaps 2 words in the word list at the inputted positions (used in quick sort)
void wordList::swap(int word1, int word2) {
	string tempword = words[word1];
	words[word1] = words[word2];
	words[word2] = tempword;
}

#endif
