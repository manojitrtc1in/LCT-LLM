



using namespace std;












namespace XYL_DEBUG_NAMESPACE {
    char tem[100007];
    int st;

    template<typename T, typename ...T2>
    void prt(const T &t, const T2 &...t2) {
        while (tem[st] == ' ' || tem[st] == ',')st++;
        int u = 0, v = 0, x = 0;
        while (u || (tem[st] != ',' && tem[st] != ' ')) {
            if (!v && !x) {
                if (tem[st] == '(')u++;
                if (tem[st] == ')')u--;
            }
            if (tem[st] == '"' && !x)v = !v;
            if (tem[st] == '\'' && !v)x = !x;
            cerr << tem[st], st++;
        }
        cerr << " = " << t;
        if constexpr (sizeof...(t2) > 0)cerr << " , ", prt(t2...);
        else cerr << endl;
    }
}










struct clock_node {

    void start_clock() {
        id1 = chrono::system_clock::now();
    }

    void end_clock() const {
        auto ends = chrono::system_clock::now();
        cerr << "timeit : " <<
             (long double) chrono::duration_cast<chrono::microseconds>(ends - id1).count() / 1000.00l
             << "ms\n";
    }

    void reset_clock() {
        auto ends = chrono::system_clock::now();
        cerr << "timeit : " <<
             (long double) chrono::duration_cast<chrono::microseconds>(ends - id1).count() / 1000.00l
             << "ms\n";
        id1 = ends;
    }

private:
    chrono::time_point<chrono::system_clock, chrono::nanoseconds> id1 = chrono::system_clock::now();
};


struct clock_node{
    void start_clock(){}
    void end_clock(){}
    void reset_clock(){}
};

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<db, db> pdd;
typedef pair<ld, ld> pld;

template<class T>
bool updmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool updmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

constexpr int px4[]{0, 1, 0, -1};
constexpr int py4[]{1, 0, -1, 0};
constexpr int px8[]{0, 1, 0, -1, 1, 1, -1, -1};
constexpr int py8[]{1, 0, -1, 0, 1, -1, 1, -1};


namespace XYL_FAST_IO {








    constexpr int Q = (1 << 10) + 1;
    int QQ = Q - 10;
    char in[Q], *is = in, *it = in, ou[Q], *os = ou;

    void out() {
        *os = 0;
        fwrite(ou, 1, os - ou, stdout);
        os = ou, QQ = Q - 10;
    }

    constexpr long double double_p() {
        long double as = 1;
        fo(i, 0, double_precision)as *= 10;
        return as;
    }

    template<class T>
    void output(T x, int num = 0) {
        if (x / 10)output(x / 10, num - 1);
        else while (num-- > 1)pc('0');
        pc(x % 10 + '0');
    }

    namespace impl {
        bool eof() {
            return is == it && feof(stdin);
        }

        template<class T, typename enable_if<is_integral<T>::value, T>::type * = nullptr>
        void ot(T x) {
            if (x < 0)pc('-'), output(-x);
            else output(x);
        }

        void ot(char x) {
            pc(x);
        }

        template<class T, typename enable_if<is_floating_point<T>::value, T>::type * = nullptr>
        void ot(T x) {
            if (x < 0)pc('-'), x *= -1.0l;
            long double zs = fmodl(x, 1.0l);
            zs *= double_p();
            ot((long long) x), pc('.');
            output((long long) zs, double_precision);
        }

        template<typename T, typename enable_if<is_pointer<T>::value, T>::type * = nullptr>
        void ot(T x) { while (*x)pc(*x++); }


        template<class Tx, class...T>
        void ot(Tx x, T...x1) {
            ot(x), ot(x1...);
        }

        template<char dem = '\n', class T>
        void otl(T x) { ot(x), dem ? pc(dem), 0 : 0; }

        template<char dem = '\n', class Tx, class ...T>
        void otl(Tx x, T... xx) { ot(x), dem ? pc(dem), 0 : 0, otl < dem >(xx...); }

        template<class ...T>
        void otb(T... xx) { otl<' '>(xx...); }

        template<char dem = ' ', class T>
        void ota(T x1, T x2) {
            while (x1 != x2)ot(*x1++), pc(dem);
            pc('\n');
        }

        template<char dem = '\0', class ...T>
        void otf(T ...x) {
            otl<dem>(x...), out(), fflush(stdout);
        }

