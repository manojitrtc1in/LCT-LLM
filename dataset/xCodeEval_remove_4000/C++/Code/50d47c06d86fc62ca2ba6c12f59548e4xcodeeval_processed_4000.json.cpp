


























using ll = long long int;
using ull = unsigned long long int;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pi = std::pair<int, int>;
using vpi = std::vector<pi>;
using vvpi = std::vector<vpi>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using vvpll = std::vector<vpll>;





template<typename T> void mk_unique(std::vector<T>& l) { if (!std::is_sorted(all(l))) std::sort(all(l)); auto it = std::unique(l.begin(), l.end()); auto d = std::distance(l.begin(), it); l.resize(d); }
template<typename T> T &smax(T& l, const T&r) { if(l<r) l=r; return l; }
template<typename T> T &smin(T& l, const T&r) { if(r < l) l=r; return l; }
constexpr int MOD = 1000000007;

template<typename T>bool array_equal(const std::vector<T> &a, const std::vector<T> &b){
    if(a.size() != b.size())return false;
    return std::equal(all(a), b.begin());
}
template<typename T>bool array_equal(const std::vector<std::vector<T>> &a, const std::vector<std::vector<T>> &b){
    if(a.size() != b.size())return false;
    for(int i = 0 ; i < a.size(); i++) if(!array_equal(a[i], b[i])) return false;
    return true;
}
template<class Fun>
class id21 {
    Fun fun_;
public:
    template<class T>
    explicit id21(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) id10(Fun &&fun) {
    return id21<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

namespace io{class input_reader{
void throw_error(){throw std::runtime_error("No more inputs while reading number");}
template<typename T>inline void id14(T&f){bool positive=true;f=0;char c;
if(!in.get(c))throw_error();
while(c<'0'||c>'9'){if(c=='-')positive=false;if(!in.get(c))throw_error();}
while(c>='0'&&c<='9'){f=(f<<3)+(f<<1)+(c&15);if(!in.get(c))break;}
if(!positive)f*=-1;}
public:
std::istream&in;
explicit input_reader(std::istream&in):in(in){}
inline void read(int&f){id14(f);}
inline void read(short&f){id14(f);}
inline void read(long int&f){id14(f);}
inline void read(long long int&f){id14(f);}
inline void read(unsigned int&f){id14(f);}
inline void read(unsigned short&f){id14(f);}
inline void read(unsigned long int&f){id14(f);}
inline void read(unsigned long long int&f){id14(f);}
template<typename T>inline void read(std::vector<T>&f){for(auto&i:f)read(i);}
template<typename T,int N>inline void read(std::array<T,N>&res){for(auto&i:res)read(i);}
template<typename T1,typename T2>inline void read(std::pair<T1,T2>&p){read(p.first,p.second);}
template<typename T>inline void read(T&f){in>>f;}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t),read(args...);}
template<typename T>inline void readArray(int n,T*res){while(n--)read(*(res++));}
template<typename T>inline input_reader&operator>>(T&t){return read(t),*this;}
};}
namespace io{class output_writer{
std::ostream&out;
template<typename T>inline void id19(T x){if(x>=10)id19(x/10);out.put(x%10+48);}
template<typename T>inline void printInteger(T x){if(x<0)out.put('-'),x=-x;id19(x);}
template<typename T>inline void printArray(T&ar,char sep=' '){int c=0;for(auto&t:ar){if(c++){print(sep);}print(t);}}
public:
explicit output_writer(std::ostream&out):out(out){}
inline void flush(){out.flush();}
inline void print(){}
inline void print(char x){out.put(x);}
inline void print(short x){printInteger(x);}
inline void print(int x){printInteger(x);}
inline void print(long int x){printInteger(x);}
inline void print(long long int x){printInteger(x);}
inline void print(unsigned short x){printInteger(x);}
inline void print(unsigned int x){printInteger(x);}
inline void print(unsigned long int x){printInteger(x);}
inline void print(unsigned long long int x){printInteger(x);}
template<typename T1>inline void print(const T1&t1){out<<t1;}
template<typename T1,typename T2>inline void print(const std::pair<T1,T2>&t1){print(t1.first,' ',t1.second);}
template<typename T1>inline void print(const std::vector<T1>&t1){printArray(t1);}
template<typename T1,std::size_t N>inline void print(const std::array<T1,N>&t1){printArray(t1);}
template<typename T1,std::size_t N,std::size_t M>inline void print(const std::array<std::array<T1,M>,N>&t1){printArray(t1,'\n');}
template<typename T1>inline void print(const std::vector<std::vector<T1>>&t1){printArray(t1,'\n');}
template<typename T,typename...Args>inline void print(const T&t,const Args&...args){print(t),print(args...);}
template<typename...Args>inline void println(const Args&...args){print(args...),print('\n');}
template<typename T>output_writer&operator<<(const T&t){return print(t),*this;}
};}
inline ll pow_mod(ll a,ll b,const ll MOD){ll res=1;for(ll i=1;b;b^=b&i,i<<=1,a=(a*a)%MOD)if(b&i)res=(res*a)%MOD;return res;}
inline ll mod_inv(const ll a,const ll MOD){return pow_mod(a,MOD-2,MOD);}
template<typename T>inline T gcd(T a,T b){T t;while(a!=0)t=a,a=b%a,b=t;return b;}
template<typename T>T lcm(const T &a,const T &b) {assert(a!=0&&b!=0);return a/gcd(a,b)*b;}
namespace math {
template<class T> int gMOD(T v){int res = (int)(v%MOD);if(res>=0) return res; return res + MOD;};
class mod_int{
using mi=mod_int;
int v;
public:
mod_int(int v):v(gMOD(v)){}
mod_int(unsigned int v):v(gMOD(v)){}
mod_int(long long int v):v(gMOD(v)){}
mod_int(unsigned long long int v):v(gMOD(v)){}
mod_int(long int v):v(gMOD(v)){}
mod_int(unsigned long int v):v(gMOD(v)){}
mod_int()=default;
mod_int(const mi& o)=default;
mod_int(mi&& o)=default;
inline mi& operator=(const mi& o)=default;
inline mi& operator=(mi&& o)=default;
inline mi& operator++(){if(v==MOD-1)v=0;else v++;return*this;}
inline mi& operator--(){if(v==0)v=MOD-1;else v--;return*this;}
inline mi operator++(int){mi t=*this;++(*this);return t;}
inline mi operator--(int){mi t=*this;--(*this);return t;}
inline bool friend operator==(const mi&lhs,const mi&rhs){return lhs.v==rhs.v;}
inline bool friend operator!=(const mi&lhs,const mi&rhs){return lhs.v!=rhs.v;}
template<typename T> inline bool friend operator==(const mi&lhs,const T&rhs){return lhs==mi(rhs);}
template<typename T> inline bool friend operator!=(const mi&lhs,const T&rhs){return lhs!=mi(rhs);}
inline mi friend operator-(const mi&lhs,const mi&rhs){mi res;res.v=lhs.v-rhs.v;if(res.v<0)res.v+=MOD;return res;}
inline mi friend operator+(const mi&lhs,const mi&rhs){mi res;res.v=lhs.v+rhs.v-MOD;if(res.v<0)res.v+=MOD;return res;}
inline mi friend operator*(const mi&lhs,const mi&rhs){return{((((long long int)lhs.v)*rhs.v))};}
inline mi friend operator/(const mi&lhs,const mi&rhs){return lhs*rhs.inv();}
template <typename T> inline mi friend operator-(const mi&lhs,const T&rhs){return lhs-mi(rhs);}
template <typename T> inline mi friend operator+(const mi&lhs,const T&rhs){return lhs+mi(rhs);}
template <typename T> inline mi friend operator*(const mi&lhs,const T&rhs){return lhs*mi(rhs);}
template <typename T> inline mi friend operator/(const mi&lhs,const T&rhs){return lhs/mi(rhs);}
template <typename T> inline mi& operator-=(const T&rhs){return*this=*this-rhs;}
template <typename T> inline mi& operator+=(const T&rhs){return*this=*this+rhs;}
template <typename T> inline mi& operator*=(const T&rhs){return*this=*this*rhs;}
template <typename T> inline mi& operator/=(const T&rhs){return*this=*this/rhs;}
inline mi inv()const{return pow(MOD-2);}
inline mi pow(long long int pw)const{mi res=1,val=*this;while(pw){if(pw&1)res*=val;val*=val;pw>>=1;}return res;}
inline operator int()const {return v;}
inline friend std::istream& operator>>(std::istream& in,mi&rhs){long long int v;in>>v;rhs={v};return in;}
inline friend std::ostream& operator<<(std::ostream& out,mi&rhs){out<<rhs.v;return out;}
};}
namespace math{
mod_int factorial(int n) {
static std::vector<mod_int>mem;static mod_int last;
if (mem.empty())last={1},mem.push_back(last);
while (n>=(int)mem.size())mem.push_back(mem.back()*last++);
return mem[n];}

mod_int id9(int n, int k){return factorial(n)/(factorial(k)*factorial(n-k));}
}
const double PI = 3.14159265358979323846264338327950288419716939937510;
std::mt19937 id25(){return std::mt19937(std::random_device()());}
template<typename T=int>T myrand(T high = std::numeric_limits<T>::max()) {assert(high > 0);
static std::mt19937 random_engine = id25();
return std::uniform_int_distribution<T>(0, high - 1)(random_engine);}
bool randbool(){return myrand(2);}











