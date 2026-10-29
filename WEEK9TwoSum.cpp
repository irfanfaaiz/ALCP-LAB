#include <iostream>
using namespace std;

// brute-force pair scan; fills out[] with the two indices and returns true if found
bool twoSum(int arr[], int n, int target, int out[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                out[0] = i;
                out[1] = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    static const int MAX = 100;   // user defined static size
    int n = 5;
    int target = 9;

    int arr[MAX] = {2, 7, 11, 15, 3};
    int out[2]   = {-1, -1};

    if (twoSum(arr, n, target, out))
        cout << "Indices: " << out[0] << " " << out[1] << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}
