
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



int D[101000][2];
int U[101000][2];
vc<pii>Ans;
vc<vi>TT;

int TraceU(int a, int ck, int pp);

int TraceD(int a, int ck, int pp)  {

    


    vi Z;
    for(auto &x : TT[a]){
        if(x==pp)continue;
        Z.pb(x);
    }

    int m = si(Z);

    
    int s=0;
    for(auto &x : Z){
        s += U[x][1];
    }

    if(m%2==0){

        if(ck==0){

            vi O;
            for(auto &x : Z){
                O.pb(TraceU(x,1,a));
            }
            rep(i,si(O)/2){
                Ans.pb({O[i*2],O[i*2+1]});
            }

            return 0;
        }
        else{
            vi O;
            for(auto &x : Z){
                if(D[a][1] == s - (m-1)/2 + U[x][0] - U[x][1]){

                    for(auto &y : Z){
                        if(x!=y)O.pb(TraceU(y,1,a));
                    }
                    rep(i,si(O)/2){
                        Ans.pb({O[i*2],O[i*2+1]});
                    }
                    TraceU(x,0,a);
                    return O.back();
                }
            }

        }
        
    }
    if(m%2==1){        
        if(ck==0){

            vi O;
            for(auto &x : Z){
                O.pb(TraceU(x,1,a));
            }
            rep(i,si(O)/2){
                Ans.pb({O[i*2],O[i*2+1]});
            }

            return O.back();

        }
        else{
            vi O;
            for(auto &x : Z){
                if(D[a][1] == s - (m-1)/2 + U[x][0] - U[x][1]){

                    for(auto &y : Z){
                        if(x!=y)O.pb(TraceU(y,1,a));
                    }
                    rep(i,si(O)/2){
                        Ans.pb({O[i*2],O[i*2+1]});
                    }
                    TraceU(x,0,a);
                    return 0;
                }
            }
        }

    }
    return 0;
    
};


int TraceU(int a, int ck, int pp){
    


    vi Z;
    for(auto &x : TT[a]){
        if(x==pp)continue;
        Z.pb(x);
    }


    int m = si(Z);
    
    if(Z.empty()){
        if(ck==1)return a;
        return 0;
    }


    
    if(m%2==0){
        if(ck==1){
            if(U[a][1] == D[a][0]+1){
                TraceD(a,0,pp);
                return a;
            }
            else{
                return TraceD(a,1,pp);
            }
        }
        else{
            TraceD(a,0,pp);
            return 0;
        }
    }
    else{
        if(ck==1){
            if(U[a][1] == D[a][0]){
                return TraceD(a,0,pp);
            }
            else{
                TraceD(a,1,pp);
                return a;
            }
        }
        else{
            int t = TraceD(a,0,pp);
            Ans.pb({t,a});
            return 0;
        }
    }
    
};

int main(){
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	Scanner sc(stdin);
	Printer pr(stdout);

    while(1){

        int n, m;
        sc.read(n,m);
        if(n==0 && m==0)break;
        vc<vi>E(n+1);
        rep(i,m){
            int c;
            sc.read(c);
            vi T(c);
            rep(j,c){
                sc.read(T[j]);
                if(j){
                    E[T[j-1]].pb(T[j]);
                    E[T[j]].pb(T[j-1]);
                }
            }
        }

        

        {
            
            vc<vi>G(n+1);
            vi vis(n+1);
            vi par(n+1);
            int cnt = 0;

            auto DFS = Rec::id0([&](auto DFS, int a) -> void {
                vis[a]=++cnt;
                for(auto &x : E[a]){
                    if(vis[x])continue;
                    par[x] = a;
                    DFS(x);
                }
            });

            DFS(1);

            set<pii>Set;

            rng(i,1,n){
                for(auto &x : E[i]){
                    if(vis[i]>vis[x])continue;
                    if(par[x]==i)continue;
                    int t = x;
                    Set.insert({x,i});
                    while(t!=i){
                        Set.insert({t,par[t]});
                        t=par[t];
                    }
                }
            }
            rng(i,1,n){
                for(auto &x : E[i]){
                    if(i>=x)continue;
                    if(Set.find(pii(i,x))==Set.end() && Set.find(pii(x,i)) == Set.end()){
                        G[i].pb(x);
                        G[x].pb(i);
                    }
                }
            }
            E = G;
        }

        {
            vi vis(n+1);
            
            auto DFS = Rec::id0([&](auto DFS, int a, int pp) -> void {
                vis[a]=1;
                vi Z;
                for(auto &x : E[a]){
                    if(x==pp)continue;
                    DFS(x, a);
                    Z.pb(x);
                }
                
                if(Z.empty()){
                    D[a][0]=D[a][1]=0;
                    U[a][0] = 0;
                    U[a][1] = 1;
                    return;
                }

                int s=0;
                for(auto &x : Z){
                    s += U[x][1];
                }

                int m = si(Z);
                
                D[a][0] = s - m/2;
                D[a][1] = 1e9;
                
                for(auto &x : Z){
                    D[a][1] = min(D[a][1], s - (m-1)/2 + U[x][0] - U[x][1]);
                }
                if(m%2==0){
                    U[a][1] = min(D[a][0]+1,D[a][1]);
                    U[a][0] = D[a][0];
                }
                else{
                    U[a][1] = min(D[a][0], D[a][1]+1);
                    U[a][0] = D[a][0];
                }

            });

            int res=0;
            Ans.clear();
            TT = E;
            rng(i,1,n){
                if(!vis[i]){
                    DFS(i, 0);
                    int c = min(D[i][0],D[i][1]);
                    if(c){
                        int z;
                        if(c==D[i][0]){
                            z=TraceD(i,0,0);
                        }
                        else{
                            z=TraceD(i,1,0);
                        }
                        if(z){
                            Ans.pb({z,i});
                        }
                    }
                }
            }
            printf("%d\n",si(Ans));
            for(auto &t: Ans)printf("%d %d\n",t.fi,t.se);
        }
    }

}