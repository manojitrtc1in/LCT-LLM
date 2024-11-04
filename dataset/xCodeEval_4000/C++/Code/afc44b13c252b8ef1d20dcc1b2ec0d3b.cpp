#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, p, q1, f[100005], vis[100005], cnt;
long long len[100005];
int Find(int x) {
    return f[x] == x? x : f[x] = Find(f[x]);
}


int main() {
    cin >> n >> m >> p >> q1;

    int a, b, l;
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        f[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        a--, b--;
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) {
            len[fb] += len[fa];
            f[fa] = fb;
        }
        len[fb] += l;
    }

    priority_queue<pair<long long, int> > q;
    for (int i = 0; i < n; i++) {
        if (!vis[Find(i)]) {
            vis[f[i]] = 1;
            q.push(make_pair(-len[f[i]], f[i]));
            cnt++;
        }
    }

    

    for (int i = cnt; i > q1; i--) {
        if (q.size() < 2) {
            cout << "NO" << endl;
            exit(0);
        }
        pair<int, int> p1, p2;
        p1 = q.top(), q.pop();
        p2 = q.top(), q.pop();
        ans.push_back(make_pair(p1.second + 1, p2.second + 1));
        int fa = Find(p1.second), fb = Find(p2.second);
        int length = min((long long)1000000000, len[fa] + len[fb] + 1);
        len[fb] += len[fa] + length;
        f[fa] = fb;
        p--;
        cnt--;
        q.push(make_pair(-len[fb], fb));
    }

    int found = -1;
    map<int, int> tmp;

    for (int i = 0; i < n; i++) {
        if (++tmp[Find(i)] > 1) {
            found = Find(i);
        }
    }

    if (found < 0 && p || p < 0 || cnt < q1) {
        cout << "NO" << endl;
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        if (Find(i) == found && i != found) {
            a = i + 1;
            b = found + 1;
            break;
        }
    }

    for (int i = 0; i < p; i++) {
        ans.push_back(make_pair(a, b));
    }

    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}






















































