        template<class T, typename enable_if<is_integral<T>::value, T>::type * = nullptr>
        void rd(T &x) {
            char ch;
            x = 0;
            bool fl = false;
            while (!isdigit(ch = gc()))(ch == '-') && (fl = true);
            for (x = (ch - '0'); isdigit(ch = gc()); x = x * 10 + (ch - '0'));
            fl && (x = -x);
        }

        template<class T, typename enable_if<is_floating_point<T>::value, T>::type * = nullptr>
        void rd(T &x) {
            bool sign = false;
            x = 0;
            char ch;
            while (!isdigit(ch = gc()))(ch == '-') && (sign = true);
            for (; isdigit(ch); ch = gc())x = x * 10 + (ch - '0');
            if (ch == '.') {
                T tmp = 1.0l;
                ch = gc();
                for (; isdigit(ch); ch = gc())tmp /= 10.0l, x += tmp * (ch - '0');
            }
            if (sign)x = -x;
        }

        void rd(char &t) {
            t = gc();
            while (t == ' ' || t == '\n')t = gc();
        }

        void rd(char *t) {
            char *p = t;
            while ((*p = gc()) != ' ' && *p != '\n' && *p != EOF)p++;
            *p = 0;
        }

        template<typename T1, typename T2>
        void rd(pair<T1, T2> &p) {
            rd(p.first), rd(p.second);
        }

        template<class Tx, class...T>
        void rd(Tx &x, T &...x1) {
            rd(x), rd(x1...);
        }

        template<class T>
        void rda(T x1, T x2) {
            while (x1 != x2)rd(*x1++);
        }

        void rdl(char *t) {
            char *p = t;
            while ((*p = gc()) != EOF)p++;
            *p = 0;
        }
    }







}

template<int mod>
struct modint {
    int val;
    constexpr modint(int val_ = 0) : val(val_) {}
    modint &operator=(int val_) { return val = val_, *this; }
    modint &operator+=(const modint &k) { return val = val + k.val >= mod ? val + k.val - mod : val + k.val, *this; }
    modint &operator-=(const modint &k) { return val = val - k.val < 0 ? val - k.val + mod : val - k.val, *this; }
    modint &operator*=(const modint &k) { return val = 1ull * val * k.val % mod, *this; }
    modint &operator^=(int k) {
        modint ret = 1, tmp = *this;
        for (; k; k >>= 1, tmp *= tmp)if (k & 1)ret *= tmp;
        return val = ret.val, *this;
    }
    modint &operator/=(modint k) { return *this *= (k ^= mod - 2); }
    modint &operator+=(int k) { return val = val + k >= mod ? val + k - mod : val + k, *this; }
    modint &operator-=(int k) { return val = val < k ? val - k + mod : val - k, *this; }
    modint &operator*=(int k) { return val = 1ull * val * k % mod, *this; }
    modint &operator/=(int k) { return *this *= ((modint(k)) ^= mod - 2); }
    template<class T>friend modint operator+(modint a, T b) { return a += b; }
    template<class T>friend modint operator-(modint a, T b) { return a -= b; }
    template<class T>friend modint operator*(modint a, T b) { return a *= b; }
    template<class T>friend modint operator^(modint a, T b) { return a /= b; }
    template<class T>friend modint operator/(modint a, T b) { return a /= b; }
    friend modint operator^(modint a, int b) { return a ^= b; }
    friend bool operator==(modint a, int b) { return a.val == b; }
    friend bool operator!=(modint a, int b) { return a.val != b; }
    bool operator!() { return !val; }
    modint operator-() { return val ? mod - val : 0; }
    modint &operator++() { return *this += 1; }
};

using namespace XYL_FAST_IO::impl;
bool id0 = false;
int n, m, k;
const int maxn = 2e5+18;
const ll mod = 998244353;
using mint = modint<mod>;

pii operator +(pii a,pii b){
    return pii(a.fi+b.fi,a.se+b.se);
}
pll operator +(pll a,pll b){
    return pll(a.fi+b.fi,a.se+b.se);
}
namespace seg{




    pii a[maxn<<2];
    pll p[maxn<<2];
    int laz[maxn<<2];

    void upd(int rt){
        laz[rt]^=1;
        swap(a[rt].first,a[rt].second);
        swap(p[rt].first,p[rt].second);
    }

    void pushdown(int rt){
        if(laz[rt])upd(rt<<1),upd(rt<<1|1),laz[rt] = 0;
    }

    void push_up(int rt){
        a[rt]=a[rt<<1|1]+a[rt<<1];
        p[rt]=p[rt<<1|1]+p[rt<<1];
    }


