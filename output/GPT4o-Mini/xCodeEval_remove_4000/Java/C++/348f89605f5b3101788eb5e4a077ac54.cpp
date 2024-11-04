#include <bits/stdc++.h>
using namespace std;

const long mod = 1000000007;
const long mod2 = 998244353;

class id0 {
public:
    void main() {
        int n, k;
        cin >> n >> k;
        vector<long> a(n);
        input(a, n);
        sort(a.begin(), a.end());
        for (int i = 0; i < n / 2; i++) {
            swap(a[i], a[n - 1 - i]);
        }
        priority_queue<long> pq;
        while (k-- >= 0) {
            pq.push(0);
        }
        long gg = 0;
        for (int i = 0; i < n; i++) {
            long cur = pq.top();
            pq.pop();
            gg += cur;
            cur += a[i];
            pq.push(cur);
        }
        cout << gg << endl;
    }

    void input(vector<long>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    id0 g;
    g.main();
    return 0;
}
