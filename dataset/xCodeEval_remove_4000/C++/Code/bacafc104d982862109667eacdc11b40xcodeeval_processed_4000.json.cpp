





using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 


template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}

template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
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
inline int64_t random_long(long long l = id3,long long r = id2){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
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
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + id0);
    }
};






const int mod = 998244353;
template<const int MOD>
struct id5{
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	id5(){
		x = 0;
	}
	template<typename T>  
	id5(const T z){
		x = (z%MOD);
		if (x < 0) x += MOD; 	
	}
	id5(const id5<MOD>* z){
		x = z->x;
	}
	id5(const id5<MOD>& z){
		x = z.x;
	}
	id5 operator - (const id5<MOD>& m) const{
		id5<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	id5 operator + (const id5<MOD>& m) const{
		id5<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	id5& operator -= (const id5<MOD>& m){
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}	
	id5& operator += (const id5<MOD>& m){
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}	
	id5 operator * (const id5<MOD>& m) const{
		id5<MOD> U;
		U.x = (x* 1ull * m.x) %MOD;
		return U;
	}
	id5& operator *= (const id5<MOD>& m){
		x = (x * 1ull * m.x)%MOD;
		return *this;
	}
	template<typename T>
	friend id5 operator + (const T &l, const id5<MOD>& p){
		return (id5<MOD>(l) + p);
	}
	template<typename T>
	friend id5 operator - (const T &l, const id5<MOD>& p){
		return (id5<MOD>(l) - p);
	}
	template<typename T>
	friend id5 operator * (const T &l, const id5<MOD>& p){
		return (id5<MOD>(l) * p);
	}
	template<typename T>
	friend id5 operator / (const T &l, const id5<MOD>& p){
		return (id5<MOD>(l) / p);
	}

	int value() const{
		return x;
	}

	id5 operator ^ (const id5<MOD>& cpower) const{
		id5<MOD> ans;
		ans.x = 1;
		id5<MOD> curr(this);
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


	id5 operator ^ (long long power) const{
		id5<MOD> ans;
		ans.x = 1;
		id5<MOD> curr(this);
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

	id5 operator ^ (int power) const{
		id5<MOD> ans;
		ans.x = 1;
		id5<MOD> curr(this);
		
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
	id5& operator ^= (T power) {
		id5<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}


	template<typename T>
	id5 pow(T x){
		return (*this)^x;
	}

	
	pair<long long,long long> gcd(const int a, const int b) const {
		if (b==0) return {1,0}; 
		pair<long long,long long> c = gcd(b , a%b);
		return { c.second , c.first - (a/b)*c.second}; 
	}

	inline void init_inverse_list() const {
		
		vector<int>& dp = id5<MOD>::inverse_list;
		dp.resize(id5<MOD>::inverse_limit + 1);
		int n = id5<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for(int i = 2; i <= n; ++i){
			dp[i] = (dp[MOD%i] * 1ull *(MOD - MOD/i))%MOD;
		}
	
	}
	id5<MOD> get_inv() const {
		if (id5<MOD>::inverse_list.size() < id5<MOD>::inverse_limit + 1) init_inverse_list();

		if (this->x <= id5<MOD>::inverse_limit){
			return id5<MOD>::inverse_list[this->x];
		}
		pair<long long,long long> G = gcd(this->x,MOD);
		return id5<MOD>(G.first);
	}
	id5<MOD> operator - () const {
		id5<MOD> v(0);
		v -= (*this);
		return v;
	}
	id5 operator / (const id5<MOD>& m) const{
		id5<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	id5& operator /= (const id5<MOD>& m){
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const id5<MOD>& m) const{
		return x == m.x;
	}

	bool operator < (const id5<MOD>& m) const {
		return x < m.x;
	}


	template<typename T>
	bool operator == (const T& m) const{
		return (*this)== (id5<MOD>(m));
	}

	template<typename T>
	bool operator < (const T& m) const {
		return x < (id5<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (id5<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const id5<MOD>& m) {
		return (id5<MOD>(x)).x == m.x;
	}
	template<typename T> 
	friend bool operator < (const T& x, const id5<MOD>& m){
		return (id5<MOD>(x)).x < m.x;
	}
	template<typename T> 
	friend bool operator > (const T& x, const id5<MOD>& m){
		return (id5<MOD>(x)).x > m.x;
	}

	friend istream& operator >> (istream& is, id5<MOD>& p){
		int64_t val;
		is >> val;
		p.x = (val%MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const id5<MOD>& p) {return os<<p.x;}



};



using mint = id5<mod>;
template<const int MOD>
vector<int> id5<MOD>::inverse_list ;
template<const int MOD>
const int id5<MOD>::inverse_limit = -1;
template<const int MOD>
const bool id5<MOD>::is_prime = true;
template<>   

const int id5<mod>::inverse_limit = 100000;





const int N = 1e6 + 100;

mint fact[N], inv_f[N];

void preprocess(){
	fact[0] = 1;
	inv_f[0] = 1;
	for(int i = 1; i < N; ++i){
		fact[i] = fact[i - 1] * i;
		inv_f[i] = inv_f[i - 1] / i;
	}
}
mint ncr(int n, int r){
	if (r < 0  || r > n || n < 0)
		return 0;
	return fact[n] * inv_f[r] * inv_f[n - r];
}
void solve(){
    int n;
    cin >> n;
    vector<int> cnt(n);

    int g = 0;
    {
    	for(int i = 0; i < n; ++i){
    		int x;
    		cin >> x;
    		++cnt[x - 1];
    	}
    	vector<int> tmp;

    	for(auto e: cnt){
    		if (e > 0)
    			tmp.push_back(e);
    	}
    	cnt = tmp;
    	for(auto e: cnt){
    		g = __gcd(e, g);
    	}
    	if (cnt.size() == 1){
    		assert (g == n);
    		cout << 1 << endl;
    		return;
    	}
    }

 	mint tot = 0;
 	mint id4 = 0;

 	vector<mint> id6(n + 1), id1(n + 1);
 	vector<bool> done(n + 1, false);
 	for(int i = 0; i < n; ++i){
 		int num_cycles = __gcd(i, n);
 		int cycle_len = n / num_cycles;
 		if ((g % cycle_len) != 0){
 			continue;
 		}

 		if (done[cycle_len]){
 			tot += id6[cycle_len];
 			id4 += id1[cycle_len];
 			continue;
 		}

 		mint ways = fact[num_cycles];


 		mint expected = 0;


 		for(int z: cnt){
 			assert ((z % cycle_len) == 0);
 			int here = z / cycle_len;
 			if (here >= 2){
 				assert (num_cycles >= 2);
 				mint here_way = here * mint(here - 1);
 				here_way /= (num_cycles * mint(num_cycles - 1));
 				expected += here_way;
 			}
 			ways *= inv_f[z / cycle_len];
 		}
 		expected *= n;

 		done[cycle_len] = true;
 		id1[cycle_len] = ways;
 		id6[cycle_len] = ways * (n - expected);

 		if (done[cycle_len]){
 			tot += id6[cycle_len];
 			id4 += id1[cycle_len];
 			continue;
 		}

 	}   
 	cout << tot / id4 << endl;
}
int main(){
    

    

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    preprocess();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    

}