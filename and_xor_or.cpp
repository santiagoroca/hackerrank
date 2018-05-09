#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    int count, value;
    cin >> count;
    
    vector<long> numbers;
    stack<long> aux;
    
    while (count--) {
        cin >> value;
        numbers.push_back(value);
    }
    
    long max = 0;
    long i = 0;
    while (i < numbers.size()) {
        while (!aux.empty()) {
            long n = numbers[i] ^ aux.top();
            if (n > max) {
                max = n;
            }
            
            if (aux.top() > numbers[i]) {
                aux.pop();
            } else {
                break;
            }
        }
        
        aux.push(numbers[i]);
        i++;
    }
    
    cout << max << endl;
    
    return 0;
}
