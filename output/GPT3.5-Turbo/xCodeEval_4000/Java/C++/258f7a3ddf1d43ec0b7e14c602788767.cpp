#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cassert>
#include <climits>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n;
int m;
vector<int> arr;
int required;
unordered_map<int, set<int>> typeDays;

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
        if (typeDays.find(typ) == typeDays.end()) {
            typeDays[typ] = set<int>();
        }
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

bool isEnough(int day) {
    int totalCoin = day;
    int req = required;

    vector<int> ddays(day + 1);
    for (auto& kv : typeDays) {
        int typ = kv.first;
        auto& days = kv.second;
        auto lastDay = days.lower_bound(day);
        if (lastDay == days.end()) continue;
        ddays[*lastDay] += arr[typ - 1];
    }

    int removed = 0;
    for (int i = 1; i < day + 1; i++) {
        int coins = i - removed;
        int toRemove = min(coins, ddays[i]);
        removed += toRemove;
        totalCoin -= toRemove;
        req -= toRemove;
    }

    return req * 2 <= totalCoin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solver();
    return 0;
}
