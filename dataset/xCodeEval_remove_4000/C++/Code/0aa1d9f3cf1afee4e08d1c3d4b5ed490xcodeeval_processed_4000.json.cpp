




















































































































































































































































































































































































































































































































































































































































int mod;


const int mod=id3;

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
vector<string> id8(string s) {
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





long long id4() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=id4();return x%(r-l+1)+l;}




using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


template <typename Iterator>
void id5(Iterator begin,Iterator end)
{
    for(Iterator it=begin+1;it!=end;it++)
    {
        iter_swap(begin+rand(0,it-begin),it);
    }
}


namespace FastIO
{
    const int id6=6200020;
    char buf[id6];
    int cursor=-1;
    inline void init()
    {
        fread(buf,1,id6,stdin);
        cursor=0;
    }
    inline char getchar()
    {
        return (cursor==id6?EOF:buf[cursor++]);
    }
    inline ll getnum()
    {
        static ll res;
        static char c;
        static int mut;
        res=0;
        c=0;
        mut=1;
        while(!isdigit(c) && c!='-') c=getchar();
        if(c=='-')
        {
            mut=-1;
            c=getchar();
        }
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res*mut;
    }
} 

using FastIO::getnum;
using namespace std;
int n,q;
int sz;

template<typename T>
struct Node
{
	Node *l=0,*r=0;
	int sz=1,rd=rand(1,10000000);
	T val;
	ll sum,id1,id7;
	Node(T &x):val(x),sum(x),id1(x),id7(x){}
	void pushup()
	{
		sz=(l?l->sz:0)+(r?r->sz:0)+1;
		id1=(l?l->id1:0)+(r?r->id1:0)+1LL*((r?r->sz:0)+1)*((l?l->sum:0)+val);
		id7=(r?r->id7:0)+(l?l->id7:0)+1LL*((l?l->sz:0)+1)*((r?r->sum:0)+val);
		sum=(l?l->sum:0)+(r?r->sum:0)+val;
	}
};


template <typename T>
node* merge(node *a,node *b)
{
	if(!a) return b;
	if(!b) return a;
	if(a->rd<b->rd)
	{
		b->l=merge(a,b->l);
		b->pushup();
		return b;
	}
	else
	{
		a->r=merge(a->r,b);
		a->pushup();
		return a;
	}
}

template <typename T>
pair<node*,node*> split(node *rt,T key)
{
	if(!rt) return mp(nullptr,nullptr);
	pair<node*,node*> o;
	if(rt->val<=key)
	{
		o=split(rt->r,key);
		rt->r=o.first;
		rt->pushup();
		return mp(rt,o.second);
	}
	else
	{
		o=split(rt->l,key);
		rt->l=o.second;
		rt->pushup();
		return mp(o.first,rt);
	}
}

template <typename T>
pair<node*,node*> split(node *rt,int key,int psum=0)
{
	if(!rt) return mp(nullptr,nullptr);
	pair<node*,node*> o;
	int curid=psum+(rt->l?rt->l->sz:0);
	if(curid<=key)
	{
		o=split(rt->r,key,curid+1);
		rt->r=o.first;
		rt->pushup();
		return mp(rt,o.second);
	}
	else
	{
		o=split(rt->l,key,psum);
		rt->l=o.second;
		rt->pushup();
		return mp(o.first,rt);
	}
}

template <typename T>
void erase(node *&rt,T key)
{
	if(rt->val==key)
	{
		rt=merge(rt->l,rt->r);
		return;
	}
	if(rt->val<key) erase(rt->r,key);else erase(rt->l,key);
	rt->pushup();
}

template <typename T>
void insert(node *&rt,T key,int rd=rand(1,1000000000))
{
	if(!rt)
	{
		rt=new Node<T>(key);
		rt->rd=rd;
		return;
	}
	if(rd>rt->rd)
	{
		pair<node*,node*> o=split(rt,key);
		rt=new Node<T> (key);rt->rd=rd;
		rt->l=o.first;rt->r=o.second;
	}
	else
	{
		if(key>rt->val) insert(rt->r,key);else insert(rt->l,key);
	}
	rt->pushup();
}

Node<ll> *rt;

template <typename T>
ll id2(node *rt,int key)
{
	ll res=0;
	while(rt)
	{
		int l=(rt->l?rt->l->sz:0);
		if(key<l)
		{
			rt=rt->l;
		}
		else
		{
			res+=(rt->l?rt->l->sum:0)+rt->val;
			rt=rt->r;
			key-=l+1;
		}
	}
	return res;
}

template <typename T>
ll id9(node *rt,int key)
{
	ll res=0;
	while(rt)
	{
		int l=(rt->l?rt->l->sz:0);
		(key<=l?(res+=(rt->r?rt->r->sum:0)+rt->val,rt=rt->l):(key-=l+1,rt=rt->r));
	}
	return res;
}

inline bool greater0(int x)
{
	return id2(rt,x-1)-(x==1?0:id9(rt,sz-(x-1)))>=0;
}

ll sump(int l,int r)
{
	l--;
	r--;
	chmax(l,0);
	if(l>r) return 0;
	pair<Node<ll>*,Node<ll>*> o=split(rt,r);
	ll res=(o.first?o.first->id1:0);
	pair<Node<ll>*,Node<ll>*> o2=split(o.first,l-1);
	res-=(o2.first?o2.first->id1:0);
	rt=merge(merge(o2.first,o2.second),o.second);
	

	return res;
}

ll sumr(int l,int r)
{
	r=sz-r+1;l=sz-l+1;swap(l,r);
	l--;
	r--;
	chmax(l,0);
	if(l>r) return 0;
	pair<Node<ll>*,Node<ll>*> o=split(rt,l-1);
	ll res=(o.second?o.second->id7:0);
	pair<Node<ll>*,Node<ll>*> o2=split(o.second,r-l);
	res-=(o2.second?o2.second->id7:0);
	rt=merge(o.first,merge(o2.first,o2.second));
	

	return res;
}

ll calc(int l,int r)
{
	if(l==-1 || r==-1) return 0;
	if(l>r) return 0;
	

	return sump(l,r)-sumr(l-1,r-1);
}

ll calc1(int l,int r,int &res)
{
	res=-1;
	int mid;
	

	while(l<=r)
	{
		mid=l+r>>1;
		if(greater0(mid))
		{
			res=mid;
			l=mid+1;
		}	
		else
		{
			r=mid-1;
		}
	}
	

	return calc(1,res);
}

ll calc2(int l,int r)
{
	int res=-1,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(greater0(mid))
		{
			res=mid;
			r=mid-1;
		}	
		else
		{
			l=mid+1;
		}
	}
	return calc(res,sz);
}

template <typename T>
node* llll(node *rt)
{
	while(rt->l) rt=rt->l;
	return rt;
}

void print()
{
	if(!rt)
	{
		puts("0");
		return;
	}
	sz=rt->sz;
	

	

	ll res=rt->sum;

	int rid=-1;
	res-=calc1(1,sz/2+1,rid);
	if(rid!=-1)
	{
		int t=sz-rid+1;
		chmax(t,rid+1);
		res-=calc(t,sz);
	}
	printf("%lld\n",res);
}

int main()
{


	FastIO::init();
	n=getnum();q=getnum();
	for(int i=0;i<n;i++)
	{
		ll x;
		

		x=getnum();
		insert(rt,x);
	}
	

	

	print();
	

	for(int i=0;i<q;i++)
	{
		int type;
		ll x;
		type=getnum();x=getnum();
		

		if(type==1) insert(rt,x);else erase(rt,x);
		print();
	}
	return 0;
}
