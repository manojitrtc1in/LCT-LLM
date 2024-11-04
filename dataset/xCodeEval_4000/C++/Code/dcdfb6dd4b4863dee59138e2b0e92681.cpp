#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;



typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;


const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	

	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}


struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
using ld = long double;


typedef pair<ld, ld> LDP;
const ld eps = 1e-10;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}




template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}



template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}
LP operator+(LP a, LP b) {
	return { a.first + b.first,a.second + b.second };
}
LP operator+=(LP& a, LP b) {
	a = a + b; return a;
}
LP operator-(LP a, LP b) {
	return { a.first - b.first,a.second - b.second };
}
LP operator-=(LP& a, LP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";













namespace internal {

    std::vector<int> sa_naive(const std::vector<int>& s) {
        int n = int(s.size());
        std::vector<int> sa(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int l, int r) {
            if (l == r) return false;
            while (l < n && r < n) {
                if (s[l] != s[r]) return s[l] < s[r];
                l++;
                r++;
            }
            return l == n;
            });
        return sa;
    }

    std::vector<int> sa_doubling(const std::vector<int>& s) {
        int n = int(s.size());
        std::vector<int> sa(n), rnk = s, tmp(n);
        std::iota(sa.begin(), sa.end(), 0);
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int x, int y) {
                if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
                int rx = x + k < n ? rnk[x + k] : -1;
                int ry = y + k < n ? rnk[y + k] : -1;
                return rx < ry;
            };
            std::sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            std::swap(tmp, rnk);
        }
        return sa;
    }

    

    

    

    

    template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
    std::vector<int> sa_is(const std::vector<int>& s, int upper) {
        int n = int(s.size());
        if (n == 0) return {};
        if (n == 1) return { 0 };
        if (n == 2) {
            if (s[0] < s[1]) {
                return { 0, 1 };
            }
            else {
                return { 1, 0 };
            }
        }
        if (n < THRESHOLD_NAIVE) {
            return sa_naive(s);
        }
        if (n < THRESHOLD_DOUBLING) {
            return sa_doubling(s);
        }

        std::vector<int> sa(n);
        std::vector<bool> ls(n);
        for (int i = n - 2; i >= 0; i--) {
            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
        }
        std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
        for (int i = 0; i < n; i++) {
            if (!ls[i]) {
                sum_s[s[i]]++;
            }
            else {
                sum_l[s[i] + 1]++;
            }
        }
        for (int i = 0; i <= upper; i++) {
            sum_s[i] += sum_l[i];
            if (i < upper) sum_l[i + 1] += sum_s[i];
        }

        auto induce = [&](const std::vector<int>& lms) {
            std::fill(sa.begin(), sa.end(), -1);
            std::vector<int> buf(upper + 1);
            std::copy(sum_s.begin(), sum_s.end(), buf.begin());
            for (auto d : lms) {
                if (d == n) continue;
                sa[buf[s[d]]++] = d;
            }
            std::copy(sum_l.begin(), sum_l.end(), buf.begin());
            sa[buf[s[n - 1]]++] = n - 1;
            for (int i = 0; i < n; i++) {
                int v = sa[i];
                if (v >= 1 && !ls[v - 1]) {
                    sa[buf[s[v - 1]]++] = v - 1;
                }
            }
            std::copy(sum_l.begin(), sum_l.end(), buf.begin());
            for (int i = n - 1; i >= 0; i--) {
                int v = sa[i];
                if (v >= 1 && ls[v - 1]) {
                    sa[--buf[s[v - 1] + 1]] = v - 1;
                }
            }
        };

        std::vector<int> lms_map(n + 1, -1);
        int m = 0;
        for (int i = 1; i < n; i++) {
            if (!ls[i - 1] && ls[i]) {
                lms_map[i] = m++;
            }
        }
        std::vector<int> lms;
        lms.reserve(m);
        for (int i = 1; i < n; i++) {
            if (!ls[i - 1] && ls[i]) {
                lms.push_back(i);
            }
        }

        induce(lms);

        if (m) {
            std::vector<int> sorted_lms;
            sorted_lms.reserve(m);
            for (int v : sa) {
                if (lms_map[v] != -1) sorted_lms.push_back(v);
            }
            std::vector<int> rec_s(m);
            int rec_upper = 0;
            rec_s[lms_map[sorted_lms[0]]] = 0;
            for (int i = 1; i < m; i++) {
                int l = sorted_lms[i - 1], r = sorted_lms[i];
                int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
                int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
                bool same = true;
                if (end_l - l != end_r - r) {
                    same = false;
                }
                else {
                    while (l < end_l) {
                        if (s[l] != s[r]) {
                            break;
                        }
                        l++;
                        r++;
                    }
                    if (l == n || s[l] != s[r]) same = false;
                }
                if (!same) rec_upper++;
                rec_s[lms_map[sorted_lms[i]]] = rec_upper;
            }

            auto rec_sa =
                sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

            for (int i = 0; i < m; i++) {
                sorted_lms[i] = lms[rec_sa[i]];
            }
            induce(sorted_lms);
        }
        return sa;
    }

}  


