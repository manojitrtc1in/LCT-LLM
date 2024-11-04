





































using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(42);







template <typename T> void id0(T &a, const T &b) { a = min(a, b); }
template <typename T> void id1(T &a, const T &b) { a = max(a, b); }

typedef tree <
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;






void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(ordered_set v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const double eps = 1e-9;
ll expo(ll a, ll b, ll mod = MOD) {
    if (b == 0) {return 1;}
    ll z = expo(a, b / 2); z *= z; z %= mod; if (b % 2 != 0) {z *= a; z %= mod;}
    return z;
}
ll gcd(ll a, ll b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}
int add(int x, int y, int mod = MOD)
{
    x += y;
    while (x >= mod) x -= mod;
    while (x < 0) x += mod;
    return x;
}

int sub(int x, int y, int mod = MOD)
{
    return add(x, -y, mod);
}

int mul(int x, int y, int mod = MOD)
{
    return (x * 1ll * y) % mod;
}
const int inf = 1e9;
int n;
vector<int>lazy1, seg1, seg3, lazy3;














void push3(int node) {
    if (lazy3[node] != 0) {
        seg3[2 * node + 2] = seg3[2 * node + 1] = lazy3[node];
        lazy3[2 * node + 1] = lazy3[2 * node + 2] = lazy3[node];
        lazy3[node] = 0;
    }
}
void push1(int node) {
    if (lazy1[node] != 0) {
        seg1[2 * node + 2] = seg1[2 * node + 1] = lazy1[node];
        lazy1[2 * node + 1] = lazy1[2 * node + 2] = lazy1[node];
        lazy1[node] = 0;
    }
}



























void update3(int node, int s, int e, int l, int r, int val) {
    if (e < l || s > r)return;
    if (l <= s && r >= e) {
        seg3[node] = val;
        lazy3[node] = val;
        return;
    }
    push3(node);
    int md = (s + e) >> 1;
    update3(2 * node + 1, s, md, l, r, val);
    update3(2 * node + 2, md + 1, e, l, r, val);
    seg3[node] = min(seg3[2 * node + 1], seg3[2 * node + 2]);
}
void update1(int node, int s, int e, int l, int r, int val) {
    if (e < l || s > r)return;
    if (l <= s && r >= e) {
        seg1[node] = val;
        lazy1[node] = val;
        return;
    }
    push1(node);
    int md = (s + e) >> 1;
    update1(2 * node + 1, s, md, l, r, val);
    update1(2 * node + 2, md + 1, e, l, r, val);
    seg1[node] = max(seg1[2 * node + 1], seg1[2 * node + 2]);
}



















int query3(int node, int s, int e, int l, int r) {
    if (e < l || s > r)return inf;
    if (l <= s && r >= e) {
        return seg3[node];
    }
    push3(node);
    int md = (s + e) >> 1;
    return (min(query3(2 * node + 1, s, md, l, r) , query3(2 * node + 2, md + 1, e, l, r) ));
}
int query1(int node, int s, int e, int l, int r) {
    if (e < l || s > r)return 0;
    if (l <= s && r >= e) {
        return seg1[node];
    }
    push1(node);
    int md = (s + e) >> 1;
    return (max(query1(2 * node + 1, s, md, l, r) , query1(2 * node + 2, md + 1, e, l, r) ));
}
































































































bool get_idx(int s, int idx, int e) {
    int l = s;
    int r = idx;
    while (l <= r) {
        int md = l + (r - l) / 2;
        if (query1(0, 0, n - 1, s, md) < idx) {
            l = md + 1;
        }
        else {
            r = md - 1;
        }
    }
    

    if (l > idx) {
        return false;
    }
    

    int ans1 = query1(0, 0, n - 1, s, l);
    

    return (l <= idx && ans1 <= e && ans1 >= idx);
}

bool check(int idx, int l, int r) {

    if (idx == 0 || idx >= n) {
        return false;
    }
    

    


    

    

    

    

    

    

    

    int val = query3(0, 0, n - 1, l, idx);


    return (val <= r);

    


}




















int id2(int s, int e) {
    int l = 1;
    int r = s - 1;
    while (l <= r) {
        int md = l + (r - l) / 2;
        if (query1(0, 0, n - 1, l, md) > e) {
            r = md - 1;
        }
        else {
            l = md + 1;
        }
    }
    return (r + 1);

}
void test() {
    int  q;
    cin >> n >> q;
    n++;
    seg1.resize(4 * n, 0);
    seg3.resize(4 * n, inf);
    lazy1 = lazy3 = seg1;
    set<int>st;
    for (int i = 1; i < n; i++) {
        st.insert(i);
    }
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            int l, r, status; 

            cin >> l >> r >> status;
            if (status == 0) {
                

                

                auto it = st.lower_bound(l);
                while (it != st.end() && *it <= r) {
                    int x = *it;
                    it++;
                    st.erase(x);
                }
            }
            else {

                id0(r, query3(0, 0, n - 1, l, n - 1));
                

                

                

                update3(0, 0, n - 1, l, l, r);
                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

            }

        }
        else {
            int idx;
            cin >> idx;
            if (!st.count(idx)) {
                cout << "NO\n";
            }
            else  {
                auto it1 = st.lower_bound(idx);
                int l, r;
                if (it1 == st.begin()) {
                    l = 0;
                }
                else {
                    it1--;
                    l = *it1;
                }
                auto it2 = st.upper_bound(idx);
                if (it2 == st.end()) {
                    r = n;
                }
                else {
                    r = *it2;
                }
                l++;
                r--;
                if (check(idx, l, r)) {
                    

                    

                    cout << "YES\n";
                }
                else {
                    cout << "N/A\n";
                }
            }

            

        }
    }
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);


    int t = 1;


    while (t--) {
        test();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}





