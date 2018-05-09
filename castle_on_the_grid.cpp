#include <bits/stdc++.h>
#include <utility>

using namespace std;

struct node {
    long x;
    long y;
    long c;
    node(long _x, long _y, long _c)
	{
		x = _x;
        y = _y;
        c = _c;
	}
};

int minimumMoves(vector <string> grid, int startX, int startY, int goalX, int goalY) {
    queue<node> positions;

    positions.push(node((long)startX, (long)startY, 0));
    node position(0, 0, 0);
    
    while (!positions.empty()) {
        position = positions.front();
        positions.pop();
        
        int i = 0;
        
        //Go Left as far as we can
        for (i = position.x; i < grid.size(); i++) {
            if (grid[position.y][i] == 'X') {
                break;
            }
        } i--;
        
        if (i == goalX && position.y == goalY) {
            break;
        }
        
        if (i != position.x) {
            positions.push(node(i, position.y, position.c + 1));
        }
        
        //Go Right as far as we can
        for (i = position.x; i >= 0; i--) {
            if (grid[position.y][i] == 'X') {
                break;
            }
        } i++;
        
        if (i == goalX && position.y == goalY) {
            break;
        }
        
        if (i != position.x) {
            positions.push(node(i, position.y, position.c + 1));
        }
        
        //Go Bottom as far as we can
        for (i = position.y; i < grid.size(); i++) {
            if (grid[i][position.x] == 'X') {
                break;
            }
        } i--;
        
        if (i != position.y) {
            positions.push(node(position.x, i, position.c + 1));
        }
        
        if (i == goalY && position.x == goalX) {
            break;
        }
        
        //Go Top as far as we can
        for (i = position.y; i >= 0; i--) {
            if (grid[i][position.x] == 'X') {
                break;
            }
        } i++;
        
        if (i == goalY && position.x == goalX) {
            break;
        }
        
        if (i != position.y) {
            positions.push(node(position.x, i, position.c + 1));
        }
    }
    
    return position.c + 1;
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startY, startX, goalY, goalX);
    cout << result << endl;
    return 0;
}
