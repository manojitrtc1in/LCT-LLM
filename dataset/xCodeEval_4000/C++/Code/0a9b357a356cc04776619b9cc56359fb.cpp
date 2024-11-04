



#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <cctype>
#include <complex>
#include <regex>
#include <unordered_map>


using namespace std;





typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<VVLL> VVVLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;
typedef vector<VS> VVS;
typedef map<int, int> MII;
typedef map<LL, LL> MLL;
typedef map<string, int> MSI;
typedef map<int, string> MIS;





inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

inline LL toLongLong(string s) {
    LL v;
    istringstream sin(s);
    sin >> v;
    return v;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}

template<typename List>
void SPRIT(const std::string &s, const std::string &delim, List &result) {
    result.clear();
    string::size_type pos = 0;
    while (pos != string::npos) {
        string::size_type p = s.find(delim, pos);
        if (p == string::npos) {
            result.push_back(s.substr(pos));
            break;
        } else {
            result.push_back(s.substr(pos, p - pos));
        }
        pos = p + delim.size();
    }
}

vector<string> SPRIT(const std::string &s, const std::string &delim) {
    vector<string> result;
    string::size_type pos = 0;
    while (pos != string::npos) {
        string::size_type p = s.find(delim, pos);
        if (p == string::npos) {
            result.push_back(s.substr(pos));
            break;
        } else {
            result.push_back(s.substr(pos, p - pos));
        }
        pos = p + delim.size();
    }
    return result;
}

string TRIM(const string &str, const char *trimCharacterList = " \t\v\r\n") {
    string result;
    string::size_type left = str.find_first_not_of(trimCharacterList);
    if (left != string::npos) {
        string::size_type right = str.find_last_not_of(trimCharacterList);
        result = str.substr(left, right - left + 1);
    }
    return result;
}

string REPLACE_STRING(const string source, const string find, const string alt) {
    string result = source;
    string::size_type pos = 0;
    while (pos = result.find(find, pos), pos != string::npos) {
        result.replace(pos, find.length(), alt);
        pos += alt.length();
    }
    return result;
}

template<typename T>
bool VECTOR_EXISTS(vector<T> vec, T data) {
    auto itr = std::find(vec.begin(), vec.end(), data);
    size_t index = distance(vec.begin(), itr);
    if (index != vec.size())return true;
    else return false;
}

template<typename T>
vector<T> VECTOR_UNIQUE_ERASE(vector<T> vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template<typename T>
void VECTOR_REMOVE_VALUE_ALL(vector<T> &vec, T data) {
    vec.erase(remove(vec.begin(), vec.end(), data), vec.end());
}

template<typename T>
vector<T> VECTOR_REMOVE_VALUE_ALL_FAST(vector<T> vec, T data) {
    vector<T> vec2;
    for (auto &x: vec) if (x != data) vec2.push_back(x);
    return vec2;
}

bool REG_MATCH(string const &text, regex const &re) {
    bool result = regex_match(text, re);
    return result;
}

bool REG_MATCH(string const &text, smatch &match, regex const &re) {
    bool result = regex_match(text, match, re);
    return result;
}

smatch REG_SEARCH(string const &text, regex const &re) {
    smatch m;
    regex_search(text, m, re);
    return m;
}

vector<smatch> REG_ALL_SEARCH(string const &text, regex const &re) {
    vector<smatch> matchs;
    sregex_iterator iter(text.cbegin(), text.cend(), re);
    sregex_iterator end;
    for (; iter != end; iter++) matchs.push_back(*iter);
    return matchs;
}

string REG_REPLACE(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace, regex_constants::format_first_only);
    return result;
}

string REG_ALL_REPLACE(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace);
    return result;
}

template<typename T, typename U, typename V, typename W>
auto operator+(const std::pair<T, U> &l, const std::pair<V, W> &r) -> std::pair<decltype(l.first + r.first), decltype(l.second + r.second)> {
    return {l.first + r.first, l.second + r.second};
}

template<typename T, typename U, typename V, typename W>
auto operator-(const std::pair<T, U> &l, const std::pair<V, W> &r) -> std::pair<decltype(l.first - r.first), decltype(l.second - r.second)> {
    return {l.first - r.first, l.second - r.second};
}

