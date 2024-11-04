#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <string>
#include <ctime>
#include <bitset>
#include <queue>
#include <cassert>
#include<unordered_set>
#include<unordered_map>
#include<string.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pll pair<ll, ll>


template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T& o : v) {
        is >> o;
    }
    return is;
}
class Query {
public:
    int l = 0;
    int r = 0;
    int idx = 0;
    Query(int L, int R, int Num) {
        l = L;
        r = R;
        idx = Num;
    }
};
int NOD(int a, int b) {
    return b ? NOD(b, a % b) : a;
}
const ll INF = 1e17 + 7;
const ll MOD1 = 2 * 1e9;
const ll NMAX = 1e6;
const ll POWER = 71;
const ll HASHMOD1 = 939999971;
const ll HASHMOD2 = 998244353;
const ll MOD2 = 939999971;
vector<int> dX = { 1, 0, -1, 0, };
vector<int> dY = { 0, 1, 0, -1 };







 




 



struct SegmentTree {
    vector<pair<int, int>> seg_tree;
    vector<int> seg_tree_add;
    void build(int v, int l, int r, vector<int>& a) {
        if (l == r) {
            seg_tree[v].first = a[l];
            seg_tree[v].second = l;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a); build(2 * v + 1, mid + 1, r, a);
        seg_tree[v] = min(seg_tree[2 * v], seg_tree[2 * v + 1]);
    }
    void push(int v) {
        if (seg_tree_add[v] != 0) {
            seg_tree_add[2 * v] = seg_tree_add[v];
            seg_tree_add[2 * v + 1] = seg_tree_add[v];
            seg_tree_add[v] = 0;
            return;
        }
    }
    pair<int, int> get(int v, int l, int r) {
        if (seg_tree_add[v] != 0) return { seg_tree_add[v], seg_tree[v].second };
        else return seg_tree[v];
    }
    void update(int v, int l, int r, int L, int R, int value) {
        if (l > R || L > r) return;
        if (l >= L && R >= r) {
            seg_tree_add[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        push(v);
        update(2 * v, l, mid, L, R, value); update(2 * v + 1, mid + 1, r, L, R, value);
        auto p1 = get(2 * v, l, mid); auto p2 = get(2 * v + 1, mid + 1, r);
        seg_tree[v] = min(p1, p2);
    }
    pair<int, int> getMax(int v, int l, int r, int L, int R) {
        if (l > R || L > r) return { INF, -1 };
        if (l >= L && R >= r) {
            return get(v, l, r);
        }
        int mid = (l + r) / 2;
        push(v);
        auto p11 = get(2 * v, l, mid); auto p12 =  get(2 * v + 1, mid + 1, r);
        seg_tree[v] = min(p11, p12);
        auto p1 = getMax(2 * v, l, mid, L, R); auto p2 = getMax(2 * v + 1, mid + 1, r, L, R);
        return min(p1, p2);
    }
public:
    int N;
    SegmentTree(vector<int>& a) {
        N = a.size();
        seg_tree.assign(4 * N + 4, { 0, 0 });
        seg_tree_add.assign(4 * N + 4, 0);
        build(1, 0, N - 1, a);
    }
    pair<int, int> getMax(int L, int R) {
        

        return getMax(1, 0, N - 1, L, R);
    }
    void updateSeg(int L, int R, int value) {
        update(1, 0, N - 1, L, R, value);
    }
};


vector<int> input;
void solve()
{
    setlocale(LC_ALL, "Russian");
    int N = 0; cin >> N; input.assign(N, 0); for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    SegmentTree ST = SegmentTree(input);
    int Q = 0; cin >> Q;
    while (Q--) {
        int l = 0, r = 0; cin >> l >> r; l--; r--;
        if (r - l + 1 <= 32) {
            int ans = INF;
            for (int i = l; i <= r; ++i) {
                for (int j = i + 1; j <= r; ++j) {
                    ans = min(ans, input[i] | input[j]);
                }
            }
            cout << ans << "\n";
        }
        else {
            vector<int> nums;
            vector<int> pos;
            for (int i = 0; i < 31; ++i) {
                auto p1 = ST.getMax(l, r);
                nums.push_back(p1.first);
                pos.push_back(p1.second);
                ST.updateSeg(p1.second, p1.second, INF);
            }
            int ans = INF;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    ans = min(ans, nums[i] | nums[j]);
                }
            }
            cout << ans << endl;
            for (auto x : pos) {
                

                ST.updateSeg(x, x, input[x]);
            }
            nums.clear(); pos.clear();
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int T = 0; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

