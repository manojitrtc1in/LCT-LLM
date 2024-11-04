




#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>




using namespace std;




typedef const int cint;
typedef unsigned int uint;
typedef long long ll;
typedef const long long cll;
typedef unsigned long long ull;
typedef long double ld;
typedef const long double cld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ld> sld;
typedef set<string> ss;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef map<int, ll> mill;
typedef map<ll, int> mlli;
typedef map<int, string> mis;
typedef map<string, int> msi;




#define EXTRA_MEMORY 3

#define FOR(i, s, f) for (decltype(s) (i) = (s); (i) < (f); ++(i))
#define ROF(i, f, s) for (decltype(s) (i) = (f) - 1; (i) >= (s); --(i))

#define forn(i, f) FOR((i), 0, (f))
#define rofn(i, f) ROF((i), (f), 0)

#define rep(i, s, f) FOR((i), (s), (f) + 1)
#define per(i, s, f) ROF((i), (f) + 1, (s))

#define forit(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

#define ALL(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define PREF_TASK ""
#define SUFF_TASK ""








#define sci(a) scanf("%d", &(a))
#define sc2i(a, b) scanf("%d%d", &(a), &(b))
#define sc3i(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

#define scid(a) int (a); sci(a)
#define sc2id(a, b) int (a), (b); sc2i((a), (b))
#define sc3id(a, b, c) int (a), (b), (c); sc3i((a), (b), (c))

#define scvi(a) forn(IT_FOR_SCANNING, sz(a)) sci((a)[IT_FOR_SCANNING])
#define scvin(a, n) forn(IT_FOR_SCANNING, (n)) sci((a)[IT_FOR_SCANNING])
#define scvind(a, n) vi a(n); scvin((a), (n))
#define scvinds(a, n) vi a((n) + EXTRA_MEMORY); scvin((a), (n))

#define sc2vi(a) forn(IT_FOR_SCANNING, min(sz(a), sz(b))) sc2i((a)[IT_FOR_SCANNING], (b)[IT_FOR_SCANNING])
#define sc2vin(a, b, n) forn(IT_FOR_SCANNING, (n)) sc2i((a)[IT_FOR_SCANNING], (b)[IT_FOR_SCANNING])
#define sc2vind(a, b, n) vi a(n), b(n); sc2vin((a), (b), (n))
#define sc2vinds(a, b, n) vi a((n) + EXTRA_MEMORY), b((n) + EXTRA_MEMORY); sc2vin((a), (b), (n))

#define scsin(a, n) forn(IT_FOR_INSERTION, (n)) (a).insert(next_int())
#define scsind(a, n) si (a); scsin(a, n)



#define scll(a) scanf("%lld", &(a))
#define sc2ll(a, b) scanf("%lld%lld", &(a), &(b))
#define sc3ll(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c))

#define sclld(a) ll (a); scll(a)
#define sc2lld(a, b) ll (a), (b); sc2ll((a), (b))
#define sc3lld(a, b, c) ll (a), (b), (c); sc3ll((a), (b), (c))

#define scvll(a) forn(IT_FOR_SCANNING, sz(a)) scll((a)[IT_FOR_SCANNING])
#define scvlln(a, n) forn(IT_FOR_SCANNING, (n)) scll((a)[IT_FOR_SCANNING])
#define scvllnd(a, n) vll a(n); scvlln((a), (n))
#define scvllnds(a, n) vll a((n) + EXTRA_MEMORY); scvlln((a), (n))

#define sc2vll(a) forn(IT_FOR_SCANNING, min(sz(a), sz(b))) sc2ll((a)[IT_FOR_SCANNING], (b)[IT_FOR_SCANNING])
#define sc2vlln(a, b, n) forn(IT_FOR_SCANNING, (n)) sc2ll((a)[IT_FOR_SCANNING], (b)[IT_FOR_SCANNING])
#define sc2vllnd(a, b, n) vll a(n), b(n); sc2vlln((a), (b), (n))
#define sc2vllnds(a, b, n) vll a((n) + EXTRA_MEMORY), b((n) + EXTRA_MEMORY); sc2vlln((a), (b), (n))

