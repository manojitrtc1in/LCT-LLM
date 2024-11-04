

using namespace std;
































struct node
{

    int val;
    int L, R;
    node()
    {
        val = 0;
        L = -1, R = -1;
    }

    node(int val, int L, int R)
    {
        this->val = val;
        this->L = L;
        this->R = R;
    }
};

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(node A)
{

    pair<int, pair<int, int>> B = {A.val, {A.L, A.R}};

    return to_string(B);
};

template <typename T>
string to_string(stack<T> st);
template <typename T>
string to_string(queue<T> q);
string to_string(char c) { return string(1, c); }
string to_string(const string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if (!first)
        {
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
    for (int i = 0; i < S; ++i)
    {
        if (!f)
        {
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
    for (const auto &x : v)
    {
        if (!first)
        {
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
template <typename T>
string to_string(stack<T> st)
{
    bool first = true;
    string res = "{";
    while (!st.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(st.top());
        st.pop();
    }
    res += "}";
    return res;
}
template <typename T>
string to_string(queue<T> q)
{
    bool first = true;
    string res = "{";
    while (!q.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;
}
template <typename T>
string to_string(T pq, bool ispq)
{
    assert(ispq);
    bool first = true;
    string res = "{";
    while (!pq.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}


void DBG() { cerr << " ]"
                  << "\n"; }
template <typename Head, typename... Tail>
void DBG(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    if (sizeof...(T))
    {
        cerr << ", ";
    }
    DBG(T...);
}












using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key, typename value, typename cmp = std::less<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;












void read(char &x) { cin >> x; }
void read(int &x) { cin >> x; }
void read(ll &x) { cin >> x; }
void read(double &x) { cin >> x; }
void read(string &s) { cin >> s; }


template <typename T1, typename T2>
void read(pair<T1, T2> &p) { cin >> p.first >> p.second; }
template <typename T>
void read(T &A)
{
    for (auto &x : A)
    {
        read(x);
    }
}
template <typename T>
void a_offset(T &A, int off = -1)
{
    for (auto &x : A)
    {
        x += off;
    }
}
template <class H, class... T>
void read(H &h, T &... t)
{
    read(h);
    read(t...);
}






template <typename T>
void out(T &A, int offset = 0)
{
    for (auto &x : A)
    {
        x += offset;
        cout << x << " ";
    }
    cout << "\n";
}





    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi)                     \
        {                                    \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid))                  \
            {                                \
                ansi = mid;                  \
                hi = mid - 1;                \
            }                                \
            else                             \
            {                                \
                lo = mid + 1;                \
            }                                \
        }                                    \
    }

    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi)                     \
        {                                    \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid))                  \
            {                                \
                ansi = mid;                  \
                lo = mid + 1;                \
            }                                \
            else                             \
            {                                \
                hi = mid - 1;                \
            }                                \
        }                                    \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id3 = 7;                   \
        while (hi - lo > id3)                \
        {                                          \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) < gv(m2))                   \
            {                                      \
                lo = m1;                           \
            }                                      \
            else                                   \
            {                                      \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i)         \
        {                                          \
            if (a_max(ansv, gv(i)))                \
            {                                      \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id3 = 7;                   \
        while (hi - lo > id3)                \
        {                                          \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) > gv(m2))                   \
            {                                      \
                lo = m1;                           \
            }                                      \
            else                                   \
            {                                      \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i)         \
        {                                          \
            if (a_min(ansv, gv(i)))                \
            {                                      \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps)                         \
        {                                             \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) < gv(m2))                      \
            {                                         \
                lo = m1;                              \
            }                                         \
            else                                      \
            {                                         \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps)                         \
        {                                             \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) > gv(m2))                      \
            {                                         \
                lo = m1;                              \
            }                                         \
            else                                      \
            {                                         \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }


mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_m(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(mt_rng); }


template <typename T>
bool a_min(T &a, const T &b) { return (b < a) ? (a = b), 1 : 0; }


template <typename T>
bool a_max(T &a, const T &b) { return (b > a) ? (a = b), 1 : 0; }


ll ceil(ll m, ll n) { return (m + n - 1) / n; }




ll gv(int i, int j, vector<ll> &pre)
{
    if (i > j || (j < 0))
    {
        return 0LL;
    }
    ll val = pre[j];
    if (i - 1 >= 0)
    {
        val -= pre[i - 1];
    }
    return val;
}


ll gpv(int i, vector<ll> &pre) { return gv(0, i, pre); }


ll gsv(int i, vector<ll> &suf)
{
    int n = sz(suf);
    if (i >= n)
    {
        return 0LL;
    }
    return suf[i];
}


