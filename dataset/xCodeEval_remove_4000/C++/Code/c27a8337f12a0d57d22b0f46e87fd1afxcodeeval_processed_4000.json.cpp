






























































































































































































































































































































































































































int mod;

const int mod=998244353;

const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}

using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
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

template <typename T>
void operator*=(vector<T> &vec, int k)
{
	for (auto &x : vec)
		x *= k;
}

template <typename T>
void operator-=(vector<T> &a, const vector<T> &b)
{
	assert(a.size() == b.size());
	for (size_t it = 0; it < a.size(); it++)
	{
		a[it] -= b[it];
	}
}

template <typename T>
vector<T> operator*(const vector<T> &vec, int k)
{
	vector<T> res(vec);
	res *= k;
	return res;
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

template <typename T>
T operator*(vector<T> v1, vector<T> v2)
{
	assert(v1.size() == v2.size());
	int n = v1.size();
	T res = 0;
	for (int i = 0; i < n; i++)
	{
		res += v1[i] * v2[i];
	}
	return res;
}

template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y)
{
	return make_pair(x.first + y.first, x.second + y.second);
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
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

using namespace std;
struct Graph
{
	public:
	bool unDirected;
	vector <vector <int> > edges;
	int n;
	int m;
	int isTree;
	void init(int _n,bool _unDirected=true)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
		unDirected=_unDirected;
		isTree=-1;
	}
	bool testTree()
	{
		if(isTree!=-1) return isTree;
		assert(unDirected==true);
		if(n!=m+1) return isTree=false;
		queue <int> que;
		vector <int> visit(n,0);
		que.push(0);
		while(que.size())
		{
			int x=que.front();
			visit[x]=true;
			que.pop();
			for(auto u:edges[x])
			{
				if(visit[u]) continue;
				que.push(u);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!visit[i]) return isTree=false;
		}
		isTree=true;
		return isTree;
	}
	void feedEdges(vector <int> _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y)
	{
		edges[x].push_back(y);
		if(unDirected) edges[y].push_back(x);
		m++;
	}
	void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	inline void reset(int _n)
	{
		int n=_n;
		clear(n);
	}
	inline void clear()
	{
		clear(n);
	}
	inline void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j)) cout<<"("<<i<<'-'<<j<<")"<<endl;
			}
		}
	}
};

template <typename T>
struct GraphWithCost
{
	public:
	bool unDirected;
	vector <vector <pair<int,T> > > edges;
	int n;
	int m;
	int isTree;
	void init(int _n,bool _unDirected)
	{
		n=_n;
		m=0;
		edges.resize(n+5);




		unDirected=_unDirected;
		isTree=-1;
	}
	void feedEdges(vector <pair<int,T> > _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y,int cost)
	{
		edges[x].push_back(mp(y,cost));
		if(unDirected) edges[y].push_back(mp(x,cost));
		m++;
	}
	void clear()
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j.first)) cout<<"("<<i<<'-'<<j.first<<")"<<endl;
			}
		}
	}
};



