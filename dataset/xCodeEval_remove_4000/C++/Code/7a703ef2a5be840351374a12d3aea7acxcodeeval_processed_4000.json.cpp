












using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct LL {

    static const long long int m = MOD; 

    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

    static vector<LL> F; 

    static vector<LL> I; 

    static void loadFactorials(int n) {
        while (F.size() <= n) {
            int k = F.size();
            F.pb(F.back()*k);
            I.pb(I.back()/k);
        }
    }

    static LL binom(long long int top, long long int bot) {
        assert(top > 0);
        assert(bot > 0);
        if (top < bot) return 0;
        loadFactorials(top);
        return F[top]*I[bot]*I[top-bot];
    }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
vector<LL> LL::F = vector<LL>(1,1);
vector<LL> LL::I = vector<LL>(1,1);



tc(T) vector<T> readVector(int sz) {
    vector<T> ret;
    for (int i = 0; i < sz; i++) {
        T x; cin >> x;
        ret.pb(x);
    }
    return ret;
}
tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}
tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}
tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}
tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}





ll P2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

template <typename T>
struct ST { 

    T val, add, mult;
    ST *L, *R;
    char lv;

    ST(int lvv = 0, T vall = 0, ST* le = nullptr, ST* ri = nullptr) : lv(lvv),val(vall),L(le),R(ri),add(0),mult(1) {}

    void push() {
        if (!(add == 0 && mult == 1)) {
            if (L == nullptr) L = new ST<T>(lv-1);
            if (R == nullptr) R = new ST<T>(lv-1);
            L->val*=mult; L->val+=add*P2[lv-1];
            R->val*=mult; R->val+=add*P2[lv-1];
            L->mult*=mult;
            L->add*=mult; L->add+=add;
            R->mult*=mult;
            R->add*=mult; R->add+=add;
            add=0; mult=1;
        }
    }

    

    void update(ll tl, ll tr, ll l, ll r, T a, T m) {
        if (l > r) return;
        if (l == tl && r == tr) {
            val = a * (tr - tl + 1) + val * m;
            mult *= m;
            add *= m; add += a;
        }
        else {
            if (L == nullptr) L = new ST<T>(lv-1);
            if (R == nullptr) R = new ST<T>(lv-1);
            push();
            ll tm = (tl + tr) / 2;
            L->update(tl, tm, l, min(r, tm), a, m);
            R->update(tm + 1, tr, max(l, tm + 1), r, a, m);
            val = L->val + R->val;
        }
    }
    T query(ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        push();
        if (l <= tl && r >= tr) return val;
        ll tm = (tl + tr) / 2;
        if (L == nullptr) L = new ST<T>(lv-1);
        if (R == nullptr) R = new ST<T>(lv-1);
        return L->query(tl, tm, l, min(r, tm))
                +R->query(tm + 1, tr, max(l, tm + 1), r);
    }
    void update(ll l, ll r, T a, T m) { update(0, P2[lv]-1, l, r, a, m); }
    T query(ll l, ll r) { return query(0, P2[lv]-1, l, r); }

    void display(int pos = 1) {
        cout << pos << ": " << val << " | " << add << " + " << mult << "x" << endl;
        if (L!=nullptr) L->display(2*pos);
        if (R!=nullptr) R->display(2*pos+1);
    }
};


struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    vector<ll> seg;
    vector<ll> lazy;
    vector<ll> mark;

    int n;

    Cheese(int n){start(n);}

    void start(int n) {
        this->n = n;
        for (int i = 0; i < 4*n+5; i++) { seg.pb(0);lazy.pb(0);mark.pb(0); }
    }

    void push(int v, int tl, int tr) {
        if (mark[v]) {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            mark[2 * v] = true;
            mark[2 * v + 1] = true;
            int tm = (tl + tr) / 2;
            seg[2 * v] = lazy[2 * v] * (tm - tl + 1);
            seg[2 * v + 1] = lazy[2 * v + 1] * (tr - tm);
            mark[v] = false;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int rep) {
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] = rep;
            mark[v] = true;
            seg[v] = rep * (tr - tl + 1);
        }
        else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), rep);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
            seg[v] = seg[2 * v + 1] + seg[2 * v];
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        push(v, tl, tr);
        if (l <= tl && r >= tr) return seg[v];
        int tm = (tl + tr) / 2;
        return (query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int l, int r, int rep) { update(1, 0, n-1, l, r, rep); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }


};

string bin(int n)
{
    string out = "";
    if (n > 1)
        out = bin(n / 2);

    
    return out + to_string(n % 2);
}

bool ch(string s,char x) {
    int N = s.size();
    for (int i = 0; i < N-1; i++) {
        if (s.at(i) == s.at(i+1))
            if (s.at(i)==x) return false;
    }
    return true;
}

