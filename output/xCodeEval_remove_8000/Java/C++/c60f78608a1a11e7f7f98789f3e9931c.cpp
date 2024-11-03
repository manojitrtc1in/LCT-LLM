#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int SIZE = 20;
const int SET[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
const int COUNT[1 << SIZE] = {0};
const int INTEGER[1 << SIZE] = {0};

int count(int set) {
    int result = 0;
    for (int integer = 0; integer < SIZE; integer++) {
        if (0 < (set & SET[integer])) {
            result += 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    set<int> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        xs.insert(points[i].first);
        ys.insert(points[i].second);
    }
    int ans = xs.size() + ys.size();
    cout << ans << endl;

    return 0;
}
