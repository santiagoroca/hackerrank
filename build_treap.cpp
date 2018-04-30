#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    long value, priority;
    node *left, *right;
};

node *join(node* left, node* right) {
    if (!left) {
        return right;
    }

    if (!right) {
        return left;
    }

    if (left->priority > right->priority) {
        left->right = join(left->right, right);
        return left;
    }

    right->left = join(left, right->left);
    return right;
}

void inorder (node* root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void level (node* root) {
    queue<node*> nodes;

    int i = 0;

    nodes.push(root);
    while (!nodes.empty() || (i++) >= 100) {
        node* n = nodes.front();
        nodes.pop();

        if (!n) {
            cout << "N ";
            nodes.push(NULL);
            nodes.push(NULL);
        } else {
            cout << n->value << " ";
            nodes.push(n->left);
            nodes.push(n->right);
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    node* root = new node;
          root->priority = rand();

    cin >> root->value;

    for (int i = 0; i < n - 1; i++) {
        node* n = new node;
             n->priority = rand();
        cin >> n->value;

        root = join(root, n);
    }

    level(root);
}
