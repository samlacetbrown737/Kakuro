/*
 * main.cpp
 * KakuroSolver
 * Sam Lacet-Brown
 * March 2021
 */

#include "KakuroSolver.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 3) {
        ifstream inputFile;
        inputFile.open(argv[2]);
        if(!inputFile.is_open()) {
            cerr << argv[2] << " cannot be opened." << endl;
            return 0;
        }
        KakuroSolver *solver = new KakuroSolver(atoi(argv[1]));
        solver->processInput(inputFile);
        inputFile.close();
        //input should be formatted as an enter separated list
        //with 0 0 -1 as black spaces and 0 0 0 as blanks
        //and horizonalClue verticalClue -1 for hint spaces
        solver->showGrid();
        solver->calcPossible(29);
    } else {
        cerr << "Usage: ./ks gridSize inputFile";
    }
    return 0;
}