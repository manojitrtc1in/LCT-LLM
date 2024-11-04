#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

class Pair {
public:
    int idx, val;
    Pair(int idx, int val) : idx(idx), val(val) {}
    bool operator<(const Pair& other) const {
        return val < other.val;
    }
};

long gcd(long x, long y) {
    return (x % y == 0) ? y : gcd(y, x % y);
}

void dfs(int start, int root, vector<bool>& visited, vector<int>& par, vector<vector<int>>& adj) {
    visited[start] = true;
    par[start] = root;
    for (int i : adj[start]) {
        if (!visited[i]) {
            dfs(i, start, visited, par, adj);
        }
    }
}

void soln() {
    int a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    long ans = 0;
    
    if ((long)a < 2 * (long)x) {
        ans += 2 * (long)x - a;
        a = 0;
    } else {
        a -= 2 * x;
    }
    
    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    } else {
        b -= 3 * z;
    }
    
    if (a < b) {
        y = max(y - a, 0);
        b -= a;
        a = 0;
    } else {
        y = max(y - b, 0);
        b = a - b;
        a = 0;
    }
    
    if (y > b) {
        ans += b + 2 * (y - b);
    } else {
        ans += y;
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    soln();
    
    return 0;
}
