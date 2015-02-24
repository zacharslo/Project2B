/*
Grid.cpp
Authors: Andrew Blum and Zach Sloane

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_FUNCTS
#define GRID_FUNCTS

#include "grid.h"

grid::grid(const string& name) {
	readGrid(name);
}

//I think it works now. Still needs to be tested though.
wordList grid::findMatches(const vector<string>& wordl) const{
	vector<string> match;
	string word;
	char character;
	bool wordfound;
	int dir = 0; // direction of word from first letter; (based off numpad) 1 = left-down (-,-), 2 = down (0,-), 3 = right-down (+,-), 4 = left (-,0), 6 = right (+,0), 7 = left-up (-,+), 8 = up (0,+), 9 = right up (+,+)
	
	//Finds words in grid matrix and appends found words to the end of the match vector
	for(int r = 0; r < (rows - 1); r++) {
		for(int c = 0; c < (columns - 1); c++) {
			for(int i = 0; i < (wordl.size() - 1); i++) {
				word = wordl[i];
				character = word[0];
				if(character == mygrid[r][c]) {
					wordfound = followWord(dir, r, c, word);
				}
				if(wordfound) {
					match.push_back(word);
				}
			}
		}
	}
	
	//Makes a new word list of the matching words and prints the list out
	wordList matches(match);
	return matches;
}

void grid::readGrid(const string& fileName) {
	// untested, but I think it will work.
	char character;
	string line;
	string getNumber;
	bool num1read = false;
	bool num2read = false;
	int n = 0;
	
	//opensgrid file
	ifstream gridfile;
	gridfile.open(fileName.c_str());
	
	//parses grid file
	if(gridfile.is_open()) {
		//gets the first line of the file (to get the row and column numbers)
		getline(gridfile, line);
		//separates the numbers and enters them into rows and columns in the grid class
		for(int i = 0; i < (line.length()); i++) {
			if(isdigit(line[i])) {
				getNumber[n] = line[i];
				n++;
				num1read = true;
			}
			if(!isdigit(line[i]) && num1read && !num2read) {
				rows = atoi(getNumber.c_str());
				getNumber = "";
				n = 0;
			}
		}
		columns = atoi(getNumber.c_str());
		
		//sizes the grid matrix to the correct size
		mygrid.resize(rows, columns);
		n = 0;
		
		//populates the grid in the grid class from the grid in the file
		while(n < rows) {
			if(!gridfile.good()) {
				break;
			}
			for(int i = 0; i < columns; i++) {
				character = gridfile.get();
				if(character != ' ' && character != '\n') {
					mygrid[n][i] = character;			
				}
				if(character == ' ' || character == '\n') {
					i--;
				}
			}
			n++;
		}
	}
	//closes the grid file
	gridfile.close();
}

//helper function to find words in grid, once the first letter of a word is found, it checks to see if the rest of the word follows in any direction. If it is, then the true is returned
bool grid::followWord(const int& dir, const int& row, const int& col, const string& word) const {
	int r = row;
	int c = col;
	string temp;
	bool output;
	switch(dir) {
		//run through all the directions
		case 0:
			output = followWord(1, r, c, word);
			output = followWord(2, r, c, word);
			output = followWord(3, r, c, word);
			output = followWord(4, r, c, word);
			output = followWord(6, r, c, word);
			output = followWord(7, r, c, word);
			output = followWord(8, r, c, word);
			output = followWord(9, r, c, word);
			break;
		case 1:
			//checks to bottom left
			for(int i = 0; i < word.length(); i++) {
				if(r-i < 0) {
					r += rows;
				}
				if(c-i < 0) {
					c += columns;
				}
				temp.push_back(mygrid[r-i][c-i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 2:
			//checks to bottom
			for(int i = 0; i < word.length(); i++) {
				
				if(c-i < 0) {
					c += columns;
				}
				temp.push_back(mygrid[r][c-i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 3:
			//checks to bottom right
			for(int i = 0; i < word.length(); i++) {
				if(r+i > (rows-1)) {
					r -= rows;
				}
				if(c-i < 0) {
					c += columns;
				}
				temp.push_back(mygrid[r+i][c-i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 4:
			//checks to left
			for(int i = 0; i < word.length(); i++) {
				if(r-i < 0) {
					r += rows;
				}
				temp.push_back(mygrid[r-i][c]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 6:
			//checks to right
			for(int i = 0; i < word.length(); i++) {
				if(r+i > (rows-1)) {
					r -= rows;
				}
				temp.push_back(mygrid[r+i][c]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 7:
			//checks to top left
			for(int i = 0; i < word.length(); i++) {
				if(r-i < 0) {
					r += rows;
				}
				if(c+i > (columns-1)) {
					c -= rows;
				}
				temp.push_back(mygrid[r-i][c+i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 8:
			//checks to top
			for(int i = 0; i < word.length(); i++) {
				if(c+i > (columns-1)) {
					c -= rows;
				}
				temp.push_back(mygrid[r][c+i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		case 9:
			//checks to right
			for(int i = 0; i < word.length(); i++) {
				if(r+i > (rows-1)) {
					r -= rows;
				}
				if(c+i > (columns-1)) {
					c -= rows;
				}
				temp.push_back(mygrid[r+i][c+i]);
			}
			if(temp == word) {
				return true;
			}
			if(temp != word) {
				return false;
			}
			break;
		default:
			cout << "\nfindMatch - 'default' called.\n";
			output = followWord(0, r, c, word);
	}
	return output;
}

#endif
