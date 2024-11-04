


















using namespace std;








































struct InputReader{
	
	char buf[bs]; int p;
	il InputReader(){ p = bs; }
	il void Flush(){ p = 0; fread(buf,1,bs,stdin); }
	il char C(){ if(p >= bs) Flush(); return buf[p++]; }
	il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }
	il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }
	int operator() (){
		int ans = 0, fu = 1; char ch = Readnum();
		if( ch == '-' ) fu = -1, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10 + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL, fu = 1LL; char ch = Readnum();
		if( ch == '-' ) fu = -1LL, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10LL + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear(); char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '-'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '-'  ||  ch == '.' ){
			x += ch;
			ch = C();
		}
	}
	il void Readchstring( char s[] ){
		int len = 0; char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)   ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)   ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
	il void Specialread( char &c ){ c = C();
		while( c != '>'  &&  c != '<'  &&  c != '='  &&  c != 'B' ) c = C();
	}
	
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){ x1 = In(); x2 = In(); x3 = In(); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ x1 = In(); x2 = In(); x3 = In(); x4 = In(); }
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll(); }













il void FILEIO(){
	
		Fin("in.in");
	
}
il void FILEIO( string pname ){
	Fin((pname+".in").c_str());
	
		Fout((pname+".out").c_str());
	
}
void Printtime(){
	
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }




















using namespace std;
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
	cout << endl;
}




















	
	
	
	
	
	
	mt19937 rng;
	
	
	

	
	
	





namespace Datagenerating{
	string Tostring( int a ){
		string ret;
		while(a){ ret += a%10+'0'; a /= 10; }
		reverse(All(ret));
		return ret;
	}
	int Toint( string s ){
		int len = s.length();
		int a = 0;
		For0(i,len){ a *= 10; a += s[i]-'0'; }
		return a;
	}
	int Randneq( int lim , int neq ){
		int ret = neq;
		while( ret == neq ) ret = Rand(lim);
		return ret;
	}
	int id0( int a , int b , int neq ){
		int ret = neq;
		while( ret == neq ) ret = Randr(a,b);
		return ret;
	}
}




namespace Graph{
	struct Dsu{
		
		int dsu[DSU];
		void Init( int n ){ Forx(i,0,n) dsu[i] = i; }
		int Findfa( int pos ){ return dsu[pos]==pos ? pos : dsu[pos]=Findfa(dsu[pos]); }
		int operator[]( int pos ){ return Findfa(pos); }
		bool Same( int a , int b ){ return Findfa(a) == Findfa(b); }
		bool Unite( int a , int b ){ return (a=Findfa(a))==(b=Findfa(b)) ? 0 : (dsu[a]=b,1); }
	};
	struct E{
		int f,t; int c;
		E(){}
		E( int fi , int ti , int ci ){ f = fi; t = ti; c = ci; }
		bool operator<( E b ){ return c > b.c; }
	};
	struct Edge{
		int to; ll cost;
		Edge(){}
		Edge( int ti , ll ci ){ to = ti; cost = ci; }
	};
}



	
	
	
	

int dx4[] = {0,-1,0,1};
int dy4[] = {1,0,-1,0};








int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};




	
	
	
	int sed = 0;
	il void Srand(){ srand(time(0)*(ull)(new char)); sed = rand(); }
	




ll p;

















namespace Maths{
	_tp<_tyn T>T Gcd( T a , T b ){ return b?Gcd(b,a%b):a; }
	ll Pow( rg ll a , rg ll b ){
		rg ll ret = 1;
		for( ; b ; a = a*a%MOD, b >>= 1LL )
			if(b&1LL) ret = ret*a%MOD;
		return ret;
	}
	_tp<_tyn T> T Pow( rg T a , rg ll b ){
		rg T ret = 1;
		for( ; b ; a = a*a, b >>= 1LL )
			if(b&1LL) ret = ret*a;
		return ret;
	}
	ll Inv( ll a ){ return Pow(a,MOD-2LL); }
	ll Frac( ll x ){
		ll ret = 1;
		For(i,x) ret = ret*i % MOD;
		return ret;
	}
}




