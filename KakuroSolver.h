/*
 * KakuroSolver.h
 * Sam Lacet-Brown
 * March 2021
 */

#ifndef __KAKUROSOLVER__
#define __KAKUROSOLVER__

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class KakuroSolver {
    public:
        KakuroSolver(int s);
        ~KakuroSolver();
        void showGrid();
        void processInput(istream &inputFile);
        void solve();
        vector<int> calcPossible(int loc);
        int* getHints(int loc, int *arr);
        struct gridSpace {
            int vert;
            int hori;
            int val; //black is -1, white is 0
            bool solved;
        };
        vector<gridSpace> grid;
    private:
        int size;
        int emptyFields;
};

#endif