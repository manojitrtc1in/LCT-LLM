

using namespace __gnu_pbds;
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;  
using vpii = vector<pii>;
template <typename key_type, typename value_type, typename comp = less<key_type>>
using rbt_map = tree<key_type, value_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key_type, typename comp = less<key_type>>
using rbt_set = rbt_map<key_type, null_type, comp>;

















template <typename value_type, typename relax_type = value_type, typename predictor = less<value_type>>
void id12(value_type& val, const relax_type& rel) { static predictor pred; if (pred(val, rel)) val = rel; }
template <typename type>
void id8(type& val, const type& rel) { id12<type, type, greater<type>>(val, rel); }
template <typename type>
void id19(type& val, const type& rel) { id12<type, type, less<type>>(val, rel); }
ld const PI = acos(-1);














                         














namespace io {


ofstream logger_("log", ios::out);


template <typename iter_t>
void id14(std::istream& in, iter_t begin, iter_t end) {
	for (; begin != end; ++begin) {
		in >> *begin;
	}
}

template <typename iter_t>
void read_seq(iter_t begin, iter_t end) {
	for (; begin != end; ++begin) {
		std::cin >> *begin;
	}
}

int read_int() {
  int res;
  std::cin >> res;
  return res;	
}

int id0(std::istream& in) {
  int res;
  in >> res;
  return res;	
}

long long read_ll() {
	long long res;
	std::cin >> res;
	return res;
}

long long id2(std::istream& in) {
	long long res;
	in >> res;
	return res;
}

unsigned long long id18() {
	unsigned long long res;
	std::cin >> res;
	return res;
}

unsigned long long id10(std::istream& in) {
	unsigned long long res;
	in >> res;
	return res;
}

char read_char() {
	char c;
	std::cin >> c;
	return c;	
}

char id13(istream& in) {
	char c;
	in >> c;
	return c;	
}

std::string read_str() {
	std::string str;
	std::cin >> str;
	return str;	
}

std::string id1(istream& in) {
	std::string str;
	in >> str;
	return str;	
}


template <typename... types>
void reads(types&... values) {
	(std::cin >> ... >> values);
}

template <typename... types>
void sreads(istream& in, types&... values) {
	(in >> ... >> values);
}


void print() {}

void sprint(ostream& ) {}

template <typename first_type>
void print(first_type&& first_value) {
	std::cout << std::forward<first_type>(first_value);
}

template <typename first_type, typename... types>
void print(first_type&& first_value, types&&... values) {
	std::cout << std::forward<first_type>(first_value) << ' ';
	print(std::forward<types>(values)...);
}

template <typename first_type>
void sprint(ostream& out, first_type&& first_value) {
	out << std::forward<first_type>(first_value);
}

template <typename first_type, typename... types>
void sprint(ostream& out, first_type&& first_value, types&&... values) {
	out << std::forward<first_type>(first_value) << ' ';
	sprint(out, std::forward<types>(values)...);
}   	

template <typename... types>
void println(types&&... values) {
	print(std::forward<types>(values)...);
	std::cout << NLINE;
}

template <typename... types>
void sprintln(ostream& out, types&&... values) {
	sprint(out, std::forward<types>(values)...);
	out << NLINE;
}



template <typename iter_t>
void print_seq(iter_t begin, iter_t end) {
	if (begin != end) {
		loop:
		std::cout << *begin;
		if (++begin != end) {
			std::cout << ' ';
			goto loop;
		}
	}
}

template <typename iter_t>
void id16(std::ostream& out, iter_t begin, iter_t end) {
	if (begin != end) {
		loop:
		out << *begin;
		if (++begin != end) {
			out << ' ';
			goto loop;
		}
	}
}

template <typename iter_t>
void println_seq(iter_t begin, iter_t end) {
	print_seq(begin, end);
	std::cout << NLINE;	
}

template <typename iter_t>
void id3(std::ostream& out, iter_t begin, iter_t end) {
	id16(out, begin, end);
	out << NLINE;
}

template <typename... types>
void LOG(types&&... values) {
	
	sprint(logger_, std::forward<types>(values)...);
	
}

template <typename... types>
void LOGln(types&&... values) {
	
	sprintln(logger_, std::forward<types>(values)...);
	
}




























template <typename iter_t>
void LOG_seq(iter_t begin, iter_t end) {
	
	id3(logger_, begin, end);
	
}




template <typename F, typename S>
std::istream operator>>(std::istream& in, std::pair<F, S>& value) {
	return in >> value.first >> value.second;
}

template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::pair<F, S>& value) {
	
	return out << "(" << value.first << ", " << value.second << ")";
	
	return out << value.first << ' ' << value.second;
	
}

