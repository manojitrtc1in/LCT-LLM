
using namespace std;


using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;










const long long inf = 1e18;
const int infi = 1e9;


















 
 
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;





template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}

}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}








struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id1);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  



int id0(ll n) {
	return (63-__builtin_clzll(n));
}




ll id3(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0; 

    ll q, x1 = 0, y1 = 1; 

    while (a&&b) {
		if(a>b) {
			q = a/b;
			x -= q*x1;
			y -= q*y1;
			a -= q*b;
		} else {
			q = b/a;
			x1 -= q*x;
			y1 -= q*y;
			b -= q*a;
		}
    }
	if(a==0){
		x=x1;
		y=y1;
		return b;
	}
    return a;
}

const int mod = 1e9+7;

struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll y) {
        if(y>=0&&y<mod) x=y;
        else {
			x=y%mod;
        	if(x<0) x+=mod;
		}
    }
    mint operator-() {return mint(-x+mod);}
    mint operator ~() const {ll a,b; id3(x,mod,a,b); return a;}
    mint& operator+=(const mint& a) {if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a) {if((x-=a.x)<0) x+=mod; return *this;}
    mint& operator*=(const mint& a) {x=(x*a.x)%mod; return *this;}
    mint& operator/=(const mint& a) {this->operator*=(~a);return *this;}
    mint operator ++() { ++x; if(x == mod) x = 0; return (*this); }
	mint operator ++(int) { x++; if(x == mod) x = 0; return mint(x-1); }
	mint operator --() { --x; if(x == -1) x = mod-1; return (*this); }
	mint operator --(int) { x--; if(x == -1) x = mod-1; return mint(x+1); }
    mint pow(ll b) const {
        mint res(1);
        mint a(*this);
        while(b) {
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    mint operator +(const mint& a) const { return mint(*this) += a;}
    mint operator -(const mint& a) const { return mint(*this) -= a;}
    mint operator *(const mint& a) const { return mint(*this) *= a;}
    mint operator /(const mint& a) const { return mint(*this) /= a;}
    bool operator <(const mint& a) const { return x < a.x;}
    bool operator <=(const mint& a) const { return x <= a.x;}
    bool operator >(const mint& a) const { return x > a.x;}
    bool operator >=(const mint& a) const { return x >= a.x;}
    bool operator ==(const mint& a) const { return x == a.x;}
    bool operator !=(const mint& a) const { return x != a.x;}
    
    friend istream& operator >>(istream& is, mint p) { return is >> p.x; }
    friend ostream& operator <<(ostream& os, mint p){ return os << p.x; }
};




vector<int> zfunc(const string& s) {
	int n=s.length();
	vector<int> z(n,0);
	for(int i=1,l=0,r=0;i<n;i++) {
		if(i<r) z[i] = min(z[i-l],r-i);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]>r) {
			r = i+z[i];
			l = i;
		} 
	}
	return z;
}

vector<int> pfunc(const string& s) {
	int n=s.length();
	vector<int> pi(n);
	for(int i=1, j=0;i<n;i++) {
		while(j>0&&s[i]!=s[j]) j = pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i]=j;
	}
	return pi;
}

vector<int> suffix_arr(string s) {
	s+='$';
	int n=s.length();
	const int alphabet = 128;
	vector<int> p(n),c(n,0), cnt(max(alphabet,n),0), pn(n),cn(n,0); 

						   

	for(int i=0;i<n;i++) {
		cnt[s[i]]++;
	}
	for(int i=1;i<alphabet;i++) {
		cnt[i]+=cnt[i-1];
	}
	for(int i=n-1;i>=0;i--) {
		p[--cnt[s[i]]]=i;
	}
	for(int i=1;i<n;i++) {
		c[p[i]] = c[p[i-1]];
		if(s[p[i]]!=s[p[i-1]]) c[p[i]]++;
	}
	for(int h=1;h<n;h<<=1) { 

		fill(cnt.begin(),cnt.end(),0);
		for(int i=0;i<n;i++) {
			pn[i] = p[i]-h;
			if(pn[i]<0) pn[i]+=n;
			cnt[c[pn[i]]]++;
		}
		for(int i=1;i<n;i++) {
			cnt[i]+=cnt[i-1];
		}
		for(int i=n-1;i>=0;i--) {
			p[--cnt[c[pn[i]]]]=pn[i];
		}
		cn[p[0]]=0;
		for(int i=1;i<n;i++) {
			cn[p[i]]=cn[p[i-1]];
			if(make_pair(c[p[i]],c[(p[i]+h)%n])!=make_pair(c[p[i-1]],c[(p[i-1]+h)%n])) cn[p[i]]++;
		}
		c=cn;
	}
	p.erase(p.begin());
	return p;
}