namespace hashes {
	class hashed_string {
	public:
		const int length;
	private:
		static std::vector<long long> MODS;
		static constexpr int by = 256;
		std::vector<std::shared_ptr<std::vector<long long>>> id23;
		const int shift;

		static long long pow_mod(long long a, long long b, long long MOD) {
			if (b == 0) return 1;
			if (b == 1) return a;
			long long side = 1;
			while (b != 1) {
				if (1 & b) side = side * a % MOD;
				a = a * a % MOD;
				b >>= 1;
			}
			return a * side % MOD;
		}

		long long get_hash(int i) const {
			long long res = (*id23[i])[shift + length];
			if (shift != 0) {
				long long id20 = (*id23[i])[shift] * pow_mod(by, length, MODS[i]) % MODS[i];
				res -= id20;
				if (res < 0) res += MODS[i];
			}
			return res;
		}

		hashed_string(std::vector<std::shared_ptr<std::vector<long long int>>> id23, int pos, int n) :
				length(n), id23(id23), shift(pos){}

		static bool id22;

		static inline int min(int a, int b) { return a < b ? a : b; }

	public:
		hashed_string(std::string &s, int id16 = 2) : length(s.size()), shift(0) {
			if (!id22)
				id22 = true, std::shuffle(MODS.begin(), MODS.end(), std::default_random_engine(0));
			id23.reserve(id16);
			for (int i = 0; i < id16; ++i) {
				id23.push_back(std::make_shared<std::vector<long long>>(length + 1));
				auto &hs = *(id23[i]);
				for (int j = 0; j < length; j++) hs[j + 1] = (hs[j] * by + s[j]) % MODS[i];
			}
		}

