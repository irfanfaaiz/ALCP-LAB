#include <iostream>
using namespace std;

// DFS helper: returns true if a cycle is found starting from v
bool dfs(int graph[][100], int visited[], int v, int parent, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (dfs(graph, visited, i, v, n))
                    return true;
            }
            else if (i != parent) {
                // visited neighbor that isn't the one we came from => cycle
                return true;
            }
        }
    }

    return false;
}

// separate function that runs DFS on every unvisited node
bool hasCycle(int graph[][100], int visited[], int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, i, -1, n))
                return true;
        }
    }
    return false;
}

int main() {
    static const int MAX = 100;   // user defined static size
    int n = 5;                    // fixed number of vertices

    static int graph[MAX][MAX];   // static so it lives off the stack
    static int visited[MAX];      // static visited array

    // hardcoded edges (undirected, so both sides set)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;   // this edge closes the cycle 0-1-2-3-0
    graph[3][4] = graph[4][3] = 1;

    if (hasCycle(graph, visited, n))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
