






















































































































































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

inline LL id3(string s) {
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

vector<string> SPRIT(const string &s, const string &delim) {
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

string id6(const string source, const string find, const string alt) {
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
void id7(vector<T> &vec, T data) {
    vec.erase(remove(vec.begin(), vec.end(), data), vec.end());
}

template<typename T>
vector<T> id18(vector<T> vec, T data) {
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

vector<smatch> id11(string const &text, regex const &re) {
    vector<smatch> matchs;
    sregex_iterator iter(text.cbegin(), text.cend(), re);
    sregex_iterator end;
    for (; iter != end; iter++) matchs.push_back(*iter);
    return matchs;
}

string id16(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace, regex_constants::format_first_only);
    return result;
}

string id15(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace);
    return result;
}

template<typename T>
vector<T> COMPRESS(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

template<typename T>
pair<map<T, int>, map<int, T>> MAPPING(const vector<T> v) {
    map<T, int> zip;
    map<int, T> unzip;
    for (int i = 0; i < v.size(); i++) zip[v[i]] = i;
    for (int i = 0; i < v.size(); i++) unzip[i] = v[i];
    return make_pair(zip, unzip);
}

template<typename T>
vector<pair<T, int>> RUN_LENGTH(const vector<T> &v) {
    vector<pair<T, int>> ret;
    int len = v.size();
    for (int i = 0, j = 0; i < len; i = j) {
        while (j < len && v[i] == v[j]) j++;
        ret.push_back(make_pair(v[i], j - i));
    }
    return ret;
}

template<typename T, typename U, typename V, typename W>
auto operator+(const std::pair<T, U> &l, const std::pair<V, W> &r) -> std::pair<decltype(l.first + r.first), decltype(l.second + r.second)> {
    return {l.first + r.first, l.second + r.second};
}

template<typename T, typename U, typename V, typename W>
auto operator-(const std::pair<T, U> &l, const std::pair<V, W> &r) -> std::pair<decltype(l.first - r.first), decltype(l.second - r.second)> {
    return {l.first - r.first, l.second - r.second};
}













double ceil_n(double dIn, long long nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut + 0.9);
    return dOut * pow(10.0, -nLen);
}



double floor_n(double dIn, long long nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut);
    return dOut * pow(10.0, -nLen);
}



double round_n(double dIn, long long nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (long long) (dOut + 0.5);
    return dOut * pow(10.0, -nLen);
}



int id10(LL num, int n) {
    string str = toString(num);
    return str[str.length() - n] - '0';
}

int id4(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}



LL id12(LL bits) {
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}










template<class T1, class T2>
inline bool chmin(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T1, class T2>
inline bool chmax(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}























































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

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
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
bool id13(Iter first, Iter middle, Iter last) {
    reverse(middle, last);
    return next_permutation(first, last);
}









template<class Iter>
bool id2(Iter first1, Iter last1, Iter first2,
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
inline T id14(const T a, const T b, T &x, T &y) {
    if (a < 0) {
        T d = id14(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = id14(a, -b, x, y);
        y = -y;
        return d;
    }
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = id14(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}





template<class T>
inline T INV_MOD(const T a, const T m) {
    T x, y;
    id14(a, m, x, y);
    return (x + m) % m;
}



template<class T>
inline bool id19(const T x) {
    if (x <= 1)return false;
    for (T i = 2; i * i <= x; i++)if (x % i == 0)return false;
    return true;
}



template<class T>
VB id0(const T n) {
    VB arr(n + 1, true);
    arr[0] = arr[1] = false;
    for (T i = 2; i * i <= n; i++) {
        if (arr[i]) {
            for (T j = i * 2LL; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }
    return arr;
}



template<typename T>
VB id0(const T a, const T b) {
    VB small = id0(b);
    VB prime(b - a, true);

    for (T i = 2; i * i <= b; i++) {
        if (small[i]) {
            for (T j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                prime[j - a] = false;
            }
        }
    }

    return prime;
}



template<typename T>
vector<T> id17(T n) {
    vector<T> v;
    for (T i = 1; i * i <= n; ++i) {
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
vector<vector<T>> id1(T n) {
    vector<vector<T>> res(n + 1);
    for (T i = 1; i <= n; i++) {
        for (T j = i; j <= n; j += i) {
            res[j].push_back(i);
        }
    }
    return res;
}



template<typename T>
vector<pair<T, T>> FACTORIZATION(T x) {
    vector<pair<T, LL>> ans;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            T count = 0;
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
    LL ret = 1;
    while (P > 0) {
        if (P & 1LL) ret = (ret * N) % M;
        N = (N * N) % M;
        P >>= 1LL;
    }
    return ret;
}



template<typename T>
inline T NCR(T n, T r) {
    if (r > n - r) r = n - r;
    T ans = 1LL;
    for (T i = 0; i < r; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}



LL id9(LL n, LL r, LL M) {
    if (r > n - r) return id9(n, n - r, M);
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






















int main() {

    int TestCase;
    scanf("%d", &TestCase);

    while (TestCase--) {

        int n;
        scanf("%d", &n);

        

        printf("1 %d ", n - 1);
        printf("1 ");
        for (int i = 2; i <= n; i++) printf("%d ", i);
        fflush(stdout);

        int id8;
        scanf("%d", &id8);

        vector<int> cand(n - 1);
        for (int i = 0; i < n - 1; i++) cand[i] = i + 2;

        for (int query = 0; query < 7; query++) {
            vector<int> left, right;
            for (int i = 0; i < (cand.size() + 1) / 2; i++) left.push_back(cand[i]);
            for (int i = (cand.size() + 1) / 2; i < cand.size(); i++) right.push_back(cand[i]);

            

            printf("1 %d ", left.size());
            printf("1 ");
            for (int i = 0; i < left.size(); i++) printf("%d ", left[i]);
            fflush(stdout);

            int result;
            scanf("%d", &result);

            if (result == id8) cand = left;
            else cand = right;
        }

        int vertex = cand[0];
        

        printf("%d %d ", 1, n - 1);
        printf("%d ", vertex);
        for (int i = 1; i <= n; i++) if (vertex != i) printf("%d ", i);
        fflush(stdout);

        int ans;
        scanf("%d", &ans);

        printf("-1 %d\n", ans);
        fflush(stdout);
    }

    return 0;
}
































































