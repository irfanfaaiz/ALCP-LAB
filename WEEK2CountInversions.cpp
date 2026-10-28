#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];

    return inversions;
}

long long countInversions(vector<int>& a, int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += countInversions(a, left, mid);
    count += countInversions(a, mid + 1, right);
    count += mergeAndCount(a, left, mid, right);

    return count;
}

int main() {
    vector<int> a = {5, 3, 2, 4, 1};

    cout << countInversions(a, 0, a.size() - 1) << '\n';

    return 0;
}
