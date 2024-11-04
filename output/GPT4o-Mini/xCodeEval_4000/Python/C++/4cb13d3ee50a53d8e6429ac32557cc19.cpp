#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <functional>
#include <numeric>
#include <limits>
#include <ctime>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    int ans = 3;
    if (a % m == 1) {
        ans--;
    }
    if (b % m == 0 || b == n) {
        ans--;
    }
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    } else if ((a - 1) / m == (b - 1) / m) {
        cout << 1 << endl;
        return 0;
    } else if ((a % m - b % m) % m == 1) {
        cout << min(2, ans, (b - 1) / m - (a - 1) / m + 1) << endl;
        return 0;
    }
    cout << min(ans, (b - 1) / m - (a - 1) / m + 1) << endl;

    return 0;
}
