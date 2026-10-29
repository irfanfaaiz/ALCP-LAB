#include <iostream>
#include <string>
using namespace std;

// DFS in four directions; visits each cell at most once on the current path
bool dfs(char grid[][100], int rows, int cols, int r, int c,
         string word, int idx, bool visited[][100]) {
    if (idx == (int)word.length())
        return true;
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;
    if (visited[r][c] || grid[r][c] != word[idx])
        return false;

    visited[r][c] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; d++) {
        if (dfs(grid, rows, cols, r + dr[d], c + dc[d], word, idx + 1, visited))
            return true;
    }

    visited[r][c] = false;   // backtrack
    return false;
}

// tries DFS from every cell as a starting point
bool wordSearch(char grid[][100], int rows, int cols, string word) {
    static bool visited[100][100];   // static so it lives off the stack

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (dfs(grid, rows, cols, r, c, word, 0, visited))
                return true;

    return false;
}

int main() {
    static const int MAX = 100;   // user defined static size
    int rows = 3, cols = 4;

    char grid[MAX][MAX] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (wordSearch(grid, rows, cols, word))
        cout << "Word found: " << word << endl;
    else
        cout << "Word not found: " << word << endl;

    return 0;
}
