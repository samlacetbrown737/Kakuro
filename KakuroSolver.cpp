/*
 * KakuroSolver.cpp
 * Sam Lacet-Brown
 * March 2021
 *
 * This program finds a solution to a Kakuro
 * puzzle, given a grid size and inputs.
 */

#include "KakuroSolver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

KakuroSolver::KakuroSolver(int s) {
    size = s;
    emptyFields = 0;
}

KakuroSolver::~KakuroSolver() {}

void KakuroSolver::processInput(istream &inputFile) {;
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(inputFile.rdbuf());
    for(int i = 0; i < (size * size); i++) {
        grid.push_back(gridSpace());
        cin >> grid[i].vert;
        cin >> grid[i].hori;
        cin >> grid[i].val;
        grid[i].solved = true;
        if(grid[i].val == 0) {
            emptyFields++;
            grid[i].solved = false;
        }
    }
    cin.rdbuf(cinbuf);
}

void KakuroSolver::showGrid() {
    int x = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << " -------";
        }
        cout << endl;
        cout << '|';
        for(int j = 0; j < size; j++) {
            cout << "       |";
        }
        cout << endl;
        cout << '|';
        for(int j = 0; j < size; j++) {
            if(grid[x].val == -1) {
                if(grid[x].hori != 0 || grid[x].vert != 0) {
                    cout << ' ' << setw(2) << setfill('0') << grid[x].vert;
                    cout << '\\';
                    cout << setw(2) << setfill('0') << grid[x].hori << ' '; 
                    cout << '|';
                } else {
                    cout << "   *   |";
                }
            } else if (grid[x].val == 0) {
                int arr[2];
                int *hints = getHints(x, arr);
                cout << " (" << setw(3) << setfill('0') << hints[1];
                cout << ") |";
            }
            x++;
        }
        cout << endl;
        for(int j = 0; j < size; j++) {
            cout << "|       ";
        }
        cout << '|' << endl;
    }
    for(int j = 0; j < size; j++) {
        cout << " -------";

    }
}

void KakuroSolver::solve() {
    if(emptyFields == 0) {
        showGrid();
        return;
    } else {
        int spot = -1;
        while(emptyFields != 0) {
            spot++;
            if(grid[spot].solved = false) {
                vector<int> values = calcPossible(spot);
                for(int i = 0; i < values.size(); i++) {
                    grid[spot].val = values[i];
                    solve();
                }
            }
        }
    }
}

vector<int> KakuroSolver::calcPossible(int loc) {
    vector<int> possible;
    int arr[2];
    int* hints = getHints(loc, arr);
    int horiHint = hints[0];
    int vertHint = hints[1];
    cout << "loc: " << loc << endl;
    cout << "hori: " << horiHint << endl;
    cout << "vert: " << vertHint << endl;
    return possible;
}

int* KakuroSolver::getHints(int loc, int *arr) {
    int check = loc;
    int horiHint = 0;
    int vertHint = 0;
    while(horiHint == 0) {
        check--;
        horiHint = grid[check].hori;
    }
    check = loc;
    while(vertHint == 0) {
        check = check - size;
        vertHint = grid[check].vert;
    }
    arr[0] = horiHint;
    arr[1] = vertHint;
    return arr;
}