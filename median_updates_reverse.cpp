#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>

using namespace std;
/* Head ends here */    


#define intt long long int

void balance (multiset<double> *small, multiset<double, greater<double>> *great) {
    int sCount = small->size();
    int gCount = great->size();
    int dif = sCount - gCount;
    
    //cout << "Diference " << dif << endl;
    
    if (dif > 1) {
        multiset<double>::iterator sIt = small->begin();
        great->insert(*sIt);
        small->erase(sIt);
    }
    
    if (dif < -1) {
        multiset<double, greater<double>>::iterator gIt = great->begin();
        small->insert(*gIt);
        great->erase(gIt);
    }
}

void add (multiset<double> *small, multiset<double, greater<double>> *great, double n) {
    multiset<double>::iterator sIt = small->begin();
    
    if (small->size() == 0 || n >= *sIt) {
        small->insert(n);
    } else {
        great->insert(n);
    }
}

bool remove (multiset<double> *small, multiset<double, greater<double>> *great, double n) {
    int sCount = small->size();
    int gCount = great->size();
    
    multiset<double>::iterator sIt = small->begin();
    if (sCount != 0 && n >= *sIt) {
        auto it = small->find(n);
        if (it != small->end()) {
            //cout << "Erasing " << *sIt <<  endl;
            small->erase(it);
            return true;
        }
    }
    
    multiset<double, greater<double>>::iterator gIt = great->begin();
    if (sCount != 0 && n <= *gIt) {
        auto it = great->find(n);
        if (it != great->end()) {
            //cout << "Erasing " << *sIt <<  endl;
            great->erase(it);
            return true;
        }
    }
    
    return false;
}

void printMedian (multiset<double> *small, multiset<double, greater<double>> *great) {
    
    //cout << "Value ";
    
    int sCount = small->size();
    int gCount = great->size();
    int dif = sCount - gCount;
    
    multiset<double>::iterator sIt;
    multiset<double, greater<double>>::iterator gIt;
    
    if (dif > 0) {
        sIt = small->begin();
        cout << fixed << setprecision(0) << *sIt << endl;
        return;
    } 
    
    if (dif < 0) {
        gIt = great->begin();
        cout << fixed << setprecision(0) << *gIt << endl;
        return;
    }
    
    sIt = small->begin();
    gIt = great->begin();
    
    double result = (*sIt + *gIt) / 2;
    if (result == ((intt)result)) {
        cout << fixed << setprecision(0) << ((intt)result) << endl;
    } else {
        cout << fixed << setprecision(1) << result << endl;
    }
}

void printBoth (multiset<double> *small, multiset<double, greater<double>> *great) {
    multiset<double>::iterator sIt = small->begin();
    multiset<double, greater<double>>::iterator gIt = great->begin();
    
    cout << "S "; 
    for (; sIt != small->end(); sIt++) {
        cout << *sIt << " ";
    }
    cout << endl;
    
    cout << "G ";
    for (; gIt != great->end(); gIt++) {
        cout << *gIt << " ";
    }
    cout << endl;
}

void median(vector<char> s,vector<int> X) {
    multiset<double> small;
    multiset<double, greater<double>> great;
    
    double type, value;
    for (int i = 0; i < s.size(); i++) {
        type = s[i], value = (double)X[i];
        
        //cout << endl;
        //cout << i << " " << type << " " << value << endl;
        
        if (type == 'a') {
            add(&small, &great, value);
            balance(&small, &great);
            printMedian(&small, &great);
        } else {
            if (remove(&small, &great, value)) {
                balance(&small, &great);
                printMedian(&small, &great);    
            } else {
                cout << "Wrong!" << endl;
            }   
        }
        
        //printBoth(&small, &great);
    }
    
}

int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   
   vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   
   median(s,X);
   return 0;
}