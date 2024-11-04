#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int binarySearchCount(const vector<int>& arr, int n, int key) {
    int left = 0, right = n - 1;
    int count = 0;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
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
    set<int> s, s1, s2;

    for (int i = 0; i < n / 2; i++) {
        for (const auto& j : s) {
            s2.insert((j + l1[i]) % k);
        }
        s.insert(l1[i]);
        for (const auto& j : s2) {
            s.insert(j);
        }
        s2.clear();
    }

    for (int i = 0; i < n - n / 2; i++) {
        for (const auto& j : s1) {
            s2.insert((j + l2[i]) % k);
        }
        s1.insert(l2[i]);
        for (const auto& j : s2) {
            s1.insert(j);
        }
        s2.clear();
    }

    vector<int> sVec(s.begin(), s.end());
    vector<int> s1Vec(s1.begin(), s1.end());
    sort(sVec.begin(), sVec.end());
    sort(s1Vec.begin(), s1Vec.end());

    int ans = max(*max_element(sVec.begin(), sVec.end()), *max_element(s1Vec.begin(), s1Vec.end()));

    for (int i = 0; i < sVec.size(); i++) {
        int t = k - 1 - sVec[i];
        int ind = binarySearchCount(s1Vec, s1Vec.size(), t);
        int r = s1Vec[ind - 1];
        int rt = s1Vec.back();
        ans = max({(r + sVec[i]) % k, (sVec[i] + rt) % k, ans});
    }

    cout << ans << endl;
    return 0;
}
