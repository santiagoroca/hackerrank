#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <queue>

using namespace std;

struct node {
    int data;
    node* left = NULL;
    node* right = NULL;
};

void swapAtDepth (node* head, int atDepth, int depth) {
    if (head == NULL) {
        return;
    }
    
    swapAtDepth(head->left, atDepth, depth + 1);
    swapAtDepth(head->right, atDepth, depth + 1); 
    
    if (depth % atDepth == 0) {
        node* tmp = head->left;
        head->left = head->right;
        head->right = tmp;
    }
}

void printInOrder (node* head) {
    if (head == NULL) {
        return;
    }
    
    printInOrder(head->left);
    cout << head->data << " ";
    printInOrder(head->right);
}

int main() {
    string line;
    regex rx("-?\\d+");
    
    getline(cin, line);
    
    int node_count = stoi(line);
    
    node* head = new node();
    head->data = 1;
    
    queue<int> values;
    queue<node*> nodes;
    
    for (int i = 0; i < node_count; i++) {
        getline(cin, line);
                
        for (auto it = sregex_iterator(line.begin(), line.end(), rx); it != sregex_iterator(); it++) {
            values.push(stoi(it->str()));
        }
    }
    
    nodes.push(head);
    
    while (!values.empty() && !nodes.empty()) {
        node* c_node = nodes.front(); nodes.pop();
        
        int d_left = values.front(); values.pop();
        if (d_left != -1) {
            node* left = new node();
            left->data = d_left;
            c_node->left = left;
            nodes.push(left);
        }
        
        int d_right = values.front(); values.pop();
        if (d_right != -1) {
            node* right = new node();
            right->data = d_right;
            c_node->right = right;
            nodes.push(right);
        }
        
    }
    
    getline(cin, line);
    
    int operations_count = stoi(line);
    
    for (int i = 0; i < operations_count; i++) {
        getline(cin, line);
                
        swapAtDepth(head, stoi(line), 1);
        printInOrder(head);
        cout << endl;
    }
    
    return 0;
}
