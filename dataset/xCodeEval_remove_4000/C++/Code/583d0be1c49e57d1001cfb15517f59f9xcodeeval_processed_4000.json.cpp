

	
		
	


































	
	

	
	


struct stringException: public std::exception
{
	std::string s;
	
	stringException(std::string s) : s(s)
	{
		std::cerr << "Exception: " << s << std::endl;
	}
	
	~stringException() throw() {}
	
	const char* what() const throw()
	{
		return s.c_str();
	}
};





	

	

	

	class MySIe : public SafeIntException
	{
		public:
			static void SafeIntOnOverflow()
			{
				throw new stringException("Caught a SafeInt Overflow exception!");
			}
			static void SafeIntOnDivZero()
			{
				throw new stringException("Caught a SafeInt Divide By Zero exception!");
			}
	};
	
	

	template<typename T, typename E>
	std::istream& operator>> (std::istream& stream, SafeInt<T,E>& o){
		T val; stream >> val; o = val; return stream;    
	}
	
	template<typename T, typename E>
	std::ostream& operator<< (std::ostream& stream, const SafeInt<T,E>& o){
		T val = o; return stream << val;
	}	





	

	typedef		SafeInt<int32_t, MySIe>		int32;
	typedef		SafeInt<int64_t, MySIe>		int64;
	typedef		SafeInt<uint32_t, MySIe>	uint32;
	typedef		SafeInt<uint64_t, MySIe>	uint64;

	typedef		int32_t						int32;
	typedef		int64_t						int64;
	typedef		uint32_t					uint32;
	typedef		uint64_t					uint64;




typedef			int							_int;




typedef 		std::pair<int32,int32>		ii;
typedef 		std::vector<int32>			vi;
typedef			std::vector<ii> 			vii;
typedef			std::vector<vi>				vvi;
typedef			std::set<int32>				si;
typedef			std::map<int32,int32>		mii;
typedef			std::map<int32,vi>			mivi;
typedef			std::stringstream			ss;







template<typename T>
struct modular
{
	T value;
	T mod;
	
	modular(T modulo): value(0) {
		dbg_assert(modulo > 0);
		mod = modulo;
	}
	
	modular(T val, T modulo)
	{
		dbg_assert(modulo > 0);
		mod = modulo;
		
		while (val < 0)
			val += mod;
		value = val % mod;
	}
	
	T find_inverse(T v)
	{
		T t = 0, newt = 1, temp, r = mod, newr = v;
		while (newr != 0)
		{
			T q = r / newr;
			temp = t, t = newt, newt = temp - q * newt;
			temp = r, r = newr, newr = temp - q * newr;
		}
		if (r > 1)
		{
			ss s;
			s << v << " in NOT invertible!";
			throw new stringException(s.str());
		}
		if (t < 0)
			t += mod;
		return t;
	}
	
	modular<T>& operator=(T val)
	{
		value = val % mod;
		return *this;
	}
	
	modular<T>& operator=(modular<T> o)
	{
		dbg_assert(mod == o.mod);
		value = o.value;
		mod = o.mod;
		return *this;
	}
	
	modular<T> operator*(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		return modular<T>(value * o.value, mod);
	}
	
	modular<T>& operator*=(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		value = (value * o.value) % mod;
		return *this;
	}
	
	modular<T> operator+(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		return modular<T>(value + o.value, mod);
	}
	
	modular<T>& operator+=(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		value = (value + o.value) % mod;
		return *this;
	}
	
	modular<T> operator-(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		return modular<T>(value - o.value);
	}
	
	modular<T>& operator-=(modular<T>& o)
	{
		dbg_assert(mod == o.mod);		
		value = (value - o.value+mod) % mod;
		return *this;
	}
	
	modular<T> operator/(modular<T>& o)
	{
		dbg_assert(mod == o.mod);
		return modular<T>(value * find_inverse(o.value), mod);
	}
	
	modular<T>& operator/=(modular<T>& o){
		dbg_assert(mod == o.mod);
		value = (value * find_inverse(o.value)) % mod;
		return *this;
	}

};






template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	for (
		auto i = v.begin();
		i != v.end() && os << *i;
		(++i != v.end()) ? os << ", " : os
	);
	return os << "]";
}



template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& v)
{
	os << "{";
	for (auto i = v.begin(); i != v.end() && os << *i; (++i != v.end()) ? os << ", " : os)
		;
	return os << "}";
}



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v)
{
	return os << "(" << v.first << ", " << v.second << ")";
}



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& v)
{
	os << "{";
	for (
		auto i = v.begin();
		i != v.end() && os << "[" << i->first << "]: " << i->second;
		(++i != v.end()) ? os << ", " : os
	);
	
	return os << "}";
}



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T1, T2>& v)
{
	os << "{";
	for (
		auto i = v.begin();
		i != v.end() && os << "[" << i->first << "]: " << i->second;
		(++i != v.end()) ? os << ", " : os
	);
	
	return os << "}";
}



template<size_t N>
std::ostream& operator<<(std::ostream& os, const std::bitset<N>& v)
{
	return os << v.to_string();
}




