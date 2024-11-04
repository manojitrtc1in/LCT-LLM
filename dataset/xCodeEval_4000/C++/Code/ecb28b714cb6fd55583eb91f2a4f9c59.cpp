#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>

#include <string>
#include <sstream>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

#include <limits.h>

#include <unordered_set>
#include <unordered_map>

#include<stdint.h>

using namespace std;



#pragma comment(linker, "/STACK:16777216")



#define llong long long
#define ulong unsigned long long
#define ushort unsigned short
#define uint unsigned int
typedef pair<short, short> PSS;
typedef pair<ulong, ulong> PUU;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;




#define REP(i,n) for(i=0; i<n; ++i)
#define REP2(i,from, to) for(i=from; i<to; ++i)



const double EPS = 1e-7;

double iround(const double a) {
    return floor(a + 0.5);
}

double iabs(const double a){
    return (a<-EPS) ? -a : a;
}

double imin(const double a, const double b){
    return (a - b > EPS) ? b : a;
}

double imax(const double a, const double b) {
    return (a - b > EPS) ? a : b;
}

template<class I>
I iabs(const I a) {
    return (a<0) ? -a : a;
}

template<class I>
I imin(const I a, const I b) {
    return (a<b) ? a : b;
}

template<class I>
I imax(const I a, const I b) {
    return (a<b) ? b : a;
}

template <class I>
inline I mod_pow(const I& x, const llong p, const I& m) {
    if (p == 0)return 1;
    I mult = (p & 1) ? x : 1;
    I t = mod_pow(x, p / 2, m) % m;
    return (((mult * t) % m) * t) % m;
}

template <class T>
inline T ipow(const T& x, const llong p) {
    if (p == 0)return 1;
    T mult = (p & 1) ? x : 1;
    T h = ipow(x, p / 2);
    return h*h*mult;
}

