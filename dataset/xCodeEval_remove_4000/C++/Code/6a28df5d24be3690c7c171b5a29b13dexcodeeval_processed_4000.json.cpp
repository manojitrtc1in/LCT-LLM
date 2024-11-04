






















using ll = long long int;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pi = std::pair<int, int>;
using vpi = std::vector<pi>;







template<typename T> void mk_unique(T& l) { if (!std::is_sorted(all(l))) std::sort(all(l)); auto it = std::unique(l.begin(), l.end()); auto d = std::distance(l.begin(), it); l.resize(d); }
template<typename T> T &smax(T& l, const T&r) { if(l<r) l=r; return l; }
template<typename T> T &smin(T& l, const T&r) { if(l>r) l=r; return l; }

constexpr int MOD = 998244353;



namespace io{
class input_reader{
void throw_error(){throw std::runtime_error("No more inputs while reading number");}
template<typename T>
inline void id14(T&f){bool positive=true;f=0;char c;
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
};
}

namespace io{
class output_writer{
std::ostream&out;
template<typename T>inline void id19(T x){if(x>=10)id19(x/10);out.put(x%10+48);}
template<typename T>inline void printInteger(T x){if(x<0)out.put('-'),x=-x;id19(x);}
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
template<typename T1>inline void print(const std::vector<T1>&t1){printArray(t1);}
template<typename T1,int N>inline void print(const std::array<T1,N>&t1){printArray(t1);}
template<typename T1,int N,int M>inline void print(const std::array<std::array<T1,M>,N>&t1){for(auto&t:t1)println(t);}
template<typename T1>inline void print(const std::vector<std::vector<T1>>&t1){bool first=true;for(auto&t:t1)print((first)? first=false,"":"\n",t);}
template<typename T,typename...Args>inline void print(const T&t,Args...args){print(t),print(args...);}
template<typename...Args>inline void println(Args...args){print(args...),print('\n');}
template<typename T>output_writer&operator<<(const T&t){return print(t),*this;}
};
}

inline ll pow_mod(ll a,ll b,const ll MOD){ll res=1;for(ll i=1;b;b^=b&i,i<<=1,a=(a*a)%MOD)if(b&i)res=(res*a)%MOD;return res;}
inline ll mod_inv(const ll a,const ll MOD){return pow_mod(a,MOD-2,MOD);}
template<typename T>inline T gcd(T a,T b){T t;while(a!=0)t=a,a=b%a,b=t;return b;}
template<typename T>T lcm(const T &a,const T &b) {assert(a!=0&&b!=0);return a/gcd(a,b)*b;}
namespace math {
template<class T> int gMOD(T v){v%=MOD;if(v<0)v+=MOD;return (int)v;};
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
inline mi pow(long long int pw)const{mi res,val;res.v=1,val.v=v;while(pw){if(pw&1)res*=val;val*=val;pw>>=1;}return res;}
inline operator int()const {return v;}
inline friend std::istream& operator>>(std::istream& in,mi&rhs){long long int v;in>>v;rhs={v};return in;}
inline friend std::ostream& operator<<(std::ostream& out,mi&rhs){out<<rhs.v;return out;}
};
}
namespace math {
mod_int factorial(unsigned int n) {
static std::vector<mod_int> mem;static mod_int last;
if (mem.empty()) last = {1}, mem.push_back(last);
while (!(n < mem.size())) mem.push_back(mem.back() * last++);
return mem[n];
}
mod_int id10(int n, int k){
mod_int res =  factorial(n);mod_int res2 = (factorial(k) * factorial(n-k));
return res/res2;
}
}

const double PI = 3.14159265358979323846264338327950288419716939937510;


















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
	class id2 : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit id2(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return u + v; }) {}

		explicit id2(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return u + v; }) {}

		explicit id2(int n, const T &val) : id2(std::vector<T>(n, val)) {}
	};


	template<typename T>
	class id7 : public ranges_array<T, std::function<T(T, T)>> {
	public:
		explicit id7(const std::vector<T> &v) :
				ranges_array<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) { return v; }) {}

		explicit id7(int n) :
				ranges_array<T, std::function<T(T, T)>>(n, [](const T &u, const T &v) { return v; }) {}

		explicit id7(int n, const T &val) : id7(std::vector<T>(n, val)) {}
	};
}





namespace range_query {


	

	

	

	

	

	template<typename T, typename Operator, bool id9 = false>
	class id1 {
		const Operator op;
		std::vector<std::vector<T>> vec;

		static int largest_bit(int x) { return 31 - __builtin_clz(x); }

	public:
		id1(std::vector<T> v, Operator op) : op(op) {
			vec.push_back(v);
			const int n = v.size();
			int id8 = 1;
			while (id8 * 2 <= n) {
				for (int i = 0; i + id8 * 2 <= n; ++i) {
					v[i] = op(v[i], v[i + id8]);
				}
				id8 <<= 1;
				vec.emplace_back(v.begin(), v.begin() + (n - id8) + 1);
			}
		}