template<typename T>
std::ostream& operator<<(std::ostream& os, const modular<T>& v){
	return os << v.value << "(%" << v.mod << ")";
}






template<typename T>
struct number_iterator: std::iterator<std::forward_iterator_tag, T>
{
	T value,step;
	
	number_iterator(T value, T step): value(value), step(step) {}
	
	operator T&()
	{
		return value;
	}
	
	T operator*() const
	{
		return value;
	}
	
	T operator++()
	{
		return value = value + step;
	}
	
	bool operator!= (const number_iterator<T>& o) const {
		return value != o.value;
	}	
};

template<typename T>
struct number_range
{
	number_iterator<T> first, last;
	
	number_range(T first,T last,T step): first(first,step), last(last,step) {}
	
	number_iterator<T> begin()
	{
		return first;
	}
	
	number_iterator<T> end(){
		return last;
	}
};

template<typename T>
number_range<T> range(T last)
{
	return number_range<T>(0, last, 1);
}

template<typename T>
number_range<T> rev_range(T last)
{
	return number_range<T>(last-1, -1, -1);
}

template<typename T>
number_range<T> range(T first, T last)
{
	return number_range<T>(first, last, 1);
}

template<typename T>
number_range<T> rev_range(T first, T last)
{
	return number_range<T>(first-1, last-1, -1);
}

template<typename T>
number_range<T> range(T first, T last, T step)
{
	return number_range<T>(first, last, step);
}

template<typename T>
number_range<T> rev_range(T first, T last, T step)
{
	return number_range<T>(first-step, last-step, -step);
}



template<typename T> class id2 : public std::vector<T>
{
	private:
		const int left_shift;

	public:
		
		

		template<typename... Args> id2(const int32 left_shift, Args&&... args):
			std::vector<T>(args...),
			left_shift(left_shift) {}
		
		T& operator[](int n)
		{
			return std::vector<T>::operator[](n-left_shift);
		}
		
		const T& operator[](int32 n) const
		{
			return std::vector<T>::operator[](n-left_shift);
		}
		
		T& at(int32 n) {
			return std::vector<T>::at(n-left_shift);
		}
		
		const T& at(int32 n) const {
			return std::vector<T>::at(n-left_shift);
		}
};



template<class ForwardIterator>
void id1(const ForwardIterator beg, const ForwardIterator end)
{
	if (beg == end)
		return;
	ForwardIterator prev = beg, cur = ++beg;
	while (cur != end)
	{
		*cur += *prev;
		prev = cur++;
	}
}

template<class BidirectionalIterator>
void id4(const BidirectionalIterator beg, const BidirectionalIterator end)
{
	if (beg == end)
		return;
	BidirectionalIterator prev = end, cur = --end;
	while (cur != beg)
	{
		*cur += *prev;
		prev = cur--;
	}
}

template<typename ForwardIterator, typename T>
void id0(
	const ForwardIterator beg,
	const ForwardIterator end,
	size_t num,
	const std::function<size_t(const T&)>lambda=[](const T& val){return val;}
){
	std::vector< std::vector<T> >count(++num);
	for (auto it = beg; it != end; ++it)
	{
		size_t l = lambda(*it);
		dbg_assert(l<num);
		count[l].push_back(*it);
	}
	auto it = beg;
	for (size_t i = 0; i < num; i++)
		for (auto j : count[i])
			*it++ = j;
}

template<typename ForwardIterator>
void id0(
	const ForwardIterator beg,
	const ForwardIterator end
){
	typedef typename std::iterator_traits<ForwardIterator>::value_type T;
	T M=*max_element(beg, end);
	T m=*min_element(beg, end);
	id0(
		beg,
		end,
		M-m,
		std::function<size_t(const T&)>(
			[m](const T& x)
			{
				return x-m;
			}
		)
	);
}

template<typename RAIterator, typename Comp>
vi sort_indices(
	const RAIterator beg,
	const RAIterator end,
	const Comp comp
){
	vi indices(std::distance(beg,end));
	std::iota(indices.begin(), indices.end(), 0);
	std::sort(
		indices.begin(),
		indices.end(),
		[beg,&comp](int x,int y)
		{
			return comp(*(beg+x), *(beg+y));
		}
	);
	return std::move(indices);
}

template<typename RAIterator>
vi sort_indices(
	const RAIterator beg,
	const RAIterator end
){
	typedef typename std::iterator_traits<RAIterator>::value_type T;
	return std::move(sort_indices(
		beg,
		end,
		std::less<T>()
	));
}

template<typename RAIterator, typename T, typename Comp>
vi compress(
	const RAIterator beg,
	const RAIterator end,
	std::vector<T>& inverse_map,
	const Comp comp
){
	if (beg == end)
		return vi();
	vi sorted_indices = sort_indices(beg, end, comp);
	vi res(std::distance(beg, end));
	
	inverse_map.clear();
	res[sorted_indices[0]] = 0;
	inverse_map.push_back(*(beg + sorted_indices[0]));
	for (auto i: range(1u, sorted_indices.size()))
	{
		res[sorted_indices[i]] = res[sorted_indices[i-1]];
		if (comp(*(beg+sorted_indices[i-1]), *(beg+sorted_indices[i])))
		{
			++res[sorted_indices[i]],
			inverse_map.push_back(*(beg+sorted_indices[i]));
		}
	}
	
	copy(beg, end, sorted_indices.begin());
	return std::move(res);
}

