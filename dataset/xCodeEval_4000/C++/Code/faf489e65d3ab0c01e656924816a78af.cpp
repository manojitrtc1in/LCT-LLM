#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int LIM = 256;
const int INF = 1e9 + 239;
const int MAX_STEP = 5;
const int BASE = 256;
const int CNT_VALID_PAIRS = 11;
const char CHANGE_LINE = '#';

string fast_to_string[LIM];
pair<int, int> valid_pairs[CNT_VALID_PAIRS];

namespace State {
    int steps;
    int val[MAX_STEP + 1];
    string go[MAX_STEP + 1];
    int pnt = -1;
    
    void init() {
        val[0] = 1;
        go[0] = "MAVZES_BEST";
        pnt = 1;
    }
    
    void add(int val_, string tmp) {
        steps++;
        val[pnt] = val_;
        go[pnt] = tmp;
        pnt++;
    }
    
    void pop() {
        steps--;
        pnt--;
    }
};


int best = INF;
vector<string>ans [LIM];

unordered_set<ull> seen[MAX_STEP + 3];

void dfs(ull cur_hash) {
    assert(State::steps < MAX_STEP + 3);
    seen[State::steps].insert(cur_hash);
    for (int i = 0; i < State::pnt; i++) {
        if (ans[State::val[i]].size() > State::steps) {
            ans[State::val[i]].clear();
            for (int j = 0; j < State::pnt; j++) {
                ans[State::val[i]].push_back(State::go[j]);
            }
        }
    }
    if (State::steps + 1 > MAX_STEP) {
        return;
}
    string cx;
    cx.push_back(State::steps + 1 + 'a');
    for (int y = 0; y <= State::steps; y++) {
        string cy;
        cy.push_back(y + 'a');
        for (int z = 0; z <= State::steps; z++) {
            string cz;
            cz.push_back(z + 'a');
            for (int i = 0; i < CNT_VALID_PAIRS; i++) {
                int a = valid_pairs[i].first;
                int b = valid_pairs[i].second;
                int nval = a * State::val[y] + b * State::val[z];
                if (nval >= LIM) {
                    break;
                }
                ull new_hash = (cur_hash * BASE) + nval;
                if (seen[State::steps + 1].count(new_hash)) {
                    continue;
                }
                string ca = fast_to_string[a];
                string cb = fast_to_string[b];
                if (b == 0) {
                    State::add(nval, "lea e" + cx + "x, ["  + ca + "*e" + cy + "x]");
                } else if (a == 0) {
                    State::add(nval, "lea e" + cx + "x, [" + cb + "*e" + cz + "x]");
                } else if (a == 1) {
                    State::add(nval, "lea e" + cx + "x, [e" + cy + "x + " + cb + "*e" + cz + "x]");
                } else if (b == 1) {
                    State::add(nval, "lea e" + cx + "x, [e" + cz + "x + " + ca + "*e" + cy + "x]");
                } else {
                    continue;
                }
                dfs(new_hash);
                State::pop();
            }
        }
    }
}

string rans[LIM];

