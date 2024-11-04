



















using namespace std;






































struct InputReader{
	
	char buf[bs]; int p;
	il InputReader(){ p = bs; }
	il void Flush(){ p = 0; fread(buf,1,bs,stdin); }
	il char C(){ if(p >= bs) Flush(); return buf[p++]; }
	il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }
	il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }
	int operator() (){
		int ans = 0, fu = 1;
		char ch = Readnum();
		if( ch == '-' ) fu = -1, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10 + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL, fu = 1LL;
		char ch = Readnum();
		if( ch == '-' ) fu = -1, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10LL + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '_'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '_'  ||  ch == '.' ){
			x += ch;
			ch = C();
		}
	}
	il void Readchstring( char s[] ){
		int len = 0;
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)   ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)   ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
	il void Specialread( char &c ){ c = C();
		while( c != '.'  &&  c != 'x'  &&  c != 'A'  &&  c != 'B' ) c = C();
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

































namespace Maths{
	_tp<_tyn T>T Gcd( T a , T b ){ return b?Gcd(b,a%b):a; }
	ll Pow( ll a , ll b ){
		ll ret = 1;
		for( ; b ; (a*=a)%=MOD, b >>= 1LL )
			if(b&1LL) (ret*=a) %= MOD;
		return ret;
	}
	ll Inv( ll a ){ return Pow(a,MOD-2LL); }
	ll Frac( ll x ){
		ll ret = 1;
		For(i,x)
			ret = ret*i % MOD;
		return ret;
	}
}







	
	
	
	
	
	
	mt19937 rng;
	
	
	

	
	
	





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


	
	
	
	
	using namespace __gnu_pbds;

int dx4[] = {0,-1,0,1};
int dy4[] = {1,0,-1,0};








int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};




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
	struct Edge{
		int to,cap,rev,cost;
		Edge(){}
		Edge( int ti , int ci , int ri , int coi ){
			to = ti; cap = ci; rev = ri; cost = coi;
		}
	};
	vc<Edge> e[NET];
	void Link( int f , int t , int c , int co ){
		e[f].Pb( Edge( t , c , e[t].size() , co ) );
		e[t].Pb( Edge( f , 0 , e[f].size()-1 , -co ) );
	}

	queue<int> q;
	int dis[NET];
	bool inque[NET];
	int prevdot[NET], prevedge[NET];
	
	bool Spfa(){
		Msn(dis,INF);
		Ms(inque);
		q.push(S);
		dis[S] = 0;
		inque[S] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			inque[u] = 0;
			For0(i,e[u].size()){
				Edge nowe = e[u][i];
				if(!nowe.cap) continue;
				int v = nowe.to;
				if( dis[v] > dis[u] + nowe.cost ){
					dis[v] = dis[u] + nowe.cost;
					prevdot[v] = u;
					prevedge[v] = i;
					if(!inque[v]){
						inque[v] = 1;
						q.push(v);
					}
				}
			}
		}
		return dis[T] != INF;
	}
	int Refresh(){
		int u = T;
		int flow = INF;
		while( u != S ){
			Mymin(flow,PREV(u).cap);
			u = prevdot[u];
		}
		u = T;
		while( u != S ){
			PREV(u).cap -= flow;
			e[u][PREV(u).rev].cap += flow;
			u = prevdot[u];
		}
		return flow;
	}
	pii id1(){
		int ans = 0, flow = 0;
		while(Spfa()){
			int tflow = Refresh();
			int tans = tflow * dis[T];
			ans += tans;
			flow += tflow;
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
	bool id0( Point<ld> a , Point<ld> b , Point<ld> c ){
		return (c-b) * (b-a) > Eps;
	}
}






using Geometry::Point;

int n;
Point<int> a[MAXN];

set< Point<int> > ansl;
void id2( int l , int r ){
	if( l >= r ) return;

	int mid = l+r >> 1;
	id2(l,mid-1);
	id2(mid+1,r);

	Forx(i,l,r)
		ansl.insert( Point<int>(a[mid].x,a[i].y) );
}

int main(){
	FILEIO();

	Read(n);
	For(i,n){
		Read(a[i].x,a[i].y);
		ansl.insert(a[i]);
	}

	sort(a+1,a+1+n,[](Point<int>a,Point<int>b){ return a.x<b.x; });

	id2(1,n);

	printf("%d\n",ansl.size());
	

	for( auto it = ansl.begin() ; it != ansl.end() ; ++it ){
		Point<int> a = *it;
		a.Print();
	}


	END();
}
