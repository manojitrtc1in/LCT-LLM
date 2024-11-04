#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream>

using namespace std;

class F {
    int n;
    int m;
    vector<int> arr;
    int required;
    map<int, multiset<int>> typeDays;

public:
    void solver() {
        cin >> n >> m;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        required = accumulate(arr.begin(), arr.end(), 0);
        
        for (int i = 0; i < m; i++) {
            int d, typ;
            cin >> d >> typ;
            if (arr[typ - 1] <= 0) continue;
            typeDays[typ].insert(d);
        }

        int lo = required;
        int hi = 2 * required;
        int valid = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isEnough(mid)) {
                valid = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << valid << endl;
    }

private:
    bool isEnough(int day) {
        int totalCoin = day;
        int req = required;

        vector<int> ddays(day + 1, 0);
        for (const auto& [typ, days] : typeDays) {
            auto it = days.lower_bound(day);
            if (it != days.begin()) {
                --it;
                ddays[*it] += arr[typ - 1];
            }
        }

        int removed = 0;
        for (int i = 1; i <= day; i++) {
            int coins = i - removed;
            int toRemove = min(coins, ddays[i]);
            removed += toRemove;
            totalCoin -= toRemove;
            req -= toRemove;
        }

        return req * 2 <= totalCoin;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    F().solver();
    return 0;
}