int N; int M;
vector<vector<int>> A;
bool check(int i, int j) {
    bool ok = (A[i][j] == 1);
    ok |= (A[i-1][j] <= A[i][j]);
    ok |= (A[i][j-1] <= A[i][j]);
    ok |= (A[i+1][j] <= A[i][j]);
    ok |= (A[i][j+1] <= A[i][j]);
    return ok;
}
int spread(int i, int j, int x, int y) {
    pii d = {i-x,j-y};
    int ret = 0;
    if (d==mp(-1,-1)) {
        ret += !check(i-1,j);
        

        ret += !check(i,j);
        ret += !check(i,j-1);
        

        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(-1,0)) {
        ret += !check(i-1,j);
        

        

        ret += !check(i,j-1);
        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(-1,1)) {
        ret += !check(i-1,j);
        

        ret += !check(i,j);
        

        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(0,-1)) {
        ret += !check(i-1,j);
        ret += !check(i+1,j);
        

        ret += !check(i,j-1);
        

        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(0,0)) {
        

        

        

        

        

        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(0,1)) {
        ret += !check(i-1,j);
        ret += !check(i+1,j);
        

        

        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(1,-1)) {
        

        ret += !check(i+1,j);
        ret += !check(i,j);
        ret += !check(i,j-1);
        

        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(1,0)) {
        

        ret += !check(i+1,j);
        

        ret += !check(i,j-1);
        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(1,1)) {
        

        ret += !check(i+1,j);
        ret += !check(i,j);
        

        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(-2,0)) {
        ret += !check(i-1,j);
        

        ret += !check(i,j);
        ret += !check(i,j-1);
        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(2,0)) {
        

        ret += !check(i+1,j);
        ret += !check(i,j);
        ret += !check(i,j-1);
        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(0,-2)) {
        ret += !check(i-1,j);
        ret += !check(i+1,j);
        ret += !check(i,j);
        ret += !check(i,j-1);
        

        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    if (d==mp(0,2)) {
        ret += !check(i-1,j);
        ret += !check(i+1,j);
        ret += !check(i,j);
        

        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    } else
    {
        ret += !check(i-1,j);
        ret += !check(i+1,j);
        ret += !check(i,j);
        ret += !check(i,j-1);
        ret += !check(i,j+1);
        ret += !check(x-1,y);
        ret += !check(x+1,y);
        ret += !check(x,y);
        ret += !check(x,y-1);
        ret += !check(x,y+1);
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    A.pb(vector<int>(M+4,999999));
    A.pb(vector<int>(M+4,999999));
    for (int i = 2; i <= N+1; i++) {
        A.pb(vector<int>());
        A[i].pb(999999);
        A[i].pb(999999);
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            A[i].pb(x);
        }
        A[i].pb(999999);
        A[i].pb(999999);
    }
    A.pb(vector<int>(M+4,999999));
    A.pb(vector<int>(M+4,999999));

    int x = -1;
    int y = -1;
    int c = 0;
    for (int i = 2; i <= N+1; i++) {
        for (int j = 2; j <= M+1; j++) {
            if (!check(i,j)) {
                x = i; y = j; ++c;
            }
        }
    }

    int t = 0;

    if (x == -1 && y == -1) {
        cout << 0 << endl;
    } else {
        int ans = 0;
        for (int i = 2; i <= N+1; i++) {
            for (int j = 2; j <= M+1; j++) {
                if (x == i && y == j) continue;
                int l = c-(spread(i,j,x,y));
                swap(A[i][j],A[x][y]);
                ans += (t == l+(spread(i,j,x,y)));
                swap(A[i][j],A[x][y]);
                if ((x != i + 1 || y != j) && (x != 2)) {
                    int k = c-(spread(i,j,x-1,y));
                    swap(A[i][j],A[x-1][y]);
                    ans += (t == k+(spread(i,j,x-1,y)));
                    swap(A[i][j],A[x-1][y]);
                }
                if ((x != i - 1 || y != j) && (x != N+1)) {
                    int k = c-(spread(i,j,x+1,y));
                    swap(A[i][j],A[x+1][y]);
                    ans += (t == k+(spread(i,j,x+1,y)));
                    swap(A[i][j],A[x+1][y]);
                }
                if ((x != i || y != j + 1) && (y != 2)) {
                    int k = c-(spread(i,j,x,y-1));
                    swap(A[i][j],A[x][y-1]);
                    ans += (t == k+(spread(i,j,x,y-1)));
                    swap(A[i][j],A[x][y-1]);
                }
                if ((x != i || y != j - 1) && (y != M+1)) {
                    int k = c-(spread(i,j,x,y+1));
                    swap(A[i][j],A[x][y+1]);
                    ans += (t == k+(spread(i,j,x,y+1)));
                    swap(A[i][j],A[x][y+1]);
                }
                

            }
        }
        if (ans) cout << 1 << " " << ans << endl;
        else cout << 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (0) { 

        int T; cin >> T;
        while (T--) solve();
    } else solve();
}
