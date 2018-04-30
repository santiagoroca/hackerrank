#include <bits/stdc++.h>
#include <stack>

using namespace std;

long max (long a, long b) {
    return a > b ? a : b;
}

long largestRectangle(vector <int> h) {
    long maxArea = 0;
    stack<int> index;
    
    //push a zero to force clean the stack
    h.push_back(0);
    
    int sizeOfH = h.size();    
    int i = 0;
    while (i < sizeOfH) {
        
        if (index.empty() || h[i] > h[index.top()]) {
            index.push(i);
            i++;
        } else {
            int pos = index.top();
            index.pop();
            maxArea = max(maxArea, h[pos] * (index.empty() ? i : i - index.top() - 1));
        }
        
    }
        
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}