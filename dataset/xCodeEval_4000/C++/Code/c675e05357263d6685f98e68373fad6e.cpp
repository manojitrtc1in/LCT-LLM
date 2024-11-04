

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cstdint>
#include <cassert>

#include <tuple>
#include <cmath>
#include <random>

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
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, s, e) for(int i = (int)(s); i <= (int)(e); ++i)
#define repr(i, s, e) for(int i = (int)(s); i >= (int)(e); --i)
#define pb push_back
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
namespace io{class input_reader{
void throw_error(){throw std::runtime_error("No more inputs while reading number");}
template<typename T>inline void readIntegerValue(T&f){bool positive=true;f=0;char c;
if(!in.get(c))throw_error();
while(c<'0'||c>'9'){if(c=='-')positive=false;if(!in.get(c))throw_error();}
while(c>='0'&&c<='9'){f=(f<<3)+(f<<1)+(c&15);if(!in.get(c))break;}
if(!positive)f*=-1;}
public:
std::istream&in;
explicit input_reader(std::istream&in):in(in){}
inline void read(int&f){readIntegerValue(f);}
inline void read(short&f){readIntegerValue(f);}
inline void read(long int&f){readIntegerValue(f);}
inline void read(long long int&f){readIntegerValue(f);}
inline void read(unsigned int&f){readIntegerValue(f);}
inline void read(unsigned short&f){readIntegerValue(f);}
inline void read(unsigned long int&f){readIntegerValue(f);}
inline void read(unsigned long long int&f){readIntegerValue(f);}
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
template<typename T>inline void printIntegerHelper(T x){if(x>=10)printIntegerHelper(x/10);out.put(x%10+48);}
template<typename T>inline void printInteger(T x){if(x<0)out.put('-'),x=-x;printIntegerHelper(x);}
template<typename T>inline void printArray(T&ar){bool first=true;for(auto&t:ar)print((first)? first=false,"":" ",t);}
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
template<typename T1,typename T2>inline void print(const std::pair<T1,T2>&t1){println(t1.first,' ',t1.second);}
template<typename T1>inline void print(const std::vector<T1>&t1){printArray(t1);}
template<typename T1,int N>inline void print(const std::array<T1,N>&t1){printArray(t1);}
template<typename T1,int N,int M>inline void print(const std::array<std::array<T1,M>,N>&t1){for(auto&t:t1)println(t);}
template<typename T1>inline void print(const std::vector<std::vector<T1>>&t1){bool first=true;for(auto&t:t1)print((first)? first=false,"":"\n",t);}
template<typename T,typename...Args>inline void print(const T&t,Args...args){print(t),print(args...);}
template<typename...Args>inline void println(Args...args){print(args...),print('\n');}
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

mod_int n_choose_k(int n, int k){return factorial(n)/(factorial(k)*factorial(n-k));}
}
const double PI = 3.14159265358979323846264338327950288419716939937510;
std::mt19937 get_random_engine(){return std::mt19937(std::random_device()());}
template<typename T=int>T myrand(T high = std::numeric_limits<T>::max()) {assert(high > 0);
static std::mt19937 random_engine = get_random_engine();
return std::uniform_int_distribution<T>(0, high - 1)(random_engine);}


















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
	class sum_range_update : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit sum_range_update(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return u + v; }) {}

		explicit sum_range_update(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return u + v; }) {}

		explicit sum_range_update(int n, const T &val) : sum_range_update(std::vector<T>(n, val)) {}
	};


	template<typename T>
	class set_range_update : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit set_range_update(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return v; }) {}

		explicit set_range_update(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return v; }) {}

		explicit set_range_update(int n, const T &val) : set_range_update(std::vector<T>(n, val)) {}
	};
}





namespace range_query {


	

	

	

	

	

	template<typename T, typename Operator, bool REPEAT_MATTER = false>
	class sparse_table {
		const Operator op;
		std::vector<std::vector<T>> vec;

