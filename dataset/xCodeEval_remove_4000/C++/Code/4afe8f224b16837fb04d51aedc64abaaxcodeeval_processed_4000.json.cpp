
using namespace std;

using ll=long long;




















template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
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
	
	cout.flush();
	
}
void no(bool ex=true){
	
	cout<<"NO"<<"\n";
	
	cout<<"No"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}
void possible(bool ex=true){
	
	cout<<"POSSIBLE"<<"\n";
	
	cout<<"Possible"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}
void impossible(bool ex=true){
	
	cout<<"IMPOSSIBLE"<<"\n";
	
	cout<<"Impossible"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
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

bool inc(int a,int b,int c){
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
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		

		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}












template<class N>
struct id2{
	struct Node{
		using np=Node*;
		np l,r,p;
		bool rev;
		N x;
		Node():l(0),r(0),p(0),rev(false),x(){}
		void clear(){
			l=0;
			r=0;
			p=0;
			rev=0;
		}
		void reverse(){
			rev^=true;
			swap(l,r);
			x.reverse();
		}
		void push(){
			if(rev){
				if(l)l->reverse();
				if(r)r->reverse();
				rev=false;
			}
			if(l)x.push(l->x);
			if(r)x.push(r->x);
			x.clear();
		}
		np update(){
			x.single();
			if(l)x.updatel(l->x);
			if(r)x.updater(r->x);
			return this;
		}
		int pos(){
			if(p&&p->l==this)return -1;
			if(p&&p->r==this)return 1;
			return 0;
		}
		void prepare(){
			if(pos())
				p->prepare();
			push();
		}
		void rotate(){
			np q=p,c;
			if(pos()==1){
				c=l;
				l=p;
				p->r=c;
			}else{
				c=r;
				r=p;
				p->l=c;
			}
			if(c)c->p=p;
			p=p->p;
			q->p=this;
			if(p&&p->l==q)p->l=this;
			if(p&&p->r==q)p->r=this;
			q->update();
		}
		np splay(){
			prepare();
			while(pos()){
				int a=pos(),b=p->pos();
				if(b&&a==b)p->rotate();
				if(b&&a!=b)rotate();
				rotate();
			}
			return update();
		}
		template<class F,class...Args>
		np find(F f,Args&&...args){
			if(!(x.*f)(forward<Args>(args)...))return 0;
			push();
			x.single();
			np a=0;
			if(l)a=l->find(f,forward<Args>(args)...);
			if(a)return a;
			if((x.*f)(forward<Args>(args)...))return splay();
			return r->find(f,forward<Args>(args)...);
		}
		np left(){
			if(l)return l->left();
			else return splay();
		}
		np right(){
			if(r)return r->right();
			else return splay();
		}
		np root(){
			if(p)return p->root();
			else return this;
		}
		np cutl(){
			if(l){
				l->p=0;
				l=0;
			}
			return update();
		}
		np linkl(np c){
			assert(!l);
			l=c;
			if(c)c->p=this;
			return update();
		}
		np cutr(){
			if(r){
				r->p=0;
				r=0;
			}
			return update();
		}
		

		np get_next(){
			splay();
			if(!r)return 0;
			else return r->left();
		}
	}*buf;
	using np=Node*;
	vc<np> ps;
	id2(int n){
		buf=new Node[n];
		rep(i,n)ps.pb(buf+i);
	}
	~id2(){delete[] buf;}
	int head=0;
	template<class...Args>
	np nn(Args&&...args){
		np a=ps.back();
		ps.pop_back();
		a->l=0;
		a->r=0;
		a->p=0;
		a->x=N(forward<Args>(args)...);
		return a;
	}
	

	pair<np,np> erase_sub(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		ps.pb(x);
		return mp(x->l,x->r);
	}
	

	np erase(np x){
		np a,b;
		tie(a,b)=erase_sub(x);
		return merge(a,b);
	}
	

	np isolate(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		np res=merge(x->l,x->r);
		x->x.single();
		x->clear();
		return res;
	}
	

	template<class F>
	np insert(np r,np x,F f){
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	template<class F,class...Args>
	np insert(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	

	template<class F,class...Args>
	np insert_cmp(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	

	template<class F>
	np insert_cmp(np r,np x,F f){
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	template<class t>
	np build(vc<t> v){
		vc<np> cur;
		for(auto z:v)cur.pb(nn(z));
		while(cur.size()>1){
			int s=cur.size();
			vc<np> nx((s+1)/2);
			for(int i=0;i<s;i+=2){
				if(i+1<s)nx[i/2]=merge(cur[i],cur[i+1]);
				else nx[i/2]=cur[i];
			}
			swap(nx,cur);
		}
		return cur[0];
	}
	np merge(np a,np b){
		if(!a)return b;
		if(!b)return a;
		return b->splay()->left()->linkl(a->splay());
	}
	

	

	template<class F,class...Args>
	pair<np,np> split(np a,F f,Args&&...args){
		if(!a)return {0,0};
		np b=a->find(f,forward<Args>(args)...);
		if(b){
			np c=b->l;
			return {c,b->cutl()};
		}
		return {a,0};
	}
	

	

	template<class F>
	pair<np,np> split_cmp(np a,F cmp,N v){
		if(!a)return {0,0};
		np x=0,y=0;
		while(a){
			if(cmp(a->x,v)){
				x=a;
				a=a->r;
			}else{
				y=a;
				a=a->l;
			}
		}
		if(x)x->splay();
		if(y){
			y->splay();
			y->cutl();
		}
		return mp(x,y);
	}
	

	

	

	tuple<np,np,np> split_range(np a,np b){
		{

			a->splay();
			b->splay();
			int lastpos;
			auto c=a;
			while(c&&c!=b){
				lastpos=c->pos();
				c=c->p;
			}
			assert(c==b);
			assert(lastpos==-1);
		}
		a->splay();
		np x=a->l;
		a->cutl();
		b->splay();
		np z=b->r;
		b->cutr();
		return mt(x,b,z);
	}
	

	template<class F>
	np id0(np x,np tar,F f){
		if(!x)return tar;
		x->push();
		tar=id0(x->l,tar,f);
		tar=id0(x->r,tar,f);
		x->x.single();
		x->clear();
		return insert(tar,x,f);
	}
	

	template<class F>
	np weighted_merge(np a,np b,F f){
		if(!a)return b;
		if(!b)return a;
		if(a->x.sz<b->x.sz)swap(a,b);
		return id0(b,a,f);
	}
	

	void enumerate(np x,vc<N>&dst){
		if(!x)return;
		x->push();
		enumerate(x->l,dst);
		dst.pb(x->x);
		enumerate(x->r,dst);
	}
};
































struct N{
	int val,sum,waf,len;
	N(int v=0):val(v),sum(v),len(1){}
	void reverse(){}
	void push(N&){
	}
	void clear(){
	}
	void single(){
		sum=val;
		waf=0;
		len=1;
	}
	static N mg(int val,const N&x,const N&y){
		N res(val);
		res.sum=x.sum+y.sum;
		res.waf=x.waf+x.len*y.sum+y.waf;
		res.len=x.len+y.len;
		return res;
	}
	void updatel(const N&x){
		*this=N::mg(val,x,*this);
	}
	void updater(const N&x){
		*this=N::mg(val,*this,x);
	}
	static bool cmp(const N&x,const N&y){
		return x.val<y.val;
	}
	bool find(int&s)const{
		if(len<=s){
			s-=len;
			return false;
		}else{
			return true;
		}
	}
	int getvalue(){
		return waf*2-sum*(len-1);
	}
};

void slv(){
	int n,q;cin>>n>>q;
	id2<N> t(n+q);
	vi rw=readvi(n);
	sort(all(rw));
	using np=id2<N>::np;
	int s=n;
	np root=t.build(rw);
	rep(_,q+1){
		if(_){
			int kind;cin>>kind;
			if(kind==1){
				int v;cin>>v;
				s++;
				root=t.insert_cmp(root,&N::cmp,v);
			}else{
				int v;cin>>v;
				s--;
				np a,b;tie(a,b)=t.split_cmp(root,N::cmp,N(v));
				assert(b);
				np c=b->left();
				b=t.erase(c);
				root=t.merge(a,b);
			}
		}
		if(s==0){
			print(0);
		}else{
			assert(root->x.len==s);
			int kmx=(s-1)/2;
			int lw=0,up=kmx+1;
			while(up-lw>1){
				const int k=(lw+up)/2;
				int tmp=k+1;
				np a,b,c;
				tie(a,b)=t.split(root,&N::find,tmp);
				assert(tmp==0);
				tmp=s-(k+1)-k;
				tie(b,c)=t.split(b,&N::find,tmp);
				assert(tmp==0);
				int x=0,y=0;
				if(a)x=a->x.sum;
				if(c)y=c->x.sum;
				root=t.merge(a,t.merge(b,c));
				if(x<y)up=k;
				else lw=k;
			}
			int ans=root->x.getvalue();
			if(up<=kmx){
				int k=up;
				int len=s-k-k;
				int tmp=k+1;
				np a,b,c;
				tie(a,b)=t.split(root,&N::find,tmp);
				assert(tmp==0);
				tmp=s-(k+1)-k;
				tie(b,c)=t.split(b,&N::find,tmp);
				assert(tmp==0);
				int val=0;
				if(a){
					val-=a->x.sum*(len);
				}
				if(c){
					val+=c->x.sum*(len);
				}
				if(b){
					val+=b->x.getvalue();
				}
				root=t.merge(a,t.merge(b,c));
				ans-=val;
			}
			print(ans);
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	

	slv();
}
