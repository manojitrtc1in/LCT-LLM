#include <iostream>
#include <deque>
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dq.push_back(num);
    }
    int a = dq.front();
    dq.pop_front();
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;
    while (!dq.empty()) {
        now = 0;
        while (now <= pre && !dq.empty()) {
            now += dq.back();
            dq.pop_back();
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }
        
        if (dq.empty()) {
            break;
        }
        
        now = 0;
        while (now <= pre && !dq.empty()) {
            now += dq.front();
            dq.pop_front();
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }
    cout << cnt << " " << a << " " << b << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