#define UPPER(s) transform((s).begin(), (s).end(), (s).begin(), ::toupper)
#define LOWER(s) transform((s).begin(), (s).end(), (s).begin(), ::tolower)










double ceil_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut + 0.9);
    return dOut * pow(10.0, -nLen);
}



double floor_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut);
    return dOut * pow(10.0, -nLen);
}



double round_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut + 0.5);
    return dOut * pow(10.0, -nLen);
}



int take_a_n(LL num, int n) {
    string str = toString(num);
    return str[str.length() - n] - '0';
}



LL bitcount64(LL bits) {
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}







#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define C_MIN(a, b) ((a)<(b)?(a):(b))
#define C_ABS(a, b) ((a)<(b)?(b)-(a):(a)-(b))

template<typename T1, typename T2>
inline void S_MAX(T1 &a, T2 b) { a = C_MAX(a, b); };

template<typename T1, typename T2>
inline void S_MIN(T1 &a, T2 b) { a = C_MIN(a, b); };






#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i, arr) for(typeof((arr).begin()) i=(arr).begin(); i!=(arr).end(); ++i)
#define EXIST(str, e) ((str).find(e)!=(str).end())
#define COUNT(arr, v) count((arr).begin(), (arr).end(), v)
#define SEARCH(v, w) search((v).begin(), (v).end(), (w).begin(), (w).end())
#define B_SEARCH(arr, v) binary_search((arr).begin(), (arr).end(), v)
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define ROTATE_LEFT(arr, c) rotate((arr).begin(), (arr).begin()+(c), (arr).end())
#define ROTATE_RIGHT(arr, c) rotate((arr).rbegin(), (arr).rbegin() + (c), (arr).rend())
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define SUMS(arr) accumulate((arr).begin(), (arr).end(), string())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define OF_ALL(arr, func) all_of((arr).begin(), (arr).end(), (func))
#define OF_NONE(arr, func) none_of((arr).begin(), (arr).end(), (func))
#define OF_ANY(arr, func) any_of((arr).begin(), (arr).end(), (func))
#define PB push_back
#define MP make_pair
#define ft first
#define sd second







#define GL(s) getline(cin, (s))
#define INIT() std::ios::sync_with_stdio(false);std::cin.tie(0);
#define OUT(d) std::cout<<(d)
#define OUT_L(d) std::cout<<(d)<<endl
#define FOUT(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)
#define FOUT_L(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)<<"\n"
#define EL() printf("\n")
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define YES() printf("YES\n")
#define NO() printf("NO\n")


template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}








#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORLL(i, a, b) for(LL i=LL(a);i<LL(b);++i)
#define RFORLL(i, a, b) for(LL i=LL(b)-1;i>=LL(a);--i)
#define REPLL(i, n) for(LL i=0;i<LL(n);++i)
#define RREPLL(i, n) for(LL i=LL(n)-1;i>=0;--i)
#define FOREACH(x, arr) for(auto &(x) : (arr))
#define FORITER(x, arr) for(auto (x) = (arr).begin(); (x) != (arr).end(); ++(x))






const double EPS = 1e-10;
const double PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};









template<typename T>
inline bool BETWEEN(const T aim, const T min, const T max) {
    if (min <= aim && aim <= max) {
        return true;
    } else {
        return false;
    }
}

template<typename T1, typename T2>
inline bool IS_OUT(const T1 toY, const T1 toX, const T2 H, const T2 W) {
    return (toY < 0 || toY >= H || toX < 0 || toX >= W);
}

template<class T>
inline T SQR(const T x) { return x * x; }

template<class T1, class T2>
inline T1 POW(const T1 x, const T2 y) {
    if (!y)return 1;
    else if ((y & 1) == 0) {
        return SQR(POW(x, y >> 1));
    } else return POW(x, y ^ 1) * x;
}


template<typename T>
constexpr T ABS(T x) {
    return x < 0 ? -x : x;
}









template<class Iter>
bool next_partial_permutation(Iter first, Iter middle, Iter last) {
    reverse(middle, last);
    return next_permutation(first, last);
}









