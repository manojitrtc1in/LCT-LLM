


























































































































































































































































































































































































int mod;


const int mod=id1;

const int mod=1000000007;


const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
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
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> id2(string s) {
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


using namespace std;
int n,q;
int a[200005];
int fa[200005];
const int B=371;
int delta[200005/B+1];
ll sum[200005/B+1];
int allClear[200005/B+1];
double st;
int t;

inline int ga(int x)
{
	if(x==-1) return -1;
	return (x==0?-1:max(0,a[x]-delta[x/B]));
}

inline int id(int x)
{
	return (x==-1?-1:x/B);
}

int find(int x)
{
	if(x==-1) return -1;
	

	if(allClear[x/B]) return ga(x);else return fa[x]=(id(x)!=id(fa[x])?fa[x]:find(fa[x]));
}


inline int lca(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==y) return x;
	int fx=find(x),fy=find(y);
	

	

	

	

	

	

	while(fx!=fy)
	{
		assert(id(x)!=id(fx));
		assert(id(y)!=id(fy));
		

		y=fy;
		fy=find(y);
		if(x>y)
		{
			swap(x,y);
			swap(fx,fy);
		}
	}
	

	fx=ga(x),fy=ga(y);
	if(x>y) swap(x,y);
	while(fx!=fy)
	{
		

		y=fy;
		fy=ga(y);
		if(x>y)
		{
			swap(x,y);
			swap(fx,fy);
		}
	}
	if(x==y) return x;
	return fx;
}

inline void recalc(int l,int r,int x)
{
	

	int k=l/B;
	for(int i=k*B;i<k*B+B;i++)
	{
		

		

		

		a[i]-=delta[k];
		chmax(a[i],0);
		fa[i]=a[i];
 		

	}
	delta[k]=0;
	for(int i=l;i<r;i++)
	{
		

		

		

		

		a[i]-=x;
		chmax(a[i],0);
		fa[i]=a[i];
		

	}
}

inline void recalc(int k,int x)
{
	sum[k]+=x;
	assert(sum[k]>=0);
	if(sum[k]>=B) allClear[k]=true;
	if(sum[k]<B) recalc(k*B,k*B+B,x);
	else delta[k]+=x;
	chmin(delta[k],n);
}

int main()
{


	

	

	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	a[0]=-1;
	for(int i=0;i<n;i++) fa[i]=a[i];
	for(int i=0;i<q;i++)
	{
		t=i;
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		x--;
		y--;
		if(type==2)
		{
			a[0]=fa[0]=-1;
			

			

			

			

			printf("%d\n",lca(x,y)+1);
		}
		else
		{
			int l=x,r=y+1;
			scanf("%d",&x);
			if(l/B==(r-1)/B)
			{
				recalc(l,r,x);
				continue;
			}
			

			recalc(l,(l/B+1)*B,x);
			l=(l/B+1)*B;
			recalc(r/B*B,r,x);
			r=r/B*B;
			for(int j=l/B;j<r/B;j++)
			{
				recalc(j,x);
			}
		}
		

		

		

		

		

		

		

		

		

		

	}
	return 0;
}
