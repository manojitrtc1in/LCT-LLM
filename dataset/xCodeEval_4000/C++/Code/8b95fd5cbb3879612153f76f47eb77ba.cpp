

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <cctype>
#include <utility>
#include <map>
#include <iterator>
#include <complex>
#include <sstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

#define sz size()
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define sqr(a) (a)*(a)
#define mp make_pair
#define rall(c) (c).rbegin(), (c).rend()
#define rmp reverse_make_pair
#define tre(u) paths[path_num[u]]


typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<vector<int> > vvint;
typedef vector<char> vchar;
typedef vector<vector<int> > graph;
typedef unsigned char uchar;
const int INF=~(1<<31);

inline int in() {
    int a;
    scanf("%d", &a);
    return a;
}
template<class T1, class T2>
inline pair<T1, T2> reverse_make_pair(T1 x, T2 y){
    return pair<T1, T2>(y, x);
}
template<class T>
ostream& operator<<(ostream& out, const vector<T> a){
    for(int i = 0; i < (int)a.size()-1; i++)   out<<a[i]<<' ';
    if(a.size ()>=1)cout<<a[a.size ()-1];
    return out;
}

double din() {
    double a;
    scanf("%lf", &a);
    return a;
}

ll gcd(ll a, ll b) {
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int logbin(int a){
    a--;
    int res=1;
    while(a) a>>=1, res<<=1;
    return res;
}

struct treap{
    treap *l,*r;
    int y,x;
    int size;
    treap(int xx){
        l=r=NULL;
        y=rand();
        x=xx;
        size=0;
        recalc();
    }
    void recalc(){
        size=1;
        if(l) size+=l->size;
        if(r) size+=r->size;
    }

};
void recalc(treap* &a){
    if(a==NULL) return;
    a->recalc ();
}
void merge(treap* &t,treap* l, treap* r){
    if(l==NULL) return (void)(t=r);
    if(r==NULL) return (void)(t=l);
    if(r->y > l->y){
        merge(r->l, l, r->l);
        t=r;
    }else{
        merge(l->r, l->r, r);
        t=l;
    }
    recalc (t);
}
void split(treap* v,int x, treap* &l, treap* &r){
    if(v==NULL) return (void)(r=l=NULL);
    if(v->x <= x){
        split(v->r, x, v->r, r);
        l=v;
    }else{
        split(v->l, x, l, v->l );
        r=v;
    }
    recalc(v);
}

const int base = 1000000000;
const int base_digits = 9;

struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
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
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
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
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
bigint l;
bigint binpow (ll aa, ll nn) {
    bigint res(1);
    bigint a(aa);
    bigint n(nn);
    while (n!=0) {
        if (n %2== 1)
            res *=a;
        a *= a;
        n /= 2;
    }
    return res;
}



struct node{
    string k;
    node *con[2], *p;
    node(string _k){
        k = _k;
        con[0] = con[1] = p = NULL;
    }
};
node *root;

void rotate(node *v, int ch=1){
    node *p = v->p, *pp = p->p;
    if(v==p->con[1]) ch^=1;
    p->con[ch^1]=v->con[ch];
    if (v->con[ch]) v->con[ch]->p=p;
    v->con[ch]=p;
    p->p=v;
    v->p=pp;
    if(pp) {
        if(p==pp->con[0]) pp->con[0]=v;
        else pp->con[1]=v;
    }
}
void splay (node *v){
    while (v->p) {
        node *p=v->p, *pp=p->p;
        if (!pp) rotate(v);
        else if ((v==p->con[0])==(p==pp->con[0]))
            rotate(p), rotate(v);
        else rotate(v), rotate(v);
    }
    root=v;
}

void insert(node *v, node *x){
    if(x->k < v->k){
        if(!v->con[0]){
            x->p=v;
            v->con[0]=x;
            splay (x);
        }else
            insert(v->con[0], x);
    }
    if(x->k > v->k){
        if(!v->con[1]){
            x->p=v;
            v->con[1]=x;
            splay(x);
        }else
            insert(v->con[1], x);
    }
}

bool find(node *v, string a){
    if(a < v->k && v->con[0]) return find(v->con[0], a);
    else if(a > v->k && v->con[1])return find(v->con[1], a);
    else{
        splay(v);
        if(a==v->k) return true;
        else return false;
    }
}

int main(){
    

    



    int n=in();

    int need=(n+1)/2;
    map<int, pair<int,int> > mm;
    for(int i=0;i<n;++i){
        int a=in(),b=in();
        mm[a].first++;
        if(a!=b)
        mm[b].second++;
    }
    int res=INF;
    for(auto i=mm.begin ();i!=mm.end ();++i){
        pair<int, pii> c=*i;
        if(c.second.first+c.second.second>=need && (need - c.second.first)<res){
            res=max((need - c.second.first),0);
        }
    }
    if(res==INF) cout<<-1<<endl;
    else cout<<res;


    

    return 0;
}
