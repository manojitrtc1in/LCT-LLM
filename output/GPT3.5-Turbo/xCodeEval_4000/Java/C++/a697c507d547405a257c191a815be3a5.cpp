#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <ctime>
#include <list>
#include <fstream>
#include <functional>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define per(i, n) for(int i = (n)-1; i >= 0; --i)
#define per1(i, n) for(int i = (n); i >= 1; --i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for(int i = (a); i >= (b); --i)
#define FORSZ(i, x) for(int i = 0; i < sz(x); ++i)
#define ROFSZ(i, x) for(int i = sz(x)-1; i >= 0; --i)
#define dbg(x) cerr << #x" = " << x << endl
#define dbgv(x) cerr << #x" = "; for(auto _x : x) cerr << _x << ' '; cerr << endl
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> bool chkmax(T& a, const T& b) { return a < b ? a = b, true : false; }
template<typename T> bool chkmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<typename T> T read() {
    T x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

template<typename T> void write(T x) {
    if(x < 0) { putchar('-'); x = -x; }
    if(x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

template<typename T> void write(T x, char c) { write(x); putchar(c); }

const int MAX_T = 1000000000;
const int MODULO = 1000000007;

struct SegmentTree {
    int size;
    vector<long long> sums;
    vector<long long> mins;

    SegmentTree(int n) {
        size = n;

        int treeSize = size << 2;
        sums.resize(treeSize);
        mins.resize(treeSize);
    }

    int index;
    long long value;

    void updateIndex(int index, long long value) {
        this->index = index;
        this->value = value;
        updateTreeIndex(1, 0, size);
    }

    void updateTreeIndex(int v, int left, int right) {
        if (left + 1 == right) {
            sums[v] = value;
            mins[v] = min(0LL, value);
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (index < mid) updateTreeIndex(vLeft, left, mid);
            else updateTreeIndex(vRight, mid, right);

            updateVertex(v, vLeft, vRight);
        }
    }

    void updateVertex(int v, int vLeft, int vRight) {
        sums[v] = sums[vLeft] + sums[vRight];
        mins[v] = min(mins[vLeft], sums[vLeft] + mins[vRight]);
    }

    bool found;
    int foundIndex;

    int start, end;
    int getInterval(int start, int end, long long value) {
        this->start = start;
        this->end = end;
        this->value = value;

        this->found = false;
        this->foundIndex = -1;

        getTreeInterval(1, 0, size);

        return foundIndex;
    }

    void getTreeInterval(int v, int left, int right) {
        if (start <= left && right <= end) {
            if (!found) {
                if (value + mins[v] <= 0) {
                    findTreeIndex(v, left, right);
                    found = true;
                } else {
                    value += sums[v];
                }
            }
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (start < mid) getTreeInterval(vLeft, left, mid);
            if (mid < end) getTreeInterval(vRight, mid, right);
        }
    }

    void findTreeIndex(int v, int left, int right) {
        if (left + 1 == right) {
            foundIndex = left;
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (value + mins[vLeft] <= 0) {
                findTreeIndex(vLeft, left, mid);
            } else {
                value += sums[vLeft];
                findTreeIndex(vRight, mid, right);
            }
        }
    }
};

struct IdMap : unordered_map<int, int> {
    int registerKey(int key) {
        int id = size();
        (*this)[key] = id;
        return id;
    }

    int getId(int key) {
        return (*this)[key];
    }
};

struct SortedIdMapper {
    vector<int> values;

    void addValue(int value) {
        values.push_back(value);
    }

    IdMap build() {
        sort(values.begin(), values.end());

        IdMap ids;
        vector<int> uniqueValues;

        for (int index = 0; index < values.size(); ++index) {
            int value = values[index];
            if (index == 0 || values[index - 1] != value) {
                ids.registerKey(value);
                uniqueValues.push_back(value);
            }
        }

        values = uniqueValues;

        return ids;
    }
};

void solve() {
    const int MAX_T = 1000000000;

    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            queries[i] = {1, a, b};
        } else if (type == 2) {
            int a;
            cin >> a;
            queries[i] = {2, a};
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            queries[i] = {3, a, b, c};
        }
    }

    SortedIdMapper mapper;
    mapper.addValue(0);
    mapper.addValue(MAX_T + 1);

    for (auto& query : queries) {
        mapper.addValue(query[1]);
        if (query[0] == 3) {
            mapper.addValue(query[2]);
        }
    }

    IdMap ids = mapper.build();
    vector<int> times = mapper.values;

    int minTime = ids.getId(0), maxTime = ids.getId(MAX_T + 1);

    map<int, int> timeSpeeds;

    timeSpeeds[minTime] = 0;
    timeSpeeds[maxTime] = 0;

    for (auto& query : queries) {
        query[1] = ids.getId(query[1]);
        if (query[0] == 3) query[2] = ids.getId(query[2]);
    }

    SegmentTree tree(ids.size());

    for (auto& query : queries) {
        int type = query[0];
        if (1 == type) {
            int time = query[1];
            int realTime = times[time];
            long long speed = query[2];

            auto itBefore = timeSpeeds.lower_bound(time);
            --itBefore;

            int timeAfter = timeSpeeds.upper_bound(time)->first;
            int realTimeAfter = times[timeAfter];

            int timeBefore = itBefore->first;
            int realTimeBefore = times[timeBefore];
            long long speedBefore = itBefore->second;

            tree.updateIndex(timeBefore, speedBefore * (realTime - realTimeBefore));
            tree.updateIndex(time, speed * (realTimeAfter - realTime));

            timeSpeeds[time] = speed;
        } else if (type == 2) {
            int time = query[1];
            int realTime = times[time];

            auto itBefore = timeSpeeds.lower_bound(time);
            --itBefore;

            int timeAfter = timeSpeeds.upper_bound(time)->first;
            int realTimeAfter = times[timeAfter];

            int timeBefore = itBefore->first;
            int realTimeBefore = times[timeBefore];

            long long speedBefore = itBefore->second;

            tree.updateIndex(timeBefore, speedBefore * (realTimeAfter - realTimeBefore));
            tree.updateIndex(time, 0);

            timeSpeeds.erase(time);
        } else {
            int start = query[1], end = query[2];
            long long value = query[3];

            if (value == 0) {
                cout << times[start] << "\n";
                continue;
            }

            int foundIndex = tree.getInterval(start, end, value);
            if (foundIndex == -1) {
                cout << -1 << "\n";
            } else {
                value = tree.value;

                int time = foundIndex;
                int realTime = times[time];

                if (value == 0) {
                    cout << realTime << "\n";
                } else {
                    long long speed = timeSpeeds.count(time) ? timeSpeeds[time] : -1;

                    int timeAfter = min(end, timeSpeeds.upper_bound(time)->first);
                    int realTimeAfter = times[timeAfter];

                    long long delta = realTimeAfter - realTime;
                    long long total = delta * speed;

                    if (value + total > 0) {
                        cout << -1 << "\n";
                    } else {
                        double badTime = realTime + (double)value / abs(speed);
                        cout << fixed << setprecision(10) << badTime << "\n";
                    }
                }
            }
        }
    }
}

int main() {
    FASTIO;

    int t = 1;
    if (false) cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
