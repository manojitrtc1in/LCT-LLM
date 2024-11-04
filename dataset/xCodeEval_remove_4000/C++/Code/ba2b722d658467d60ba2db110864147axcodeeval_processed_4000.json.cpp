

















using namespace std;
using namespace __gnu_pbds;






template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
    

}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
























struct ConfigIO {
    ConfigIO() {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);   

    }
} id3;

























template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;







template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

inline long long toint(const string &s) {stringstream ss; ss << s; long long x; ss >> x; return x;}
inline string tostring(long long number) {stringstream ss; ss << number; return ss.str();}
inline string tobin(long long x) {return bitset<63>(x).to_string();}










































const long long INF = 1e18;
const long long fftmod = 998244353;
const long long MOD = fftmod;
const long double PI = acos(-1);
const int N = 1e6 + 10;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        

        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {

        return x % m;

        

        

        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

namespace NTT {
vector<mod_int> roots = {0, 1};
vector<int> bit_reverse;
int max_size = -1;
mod_int root;

bool id4(int n) {
    return (n & (n - 1)) == 0;
}

int id7(int n) {
    while (n & (n - 1))
        n = (n | (n - 1)) + 1;

    return max(n, 1);
}



int get_length(int n) {
    assert(id4(n));
    return __builtin_ctz(n);
}





void id10(int n, vector<mod_int> &values) {
    if ((int) bit_reverse.size() != n) {
        bit_reverse.assign(n, 0);
        int length = get_length(n);

        for (int i = 0; i < n; i++)
            bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
    }

    for (int i = 0; i < n; i++)
        if (i < bit_reverse[i])
            swap(values[i], values[bit_reverse[i]]);
}

void find_root() {
    max_size = 1 << __builtin_ctz(MOD - 1);
    root = 2;

    

    while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
        root++;
}

void id5(int n) {
    if (max_size < 0)
        find_root();

    assert(n <= max_size);

    if ((int) roots.size() >= n)
        return;

    int length = get_length(roots.size());
    roots.resize(n);

    

    

    while (1 << length < n) {
        

        mod_int z = root.pow(max_size >> (length + 1));

        for (int i = 1 << (length - 1); i < 1 << length; i++) {
            roots[2 * i] = roots[i];
            roots[2 * i + 1] = roots[i] * z;
        }

        length++;
    }
}

void id9(int N, vector<mod_int> &values) {
    assert(id4(N));
    id5(N);
    id10(N, values);

    for (int n = 1; n < N; n *= 2)
        for (int start = 0; start < N; start += 2 * n)
            for (int i = 0; i < n; i++) {
                mod_int even = values[start + i];
                mod_int odd = values[start + n + i] * roots[n + i];
                values[start + n + i] = even - odd;
                values[start + i] = even + odd;
            }
}

const int id8 = 150;

vector<mod_int> id6(vector<mod_int> left, vector<mod_int> right) {
    int n = left.size();
    int m = right.size();

    

    if (min(n, m) < id8) {
        const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
        vector<uint64_t> result(n + m - 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);

                if (result[i + j] > ULL_BOUND)
                    result[i + j] %= MOD;
            }

        for (uint64_t &x : result)
            if (x >= MOD)
                x %= MOD;

        return vector<mod_int>(result.begin(), result.end());
    }

    int N = id7(n + m - 1);
    left.resize(N);
    right.resize(N);

    bool equal = left == right;
    id9(N, left);

    if (equal)
        right = left;
    else
        id9(N, right);

    mod_int inv_N = mod_int(N).inv();

    for (int i = 0; i < N; i++)
        left[i] *= right[i] * inv_N;

    reverse(left.begin() + 1, left.end());
    id9(N, left);
    left.resize(n + m - 1);
    return left;
}

vector<mod_int> mod_power(const vector<mod_int> &v, int exponent) {
    assert(exponent >= 0);
    vector<mod_int> result = {1};

    if (exponent == 0)
        return result;

    for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
        result = id6(result, result);

        if (exponent >> k & 1)
            result = id6(result, v);
    }

    return result;
}

vector<mod_int> id1(int l, int r, const vector<vector<mod_int>> &polynomials)
{
    if (l == r)
        return polynomials[l];

    int mid = (l + r) / 2;
    return (id6(id1(l, mid, polynomials), id1(mid + 1, r, polynomials)));
}

vector<mod_int> id0(const vector<vector<mod_int>> &polynomials) {
    if (polynomials.empty())
        return {1};

    

    


    struct compare_size {
        bool operator()(const vector<mod_int> &x, const vector<mod_int> &y) {
            return x.size() > y.size();
        }
    };

    priority_queue<vector<mod_int>, vector<vector<mod_int>>, compare_size> pq;

    for (auto &poly : polynomials)
        pq.push(poly);

    while (pq.size() > 1) {
        vector<mod_int> a = pq.top(); pq.pop();
        vector<mod_int> b = pq.top(); pq.pop();
        pq.push(id6(a, b));
    }

    return pq.top();
}
}









void id2(int testcase)
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int qu;
    cin >> qu;
    while (qu--)
    {
        int t, q;
        cin >> t >> q;
        int temp[n];
        for (int i = 0; i < n; ++i)
            temp[i] = a[i];
        if (t == 1)
        {
            int id, d;
            cin >> id >> d;
            id--;
            temp[id] = d;
        }
        else
        {
            int l, r, d;
            cin >> l >> r >> d;
            l--, r--;
            for (int i = l; i <= r; ++i)
                temp[i] += d;
        }
        int b[n];
        for (int i = 0; i < n; ++i)
            b[i] = q - temp[i];
        vector<vector<mod_int>> poly;
        for (int i = 0; i < n; ++i)
            poly.pb({1, b[i]});
        vector<mod_int> ans = NTT::id0(poly);
        cout << ans[k] << '\n';
    }

    return;
}

int32_t main() {

    rlimit cpu_time {.rlim_cur = 2, .rlim_max = RLIM_INFINITY};
    setrlimit(RLIMIT_CPU, &cpu_time);
    

    int TESTS = 1;
    

    for (int i = 1; i <= TESTS; ++i) {id2(i); if (i != TESTS) cout << '\n';}
    return 0;
}