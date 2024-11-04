#include<bits/stdc++.h>
#define int ll
#define sz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int minf = 0xc0c0c0c0c0c0c0c0;

#ifdef LOCAL
ostream &operator<<(ostream &os, pair<auto, auto> v) {
    os << '(' << v.first << ' ' << v.second << ')';
    return os;
}
ostream &operator<<(ostream &os, tuple<auto, auto, auto> v) {
    os << '(' << get<0>(v) << ' ' << get<1>(v) << ' ' << get<2>(v) << ')';
    return os;
}
ostream &operator<<(ostream &os, tuple<auto, auto, auto, auto> v) {
    os << '(' << get<0>(v) << ' ' << get<1>(v) << ' ' << get<2>(v) << ' ' << get<3>(v) << ')';
    return os;
}
ostream &operator<<(ostream &os, tuple<auto, auto, auto, auto, auto> v) {
    os << '(' << get<0>(v) << ' ' << get<1>(v) << ' ' << get<2>(v) << ' ' << get<3>(v) << ' ' << get<4>(v) << ')';
    return os;
}
ostream &operator<<(ostream &os, vector<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, deque<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, list<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, set<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, set<auto, auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, multiset<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, multiset<auto, auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, map<auto, auto> v) {
    bool flag = false;
    os << '[';
    for (auto [x, y] : v) {
        if (flag) {
            os << ", ";
        }
        flag = true;
        os << x << ": " << y;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, map<auto, auto, auto> v) {
    bool flag = false;
    os << '[';
    for (auto [x, y] : v) {
        if (flag) {
            os << ", ";
        }
        flag = true;
        os << x << ": " << y;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, unordered_set<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, unordered_multiset<auto> v) {
    bool flag = false;
    os << '[';
    for (auto x : v) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << x;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, unordered_map<auto, auto> v) {
    bool flag = false;
    os << '[';
    for (auto [x, y] : v) {
        if (flag) {
            os << ", ";
        }
        flag = true;
        os << x << ": " << y;
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, stack<auto> v) {
    bool flag = false;
    os << '[';
    while (sz(v)) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << v.top();
        v.pop();
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, queue<auto> v) {
    bool flag = false;
    os << '[';
    while (sz(v)) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << v.front();
        v.pop();
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, priority_queue<auto> v) {
    bool flag = false;
    os << '[';
    while (sz(v)) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << v.top();
        v.pop();
    }
    os << ']';
    return os;
}
ostream &operator<<(ostream &os, priority_queue<auto, auto, auto> v) {
    bool flag = false;
    os << '[';
    while (sz(v)) {
        if (flag) {
            os << ' ';
        }
        flag = true;
        os << v.top();
        v.pop();
    }
    os << ']';
    return os;
}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) {
        cerr << ", ";
    }
    debug_out(T...);
}
#define debug(...) cerr << #__VA_ARGS__ << " = ", debug_out(__VA_ARGS__)
#else
#define debug(...) 0xF
#endif















char S[300300];
int match[300300];
int inv[300300];

vector<int> v;

int num = 0;

int L2in[300300];
int R2in[300300];

int myth[300300];
int chdcnt[300300];
int par[300300];

int sub[300300];


void dfs(int le, int ri) {

    ++num;
    int mynum = num;

    sub[mynum] = 1;

    L2in[v[le]] = mynum;
    R2in[v[ri]] = mynum;

    int th = 0;

    for (int i = le + 1; i < ri;) {
        ++th;
        int j = inv[match[v[i]]];
        int chdnum = num + 1;
        myth[chdnum] = th;
        par[chdnum] = mynum;
        dfs(i, j);
        sub[mynum] += sub[chdnum];
        i = j + 1;
    }

    chdcnt[mynum] = th;
    debug(v[le], v[ri], chdcnt[mynum]);
}


struct SEG {
    int node_size, bias;
    vector<int> A;

    void init(int st, int en) {
        node_size = en - st + 1;
        bias = -st;
        A.resize(node_size * 2 + 5);
        fill(all(A), 0);
        

        

    }

    void init(int st, int en, auto origin) {
        node_size = en - st + 1;
        bias = -st;
        A.resize(node_size * 2 + 5);

        for (int i = node_size, j = st; j <= en; i++, j++) {
            A[i] = origin[j];
        }
        for (int i = node_size - 1; i; i--) {
            A[i] = A[i << 1] + A[i << 1 | 1];
            

            

        }
    }

    int solve(int le, int ri) {
        int ret = 0;
        

        


        for (le += node_size + bias, ri += node_size + bias; le <= ri; le >>= 1, ri >>= 1) {
            if (le & 1) {
                ret += A[le];
                

                

                ++le;
            }
            if (~ri & 1) {
                ret += A[ri];
                

                

                --ri;
            }
        }
        return ret;
    }

    void update(int idx, int val) {
        idx += node_size + bias;

        A[idx] = val;
        


        for (idx >>= 1; idx; idx >>= 1) {
            A[idx] = A[idx << 1] + A[idx << 1 | 1];
            

            

        }
    }
} tree;


