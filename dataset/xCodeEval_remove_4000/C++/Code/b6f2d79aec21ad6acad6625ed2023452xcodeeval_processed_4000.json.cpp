


























































































































































































































































































































































































































































































































































































































const int mod=200003;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
































const int mod=200003;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}


using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
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
	for(int i=0;i<vec.size();i++)
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




long long id1() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=id1();return x%(r-l+1)+l;}




using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



using namespace std;
int n;
int c[200005];
int q[200005];

struct Treap
{
	public:
	struct Data
	{
		int key;
		int name;
		Data (){}
		Data (int _key,int _name){key=_key;name=_name;}
		int res=0;
		void operator += (int x)
		{
			key+=x;
		}
		bool operator < (Data x)
		{
			return key>x.key;
		}
		bool operator > (Data x)
		{
			return x<*this;
		}
		bool operator == (Data x)
		{
			return !(*this<x) && !(*this>x);
		}
		bool operator <= (Data x)
		{
			return (*this<x || x==*this);
		}
	};
	public:


	struct Node
	{
		Data value;
		Node *l=nullptr,*r=nullptr;
		int sz=1;
		int rd=rand(1,1e9);
		int tag=0;
		int tagres=0;
		int name;
		Node();
		Node(Data _value){value=_value;}
		inline int size()
		{
			return (this==nullptr?0:sz);
		}
		inline Node front()
		{
			Node *now=this;
			while(now->l)
			{
				now->pushdown();
				now=now->l;
			}
			return *now;
		}
		inline Node back()
		{
			Node *now=this;
			while(now->r)
			{
				now->pushdown();
				now=now->r;
			}
			return *now;
		}
		inline void pushdown()
		{
			if(l)
			{
				l->tag+=tag;
				l->value+=tag;
				l->tagres+=tagres;
				l->value.res+=tagres;
			}
			if(r)
			{
				r->tag+=tag;
				r->value+=tag;
				r->tagres+=tagres;
				r->value.res+=tagres;
			}
			tag=0;
			tagres=0;
		}
		inline void pushup()
		{
			sz=l->size()+r->size()+1;
		}
	};
	Node *rt=nullptr;
	inline pair<Node*,Node*> splitID(Node *rt,int key,int pSum=0)
	{
		if(rt==nullptr) return mp(nullptr,nullptr);
		int curID=pSum+rt->l->size();
		rt->pushdown();
		if(curID<=key)
		{
			pair <Node*,Node*> o=splitID(rt->r,key,curID+1);
			rt->r=o.first;
			rt->pushup();
			return mp(rt,o.second);
		}
		else
		{
			pair <Node*,Node*> o=splitID(rt->l,key,pSum);
			rt->l=o.second;
			rt->pushup();
			return mp(o.first,rt);
		}
	}
	inline pair<Node*,Node*> splitValue(Node *rt,Data key)
	{
		if(rt==nullptr) return mp(nullptr,nullptr);
		rt->pushdown();
		if(rt->value<=key)
		{
			pair <Node*,Node*> o=splitValue(rt->r,key);
			rt->r=o.first;
			rt->pushup();
			return mp(rt,o.second);
		}
		else
		{
			pair <Node*,Node*> o=splitValue(rt->l,key);
			rt->l=o.second;
			rt->pushup();
			return mp(o.first,rt);
		}
	}
	inline Node* merge(Node *a,Node *b)
	{
		if(!a) return b;
		if(!b) return a;
		if(a->rd>b->rd)
		{
			a->pushdown();
			Node *c=merge(a->r,b);
			a->r=c;
			a->pushup();
			return a;
		}
		else
		{
			b->pushdown();
			Node *c=merge(a,b->l);
			b->l=c;
			b->pushup();
			return b;
		}
	}
	Data querykth(Node *rt,int key,int pSum=0)
	{


		assert(rt);
		int curID=pSum+rt->l->size();
		rt->pushdown();
		if(curID==key) return rt->value;
		if(curID<key) return querykth(rt->r,key,curID+1);
		else return querykth(rt->l,key,pSum);
	}
	inline void insert(Node *&rt,Data key)
	{


		pair<Node*,Node*> o=splitValue(rt,key);
		rt=merge(merge(o.first,new Node(key)),o.second);
	}
	inline void eraseID(Node *&rt,int key)
	{
		pair<Node*,Node*> o=splitID(rt,key);
		pair<Node*,Node*> o2=splitID(o.first,key-1);
		if(o2.second) delete o2.second;
		rt=merge(o2.first,o.second);
	}
	inline Node front()
	{
		return rt->front();
	}
	inline Node back()
	{
		return rt->back();
	}
	public:
	inline void insert(Data key)
	{
		insert(rt,key);
	}
	inline void solve(int price)
	{
		pair <Node*,Node*> o=splitValue(rt,{price,0});
		Node *l=o.first,*r=o.second;
		if(l) l->value.key-=price,l->tag-=price;
		if(l) l->tagres++,l->value.res++;
		if(!l || !r)
		{
			rt=merge(l,r);
			return;
		}


		while(l && r && l->back().value.key<r->front().value.key)
		{
			Node tmp=l->back();
			eraseID(l,l->sz-1);
			insert(r,tmp.value);
		}
		rt=merge(l,r);
	}
	inline Data querykth(int pos)
	{


		return querykth(rt,pos);
	}
	inline int size()
	{
		return rt->size();
	}
	inline void print()
	{
		cout<<"Total size="<<size()<<endl;
		for(int i=0;i<size();i++)
		{
			cout<<querykth(i).key<<'-'<<querykth(i).res<<endl;
		}
		cout<<endl;
		cout<<"Done"<<endl;
	}
};
vector <pii> vSort;
int a[200005];
int b[200005];

int main()
{


	cin>>n;
	for(int i=0;i<n;i++)
	{
		static int x,y;
		scanf("%d%d",&x,&y);
		vSort.push_back(mp(-y,x));
	}
	sort(all(vSort));
	for(int i=0;i<n;i++)
	{
		a[i]=vSort[i].second;


	}


	int q;
	cin>>q;
	Treap treap;
	for(int i=0;i<q;i++)
	{
		scanf("%d",b+i);
		treap.insert({b[i],i});
	}


	for(int i=0;i<n;i++)
	{
		treap.solve(a[i]);


	}
	int ans[200005];
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<q;i++)
	{
		Treap::Data tmp=treap.querykth(i);
		ans[tmp.name]=tmp.res;
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}