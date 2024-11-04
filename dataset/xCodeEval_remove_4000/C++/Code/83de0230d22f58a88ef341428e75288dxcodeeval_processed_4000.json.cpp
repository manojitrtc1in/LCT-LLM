



































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





inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

inline LL id4(string s) {
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

string id8(const string source, const string find, const string alt) {
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
vector<T> id12(vector<T> vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template<typename T>
void id9(vector<T> &vec, T data) {
    vec.erase(remove(vec.begin(), vec.end(), data), vec.end());
}

template<typename T>
vector<T> id24(vector<T> vec, T data) {
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

vector<smatch> id14(string const &text, regex const &re) {
    vector<smatch> matchs;
    sregex_iterator iter(text.cbegin(), text.cend(), re);
    sregex_iterator end;
    for (; iter != end; iter++) matchs.push_back(*iter);
    return matchs;
}

string id22(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace, regex_constants::format_first_only);
    return result;
}

string id21(string const &text, regex const &re, string const &replace) {
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



int id11(LL num, int n) {
    string str = toString(num);
    return str[str.length() - n] - '0';
}









int id15(const std::string &s) {
    int out = 0;
    for (int i = 0, size = s.size(); i < size; ++i) {
        out *= 2;
        out += ((int) s[i] == 49) ? 1 : 0;
    }
    return out;
}



int id6(const std::string &s) {
    int binary = toInt(s);
    int out = 0;
    for (int i = 0; binary > 0; i++) {
        out = out + (binary % 2) * pow(static_cast<int>(10), i);
        binary = binary / 2;
    }
    return out;
}



int id20(const std::string &s) {
    int out = stoi(s, 0, 16);
    return out;
}



int id7(int in) {
    string str = toString(in);
    return id15(str);
}



int id18(int in) {
    string str = toString(in);
    return id6(str);
}

int id0(int in) {
    string str = toString(in);
    return id20(str);
}



string id13(unsigned int val, bool lower = true) {
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



LL id16(LL bits) {
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}











template<typename T1, typename T2>
inline void S_MAX(T1 &a, T2 b) { a = C_MAX(a, b); };

template<typename T1, typename T2>
inline void S_MIN(T1 &a, T2 b) { a = C_MIN(a, b); };





















































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
bool id17(Iter first, Iter middle, Iter last) {
    reverse(middle, last);
    return next_permutation(first, last);
}









template<class Iter>
bool id3(Iter first1, Iter last1, Iter first2,
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
inline T id19(const T a, const T b, T &x, T &y) {
    if (a < 0) {
        T d = id19(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = id19(a, -b, x, y);
        y = -y;
        return d;
    }
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = id19(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}



template<class T>
inline bool id25(const T x) {
    if (x <= 1)return false;
    for (T i = 2; SQR(i) <= x; i++)if (x % i == 0)return false;
    return true;
}



template<class T>
VB id1(const T n) {
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
VB id1(const T a, const T b) {
    VB small = id1(b);
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
vector<T> id23(T n) {
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
vector<vector<T>> id2(T n) {
    vector<vector<T>> res(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
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



LL id5(LL N, LL P, LL M) {
    if (P == 0) return 1LL;
    if (P % 2 == 0) {
        LL ret = id5(N, P / 2, M);
        return ret * ret % M;
    }
    return N * id5(N, P - 1, M) % M;
}



template<typename T>
inline T NCR(T n, T r) {
    T ans = 1;
    REPLL(i, r) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}



LL id10(LL n, LL r, LL M) {
    if (r > n - r) return id10(n, n - r, M);
    LL numerator = 1LL; 

    LL denominator = 1LL; 

    for (LL i = 0; i < r; i++) {
        numerator *= (n - i);
        numerator %= M;
        denominator *= (i + 1);
        denominator %= M;
    }
    return numerator * id5(denominator, M - 2, M) % M;
}


















constexpr long long INF = 1e12;

vector<vector<long long>> dp;
vector<vector<long long>> ff;

long long f(long long v, long long S, int N, int M, vector<vector<long long>> &a, long long first) {
    if (dp[S][v] != INF)return dp[S][v];
    if (S == ((1 << N) - 1)) {
        long long maxV = INF;
        for (int i = 0; i < M - 1; i++) {
            maxV = min(maxV, abs(a[first][i] - a[v][i + 1]));
        }
        return dp[S][v] = maxV;
    }
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        if (!(S & (1 << i))) {
            int toS = S | (1 << i);
            long long maxV = INF;
            maxV = min(maxV, ff[v][i]);
            ret = max(ret, min(maxV, f(i, toS, N, M, a, first)));
        }
    }
    return dp[S][v] = ret;
}

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> a(N, vector<long long>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];


    

    ff = vector<vector<long long>>(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                long long maxV = INF;
                for (int k = 0; k < M; k++) maxV = min(maxV, abs(a[i][k] - a[j][k]));
                ff[i][j] = maxV;
            }
        }
    }

    


    long long ans = 0;
    for (int i = 0; i < N; i++) {
        dp = vector<vector<long long>>(1 << N, vector<long long>(N, INF));
        ans = max(ans, f(i, 1 << i, N, M, a, i));
    }

    cout << ans << endl;

    return 0;
}

















































