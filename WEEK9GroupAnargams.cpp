#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// two words are anagrams iff their sorted forms match
string normalize(string s) {
    sort(s.begin(), s.end());
    return s;
}

// groups words that are anagrams of each other
void groupAnagrams(string words[], int n) {
    vector<vector<string>> groups;
    vector<string> keys;

    for (int i = 0; i < n; i++) {
        string key = normalize(words[i]);

        int found = -1;
        for (int j = 0; j < (int)keys.size(); j++) {
            if (keys[j] == key) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            keys.push_back(key);
            groups.push_back(vector<string>());
            groups.back().push_back(words[i]);
        } else {
            groups[found].push_back(words[i]);
        }
    }

    for (int i = 0; i < (int)groups.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < (int)groups[i].size(); j++) {
            cout << groups[i][j];
            if (j != (int)groups[i].size() - 1)
                cout << ", ";
        }
        cout << " ]\n";
    }
}

int main() {
    static const int MAX = 100;   // user defined static size
    int n = 6;

    string words[MAX] = {"eat", "tea", "tan", "ate", "nat", "bat"};

    groupAnagrams(words, n);

    return 0;
}