template<class Iter>
bool next_combination(Iter first1, Iter last1, Iter first2,
                      Iter last2) {
    if ((first1 == last1) || (first2 == last2)) {
        return false;
    }
    Iter m1 = last1;
    Iter m2 = last2;
    --m2;
    while (--m1 != first1 && !(*m1 < *m2)) {
    }
    bool result = (m1 == first1) && !(*first1 < *m2);
    if (!result) {
        while (first2 != m2 && !(*m1 < *first2)) {
            ++first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++first1;
        ++first2;
    }
    if ((first1 != last1) && (first2 != last2)) {
        m1 = last1;
        m2 = first2;
        while ((m1 != first1) && (m2 != last2)) {
            std::iter_swap(--m1, m2);
            ++m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return !result;
}









template<typename T>
constexpr bool ODD(T x) {
    return x % 2 != 0;
}

template<typename T>
constexpr bool EVEN(T x) {
    return x % 2 == 0;
}



template<class T>
inline T GCD(const T x, const T y) {
    if (x < 0)return GCD(-x, y);
    if (y < 0)return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}



template<class T>
inline T LCM(const T x, const T y) {
    if (x < 0)return LCM(-x, y);
    if (y < 0)return LCM(x, -y);
    return x * (y / GCD(x, y));
}





template<class T>
inline T EXTGCD(const T a, const T b, T &x, T &y) {
    if (a < 0) {
        T d = EXTGCD(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = EXTGCD(a, -b, x, y);
        y = -y;
        return d;
    }
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = EXTGCD(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}



template<class T>
inline bool ISPRIME(const T x) {
    if (x <= 1)return false;
    for (T i = 2; i * i <= x; i++)if (x % i == 0)return false;
    return true;
}



template<class T>
VB ERATOSTHENES(const T n) {
    VB arr(n + 1, true);
    arr[0] = arr[1] = false;
    for (LL i = 2; i * i <= n; i++) {
        if (arr[i]) {
            for (LL j = i * 2LL; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }
    return arr;
}



template<typename T>
VB ERATOSTHENES(const T a, const T b) {
    VB small = ERATOSTHENES(b);
    VB prime(b - a, true);

    for (LL i = 2; i * i <= b; i++) {
        if (small[i]) {
            for (LL j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                prime[j - a] = false;
            }
        }
    }

    return prime;
}



template<typename T>
vector<T> DIVISOR(T n) {
    vector<T> v;
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}



template<typename T>
vector<vector<T>> DIVISOR_ALL(T n) {
    vector<vector<T>> res(n + 1);
    for (LL i = 1; i <= n; i++) {
        for (LL j = i; j <= n; j += i) {
            res[j].push_back(i);
        }
    }
    return res;
}



template<typename T>
vector<pair<T, LL>> FACTORIZATION(T x) {
    vector<pair<T, LL>> ans;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            LL count = 0;
            while (x % i == 0) {
                count++;
                x /= i;
            }
            ans.push_back(MP(i, count));
        }
    }
    if (x != 1) ans.push_back(MP(x, 1));
    return ans;
}



LL POW_MOD(LL N, LL P, LL M) {
    if (P == 0) return 1LL;
    if (P % 2 == 0) {
        LL ret = POW_MOD(N, P / 2, M);
        return ret * ret % M;
    }
    return N * POW_MOD(N, P - 1, M) % M;
}



template<typename T>
inline T NCR(T n, T r) {
    if (r > n - r) r = n - r;
    T ans = 1;
    REPLL(i, r) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}



LL NCR_MOD(LL n, LL r, LL M) {
    if (r > n - r) return NCR_MOD(n, n - r, M);
    LL numerator = 1LL; 

    LL denominator = 1LL; 

    for (LL i = 0; i < r; i++) {
        numerator *= (n - i);
        numerator %= M;
        denominator *= (i + 1);
        denominator %= M;
    }
    return numerator * POW_MOD(denominator, M - 2, M) % M;
}








#define CLR(arr, d) memset((arr), (d),sizeof(arr))



#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " "  << endl;




int main() {

    int n;
    cin >> n;

    VS S(n);
    cin >> S;

    VS ans(n);
    ans[n - 1] = S[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (S[i] <= ans[i + 1]) ans[i] = S[i];
        else {
            int p = 0;
            while (p < S[i].size() && p < ans[i + 1].size() && S[i][p] == ans[i + 1][p])p++;
            S[i].resize(p);
            ans[i] = S[i];
        }
    }

    for (int i = 0; i < n; i++) printf("%s\n", ans[i].c_str());

    return 0;
}










