		explicit id1(const std::vector<T> &v) : id1(v, Operator()) {}

		T query(int l, int r) const {
			assert(l <= r);
			if (!id9) {
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
	class id16 : public id1<T, std::function<T(T, T)>> {
	public:
		id16(const std::vector<T> &v, Comparator comp) :
				id1<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? u : v;
				}) {}

		explicit id16(const std::vector<T> &v)
				: id16(v, Comparator()) {}
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
	class id22 : public id1<T, std::function<T(T, T)>> {
	public:
		explicit id22(const std::vector<T> &v) :
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
id18(const std::vector<T> &v, Comparator cmp) : ranges_array_(v, get_min(cmp)) {}
explicit id18(const std::vector<T> &v) : ranges_array_(v) {}
id18(int n, Comparator cmp) : ranges_array_(n, get_min(cmp)) {}
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
    class id3 : public id5<K, T, std::function<T(T, T)>> {
    public:
        explicit id3(const K l, const K r) :
                id5<K, T, std::function<T(T, T)>>(l, r, [](const T &u, const T &v) {
                    return v + u;
                }) {}
    };
}





using mi = math::mod_int;
using vmi = std::vector<mi>;
using vvmi = std::vector<std::vector<mi>>;

using namespace std;
int a[15];
int n;
pair<int, pi> dp[16][16][1 << 15];
bool deleted[15];
int sums[1 << 15];


class FMakeItAscending {
    template<int n>class Solver {
    public:
        io::input_reader in;
        io::output_writer out;

        Solver(std::istream &in, std::ostream &out) : in(in), out(out) {}


        void calc_sums() {
            sums[0] = 0;
            rep(i, 1, (1 << n) - 1) {
                int lsb = i & (-i);
                int id4 = __builtin_ctz(lsb);
                sums[i] = sums[i ^ lsb] + a[id4];
            }
        }

        int get_pos(int i) {
            repr(j, i - 1, 0) {
                if (deleted[j]) i--;
            }
            return i;
        }

        void print(int i, int id6) {
            out.println(get_pos(i) + 1, " ", get_pos(id6) + 1);
            deleted[i] = true;
        }

        void print(int c, int last_open, int mask) {
            if (c != 0) {
                print(c - 1, dp[c][last_open][mask].second.first, dp[c][last_open][mask].second.second);
            }
            int to_use = dp[c][last_open][mask].second.second ^mask;
            int id6 = last_open - 1;
            fori(i, n)
                if (id6 != i)
                    if ((1 << i) & to_use)
                        print(i, id6);
        }


        void solve() {
            

            fori(i, n) in >> a[i];
            fori(i, n + 1) fori(j, n + 1) fori(mask, 1 << n) dp[i][j][mask] = {-1, {-1, -1}};
            dp[0][0][0] = {0, {0, 0}};
            pi best = {-1, -1};
            calc_sums();
            rep(c, 1, n) {
                fori(id21, n) {
                    fori(mask, 1 << n) {
                        auto id20 = dp[c - 1][id21][mask].first;
                        if (id20 == -1) continue;
                        int rmask = ((1 << n) - 1) ^mask;
                        for (int nmask = rmask; nmask >= 1 << id21; nmask = (nmask - 1) & rmask) {
                            int new_v = sums[nmask];
                            if (id20 < new_v) {
                                int id17 = id21 + __builtin_ctz(nmask >> id21) + 1;
                                int old_v = dp[c][id17][mask | nmask].first;
                                if (old_v == -1 || new_v < old_v) {
                                    dp[c][id17][mask | nmask] = {new_v, {id21, mask}};
                                    if ((mask | nmask) == (1 << n) - 1) {
                                        best = {c, id17};
                                    }
                                }
                            }
                        }
                    }
                }
            }
            

            out.println(n - best.first);
            fori(i, n) deleted[i] = false;
            print(best.first, best.second, (1 << n) - 1);
        }
    };

public:

    void solve(std::istream &in, std::ostream &out) {
        in >> n;
        if(1==n) Solver<1>(in, out).solve();
        if(2==n) Solver<2>(in, out).solve();
        if(3==n) Solver<3>(in, out).solve();
        if(4==n) Solver<4>(in, out).solve();
        if(5==n) Solver<5>(in, out).solve();
        if(6==n) Solver<6>(in, out).solve();
        if(7==n) Solver<7>(in, out).solve();
        if(8==n) Solver<8>(in, out).solve();
        if(9==n) Solver<9>(in, out).solve();
        if(10==n) Solver<10>(in, out).solve();
        if(11==n) Solver<11>(in, out).solve();
        if(12==n) Solver<12>(in, out).solve();
        if(13==n) Solver<13>(in, out).solve();
        if(14==n) Solver<14>(in, out).solve();
        if(15==n) Solver<15>(in, out).solve();

    }

};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	FMakeItAscending solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}