std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}









template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
    const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

template<typename T>
struct SegT {
private:
    int sz; vector<T> node;
    vector<int> node2;
    T init_c;
    function<T(T, T)> f;
public:
    SegT(int n, vector<int> v2, T _init_c, function<T(T, T)> _f) {
        assert(n == v2.size());
        init_c = _init_c; f = _f;
        sz = 1;
        while (sz < n)sz *= 2;
        node.resize(2 * sz - 1, init_c);
        node2.resize(2 * sz - 1, mod);
        rep(i, n) {
            node2[i + sz - 1] = v2[i];
        }
        per(i, sz - 1) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
            node2[i] = min(node2[2 * i + 1], node2[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        k += sz - 1;
        node[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)r = sz;
        if (r <= a || b <= l)return init_c;
        else if (a <= l && r <= b)return node[k];
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return f(vl, vr);
        }
    }
    int queryl(int i, int len) {
        int res = init_c;
        int k = i + sz - 1;
        while (k > 0) {
            int cop = k;
            k = (k - 1) / 2;
            if (2 * k + 1 == cop) {
                

            }
            else {
                if (node2[2 * k + 1] >= len) {
                    res = f(res, node[2 * k + 1]);
                }
                else {
                    k = 2 * k + 1; break;
                }
            }
        }
        if (k > 0) {
            while (k < sz - 1) {
                if (node2[2 * k + 2] >= len) {
                    res = f(res, node[2 * k + 2]);
                    k = 2 * k + 1;
                }
                else {
                    k = 2 * k + 2;
                }
            }
        }
        return res;
    }
    int queryr(int i, int len) {
        int res = init_c;
        int k = i + sz - 1;
        if (node2[k] < len)return res;
        while (k > 0) {
            int cop = k;
            k = (k - 1) / 2;
            if (2 * k + 1 == cop) {
                if (node2[2 * k + 2] >= len) {
                    res = f(res, node[2 * k + 2]);
                }
                else {
                    k = 2 * k + 2; break;
                }
            }
            else {
                

            }
        }
        if (k > 0) {
            while (k < sz - 1) {
                if (node2[2 * k + 1] >= len) {
                    res = f(res, node[2 * k + 1]);
                    k = 2 * k + 2;
                }
                else {
                    k = 2 * k + 1;
                }
            }
            res = f(res, node[k]);
        }
        

        return res;
    }
    int querylr(int i, int len) {
        int res = f(queryl(i, len), queryr(i, len));
        return res;
    }
};


void manacher(const string& s, vector<int>& r) {
	r.resize(s.size());
	int i = 0, j = 0;
	while (i < s.size()) {
		while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j])++j;
		r[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < s.size() && k + r[i - k] < j)r[i + k] = r[i - k], ++k;
		i += k; j -= k;
	}
}

