

using namespace std;


































template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(char c) { return string(1, c); }
string to_string(const string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}


template <size_t S>
string to_string(bitset<S> b)
{
    string res;
    res += '{';
    bool f = true;
    for (int i = 0; i < S; ++i) {
        if (!f) {
            res += ',';
        }
        f = false;
        res += char('0' + b[i]);
    }
    res += '}';
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }


void DBG() { cerr << " ]"
                  << "\n"; }
template <typename Head, typename... Tail>
void DBG(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    if (sizeof...(T)) {
        cerr << ", ";
    }
    DBG(T...);
}












using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key, typename value, typename cmp = std::less<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;












void read(char& x) { cin >> x; }
void read(int& x) { cin >> x; }
void read(ll& x) { cin >> x; }
void read(double& x) { cin >> x; }
void read(string& s) { cin >> s; }


template <typename T1, typename T2>
void read(pair<T1, T2>& p) { cin >> p.first >> p.second; }
template <typename T>
void read(T& A)
{
    for (auto& x : A) {
        read(x);
    }
}
template <typename T>
void a_offset(T& A, int off = -1)
{
    for (auto& x : A) {
        x += off;
    }
}
template <class H, class... T>
void read(H& h, T&... t)
{
    read(h);
    read(t...);
}






template <typename T>
void out(T& A, int offset = 0)
{
    for (auto& x : A) {
        x += offset;
        cout << x << " ";
    }
    cout << "\n";
}





    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi) {                   \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid)) {                \
                ansi = mid;                  \
                hi = mid - 1;                \
            } else {                         \
                lo = mid + 1;                \
            }                                \
        }                                    \
    }

    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi) {                   \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid)) {                \
                ansi = mid;                  \
                lo = mid + 1;                \
            } else {                         \
                hi = mid - 1;                \
            }                                \
        }                                    \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id0 = 7;                   \
        while (hi - lo > id0) {              \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) < gv(m2)) {                 \
                lo = m1;                           \
            } else {                               \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i) {       \
            if (a_max(ansv, gv(i))) {              \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id0 = 7;                   \
        while (hi - lo > id0) {              \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) > gv(m2)) {                 \
                lo = m1;                           \
            } else {                               \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i) {       \
            if (a_min(ansv, gv(i))) {              \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps) {                       \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) < gv(m2)) {                    \
                lo = m1;                              \
            } else {                                  \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps) {                       \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) > gv(m2)) {                    \
                lo = m1;                              \
            } else {                                  \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }


template <typename T>
bool a_min(T& a, const T& b) { return (b < a) ? (a = b), 1 : 0; }


template <typename T>
bool a_max(T& a, const T& b) { return (b > a) ? (a = b), 1 : 0; }


ll ceil(ll m, ll n) { return (m + n - 1) / n; }




ll gv(int i, int j, vector<ll>& pre)
{
    if (i > j || (j < 0)) {
        return 0LL;
    }
    ll val = pre[j];
    if (i - 1 >= 0) {
        val -= pre[i - 1];
    }
    return val;
}


ll gpv(int i, vector<ll>& pre) { return gv(0, i, pre); }


ll gsv(int i, vector<ll>& suf)
{
    int n = suf.size();
    if (i >= n) {
        return 0LL;
    }
    return suf[i];
}


void a_pre(vector<ll>& pre, vector<ll>& A)
{
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        pre[i] = A[i];
        if (i) {
            pre[i] += pre[i - 1];
        }
    }
}


void id1(vector<ll>& suf, vector<ll>& A)
{
    int n = A.size();
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = A[i];
        if (i + 1 < n) {
            suf[i] += suf[i + 1];
        }
    }
}


template <typename T>
int sorted_r(const vector<T>& A, int l, int r)
{
    int n = A.size();
    if (r < l) {
        return 0;
    }
    return ubi(A, r) - ubi(A, l - 1);
}


template <typename T>
void r_dup(vector<T>& v)
{
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}


constexpr int ppcnt(int x) { return __builtin_popcount(x); }
constexpr int ppcnt(ll x) { return __builtin_popcountll(x); }


constexpr int id2(int x) { return 31 - __builtin_clz(x); }
constexpr int id2(ll x) { return 63 - __builtin_clzll(x); }






auto start = std::chrono::system_clock::now();




const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18;

const int M = 1e9 + 7;





bool id4 = 0;

bool id3 = 1;







void solve()
{

    int n, x, y;
    cin >> n >> x >> y;

    y -= x;
    vector<int> A(n), res(n);

    read(A);

    vector<vector<int>> pos(n + 2);

    for (int i = 0; i < n; ++i) {
        pos[A[i]].push_back(i);
    }

    dbg(A, pos);

    int lc = -1;

    set<ar<int, 2>> st;
    for (int i = 1; i <= n + 1; ++i) {
        if (pos[i].empty()) {
            lc = i;
        } else {
            st.insert({ pos[i].size(), i });
        }
    }

    dbg(lc, st);


    cout << "NO"  \
         << "\n"; \
    return;

    while (x) {

        if (st.empty()) {
            ret();
        }

        auto lst = *st.rbegin();
        st.erase(lst);

        res[pos[lst[1]].back()] = lst[1];
        pos[lst[1]].pop_back();

        if (--lst[0] > 0) {
            st.insert(lst);
        }
        --x;
    }

    dbg(res);
    dbg(x);
    dbg(st);


    cout << "YES"                 \
         << "\n";                 \
    for (int i = 0; i < n; ++i) { \
        if (res[i] == 0) {        \
            res[i] = lc;          \
        }                         \
    }                             \
    out(res);                     \
    return;

    while (y > 0) {

        if (st.empty()) {
            ret();
        }

        if (y == 3 && sz(st) > 2) {
            

            

            

            

            


            auto fst = *st.rbegin();
            st.erase(fst);

            auto mid = *st.rbegin();
            st.erase(mid);

            auto lst = *st.rbegin();
            st.erase(lst);

            res[pos[fst[1]].back()] = lst[1];
            res[pos[mid[1]].back()] = fst[1];
            res[pos[lst[1]].back()] = mid[1];
            pos[fst[1]].pop_back();
            pos[mid[1]].pop_back();
            pos[lst[1]].pop_back();
            --fst[0], --mid[0], --lst[0];

            y -= 3;

            retans();
        } else if (y == 1) {

            if (sz(st) <= 1) {
                ret();
            }

            auto it = st.begin();
            auto fst = *it++;
            auto lst = *it;

            res[pos[fst[1]].back()] = lst[1];
            pos[fst[1]].pop_back();
            --fst[0];
            y -= 1;

            retans();
        }

        if (sz(st) < 2) {
            ret();
        }

        

        

        

        


        auto fst = *st.rbegin();
        st.erase(fst);

        auto lst = *st.rbegin();
        st.erase(lst);

        

        


        res[pos[fst[1]].back()] = lst[1];
        res[pos[lst[1]].back()] = fst[1];
        pos[fst[1]].pop_back();
        pos[lst[1]].pop_back();
        dbg(fst, lst);
        dbg(st);

        if (--fst[0]) {
            st.insert(fst);
        }
        if (--lst[0]) {
            st.insert(lst);
        }
        y -= 2;
        dbg(y);
    }

    retans();
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

    if (id4) {
        id3 = true;
    }

    if (id3) {
        cin >> T;
    }

    for (int t = 1; t <= T; ++t) {
        if (t == 1) {

            start = std::chrono::system_clock::now();

        }
        if (id4)
            cout << "Case 
        solve();
    }


    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";


    return 0;
}