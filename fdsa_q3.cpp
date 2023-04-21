#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void inorderTraversal(Node* node, vector<int>& values) {
    if (!node) return;
    inorderTraversal(node->left, values);
    values.push_back(node->data);
    inorderTraversal(node->right, values);
}

void setValues(Node* node, vector<int>& values, int& i) {
    if (!node) return;
    setValues(node->left, values, i);
    node->data = values[i++];
    setValues(node->right, values, i);
}

void eulerTour(Node* node, vector<int>& values) {
    if (!node) return;
    values.push_back(node->data);
    if (node->left) {
        eulerTour(node->left, values);
        values.push_back(node->data);
    }
    if (node->right) {
        eulerTour(node->right, values);
        values.push_back(node->data);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    // Create binary tree
    vector<Node*> nodes(n, NULL);
    nodes[0] = new Node(values[0]);
    for (int i = 0; i < n - 1; i++) {
        int parent_val = edges[i].first - 1;
        int child_val = edges[i].second - 1;
        if (!nodes[child_val]) {
            nodes[child_val] = new Node(values[child_val]);
        }
        Node* parent = nodes[parent_val];
        if (!parent->left) {
            parent->left = nodes[child_val];
        } else {
            parent->right = nodes[child_val];
        }
    }

    // Convert binary tree to BST
    vector<int> bst_values;
    inorderTraversal(nodes[0], bst_values);
    sort(bst_values.begin(), bst_values.end());
    int i = 0;
    setValues(nodes[0], bst_values, i);

    // Euler tour on BST
    vector<int> euler_values;
    eulerTour(nodes[0], euler_values);

    // Calculate total points collected during traversal
    int total_points = 0;
    for (int i = 0; i < euler_values.size(); i++) {
        total_points += euler_values[i];
    }
    cout << total_points << endl;

    return 0;
}
