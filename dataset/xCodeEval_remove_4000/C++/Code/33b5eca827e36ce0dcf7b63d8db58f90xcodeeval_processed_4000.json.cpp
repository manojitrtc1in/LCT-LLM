 















































































 
 




const long long mod = 1e9+7;


const long long mod1 = 998244353;
const long long int special_prime = 982451653;
using namespace std;





vector<string> id9(string s) {
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





















































const long long N = 1e6 + 100;
 int pr[N]; void id12(){for(int i = 2; i < N; ++i){if(!pr[i])for(int j = i; j < N; j+=i)pr[j]=i;}}
 ll inv[N]; void id1(){inv[0]=0;inv[1]=1;for(int i = 2; i < N; ++i)inv[i] = mod-mod/i*inv[mod%i]%mod;}

 ll ifact[N]; void id7(){ifact[0]=1; ifact[1] = 1; for(int i = 2; i < N; ++i)ifact[i]=ifact[i-1]*inv[i]%mod;}

 ll fact[N];
void preFact(){fact[0] = 1,fact[1] = 1; for(int i = 2; i < N; ++i)fact[i]=fact[i-1]*i%mod;}


 
 
 
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator<<(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
template<class T, class U>pair<T,U> operator+(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first+b.first,a.second+b.second);}
template<class T, class U>pair<T,U> operator-(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first-b.first,a.second-b.second);}




template<class T>istream& operator>>(istream& in, vector<T> &a){for(auto &i: a)cin >> i;return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a){for(auto &i: a)cout << i << " ";return out;}


template<class T>ostream& operator<<(ostream& out, const set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a){for(auto &i: a)cout << i << " ";return out;}


template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}
 
using namespace __gnu_pbds;

template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;



const long long inf = 1e9;
const long double pi = acos(-1);

string tostring(int number){stringstream ss; ss<<number; return ss.str();}


ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int INF = (int) 1e9;
const int INF2 = 0x3f3f3f3f;

const int maxm=1e5+5;


const int XN = 1e5 + 3;
ll binpower(ll base, ll e, ll mod) 
{
    int result = 1;
    base %= mod;
    while (e) 
    {
        if (e & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        e >>= 1;
    }
    return result;
}

bool id13(int n, int a, int d, int s)
 {
    int x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (int)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool id14(int n) 
{ 
	

    if (n < 2)
        return false;


    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0) 
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (id13(n, a, d, r))
            return false;
    }
    return true;
}
ll wil_work(string a,string b)
{
   
    int i = 0;
    for(int k=0;k<a.length();k++){
        if(a[k]==b[i])
        {
			
            i++;
        }
        if(i >= b.length())
        {
            ll ans = a.length() - b.length();
            return ans;
        }
    }
    ll ans = (b.length() - i) + (a.length() - i);
    return ans;
   
}	
bool id5(const string& s) 
{
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}

vector<int> id2(int n) 
{
    vector<int> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (int d = 3; d * d <= n; d += 2)
     {
        while (n % d == 0)
         {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

ll gcd(ll a, ll b){
	return (b == 0) ? a : gcd(b, a % b);}	

	
bool id8(ll n, ll digit) 
{ 
    

    

    return (digit != 0 && n % digit == 0); 
} 
  




int id0(int n, int k) 
{ 
    return pow(k, 
               (1.0 / k) 
                   * (log(n) 
                      / log(k))); 
} 
int id10(int n)
{
    int num = n;
    int dec_value = 0;
 
    

    int base = 1;
 
    int temp = num;
    while (temp) 
    {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}






set<ll>facs (ll n)  
{  
	set<ll>val;
    

    while (n % 2 == 0)  
    {  
        val.insert(2);
        n = n/2;  
    }  
  
    

    

    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        

        while (n % i == 0)  
        {  
            val.insert(i);
            n = n/i;  
        }  
    }  
  
    

    

    if (n > 2)  
        val.insert(n);
        
  return val;
}  


ll getExponent(int n, int p) {
    if (p <= 1) {
        return -1;
    }
    int x = 0;
    for (; n % p == 0; n /= p) {
        x++;
    }
    return x;
}
ll largestPower(ll n, ll p)  
{  
    

    ll x = 0;  
  
    

    while (n)  
    {  
        n /= p;  
        x += n;  
    }  
    return x;  
} 
long long id11(long long a,
                            long long b,
                            long long mod)
{
    long long res = 0; 

  
    

    

    a %= mod;
  
    while (b)
    {
        

        if (b & 1)
            res = (res + a) % mod;
  
        

        

        a = (2 * a) % mod;
  
        b >>= 1; 

    }
  
    return res;
}

class trio {
 public:
	int first,second ,third;
 
	void print() {
		cout << first << " " << second << " " << third << endl;
	}
};
bool id3(trio &a, trio &b) 
{
	if (a.TH == b.TH) {
		if (a.S == b.S)
			return a.F < b.F;
		return a.S < b.S;
	}
	return a.TH < b.TH;
}
bool id4(trio &a,trio &b)
{
	
	return a.TH < b.TH;
	}
	
 
template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;
 
  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }
 
  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l], l);
 
    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }
 
  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }
 
  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
 
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];
 
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }
 
  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }
 
  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;
 
    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
 
  
  
  void eval_lazy(int i, int l, int r) {
    
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
    
 
    lazy[i] = num_t();
  }
};

