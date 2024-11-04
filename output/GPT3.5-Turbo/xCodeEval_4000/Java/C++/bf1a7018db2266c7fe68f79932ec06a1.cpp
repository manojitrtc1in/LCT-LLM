#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

class FastReader {
public:
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int nextInt() {
        int num = 0;
        char c;
        while ((c = getchar()) != '\n' && c != ' ') {
            num = num * 10 + (c - '0');
        }
        return num;
    }

    long long nextLong() {
        long long num = 0;
        char c;
        while ((c = getchar()) != '\n' && c != ' ') {
            num = num * 10 + (c - '0');
        }
        return num;
    }

    string next() {
        string str;
        char c;
        while ((c = getchar()) != '\n' && c != ' ') {
            str.push_back(c);
        }
        return str;
    }

    string nextLine() {
        string str;
        char c;
        while ((c = getchar()) != '\n') {
            str.push_back(c);
        }
        return str;
    }
};

class Main {
public:
    Main() {
        FastReader in;

        int nt = in.nextInt();

        for (int it = 0; it < nt; it++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int s = in.nextInt();
            int t = in.nextInt();
            vector<int> sz(n + 1);
            vector<vector<int>> nbs(n + 1);
            vector<vector<int>> es(m, vector<int>(2));
            for (int i = 0; i < m; i++) {
                es[i][0] = in.nextInt();
                es[i][1] = in.nextInt();
                sz[es[i][0]]++;
                sz[es[i][1]]++;
            }
            for (int i = 1; i <= n; i++) {
                nbs[i].resize(sz[i]);
                sz[i] = 0;
            }

            for (auto& e : es) {
                int p = e[0], q = e[1];
                nbs[p][sz[p]++] = q;
                nbs[q][sz[q]++] = p;
            }
            vector<int> subTreeSize(n + 1);
            vector<bool> visited(n + 1);
            long long l = dfs(s, 0, s, t, nbs, subTreeSize, visited);
            for (int i = 1; i <= n; i++) {
                subTreeSize[i] = 0;
                visited[i] = false;
            }
            long long r = dfs(t, 0, t, s, nbs, subTreeSize, visited);
            long long tot = (n - 1 - l) * (n - 1 - r);
            cout << tot << "\n";
        }
    }

    long long dfs(int root, int par, int chosenRoot, int special, vector<vector<int>>& nbs, vector<int>& size, vector<bool>& visited) {
        int sz = 1;
        visited[root] = true;
        if (nbs[root].size() == 1 && par > 0) {
            size[root] = 1;
            if (root == special) return 1;
            return 0;
        }

        int ans = root == special ? 1 : 0;
        for (int next : nbs[root]) {
            if (next != par && !visited[next]) {
                long long sub = dfs(next, root, chosenRoot, special, nbs, size, visited);
                if (root == chosenRoot) {
                    if (sub > 0) return sub;
                }
                else {
                    ans += sub;
                }
                sz += size[next];
            }
        }
        size[root] = sz;
        if (ans == 0) return 0;

        return sz;
    }
};

int main() {
    Main obj;
    return 0;
}
