#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

class InVoker {
public:
    void main() {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        input(a, n);
        sort(a.begin(), a.end());
        for (int i = 0; i < n / 2; i++) {
            swap(a[i], a[n - 1 - i]);
        }
        priority_queue<long long> pq;
        while (k-- >= 0) {
            pq.push(0LL);
        }
        long long gg = 0;
        for (int i = 0; i < n; i++) {
            long long cur = pq.top();
            pq.pop();
            gg += cur;
            cur += a[i];
            pq.push(cur);
        }
        cout << gg << endl;
    }

    void input(vector<long long>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(vector<int>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(vector<string>& s, int n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    void input(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void input(vector<vector<long long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }
};

int main() {
    InVoker g;
    g.main();
    return 0;
}
