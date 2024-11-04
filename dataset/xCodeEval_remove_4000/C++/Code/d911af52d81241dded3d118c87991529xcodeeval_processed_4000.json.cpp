





using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
using TI = tuple<int, int, int>;
using TL = tuple<LL, LL, LL>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b) : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b) : -abs(a) / abs(b);
}
template <class T> bool chmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); } 
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> auto sum(const T &a) { return accumulate(ALL(a), (typename T::value_type)0); }
template <> auto sum(const vector<int> &a) { return accumulate(ALL(a), 0LL); }
template <> auto sum(const vector<string> &a) { return accumulate(ALL(a), string()); }
template <class T> void id3(T &a) { sort(ALL(a)); a.erase(unique(ALL(a)), a.end()); }
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
 


template <typename T> void in(T &a) { cin >> a; }
template <typename A, typename... B> void in(A &a, B &... b) { in(a), in(b...); }
template <typename A, typename B> void in(pair<A, B> &p) { in(p.first, p.second); }
template <typename A, typename B, typename C> void in(tuple<A, B, C> &p) { in(get<0>(p), get<1>(p), get<2>(p)); }
template <typename T, size_t N> void in(array<T, N> &a) { for (auto &v: a) in(v); }
template <typename T> void in(vector<T> &vec) { for (auto& v: vec) in(v); }
template <typename T, size_t N>
istream& operator >>(istream& inp, array<T, N> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename T>
istream& operator >>(istream& inp, vector<T> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename A, typename B>
istream& operator >>(istream& inp, pair<A, B> &p) {
    inp >> p.first >> p.second;
    return inp;
}
template <typename A, typename B, typename C>
istream& operator >>(istream& inp, tuple<A, B, C> &p) {
    inp >> get<0>(p) >> get<1>(p) >> get<2>(p);
    return inp;
}
void ou() { cout << '\n'; }
template<typename T> void ou(const T &a) { cout << a << '\n'; }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template<typename A, typename B> void ou(const pair<A, B> &p) {
    cout << p.first << ' ' << p.second << '\n';
}
template<typename A, typename B, typename C> void ou(const tuple<A, B, C> &p) {
    cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
}
void ou(const vector<int> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<LL> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<double> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
template <typename A> void ou(const vector<A> &vec) {
    for (auto &v: vec) ou(v);
}
template<size_t N> void ou(const array<int, N> &a) {
    for (int i = 0; i < N; i++) cout << a[i] << " \n"[i == N - 1];
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

const string COLOR_RESET = "\033[0m";
const string id1 = "\033[1;32m";
const string id4 = "\033[1;31m";
const string id0 = "\033[1;36m";
const string id2 = "\033[0;9;37m";
const string RED_BACKGROUND = "\033[1;41m";
const string id6 = "\033[0;2m";
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<class A, class B, class C> ostream& operator <<(ostream& out, const tuple<A, B, C> &p) {
    return out << "(" << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ")";
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
    out << "["; for (int i = 0; i < (int)N; i++) out << a[i] << (i == N - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const deque<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream &out, const multiset<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const unordered_set<T>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << it->first << ":" << it->second << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, class Cmp>
ostream& operator <<(ostream& out, priority_queue<U, vector<U>, Cmp>& a) {
    out << "{"; bool first = true;
    priority_queue<U, vector<U>, Cmp> tmp;
    while (!a.empty()) { out << (first ? "" : ", "); out << a.top(); tmp.emplace(a.top()); a.pop(); first = 0; } out << "}";
    a = move(tmp);
    return out;
}


 


template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << id0 << name << COLOR_RESET << ": " << arg1 << COLOR_RESET << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << id0;
    cerr.write(names, comma - names) << COLOR_RESET << ": " << arg1 << ' ';
    cerr << id4 << "| " << COLOR_RESET;
    __f(comma + 1, args...);
}




int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);










    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n); in(a);
        if (n <= 2) { YES(1); ou(a); continue; }
        

        

        

        

        

        auto dp = vect<int>(inf<int>(), n, 2, 2);
        PII ivld = make_pair(-1, -1);
        auto id5 = vect<PII>(ivld, n, 2, 2);
        if (a[0] > a[1]) {
            dp[1][1][1] = a[0];         

            id5[1][1][1] = make_pair(0, 1);
            dp[1][1][0] = a[0];         

            id5[1][1][0] = make_pair(0, 1);
            dp[1][0][0] = -(n + 1);    

            id5[1][0][0] = make_pair(0, 0);
        } else {
            dp[1][0][1] = -(n + 1);        

            id5[1][0][1] = make_pair(0, 0);
            dp[1][1][0] = -a[0];        

            id5[1][1][0] = make_pair(0, 0);
        }

        for (int i = 2; i < n; i++) {
            int v = a[i];
            PII csta = make_pair(0, 0);
            auto upd = [&](int pos, int sgn, int newval) {
                if (newval < dp[i][pos][sgn]) {
                    dp[i][pos][sgn] = newval;
                    id5[i][pos][sgn] = csta;
                }
            };
            for (int pos = 0; pos < 2; pos++) {
                for (int s = 0; s < 2; s++) if (dp[i - 1][pos][s] < inf<int>()) {
                    csta = make_pair(pos, s);
                    auto oth = dp[i - 1][pos][s];
                    int pre = (s == 0 ? -a[i - 1] : a[i - 1]);
                    int X = max(oth, pre), Y = min(oth, pre);
                    trace(i, pos, s, X, Y);
                    for (int ns = 0; ns < 2; ns++) {
                        int now = (ns == 0 ? -a[i] : a[i]);
                        trace(ns, now);    
                        if (now > X) {
                            upd(0, ns, Y);
                        } else if (now > Y) {
                            upd(1, ns, X);
                        }
                    }
                }
            }

            

            

            

            

            

            


            

            

            


            

            

            

            

            

            

            

            


            

            

            

            

            

            

            

            

            


            

            

            

            

            

            

            

        }


        for (int i = 1; i < n; i++) {
            int v = a[i];
            trace("\n", i, v);
            for (int p = 0; p < 2; p++) {
                for (int s = 0; s < 2; s++) if (dp[i][p][s] < inf<int>()) {
                    auto res = dp[i][p][s];
                    int cur = (s == 0 ? -v : v);
                    trace(p, s);
                    if (p == 0) {
                        cerr << "X: " << cur << " Y: " << res << '\n';
                    } else {
                        cerr << "X: " << res << " Y: " << cur << '\n';
                    }
                }
            }
        }



        PII cur = ivld;
        for (int p = 0; p < 2; p++) for (int s = 0; s < 2; s++) if (dp[n - 1][p][s] < inf<int>()) {
            cur = make_pair(p, s);
        };
        auto LIS = [](vector<int>& b) -> int {
            int n = b.size();
            vector<int> e;
            for (int i = 0; i < n; i++) {
                if (e.empty() || b[i] > e.back()) e.push_back(b[i]);
                else *lower_bound(ALL(e), b[i]) = b[i];
            }
            return SZ(e);
        };









        if (cur == ivld) {
            ou("NO");
            

            

        } else {
            ou("YES");
            vector<int> ans = a;
            for (int i = n - 1; i >= 0; i--) {
                auto [p, s] = cur;
                if (s == 0) ans[i] = -ans[i];
                cur = id5[i][p][s];
            }
            

            

            

            

            

            ou(ans);
        }
    }









    return 0;
}
