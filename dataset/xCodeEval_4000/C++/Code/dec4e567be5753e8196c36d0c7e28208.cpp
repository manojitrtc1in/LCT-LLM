

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll MAXM = 35;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; 


constexpr ll base = 1000000000;
constexpr ll base_digits = 9;

struct bigint {
    

    vector<ll> z; 


    

    

    ll sign;

    bigint() : sign(1) {}

    bigint(long long v) { *this = v; }

    bigint &operator=(long long v) {
        sign = v < 0 ? -1 : 1;
        v *= sign;
        z.clear();
        for (; v > 0; v = v / base) z.push_back((ll) (v % base));
        return *this;
    }

    bigint(const string &s) { read(s); }

    bigint &operator+=(const bigint &other) {
        if (sign == other.sign) {
            for (ll i = 0, carry = 0; i < other.z.size() || carry; ++i) {
                if (i == z.size())
                    z.push_back(0);
                z[i] += carry + (i < other.z.size() ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry)
                    z[i] -= base;
            }
        } else if (other != 0 ) {
            *this -= -other;
        }
        return *this;
    }

    friend bigint operator+(bigint a, const bigint &b) { return a += b; }

    bigint &operator-=(const bigint &other) {
        if (sign == other.sign) {
            if (sign == 1 && *this >= other || sign == -1 && *this <= other) {
                for (ll i = 0, carry = 0; i < other.z.size() || carry; ++i) {
                    z[i] -= carry + (i < other.z.size() ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry)
                        z[i] += base;
                }
                trim();
            } else {
                *this = other - *this;
                this->sign = -this->sign;
            }
        } else {
            *this += -other;
        }
        return *this;
    }

    friend bigint operator-(bigint a, const bigint &b) { return a -= b; }

    bigint &operator*=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = 0, carry = 0; i < z.size() || carry; ++i) {
            if (i == z.size())
                z.push_back(0);
            long long cur = (long long) z[i] * v + carry;
            carry = (ll) (cur / base);
            z[i] = (ll) (cur % base);
        }
        trim();
        return *this;
    }

    bigint operator*(ll v) const { return bigint(*this) *= v; }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        ll norm = base / (b1.z.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.z.resize(a.z.size());

        for (ll i = (ll) a.z.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.z[i];
            ll s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
            ll s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
            ll d = (ll) (((long long) s1 * base + s2) / b.z.back());
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.z[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return {q, r / norm};
    }

    friend bigint sqrt(const bigint &a1) {
        bigint a = a1;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        ll n = a.z.size();

        ll firstDigit = (ll) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        ll norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
        firstDigit = (ll) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        ll q = firstDigit;
        bigint res;

        for (ll j = n / 2 - 1; j >= 0; j--) {
            for (;; --q) {
                bigint r1 = (r - (res * 2 * base + q) * q) * base * base +
                            (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0) {
                ll d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
                ll d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
                ll d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
                q = (ll) (((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2));
            }
        }

        res.trim();
        return res / norm;
    }

    bigint operator/(const bigint &v) const { return divmod(*this, v).first; }

    bigint operator%(const bigint &v) const { return divmod(*this, v).second; }

    bigint &operator/=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = (ll) z.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = z[i] + rem * (long long) base;
            z[i] = (ll) (cur / v);
            rem = (ll) (cur % v);
        }
        trim();
        return *this;
    }

    bigint operator/(ll v) const { return bigint(*this) /= v; }

    ll operator%(ll v) const {
        if (v < 0) v = -v;
        ll m = 0;
        for (ll i = (ll) z.size() - 1; i >= 0; --i)
            m = (ll) ((z[i] + m * (long long) base) % v);
        return m * sign;
    }

    bigint &operator*=(const bigint &v) { return *this = *this * v; }

    bigint &operator/=(const bigint &v) { return *this = *this / v; }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (z.size() != v.z.size())
            return z.size() * sign < v.z.size() * v.sign;
        for (ll i = (ll) z.size() - 1; i >= 0; i--)
            if (z[i] != v.z[i])
                return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const { return v < *this; }

    bool operator<=(const bigint &v) const { return !(v < *this); }

    bool operator>=(const bigint &v) const { return !(*this < v); }

    bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }

    bool operator!=(const bigint &v) const { return *this < v || v < *this; }

    void trim() {
        while (!z.empty() && z.back() == 0) z.pop_back();
        if (z.empty()) sign = 1;
    }

    bool isZero() const { return z.empty(); }

    friend bigint operator-(bigint v) {
        if (!v.z.empty()) v.sign = -v.sign;
        return v;
    }

    bigint abs() const {
        return sign == 1 ? *this : -*this;
    }

    long long longValue() const {
        long long res = 0;
        for (ll i = (ll) z.size() - 1; i >= 0; i--)
            res = res * base + z[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }

    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        z.clear();
        ll pos = 0;
        while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (ll i = (ll) s.size() - 1; i >= pos; i -= base_digits) {
            ll x = 0;
            for (ll j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (ll i = (ll) v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }

    static vector<ll> convert_base(const vector<ll> &a, ll old_digits, ll new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (ll i = 1; i < p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<ll> res;
        long long cur = 0;
        ll cur_digits = 0;
        for (ll v : a) {
            cur += v * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(ll(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((ll) cur);
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        ll n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (ll i = 0; i < n; i++)
                for (ll j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        ll k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (ll i = 0; i < k; i++)
            a2[i] += a1[i];
        for (ll i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (ll i = 0; i < a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (ll i = 0; i < a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (ll i = 0; i < r.size(); i++)
            res[i + k] += r[i];
        for (ll i = 0; i < a1b1.size(); i++)
            res[i] += a1b1[i];
        for (ll i = 0; i < a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<ll> a6 = convert_base(this->z, base_digits, 6);
        vector<ll> b6 = convert_base(v.z, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (ll i = 0, carry = 0; i < c.size(); i++) {
            long long cur = c[i] + carry;
            res.z.push_back((ll) (cur % 1000000));
            carry = (ll) (cur / 1000000);
        }
        res.z = convert_base(res.z, 6, base_digits);
        res.trim();
        return res;
    }

};

ll add(ll a, ll b) {
    return min(INF, a + b);
}

ll mult(ll a, ll b) {
    if ((INF + b - 1) / b <= a) return INF;
    return a * b;
}

ll n, k, A[MAXN], C[MAXM][MAXN];

ll c(ll r, ll n) {
    bigint ans = 1;
    for (ll i = 0; i < r; i++) ans = ans * (n - i), ans = ans / (i + 1);
    if (ans >= INF) return INF;
    return ans.longValue();
}

ll check(ll x) {
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum = add(sum, mult(A[i], (n >= 70 ? C[x - 1][n + x - i - 2] : c(n - i - 1, n + x - i - 2))));
    }
    return sum >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(C[0], C[0] + MAXN, 1);
    for (ll i = 1; i < MAXM; i++) {
        for (ll j = 1; j < MAXN; j++) {
            C[i][j] = add(C[i - 1][j - 1], C[i][j - 1]);
        }
    }

    cin >> n >> k;
    ll first = INF;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 0) first = min(first, i);
    }
    n -= first;
    for (ll i = 0; i < n; i++) A[i] = A[i + first];
    if (*max_element(A, A + n) >= k) return cout << 0 << endl, 0;
    if (n >= 70) {
        for (ll i = 1; i < MAXM; i++) if (check(i)) return cout << i << endl, 0;
    }

    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;


    return 0;
}
