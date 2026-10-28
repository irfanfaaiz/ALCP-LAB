#include <iostream>
#include <stack>
using namespace std;

void findNextGreater(int arr[], int res[], int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
}

int main() {
    static const int MAX = 100;   
    int n = 6;                   
    int arr[MAX] = {4, 5, 2, 25, 7, 8};
    int result[MAX];

    for (int i = 0; i < n; i++)
        result[i] = -1;

    findNextGreater(arr, result, n);

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}
