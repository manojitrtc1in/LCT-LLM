#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countGreater(vector<int>& arr, int n, int k) {
    int l = 0;
    int r = n - 1;

    int leftGreater = n;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= k) {
            leftGreater = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return (n - leftGreater);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        l[i] %= k;
    }

    if (n == 1) {
        cout << l[0] << endl;
        return 0;
    }

    vector<int> l1(l.begin(), l.begin() + n / 2);
    vector<int> l2(l.begin() + n / 2, l.end());
    set<int> s;
    set<int> s1;
    set<int> s2;

    for (int i = 0; i < n / 2; i++) {
        for (auto j : s) {
            s2.insert((j + l1[i]) % k);
        }
        s.insert(l1[i]);
        for (auto j : s2) {
            s.insert(j);
        }
        s2.clear();
    }

    for (int i = 0; i < n - n / 2; i++) {
        for (auto j : s1) {
            s2.insert((j + l2[i]) % k);
        }
        s1.insert(l2[i]);
        for (auto j : s2) {
            s1.insert(j);
        }
        s2.clear();
    }

    vector<int> sVec(s.begin(), s.end());
    vector<int> s1Vec(s1.begin(), s1.end());
    sort(sVec.begin(), sVec.end());
    sort(s1Vec.begin(), s1Vec.end());

    int ans = max(max(sVec.back(), s1Vec.back()), 0);

    for (int i = 0; i < sVec.size(); i++) {
        int t = k - 1 - sVec[i];
        int ind = countGreater(s1Vec, s1Vec.size(), t);
        int r = s1Vec[ind - 1];
        int rt = s1Vec.back();
        int temp = ans;
        ans = max((r + sVec[i]) % k, (sVec[i] + rt) % k);
        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}
