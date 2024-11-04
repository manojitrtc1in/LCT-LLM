




#include <bits/stdc++.h>
using namespace std;



#define biti(x, i) ((x) & (1 << (i)))  

#define bit1(x, i) (((x) >> (i)) & 1)  

#define bitcnt(x) (__builtin_popcountll(x)) 

#define lastbit(x) ((x) & -(x))
#define fi first
#define se second
#define FR(x) freopen((x), "r", stdin)
#define FW(x) freopen((x), "w", stdout)
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)
#define all(c) ::std::begin(c), ::std::end(c)   

#define rall(c) rbegin(c),rend(c)
#define make_unique(a) a.erase(unique(begin(a),end(a)),end(a))
#define len(x) ((int)x.size())

#define llong long long
#define ldouble long double
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;    

typedef vector<vi> vvi;    

typedef vector<vvi> vvvi;  

#define vv(type, name, n, ...) vector<vector<type>> name(n, vector<type>(__VA_ARGS__));
#define vvv(type, name, m, n, ...) vector<vector<vector<type>>> name(m, vector<vector<type>>(n, vector<type>(__VA_ARGS__)));
#define umap unordered_map
#define uset unordered_set



template<class T> T mod(T a, T m) { return (a % m + m) % m; } 

template<class T> T add(T a, T b, T m) { return mod(a % m + b % m, m); }
template<class T> T mul(T a, T b, T m) { return mod(a % m * b % m, m); }
template<class T> T ceildiv(T a, T b) {  

    return (a + b - 1) / b;
}


template<class T> pair<T, T> divmod(T a, T p) { 

    T q = a / p; 

    return q<0?pair<T, T>{q-1, mod(a, p)}:pair<T, T>{q, mod(a, p)}; 

}
template<class T> T square(T x) { return (T)x * x; }
template<class T> T cube(T x) { return (T)x * x * x; }



inline int offset(int x, int y, int n) { return x * n + y;}
inline int offset(int x, int y, int z, int m, int n) { return x * m * n + y * n + z;}
inline pair<int, int> getxy(int offset, int n) { return {offset / n, offset % n}; }
inline tuple<int, int, int> getxyz(int offset, int m, int n) { return {offset / (m*n), offset % (m*n) / n, offset % (m*n) % n}; }

inline string toupper(string s) {
  int n = len(s);
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string tolower(string s){
  int n = len(s);
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}



inline string to_string(const string &s) { return '"' + s + '"'; }
inline string to_string(const char *s) { return to_string((string) s); }
inline string to_string(bool b) { return (b ? "true" : "false"); } 

inline string to_string(char c) { return "'" + string(1, c) + "'"; }

template<typename T> string to_string(const T &x);


template <size_t N>
string to_string(bitset<N> v) { string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); } return res; }
template<typename A, typename B>
string to_string(const pair<A, B> &x) {return "("+ to_string(x.first) + "," + to_string(x.second) + ")";}  

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template<typename T>
string to_string(const T &v) {int f = 0; string res =  "{"; for (const auto &x: v) (res += (f++ ? "," : "") + to_string(x)); res += "}"; return res;}

#ifdef DEBUG
void debug_out() {cerr << "]\n";} 

template <typename Head, typename... Tail>
void debug_out(Head h, Tail... t) { cerr << to_string(h); if (sizeof...(t)) cerr << ", ", debug_out(t...);}
#define debug(...) cerr  << "(" << #__VA_ARGS__ << ") = (", debug_out(__VA_ARGS__), cerr << ")\n"
#define debug_if(c, x...) if(c) debug(x)  

#define LOG(x...) cerr << __FILE__ << ":" << __LINE__ << " "; debug(x) 

#define ERROR(...) cerr << "\033[31m"; debug(__VA_ARGS__); cerr << "\033[0m";
#define INFO(...) cerr <<"\033[32m"; debug(__VA_ARGS__); cerr <<"\033[0m";"]]]]"
#else
#define debug(...)
#define debug_if(...)
#define LOG(...)
#define ERROR(...)
#define INFO(...)
#endif 





template <class T,
         typename container = vector<T>, 

         const T& (*combine)(const T&, const T&) = std::min<T>, 

         T initValue=INT_MAX
         >
class SegmentTree {
    size_t n;
    container tree;    

