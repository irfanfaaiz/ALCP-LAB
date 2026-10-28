#include <iostream>
using namespace std;

// selection sort by ratio, descending — sorts ratio, weights, and profits together
void sortByRatio(double ratio[], int w[], int p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
            if (ratio[j] > ratio[maxIdx])
                maxIdx = j;

        // swap all three arrays so item (w, p, ratio) stays intact
        double tr = ratio[i]; ratio[i] = ratio[maxIdx]; ratio[maxIdx] = tr;
        int tw = w[i];        w[i] = w[maxIdx];       w[maxIdx] = tw;
        int tp = p[i];        p[i] = p[maxIdx];       p[maxIdx] = tp;
    }
}

// fills x[] with fractions taken and returns the total profit
double GreedyKnapsack(int w[], int p[], int M, int n, double x[]) {
    double ratio[100];
    for (int i = 0; i < n; i++)
        ratio[i] = (double)p[i] / w[i];

    sortByRatio(ratio, w, p, n);

    int weight = 0;
    double profit = 0;

    for (int i = 0; i < n; i++) {
        if (weight + w[i] <= M) {
            x[i] = 1.0;
            weight += w[i];
            profit += p[i];
        } else {
            x[i] = (double)(M - weight) / w[i];
            profit += p[i] * x[i];
            weight = M;
            break;   // knapsack full
        }
    }

    return profit;
}

int main() {
    static const int MAX = 100;   // user defined static size
    int n = 7;
    int M = 15;

    int profits[MAX] = {10, 5, 15, 7, 6, 18, 3};
    int masses[MAX]  = {2, 3, 5, 7, 1, 4, 1};
    double x[MAX] = {0};

    double total = GreedyKnapsack(masses, profits, M, n, x);

    cout << "Fractions taken: ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "\nMax profit: " << total << endl;

    return 0;
}
