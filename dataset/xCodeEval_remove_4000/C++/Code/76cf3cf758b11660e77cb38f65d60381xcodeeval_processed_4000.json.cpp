


















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




	
	
	
	int sed = 0;
	il void Srand(){ srand(time(0)*(ull)(new char)); sed = rand(); }
	il int Rand(){ return sed = (sed*sed*73+sed*233+19260817) & 0x00ffffff; }





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




ll p;

















namespace Maths{
	_tp<_tyn T>T Gcd( T a , T b ){ return b?Gcd(b,a%b):a; }
	il ll Pow( rg ll a , rg ll b ){
		rg ll ret = 1;
		for( ; b ; (a*=a)%=MOD, b >>= 1LL )
			if(b&1LL) (ret*=a) %= MOD;
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







int Len( int a ){
	int ret = 0;
	while(a){ a >>= 1; ret++; }
	return ret;
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








struct Seg{ int l,r,p; };

int setcnt,qu,segment;
Seg a[MAXSEG];










struct Node{
	int l,r,mx,h;
	Node(){ l = r = mx = h = 0; }
};
Node tree[TREE];
int root[MAXSEG], nownode = 0;
il void Update( int pos ){
	Mx(pos) = 0;
	if(L(pos)) Mymax(Mx(pos),Mx(L(pos)));
	if(R(pos)) Mymax(Mx(pos),Mx(R(pos)));
	Have(pos) = 0;
	if(L(pos)) Have(pos) += Have(L(pos));
	if(R(pos)) Have(pos) += Have(R(pos));
}
void Insert( int gpos , int x , int old , ARG ){
	pos = ++nownode;
	tree[pos] = tree[old];
	if( l == r ){
		Mx(pos) = Mx(pos) ? min(Mx(pos),x) : x;
		Have(pos) = 1;
		return;
	}
	int mid = l+r >> 1;
	if( gpos <= mid ) Insert(gpos,x,L(old),LSON);
	else Insert(gpos,x,R(old),RSON);
	Update(pos);
}
int Querymax( int gl , int gr , ARG ){
	if(!pos) return -INF;
	if( gl <= l && r <= gr ) return Mx(pos);
	if( gr < l || r < gl ) return -INF;
	return max( Querymax(gl,gr,LSON) , Querymax(gl,gr,RSON) );
}
int Queryhave( int gl , int gr , ARG ){
	if(!pos) return 0;
	if( gl <= l && r <= gr ) return Have(pos);
	if( gr < l || r < gl ) return 0;
	return Queryhave(gl,gr,LSON) + Queryhave(gl,gr,RSON);
}

int main(){
	FILEIO();

	scanf("%d%d%d",&setcnt,&qu,&segment);
	For(i,segment)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].p);

	sort(a+1,a+1+segment,[](Seg a,Seg b){ return a.l < b.l; });
	fOR(i,segment){
		Insert(a[i].p,a[i].r,root[i+1],ROOT(i));
	}


	For(qwq,qu){
		int pl,pr,x,y;
		scanf("%d%d%d%d",&pl,&pr,&x,&y);
		int stpos = lower_bound(a+1,a+1+segment,(Seg){x,-INF,-INF},[](Seg a,Seg b){
			if( a.l != b.l ) return a.l < b.l;
			return a.r < b.r;
		}) - a;
		

		int rmax = Queryhave(pl,pr,ROOT(stpos)) == (pr-pl+1) ? Querymax(pl,pr,ROOT(stpos)) : INF;


		printf("%s\n",rmax<=y?"yes":"no");
		fflush(stdout);
	}

	END();
}
