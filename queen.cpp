#include "queen.h"
#include <iostream>
#include <fstream>

using namespace std;

Queen::Queen() {
    clearBoard();
}

void Queen::clearBoard() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = 0;
}

bool Queen::isSafe(int row, int col) {
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < SIZE; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

void Queen::solve(int col) {
    if (col >= SIZE) {
        addSolution();
        return;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

void Queen::solve() {
    solve(0);
}

void Queen::addSolution() {
    std::vector<int> solution(SIZE * SIZE, 0);
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            solution[i * SIZE + j] = board[i][j];

    if (isUniqueSolution(solution)) {
        solutions.push_back(solution);
    }
}

bool Queen::isUniqueSolution(const std::vector<int>& solution) {
    for (const auto& sol : solutions) {
        if (sol == solution)
            return false;
    }
    return true;
}

void Queen::printSolutions() {
    int t = 0;
    for (const auto& solution : solutions) {
        cout << "Решение " << ++t << endl;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j)
                cout << (solution[i * SIZE + j] ? " O " : " . ");
            cout << endl;
        }
        cout << endl;
    }
}

void Queen::saveSolutionsToFile(const char* filename) {
    ofstream file(filename);
    int t = 0;

    for (const auto& solution : solutions) {
        file << "Решение " << ++t << endl;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j)
                file << (solution[i * SIZE + j] ? " 0 " : " . ");
            file << endl;
        }
        file << endl;
    }
    file.close();
}