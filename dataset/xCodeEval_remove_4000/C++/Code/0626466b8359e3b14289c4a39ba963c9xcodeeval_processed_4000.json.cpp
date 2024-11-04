





using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

struct custom_hash { 

    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + id0);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}


ostream& operator << (ostream &os, __int128 T){
    const static long long N = (1'000'000'000'000'000'000);
    if (T < 0){
        os << '-';
        T *= -1;
    }

    unsigned long long b = T%N;
    T /= N;
    if (T == 0)
        return os << b ;
    unsigned long long a = T % N;
    T /= N;
    if (T == 0){
        os << a;
        __int128 mul = 10;
        int cnt = 0;
        while( mul*b < N && cnt < 17){
            os << '0';
            mul *= 10;
            ++cnt;
        }
        return os << b;
    }
    os << ((long long) T);
    
     __int128 mul = 10;
      int cnt = 0;
    while( mul*a < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    os << a;
    mul = 10;
    cnt = 0;
    while( mul*b < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    return os << b;

}
istream& operator >> (istream& is, __int128& T){
    string U;
    is >> U;
    T = 0;
    size_t pos = 0;
    int mul = 1;
    if (U[pos] == '-'){
        ++pos;
        mul *= -1;
    }
    for(; pos < U.size(); ++pos){
        T *= 10;
        T += (U[pos] - '0');
    }
    T *= mul;

    return is;
}

template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}



    
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }

    


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}



typedef vector<int> vi;
typedef pair<int,int> pii;