		hashed_string substr(int pos, int n = -1) const {
			if (n == -1) n = length - pos;
			return hashed_string(id23, pos + shift, n);
		}

		bool operator==(const hashed_string &lhs) const {
			if (length != lhs.length) return false;
			int id2 = min(id23.size(), lhs.id23.size());
			for (int i = 0; i < id2; ++i)
				if (get_hash(i) != lhs.get_hash(i)) return false;
			return true;
		}

		bool operator!=(const hashed_string &lhs) const {
			return !(*this == lhs);
		}
	};

	bool hashed_string::id22 = false;
	std::vector<long long> hashed_string::MODS = {
			1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
			1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297,
			1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427, 1000000433,
			1000000439, 1000000447, 1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
			1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753, 1000000787, 1000000801,
			1000000829, 1000000861, 1000000871, 1000000891, 1000000901, 1000000919, 1000000931, 1000000933,
			1000000993, 1000001011, 1000001021, 1000001053, 1000001087, 1000001099, 1000001137, 1000001161,
			1000001203, 1000001213, 1000001237, 1000001263, 1000001269, 1000001273, 1000001279, 1000001311,
			1000001329, 1000001333, 1000001351, 1000001371, 1000001393, 1000001413, 1000001447, 1000001449,
			1000001491, 1000001501, 1000001531, 1000001537, 1000001539, 1000001581, 1000001617, 1000001621,
			1000001633, 1000001647, 1000001663, 1000001677, 1000001699, 1000001759, 1000001773, 1000001789,
			1000001791, 1000001801, 1000001803, 1000001819, 1000001857, 1000001887, 1000001917, 1000001927,
			1000001957, 1000001963, 1000001969, 1000002043, 1000002089, 1000002103, 1000002139, 1000002149,
			1000002161, 1000002173, 1000002187, 1000002193, 1000002233, 1000002239, 1000002277, 1000002307,
			1000002359, 1000002361, 1000002431, 1000002449, 1000002457, 1000002499, 1000002571, 1000002581,
			1000002607, 1000002631, 1000002637, 1000002649, 1000002667, 1000002727, 1000002791, 1000002803,
			1000002821, 1000002823, 1000002827, 1000002907, 1000002937, 1000002989, 1000003009, 1000003013,
			1000003051, 1000003057, 1000003097, 1000003111, 1000003133, 1000003153, 1000003157, 1000003163,
			1000003211, 1000003241, 1000003247, 1000003253, 1000003267, 1000003271, 1000003273, 1000003283,
			1000003309, 1000003337, 1000003351, 1000003357, 1000003373, 1000003379, 1000003397, 1000003469,
			1000003471, 1000003513, 1000003519, 1000003559, 1000003577, 1000003579, 1000003601, 1000003621,
			1000003643, 1000003651, 1000003663, 1000003679, 1000003709, 1000003747, 1000003751, 1000003769,
			1000003777, 1000003787, 1000003793, 1000003843, 1000003853, 1000003871, 1000003889, 1000003891,
			1000003909, 1000003919, 1000003931, 1000003951, 1000003957, 1000003967, 1000003987, 1000003999,
			1000004023, 1000004059, 1000004099, 1000004119, 1000004123, 1000004207, 1000004233, 1000004249
	};
}