template <typename iter_t>
std::ostream& id15(std::ostream& out, iter_t begin, iter_t end) {
	
	id16(out, begin, end);
	return out;
	
	out << "{";
	if (begin != end) {
		loop:
		out << *begin;
		if (++begin != end) {
			out << ", ";
			goto loop;
		}
	}
	out << "}";
	return out;
	
}

template<typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& value) {
	id14(in, value.begin(), value.end());
	return in;
}
template<typename T, size_t capacity>
std::istream& operator>>(std::istream& in, std::array<T, capacity>& value) {
	id14(in, value.begin(), value.end());
	return in;
}
template<typename T>
std::istream& operator>>(std::istream& in, std::deque<T>& value) {
	id14(in, value.begin(), value.end());
	return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
	return id15(out, value.begin(), value.end());
}
template <typename T, size_t capacity>
std::ostream& operator<<(std::ostream& out, const std::array<T, capacity>& value) {
	return id15(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& value) {
	return id15(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& value) {
	return id15(out, value.begin(), value.end());
}
template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::map<F, S>& value) {
	return id15(out, value.begin(), value.end());
}

template <size_t pos, typename... types>
struct tuple_io_impl {
	using tuple_t = tuple<types...>;
	
	static void read(std::istream& in, tuple_t& value) {
		if constexpr (pos != sizeof...(types)) {
			in >> get<pos>(value);
			tuple_io_impl<pos + 1, types...>::read(in, value);
		}	
	}

	static void print(std::ostream& out, const tuple_t& value) {
		if constexpr (pos != sizeof...(types)) {
			out << get<pos>(value);
			if constexpr (pos + 1 != sizeof...(types)) {
				
				out << ", ";
				
				out << ' ';
				
			}
			tuple_io_impl<pos + 1, types...>::print(out, value);
		}
	}
};

template <typename... types>
std::istream& operator>>(std::istream& in, std::tuple<types...>& value) {
	tuple_io_impl<0, types...>::read(in, value);
	return in;		
}

template <typename... types>
std::ostream& operator<<(std::ostream& out, const std::tuple<types...>& value) {
	
	out << "(";
	
	tuple_io_impl<0, types...>::print(out, value);
	
	out << ")";
	
	return out;		
}

} 




using namespace io;












namespace combinatorics {

enum mod_type {prime, composite};

template <int index = 0,
			mod_type id4 = prime, 
				typename value_t = int, 
					value_t mod_val = 1'000'000'007,
						typename mult_t = long long, 
							typename pow_t = long long>
struct modulus_t {
	using value_type = value_t;
	using mult_type = mult_t;
	using pow_type = pow_t;
	
	static constexpr mod_type mod_tp = id4;
	static value_type mod;
	static mult_type mult_mod;
	static pow_type	id17;

