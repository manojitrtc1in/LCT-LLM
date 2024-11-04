#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearchCount(vector<int>& arr, int n, int key) {
    int left = 0;
    int right = n - 1;

    int count = 0;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return count;
}

int countGreater(vector<int>& arr, int n, int k) {
    int l = 0;
    int r = n - 1;

    int leftGreater = n;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= k) {
            leftGreater = m;
            r = m - 1;
        }
        else {
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
    vector<int> s_vec(s.begin(), s.end());
    vector<int> s1_vec(s1.begin(), s1.end());
    sort(s_vec.begin(), s_vec.end());
    sort(s1_vec.begin(), s1_vec.end());
    int ans = max(max(s_vec.back(), s1_vec.back()), 0);
    for (int i = 0; i < s_vec.size(); i++) {
        int t = k - 1 - s_vec[i];
        int ind = binarySearchCount(s1_vec, s1_vec.size(), t);
        int r = s1_vec[ind - 1];
        int rt = s1_vec.back();
        int temp = ans;
        ans = max((r + s_vec[i]) % k, (s_vec[i] + rt) % k);
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