namespace range_update {

	
	template<typename T, typename Operator>
	class ranges_array {
		struct T_in_use {
			T t;
			bool in_use = false;
		};
		const Operator op;
		mutable std::vector<T_in_use> vec;
		const int n;

		void update_index(int index, const T &val) const {
			if (vec[index].in_use) {
				vec[index].t = op(vec[index].t, val);
			} else vec[index].t = val;
			vec[index].in_use = true;
		}

		void update_index_down(int index) const {
			if (vec[index].in_use) {
				update_index(index * 2, vec[index].t);
				update_index(index * 2 + 1, vec[index].t);
				vec[index].in_use = false;
			}
		}

		void update_range(int index, int index_l, int index_r, int l, int r, const T &val) {
			if (l == index_l && r == index_r) {
				update_index(index, val);
			} else {
				update_index_down(index);
				int index_m = (index_l + index_r) / 2;
				if (l <= index_m)
					update_range(index * 2, index_l, index_m, l, std::min(r, index_m), val);
				if (r > index_m)
					update_range(index * 2 + 1, index_m + 1, index_r, std::max(l, index_m + 1), r, val);
			}
		}


		static size_t calc_vec_size(int index, int l, int r) {
			if (l == r) return (size_t) index + 1;
			auto res = std::max(calc_vec_size(index * 2, l, (l + r) / 2),
								calc_vec_size(index * 2 + 1, 1 + (l + r) / 2, r));
			return res;
		}

