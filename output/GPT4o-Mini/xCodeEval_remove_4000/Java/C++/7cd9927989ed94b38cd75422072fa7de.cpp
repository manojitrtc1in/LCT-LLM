#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Pair {
public:
    int val;
    int dist;
    Pair(int v, int d) : val(v), dist(d) {}
};

void bfs(vector<vector<int>>& arr, vector<int>& visited, int start, unordered_map<int, int>& map) {
    queue<Pair> q;
    q.push(Pair(start, 0));
    map[start] = 0;
    visited[start] = 1;

    while (!q.empty()) {
        Pair ob = q.front();
        q.pop();

        for (int curr : arr[ob.val]) {
            if (visited[curr] == 0) {
                visited[curr] = 1;
                q.push(Pair(curr, ob.dist + 1));
                map[curr] = ob.dist + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rarr(n + 1), arr(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        rarr[b].push_back(a);
    }

    int h;
    cin >> h;
    vector<int> path(h);
    for (int i = 0; i < h; i++) {
        cin >> path[i];
    }

    unordered_map<int, int> map;
    vector<int> visited(n + 1, 0);
    bfs(rarr, visited, path[h - 1], map);

    int min = 0;
    int max = 0;

    for (int i = 0; i < h - 1; i++) {
        int count = 0;
        if (map[path[i]] == map[path[i + 1]] + 1) {
            for (int curr : arr[path[i]]) {
                if (map[curr] == map[path[i]] - 1) {
                    count++;
                }
            }

            if (count > 1) {
                max++;
            }
        } else {
            min++;
            max++;
        }
    }

    cout << min << " " << max << endl;

    return 0;
}
