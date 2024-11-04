#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 998244353;

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
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        

        

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

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
    

    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    inv = {0, 1};
    factorial = inv_factorial = {1, 1};

    maximum = max(maximum, 1);
    inv.resize(maximum + 1);
    factorial.resize(maximum + 1);
    inv_factorial.resize(maximum + 1);

    for (int i = 2; i <= maximum; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i);
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
}

mod_int choose(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
    assert(0 <= k && k <= n);
    return inv_factorial[n] * factorial[n - k];
}

namespace NTT {
    vector<mod_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    mod_int root;

    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    

    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    

    

    void bit_reorder(int n, vector<mod_int> &values) {
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

    void prepare_roots(int n) {
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

    void fft_iterative(int N, vector<mod_int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    mod_int even = values[start + i];
                    mod_int odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    const int FFT_CUTOFF = 150;

    vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
        int n = left.size();
        int m = right.size();

        

        if (min(n, m) < FFT_CUTOFF) {
            static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);

                    if (result[i + j] > U64_BOUND)
                        result[i + j] %= MOD;
                }

            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;

            return vector<mod_int>(result.begin(), result.end());
        }

        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);

        bool equal = left == right;
        fft_iterative(N, left);

        if (equal)
            right = left;
        else
            fft_iterative(N, right);

        mod_int inv_N = mod_int(N).inv();

        for (int i = 0; i < N; i++)
            left[i] *= right[i] * inv_N;

        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }

    vector<mod_int> mod_power(const vector<mod_int> &v, int exponent) {
        assert(exponent >= 0);
        vector<mod_int> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);

            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }

        return result;
    }

    vector<mod_int> mod_multiply_all(const vector<vector<mod_int>> &polynomials) {
        if (polynomials.empty())
            return {1};

        struct compare_size {
            bool operator()(const vector<mod_int> &x, const vector<mod_int> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<mod_int>, vector<vector<mod_int>>, compare_size> pq(polynomials.begin(), polynomials.end());

        while (pq.size() > 1) {
            vector<mod_int> a = pq.top(); pq.pop();
            vector<mod_int> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }

        return pq.top();
    }
}




vector<mod_int> bernoulli;

void prepare_bernoulli(int maximum) {
    bernoulli.resize(maximum + 1);

    for (int m = 0; m <= maximum; m++) {
        bernoulli[m] = 1;

        for (int k = 0; k < m; k++)
            bernoulli[m] -= choose(m, k) * bernoulli[k] * inv[m - k + 1];
    }
}

using polynomial = vector<mod_int>;

mod_int evaluate(const polynomial &poly, mod_int x) {
    mod_int result = 0, power = 1;

    for (int i = 0; i < (int) poly.size(); i++) {
        result += poly[i] * power;
        power *= x;
    }

    return result;
}

polynomial& operator+=(polynomial &a, const polynomial &b) {
    a.resize(max(a.size(), b.size()), 0);

    for (int i = 0; i < (int) b.size(); i++)
        a[i] += b[i];

    return a;
}

polynomial operator+(polynomial a, const polynomial &b) {
    return a += b;
}

polynomial& operator-=(polynomial &a, const polynomial &b) {
    a.resize(max(a.size(), b.size()), 0);

    for (int i = 0; i < (int) b.size(); i++)
        a[i] -= b[i];

    return a;
}

polynomial operator-(polynomial a, const polynomial &b) {
    return a -= b;
}

polynomial& operator*=(polynomial &poly, mod_int mult) {
    for (int i = 0; i < (int) poly.size(); i++)
        poly[i] *= mult;

    return poly;
}

polynomial operator*(polynomial poly, mod_int mult) {
    return poly *= mult;
}

polynomial operator*(mod_int mult, const polynomial &poly) {
    return poly * mult;
}

polynomial operator*(const polynomial &a, const polynomial &b) {
    return NTT::mod_multiply(a, b);
}

polynomial& operator*=(polynomial &a, const polynomial &b) {
    return a = a * b;
}



polynomial sum_of_powers(int k) {
    polynomial result(k + 2, 0);

    

    for (int a = 0; a <= k; a++)
        result[k - a + 1] = bernoulli[a] * inv_factorial[a] * factorial[k] * inv_factorial[k - a + 1];

    return result;
}



polynomial partial_sum(const polynomial &poly) {
    polynomial result(poly.size() + 1, 0);

    if (!poly.empty()) {
        result[1] = poly[0];

        

        result[0] = poly[0];
    }

    

    


    

    

    


    vector<mod_int> a_half(poly.size(), 0);
    vector<mod_int> k_half(poly.size(), 0);

    for (int a = 0; a < (int) poly.size(); a++)
        a_half[a] = bernoulli[a] * inv_factorial[a];

    reverse(a_half.begin(), a_half.end());

    for (int k = 1; k < (int) poly.size(); k++)
        k_half[k] = factorial[k] * poly[k];

    vector<mod_int> product = a_half * k_half;

    for (int i = 1; i <= (int) poly.size(); i++)
        result[i] += product[i + poly.size() - 2] * inv_factorial[i];

    return result;
}

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prepare_factorials(1005);
    prepare_bernoulli(505);

    int N;
    cin >> N;
    vector<int> L(N), R(N);
    mod_int denominator = 1;

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        denominator *= R[i] - L[i] + 1;
    }

    for (int i = 1; i < N; i++)
        R[i] = min(R[i], R[i - 1]);

    for (int i = N - 2; i >= 0; i--)
        L[i] = max(L[i], L[i + 1]);

    for (int i = 0; i < N; i++)
        if (L[i] > R[i]) {
            cout << 0 << '\n';
            return 0;
        }

    L.insert(L.begin(), INF);
    R.insert(R.begin(), INF);

    vector<pair<int, polynomial>> sections = {{0, {1}}, {INF, {0}}};

    for (int i = N; i >= 0; i--) {
        vector<pair<int, polynomial>> new_sections;

        if (L[i] > 0)
            new_sections.emplace_back(L[i] - 1, polynomial({0}));

        int previous = -1;
        mod_int running_sum = 0;

        for (auto &section : sections) {
            if (section.first >= L[i]) {
                int end = min(R[i], section.first);

                mod_int constant = running_sum - evaluate(partial_sum(section.second), previous);
                new_sections.emplace_back(end, partial_sum(section.second) + polynomial({constant}));

                if (section.first >= R[i])
                    break;
            }

            running_sum += evaluate(partial_sum(section.second), section.first) - evaluate(partial_sum(section.second), previous);
            previous = section.first;
        }

        new_sections.emplace_back(INF, polynomial({0}));
        sections = new_sections;

        


        

        

    }

    sections.pop_back();
    mod_int answer = evaluate(sections.back().second, sections.back().first);
    answer /= denominator;
    cout << answer << '\n';
}
