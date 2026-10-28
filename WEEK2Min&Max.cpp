#include <iostream>
using namespace std;
void MaxMin(int i, int j, int &max, int &min, int a[]) {
    if (i == j) {
        max = min = a[i];
    }
    else if (i == j - 1) {
        if (a[i] > a[j]) {
            max = a[i];
            min = a[j];
        }
        else {
            max = a[j];
            min = a[i];
        }
    }
    else {
        int mid = (i + j) / 2;

        int max1, min1, max2, min2;

        MaxMin(i, mid, max1, min1, a);
        MaxMin(mid + 1, j, max2, min2, a);

        max = (max1 > max2) ? max1 : max2;
        min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int arr[] = {1, 20, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max, min;

    MaxMin(0, n - 1, max, min, arr);

    cout << "Maximum element = " << max << endl;
    cout << "Minimum element = " << min << endl;

    return 0;
}