void assign_pre(vector<ll> &pre, vector<ll> &A)
{
    int n = sz(A);
    for (int i = 0; i < n; ++i)
    {
        pre[i] = A[i];
        if (i)
        {
            pre[i] += pre[i - 1];
        }
    }
}


void id1(vector<ll> &suf, vector<ll> &A)
{
    int n = sz(A);
    for (int i = n - 1; i >= 0; --i)
    {
        suf[i] = A[i];
        if (i + 1 < n)
        {
            suf[i] += suf[i + 1];
        }
    }
}


template <typename T>
int sorted_range(const vector<T> &A, int l, int r)
{
    int n = A.size();
    if (r < l)
    {
        return 0;
    }
    return ubi(A, r) - ubi(A, l - 1);
}


template <typename T>
void remove_dup(vector<T> &v)
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

bool id0 = 0;







ll idist(ll x, ll y)
{
    if (x > y)
    {
        swap(x, y);
    }
    return y - x + 1;
}

ll ileft(ll x, ll xl)
{
    x = x - xl + 1;
    return x;
}

ll iright(ll x, ll xl)
{
    x = x + xl - 1;
    return x;
}

ll getcomp(const string &s)
{

    vector<node> A;

    int n = sz(s);

    int N = n;
    int i = 0;

    while (i < n)
    {

        int j = i;

        while (j < n && s[i] == s[j])
        {

            ++j;
        }

        if (s[i] != '0')
        {
            A.push_back(node(j - i, i, j - 1));
        }
        i = j;
    }

    ll ans = 0;

    auto sum = [&](ll i) {
        ll val = 0;
        dbg(i); 
        for (ll j = 1; j <= i; ++j)
        {
            val += (j * (j + 1)) / 2;
        }
        dbg(val);
        return val;
    };

    for (node x : A)
    {
        

        ans += sum(x.val);
    }

    dbg(ans);

    n = sz(A);

    vector<int> L(n);
    stack<node> st;

    for (int i = 0; i < n; ++i)
    {

        while (!st.empty() && st.top().val <= A[i].val)
        {
            st.pop();
        }

        if (st.empty())
        {
            L[i] = A[i].L;
        }
        else
        {
            

            


            


            L[i] = idist(A[i].L - 1, ileft(st.top().R, A[i].val));
            

        }

        st.push(A[i]);
    }

    st = stack<node>();

    vector<int> R(n);

    for (int i = n - 1; i >= 0; --i)
    {

        while (!st.empty() && st.top().val < A[i].val)
        {
            st.pop();
        }

        if (st.empty())
        {
            R[i] = N - (A[i].R + 1);
            

        }
        else
        {
            

            


            dbg(st.top().L, A[i].val, A[i].R);

            


            R[i] = idist(A[i].R + 1, iright(st.top().L, A[i].val - 1));

            

            

            

        }

        st.push(A[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        ans += 1LL * A[i].val * L[i] * R[i];
    }

    dbg(A);
    dbg(L, R);
    dbg(ans);

    return ans;
}

ll getcum(string s, bool f)
{

    dbg(s, f);

    ll ans = 0;

    stack<node> st;

    ll curlen = 0;

    int n = sz(s);

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            st.push(node(curlen, i - curlen, i - 1));
            curlen = 0;
            continue;
        }

        ++curlen;

        if (!f)
        {

            while (!st.empty() && st.top().val <= curlen)
            {
                st.pop();
            }

            if (st.empty())
            {
                ans += curlen * (i + 1 - curlen);
            }
            else
            {

                

                ans += curlen * idist(ileft(st.top().R, curlen), ileft(i, curlen) - 1);
                
                dbg(st.top() , st.top().R , curlen , i);
                dbg(ileft(i , curlen) , ileft(st.top().R, curlen)); 
            }
            dbg(i, ans);
        }
        else
        {

            while (!st.empty() && st.top().val < curlen)
            {
                st.pop();
            }

            if (st.empty())
            {
                ans += curlen * (i + 1 - curlen);
                dbg(curlen, i);
            }
            else
            {
                


                ans += curlen * idist(ileft(st.top().R, curlen - 1), ileft(i, curlen) - 1);
            }
            dbg(ans);
        }
    }

    return ans;
};

void solve()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = getcomp(s);

    ll forward = getcum(s, false);

    dbg(forward);
    ans += forward;

    reverse(all(s));

    ll rev = getcum(s, true);
    dbg(rev);

    ans += rev;

    cout << ans << "\n";
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

    if (id4)
    {
        id0 = true;
    }

    if (id0)
    {
        cin >> T;
    }

    for (int t = 1; t <= T; ++t)
    {
        if (t == 1)
        {

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