		static int largest_bit(int x) { return 31 - __builtin_clz(x); }

	public:
		sparse_table(std::vector<T> v, Operator op) : op(op) {
			vec.push_back(v);
			const int n = v.size();
			int currentLevelWindow = 1;
			while (currentLevelWindow * 2 <= n) {
				for (int i = 0; i + currentLevelWindow * 2 <= n; ++i) {
					v[i] = op(v[i], v[i + currentLevelWindow]);
				}
				currentLevelWindow <<= 1;
				vec.emplace_back(v.begin(), v.begin() + (n - currentLevelWindow) + 1);
			}
		}

		explicit sparse_table(const std::vector<T> &v) : sparse_table(v, Operator()) {}

		T query(int l, int r) const {
			assert(l <= r);
			if (!REPEAT_MATTER) {
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
	class static_min_range_query : public sparse_table<T, std::function<T(T, T)>> {
	public:
		static_min_range_query(const std::vector<T> &v, Comparator comp) :
				sparse_table<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? u : v;
				}) {}

		explicit static_min_range_query(const std::vector<T> &v)
				: static_min_range_query(v, Comparator()) {}
	};


	template<typename T, typename Comparator = std::less<T>>
	class static_max_range_query : public sparse_table<T, std::function<T(T, T)>> {
	public:
		static_max_range_query(const std::vector<T> &v, Comparator comp) :
				sparse_table<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? v : u;
				}) {}

		explicit static_max_range_query(const std::vector<T> &v)
				: static_max_range_query(v, Comparator()) {}
	};

	template<typename T>
	class static_sum_range_query : public sparse_table<T, std::function<T(T, T)>> {
	public:
		explicit static_sum_range_query(const std::vector<T> &v) :
				sparse_table<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) {
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


class updatable_instance {T t;ranges_array &rq;const int index;
public:
updatable_instance(ranges_array &rq, const int index):t(rq.vec[index]), rq(rq), index(index) {}
updatable_instance&operator=(const T&val){t=val;rq.vec[index]=val;rq.update_up(index);return *this;}
operator T() const { return t; }
};

updatable_instance operator[](int index) { return updatable_instance(*this, n+1+index); }
};

template<typename T, typename Comparator>struct get_min : public std::binary_function<T, T, T> {Comparator cmp;
get_min() = default;
explicit get_min(Comparator cmp) : cmp(cmp) {}
T operator()(const T &__x, const T &__y) const { return cmp(__x, __y) ? __x : __y; }
};

template<typename T>struct get_sum : public std::binary_function<T, T, T> {
T operator()(const T &__x, const T &__y) const { return __x + __y; }
};

template<typename T, typename Comparator = std::less<T>>struct min_range_query : public ranges_array<T, get_min<T, Comparator>> {
using ranges_array_ = ranges_array<T, get_min<T, Comparator>>;
min_range_query(const std::vector<T> &v, Comparator cmp) : ranges_array_(v, get_min<T, Comparator>(cmp)) {}
explicit min_range_query(const std::vector<T> &v) : ranges_array_(v) {}
min_range_query(int n, Comparator cmp) : ranges_array_(n, get_min<T, Comparator>(cmp)) {}
explicit min_range_query(int n) : ranges_array_(n) {}
};

template<typename T>struct sum_range_query : public ranges_array<T, get_sum<T>> {
using ranges_array_ = ranges_array<T, get_sum<T>>;
explicit sum_range_query(const std::vector<T> &v) : ranges_array_(v) {}
explicit sum_range_query(int n) : ranges_array_(n) {}
};
}




namespace range_query {

    template<typename K, typename T, typename Operator = std::function<T(const T &, const T &)>>
    class big_ranges_tree {
        const Operator op;

        class Node {
            const K l, r;
            T val;
            Node *left, *right;
        public:
            Node(K l, K r) : l(l), r(r), val(K()), left(nullptr), right(nullptr) {}

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
        big_ranges_tree(K l, K r, Operator op) : root(l, r), op(op) {}