template<typename RAIterator, typename T>
vi compress(const RAIterator beg, const RAIterator end, std::vector<T>& inverse_map)
{
	return compress(beg, end, inverse_map, std::less<T>());
}



template<typename T>
T pow(const T& base, uint32 exp){
	if (exp <= 0)
		throw new stringException("call to pow with non-positive exponent");
	
	T mul = base, res = base;
	for (--exp; exp; exp >>= 1)
	{
		if (exp & 1)
			res *= mul;
		mul = (mul * mul);
	}
	
	return std::move(res);
}



vi z_algorithm(std::string s)
{
	int32 n = (int32)s.length();
	std::vector<int32> Z(n);
	
	for (int32 i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i <= r)
			Z[i] = std::min(r-i+1, Z[i-l]);
		while (i + Z[i] < n && s[Z[i]] == s[i+Z[i]])
			++Z[i];
		if (i+Z[i]-1 > r)
			l = i, r = i+Z[i]-1;
	}
	
	return std::move(Z);
}









using namespace std;

const _int MAXN = 100005;
const _int MAXB = 17;

struct id3 {
	mii M;
	vector<bool> value;
	int64 oldval;
	
	id3() {value.resize(MAXN, false); M[-2] = 0; oldval = 0;}
	
	int64 change(int bitpos, bool val) {
		auto it = M.upper_bound(bitpos);
		
		dbg_assert(it != M.begin());
		--it;

		int l  = it->second;
		int sp   = it->first;
		
		if (val == false && value[bitpos] == true) {
			oldval -= int64(l)*int64(l+1)/2;
			
			int id6 = bitpos-sp;
			int id5 = sp+l-1-bitpos;
			
			oldval += int64(id6)*int64(id6+1)/2;
			oldval += int64(id5)*int64(id5+1)/2;
			
			M.erase(it);
			
			if (id6) M[sp] = id6;
			if (id5) M[bitpos+1] = id5;
		}
		
		if (val == true && value[bitpos] == false) {
			
			if (bitpos && value[bitpos-1] == true && value[bitpos+1] == true) {
			
				auto it2 = it;
				it2++;
				int l2 = it2->second;
				it->second += l2+1;
				M.erase(it2);

				oldval -= int64(l)*int64(l+1)/2;				
				oldval -= int64(l2)*int64(l2+1)/2;				
				oldval += int64(l+l2+1)*int64(l+l2+2)/2;
				
			}
			else if (bitpos && value[bitpos-1] == true) {
				oldval -= int64(l)*int64(l+1)/2;
				oldval += int64(l+1)*int64(l+2)/2;
				it->second++;
			}
			else if (value[bitpos+1] == true) {
				
				++it;
				int l2 = it->second;
				oldval -= int64(l2)*int64(l2+1)/2;
				oldval += int64(l2+1)*int64(l2+2)/2;
				M.erase(it);
				M[bitpos] = l2+1;
			}
			else {
				M[bitpos] = 1;
				oldval += 1;
			}
		}
			
		value[bitpos] = val;
		
		dbg_assert(debug());
		
		return oldval;
	}
	
	bool debug() {
		vii chk;
		chk.pb(ii(-2,0));
		
		int last1 = -2;
		
		for (int i: range(MAXN)) {
			if (value[i]) {
				if (last1 == i-1) {
					++chk[chk.size()-1].second;
				} else {
					chk.pb(ii(i,1));
				}
				
				last1 = i;
			}
		}
		
		int64 exp_ans = 0;
		for (ii x: chk)
			exp_ans += x.second * (x.second+1)/2;
		
		

		vii chk2(M.begin(), M.end());
		
		bool res = (chk == chk2 && exp_ans == oldval);
		if (!res) {
			cout << "value:    " << value << endl;
			cout << "real:     " << chk2 << endl;
			cout << "expected: " << chk << endl;
			cout << endl;
			cout << "real ans: " << oldval << endl;
			cout << "exp. ans: " << exp_ans << endl;
		}
			
		return res;
	}
} bits[MAXB];



_int main() {
	int N, M;
	
	cin >> N >> M;
	
	for (int i: range(N)) {
		int v; cin >> v;
		
		for (int b: range(MAXB))
			if (v&(1<<b))
				bits[b].change(i,1);
	}
	
	for (int i: range(M)) {
		int p, v; cin >> p >> v;
		--p;
		
		int64 ans = 0;
		for (int b: range(MAXB)) {
			if (v&(1<<b))
				ans += int64(1<<b) * bits[b].change(p,1);
			else
				ans += int64(1<<b) * bits[b].change(p,0);
		}
		
		cout << ans << endl;		
	}
	return 0;
}
