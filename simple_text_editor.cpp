#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void add (string* base, string append) {
    *base += append;
}

string substract (string* base, int count) {
    int sSize = base->size();
    string r = base->substr(sSize - count, sSize);
    base->resize(sSize - count);
    return r;
}


int main() {
    int operationsCount, operationType, intOperationValue;
    string stringOperationValue;
    stack<int> operation;
    stack<string> value;
    
    cin >> operationsCount;
    
    string text;
    for (int i = 0; i < operationsCount; i++) {
        cin >> operationType;
        
        switch (operationType) {
                
            case 1: {
                cin >> stringOperationValue;
                operation.push(1);
                value.push(stringOperationValue);
                add(&text, stringOperationValue);
            } break;
                
            case 2: {
                cin >> intOperationValue;
                operation.push(2);
                value.push(substract(&text, intOperationValue));
            } break;
                
            case 3: {
                cin >> intOperationValue;
                cout << text[intOperationValue - 1] << endl;
            } break;
                
            case 4: {
                intOperationValue = operation.top();
                
                if (intOperationValue == 1) {
                    substract(&text, value.top().size());
                } else {
                    add(&text, value.top());
                }
                
                operation.pop();
                value.pop();
            }

        }
    }
    
    return 0;
}
