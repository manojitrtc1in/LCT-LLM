


















using namespace std;
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Pii = pair<int, int>;
using Vp = vector<Pii>;
using VVp = vector<Vp>;
using Pl = pair<ll, int>;
using Vpl = vector<Pl>;
using VVpl = vector<Vpl>;
using tup = tuple<ll, ll, int>;
using Vt = vector<tuple<int, int, int>>;
using Pll = pair<ll, ll>;
using Vc = vector<char>;
using VVc = vector<Vc>;
template <class U>
using PQmax = priority_queue<U>;
template <class U>
using PQmin = priority_queue<U, vector<U>, greater<U>>;





void id5(int u, const VVi& gr, Vi& tpr, Vi& par);
void id5(int u, const VVpl& gr, Vi& tpr, Vi& par);


void id5(const VVi& gr, Vi& tpr);
ll mpow(ll x, ll n, ll m = 1e9 + 7);
ll comb(int n, int r, const Vl& kai, const Vl& fkai, ll m = 1e9 + 7);
ll gcd(ll a, ll b);
int LCA(const VVi& par, const Vi& depth, int a, int b);
Vi id1(const VVi& gr);
void dijkstra(const VVi& gr, const VVl& cost, Vl& dist, int s);
void id3(const VVi& gr, const VVl& cost, Vl& dist, Vi& prev, int s);



struct DLine {
    ll a;
    ll b;
    ll c;
    bool operator<(const DLine l) const;
};
DLine id4(ll x1, ll y1, ll x2, ll y2);
double id0(DLine l1);
bool is_upper(DLine l, ll x, ll y);
bool is_inside(DLine l, ll x, ll y);

class unionfind
{
private:
    Vi par;
    Vi siz;

public:
    unionfind(int N);
    unionfind();
    int root(int v);
    void merge(int a, int b);
    bool same(int a, int b);
    int size(int a);
};
class id2
{
private:
    Vi par;
    Vi siz;
    Vi val;

public:
    id2(int N);
    id2();
    int root(int v);
    void merge(int a, int b, int z);
    bool same(int a, int b);
    int value(int a);
};
class BIT
{
private:
    Vl bit;
    int siz;

public:
    BIT(int N);
    BIT();
    ll& get(int id);
    void add(int id, ll a, ll m);
    ll sum(int id, ll m);
};
class RMQ
{
private:
    Vl val;
    int siz;
    ll e;
    ll prod_sub(int l, int r, int a, int b, int id);

public:
    RMQ(int N, ll e = (ll)1e18);
    RMQ(Vl A, ll e = (ll)1e18);
    RMQ(ll e = (ll)1e18);
    ll& get(int id);
    void set(int id, ll a);
    void add(int id, ll a);
    ll prod(int l, int r);
};
class Fraction
{
public:
    ll mot;
    ll son;

    

    Fraction(ll a = 0, ll b = 1)
    {
        ll g = gcd(abs(a), abs(b));
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        mot = b / g;
        son = a / g;
    }
    Fraction(const Fraction& F) : mot(F.mot), son(F.son) {}
    Fraction operator+(const Fraction A) const;
    Fraction operator-(const Fraction A) const;
    Fraction operator*(const Fraction A) const;
    

    Fraction operator/(const Fraction A) const;
    Fraction operator=(const Fraction& A);
    bool operator<(const Fraction A) const;
    bool operator>(const Fraction A) const;
};

int main()
{
    int T;
    

    scanf(" %d", &T);
    for (int pkj = 0; pkj < T; pkj++) {
        int N, K;
        

        scanf(" %d %d", &N, &K);
        

        

        Vi A(N);
        Vi ma(100010, 0);
        for (int i = 0; i < N; i++) {
            scanf(" %d", &A[i]);
            int a = sqrt(A[i]);
            while (a * a <= A[i]) {
                a++;
            }
            ma[0] = max(ma[0], A[i] / K);
            for (int j = min(a, K + 1); j > 1; j--) {
                ma[A[i] / j + 1] = max(ma[A[i] / j + 1], A[i] / (j - 1));
            }
        }
        int ans = 1e9 + 7;
        for (int i = 1; i <= A[0]; i++) {
            ma[i] = max({i, ma[i], ma[i - 1]});
            ans = min(ans, ma[i] - i);
        }
        printf("%d\n", ans);
    }
}





void id5(int u, const VVpl& gr, Vi& tpr, Vi& par)
{
    

    
    stack<int> st;
    st.push(u);
    bool vis[2000020];
    for (int i = 0; i <= gr.size(); i++) {
        vis[i] = false;
    }
    while (!st.empty()) {
        int v = st.top();
        if (!vis[v]) {
            vis[v] = true;
            for (auto [x, p] : gr[v]) {
                if (par[p] == -1) {
                    par[p] = v;
                    st.push(p);
                }
            }
        } else {
            tpr.push_back(v);
            st.pop();
        }
    }
}



