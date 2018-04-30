#include <bits/stdc++.h>
#include <stack>

using namespace std;

int max (int a, int b) {
    return a > b ? a : b;
}

int poisonousPlants(vector <int> p) {
    stack<int> positions, days;
    
    int index = 0;
    int maxDaysToDie = -1;
    int daysToDie = 0;
    
    while (index < p.size()) {        
        if (!positions.empty() && p[index] <= p[positions.top()]) {
            daysToDie = max(daysToDie, days.top() + 1);
                        
            //Pop bigger element than current
            positions.pop();
            days.pop();
        } else {
            if (positions.empty()) {
                daysToDie = -1;
            }
            
            maxDaysToDie = max(maxDaysToDie, daysToDie + 1);
            
            //Store current Plant
            days.push(daysToDie);
            positions.push(index);
            
            daysToDie = 0;
            index++;
        }
        
    }
    
    return maxDaysToDie;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    int result = poisonousPlants(p);
    cout << result << endl;
    return 0;
}
