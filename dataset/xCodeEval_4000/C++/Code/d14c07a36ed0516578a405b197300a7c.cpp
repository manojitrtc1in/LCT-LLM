



#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
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

string TRIM(const string &str, const char *trimCharacterList = " \t\v\r\n") {
    string result;
    string::size_type left = str.find_first_not_of(trimCharacterList);
    if (left != string::npos) {
        string::size_type right = str.find_last_not_of(trimCharacterList);
        result = str.substr(left, right - left + 1);
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

#define UPPER(s) transform((s).begin(), (s).end(), (s).begin(), ::toupper)
#define LOWER(s) transform((s).begin(), (s).end(), (s).begin(), ::tolower)










double ceil_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut + 0.9);
    return dOut * pow(10.0, -nLen);
}



double floor_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut);
    return dOut * pow(10.0, -nLen);
}



double round_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut + 0.5);
    return dOut * pow(10.0, -nLen);
}



int take_a_n(LL num, int n) {
    string str = toString(num);
    return str[str.length() - n] - '0';
}









int strbase_2to10(const std::string &s) {
    int out = 0;
    for (int i = 0, size = s.size(); i < size; ++i) {
        out *= 2;
        out += ((int) s[i] == 49) ? 1 : 0;
    }
    return out;
}



int strbase_10to2(const std::string &s) {
    int binary = toInt(s);
    int out = 0;
    for (int i = 0; binary > 0; i++) {
        out = out + (binary % 2) * pow(static_cast<int>(10), i);
        binary = binary / 2;
    }
    return out;
}



int strbase_16to10(const std::string &s) {
    int out = stoi(s, 0, 16);
    return out;
}



int intbase_2to10(int in) {
    string str = toString(in);
    return strbase_2to10(str);
}



int intbase_10to2(int in) {
    string str = toString(in);
    return strbase_10to2(str);
}

int intbase_16to10(int in) {
    string str = toString(in);
    return strbase_16to10(str);
}



string intbase_10to16(unsigned int val, bool lower = true) {
    if (!val)
        return std::string("0");
    std::string str;
    const char hc = lower ? 'a' : 'A';     

    while (val != 0) {
        int d = val & 15;     

        if (d < 10)
            str.insert(str.begin(), d + '0');  

        else 

            str.insert(str.begin(), d - 10 + hc);
        val >>= 4;
    }
    return str;
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
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define SUMS(arr) accumulate((arr).begin(), (arr).end(), string())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define PB push_back
#define MP make_pair








#define GL(s) getline(cin, (s))
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define OUT(d) std::cout<<(d)
#define OUT_L(d) std::cout<<(d)<<endl
#define FOUT(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)
#define FOUT_L(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)<<"\n"
#define EL() std::cout << "\n"
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
#define Yes() std::cout << "Yes" << "\n"
#define No() std::cout << "No" << "\n"
#define YES() std::cout << "YES" << "\n"
#define NO() std::cout << "NO" << "\n"


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
const int MOD = 1000000007;













template<typename T>
inline bool BETWEEN(const T aim, const T min, const T max) {
    if (min <= aim && aim <= max) {
        return true;
    } else {
        return false;
    }
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
    for (T i = 2; SQR(i) <= x; i++)if (x % i == 0)return false;
    return true;
}



template<class T>
VB ERATOSTHENES(const T n) {
    VB arr(n, true);
    for (int i = 2; SQR(i) < n; i++) {
        if (arr[i]) {
            for (int j = 0; i * (j + 2) < n; j++) {
                arr[i * (j + 2)] = false;
            }
        }
    }
    return arr;
}



template<typename T>
VB ERATOSTHENES(const T a, const T b) {
    VB small = ERATOSTHENES(b);
    VB prime(b - a, true);

    for (int i = 2; (T) (SQR(i)) < b; i++) {
        if (small[i]) {
            for (T j = max(2, (a + i - 1) / i) * i; j < b; j += i) {
                prime[j - a] = false;
            }
        }
    }

    return prime;
}



template<typename T>
vector<T> DIVISOR(T n) {
    vector<T> v;
    for (int i = 1; i * i <= n; ++i) {
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
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            res[j].push_back(i);
        }
    }
    return res;
}



template<typename T>
inline T NCR(T n, T r) {
    T ans = 1;
    REPLL(i, r) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}









#define CLR(arr, d) memset((arr), (d),sizeof(arr))



#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;




int main() {

    int N;
    cin >> N;
    VI a(N);
    for(int i=0;i<N;i++) {
        scanf("%d", &a[i]);
    }

    int M;
    cin >> M;
    VI b(M);
    for(int i=0;i<M;i++) scanf("%d", &b[i]);

    LL sumA = accumulate(ALL(a), 0LL);
    LL sumB = accumulate(ALL(b), 0LL);

    if (sumA != sumB) {
        OUT_L(-1);
        return 0;
    }

    int pA = 0;
    int pB = 0;
    LL sA = 0;
    LL sB = 0;
    int ans = 0;
    while (true) {
        if (pA == N && pB == M) {
            ans++;
            break;
        }
        if (sA == sB && sA != 0 && sB != 0) {
            ans++;
            sA = 0;
            sB = 0;
            continue;
        }
        if (sA <= sB) {
            sA += a[pA];
            pA++;
        } else {
            sB += b[pB];
            pB++;
        }
    }

    OUT_L(ans);

    return 0;
}




























