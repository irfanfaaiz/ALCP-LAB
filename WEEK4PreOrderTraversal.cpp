#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

// builds the tree from a level-order list, -1 means no child
Node* buildTree(int vals[], int total) {
    static int idx = 0;   // own static counter for this file

    if (idx >= total || vals[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(vals[idx++]);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (idx < total && vals[idx] != -1) {
            curr->left = new Node(vals[idx]);
            q.push(curr->left);
        }
        idx++;

        if (idx < total && vals[idx] != -1) {
            curr->right = new Node(vals[idx]);
            q.push(curr->right);
        }
        idx++;
    }

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    static const int MAX = 15;   // user defined static size
    int vals[MAX] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};

    Node* root = buildTree(vals, MAX);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    return 0;
}