	static void set_mod(const value_type& nmod) {
		mod = nmod;	
		mult_mod = mod;
		if (mod < 3)
			id17 = 0;
		else 
			id17 = mod - 2;
    }
};

template <typename modulus_t_ = modulus_t<>>
struct mint_t {
	using modulus_type = modulus_t_;
	using value_type = typename modulus_type::value_type;
	using mult_type = typename modulus_type::mult_type;
	using pow_type = typename modulus_type::pow_type;
	
private:
	static constexpr const mod_type& mod_tp = modulus_type::mod_tp;
	static constexpr value_type& mod = modulus_type::mod;
	static constexpr mult_type& mult_mod = modulus_type::mult_mod;
	static constexpr pow_type& id17 = modulus_type::id17;

	value_type val = 0;

	static mult_type mult(const mult_type& lhs, const mult_type& rhs) {
		return (lhs * rhs) % mult_mod;
	}
	static mult_type bin_pow(mult_type a, pow_type ppw) {
		mult_type res = 1;
		while (ppw) {
			if (ppw & 1)
				res = mult(res, a);
			a = mult(a, a);
			ppw >>= 1;        			 
		} 	
		return res;
	}
	static void ext_euc(const value_type& a, const value_type& b, value_type& g, value_type& x, value_type& y) {
		if (b < a)
			return ext_euc(b, a, g, y, x);
		if (!a) {
			x = 0;
			y = 1;
			g = b;
			return;
		}	
		value_type id7 = b / a, id11 = b - id7 * a;
		ext_euc(id11, a, g, y, x);
		x -= y * id7; 
	}           
public:
	static const value_type& modulo() {
		return mod;
	}
	static void set_mod(const value_type& nmod) {
		modulus_type::set_mod(nmod);
    }
    const value_type& value() const {
		return val;
	}
    mint_t() = default;
	mint_t(const value_type& val) : val(val) {}

	void normalize() {
		val %= mod;
       	if (val < 0)
       		val += mod;      
	}
	//todo maybe better to do explicit
	explicit operator value_type() {
		return val;
	}
	explicit operator bool() {
		return val;
	}
	///copy/move constructors/assignments are default
       	
	//+- operations
	mint_t& operator+=(const mint_t& add) & {
		val += add.val;
		if (val >= mod)
			val -= mod;
		return *this;
	}
	mint_t& operator-=(const mint_t& sub) & {
		val -= sub.val;
		if (val < 0)
			val += mod;
		return *this;
	}
	mint_t operator-() const {
		mint_t res(val ? mod - val : 0);
		return res;
	}
	friend mint_t operator+(const mint_t& lhs, const mint_t& rhs) {
		mint_t res(lhs);
		res += rhs;
		return res;	
	}
	friend mint_t operator-(const mint_t& lhs, const mint_t& rhs) {
		mint_t res(lhs);
		res -= rhs;
		return res;	
	}

	//++, -- operations
	mint_t& operator++() & {
		++val;
		if (val >= mod)
			val = 0;
	    return *this;
	}
	mint_t& operator--()& {
		if (mod == 1)
			return *this;
		if (!val)
			val = mod;
		--val;
		return *this;
	}
	mint_t operator++(int) & {
		mint_t res(val);
		++(*this);
		return res;
	}
	mint_t operator--(int) & {
		mint_t res(val);
		--(*this);
		return res;		
	}

	 
	        
	//* operations
	friend mint_t operator*(const mint_t& lhs, const mint_t& rhs) {
		mint_t res(mult(lhs.val, rhs.val));
		return res;	
	}
	mint_t& operator*=(const mint_t& mlt) & {
		val = mult(val, mlt.val);
		return *this;
	}

	//^ operations     
	mint_t& operator^=(const pow_type& ppw) & {
		val = bin_pow(val, ppw);       	
		return *this;
	}
	friend mint_t operator^(const mint_t& a, const pow_type& ppw) {
		mint_t res(bin_pow(a.val, ppw));
		return res;
	}

