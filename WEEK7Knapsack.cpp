#include <iostream>
using namespace std;

// DP table: dp[i][c] = best value using first i items with capacity c
int knapsack(int w[], int p[], int n, int M) {
    static int dp[100][100];   // static so it lives off the stack

    // first row and column stay 0 — nothing to take, or no room
    for (int i = 0; i <= n; i++) {
        for (int c = 0; c <= M; c++) {
            if (i == 0 || c == 0)
                dp[i][c] = 0;
            else if (w[i - 1] <= c)
                dp[i][c] = max(p[i - 1] + dp[i - 1][c - w[i - 1]], dp[i - 1][c]);
            else
                dp[i][c] = dp[i - 1][c];
        }
    }

    return dp[n][M];
}

// separate helper that walks the DP table backwards to find which items were taken
void showPicked(int w[], int p[], int n, int M, int dp[][100], int picked[]) {
    int c = M;
    for (int i = n; i > 0; i--) {
        if (dp[i][c] != dp[i - 1][c]) {
            picked[i - 1] = 1;      // item i-1 was taken
            c -= w[i - 1];
        }
    }
}

int main() {
    static const int MAX = 100;   // user defined static size
    int n = 4;                    // fixed number of items
    int M = 8;                    // fixed capacity

    int weights[MAX]  = {2, 3, 4, 5};
    int profits[MAX]  = {3, 4, 5, 6};
    int picked[MAX]   = {0};

    int total = knapsack(weights, profits, n, M);

    // rebuild dp the same way so showPicked can read it
    static int dp[100][100];
    for (int i = 0; i <= n; i++) {
        for (int c = 0; c <= M; c++) {
            if (i == 0 || c == 0)
                dp[i][c] = 0;
            else if (weights[i - 1] <= c)
                dp[i][c] = max(profits[i - 1] + dp[i - 1][c - weights[i - 1]], dp[i - 1][c]);
            else
                dp[i][c] = dp[i - 1][c];
        }
    }

    showPicked(weights, profits, n, M, dp, picked);

    cout << "Items taken: ";
    for (int i = 0; i < n; i++)
        cout << picked[i] << " ";

    cout << "\nTotal value: " << total << endl;

    return 0;
}
