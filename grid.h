/*
Grid.h
Authors: Andrew Blum and Zach Sloane

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_CLASS
#define GRID_CLASS

#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "wordList.cpp"

#include "d_matrix.h" //Has a warning, because it #includes "d_except.h" which contains the strstream library. This library is out of date and therefore a warning message appears telling us that it "may be removed without further notice at a future date". Ignore this warning message for now.

using namespace std;

class grid {
	public:
    	grid(const string& name);
    	wordList findMatches(const vector<string>& wordl) const;

	private:
		void readGrid(const string& name);
		bool followWord(const int& dir, const int& row, const int& column, const string& word) const;
		int rows;
		int columns;
		matrix<char> mygrid;
};

#endif
