#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<pair<int, int>> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());
    auto check = [&](int x) {
        int now = x;
        int c = accumulate(l.begin(), l.end(), 0);
        int cur = 0;
        int last = 0;
        unordered_map<int, int> ld;
        for (int i = 0; i < m; i++) {
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
        if (now >= 2 * c) {
            return true;
        }
        return false;
    };
    int st = 1;
    int end = 2 * accumulate(l.begin(), l.end(), 0);
    int ans = end;
    while (st <= end) {
        int mid = st + (end - st) / 2;
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