	//\operators
	void invert() & {
		val = bin_pow(val, id17);			
	}
	mint_t inv() const {
		if constexpr (mod_tp == composite) {
			static value_type res, buf, g;
			ext_euc(val, mod, g, res, buf);
			if (g != 1)
				res = 0;
			mint_t ans(res);
			ans.normalize();
			return ans;		
		} else {
			mint_t res(bin_pow(val, id17));
			return res;	
		}
		return mint_t(0);
	}
	friend mint_t operator/(const mint_t& lhs, const mint_t& rhs) {
		if constexpr (mod_tp == composite) {
			static value_type res, buf, g;
			ext_euc(rhs.val, mod, g, res, buf);
			if (lhs.val % g)
				res = 0;
			mint_t ans(res);
			ans.normalize();
			return ans;	
		} else {
			return lhs * rhs.inv();
		}
		return mint_t(0);
	}
	mint_t& operator/=(const mint_t& divi) & {
		(*this) = (*this) / divi; 	
		return *this;
	}

	//stream operators
	friend std::istream& operator>>(std::istream& in, mint_t& x) {
		in >> x.val;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const mint_t& x) {
		out << x.val;
		return out;
	}

	//comparisons 
	friend bool operator==(const mint_t& lhs, const mint_t& rhs) {
		return lhs.val == rhs.val;
	}
	friend bool operator!=(const mint_t& lhs, const mint_t& rhs) {
		return !(lhs == rhs);
	}
	friend bool operator<(const mint_t& lhs, const mint_t& rhs) {
		return lhs.val < rhs.val;
	}
	friend bool operator>(const mint_t& lhs, const mint_t& rhs) {
		return rhs.val < lhs.val;
	}
	friend bool operator<=(const mint_t& lhs, const mint_t& rhs) {
		return !(rhs.val < lhs.val);
	}
	friend bool operator>=(const mint_t& lhs, const mint_t& rhs) {
		return !(lhs.val < rhs.val);
	}

	//k : a^k == b
	static pow_type dlog(const mint_t& a, const mint_t& b) {
		pow_type n = (pow_type)sqrtl(mod + .0) + 10;
		std::map<mint_t, pow_type> vals;
		mint_t an = a^n;  
		mint_t ani = an;   //a^{ni}
		for (pow_type i = 1; i <= n; ++i, ani *= an) {
			vals.emplace(ani, i);
		}
		mint_t ai = a;  //a^i
		for (pow_type i = 1; i <= n; ++i, ai *= a) {
			auto it = vals.find(ai * b);
			if (it != vals.end())
				return it->second * n - i;
		}
		return -1;	
	}
};

template <int index,
			mod_type mod_tp, 
				typename value_t, 
					value_t mod_val,
						typename mult_t, 
							typename pow_t>
value_t modulus_t<index, mod_tp, value_t, mod_val, mult_t, pow_t>::mod = mod_val;

template <int index,
			mod_type mod_tp, 
				typename value_t, 
					value_t mod_val,
						typename mult_t, 
							typename pow_t>
mult_t modulus_t<index, mod_tp, value_t, mod_val, mult_t, pow_t>::mult_mod = mod_val;

template <int index,
			mod_type mod_tp, 
				typename value_t, 
					value_t mod_val,
						typename mult_t, 
							typename pow_t>
pow_t modulus_t<index, mod_tp, value_t, mod_val, mult_t, pow_t>::id17 = mod_val - 2;
	
template <typename value_t = mint_t<>>
struct id9 {
	using value_type = value_t;
private:
	using pow_type = typename value_t::pow_type;
	value_t* fac_ = nullptr;
public:
	void resize(size_t n) {
		delete[] fac_;
		fac_ = new value_t[n + 1];
		value_t val = 1;
		fac_[0] = val;	
		
		for (size_t i = 1; i <= n; ++i, ++val)
			fac_[i] = fac_[i - 1] * val;
	}
	
	id9() = default;
	id9(size_t n) {		
		resize(n);
	}
	id9(const id9&) = delete;
	~id9 () {
		delete[] fac_;
	}
	
