




















































































































































































































































































































int mod;


const int mod=id2;

const int mod=1000000007;


const int gmod=3;
const int inf=1039074182;

const double eps=id1;

const double eps=1e-9;

const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;





using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}


void id0(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void id0(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		std::cout<<(x&1);
		x>>=1;
		len--;
		

		

	}
	while(len--) cout<<0;
	

	

	

	

	

	

	

	

	

	

}
vector<string> id5(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}


struct DSUAE
{
	int *f;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
		}
	}
	inline void init(int n)
	{
		f=new int[n+5];
		clear(n);
	}
	inline int find(int x)
	{
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(x&1) f[x]=y;else f[y]=x;
		return 1;
	}
	inline bool same(int x,int y)
	{
		return (find(x)==find(y));
	}
};

struct DSU
{
	int *f;
	int *depth;
	int *sz;
	int n;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
			depth[i]=1;
			sz[i]=1;
		}
	}
	inline void init(int _n)
	{
		n=_n;
		f=new int[n+5];
		depth=new int [n+5];
		sz=new int [n+5];
		clear(n);
	}
	inline int find(int x)
	{
		assert(0<=x && x<n);
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline int getSize(int x)
	{
		assert(0<=x && x<n);
		return sz[find(x)];
	}
	inline int merge(int x,int y)
	{
		assert(0<=x && x<n);
		assert(0<=y && y<n);
		x=find(x);
		y=find(y);
		if(x==y) return false;
		if(depth[x]>depth[y])
		{
			f[y]=x;
			sz[x]+=sz[y];
		}
		else if(depth[y]>depth[x])
		{
			f[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			sz[y]+=sz[x];
			f[x]=y;
			depth[y]++;
		}
		return true;
	}
	inline int same(int x,int y)
	{
		assert(0<=x && x<n);
		assert(0<=y && y<n);
		return (find(x)==find(y));
	}
	~DSU()
	{
		delete[] f;
		delete[] depth;
		delete[] sz;
	}
};

struct PersistentDSU:public DSU
{
	int find(int x)
	{
		return (x==f[x]?x:find(f[x]));
	}
	inline int merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return false;
		if(depth[x]>depth[y])
		{
			f[y]=x;
			sz[x]+=sz[y];
		}
		else if(depth[y]>depth[x])
		{
			f[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			sz[y]+=sz[x];
			f[x]=y;
			depth[y]++;
		}
		return true;
	}
};



long long id3() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=id3();return x%(r-l+1)+l;}




using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


template <typename Iterator>
void id4(Iterator begin,Iterator end)
{
    for(Iterator it=begin+1;it!=end;it++)
    {
        iter_swap(begin+rand(0,it-begin),it);
    }
}


using namespace std;
int n,k;
int d[55];
int w[55][55];
vector<int> edges[55];
DSUAE dsu;
vector<pair<int,pii> > vSort;
int best=inf;
int ch[55][55];
int t[55];
int s[55];

int calc()
{
	int res=0;
	dsu.clear(n);
	vSort.clear();
	int cnt=n;
	memset(t,0,sizeof(t));
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ch[i][j])
			{
				if(dsu.same(i,j)) return inf;
				t[i]++;
				t[j]++;
				res+=w[i][j];
				dsu.merge(i,j);
				cnt--;
			}
			else
			{
				vSort.push_back(mp(w[i][j],mp(i,j)));
			}
		}
	}
	sort(all(vSort));
	for(auto &o:vSort)
	{
		int w=o.first,x=o.second.first,y=o.second.second;
		if(!dsu.same(x,y) && t[x]!=d[x] && t[y]!=d[y])
		{
			dsu.merge(x,y);
			res+=w;
			cnt--;
			t[x]++;
			t[y]++;
		}
	}
	

	return (cnt==1?res:inf);
}

int main()
{


	cin>>n>>k;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<k;i++)
	{
		cin>>d[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			scanf("%d",w[i]+j);
			vSort.push_back(mp(w[i][j],mp(i,j)));
		}
	}
	dsu.init(n);
	vector<pii> tmp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(i<k) tmp.emplace_back(i,j);
		}
	}
	int now=calc();
	best=now;
	

	

	for(double T=1000;T>=0.001;T*=0.9993)
	{
		int x,y;
		while(true)
		{
			pii o=tmp[rand(0,tmp.size()-1)];
			x=o.first,y=o.second;
			if(!ch[x][y] && (s[x]==d[x] || s[y]==d[y])) continue;
			else break;
		}
		s[x]-=ch[x][y];
		s[y]-=ch[x][y];
		ch[x][y]^=1;
		s[x]+=ch[x][y];
		s[y]+=ch[x][y];
		int delta=calc()-now;
		

		if(exp(-(double)delta/T)>=(double)rand(0,1000000000)/1000000000)
		{
			now+=delta;
			chmin(best,now);
		}
		else
		{
			s[x]-=ch[x][y];
			s[y]-=ch[x][y];
			ch[x][y]^=1;
			s[x]+=ch[x][y];
			s[y]+=ch[x][y];
		}
	}
	

	

	

	

	

	

	

	

	cout<<best<<endl;
	


	

	

	


	

	return 0;
}