    container lazy;    


public:
    SegmentTree(long n): n(n) {
        if (is_same<container, vector<T>>::value) { 

            tree.reserve(4l * n); 

            lazy.reserve(4l * n); 

            for (int i = 0; i < 4l * n; ++i) { 

                tree[i] = lazy[i] = 0;
            }
        }
    }

    SegmentTree(const vector<T> &nums): SegmentTree(nums.size()) { build(1, 0, n, nums); }

    T query(size_t low, size_t high) {
        return query(1, 0, n, low, high);
    }

    void update(size_t low, size_t high, T delta) {
        return update(1, 0, n, low, high, delta);
    }

    size_t upper_bound(size_t l, T v) { 

        size_t low = l + 1, high = n;
        while (low <= high) { 

            size_t mid = low + (high - low) / 2;
            T mn = query(1, 0, n, l, mid);
            if (mn < v) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    void build(size_t v, size_t l, size_t r, const vector<T> &nums) {
        

        

        if (l + 1 == r) {
            tree[v] = nums[l];
            return;
        }
        size_t mid = (l + r) >> 1;
        build(2 * v, l, mid, nums); 

        build(2 * v + 1, mid, r, nums);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }

    T query(size_t v, size_t l, size_t r, size_t low, size_t high) {
        

        if (l == low && high == r) {
            return tree[v];
        } 

        T result = initValue;   

        push(v, l, r);    

        size_t mid = (l + r) >> 1; 

        if (low < mid)
            result = combine(result, query(2 * v, l, mid, low, min(high, mid)));
        if (high > mid)
            result = combine(result, query(2 * v + 1, mid, r, max(low, mid), high));

        return result;
    }

    void update(size_t v, size_t l, size_t r, size_t L, size_t R, T delta) {
        if (l == L && r == R) {
            tree[v] += delta; 

            lazy[v] += delta;           

            return;
        } 

        push(v, l, r);  

        size_t m = l + (r - l) / 2;
        if (L < m) { update(2 * v,     l, m, L, min(m, R), delta); }
        if (R > m) { update(2 * v + 1, m, r, max(L, m), R, delta); }

        tree[v] = combine(tree[2 * v], tree[2 * v + 1]); 

    }

    void push(size_t v, size_t l, size_t r) { 

                                     

        tree[2 * v]     += lazy[v];
        lazy[2 * v]     += lazy[v];  

        tree[2 * v + 1] += lazy[v];
        lazy[2 * v + 1] += lazy[v];  


        lazy[v] = 0;  

    }

    void set(size_t v, size_t l, size_t r, size_t pos, T val) { 

        

        if (l + 1 == r) {
            tree[v] = val;
            return;
        }
        size_t m = l + (r - l) / 2;
        if (pos < m) {
            set(2 * v, l, m, pos, val);
        }
        if (pos >= m) {
            set(2 * v + 1, m, r, pos, val);
        }
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
};

int solveRMQ(vector<int> &arr, long long s) {
    

    

    

    

    

    

    int n = len(arr);
    int l = 0, r = 0;
    int best_r = -1;
    int best_size = 0; 

    vector<long long> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + arr[i];
    

    SegmentTree<long long> st(ps);
    for (l = 0; l < n; ++l) { 

        r = (int)st.upper_bound(l, ps[l] - s); 

        r -=  1 + 1 + 1; 

        if (r - l + 1 > best_size) {
            best_size = r - l + 1;
            best_r = r;
        }
    }
    if (best_size == 0) {
        cout << -1 << endl;
    } else cout << (best_r - best_size + 1 + 1) << " " << (best_r + 1) << endl;

    return 0;
}

int solveSlidingWindow(vector<int> &arr, long long s) {
    

    

    

    

    int n = len(arr);
    int l = 0, r = 0;
    int best_r = -1;
    int best_size = 0; 

    for (; r < n; ++r) {
        

        s += arr[r]; 

        while (l <= r && s < 0) {
            s -= arr[l++];
        }
        if (r - l + 1 > best_size) {
            best_size = r - l + 1;
            best_r = r;
        }
    }
    if (best_size == 0) {
        cout << -1 << endl;
    } else cout << (best_r - best_size + 1 + 1) << " " << (best_r + 1) << endl;

    return 0;
}

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false); 

    std::cin.tie(NULL);

    while(!cin.eof()) {
        int t;
        cin >> t;
        while (t--) {
            int n, s;
            cin >> n >> s;
            if (cin.eof()) break;
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
            

            solveRMQ(arr, s);
        }
    }

    return 0;
}