namespace Datastructure{
	_tp<_cl T>struct Bit{
		
		
		

		T tree[BIT];
		Bit(){ Ms(tree); }
		void Add( rg int pos , rg T x ){
			for( ; pos < BIT ; pos += Lowbit(pos) ){
				tree[pos] += x;
				
					Mymod(tree[pos]);
				
			}
		}
		T Sum( rg int pos ){
			rg T ret = 0;
			for( ; pos ; pos -= Lowbit(pos) ){
				ret += tree[pos];
				
					Mymod(ret);
				
			}
			return ret;
		}
		T Sum( rg int l , rg int r ){
			
				return Rmo(Sum(r) - Sum(l-1));
			
				return Sum(r) - Sum(l-1);
			
		}
	};
}




namespace Networkflow{
	
	int S = NET-2;
	int T = NET-1;
	int id3 = NET-4;
 	int id2 = NET-3;
	struct Edge{
		int to,rev,id; ll cap; int cost;
		Edge(){}
		Edge( int ti , ll ci , int ri , int coi , int iid = -2333333 ){
			to = ti; cap = ci; rev = ri; cost = coi; id = iid;
		}
	};
	vc<Edge> e[NET];
	il void Link( int f , int t , ll c , int co = 0 , int id = -2333333 ){
		

		e[f].Pb( Edge( t , c , e[t].size() , co , id ) );
		e[t].Pb( Edge( f , 0 , e[f].size()-1 , -co , id==-2333333?id:-id ) );
	}
	int in[NET], out[NET];
	il void Links( int a , int b , ll lower , ll upper , int id = 0 ){
		if(id) Link(a,b,upper-lower,0,id); else Link(a,b,upper-lower);
		in[b] += lower; out[a] += lower;
	}
	il int Smooth(){
		rg int tot = 0;
		For(i,NET-1){
			if( in[i] > out[i] ){ Link(S,i,in[i]-out[i]); tot += in[i]-out[i]; }
			elif( in[i] < out[i] ){ Link(i,T,out[i]-in[i]); }
		}
		return tot;
	}
	void Cleargraph(){ Ms(in); Ms(out); For0(i,NET) e[i].clear(); }

	int lev[NET];
	queue<int> q;
	bool Bfs(){
		Msn(lev,-1);
		q.push(S); lev[S] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			For0(i,e[u].size()){
				int v = e[u][i].to;
				if( ~lev[v] || !e[u][i].cap ) continue;
				lev[v] = lev[u]+1; q.push(v);
			}
		}
		return ~lev[T];
	}
	ll Dfs( int pos , ll flow ){
		if( pos == T ) return flow;
		ll used = 0;
		For0(i,e[pos].size()){
			int v = e[pos][i].to; ll co = e[pos][i].cap;
			if( lev[v] != lev[pos]+1 || !co ) continue;
			ll w = Dfs(v,min(flow - used,co));
			if(w){
				e[pos][i].cap -= w;
				e[v][e[pos][i].rev].cap += w;
				used += w;
			}
			if( used == flow ) break;
		}
		if(!used) lev[pos] = -1;
		return used;
	}
	ll Dinic(){
		rg ll ans = 0;
		while(Bfs()) ans += Dfs(S,INF);
		return ans;
	}

	ll dis[NET];
	bool inque[NET];
	int prevdot[NET], prevedge[NET];
	
	bool Spfa(){
		For0(i,NET) dis[i] = LINF;

		Ms(inque); q.push(S);
		dis[S] = 0; inque[S] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			inque[u] = 0;
			For0(i,e[u].size()){
				Edge nowe = e[u][i];
				if( nowe.cap <= 0 ) continue;
				int v = nowe.to;
				if( dis[v] > dis[u] + nowe.cost ){
					dis[v] = dis[u] + nowe.cost;
					prevdot[v] = u; prevedge[v] = i;
					if(!inque[v]){ inque[v] = 1; q.push(v); }
				}
			}
		}
		return dis[T] != LINF;
	}
	ll Refresh(){
		int u = T;
		ll flow = LINF;
		while( u != S ){ Mymin(flow,PREV(u).cap); u = prevdot[u]; }
		u = T;
		while( u != S ){
			PREV(u).cap -= flow;
			e[u][PREV(u).rev].cap += flow;
			u = prevdot[u];
		}
		return flow;
	}
	
	
	pll id4(){
		ll ans = 0; ld flow = 0;
		while(Spfa()){
			ll tflow = Refresh();
			ll tans = tflow * dis[T];
			ans += tans; flow += tflow;
		}
		return Mp(ans,flow);
	}
	
}







namespace Bitset{
	int Len( ll a ){
		int ret = 0;
		while(a){ a >>= 1LL; ret++; }
		return ret;
	}
}




