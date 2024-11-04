#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define int long long

int n, m;
vector<int> l;
vector<pair<int, int>> t;

bool check(int x) {
    int now = x;
    int c = accumulate(l.begin(), l.end(), 0LL);
    int cur = 0;
    int last = 0;
    unordered_map<int, int> ld;

    for (int i = 0; i < t.size(); i++) {
        if (t[i].first <= x) {
            ld[t[i].second] = i;
        }
    }

    for (int i = 0; i < m; i++) {
        if (ld[t[i].second] != i) {
            continue;
        }
        if (t[i].first > x) {
            break;
        }
        cur += t[i].first - last;
        int rt = min(cur, l[t[i].second - 1]);
        cur -= rt;
        now -= rt;
        c -= rt;
        last = t[i].first;
    }
    
    return now >= 2 * c;
}

int32_t main() {
    cin >> n >> m;
    l.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    t.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());

    int st = 1;
    int end = 2 * accumulate(l.begin(), l.end(), 0LL);
    int ans = end;

    while (st <= end) {
        int mid = (st + end) / 2;
        if (check(mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
