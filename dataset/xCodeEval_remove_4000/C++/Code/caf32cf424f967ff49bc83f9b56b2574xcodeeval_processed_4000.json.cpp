
















using namespace std;
typedef long long ll;












template<class T> 
inline void debug_v(const vector<T> &vec) {
    printf("vec: ");
    for (auto u : vec) cout << u << " ";
    cout << endl;
}

inline int cntOne(unsigned int x) {
    return __builtin_popcount(x);
}
inline int id1(unsigned long long x) {
    return __builtin_popcountll(x); 
}


inline ll qpow(ll a, int n) {
    ll ans = 1;
    for(; n; n >>= 1) {
        if(n & 1) ans *= 1ll * a;
        a *= a;
    }
    return ans;
}

template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll ksc(ll a, ll b, ll mod) {
    ll ans = 0;
    for(; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a * 2) % mod;
    }
    return ans;
}

ll ksm(ll a, ll b, ll mod) {
    ll ans = 1 % mod;
    a %= mod;

    for(; b; b >>= 1) {
        if (b & 1) ans = ksc(ans, a, mod);
        a = ksc(a, a, mod);
    }

    return ans;
}

template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool id2(vector<T> a, vector<T> b) {
    int n = a.size(), m = b.size();
    int i;
    for(i = 0; i < n && i < m; i++) {
        if (a[i] < b[i]) return true;
        else if (b[i] < a[i]) return false;
    }
    return (i == n && i < m);
}

constexpr int P = 998244353;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res *= a;
        a *= a;
    }
    return res;
}

struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}

    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P-x));
    }
    Z &operator *= (const Z &rhs) {
        x = (ll)(x) * rhs.x % P;
        return *this;
    }
    Z &operator += (const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator -= (const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator /= (const Z &rhs) {
        return *this *= rhs.inv();
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P-2);
    }
    friend Z operator* (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+ (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator- (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/ (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

struct Int {
    static constexpr int B = 10;
    vector<int> X;
    int size() const {
        return (int)X.size();
    }

    Int(int x = 0) {
        while (x) {
            X.push_back(x % B), x /= B;
        }
    }

    Int(string str) {
        reverse(str.begin(), str.end());
        for (auto u : str) X.push_back(u-'0');
    }

    friend Int operator+ (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return rhs + lhs;
        Int res;

        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t += lhs.X[i];
            if (i < rhs.size()) t += rhs.X[i];
            res.X.push_back(t % B), t /= B;
        }
        if (t) res.X.push_back(t);
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator- (const Int &lhs, const Int &rhs) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t = lhs.X[i] - t;
            if (i < rhs.size()) t -= rhs.X[i];
            res.X.push_back((t + B) % B);

            if (t < 0) t = 1;
            else t = 0;
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, int b) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.X.size() || t; i++) {
            if (i < lhs.X.size()) t += lhs.X[i] * b;
            res.X.push_back(t % B), t /= B;
        }
        return res;
    }

    friend Int operator/ (const Int &lhs, int b) {
        Int res;
        int r = 0;
        for (int i = lhs.X.size()-1; i >= 0; i--) {
            r = r * B + lhs.X[i];
            res.X.push_back(r / b), r %= b;
        }
        reverse(res.X.begin(), res.X.end());
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, const Int &rhs) {
        Int res;
        res.X.resize(lhs.size() + rhs.size() + B);
        fill(res.X.begin(), res.X.end(), 0);

        for (int i = 0; i < lhs.size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                res.X[i+j] += lhs.X[i] * rhs.X[j];
            }
        }
        for (int i = 0; i < res.X.size(); i++) {
            if (res.X[i] >= B) res.X[i+1] += res.X[i] / B, res.X[i] %= B;
        }

        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator/ (const Int& lhs, const Int &rhs) {
        int dv = lhs.size() - rhs.size();
        assert(dv >= 0);

        Int res;
        res.X.resize(dv+1);
        fill(res.X.begin(), res.X.end(), 0);

        

        Int a = lhs, b = rhs;
        reverse(b.X.begin(), b.X.end());
        for (int i = 0; i < dv; i++) b.X.push_back(0);
        reverse(b.X.begin(), b.X.end());

        for (int i = 0; i <= dv; i++) {
            while (b < a) {
                a = a-b;
                res.X[dv-i]++;
            }
            b.X.erase(b.X.begin());
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend bool operator< (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return true;
        if (lhs.size() > rhs.size()) return false;

        if (vector<int>(lhs.X.rbegin(), lhs.X.rend()) <= vector<int>(rhs.X.rbegin(), rhs.X.rend())) return true;
        return false;
    }
    void out() {
        reverse(X.begin(), X.end());
        for (auto x : X) printf("%d", x);
        printf("\n");
    }
};

Int max_int(const Int &A, const Int &B) {
    if (A < B) return B;
    else return A;
}




namespace fastIO{ 
	
	
	
	

	bool IOerror=0; 
	inline char nc(){ 
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
		if (p1==pend){ 
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
			if (pend==p1){IOerror=1;return -1;} 
			

		} 
		return *p1++; 
	} 
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
	inline void read(int &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(ll &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(double &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (ch=='.'){ 
			double tmp=1; ch=nc(); 
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
		} 
		if (sign)x=-x; 
	} 
	inline void read(char *s){ 
		char ch=nc(); 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
		*s=0; 
	} 
	inline void read(char &c){ 
		for (c=nc();blank(c);c=nc()); 
		if (IOerror){c=-1;return;} 
	} 
	

	inline void read1(int &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(ll &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(double &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (ch=='.'){ 
			double tmp=1; 
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar()); 
		} 
		if (bo)x=-x; 
	} 
	inline void read1(char *s){ 
		char ch=getchar(); 
		for (;blank(ch);ch=getchar()); 
		for (;!blank(ch);ch=getchar())*s++=ch; 
		*s=0; 
	} 
	inline void read1(char &c){for (c=getchar();blank(c);c=getchar());} 
	

	inline void read2(int &x){scanf("%d",&x);} 
	inline void read2(ll &x){ 
		
			scanf("%I64d",&x); 
		
		
			scanf("%lld",&x); 
		
			puts("error:can't recognize the system!"); 
		
		
	} 
	inline void read2(double &x){scanf("%lf",&x);} 
	inline void read2(char *s){scanf("%s",s);} 
	inline void read2(char &c){scanf(" %c",&c);} 
	

	

	struct id0{ 
		char *buf,*p1,*pend; 
		id0(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
		void out(char ch){ 
			if (p1==pend){ 
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
			} 
			*p1++=ch; 
		} 
		void print(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); out('\n'); 
		} 
		void print(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); out('\n'); 
		} 
		void print(double x,int y){ 
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
			if (x<-1e-12)out('-'),x=-x;x*=mul[y]; 
			ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
			ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
			if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];++i) out('0'); print(x3);} 
		} 
		void println(double x,int y){print(x,y);out('\n');} 
		void print(char *s){while (*s)out(*s++);} 
		void println(char *s){while (*s)out(*s++);out('\n');} 
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
		~id0(){flush();} 
	}Ostream; 
	inline void print(int x){Ostream.print(x);} 
	inline void println(int x){Ostream.println(x);} 
	inline void print(char x){Ostream.out(x);} 
	inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
	inline void print(ll x){Ostream.print(x);} 
	inline void println(ll x){Ostream.println(x);} 
	inline void print(double x,int y){Ostream.print(x,y);} 
	inline void println(double x,int y){Ostream.println(x,y);} 
	inline void print(char *s){Ostream.print(s);} 
	inline void println(char *s){Ostream.println(s);} 
	inline void println(){Ostream.out('\n');} 
	inline void flush(){Ostream.flush();} 
	

	char Out[OUT_SIZE],*o=Out; 
	inline void print1(int x){ 
		static char buf[15]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(int x){print1(x);*o++='\n';} 
	inline void print1(ll x){ 
		static char buf[25]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(ll x){print1(x);*o++='\n';} 
	inline void print1(char c){*o++=c;} 
	inline void println1(char c){*o++=c;*o++='\n';} 
	inline void print1(char *s){while (*s)*o++=*s++;} 
	inline void println1(char *s){print1(s);*o++='\n';} 
	inline void println1(){*o++='\n';} 
	inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}} 
	struct puts_write{ 
		~puts_write(){flush1();} 
	}_puts; 
	inline void print2(int x){printf("%d",x);} 
	inline void println2(int x){printf("%d\n",x);} 
	inline void print2(char x){printf("%c",x);} 
	inline void println2(char x){printf("%c\n",x);} 
	inline void print2(ll x){ 
		
			printf("%I64d",x); 
		
		
			printf("%lld",x); 
		
			puts("error:can't recognize the system!"); 
		
		
	} 
	inline void println2(ll x){print2(x);printf("\n");} 
	inline void println2(){printf("\n");} 
	
	
	
}; 
using namespace fastIO; 

const int maxn = 1e6 + 5;
int n, q, a[maxn];

template<class T>
struct Fenwick {
    int n;
    vector<T> C;
    Fenwick() = default;
    Fenwick(int n) : n(n) {
        C.resize(n+1);
        fill(C.begin(), C.end(), 0);
    }
    Fenwick(vector<T> x) {
        C = x;
        this->n = C.size();
    }
    void clear() {
        fill(C.begin(), C.end(), 0);
    }

    T sum(T x) {
        T res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) res += C[i];
        return res;
    }
    void add(int x, int d) {
        for (int i = x; i <= n; i += lowbit(i)) C[i] += d;
    }

    int kth(T x) {
        assert(x >= 0);
        int lg = 20;
        int p = 0;

        for (int j = lg; j >= 0; j--) {
            if (p + (1<<j) <= n && C[p + (1<<j)] < x) {
                p += (1<<j), x -= C[p];
            }
        }
        return p;
    }
};

struct A {
    int l, k, id;
};

vector<A> qry[maxn];
vector<int> G[maxn];

int cnt[maxn];
set<int> num[maxn];
int ans[maxn];
void dfs(int u, Fenwick<int> &fen) {
    if (cnt[a[u]]) {
        fen.add(cnt[a[u]], -1), num[cnt[a[u]]].erase(a[u]);
    }
    cnt[a[u]]++, fen.add(cnt[a[u]], 1), num[cnt[a[u]]].insert(a[u]);

    

    for (auto x : qry[u]) {
        int l = x.l, k = x.k;
        int k0 = fen.sum(l-1), m = fen.sum(n);
        

        if (k0 + k > m) {
            ans[x.id] = -1;
            continue;
        }

        int res = fen.kth(k0 + k) + 1;
        

        

        ans[x.id] = *num[res].begin();
    }
    
    for (auto v : G[u]) dfs(v, fen);

    fen.add(cnt[a[u]], -1), num[cnt[a[u]]].erase(a[u]);
    cnt[a[u]]--;
    if (cnt[a[u]]) fen.add(cnt[a[u]], 1), num[cnt[a[u]]].insert(a[u]);
}

void init(int n) {
    for (int i = 0; i <= n; i++) G[i].clear(), qry[i].clear(), num[i].clear();

    for (int i = 0; i <= n; i++) cnt[i] = 0;
}

int main() {
    

    int cas;
    read(cas);
    while (cas--) {
        read(n), read(q);
        init(n);

        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 2; i <= n; i++) {
            int pi; read(pi);
            G[pi].push_back(i);
        }

        for (int i = 1; i <= q; i++) {
            int u, l, k;
            read(u), read(l), read(k);
            qry[u].push_back(A{ l, k, i });
        }

        

        Fenwick<int> fen(n+1);
        dfs(1, fen);
        for (int i = 1; i <= q; i++) println(ans[i]);
    }
}