    pii query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return a[rt];
        else{
            pii ans(0,0);
            pushdown(rt);
            if(L<=mid)ans=ans+query(lson,L,R);
            if(R>mid)ans=ans+query(rson,L,R);
            push_up(rt);
            return ans;
        }
    }

    pll queryp(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return p[rt];
        else{
            pll ans(0,0);
            pushdown(rt);
            if(L<=mid)ans=ans+queryp(lson,L,R);
            if(R>mid)ans=ans+queryp(rson,L,R);
            push_up(rt);
            return ans;
        }
    }

    void update1(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)upd(rt);
        else{
            pushdown(rt);
            if(L<=mid)update1(lson,L,R);
            if(R>mid)update1(rson,L,R);
            push_up(rt);
        }
    }

    void update2(int rt,int l,int r,int P,int k){
        if(l==r){
            if(!laz[rt])a[rt].second+=1,p[rt].second+=k;
            else a[rt].first+=1,p[rt].first+=k;
            return;
        }
        pushdown(rt);
        if(P<=mid)update2(lson,P,k);
        if(P>mid)update2(rson,P,k);
        push_up(rt);
    }




}

namespace hld{

    int e,beg[maxn],nex[maxn<<1],to[maxn<<1],w[maxn],wt[maxn];
    int son[maxn],id[maxn],fa[maxn],cnt=0,dep[maxn],siz[maxn],top[maxn];

    void updRange(int x,int y){

        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            seg::update1(1,1,n,id[top[x]],id[x]);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        seg::update1(1,1,n,id[top[x]],id[x]);
    }
    void dfs1(int x,int f,int deep){

        dep[x]=deep;

        fa[x]=f;

        siz[x]=1;

        int maxson=-1;

        for(int i=beg[x];i;i=nex[i]){
            int y=to[i];
            if(y==f)continue;

            dfs1(y,x,deep+1);

            siz[x]+=siz[y];

            if(siz[y]>maxson)son[x]=y,maxson=siz[y];

        }
    }
    void dfs2(int x,int topf){

        id[x]=++cnt;

        wt[cnt]=w[x];

        top[x]=topf;

        if(!son[x])return;

        dfs2(son[x],topf);

        for(int i=beg[x];i;i=nex[i]){
            int y=to[i];
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);

        }
    }
    inline void add(int x,int y){

        to[++e]=y;
        nex[e]=beg[x];
        beg[x]=e;
    }
    void init(){
        dfs1(1,1,1);
        dfs2(1,1);
    }
}
vector<int>v;
int act[maxn];
pii vx[maxn];
int as[maxn];
int dfs(int x,int f){
    int now = act[x];
    for(int i=hld::beg[x];i;i=hld::nex[i]){
        int y=hld::to[i];
        if(y==f)continue;
        now+=dfs(y,x);
    }
    if(now&1&&act[x])v.push_back(as[x]);
    return now&1;
}
void solve() {
    rd(n);
    fo(i,0,n-1){
        int a,b;
        rd(a,b);
        hld::add(a,b),hld::add(b,a);
        vx[i]=minmax(a,b);
    }
    hld::init();
    seg::update2(1,1,n,1,0);hld::updRange(1,1);
    act[1] = 1;
    fo(i,0,n-1){
        auto [x,y]=vx[i];
        if(hld::fa[x]==y)as[x]= i + 1;
        else if(hld::fa[y]==x)as[y] = i+1;
    }
    while(1){
        int op;
        rd(op);
        if(op==2){
            auto p = seg::query(1,1,n,1,n);
            if(p.first!=p.second)otf(0,'\n');
            else{
                v.clear();
                dfs(1,1);
                sort(v.begin(),v.end());
                ot(v.size());
                for(int i:v)ot(' ',i);
                otf("\n");
            }
        }else if(op==1){
            int v;
            rd(v);
            act[v] = 1;
            if(v!=1)seg::update2(1,1,n,hld::id[v],as[v]);
            hld::updRange(1,v);
            auto p = seg::query(1,1,n,1,n);
            if(p.first!=p.second)otf(0,'\n');
            else otf(seg::queryp(1,1,n,1,n).fi,'\n');
        }else break;
    }

}

signed main() {

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    clock_node clockNode{};

    int t = 1;
    srand(time(nullptr));
    if (id0)rd(t);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    XYL_FAST_IO::out();

    clockNode.end_clock();
    freopen("CON", "w", stdout);
    freopen("1.out", "r", stdin);
    char seq[(1u << 20u) + 7];
    while (!feof(stdin))fwrite(seq, 1, fread(seq, 1, 1u << 20u, stdin), stdout);

    return 0;
}
