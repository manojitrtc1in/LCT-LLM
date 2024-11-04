
using namespace std;
 
 
namespace Rec{
    template<class Fun>
    class id2 {
        Fun fun_;
    public:
        template<class T>
        explicit id2(T &&fun): fun_(std::forward<T>(fun)) {}
 
        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };
 
    template<class Fun>
    decltype(auto) id0(Fun &&fun) {
        return id2<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }
}
 
 


struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(vector<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
 
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }
 
    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }
 
  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  

        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
 
 
using ll=long long;


 

















 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pii=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 





void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}




 
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
 
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}
 
template<int i,class T>
void print_tuple(ostream&,const T&){
}
 
template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}
 
template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}
 
template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}
 
ll read(){
	ll i;
	cin>>i;
	return i;
}
 
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}
 
template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}
 
string readString(){
	string s;
	cin>>s;
	return s;
}
 
template<class T>
T sq(const T& t){
	return t*t;
}
 


void yes(bool ex=true){
	
	cout<<"YES"<<"\n";
	
	cout<<"Yes"<<"\n";
	
	if(ex)exit(0);
}
void no(bool ex=true){
	
	cout<<"NO"<<"\n";
	
	cout<<"No"<<"\n";
	
	if(ex)exit(0);
}
void possible(bool ex=true){
	
	cout<<"POSSIBLE"<<"\n";
	
	cout<<"Possible"<<"\n";
	
	if(ex)exit(0);
}
void impossible(bool ex=true){
	
	cout<<"IMPOSSIBLE"<<"\n";
	
	cout<<"Impossible"<<"\n";
	
	if(ex)exit(0);
}
 
constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}
 
const ll infLL=LLONG_MAX/3;
 

const int inf=infLL;

const int inf=INT_MAX/2-100;

 
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool id1(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}
 
template<class t>
bool inc(t a,t b,t c){
	return a<=b&&b<=c;
}
 
template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}
 
ll rand_int(ll l, ll r) { 

	
	static mt19937_64 gen;
	
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
    return uniform_int_distribution<ll>(l, r)(gen);
}
 
template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}
 
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	

	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;

int TPTP[201000], ppar[201000][20];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	Scanner sc(stdin);
	Printer pr(stdout);
    int n, m;
    scanf("%d",&n);
    if(n==1){
        printf("0\n! 1 1\n");
        return 0;
    }
    vc<vi>E(n+1), Tr(n+1);
    vi D(n+1), D2(n+1), par(n+1), UU(n+1), Dep(n+1);
    rep(i,n-1){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].pb(b);
        E[b].pb(a);
    }

    auto Get = [&](int a, int pp) -> int{
        if(par[a]==pp) return D[a];
        return D2[pp];
    };

    auto DFS1 = Rec::id0([&](auto DFS1, int a, int pp) -> void {
        if(!pp)Dep[a]=0;
        else Dep[a]=Dep[pp]+1;
        par[a]=pp;
        ppar[a][0]=pp;
        rep(i,18)ppar[a][i+1]=ppar[ppar[a][i]][i];
        for(auto &x : E[a]){
            if(x==pp)continue;
            DFS1(x,a);
            Tr[a].pb(x);
        }
        if(Tr[a].empty()){
            D[a]=1;
            UU[a]=a;
            return;
        }
        vc<pii> TP;
        for(auto &x : Tr[a]){
            TP.pb({D[x],x});
        }
        sort(all(TP));
        reverse(all(TP));
        int r = 0, pv = -1;;
        rep(i,si(TP)){
            if(r < i+TP[i].fi){
                r = i+TP[i].fi;
                pv = TP[i].se;
            }
        }
        UU[a] = UU[pv];
        D[a] = r;
    });

    int MM = 0;

    auto DFS2 = Rec::id0([&](auto DFS2, int a) -> void {

        vc<pii>V;
        if(par[a]){
            V.pb({D2[a],par[a]});
        }
        for(auto &x : Tr[a]){
            V.pb({D[x], x});
        }
        sort(all(V));
        reverse(all(V));

        int d = si(V);
        vi ww(d), BB(d), EE(d);
        rep(i,d){
            ww[i] = V[i].fi+i;
            BB[i]=ww[i];
            EE[i]=ww[i];
            TPTP[V[i].se] = i;
        }

        rng(i,1,d-1) BB[i]=max(BB[i-1],BB[i]);
        gnr(i,d-2,0) EE[i]=max(EE[i],EE[i+1]);

        int rrr = max(d,BB[d-1]);
        rep(i,d-1){
            rrr = max(rrr, ww[i] - i - 1 + EE[i+1]);
        }
        MM = max(MM,rrr);
        for(auto &x : Tr[a]){

            int pv = TPTP[x];
            int rr = 1;
            if(pv!=0) rr = max(rr, BB[pv-1]);
            if(pv!=d-1) rr = max(rr, EE[pv+1]-1);

            D2[x] = rr;
        }

        for(auto &x : Tr[a]){
            DFS2(x);
        }
    });

    DFS1(1,0);
    DFS2(1);

    printf("%d\n",MM);
    fflush(stdout);

    int f;

    scanf("%d",&f);

    rng(i,1,n)Tr[i].clear();
    DFS1(f,0);

    vc<int>Ans;

    auto Go = Rec::id0([&](auto Go, int a, int ban, int cc) -> void {

        vc<pii>V;
        for(auto &x : Tr[a]){
            if(x==ban)continue;
            V.pb({D[x],x});
        }
        if(V.empty()){
            Ans.pb(a);
            return;
        }
        sort(all(V));
        reverse(all(V));

        for(auto &t : V){
            printf("? %d\n",UU[t.se]);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            
            if(x != a){
                cc--;
                if(x==UU[t.se]){
                    Ans.pb(x);
                }
                else{
                    int oo = UU[t.se];
                    while(par[oo]!=x)oo=par[oo];
                    Go(x,oo,1);
                }

                if(cc==0)break;
            }
        }
        rep(i,cc){
            Ans.pb(a);
        }

    });


    Go(f,0,2);

    printf("! %d %d\n",Ans[0],Ans[1]);

}