namespace Geometry{
	_tp<_cl T>struct Point{
		T x,y;
		Point(){ x = y = 0; }
		Point( T ai , T bi ){ x = ai; y = bi; }
		T norm2(){ return Sqr(x) + Sqr(y); }
		ld norm(){ return sqrt(norm2()); }
		void Print(){ cout << x << " " << y << endl; }
		Point operator+( Point<T> v ){ return Point(x+v.x,y+v.y); }
		Point operator-( Point<T> v ){ return Point(x-v.x,y-v.y); }
		T operator*( Point<T> v ){ return x*v.y - y*v.x; }
		T Dis2( Point<T> v ){ return (v-*this).norm2(); }
		ld Dis( Point<T> v ){ return sqrt(Dis2(v)); }
		bool operator!=( Point<T> v ){ return x!=v.x || y!=v.y; }
		bool operator<( Point<T> v )const{ return x!=v.x ? x<v.x : y<v.y; }
	};
	_tp<_tyn T>bool Turnright( Point<T> a , Point<T> b , Point<T> c ){
		return (c-b) * (b-a) > 0;
	}
	bool id1( Point<ld> a , Point<ld> b , Point<ld> c ){
		return (c-b) * (b-a) > Eps;
	}
}




namespace Mat{
	
	_tp<_cl T>struct Matrix{
		int n,m;
		T d[MAT][MAT];
		Matrix(){ Ms(d); }
		Matrix( int ni , int mi = -233 ){
			n = ni;
			m = mi==-233 ? ni : mi;
			Ms(d);
			if( mi == -233 )
				Forx(i,0,n)
					d[i][i] = 1;
		}
	};
	_tp<_tyn T> Matrix<T> operator*( rg const Matrix<T> &a , rg const Matrix<T> &b ){
		if( a.m != b.n ) ERR("[MartixMul] a.m != b.n");
		Matrix<T> c;
		c.n = a.n; c.m = b.m;
		

		For0(k,a.m)
			For0(i,a.n)
				For0(j,b.m){
					ll t = c.d[i][j] + 1LL * a.d[i][k] * b.d[k][j] % MOD;
					

					Mymod(t);
					c.d[i][j] = t;
				}
		return c;
	}
	_tp<_tyn T> Matrix<T> operator^( rg Matrix<T> a , rg ll b ){
		Matrix<T> ret(a.n);
		for( ; b ; a=a*a,b>>=1LL )
			if(b&1LL) ret = ret*a;
		return ret;
	}
	
}








int a[MAXN], b[MAXN];

int cnt = 0;
int Ask( int c , int d ){
	++cnt;
	if( cnt > 62 ) while(1);
	

	printf("? %d %d\n",c,d);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	fflush(stdout);
	return a;
}

void Gen( int &res , int pos , int posfill , int id5 , bool useb ){
	res = 0;
	For(i,MX){
		if( pos == i ) res |= posfill<<i-1;
		if( pos > i ) res |= id5<<i-1;
		if( pos < i ){
			if(useb) res |= b[i]<<i-1;
			else res |= a[i]<<i-1;
		}
	}
}
int c,d;

void Printans(){
	

	

	int ansa = 0, ansb = 0;
	For(i,MX){
		if(a[i]) ansa |= 1<<i-1;
		if(b[i]) ansb |= 1<<i-1;
	}
	printf("! %d %d\n",ansa,ansb);
	fflush(stdout);
}
int main(){
	int lastst = -233;
	fOR(i,MX){
		Gen(c,i,0,0,0); Gen(d,i,1,0,1);
		int ans1 = Ask(c,d);
		Gen(c,i,1,0,0); Gen(d,i,0,0,1);
		int ans2 = Ask(c,d);
		if( ans1 != ans2 ){
			if( ans1 == -1 ) a[i] = b[i] = 0;
			else a[i] = b[i] = 1;
		}else{
			if( lastst == -233 ){
				Gen(c,i,0,0,0); Gen(d,i,0,0,1);
				int ans3 = Ask(c,d);
				if( ans3 == 1 ){ a[i] = 1; b[i] = 0; }
				else{ a[i] = 0; b[i] = 1; }
				lastst = ans1;
			}else{
				if( lastst == 1 ){ a[i] = 1; b[i] = 0; }
				else{ a[i] = 0; b[i] = 1; }
				lastst = ans1;
			}
		}
		

	}

	Printans();

	END();
}