		void set_values(const std::vector<T> &v, int index, int l, int r) {
			if (l == r)
				vec[index] = {v[l], true};
			else {
				set_values(v, index * 2, l, (l + r) / 2);
				set_values(v, index * 2 + 1, 1 + (l + r) / 2, r);
			}
		}

	public:

		ranges_array(int n, Operator op) : n(n), op(op), vec(calc_vec_size(1, 0, n - 1)) {}

		explicit ranges_array(int n) : ranges_array(n, Operator()) {}

		ranges_array(const std::vector<T> &v, Operator op) : ranges_array(v.size(), op) {
			set_values(v, 1, 0, n - 1);
		}

		explicit ranges_array(const std::vector<T> &v) : ranges_array(v, Operator()) {}

		void update_range(int l, int r, const T &val) {
			assert(l <= r);
			update_range(1, 0, n - 1, l, r, val);
		}





























		T operator[](int i) const {
			int index = 1;
			int l1 = 0;
			int r1 = n - 1;
			while (i != l1 || i != r1) {
				update_index_down(index);
				int m = (l1 + r1) / 2;
				if (i <= m)
					index *= 2, r1 = m;
				else
					index = index * 2 + 1, l1 = m + 1;
			}
			return vec[index].t;
		}
	};

	template<typename T>
	class id3 : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit id3(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return u + v; }) {}

		explicit id3(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return u + v; }) {}

		explicit id3(int n, const T &val) : id3(std::vector<T>(n, val)) {}
	};


	template<typename T>
	class id6 : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit id6(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return v; }) {}

		explicit id6(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return v; }) {}

		explicit id6(int n, const T &val) : id6(std::vector<T>(n, val)) {}
	};
}





namespace range_query {


	

	

	

	

	

	template<typename T, typename Operator, bool id8 = false>
	class id1 {
		const Operator op;
		std::vector<std::vector<T>> vec;

		static int largest_bit(int x) { return 31 - __builtin_clz(x); }

	public:
		id1(std::vector<T> v, Operator op) : op(op) {
			vec.push_back(v);
			const int n = v.size();
			int id7 = 1;
			while (id7 * 2 <= n) {
				for (int i = 0; i + id7 * 2 <= n; ++i) {
					v[i] = op(v[i], v[i + id7]);
				}
				id7 <<= 1;
				vec.emplace_back(v.begin(), v.begin() + (n - id7) + 1);
			}
		}

		explicit id1(const std::vector<T> &v) : id1(v, Operator()) {}

		T query(int l, int r) const {
			assert(l <= r);
			if (!id8) {
				int len = r - l + 1;
				int level = 0;
				while ((1 << (level + 1)) <= len) level++;
				int level_window = 1 << level;
				r = r - level_window + 1;
				return op(vec[level][l], vec[level][r]);
			} else {
				int dif = r - l + 1;
				int i = largest_bit(dif);
				T res = vec[i][l];
				l += 1 << i;
				dif -= 1 << i;
				i = largest_bit(dif);
				for (; dif; i = largest_bit(dif)) {
					res = op(res, vec[i][l]);
					l += 1 << i;
					dif -= 1 << i;
				}
				return res;
			}
		}
	};