void id5(int u, const VVi& gr, Vi& tpr, Vi& par)
{
    

    
    stack<int> st;
    st.push(u);
    bool vis[2000020];
    for (int i = 0; i <= gr.size(); i++) {
        vis[i] = false;
    }
    while (!st.empty()) {
        int v = st.top();
        if (!vis[v]) {
            vis[v] = true;
            for (int p : gr[v]) {
                if (par[p] == -1) {
                    par[p] = v;
                    st.push(p);
                }
            }
        } else {
            tpr.push_back(v);
            st.pop();
        }
    }
}

Vi id1(const VVi& gr)
{
    int N = gr.size();
    Vi tpr;
    Vi par(N, -1);
    for (int i = 0; i < N; i++) {
        if (par[i] == -1) {
            id5(i, gr, tpr, par);
        }
    }
    Vi ret(N, -1);
    int now = 0;
    for (int i = N - 1; i >= 0; i--) {
        int u = tpr[i];
        if (ret[u] != -1) {
            continue;
        }
        ret[u] = now;
        stack<int> st;
        st.push(u);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            for (int p : gr[v]) {
                if (ret[p] == -1) {
                    st.push(p);
                    ret[p] = now;
                }
            }
        }
        now++;
    }
    return ret;
}

ll gcd(ll a, ll b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll mpow(ll x, ll n, ll m)
{
    ll ret = 1;
    while (n) {
        if (n % 2) {
            ret *= x;
            ret %= m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return ret;
}
ll comb(int n, int r, const Vl& kai, const Vl& fkai, ll m)
{
    if (n < 0 || r < 0 || n < r) {
        return 0;
    }
    ll ret = kai[n];
    ret *= fkai[r];
    ret %= m;
    ret *= fkai[n - r];
    ret %= m;
    return ret;
}

int LCA(const VVi& par, const Vi& depth, int a, int b)
{
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int dis = depth[a] - depth[b];
    for (int i = 19; i >= 0; i--) {
        if ((dis >> i) & 1) {
            a = par[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 19; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

void dijkstra(const VVi& gr, const VVl& cost, Vl& dist, int s)
{
    ll INF = (ll)1e18;
    dist.assign(gr.size(), INF);
    dist[s] = 0;
    PQmin<Pl> pque;
    pque.push(make_pair(0, s));
    while (!pque.empty()) {
        auto [L, u] = pque.top();
        pque.pop();
        while (L != dist[u] && !pque.empty()) {
            tie(L, u) = pque.top();
            pque.pop();
        }
        for (int i = 0; i < gr[u].size(); i++) {
            int v = gr[u][i];
            ll c = cost[u][i];
            if (dist[v] > c + L) {
                dist[v] = c + L;
                pque.push(make_pair(dist[v], v));
            }
        }
    }
    return;
}

void id3(const VVi& gr, const VVl& cost, Vl& dist, Vi& prev, int s)
{
    ll INF = (ll)1e18;
    dist.assign(gr.size(), INF);
    dist[s] = 0;
    PQmin<Pl> pque;
    pque.push(make_pair(0, s));
    while (!pque.empty()) {
        auto [L, u] = pque.top();
        pque.pop();
        while (L != dist[u] && !pque.empty()) {
            tie(L, u) = pque.top();
            pque.pop();
        }
        for (int i = 0; i < gr[u].size(); i++) {
            int v = gr[u][i];
            ll c = cost[u][i];
            if (dist[v] > c + L) {
                dist[v] = c + L;
                prev[v] = u;
                pque.push(make_pair(dist[v], v));
            }
        }
    }
    return;
}

DLine id4(ll x1, ll y1, ll x2, ll y2)
{
    ll dx = x1 - x2;
    ll dy = y2 - y1;
    if (dy < 0) {
        dx *= -1;
        dy *= -1;
    }
    if (dy == 0) {
        dx = abs(dx);
    }
    ll g = gcd(dy, abs(dx));
    dx /= g;
    dy /= g;
    ll c = dx * y1 + dy * x1;
    return DLine{dy, dx, c};
}
double id0(DLine l)
{
    return atan2(l.a, l.b);
}
bool is_upper(DLine l, ll x, ll y)
{
    return x * l.a + y * l.b > l.c;
}
bool is_inside(DLine l, ll x, ll y)
{
    return x * l.a + y * l.b == l.c;
}

unionfind::unionfind(int N)
{
    par.resize(N);
    siz.assign(N, 1);
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }
}
unionfind::unionfind()
{
    par.resize(100010);
    siz.assign(100010, 1);
    for (int i = 0; i <= 100010; i++) {
        par[i] = i;
    }
}
int unionfind::root(int v)
{
    if (v == par[v]) {
        return v;
    }
    return par[v] = root(par[v]);
}
void unionfind::merge(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a == b) {
        return;
    }
    if (siz[a] < siz[b]) {
        int t = a;
        a = b;
        b = t;
    }
    par[b] = a;
    siz[a] += siz[b];
}
bool unionfind::same(int a, int b)
{
    a = root(a);
    b = root(b);
    return a == b;
}
int unionfind::size(int a)
{
    return siz[this->root(a)];
}

id2::id2(int N)
{
    par.resize(N);
    siz.assign(N, 1);
    val.assign(N, 0);
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }
}
id2::id2()
{
    par.resize(100010);
    siz.assign(100010, 1);
    val.assign(100010, 0);
    for (int i = 0; i <= 100010; i++) {
        par[i] = i;
    }
}
int id2::root(int v)
{
    if (v == par[v]) {
        return v;
    }
    int p = root(par[v]);
    val[v] += val[par[v]];
    par[v] = p;
    return p;
}
void id2::merge(int a, int b, int z)
{
    z -= this->value(b);
    z += this->value(a);
    a = root(a);
    b = root(b);
    if (a == b) {
        return;
    }
    if (siz[a] < siz[b]) {
        int t = a;
        a = b;
        b = t;
        z *= -1;
    }
    par[b] = a;
    siz[a] += siz[b];
    val[b] += z;
}
bool id2::same(int a, int b)
{
    a = root(a);
    b = root(b);
    return a == b;
}
int id2::value(int a)
{
    root(a);
    return val[a];
}


BIT::BIT(int N)
{
    siz = N;
    bit.assign(N + 1, 0);
}

BIT::BIT()
{
    siz = 0;
}

ll& BIT::get(int id)
{
    return bit[id];
}

void BIT::add(int id, ll a, ll m)
{
    while (id <= siz) {
        bit[id] += a;
        bit[id] %= m;
        id += (id & (-id));
    }
}

ll BIT::sum(int id, ll m)
{
    ll ret = 0;
    while (id) {
        ret += bit[id];
        ret %= m;
        id -= (id & (-id));
    }
    return ret;
}

RMQ::RMQ(int N, ll e)
{
    siz = 1;
    this->e = e;
    while (siz < N) {
        siz *= 2;
    }
    val.assign(siz * 2, e);
}
RMQ::RMQ(Vl A, ll e)
{
    siz = 1;
    this->e = e;
    while (siz < A.size()) {
        siz *= 2;
    }
    val.assign(siz * 2, e);
    for (int i = 0; i < A.size(); i++) {
        val[i + siz - 1] = A[i];
    }
    for (int i = siz - 2; i >= 0; i--) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        val[i] = min(val[l], val[r]);
    }
}

RMQ::RMQ(ll e)
{
    siz = (1 << 20);
    this->e = e;
    val.assign(siz * 2, e);
}

ll& RMQ::get(int id)
{
    return val[id + siz - 1];
}

void RMQ::set(int id, ll a)
{
    id += siz - 1;
    val[id] = a;
    while (id > 0) {
        id = (id - 1) / 2;
        int l = id * 2 + 1;
        int r = id * 2 + 2;
        ll v = min(val[l], val[r]);
        
        val[id] = v;
    }
}

void RMQ::add(int id, ll a)
{
    ll n = a + val[id + siz - 1];
    this->set(id, n);
}

ll RMQ::prod_sub(int l, int r, int a, int b, int id)
{
    if (b <= l || r <= a) {
        return this->e;
    }
    if (l <= a && b <= r) {
        return val[id];
    }
    return min(this->prod_sub(l, r, a, (a + b) / 2, id * 2 + 1),
        this->prod_sub(l, r, (a + b) / 2, b, id * 2 + 2));
}

ll RMQ::prod(int l, int r)
{
    return prod_sub(l, r, 0, siz, 0);
}

Fraction Fraction::operator+(const Fraction A) const
{
    return Fraction{this->son * A.mot + A.son * this->mot, this->mot * A.mot};
}
Fraction Fraction::operator-(const Fraction A) const
{
    return Fraction{this->son * A.mot - A.son * this->mot, this->mot * A.mot};
}
Fraction Fraction::operator*(const Fraction A) const
{
    return Fraction{this->son * A.son, this->mot * A.mot};
}








Fraction Fraction::operator/(const Fraction A) const
{
    return Fraction{this->son * A.mot, this->mot * A.son};
}
Fraction Fraction::operator=(const Fraction& A)
{
    this->mot = A.mot;
    this->son = A.son;
    return *this;
}
bool Fraction::operator<(const Fraction A) const
{
    if (A.son < 0 && this->son > 0) {
        return false;
    }
    if (A.son > 0 && this->son < 0) {
        return true;
    }
    if (A.son < 0) {
        return (A * -1) < (*this * -1);
    }
    if (max({this->son, A.son, A.mot, this->mot}) < 3000000000ll) {
        return this->son * A.mot < this->mot * A.son;
    } else if (this->son / this->mot != A.son / A.mot) {
        return this->son / this->mot < A.son / A.mot;
    } else {
        ll f = this->son / this->mot;
        return (*this - f) < (A - f);
    }
}
bool Fraction::operator>(const Fraction A) const
{
    return A < *this;
}
bool DLine::operator<(const DLine l) const
{
    if (a == l.a && b == l.b) {
        return c < l.c;
    }
    return Fraction{a, -b} < Fraction{l.a, -l.b};
}