ulong gcd(const ulong a, const ulong b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

template<class T>
T next_power_of_two(T v) {
    if (v<0)return 0;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v++;
    return v;
}

string bin(unsigned int i) {
    string res = "";
    while (i != 0){
        res += ('0' + (i % 2));
        i = i / 2;
    }
    return string(res.rbegin(), res.rend());
}



template<int SIZE>
class DSU {
public:
    int parent[SIZE]; 

    int rank[SIZE]; 

    int count; 


    void clear() {
        for (int i = 0; i<SIZE; i++) {
            this->parent[i] = -1;
            this->rank[i] = 0;
        }
        this->count = 0;
    }

    DSU() {
        this->clear();
    }

    void make(int x) {
        this->parent[x] = x;
        this->rank[x] = 1;
        this->count++;
    }

    bool in_a_set(int x) {
        return this->parent[x] != -1;
    }

    int find(int x) {
        if (x == this->parent[x])return x;
        return this->parent[x] = find(this->parent[x]);
    }

    void combine(int x, int y) {
        x = this->find(x);
        y = this->find(y);
        if (x != y){
            if (this->rank[x] > this->rank[y])
                this->parent[x] = y;
            else this->parent[y] = x;
        }
    }
};

class BigInt {
public:
    const static unsigned int N = 4000;
    const static unsigned int base = 10;
    unsigned int len;
    short sign;
    unsigned int digits[N];

    BigInt(const BigInt& bi) {
        this->len = bi.len;
        this->sign = bi.sign;
        for (unsigned int i = 0; i<this->len; ++i) (*this)[i] = bi[i];
    }

    BigInt(llong n) {
        this->len = 0;
        this->sign = (n >= 0) ? 1 : -1;
        this->digits[0] = 0;
        while (n) {
            this->digits[this->len] = n % this->base;
            n /= this->base;
            this->len++;
        }
        if (this->len == 0)this->len = 1;
    }

    BigInt() : BigInt(0) {
    }

    BigInt(string s) {
        this->sign = (s[0] == '-') ? 1 : -1;
        this->digits[0] = 0;
        if (s[0] == '-')s = s.substr(1, s.length() - 1);
        this->len = s.length();
        for (unsigned int i = 0; i<this->len; i++)
            (*this)[i] = s[this->len - i - 1] - '0';
    }

    string toString() const{
        

        

        stringstream ss;
        for (int i = this->len - 1; i >= 0; --i) ss << (int)(*this)[i];
        return ss.str();
    }

    unsigned int& operator[](const unsigned int i){
        

        

        return digits[i];
    }

    unsigned int operator[](const unsigned int i) const{
        

        if (i<this->len)return this->digits[i];
        return 0;
    }

    bool iszero() const {
        if (this->len <= 1 && this->digits[0] == 0) return true;
        return false;
    }

    BigInt& operator= (const BigInt& rval) {
        if (this != &rval) {
            this->len = rval.len;
            this->sign = rval.sign;
            for (unsigned int i = 0; i<this->len; ++i)
                (*this)[i] = rval[i];
        }
        return *this;
    }

    BigInt operator+ (const BigInt& rhs) const{
        BigInt s(0);
        unsigned long long r = 0, d, i;
        for (i = 0; i<max(this->len, rhs.len); i++) {
            d = (*this)[i] + rhs[i] + r;
            r = d / this->base;
            s[i] = d % this->base;
        }
        s.len = max(this->len, rhs.len);
        if (r)
            s[s.len++] = r;
        return s;
    }

    BigInt operator+ (unsigned long long rhs) const{
        BigInt s(*this);
        unsigned long long r = 0, d, i = 0;
        while (rhs != 0 || r != 0) {
            d = s[i] + (rhs % s.base) + r;
            rhs /= s.base;
            r = d / s.base;
            s[i] = d % s.base;
            i++;
        }
        if (i>s.len) s.len = i;
        return s;
    }

    BigInt operator* (unsigned long long rhs) const{
        

        if (rhs == 0) return BigInt(0);

        BigInt s(*this);
        unsigned long long r = 0, d, i;
        for (i = 0; i<s.len; ++i) {
            d = s[i] * rhs + r;
            r = d / this->base;
            s[i] = d % this->base;
        }
        while (r) s[s.len++] = r % this->base, r /= this->base;
        return s;
    }

    BigInt operator* (const BigInt& rhs) const {
        BigInt s(0);
        if (rhs.iszero())return s;
        unsigned long long r, d, i, j, k;
        for (i = 0; i < this->N; i++) s[i] = 0;
        for (i = 0; i < this->len; i++) {
            r = 0;
            for (j = 0, k = i; j<rhs.len; j++, k++) {
                d = (*this)[i] * rhs[j] + r + s[k];
                r = d / this->base;
                s[k] = d % this->base;
            }
            while (r)s[k++] = r % this->base, r /= this->base;
            if (k>s.len) s.len = k;
        }
        while (s.len>1 && s[s.len - 1] == 0)s.len--;
        return s;
    }

    unsigned int operator% (unsigned int rhs) {
        BigInt t(*this);
        unsigned long long pow = 1;
        unsigned long long mod = 0;
        for (unsigned int i = 0; i<this->len && pow != 0; i++) {
            mod = (((*this)[i] % rhs) * pow + mod) % rhs;
            pow = (pow * this->base) % rhs;
        }
        return mod;
    }
};

template <int N>
class SegmentTreeSum {
private:
    llong t[4 * N];
    uint R;

    void _Build(int a[], uint v, uint l, uint r) {
        if (l == r)this->t[v] = a[l];
        else{
            uint m = (l + r) / 2;
            this->_Build(a, 2 * v, l, m);
            this->_Build(a, 2 * v + 1, m + 1, r);
            this->t[v] = this->t[2 * v] + this->t[2 * v + 1];
        }
    }

    int _Sum(int v, uint l, uint r, uint tl, uint tr) {
        if (l>r)return 0;
        if (tl == l && tr == r) return this->t[v];
        int res = 0;
        uint tm = (tl + tr) / 2;
        res += this->_Sum(2 * v, l, imin(r, tm), tl, tm);
        res += this->_Sum(2 * v + 1, imax(l, tm + 1), r, tm + 1, tr);
        return res;
    }

    void _Update(uint i, uint v, uint tl, uint tr, int x) {
        if (tl == tr)this->t[v] = x;
        else {
            uint tm = (tl + tr) / 2;
            if (i <= tm) this->_Update(i, 2 * v, tl, tm, x);
            else this->_Update(i, 2 * v + 1, tm + 1, tr, x);
            this->t[v] = this->t[2 * v] + this->t[2 * v + 1];
        }
    }

public:
    SegmentTreeSum(int a[], uint count) {
        int b[4 * N];
        uint i = 0;
        this->R = next_power_of_two(count);
        while (i<count)b[i + 1] = a[i], i++;
        while (i<R)b[++i] = 0;
        this->_Build(b, 1, 1, R);
    }

    int Sum(int l, int r) {
        return this->_Sum(1, l, r, 1, this->R);
    }

    void Update(uint i, int x) {
        this->_Update(i, 1, 1, this->R, x);
    }

    void print() {
        for (uint i = 1; i <= 2 * this->R; ++i) cout << this->t[i] << " ";
        cout << endl;
    }
};

template<int N, class T, T operation(T op1, T op2), T neutral>
class SegmentTree {
private:
    T t[4 * N]; 

    uint R; 

    


    void _build(T a[], uint v, uint tl, uint tr) {
        if (tl == tr) this->t[v] = a[tl];
        else{
            uint tm = (tl + tr) / 2;
            this->_build(a, 2 * v, tl, tm);
            this->_build(a, 2 * v + 1, tm + 1, tr);
            this->t[v] = operation(this->t[2 * v], this->t[2 * v + 1]);
        }
    }

    void _update(uint v, uint tl, uint tr, uint i, uint x) {
        if (tl == tr) this->t[v] = x;
        else{
            uint tm = (tl + tr) / 2;
            if (i <= tm) this->_update(2 * v, tl, tm, i, x);
            else this->_update(2 * v + 1, tm + 1, tr, i, x);
            this->t[v] = operation(this->t[2 * v], this->t[2 * v + 1]);
        }
    }

    T _compute(uint v, uint tl, uint tr, uint l, uint r) {
        if (l>r)return neutral;
        if (tl == l && tr == r)return this->t[v];
        uint tm = (tl + tr) / 2;
        T result = neutral;
        result = operation(result, this->_compute(2 * v, tl, tm, l, imin(r, tm)));
        result = operation(result, this->_compute(2 * v + 1, tm + 1, tr, imax(l, tm + 1), r));
        return result;
    }
public:
    SegmentTree(T b[], uint count) {
        this->R = next_power_of_two(count);
        uint i = 0;
        T a[4 * N];
        while (i<count)a[i + 1] = b[i], i++;
        while (i<this->R)a[i + 1] = neutral, i++;
        this->_build(a, 1, 1, this->R);
    }

    void update(uint i, T x) {
        this->_update(1, 1, this->R, i, x);
    }

    T compute(uint l, uint r) {
        return this->_compute(1, 1, this->R, l, r);
    }
};

bool isprime_miller_rabin(ulong m, int r) {
    

    ulong t = m - 1, s = 0;
    if (m % 2 == 0) return false;
    while (t % 2 == 0) t /= 2, s++;
    for (; r>0; r--) {
        ulong a = 2 + rand() % (m - 4);
        ulong x = mod_pow(a, t, m);
        if (x == 1 || x == m - 1) continue;
        uint i = 0;
        while (i < s - 1) {
            x = x*x % m;
            if (x == 1) return false;
            if (x == m - 1)i = s;
            i++;
        }
        if (i == s) continue;
        else return false;
    }
    return true;
}

vector<llong> genprimes(const ulong n) {
    vector<llong> res;
    res.push_back(2);
    llong m, t, j;
    for (int i = 3; i <= n; i += 2) {
        j = 0;
        m = res.size();
        t = (llong)sqrt(i*1.0) + 1;
        while (j<m && res[j]<t && i%res[j] != 0) j++;
        if (j == m || res[j] >= t)res.push_back(i);
    }
    return res;
}

const llong N = 1000 * 100 + 10;
const llong M = 3 * N + 10;
const int64_t MOD = 1000000007;
const llong INF = 1000 * 1000 * 1000 + 100;



int64_t n, m, i, j, k, t, p, q, z, c;
int64_t w, r;
llong price[N];
short u[N];

vector<int> ord, comp;
vector<int> al[N], la[N];

void dfso(int v) {
    u[v] = 1;
    for (int i = 0; i < al[v].size(); ++i) {
        if (!u[al[v][i]]) dfso(al[v][i]);
    }
    ord.push_back(v);
}

void dfsc(int v) {
    u[v] = 1;
    comp.push_back(v);
    for (int i = 0; i < la[v].size(); ++i) {
        if (!u[la[v][i]]) dfsc(la[v][i]);
    }
}

int main(int argc, char* argv[]) {
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> price[i + 1];
    }

    cin >> m;
    for (i = 0; i < m; ++i) {
        cin >> p >> q;
        al[p].push_back(q);
        la[q].push_back(p);
    }

    for (i = 0; i < n; ++i) u[i + 1] = 0;
    for (i = 0; i < n; ++i) if (!u[i + 1]) dfso(i + 1);


    r = 0;
    w = 1L;
    for (i = 0; i < n; ++i) u[i + 1] = 0;

    for (i = ord.size() - 1; i >= 0; --i) {
        if (!u[ord[i]]) {
            dfsc(ord[i]);
            p = INF;
            for (j = 0; j < comp.size(); ++j) {
                p = imin(p, price[comp[j]]);
            }

            q = 0;
            for (j = 0; j < comp.size(); ++j) {
                if (price[comp[j]] == p) q++;
            }

            r += p;
            w = (w * q) % MOD;

            comp.clear();
        }
    }

    cout << r << " " << w << endl;
    return 0;
}
