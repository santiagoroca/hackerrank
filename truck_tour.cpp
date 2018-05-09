#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    queue<long> numbers;
    long count, 
         petrol, 
         distance;
    
    cin >> count;
    
    for (int i = 0; i < count; i++) {
        cin >> petrol >> distance;
        numbers.push(petrol - distance);
    }
    
    long carryOver = 0;
    long index = 0, i = 0;
    while (!numbers.empty()) {
        carryOver += numbers.front();
        numbers.pop();
        i++;
        
        if (carryOver < 0) {
            carryOver = 0;
            index = i;
        }
    }
    
    cout << index;
    
    return 0;
}
