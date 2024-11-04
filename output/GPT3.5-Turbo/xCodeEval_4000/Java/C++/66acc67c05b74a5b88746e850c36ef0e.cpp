#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pair {
    int idx, val;
    Pair(int idx, int val) {
        this->idx = idx;
        this->val = val;
    }
    bool operator<(const Pair& other) const {
        return val < other.val;
    }
};

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
    long long ans = 0;
    if ((long long)a < 2 * (long long)x) {
        ans += 2 * (long long)x - a;
        a = 0;
    }
    else {
        a = a - 2 * x;
    }
    if ((long long)b < 3 * (long long)z) {
        ans += 3 * (long long)z - b;
        b = 0;
    }
    else {
        b = b - 3 * z;
    }
    if (a < b) {
        y = y - a > 0 ? y - a : 0;
        b = b - a;
        a = 0;
    }
    else {
        y = y - b > 0 ? y - b : 0;
        b = a - b;
        a = 0;
    }
    if (y > b) {
        ans += b + 2 * (y - b);
    }
    else {
        ans += y;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    long long ans = 0;
    if ((long long)a < 2 * (long long)x) {
        ans += 2 * (long long)x - a;
        a = 0;
    }
    else {
        a = a - 2 * x;
    }
    if ((long long)b < 3 * (long long)z) {
        ans += 3 * (long long)z - b;
        b = 0;
    }
    else {
        b = b - 3 * z;
    }
    if (a < b) {
        y = y - a > 0 ? y - a : 0;
        b = b - a;
        a = 0;
    }
    else {
        y = y - b > 0 ? y - b : 0;
        b = a - b;
        a = 0;
    }
    if (y > b) {
        ans += b + 2 * (y - b);
    }
    else {
        ans += y;
    }
    cout << ans << endl;
    return 0;
}
