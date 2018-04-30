#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    long priority = rand();
    int value, size = 1;
};

int size (Node* root) {
    if (!root) {
        return 0;
    }
    
    return root->size;
}

void inorder (Node* root) {
    if (!root) {
        return;
    }
    
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void inorderList (Node* root, vector<int> *&_list) {
    if (!root) {
        return;
    }
    
    inorderList(root->left, _list);
    _list->push_back(root->value);
    inorderList(root->right, _list);
}

Node* join (Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (left->priority < right->priority) {
        left->right = join(left->right, right);
        left->size = size(left->left) + size(left->right) + 1;
        return left;
    }
    
    right->left = join(left, right->left);
    right->size = size(right->left) + size(right->right) + 1;
    return right;
}

void split (Node* root, int index, Node *&left, Node *&right) {
    if (!root) {
        left = right = NULL;
        return;
    } else {
        int current = size(root->left) + 1;
        
        if (index < current) {
            split(root->left, index, left, root->left);
            right = root;
        } else {
            split(root->right, index - current, root->right, right);
            left = root;
        }
    }
    
    root->size = size(root->left) + size(root->right) + 1;
}

Node* extract (Node *&root, int from, int to) {
    Node *left, *right, *medium;
    
    split(root, to, medium, right);
    split(medium, from, left, medium);
    
    root = join(left, right);
    
    return medium;
}

int main () {
    rand();
    
    int n, m;
    cin >> n >> m;
    
    Node* root = new Node;
    cin >> root->value;
    
    for (int i = 1; i < n; i++) {
        Node* n = new Node;
        cin >> n->value;
        root = join(root, n);
    }
    
    int type, from, to;
    Node* medium;
    for (int i = 0; i < m; i++) {
        cin >> type >> from >> to;
        medium = extract(root, from - 1, to);
        
        if (type == 1) {
            root = join(medium, root);
        } else {
            root = join(root, medium);
        }
    }
    
    vector<int> *nList = new vector<int>; 
    inorderList(root, nList);

    cout << abs(nList->at(0) - nList->at(nList->size() - 1)) << endl;
    for (int i = 0; i < nList->size(); i++) {
        cout << nList->at(i) << " ";
    }
}