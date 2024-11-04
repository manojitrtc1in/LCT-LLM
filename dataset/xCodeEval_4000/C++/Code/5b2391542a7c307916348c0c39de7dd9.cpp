
#include<stdio.h>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#define     LL                      long long int
#define     LD                      long double
#define     ULL                     unsigned long long int


#define     pii                     pair<int, int>
#define     ump                     unordered_map
#define     mp                      make_pair
#define     mt                      make_tuple
#define     pb                      push_back
#define     ff                      first
#define     ss                      second
#define     SZ(x)                   (int)x.size()
#define     all(x)                  x.begin(), x.end()
#define     lb(x, y)                lower_bound(all(x), y)
#define     fill2d(arr, a, b, v)    fill(&arr[0][0], &arr[0][0] + a * b, v)
#define     fill3d(arr, a, b, c, v) fill(&arr[0][0], &arr[0][0] + a * b * c, v)
#define     rep(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define     sp(x)                   setprecision(x) << fixed
#define     what_is(x)              cout << #x << " is " << x << endl


#define     PI                      acos(-1.0)
#define     EPS                     1e-12
#define     mx                      200010
#define     S_SIZE                  2000010


const LL inf = 1000000000;
const LL mod = 1000000000 + 7;


inline void IO() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline int dcmp (LD x) { return x < -EPS ? -1 : (x > EPS); }


template<class T> inline int CHECK(T MASK, int i) { return (MASK >> i) & 1; }
template<class T> inline T ON(T MASK, int i) { return MASK | (T(1) << i); }
template<class T> inline T OFF(T MASK, int i) { return MASK & (~(T(1) << i)); }
template<typename T> inline int CNT(T MASK) {
    if (numeric_limits<T>::digits <= numeric_limits<unsigned int>::digits) return __builtin_popcount(MASK);
    else return __builtin_popcountll(MASK);
}
template<class T> inline int RIGHT(T MASK) { return log2(MASK & -MASK); }


int dx4[] = { 0, 0, -1, +1 }; int dy4[] = { +1, -1, 0, 0 };
int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 }; int dy8[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };


inline void I(int& a) { scanf("%d", &a); } inline void I(LL& a) { scanf("%lld", &a); }
inline void I(ULL& a) { scanf("%llu", &a); } inline void I(char* a) { scanf("%s", a); }
char Iarr[S_SIZE]; inline void I(string& a) { scanf("%s", Iarr); a = Iarr; }
template<typename T1, typename T2>
void I(pair<T1, T2>& a) { I(a.ff); I(a.ss); }
template<typename T>
void I(vector<T>& a) { for (int i = 0; i < SZ(a); i++) I(a[i]); }
template<typename T, typename... Args>
void I(T& a, Args&... args) { I(a); I(args...); }


inline void OUT(int a) { printf("%d", a); } inline void OUT(LL a) { printf("%I64d", a); }
inline void OUT(const char* a) { printf("%s", a); } inline void OUT(char* a) { printf("%s", a); }
inline void OUT(bool a) { printf("%d", a); } inline void OUT(string a) { rep(it, a.begin(), a.end()) printf("%c", *it); }
inline void OUT(ULL a) { printf("%I64u", a); }
template<typename T, typename... Args>
void OUT(T a, Args... args) { OUT(a); OUT(" "); OUT(args...); }
template<typename... Args>
void O(Args... args) { OUT(args...); OUT("\n"); }


template<typename T1, typename T2>
inline ostream& operator<<(ostream& os, pair<T1, T2> p) { os << "{" << p.first << ", " << p.second << "}"; return os; }
template<typename T>
inline ostream& operator<<(ostream& os, vector<T>& a) { os << "["; for (int i = 0; i < (int)a.size(); i++) { if (i) os << ", "; os << a[i]; } os << "]"; return os; }


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};


void faster(auto &unorderedMap, int n) { int num = 2; while (num < n) num *= 2; unorderedMap.reserve(num); unorderedMap.max_load_factor(0.25); }









const int M = 200010; 



int main()
{
    int n;
    I(n);
    unordered_map<LL, int, custom_hash> ump;
    faster(ump, 100000);
    LL sum = 0;
    LL ans = 0;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        deq.push_back(i);
        LL x; I(x);
        sum += x;
        int in = -1;
        if (sum == 0) {
            in = 0;
        }
        if (ump.find(sum) != ump.end()) {
            in = max(in, ump[sum] + 1);
        }
        while (SZ(deq)) {
            if (deq[0] <= in) {
                deq.pop_front();
            }
            else {
                break;
            }
        }
        ump[sum] = i;
        ans += SZ(deq);
    }
    O(ans);

    return 0;
}


















