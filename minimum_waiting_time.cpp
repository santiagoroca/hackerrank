#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

typedef long long int llint;

using namespace std;

struct customer {
    llint arrival = 0;
    llint cookTime = 0;
    bool operator<(const customer& c) const
    {
        return arrival > c.arrival;
    };
};


struct cmp
{
    bool operator()(customer a, customer b)
    {
        return a.cookTime > b.cookTime;
    }
};

llint max (llint a, llint b) {
    return a > b ? a : b;
}

llint min (llint a, llint b) {
    return a < b ? a : b;
}

int main() {
    llint count, arrival, cookTime, timeElapsedSinceLastCoockedPizza;
    llint totalCookTime = 0, currentTime = 0;
    
    cin >> count;
    
    priority_queue<customer> customers;
    priority_queue<customer, vector<customer>, cmp> waitingList;
    
    for (int i = 0; i < count; i++) {
        customer c;
        cin >> c.arrival;
        cin >> c.cookTime;
        customers.push(c);
    }
    
    while (!waitingList.empty() || !customers.empty()) {
        
        while (!customers.empty() && customers.top().arrival <= currentTime) {
            waitingList.push(customers.top());
            customers.pop();
        }
        
        if (waitingList.empty()) {
            currentTime = customers.top().arrival;
            continue;
        }
        
        currentTime += waitingList.top().cookTime;
        totalCookTime += currentTime - waitingList.top().arrival;
        waitingList.pop();
    }
    
    cout << totalCookTime / count << endl;
    
    return 0;
}