	const value_t& fac(size_t n) const {
		return fac_[n];		
	}
	value_t C(size_t n, size_t k) const {
		return fac[n] / (fac[n - k] * fac[k]);
	}
	value_t A(size_t n, size_t k) const {
		return fac[n] / fac[n - k]; 
	}
	value_t A_rep(const value_t& n, const pow_type& k) {
		return n ^ k; 			
	}
	value_t C_rep(size_t n, size_t k) const {
		return C(n + k - 1, k);
	}
	value_t Catalan(size_t n) const {
		return C(2 * n, n) / value_t(n + 1);	
	}
};

template <typename value_t = mint_t<>>
struct id6 {
	using value_type = value_t;
private:
	using pow_type = typename value_t::pow_type;
	id9<value_t> fac_;
	value_t* id5 = nullptr;

public:
	void resize(size_t n) {
		fac_.resize(n);
		delete[] id5;
		id5 = new value_t[n + 1];

		value_type val = n;
		id5[n] = fac_.fac(n).inv();
		for (size_t i = n; i; --i, --val) {
			id5[i - 1] = id5[i] * val;	
		}	    
	}

	id6() = default;
	id6(size_t n) {
		resize(n);
	}
	~id6() {
		delete[] id5;
	}	

	const value_t& fac(size_t n) const {
		return fac_.fac(n);
	}
	const value_t& ifac(size_t n) const {
		return id5[n];
	}
	value_t C(size_t n, size_t k) {
		return fac(n) * ifac(k) * ifac(n - k);		
	}
	value_t A(size_t n, size_t k) {
		return fac(n) * ifac(n - k);
	}
	value_t C_rep(size_t n, size_t k) {
		return C(n + k - 1, k);
	}
	value_t A_rep(const value_t& n, const pow_type& k) {
		return n ^ k; 			
	}
	value_t Catalan(size_t n) const {
		return C(2 * n, n) / value_t(n + 1);	
	}

	//Stirling's number (2 kind)
	value_t S(const pow_type& n, size_t k) {
		value_t res = 0;
		bool sub = (k & 1);
		for (size_t j = 0; j <= k; ++j, sub = !sub) {
			value_t cur = C(k, j) * (value_type(j) ^ n);
			if (sub)
				res -= cur;
			else
				res += cur;				
		}
		res *= ifac(k);
		return res;
	}
};

} 





using namespace combinatorics;
using mint = mint_t<>;



int const N = 1e6 + 4;
mint ppw[N], ippw[N];
mint dp[N], sdp[N];

mint lcalc(int i, int) {
	if (i == 1) {
		return 0;
	}	
	int mk = (i - 1) / 2;
	return ippw[mk + 1] * dp[i];
}

mint rcalc(int i, int n) {
	return i == n ? lcalc(i, n) : mint(0);
}

void solve() {
	int n = read_int();
	if (n == 1) {
		println(1);
		return;
	}
	sdp[n + 1] = 0;
	dp[n] = 1;
	sdp[n] = dp[n] * ippw[n];
	f(i, n - 1, 2) {
		dp[i] = 0;
		if (i > n - i) {
			dp[i] = ippw[n - i];
		}
		int r = min(n, 2 * i - 1);
		dp[i] += ppw[i] * (sdp[i + 1] - sdp[r + 1]);
		sdp[i] = sdp[i + 1] + dp[i] * ippw[i];
	}
	F(i, 1, n) {
		mint tot = lcalc(i, n) + rcalc(i, n);
		println(tot);
	}		
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	ppw[0] = 1;
	F(i, 1, N - 1) {
		ppw[i] = ppw[i - 1] + ppw[i - 1];
	}
	ippw[N - 1] = ppw[N - 1].inv();
	f(i, N - 1, 1) {
		ippw[i - 1] = ippw[i] + ippw[i];
	}
	int t = read_int();
	while (t--) {
		solve();
	}   
	return 0;
}       		