void id3(int x)
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
void id3(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

namespace Tree
{
	struct GetParent
	{
		template <typename T>
		void dfs(int x, int p, T &arr, Graph &g)
		{
			arr[x] = p;
			for (auto &u : g.edges[x])
			{
				if (u == p)
					continue;
				dfs(u, x, arr, g);
			}
		}
		template <typename T>
		void id0(Graph &g, int rt, T &arr)
		{
			dfs(rt, -1, arr, g);
		}
	};

	struct GetDepth
	{
		template <typename T>
		void dfs(int x, int p, int depth, T &arr, Graph &g)
		{
			arr[x] = depth;
			for (auto &u : g.edges[x])
			{
				if (u == p)
					continue;
				dfs(u, x, depth + 1, arr, g);
			}
		}
		template <typename T>
		void id2(T &arr, Graph &g, int rt = 0)
		{
			dfs(rt, -1, 0, arr, g);
		}
	};

	struct LCA
	{
		int N;
		int LOGN;
		vector<int> depth;
		vector<vector<int>> par;
		void error(string s)
		{
			cout << s << endl;
			exit(0);
		}
		void init(Graph &g)
		{
			if (g.unDirected == false)
			{
				error("Error occured! Now LCA-algorithm only supports undirected graph!");
			}
			N = g.n;
			int tn = N;
			LOGN = 0;
			while (tn)
			{
				tn /= 2;
				LOGN++;
			}
			depth.resize(N);
			par.resize(LOGN);
			for (int i = 0; i < LOGN; i++)
			{
				par[i].resize(N);
			}
			GetDepth ta;
			GetParent tb;
			ta.id2(depth, g, 0);
			tb.id0(g, 0, par[0]);
			for (int k = 0; k < LOGN - 1; k++)
			{
				for (int i=0;i<g.n;i++)
				{
					if(par[k][i] == -1)
					{
						par[k+1][i]=-1;
					}
					else
					{
						par[k + 1][i] = par[k][par[k][i]];
					}
				}
			}
		}
		int lca(int a, int b)
		{
			if (depth[a] < depth[b]) swap(a, b);
			int t = depth[a] - depth[b];
			for (int i = 0; i < LOGN; i++)
			{
				if ((t & (1 << i)))	a=par[i][a];
			}
			if (a == b)	return a;
			for (int i = LOGN - 1; i >= 0; i--)
			{
				if (par[i][a] != par[i][b])
				{
					a = par[i][a];
					b = par[i][b];
				}
			}
			return par[0][a];
		}
		inline int getDist(int a, int b)
		{
			return depth[a] + depth[b] - depth[lca(a, b)] * 2;
		}
	};

	struct GetDiameter
	{
		pair<int, int> dfs(Graph &g, int x, int par)
		{
			pair<int, int> res = make_pair(1, x);
			for (auto u : g.edges[x])
			{
				if (u == par)
					continue;
				chmax(res, dfs(g, u, x) + make_pair(1, 0));
			}
			return res;
		}
		int getDiameter(Graph &g, int x = 0, int par = -1)
		{
			int a = dfs(g, x, par).second;
			return dfs(g, a, -1).first;
		}
	};

	struct GetPSum
	{
		void dfs(Graph &g, int dst[], int src[], int x = 0, int par = -1)
		{
			dst[x] = src[x];
			for (auto u : g.edges[x])
			{
				if (u == par)
					continue;
				dfs(g, dst, src, u, x);
				dst[x] += dst[u];
			}
		}
	};

	struct MarkLeaf
	{
		void mark(Graph &g,int arr[],int x=0)
		{
			for (int i = 0;i<g.n;i++)
			{
				if ((i!=x && (int)g.edges[i].size()<=1) || (i==x && g.edges[i].size()==0))
				{
					arr[i]=true;
				}
				else
				{
					arr[i]=false;
				}
			}
		}
	};

	struct JustVisit
	{
		int dfs(Graph &g, int arr[], int x = 0, int par = -1)
		{
			arr[x] = true;
			int cnt = 1;
			for (auto u : g.edges[x])
			{
				if (u == par)
					continue;
				cnt += dfs(g, arr, u, x);
			}
			return cnt;
		}
	};

	struct BulidSPTree
	{
		vector<int> dist;
		template <typename T>
		inline vector<pair<int, T>> build(GraphWithCost<T> &g, int rt)
		{
			vector<pair<int, T>> v(g.n);
			dist.resize(g.n);
			priority_queue<pii, vector<pii>, greater<pii>> que;
			for (int i = 0; i < g.n; i++)
			{
				dist[i] = inf;
			}
			dist[rt] = 0;
			que.push(mp(0, rt));
			while (que.size())
			{
				int x = que.top().second;
				int s = que.top().first;
				que.pop();
				if (s != dist[x])
					continue;
				for (int i = 0; i < g.edges[x].size(); i++)
				{
					int u = g.edges[x][i].first, ct = g.edges[x][i].second;
					if (dist[u] <= dist[x] + ct)
						continue;
					dist[u] = dist[x] + ct;
					v[u] = mp(x, ct);
					que.push(mp(dist[u], u));
				}
			}
			v[0] = mp(-1, 0);
			return v;
		}
	};
} 

namespace FastIO
{
    const int id1=25000000;
    char buf[id1];
    int cursor=-1;
    inline void init()
    {
        fread(buf,1,id1,stdin);
        cursor=0;
    }
    inline char getchar()
    {
        return buf[cursor++];
    }
    inline int getnum()
    {
        static int res;
        static char c;
        res=0;
        c=0;
        while(!isdigit(c)) c=getchar();
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res;
    }
} 

using FastIO::getnum;
using namespace std;
Tree::LCA lca;
int n;
int p[200005];
int q[200005];
Graph g;

struct Node
{
	int a,b;
	bool ok;
	bool E;
	Node(){E=true;ok=true;}
	Node(int x){a=x;b=x;E=false;ok=true;}
	Node(int x,int y){a=x;b=y;E=false;ok=true;}
	bool operator == (const Node &node)const&
	{
		if(ok==false && node.ok==false) return true;
		if(E==true && node.E==true) return true;
		return (ok==node.ok && E==node.E && a==node.a && b==node.b);
	}
};
ostream & operator << (ostream &cout,const Node &node)
{
	cout<<"{"<<node.a<<","<<node.b;
	if(node.ok) cout<<","<<"ok";
	if(node.E) cout<<","<<"E";
	cout<<"}";
	return cout;
}

inline void merge(const Node &a,int x,Node &res)
{
	if(!a.ok) return res.ok=false,void(0);
	int len=lca.getDist(a.a,a.b);
	int la=lca.getDist(x,a.a);
	int lb=lca.getDist(x,a.b);
	

	res=a;
	if(la+lb==len) return;
	if(la+len==lb) res.a=x;
	else if(lb+len==la) res.b=x;
	else res.ok=false;
}

inline void merge(const Node &a,const Node &b,Node &res)
{
	if(!b.ok || !a.ok) return res.ok=false,void(0);
	if(a.E) return res=b,void(0);
	if(b.E) return res=a,void(0);
	res=a;
	merge(res,b.a,res);
	merge(res,b.b,res);
}

inline Node merge(const Node &a,const Node &b)
{
	Node tmp;
	merge(a,b,tmp);
	return tmp;
}

struct SegmentTree
{
	static const int nn=262144;
	Node data[nn*2+5];
	inline void build(int p[],int n)
	{
		for(int i=nn;i<nn+n;i++)
		{
			data[i]=p[i-nn];
		}
		for(int i=nn-1;i>=1;i--)
		{
			merge(data[i*2],data[i*2+1],data[i]);
			

		}
	}
	inline Node query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return Node();
		if(l>=ql && r<=qr) return data[x];
		return merge(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
	inline int query(int x,int l,int r,Node pSum)
	{
		assert(pSum.ok);
		if(x>=nn)
		{
			Node t=merge(pSum,data[x]);
			return (t.ok?x-nn+1:x-nn);
		}
		Node tpSum=merge(pSum,data[x*2]);
		if(tpSum.ok) return query(x*2+1,l+r>>1,r,tpSum);
		else return query(x*2,l,l+r>>1,pSum);
	}
	inline void change(int pos,Node value)
	{
		

		pos+=nn;
		data[pos]=value;
		pos/=2;
		while(pos>=1)
		{
			Node tmp=merge(data[pos*2],data[pos*2+1]);
			if(tmp==data[pos]) return;
			data[pos]=tmp;
			pos/=2;
		}
	}
}sgt;



int main()
{
	FastIO::init();
	



	

	n=getnum();
	g.init(n);
	for (int i=0;i<n;i++)
	{
		p[i]=getnum();
		

		q[p[i]]=i;
	}
	for(int i=1;i<n;i++)
	{
		int par;
		par=getnum();
		

		par--;
		g.addEdges(par,i);
	}
	lca.init(g);
	sgt.build(q,n);
	int q;
	q=getnum();
	

	int type,x,y;
	

	

	

	

	

	

	

	

	

	

	

	while(q--)
	{
		type=getnum();
		

		if(type==1)
		{
			

			x=getnum();
			y=getnum();
			

			x--;
			y--;
			

			

			sgt.change(p[y],x);
			sgt.change(p[x],y);
			swap(p[x],p[y]);
			

			

			

		}
		else
		{
			

			printf("%d\n",min(n,sgt.query(1,0,n,Node())));
			

		}
		

		

	}
	return 0;
}