	template<typename T, typename Comparator = std::less<T>>
	class id17 : public id1<T, std::function<T(T, T)>> {
	public:
		id17(const std::vector<T> &v, Comparator comp) :
				id1<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? u : v;
				}) {}

		explicit id17(const std::vector<T> &v)
				: id17(v, Comparator()) {}
	};


	template<typename T, typename Comparator = std::less<T>>
	class id0 : public id1<T, std::function<T(T, T)>> {
	public:
		id0(const std::vector<T> &v, Comparator comp) :
				id1<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? v : u;
				}) {}

		explicit id0(const std::vector<T> &v)
				: id0(v, Comparator()) {}
	};

	template<typename T>
	class id24 : public id1<T, std::function<T(T, T)>, true> {
	public:
		explicit id24(const std::vector<T> &v) :
				id1<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) {
					return v + u;
				}) {}
	};
}




namespace range_query {

template<typename T, typename Operator = std::function<T(const T &, const T &)>>
class ranges_array {
const int n{};const Operator op;std::vector<T> vec;

void update_up_range(int l, int r) { int range=(vec.size()-1)<<1;
while (l>>=1,r>>=1,range>>=1,l) {for(int i=l;i<=r;++i){ vec[i]=vec[i*2]; if(i*2<range)vec[i]=op(vec[i],vec[i*2+1]);}}}

void update_up(int i) {int range=(vec.size()-1)<<1;
while (i>>=1,range>>=1,i) {T new_v=vec[i*2]; if(i*2<range)new_v=op(new_v,vec[i*2+1]);
if(vec[i]==new_v){return;}vec[i]=new_v;}}

public:
ranges_array(const std::vector<T> &v, Operator op) : n(v.size()), op(op), vec(v.size()*2+1) {
std::copy(v.begin(), v.end(), vec.begin() + n + 1); update_up_range(vec.size() - n, vec.size() - 1);}

explicit ranges_array(const std::vector<T> &v) : ranges_array(v, Operator()) {}
ranges_array(int n, Operator op) : n(n), op(op), vec(n*2+1) {}
explicit ranges_array(int n) : ranges_array(n, Operator()) {}

T query(int l, int r) const {


assert(0 <= l && l < n && 0 <= r && r < n && l <= r);
T res; bool first = true;l += n + 1, r += n + 1; if (l == r) return vec[l];
auto update_res = [&](const T &t1) {res = first ? t1 : op(res, t1);first = false;};
do{if ((l & 1) == 1) update_res(vec[l++]);if ((r & 1) == 0) update_res(vec[r--]);} while(l>>=1, r>>=1, l<r);
if (l == r) update_res(vec[l]);
return res;
}

T query() { return query(0, n - 1); }


class id13 {T t;ranges_array &rq;const int index;
public:
id13(ranges_array &rq, const int index):t(rq.vec[index]), rq(rq), index(index) {}
id13&operator=(const T&val){t=val;rq.vec[index]=val;rq.update_up(index);return *this;}
operator T() const { return t; }
};

id13 operator[](int index) { return id13(*this, n+1+index); }
};

template<typename T, typename Comparator>struct get_min : public std::binary_function<T, T, T> {Comparator cmp;
get_min() = default;
explicit get_min(Comparator cmp) : cmp(cmp) {}
T operator()(const T &__x, const T &__y) const { return cmp(__x, __y) ? __x : __y; }
};

template<typename T>struct get_sum : public std::binary_function<T, T, T> {
T operator()(const T &__x, const T &__y) const { return __x + __y; }
};

template<typename T, typename Comparator = std::less<T>>struct id18 : public ranges_array<T, get_min<T, Comparator>> {
using ranges_array_ = ranges_array<T, get_min<T, Comparator>>;
id18(const std::vector<T> &v, Comparator cmp) : ranges_array_(v, get_min<T, Comparator>(cmp)) {}
explicit id18(const std::vector<T> &v) : ranges_array_(v) {}
id18(int n, Comparator cmp) : ranges_array_(n, get_min<T, Comparator>(cmp)) {}
explicit id18(int n) : ranges_array_(n) {}
};

template<typename T>struct id12 : public ranges_array<T, get_sum<T>> {
using ranges_array_ = ranges_array<T, get_sum<T>>;
explicit id12(const std::vector<T> &v) : ranges_array_(v) {}
explicit id12(int n) : ranges_array_(n) {}
};
}