void solve() {
	int q; cin >> q;
	vector<string> ords(q);
	vector<char> c(q);
	rep(i, q) {
		cin >> ords[i];
		if (ords[i] == "push")cin >> c[i];
	}
	string al;
	rep(i, q)if (ords[i] == "push")al.push_back(c[i]);
	string tal;
	rep(i, al.size()) {
		if (i > 0)tal.push_back('?');
		tal.push_back(al[i]);
	}
	vector<int>mal;
	manacher(tal, mal);
	vector<int> qr(al.size(), -1);
	vector<int> ql(al.size(), -1);
	int l = 0, r = 0;
	rep(i, q) {
		if (ords[i] == "push") {
			ql[r] = l;
			r++;
		}
		else {
			qr[l] = r-1;
			l++;
		}
	}
    vector<vector<int>> adr(mal.size()), adl(mal.size());
    rep(i, mal.size()) {
        int le = i - mal[i] + 1;
        int ri = i + mal[i] - 1;
        adr[le].push_back(i);
        adl[ri].push_back(i);
    }
    vector<int> lenr(al.size());
    vector<int> lenl(al.size());
    

    int tmp = 0;
    int val = -1;
    rep(i, mal.size()) {
        if ((i + tmp) % 2 == 0) {
            int mid = (i + tmp) / 2;
            if (mid - i + 1 <= mal[mid])chmax(val, mid);
        }
        for (int loc : adr[i]) {
            if (2 * loc - i < tmp)chmax(val, loc);
        }
        if (i % 2 == 0) {
            int id = i / 2;
            if (qr[id] >= 0) {
                int sup = 2 * qr[id];
                while (tmp <= sup) {
                    if ((i + tmp) % 2 == 0) {
                        int mid = (i + tmp) / 2;
                        if (mid - i + 1 <= mal[mid])chmax(val, mid);
                    }
                    tmp++;
                }
                

                assert(i <= val);
                int to = 2 * val - i;
                to /= 2;
                assert(to < al.size());
                lenr[id] = to - id + 1;
            }
        }
    }
    

    val = mal.size();
    tmp = mal.size();
    per(i, mal.size()) {
        if ((i + tmp) % 2 == 0) {
            int mid = (i + tmp) / 2;
            if (i - mid + 1 <= mal[mid])chmin(val, mid);
        }
        for (int loc : adl[i]) {
            if (2 * loc - i >= tmp)chmin(val, loc);
        }
        if (i % 2 == 0) {
            int id = i / 2;
            if (ql[id] >= 0) {
                int low = 2*ql[id];
                while (low < tmp) {
                    tmp--;
                    if ((i + tmp) % 2 == 0) {
                        int mid = (i + tmp) / 2;
                        if (i - mid + 1 <= mal[mid])chmin(val, mid);
                    }
                }
                assert(i >= val);
                int to = 2 * val - i;
                to /= 2;
                assert(to >= 0);
                lenl[id] = id - to + 1;
            }
        }
    }

    vector<int> sa = suffix_array(al);
    vector<int> lcp = lcp_array(al, sa);
    

    lcp.push_back(0);
    vector<int> rev(al.size());
    rep(i, al.size())rev[sa[i]] = i;

    vector<int> incl(al.size()), incr(al.size());
    auto f = [&](int a, int b) {
        return min(a, b);
    };
    SegT<int> stmi(al.size(),lcp, mod, f);
    per(i, al.size()) {
        int loc = rev[i];
        if (qr[i] >= 0) {
            int le = stmi.querylr(loc, lenr[i]);
            

            if (le + lenr[i] - 1 <= qr[i]) {
                incr[i] = 0;
            }
            else {
                incr[i] = 1;
            }
        }
        stmi.update(loc, i);
    }
    auto g = [&](int a, int b) {
        return max(a, b);
    };
    SegT<int> stma(al.size(),lcp, -mod, g);
    vector<vector<int>> qs(al.size());
    rep(i, al.size())if (ql[i] >= 0) {
        qs[i-lenl[i]+1].push_back(i);
    }
    rep(i, al.size()) {
        int loc = rev[i];
        for (int id : qs[i]) {
            int ri = stma.querylr(loc, lenl[id]);
            if (ri >= ql[id]) {
                incl[id] = 0;
            }
            else {
                incl[id] = 1;
            }
        }
        stma.update(loc, i);
    }
    

    

    

    int curans = 0;
    l = 0, r = 0;
    rep(i, q) {
        if (ords[i] == "push") {
            if (incl[r])curans++;
            r++;
        }
        else {
            if (incr[l])curans--;
            l++;
        }
        cout << curans << "\n";
    }
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	

	

	

	

	

	solve();
	return 0;
}