void solve() {
    State::init();
    ull h = 1;
    dfs(h);
    for (int i = 0; i < LIM; i++) {
        string cur;
        string uu = to_string((int)ans[i].size() - 1);
        for (auto y : uu) {
            cur.push_back(y);
        }
        cur.push_back('\n');
        for (int j = 1; j < (int)ans[i].size(); j++) {
            for (auto c : ans[i][j]) {
                cur.push_back(c);
            }
            cur.push_back('\n');
        }
        rans[i] = cur;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    
    vector<string> uu = {
        "6#######",
        "0#",
        "1#lea ebx, [eax + 1*eax]#",
        "1#lea ebx, [eax + 2*eax]#",
        "1#lea ebx, [4*eax]#",
        "1#lea ebx, [eax + 4*eax]#",
        "2#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#",
        "2#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 2*eax]#",
        "1#lea ebx, [8*eax]#",
        "1#lea ebx, [eax + 8*eax]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*eax]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 2*eax]#",
        "2#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 2*ebx]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 8*eax]#",
        "2#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [2*ebx]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [eax + 2*ebx]#",
        "2#lea ebx, [4*eax]#lea ecx, [ebx + 4*ebx]#",
        "2#lea ebx, [eax + 4*eax]#lea ecx, [eax + 4*ebx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [eax + 2*ecx]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#",
        "2#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 4*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 2*eax]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 4*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 4*eax]#",
        "2#lea ebx, [8*eax]#lea ecx, [4*ebx]#",
        "2#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [4*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*eax]#",
        "2#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [eax + 4*ebx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 2*ecx]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#",
        "2#lea ebx, [eax + 4*eax]#lea ecx, [eax + 8*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*eax]#lea edx, [ebx + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*eax]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 1*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 1*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 8*eax]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 8*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 2*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ebx + 8*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ebx]#",
        "2#lea ebx, [8*eax]#lea ecx, [8*ebx]#",
        "2#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [8*ebx]#lea edx, [ecx + 4*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 4*eax]#",
        "3#lea ebx, [4*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 4*eax]#lea eex, [edx + 2*eax]#",
        "2#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*eax]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*eax]#lea eex, [edx + 2*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*eax]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 8*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 1*ecx]#",
        "2#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 1*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [eax + 1*edx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 8*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 8*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ebx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 8*ecx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [4*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [4*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#",
        "3#lea ebx, [eax + 2*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [eax + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 2*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ebx + 8*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 8*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 8*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [ebx + 1*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ebx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 8*ebx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*ebx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 8*ecx]#lea eex, [ebx + 1*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ebx + 4*ecx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [eax + 2*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [8*ebx]#lea edx, [2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [8*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [2*ecx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 8*ebx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [eax + 8*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 4*eax]#lea eex, [eax + 2*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*eax]#lea eex, [eax + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [eax + 8*ebx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*eax]#lea edx, [ecx + 8*ebx]#lea eex, [ecx + 2*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [2*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 4*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 8*eax]#lea eex, [ecx + 2*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 2*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#lea eex, [ebx + 2*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 8*ebx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 8*eax]#lea eex, [edx + 2*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [4*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 4*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [2*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 2*ecx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 8*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [eax + 1*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ebx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [eax + 4*ecx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [ecx + 1*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [eax + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ebx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 8*ebx]#lea eex, [ecx + 2*edx]#",
        "3#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 4*ecx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*eax]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 4*ecx]#lea eex, [edx + 2*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [ebx + 2*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ebx + 8*ecx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 8*ecx]#lea eex, [edx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 4*ebx]#lea eex, [ecx + 4*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 8*ecx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 4*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [8*ecx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [8*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [8*ecx]#lea eex, [edx + 4*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 8*ecx]#lea eex, [edx + 4*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [8*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*eax]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [eax + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 8*ebx]#lea eex, [ecx + 2*edx]#",
        "3#lea ebx, [eax + 2*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ebx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 4*ebx]#lea eex, [ecx + 4*edx]#",
        "3#lea ebx, [eax + 4*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ebx + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [eax + 8*ecx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 4*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 8*ebx]#lea eex, [ecx + 1*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [eax + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*ebx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [eax + 2*ecx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ebx + 8*ecx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*eax]#lea edx, [ebx + 2*ecx]#lea eex, [edx + 4*edx]#",
        "3#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 8*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*eax]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 8*ecx]#lea eex, [edx + 4*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [eax + 8*ecx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [ebx + 1*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*ecx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [eax + 1*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*ebx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 8*ebx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ebx + 4*ecx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 4*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*ecx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*ebx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [eax + 2*ebx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 8*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [eax + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ecx + 2*ebx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [eax + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 2*ebx]#",
        "4#lea ebx, [eax + 4*eax]#lea ecx, [eax + 1*ebx]#lea edx, [ebx + 4*ecx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*eax]#lea edx, [ebx + 8*ecx]#lea eex, [ecx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ebx + 1*ecx]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [eax + 2*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [eax + 1*ebx]#lea edx, [ebx + 2*ecx]#lea eex, [ecx + 8*edx]#",
        "3#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 4*ebx]#lea eex, [ecx + 4*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [eax + 2*ecx]#lea eex, [edx + 4*edx]#",
        "4#lea ebx, [4*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ecx]#lea eex, [ecx + 8*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 4*ebx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*eax]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 4*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*ecx]#lea eex, [edx + 8*eax]#",
        "4#lea ebx, [8*eax]#lea ecx, [ebx + 2*ebx]#lea edx, [ecx + 4*eax]#lea eex, [edx + 8*edx]#",
        "4#lea ebx, [eax + 8*eax]#lea ecx, [ebx + 4*ebx]#lea edx, [ecx + 2*ebx]#lea eex, [eax + 4*edx]#",
        "5#lea ebx, [8*eax]#lea ecx, [ebx + 8*ebx]#lea edx, [ecx + 2*eax]#lea eex, [edx + 2*edx]#lea efx, [eex + 4*ebx]#",
        "4#lea ebx, [8*eax]#lea ecx, [eax + 2*ebx]#lea edx, [ecx + 4*ecx]#lea eex, [edx + 2*edx]#",

    };
    






































































    
    int n;
    cin >> n;
    for (auto t : uu[n]) {
        if (t == CHANGE_LINE) {
            cout << '\n';
        } else {
            cout << t;
        }
    }
}