namespace range_query {

    template<typename K, typename T, typename Operator = std::function<T(const T &, const T &)>>
    class id5 {
        const Operator op;

        class Node {
            const K l, r;
            T val;
            Node *left, *right;
        public:
            Node(K l, K r) : l(l), r(r), val(), left(nullptr), right(nullptr) {}

            ~Node() {
                if (left) delete left;
                if (right)delete right;
            }

            void set(const K i, const T v, const Operator &op) {
                const K m = (l + r) / 2;
                if (l == r) val = v;
                else {
                    if (i <= m) {
                        if (left == nullptr) left = new Node(l, m);
                        left->set(i, v, op);
                    } else {
                        if (right == nullptr) right = new Node(m + 1, r);
                        right->set(i, v, op);
                    }
                    update(op);
                }
            }

            void update(const Operator &op) {
                if (left == nullptr) {
                    if (right != nullptr) {
                        val = right->val;
                    }
                } else {
                    if (right == nullptr) val = left->val;
                    else val = op(left->val, right->val);
                }
            }

            T get(K l1, K r1, const Operator &op) const {
                if (l1 < l) l1 = l;
                if (r1 > r) r1 = r;
                if (l1 == l && r1 == r) return val;
                const K m = (l + r) / 2;
                bool left_ok = l1 <= m && left != nullptr;
                bool right_ok = r1 > m && right != nullptr;
                if (left_ok && right_ok) return op(left->get(l1, r1, op), right->get(l1, r1, op));
                if (left_ok) return left->get(l1, r1, op);
                if (right_ok) return right->get(l1, r1, op);
                else return T();
            }
        };

        Node root;

    public:
        id5(K l, K r, Operator op) : root(l, r), op(op) {}

        explicit id5(K l, K r) : id5(l, r, Operator()) {}

        class id13 {
            id5<K, T, Operator> &rq;
            const K index;
        public:
            id13(id5<K, T, Operator> &rq, const K index) : rq(rq), index(index) {}

            id13 &operator=(const T &val) {
                rq.root.set(index, val, rq.op);
                return *this;
            }
        };

        id13 operator[](const K index) {
            return id13(*this, index);
        }

        const T &operator[](const K index) const {
            return root.get(index, index, op);
        }

        T query(K l, K r) const {
            assert(l <= r);
            return root.get(l, r, op);
        }

        T query() {
            return root.val;
        }
    };


    template<typename K, typename T, typename Comparator = std::less<T>>
    class id11 : public id5<K, T, std::function<T(T, T)>> {
    public:
        id11(K l, K r, Comparator comp) :
                id5<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? u : v;
                }) {}

        explicit id11(K l, K r)
                : id11(l, r, Comparator()) {}
    };

    template<typename K, typename T, typename Comparator = std::less<T>>
    class id15 : public id5<K, T, std::function<T(T, T)>> {
    public:
        id15(const K l, const K r, Comparator comp) :
                id5<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? v : u;
                }) {}

        explicit id15(const std::vector<T> &v)
                : id15(v, Comparator()) {}
    };

    template<typename K, typename T>
    class id4 : public id5<K, T, std::function<T(T, T)>> {
    public:
        explicit id4(const K l, const K r) :
                id5<K, T, std::function<T(T, T)>>(l, r, [](const T &u, const T &v) {
                    return v + u;
                }) {}
    };
}