struct max_t {
  long long val;
  int ind;
  static const long long null_v = -9223372036854775807LL;
 
  max_t(): val(0) {}
  max_t(long long v): val(v) {}
  max_t(long long v, int i): val(v), ind(i) {};
 
  max_t op(max_t& other) {
     if (other.val == val) 
      return (ind < other.ind) ? other : *this;
    return (val < other.val) ? other : *this;
  }
  
  max_t lazy_op(max_t& v, int size) {
    return max_t(val + v.val,ind);
  }
};
struct min_t {
  long long val;
  int ind;
  static const long long null_v = 9223372036854775807LL;
 
  min_t(): val(0) {}
  min_t(long long v): val(v) {}
  min_t(long long v, int i): val(v), ind(i) {};
 
  min_t op(min_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val > other.val) ? other : *this;
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val, ind);
  }
};

struct sum_t {
  long long val;
  int ind;
  static const long long null_v = 0;
 
  sum_t(): val(0) {}
  sum_t(long long v): val(v) {}
  sum_t(long long v, int i): val(v), ind(i) {};
 
  sum_t op(sum_t& other) {
    return sum_t(val + other.val,ind);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    return sum_t(val + v.val * size,ind);
  }
};
 


struct SG {
    V<int> tree;
    SG() {}
    SG(int n) {
        tree.assign(4 * n, 0);
    }
    int query(int i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return tree[i];
        int m = (l + r) / 2;
        return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
    }
    void upd(int i, int l, int r, int k, int x) {
        if(l == r) {
            tree[i] = max(tree[i], x);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m) upd(2 * i + 1, l, m, k, x);
        else upd(2 * i + 2, m + 1, r, k, x);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
};
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}



const int MX = 200001; 

const int NX = 500001;
const int mxX=1e5+7;
const int nx = 20;
const int M1 = 1e9+9;
const int M2 = 1e9+7;



V<int> primes, leastFac;
bool is_prime[NX+NX];
void id6(int N) {
	memset(is_prime,false,sizeof(is_prime));
	loop(i,0, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	loop(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			is_prime[i]=true;
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
			is_prime[i*primes[j]]=false;
		}
	}
}
V<PLL>adj[MX];
V<ll>mia[MX];

const ll MR= 1e4+5;


ll n,m,k;




ll vis[MX+MX];




char val[501][501],siz[MX];







int check=0;
ll name(ll x,ll y){
	return x*m+y;
	
	}





segtree<sum_t> st2; 




ll a[MX+MX],b[501][501],posi[MX];
bool dfs(int x,int st)
{
	if(vis[x]){return 1;}
	vis[x]=1;
	a[x]=st;
	for(auto k:adj[x]){
		if(!vis[k.F]){dfs(k.F,k.S^a[x]);}
		else{
			if(a[x]^a[k.F] != k.S){return 0;}
			
			
			}
		
		
		}
	return 1;
	
}
int main()
{
	FAST;
cout<<setprecision(12)<<fixed;
int tes=1;




while(tes--)
{ 
 cin>>n>>m;
 loop(i,0,n){
	 loop(j,0,m){
		 
		 cin>>val[i][j];
		 }
	 
	 
	 }
 
 V<ll>mia;
check=0;
loop(i,0,n){
	
	loop(j,0,m){
		
		if(val[i][j]=='X'){
			int cn=0;
			mia.clear();
			loop(k,0,4){
				
				ll na= i+dx[k]; ll nb= j+dy[k];
				if(val[na][nb]=='.'){cn++; mia.pb(k);}
				
				}
			if(cn&1){check=1; break;}
			if(cn==2){
				

				

				

				

				ll x=name(i+dx[mia[0]],j+dy[mia[0]]);
				ll y =name(i+dx[mia[1]],j+dy[mia[1]]);
				adj[x].pb(y,1); 

				adj[y].pb(x,1);
				}else if(cn==4){
					ll x= name(i-1,j); ll y= name(i+1,j);
					adj[x].pb(y,0);
					adj[y].pb(x,0); 

					x= name(i,j-1); y=name(i,j+1);
					adj[x].pb(y,0); adj[y].pb(x,0);
					

					x= name(i-1,j); y= name(i,j-1);
					adj[x].pb(y,1); adj[y].pb(x,1);
					
					
					
					}
					b[i][j]=5*(cn/2);
					
			}
		
		
		}
	
	
	}
if(check){cout<<"NO"<<endl; continue;}	 
 loop(i,0,n)
 {
	 loop(j,0,m){
		 
		 if(val[i][j]!='X'){
			 ll rn= name(i,j);
			 if(!vis[rn]){
			 if(!dfs(rn,0)){
				 

				 cout<<"NO"<<endl; return 0;
				 }
			 }
			 
			 
			 
			 
			 
			 
			 }
		 
		 
		 }
	 
	 }
cout<<"YES"<<endl;
loop(i,0,n)
{
    loop(j,0,m){
        
        if(val[i][j]=='X'){cout<<b[i][j]<<" ";}
        else{
            
            ll rn= name(i,j);
      cout<<1+3*a[rn]<<" ";
            
        }
       
    }
    cout<<endl;
    
    
}
 
}
return 0;
}

 






