vector<int> id2(const string& s, const vector<int>& p) {
	int n = p.size();
	vector<int> rank(n);
	for(int i=0;i<n;i++) {
		rank[p[i]]=i;
	}
	vector<int> lcp(n-1);
	int k=0;
	for(int i=0;i<n;i++) {
		if(rank[i]==n-1) {
			k=0;
			continue;
		}
		int j = p[rank[i]+1];
		while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[rank[i]]=k;
		if(k) k--;
	}
	return lcp;
}


struct Matrix {
	vector<vector<int>> a = {{0,0},{0,0}};
	Matrix operator*(const Matrix& other) {
		Matrix product;
		ll temp;
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				temp=0;
				for(int k=0;k<2;k++) {
					temp = temp + (ll)a[i][k]*other.a[k][j]%mod; 

				}
				product.a[i][j] = (int)(temp%mod);
			}
		}
		return product;
	}
};

ll binpow(ll a, ll b, ll m) {
	return mint(a).pow(b).x;
}

vector<mint> fact,invfact;
void init_combo(ll n) {
	fact.resize(n+1,1);
	invfact.resize(n+1);
	for(ll i=1;i<=n;i++) {
		fact[i]=fact[i-1]*i;
	}
	invfact[n]=~fact[n];
	for(ll i=n;i>0;i--) {
		invfact[i-1]=invfact[i]*i;
	}
}

mint ncr(ll n, ll r) {
	if(n<0||r<0||n<r) return mint(0);
	return fact[n]*invfact[r]*invfact[n-r];
}

struct node {
    ll cnt=0, sum=0, sum2=0, lazy=0;

    node operator+(const node& other) {
        node res;
        res.sum2 = sum2+other.sum2;
        res.sum = sum+other.sum;
        res.cnt = cnt+other.cnt;
        return res;
    }
};

ll nax = 2e5+5;
vector<node> t(4*nax);

void mark(int v, ll k) { 

    t[v].sum2 += (t[v].sum*k + t[v].cnt*((k*(k-1))/2));
    t[v].sum += (t[v].cnt*k);
    t[v].lazy+=k;
}

void push(int v) {
    if(t[v].lazy) {
        mark(2*v,t[v].lazy);
        mark(2*v+1,t[v].lazy);
        t[v].lazy=0;
    }
}

void update(int tl, int tr, int v, int i, ll sum, bool add) { 

    if(tl==tr) {
        if(add) {
            t[v].cnt=1;
        } else {
            t[v].cnt=0;
        }
        t[v].sum = sum;
        t[v].sum2 = (sum*(sum-1))/2;
    } else {
        push(v);
        int tm = (tl+tr)/2;
        if(i<=tm) {
            update(tl,tm,2*v,i,sum,add);
        } else update(tm+1,tr,2*v+1,i,sum,add);
        t[v] = t[2*v]+t[2*v+1];
    }
}

void add(int tl, int tr, int v, int l, int r, int to_add) {

    if(l>r) return;
    if((tl==l)&&(tr==r)) {
        mark(v,to_add);
    } else {
        push(v);
        int tm = (tl+tr)/2;
        add(tl,tm,2*v,l,min(r,tm), to_add);
        add(tm+1,tr,2*v+1,max(tm+1,l),r, to_add);
        t[v] = t[2*v]+t[2*v+1];
    }
}

node query(int tl, int tr, int v, int l, int r) {
    if(l>r) return node();
    if((tl==l)&&(tr==r)) return t[v];
    push(v);
    int tm = (tl+tr)/2;
    return query(tl, tm, 2*v, l, min(r,tm))+query(tm+1,tr, 2*v+1, max(l,tm+1),r);
}

void solve() {
    ll q,d;
    cin>>q>>d;
    vector<bool> inset(nax,false);
    ll a;
    for(int i=0;i<q;i++) {
        cin>>a;
        a--;
        if(inset[a]) {
            update(0,nax-1,1,a,0,false);
            add(0,nax-1,1,max(0LL,a-d),a-1,-1);
            inset[a]=false;
        } else {
            update(0,nax-1,1,a,query(0,nax-1,1,a+1,min(nax-1,a+d)).cnt,true);
            add(0,nax-1,1,max(0LL,a-d),a-1,1);
            inset[a]=true;
        }
        cout<<query(0,nax-1,1,0,nax-1).sum2<<'\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc=1;
	

    for(int i=1;i<=tc;i++) {
        solve();
    }
	return 0;
}

 