const int mod=1e9+7;
template<const int MOD>
struct id1{
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	id1(){
		x = 0;
	}
	template<typename T>  
	id1(const T z){
		x = (z%MOD);
		if (x < 0) x += MOD; 	
	}
	id1(const id1<MOD>* z){
		x = z->x;
	}
	id1(const id1<MOD>& z){
		x = z.x;
	}
	id1 operator - (const id1<MOD>& m) const{
		id1<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	id1 operator + (const id1<MOD>& m) const{
		id1<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	id1& operator -= (const id1<MOD>& m){
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}	
	id1& operator += (const id1<MOD>& m){
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}	
	id1 operator * (const id1<MOD>& m) const{
		id1<MOD> U;
		U.x = (x* 1ull * m.x) %MOD;
		return U;
	}
	id1& operator *= (const id1<MOD>& m){
		x = (x * 1ull * m.x)%MOD;
		return *this;
	}
	template<typename T>
	friend id1 operator + (const T &l, const id1<MOD>& p){
		return (id1<MOD>(l) + p);
	}
	template<typename T>
	friend id1 operator - (const T &l, const id1<MOD>& p){
		return (id1<MOD>(l) - p);
	}
	template<typename T>
	friend id1 operator * (const T &l, const id1<MOD>& p){
		return (id1<MOD>(l) * p);
	}
	template<typename T>
	friend id1 operator / (const T &l, const id1<MOD>& p){
		return (id1<MOD>(l) / p);
	}

	int value() const{
		return x;
	}

	id1 operator ^ (const id1<MOD>& cpower) const{
		id1<MOD> ans;
		ans.x = 1;
		id1<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return ans;
	}


	id1 operator ^ (long long power) const{
		id1<MOD> ans;
		ans.x = 1;
		id1<MOD> curr(this);
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		

		if (power >= MOD && is_prime){
			power %= (MOD - 1);
		}

		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	id1 operator ^ (int power) const{
		id1<MOD> ans;
		ans.x = 1;
		id1<MOD> curr(this);
		
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}
	
	template<typename T>
	id1& operator ^= (T power) {
		id1<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}


	template<typename T>
	id1 pow(T x){
		return (*this)^x;
	}

	
	pair<long long,long long> gcd(const int a, const int b) const {
		if (b==0) return {1,0}; 
		pair<long long,long long> c = gcd(b , a%b);
		return { c.second , c.first - (a/b)*c.second}; 
	}

	inline void init_inverse_list() const {
		
		vector<int>& dp = id1<MOD>::inverse_list;
		dp.resize(id1<MOD>::inverse_limit + 1);
		int n = id1<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for(int i = 2; i <= n; ++i){
			dp[i] = (dp[MOD%i] * 1ull *(MOD - MOD/i))%MOD;
		}
	
	}
	id1<MOD> get_inv() const {
		if (id1<MOD>::inverse_list.size() < id1<MOD>::inverse_limit + 1) init_inverse_list();

		if (this->x <= id1<MOD>::inverse_limit){
			return id1<MOD>::inverse_list[this->x];
		}
		pair<long long,long long> G = gcd(this->x,MOD);
		return id1<MOD>(G.first);
	}
	id1<MOD> operator - () const {
		id1<MOD> v(0);
		v -= (*this);
		return v;
	}
	id1 operator / (const id1<MOD>& m) const{
		id1<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	id1& operator /= (const id1<MOD>& m){
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const id1<MOD>& m) const{
		return x == m.x;
	}

	bool operator < (const id1<MOD>& m) const {
		return x < m.x;
	}


	template<typename T>
	bool operator == (const T& m) const{
		return (*this)== (id1<MOD>(m));
	}

	template<typename T>
	bool operator < (const T& m) const {
		return x < (id1<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (id1<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const id1<MOD>& m) {
		return (id1<MOD>(x)).x == m.x;
	}
	template<typename T> 
	friend bool operator < (const T& x, const id1<MOD>& m){
		return (id1<MOD>(x)).x < m.x;
	}
	template<typename T> 
	friend bool operator > (const T& x, const id1<MOD>& m){
		return (id1<MOD>(x)).x > m.x;
	}

	friend istream& operator >> (istream& is, id1<MOD>& p){
		int64_t val;
		is >> val;
		p.x = (val%MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const id1<MOD>& p) {return os<<p.x;}



};



using mint = id1<mod>;
template<const int MOD>
vector<int> id1<MOD>::inverse_list ;
template<const int MOD>
const int id1<MOD>::inverse_limit = -1;
template<const int MOD>
const bool id1<MOD>::is_prime = true;








bool cmp(const pair<ll,ll>& b, const pair<ll,ll>& a){
	return (b.second < a.second || (b.second == a.second && b.first < a.first));
}

void uniq(vector<pair<ll,ll>> & T){
	set<int> cur;

	for(auto e: T){
		cur.insert(e.first);
		cur.insert(e.second);
	}

	cur.insert(0);
	gp_hash_table<int,int> mp;
	int z = 1;
	for(auto e: cur){
		mp[e] = z;
		++z;
	}

	for(auto&e : T){
		e.first = mp[e.first];
		e.second = mp[e.second];
	}
}


const int N = 3e5 + 100;

mint bit[N];



void upd(int x,mint y){
	while(x < N){
		bit[x] += y;
		x += (x & (-x));
	}
}

mint sum(int x){
	mint ans = 0;
	while(x > 0){
		ans += bit[x];
		x -= (x & (-x));
	}
	return ans;
}


mint sum(int l,int r){
	return sum(r) - sum(l  - 1);
}
void solve(){
	int n;
	cin >> n;
	ll m;
	cin >> m;
	vector<pair<ll,ll>> res;
	if (m == 0){
		cout << 0 << endl;
		return;
	}
	for(int i = 0; i < m; ++i){
		ll s, t;
		cin >> s >> t;
		res.push_back({s, t});
	}
	sort(all(res), cmp);


	if (res.back().second != n){
		cout << 0 << endl;
		return;
	}
	uniq(res);



	gp_hash_table<int, mint, custom_hash> dp;

	dp[1] = 1;

	int tot = res.size();


	upd(1, 1);

	for(auto e: res){
		mint cur = sum(e.first, e.second - 1);
		dp[e.second] += cur;
		upd(e.second, cur);
	}



	ll tt = res.back().second;
	cout << sum(tt , tt) << endl;

}
int main(){
    

    

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    

    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    

}