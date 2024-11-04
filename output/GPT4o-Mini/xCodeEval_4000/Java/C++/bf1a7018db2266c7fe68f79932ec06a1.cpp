#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class Main {
public:
    Main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int nt;
        cin >> nt;
        StringBuilder sb;

        for (int it = 0; it < nt; it++) {
            int n, m, s, t;
            cin >> n >> m >> s >> t;
            vector<int> sz(n + 1, 0);
            vector<vector<int>> nbs(n + 1);
            vector<pair<int, int>> es(m);
            for (int i = 0; i < m; i++) {
                cin >> es[i].first >> es[i].second;
                sz[es[i].first]++;
                sz[es[i].second]++;
            }
            for (int i = 1; i <= n; i++) {
                nbs[i].resize(sz[i]);
                sz[i] = 0;
            }

            for (auto& e : es) {
                int p = e.first, q = e.second;
                nbs[p][sz[p]++] = q;
                nbs[q][sz[q]++] = p;
            }
            vector<int> subTreeSize(n + 1, 0);
            vector<bool> visited(n + 1, false);
            long l = dfs(s, 0, s, t, nbs, subTreeSize, visited);
            fill(subTreeSize.begin(), subTreeSize.end(), 0);
            fill(visited.begin(), visited.end(), false);
            long r = dfs(t, 0, t, s, nbs, subTreeSize, visited);
            long tot = (n - 1 - l) * (n - 1 - r);
            sb.append(to_string(tot) + "\n");
        }
        cout << sb;
    }

private:
    long dfs(int root, int par, int chosenRoot, int special, vector<vector<int>>& nbs, vector<int>& size, vector<bool>& visited) {
        int sz = 1;
        visited[root] = true;
        if (nbs[root].size() == 1 && par > 0) {
            size[root] = 1;
            return root == special ? 1 : 0;
        }

        int ans = root == special ? 1 : 0;
        for (int next : nbs[root]) {
            if (next != par && !visited[next]) {
                long sub = dfs(next, root, chosenRoot, special, nbs, size, visited);
                if (root == chosenRoot) {
                    if (sub > 0) return sub;
                } else {
                    ans += sub;
                }
                sz += size[next];
            }
        }
        size[root] = sz;
        return ans == 0 ? 0 : sz;
    }

    class StringBuilder {
    public:
        void append(const string& str) {
            buffer += str;
        }

        friend ostream& operator<<(ostream& os, const StringBuilder& sb) {
            os << sb.buffer;
            return os;
        }

    private:
        string buffer;
    };
};

int main() {
    new Main();
    return 0;
}