namespace range_query {
using namespace std;

template<typename T>
class fenwick {
int n;std::vector<T> arr;std::vector<T> origin;
public:
explicit fenwick(int n) : n(n), arr(n + 1), origin(n + 1) {}
explicit fenwick(const std::vector<T> &v) : fenwick(v.size()) { for (int i = 0; i < n; ++i) add(v[i], i + 1); }
void add(T diff, int i) {i++;origin[i] += diff;for(;i<=n;i+=(i) & (-i)) arr[i] += diff;}


T query(int i) const
{i++;T ans;bool first = true;for(;i<=n;i+=(i) & (-i)){T v = arr[i];ans = first ? v : ans + v;first=false;}return ans;}

T get(int i) const {i++;return origin[i];}
void set(T val, int i) {add(val - get(i), i);}
size_t size() { return n; }

int lower_bound(T val) {
int i = 1;
while (i * 2 <= n) i <<= 1;

while (i != 0 && arr[i - 1] >= val) i >>= 1;
if (i == 0) return i;

T sum = arr[i - 1];
for (int ind = i >> 1; ind != 0; ind >>= 1) {
if (i + ind > n) continue;
if (sum + arr[i + ind - 1] < val) {
i += ind;
sum += arr[i - 1];
}
}
return i;
}
};
}


namespace xor_helpers {
    template<typename T>
    struct base {
        base() = default;
        explicit base(const std::vector<T>& arr):base(){ for(T t:arr) push_back(t); }

        std::vector<T> values;
        void push_back(T t){
            for(auto b : values){
                t = std::min(t, t^b);
                if(t==0) return;
            }
            values.push_back(t);
        }

        base& operator+=(T t){push_back(t); return *this;}
        base operator+(T t){base<T> b = *this; b+=t; return b;}

        int size() const { return values.size(); }
        friend bool operator==(const base<T> &lhs, const base<T> &rhs) { return bases_equal(lhs, rhs); }
        friend bool operator!=(const base<T> &lhs, const base<T> &rhs) { return !(lhs == rhs); }
        explicit operator const std::vector<T> &() const { return values; }
        explicit operator std::vector<T>() const { return values; }
    };

    template<typename T>
    bool bases_equal(const base<T> &base1, const base<T> &base2) {
        if (base1.size() != base2.size()) return false;
        for (T t : base1.values) {
            for (const T t2: base2.values) {
                t = std::min(t, t ^ t2);
                if (t == 0) break;
            }
            if (t != 0) return false;
        }
        return true;
    }


}



using mi = math::mod_int;
using vmi = std::vector<mi>;
using vvmi = std::vector<std::vector<mi>>;

using namespace std;

class FOmkarAndLandslide {
    class Solver {
    public:
        io::input_reader in;
        io::output_writer out;

        Solver(std::istream &in, std::ostream &out) : in(in), out(out) {}

        void solve() {
            

            int n;
            ll last;
            in >> n;
            vll h(n);
            deque<int> eqs;
            in >> h;
            last = h[0];
            rep(i, 1, n - 1) {
                ll d = h[i] - last;
                while (d >= 2) {
                    if (!eqs.empty()) {
                        int last_eq = eqs.back();
                        eqs.pop_back();
                        int cost = i - last_eq + 1;
                        if (d - cost >= 0) {
                            d -= cost;
                            last += 1;
                        } else {
                            

                            eqs.pb(last_eq + d - 1);
                            d = 1;
                        }
                    } else {
                        ll reps = d / (i + 1);
                        d -= reps * (i + 1);
                        last += reps;
                        if (d >= 2) {
                            eqs.pb(1), d--;
                        }
                    }
                }
                if (!d) eqs.pb(i);
                last += d;
            }
            h[n - 1] = last;
            repr(i, n - 2, 0) {
                if (eqs.empty() || eqs.back() - 1 < i) h[i] = h[i + 1] - 1;
                else h[i] = h[i + 1], eqs.pop_back();
            }


            

            out.println(h);
        }
    };

public:
    static void solve(std::istream &in, std::ostream &out) {
        Solver(in, out).solve();
    }
};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	FOmkarAndLandslide solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
