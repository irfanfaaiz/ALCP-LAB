#include <iostream>
using namespace std;

void slidingWindowMax(int arr[], int n, int k) {
    for (int i = 0; i <= n - k; i++) {
        int max = arr[i];

        for (int j = i; j < i + k; j++) {
            if (arr[j] > max)
                max = arr[j];
        }

        cout << max << " ";
    }
}

int main() {
    static const int MAX = 100;   
    int n = 8;                    
    int k = 3;                    
    int arr[MAX] = {1, 3, -1, -3, 5, 3, 6, 7};

    cout << "Sliding Window Maximum: ";
    slidingWindowMax(arr, n, k);

    return 0;
}
