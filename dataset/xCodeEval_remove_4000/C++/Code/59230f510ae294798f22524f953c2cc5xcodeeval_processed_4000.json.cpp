





































using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef long double dbl;
struct LL {

    static ll m; 

    ll val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static ll reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
ll LL::m = mod;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;






























ll cases,N,M,Q,K,X,Y;





ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}
tcc(S,T) void rdv(vector<S>& vec, T* sz, bool flag = 1) {
    if (flag) *sz = rd();
    F0(i,*sz) vec.pb(rd());
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
void ds(char* v) { cout << v << " "; }
tc(T) void ds(T* v, int t) {
    auto x = v;
    F0(i,t) ds(*(x++)); cout << endl;
}
tcc(S,T) void ds(pair<S,T> v) {cout << "( "; ds(v.f); cout << ", "; ds(v.s); cout << ") ";}
tc(T) void ds(vector<T> v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { ds(out); exit(0); }

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



bool witness(LL a, ll d, ll m) {
    LL x = LL::exp(a,m);
    if (x==LL(1)) return 1;
    F0(r,d) {
        if (x==LL(-1)) return 1;
        x = x*x;
    }
    return 0;
}



bool isPrime(ll x) {
    if (x < T5) {
        ll j = 2;
        while (j*j <= x) {
            if (x%j==0) return 0;
            ++j;
        }
        return 1;
    }
    ll d = 0;
    ll m = 0;
    ll y = x;
    ll cur = LL::m;
    LL::m = x;
    bool ret = 1;
    while (y>>=1) {
        ++d; if (y&1) break;
    }
    m = y;
    

    ret = witness(LL(2),d,m)
            && witness(LL(13),d,m)
            && witness(LL(23),d,m)
            && witness(LL(1662803),d,m);
    LL::m = cur;
    return ret;
}




ll gcd(ll a, ll b) {
    return b?gcd(b, a % b):a;
}

bool cmp(pii a, pii b) {
    return 1;
}

pii pl(pii a, pii b) {
    return {a.f+b.f,a.s+b.s};
}
bool inrange(pii a) {
    return (a.f>=0)&&(a.f<=K)&&(a.s>=0)&&(a.s<=K);
}

int query(int k) {
    cout << "? " << k << endl; fl();
    return rd();
}

bool debug = 0;

void precalc() {
    debug=0;
}

void reset() {
}

struct Splay {

    int val;
    Splay *L,*R,*P,*PP;

    Splay() { L=R=P=PP=nullptr; }
    Splay(int _val) : val(_val) { L=R=P=PP=nullptr; }

    bool isR() {
        return P->R==this;
    }

    void setL(Splay* const C) {
        if (C!=nullptr) C->P=this;
        L=C;
    }

    void setR(Splay* const C) {
        if (C!=nullptr) C->P=this;
        R=C;
    }

	void rotate() {
		const auto p = P;
		const bool i = isR();

		if (p->P != nullptr) {
			if (p->isR()) p->P->setR(this);
			else p->P->setL(this);
		} else P = nullptr;

		if (i) {
            p->setR(L);
            setL(p);
		} else {
		    p->setL(R);
		    setR(p);
		}

		PP=p->PP;
	}

	void yeet() {
	    for (;P!=nullptr;rotate()) {
            if (P->P!=nullptr) {
                if (isR() == P->isR()) P->rotate();
                else this->rotate();
            }
            if(debug) {this->print(); cout << endl;}
	    }
	}

	void print() {
	    cout << val << "[";
	    if (L) cout << L->val; cout << ",";
	    if (R) cout << R->val; cout << "]" << endl;
	    if (L) L->print();
	    if (R) R->print();
	}

};

Splay* access(Splay* V) {
    V->yeet();
    if (V->R != nullptr){
        V->R->PP = V;
        V->R->P = nullptr;
    }
    V->R = nullptr;
    Splay* P = V;
    while (V->PP != nullptr) {
        P = V->PP;
        P->yeet();
        if (P->R != nullptr){
            P->R->PP = P;
            P->R->P = nullptr;
        }
        P->setR(V);
        V->PP = nullptr;
        V->yeet();
    }
    return P;
}

Splay* root(Splay* V) {
    access(V);
    for (;V->L != nullptr; V=V->L);
    access(V);
    return V;
}

void cut(Splay* V) {
    access(V);
    if (V->L == nullptr) return;
    V->L->P=nullptr;
    V->L=nullptr;
}

Splay* lca(Splay* U, Splay* V) {
    if (root(U) != root(V)) return nullptr;
    access(U);
    return access(V);
}

void link(Splay* U, Splay* V) {
    if (lca(U,V)==V) link(V,U);
    else {
        access(V);
        access(U);
        V->setL(U);
    }
}

void cut(Splay* U, Splay* V) {
    if (lca(U,V)==U) cut(V);
    else cut(U);
}

bool conn(Splay* U, Splay* V) {
    return (root(U) == root(V));
}

Splay* T[H];



ll P2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

template <typename T>
struct ST { 

    T val, add, mult;
    ST *L, *R;
    int lv;

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
    LL query(ll l, ll r) { return query(0, P2[lv]-1, l, r); }


    
    void display(int pos = 1) {
        cout << pos << ": " << val << " | " << add << " + " << mult << "x" << endl;
        if (L!=nullptr) L->display(2*pos);
        if (R!=nullptr) R->display(2*pos+1);
    }
    
};


void read() {
    ST<LL> ret(30);
    ll BIG = P2[30]-1;
    N=rd()-1;
    ret.update(1,rd(),1,1);
    F0(i,N) {
        int k = rd();
        
        ret.update(1,k,ret.query(1,BIG),-1);
        ret.update(k+1,BIG,0,0);
    }
    ds(ret.query(1,BIG));
}

int main() {

    precalc();

    bool trials = 0;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

}
