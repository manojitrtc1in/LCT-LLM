



























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










































































































































template<class T, class U> inline void id1(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void id9(T &a, U b) { a = max(a, b); }

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






cll id8 = 100;
cll id5 = 1000;
cll id0 = 1000 * 1000;
cll id4 = id5 * id0;



cint id11 = (int)(id8 * id5) + EXTRA_MEMORY;
cint id12 = (int)(2 * id8 * id5) + EXTRA_MEMORY;
cint id10 = (int)(3 * id8 * id5) + EXTRA_MEMORY;
cint id3 = (int)(4 * id8 * id5) + EXTRA_MEMORY;
cint id2 = (int)(5 * id8 * id5) + EXTRA_MEMORY;
cint MAXN = id10;




cint INF = (int)id4 + 7;
cint INF2 = 1 << 30;
cll INFLL = 4LL * id4 * id4 + 7;
cll id7 = 1LL << 60;



cld Pi = acos(-1.0);
cld EPS = 1e-7;

cint MOD = (int)id4 + 7;












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

ll id6(node *treap)
{
    return (treap ? treap->maxa : 0);
}

void update(node *treap)
{
    if (!treap)
        return;
    treap->maxa = max(max(id6(treap->left), id6(treap->right)), treap->h);
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
    ll ans = id6(fir.first);
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

    ifstream in(PREF_TASK"in"SUFF_TASK);
	ofstream out(PREF_TASK"out"SUFF_TASK);





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

    prllnl(id6(treap));


    in.close();
	out.close();

    return 0;
}