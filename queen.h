#ifndef QUEEN_H
#define QUEEN_H

#include <vector>

class Queen {
public:
    Queen();
    void solve();
    void printSolutions();
    void saveSolutionsToFile(const char* filename);

private:
    static const int SIZE = 8;
    int board[SIZE][SIZE];
    std::vector<std::vector<int>> solutions;
    bool isSafe(int row, int col);
    void clearBoard();
    void solve(int col);
    bool isUniqueSolution(const std::vector<int>& solution);
    void addSolution();
};

#endif // QUEEN_H