        explicit big_ranges_tree(K l, K r) : big_ranges_tree(l, r, Operator()) {}

        class updatable_instance {
            big_ranges_tree<K, T, Operator> &rq;
            const K index;
        public:
            updatable_instance(big_ranges_tree<K, T, Operator> &rq, const K index) : rq(rq), index(index) {}

            updatable_instance &operator=(const T &val) {
                rq.root.set(index, val, rq.op);
                return *this;
            }
        };

        updatable_instance operator[](const K index) {
            return updatable_instance(*this, index);
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
    class min_range_query_tree : public big_ranges_tree<K, T, std::function<T(T, T)>> {
    public:
        min_range_query_tree(K l, K r, Comparator comp) :
                big_ranges_tree<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? u : v;
                }) {}

        explicit min_range_query_tree(K l, K r)
                : min_range_query_tree(l, r, Comparator()) {}
    };

    template<typename K, typename T, typename Comparator = std::less<T>>
    class max_range_query_tree : public big_ranges_tree<K, T, std::function<T(T, T)>> {
    public:
        max_range_query_tree(const K l, const K r, Comparator comp) :
                big_ranges_tree<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? v : u;
                }) {}

        explicit max_range_query_tree(const std::vector<T> &v)
                : max_range_query_tree(v, Comparator()) {}
    };

    template<typename K, typename T>
    class sum_range_query_tree : public big_ranges_tree<K, T, std::function<T(T, T)>> {
    public:
        explicit sum_range_query_tree(const K l, const K r) :
                big_ranges_tree<K, T, std::function<T(T, T)>>(l, r, [](const T &u, const T &v) {
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

class CBoboniuAndString {
    class Solver {
    public:
        io::input_reader in;
        io::output_writer out;

        Solver(std::istream &in, std::ostream &out) : in(in), out(out) {}

        void solve() {
            

            int n;
            in >> n;
            vector<array<int, 2>> a(n);
            fori(i, n) {
                string s;
                in >> s;
                for (char c:s) a[i][c == 'N']++;
            }
            vi x, y, xy;
            for (auto aa: a) x.pb(aa[0]), y.pb(aa[1]), xy.pb(aa[0] - aa[1]);
            auto mm_x = minmax_element(all(x));
            auto mm_y = minmax_element(all(y));
            auto mm_xy = minmax_element(all(xy));
            int min_x = *mm_x.first, max_x = *mm_x.second;
            int min_y = *mm_y.first, max_y = *mm_y.second;
            int min_xy = *mm_xy.first, max_xy = *mm_xy.second;

            auto sol = [=](int d) -> optional<array<int, 2>> {
                int _max_x = min_x + d, _min_x = max_x - d;
                int _max_y = min_y + d, _min_y = max_y - d;
                int _max_xy = min_xy + d, _min_xy = max_xy - d;
                if (_max_x < _min_x || _max_y < _min_y || _max_xy < _min_xy) return nullopt;

                int x = _max_x, y = _max_y;

                if (x - y > _max_xy) {
                    

                    x = _max_xy + y;
                } else if (x - y < _min_xy) {
                    

                    y = x - _min_xy;
                }
                if (
                        (x == 0 && y == 0) ||
                        (x < _min_x ||
                         x > _max_x ||
                         y < _min_y ||
                         y > _max_y))
                    return nullopt;
                return {{x, y}};
            };
            int dl = 0, dr = 1e6;
            while (dl < dr) {
                int dm = (dl + dr) / 2;
                if (sol(dm)) dr = dm;
                else dl = dm + 1;
            }
            

            auto ans = *sol(dl);
            string sans;
            fori(i, ans[0]) sans.push_back('B');
            fori(i, ans[1]) sans.push_back('N');
            out.println(dl);
            out.println(sans);
        }
    };

public:
    static void solve(std::istream &in, std::ostream &out) {
        Solver(in, out).solve();
    }
};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	CBoboniuAndString solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