#define scslln(a, n) forn(IT_FOR_INSERTION, (n)) (a).insert(next_ll())
#define scsllnd(a, n) sll (a); scslln(a, n)



#define prnl printf("\n")



#define pri(a) printf("%d ", (a))
#define pr2i(a, b) printf("%d %d ", (a), (b))
#define pr3i(a, b, c) printf("%d %d %d ", (a), (b), (c))

#define prinl(a) printf("%d\n", (a))
#define pr2inl(a, b) printf("%d %d\n", (a), (b))
#define pr3inl(a, b, c) printf("%d %d %d\n", (a), (b), (c))

#define prvi(a) forn(IT_FOR_PRINTING, sz(a)) pri((a)[IT_FOR_PRINTING])
#define prvinl(a) forn(IT_FOR_PRINTING, sz(a)) prinl((a)[IT_FOR_PRINTING])
#define prvin(a, n) forn(IT_FOR_PRINTING, (n)) pri((a)[IT_FOR_PRINTING])
#define prvinnl(a, n) forn(IT_FOR_PRINTING, (n)) prinl((a)[IT_FOR_PRINTING])



#define prll(a) printf("%lld ", (a))
#define pr2ll(a, b) printf("%lld %lld ", (a), (b))
#define pr3ll(a, b, c) printf("%lld %lld %lld ", (a), (b), (c))

#define prllnl(a) printf("%lld\n", (a))
#define pr2llnl(a, b) printf("%lld %lld\n", (a), (b))
#define pr3llnl(a, b, c) printf("%lld %lld %lld\n", (a), (b), (c))

#define prvll(a) forn(IT_FOR_PRINTING, sz(a)) prll((a)[IT_FOR_PRINTING])
#define prvllnl(a) forn(IT_FOR_PRINTING, sz(a)) prllnl((a)[IT_FOR_PRINTING])
#define prvlln(a, n) forn(IT_FOR_PRINTING, (n)) prll((a)[IT_FOR_PRINTING])
#define prvllnnl(a, n) forn(IT_FOR_PRINTING, (n)) prllnl((a)[IT_FOR_PRINTING])



#define FILL(a, x) memset((a), (x), sizeof(a))
#define FILLN(a, n, x) memset((a), (x), (n) * sizeof(*(a)))
#define cl(a) FILL((a), 0)
#define cln(a, n) FILLN((a), (n), 0)



#define rmin(a, b) (a) = min((a), (b))
#define rmax(a, b) (a) = max((a), (b))



#define modFix(a, MOD) ((((a) % (MOD)) + (MOD)) % (MOD))
#define modSum(a, b, MOD) modFix(((a) + (b)), (MOD))

#define modSub(a, b, MOD) modFix(((a) - (b)), (MOD))
#define modMul(a, b, MOD) modFix(((ll)(a) * (ll)(b)), (MOD))



#define init_cin ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define cout_prec cout.precision(30)






template<class T, class U> inline void relax_min(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void relax_max(T &a, U b) { a = max(a, b); }

template<typename T> inline bool updmax(T &a, const T &b){ return a < b ? a = b, 1 : 0; }
template<typename T> inline bool updmin(T &a, const T &b){ return a > b ? a = b, 1 : 0; }



template<class T, class U> istream &operator>>(istream &in, pair<T, U> &a)
{
    in >> a.first >> a.second;
    return in;
}

template<class T, class U> ostream &operator<<(ostream &out, const pair<T, U> &a)
{
    out << a.first << ' ' << a.second;
    return out;
}

template<class T> istream &operator>>(istream &in, vector<T> &a)
{
    forn(i, sz(a))
        in >> a[i];
    return in;
}

template<class T> ostream &operator<<(ostream &out, const vector<T> &a)
{
    forn(i, sz(a))
        out << a[i] << ' ';
    return out;
}



int next_int()
{
    scid(tmp);
    return tmp;
}

ll next_ll()
{
    sclld(tmp);
    return tmp;
}



ll modPow(ll a, ll b, ll MOD){
    ll ret = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ret = modMul(ret, a, MOD);
        a = modMul(a, a, MOD);
    }
    return ret;
}