struct Node {
    int lmx, rmx, val, zmrl;
    Node(int lmx = 0, int rmx = 0, int val = 0, int zmrl = 0) : lmx(lmx), rmx(rmx), val(val), zmrl(zmrl) {}
};

struct SEG2 {
    int st, en, le, ri, idx, val, k;
    vector<Node> A;

    void init(int st, int en) {
        this->st = st, this->en = en;
        A.resize((en - st + 1) * 4 + 5);
        fill(all(A), Node());
        

        

    }

    

    

    

    

    


    

    

    

    

    

    

    

    


    

    

    

    


    Node solve(int le, int ri) {
        this->le = le, this->ri = ri;
        return solve(1, st, en);
    }

    Node solve(int nidx, int st, int en) {
        if (st > ri || en < le || le > ri) {
            return Node();
            

            

        }
        if (le <= st && en <= ri) {
            return A[nidx];
        }
        int mid = (st + en) >> 1;
        Node L = solve(nidx << 1, st, mid);
        Node R = solve(nidx << 1 | 1, mid + 1, en);

        Node ret = Node();
        ret.lmx = L.lmx;
        if (L.lmx == L.zmrl) {
            ret.lmx += R.lmx;
        }

        ret.rmx = R.rmx;
        if (R.rmx == R.zmrl) {
            ret.rmx += L.rmx;
        }

        ret.val = L.val + R.val - (L.rmx * (L.rmx + 1) / 2 + R.lmx * (R.lmx + 1) / 2) + (L.rmx + R.lmx) * (L.rmx + R.lmx + 1) / 2;


        ret.zmrl = L.zmrl + R.zmrl;

        return ret;
        

        

    }

    void update(int idx, int val) {
        this->idx = idx, this->val = val;
        update(1, st, en);
    }

    void update(int nidx, int st, int en) {
        if (st == en) {
            A[nidx] = Node(val, val, val, val);

            

            return;
        }
        int mid = (st + en) >> 1;
        if (idx <= mid) {
            update(nidx << 1, st, mid);
        }
        else {
            update(nidx << 1 | 1, mid + 1, en);
        }
        Node L = A[nidx << 1];
        Node R = A[nidx << 1 | 1];

        Node &ret = A[nidx];

        ret.lmx = L.lmx;
        if (L.lmx == L.zmrl) {
            ret.lmx += R.lmx;
        }

        ret.rmx = R.rmx;
        if (R.rmx == R.zmrl) {
            ret.rmx += L.rmx;
        }

        ret.val = L.val + R.val - (L.rmx * (L.rmx + 1) / 2 + R.lmx * (R.lmx + 1) / 2) + (L.rmx + R.lmx) * (L.rmx + R.lmx + 1) / 2;

        ret.zmrl = L.zmrl + R.zmrl;

        

        

    }

    

    

    

    


    

    

    

    

    

    

    

    


    

    

    

} fuck[300300];













signed main() {
#ifdef LOCAL
    freopen("debug.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);





    int n, Q; cin >> n >> Q >> S;
    for (int i = n; i >= 0; i--) {
        S[i + 1] = S[i];
    }

    vector<int> stk;

    for (int i = 1; i <= n; i++) {
        if (S[i] == '(') {
            stk.push_back(i);
        }
        else {
            if (sz(stk)) {
                match[stk.back()] = i;
                match[i] = stk.back();
                stk.pop_back();
            }
        }
    }

    match[0] = n + 1, match[n + 1] = 0;


    v.push_back(0);

    for (int i = 1; i <= n; i++) {
        if (match[i] != 0) {
            v.push_back(i);
        }
    }

    v.push_back(n + 1);

    debug(v);


    for (int i = 0; i < sz(v); i++) {
        inv[v[i]] = i;
    }

    dfs(0, sz(v) - 1);


    tree.init(1, num);

    for (int i = 1; i <= num; i++) {
        debug(i, chdcnt[i]);
        tree.update(i, chdcnt[i] * (chdcnt[i] + 1) / 2);
        if (chdcnt[i] > 0) {
            fuck[i].init(1, chdcnt[i]);
            for (int j = 1; j <= chdcnt[i]; j++) {
                fuck[i].update(j, 1);
            }
        }
    }




    while (Q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            assert(L2in[l] == R2in[r]);
            int in = L2in[l];
            int p = par[in];
            chdcnt[p]--;
            tree.update(p, chdcnt[p] * (chdcnt[p] + 1) / 2);
            fuck[p].update(myth[in], 0);
        }
        else {
            int L = L2in[l];
            int R = R2in[r] + sub[R2in[r]] - 1;
            int res = tree.solve(L, R);

            int p = par[L2in[l]];

            res += fuck[p].solve(myth[L2in[l]], myth[R2in[r]]).val;

            cout << res << '\n';
        }
    }



























    return 0;
}