cll EXACTLY_ONE_HUNDRED = 100;
cll EXACTLY_ONE_THOUSAND = 1000;
cll EXACTLY_ONE_MILLION = 1000 * 1000;
cll EXACTLY_ONE_BILLION = EXACTLY_ONE_THOUSAND * EXACTLY_ONE_MILLION;



cint MAXN1 = (int)(EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + EXTRA_MEMORY;
cint MAXN2 = (int)(2 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + EXTRA_MEMORY;
cint MAXN3 = (int)(3 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + EXTRA_MEMORY;
cint MAXN4 = (int)(4 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + EXTRA_MEMORY;
cint MAXN5 = (int)(5 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + EXTRA_MEMORY;
cint MAXN = MAXN3;




cint INF = (int)EXACTLY_ONE_BILLION + 7;
cint INF2 = 1 << 30;
cll INFLL = 4LL * EXACTLY_ONE_BILLION * EXACTLY_ONE_BILLION + 7;
cll INFLL2 = 1LL << 60;



cld Pi = acos(-1.0);
cld EPS = 1e-7;

cint MOD = (int)EXACTLY_ONE_BILLION + 7;












int gen_rand()
{
    return (rand() << 15) + rand();
}

struct node
{
    int x, y;
    ll h, maxa; 

    node *left, *right;




    node(int val, ll height) :
            x(val), h(height), maxa(height), y(gen_rand()), left(0), right(0){}
};


typedef pair<node *, node *> pnn;

ll get_maxa(node *treap)
{
    return (treap ? treap->maxa : 0);
}

void update(node *treap)
{
    if (!treap)
        return;
    treap->maxa = max(max(get_maxa(treap->left), get_maxa(treap->right)), treap->h);
}

node *merge(node *treap1, node *treap2)
{
    if (treap1 == 0)
        return treap2;
    if (treap2 == 0)
        return treap1;

    if (treap1->y > treap2->y)
    {
        treap1->right = merge(treap1->right, treap2);
        update(treap1);
        return treap1;
    }
    else
    {
        treap2->left = merge(treap1, treap2->left);
        update(treap2);
        return treap2;
    }
}

pnn split(node *treap, int key)
{
    if (treap == 0)
        return pnn(0, 0);
    if (key < treap->x)
    {
        pnn temp = split(treap->left, key);
        treap->left = temp.second;
        update(treap);
        return pnn(temp.first, treap);
    }
    else
    {
        pnn temp = split(treap->right, key);
        treap->right = temp.first;
        update(treap);
        return pnn(treap, temp.second);
    }
}
















node *insert(node *treap, int key, ll h)
{
    pnn fir = split(treap, key);
    pnn sec = split(fir.first, key - 1);
    node *ins = new node(key, h);
    return merge(merge(sec.first, ins), fir.second);
}

ll get_max(node *treap, int a) {  

    pnn fir = split(treap, a);
    ll ans = get_maxa(fir.first);
    merge(fir.first, fir.second);
    return ans;
}

















bool cmp(pair<pi, ll> a, pair<pi, ll> b) {
    if (a.first.first > b.first.first)
        return true;
    if (a.first.first < b.first.first)
        return false;
    return (a.first.second > b.first.second);
}

int main()
{
#ifdef FILEIO
    ifstream in(PREF_TASK"in"SUFF_TASK);
	ofstream out(PREF_TASK"out"SUFF_TASK);
#endif




    node *treap = NULL;

    scid(n);
    vector<pair<pi, ll>> arr;
    forn(i, n) {
        sc2id(a, b);
        sclld(h);

        arr.emplace_back(pi(b, a), h);
    }

    sort(ALL(arr), cmp);













    ll cur_h = 0;
    int cur_a = INF;
    FOR(i, 0, n) {
        cur_h += arr[i].second;
        updmin(cur_a, arr[i].first.second);
        if (i < n - 1 && arr[i].first.first == arr[i + 1].first.first) {
            continue;
        } else {


            ll H = get_max(treap, arr[i].first.first - 1);
            treap = insert(treap, cur_a, cur_h + H);
            cur_a = INF;
            cur_h = 0;
        }
    }

    prllnl(get_maxa(treap));

#ifdef FILEIO
    in.close();
	out.close();
#endif
    return 0;
}