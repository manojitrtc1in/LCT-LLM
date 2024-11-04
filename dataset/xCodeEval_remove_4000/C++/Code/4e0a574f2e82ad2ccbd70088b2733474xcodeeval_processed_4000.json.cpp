



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
void id7(value_type& val, const relax_type& rel) { static predictor pred; if (pred(val, rel)) val = rel; }
template <typename type>
void id4(type& val, const type& rel) { id7<type, type, greater<type>>(val, rel); }
template <typename type>
void id14(type& val, const type& rel) { id7<type, type, less<type>>(val, rel); }
ld const PI = acos(-1);














                         














namespace io {


ofstream logger_("log", ios::out);


template <typename iter_t>
void id10(std::istream& in, iter_t begin, iter_t end) {
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

unsigned long long id13() {
	unsigned long long res;
	std::cin >> res;
	return res;
}

unsigned long long id6(std::istream& in) {
	unsigned long long res;
	in >> res;
	return res;
}

char read_char() {
	char c;
	std::cin >> c;
	return c;	
}

char id8(istream& in) {
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
void id12(std::ostream& out, iter_t begin, iter_t end) {
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
	id12(out, begin, end);
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
std::ostream& id11(std::ostream& out, iter_t begin, iter_t end) {
	
	id12(out, begin, end);
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
	id10(in, value.begin(), value.end());
	return in;
}
template<typename T, size_t capacity>
std::istream& operator>>(std::istream& in, std::array<T, capacity>& value) {
	id10(in, value.begin(), value.end());
	return in;
}
template<typename T>
std::istream& operator>>(std::istream& in, std::deque<T>& value) {
	id10(in, value.begin(), value.end());
	return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
	return id11(out, value.begin(), value.end());
}
template <typename T, size_t capacity>
std::ostream& operator<<(std::ostream& out, const std::array<T, capacity>& value) {
	return id11(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& value) {
	return id11(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& value) {
	return id11(out, value.begin(), value.end());
}
template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::map<F, S>& value) {
	return id11(out, value.begin(), value.end());
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













void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}




size_t const alloc_mem = 4e7;
int buf[alloc_mem];
int* ptr = buf;
int* make_array(int n) {
	int* res = ptr;
	ptr += n;
	

	return res; 
}



int const N = 2e5 + 4, T = (1 << 19);
ll v;
int a[N], t[N]; 
int* fenw[T];
int* hv[T];
int sz[T];
vi bhv[N];
ll sval[2][N];

struct Comp {	
	bool operator()(int i, int j) const {
		return t[i] == t[j] ? i < j : t[i] < t[j];
	}
} comp;

void build(int v, int tl, int tr) {
	if (tl == tr) {
		sz[v] = bhv[tl].size();
		hv[v] = make_array(sz[v]);
		copy(all(bhv[tl]), hv[v]);
		copy(hv[v], hv[v] + sz[v], hv[v]);
		sort(hv[v], hv[v] + sz[v], comp);		
	} else {
		trans;
		build(l, tl, tm);
		build(r, tm + 1, tr);
		sz[v] = sz[l] + sz[r];
		hv[v] = make_array(sz[v]);
		merge(hv[l], hv[l] + sz[l], hv[r], hv[r] + sz[r], hv[v], comp);
	}
	fenw[v] = make_array(sz[v]);
	fill(fenw[v], fenw[v] + sz[v], -N);
}

void id9(int* bit, int sz, int v, int val) {
	for (; v < sz; v |= (v + 1)) {
		id14(bit[v], val);
	}
}

int bit_get(int* bit, int v) {
	--v;
	int ans = -N;
	for (; v >= 0; v = (v & (v + 1)) - 1) {
		id14(ans, bit[v]);
	}
	return ans;
}

void set_val(int v, int id, int val) {
	int pos = lower_bound(hv[v], hv[v] + sz[v], id, comp) - hv[v];
	id9(fenw[v], sz[v], pos, val);
}

void set_val(int STqp, int id, int val) {
	set_val(v, id, val);
	while (tl < tr) {
		trans;
		if (i <= tm) {
			v = l, tr = tm;
		} else {
			v = r, tl = tm + 1;
		}
		set_val(v, id, val);
	}	
}

int get_val(int id5, int id) {
	if (ql > qr) {
		return -N;
	}
	if (STqmtch) {
		t[N - 1] = t[id];
		int pref = lower_bound(hv[v], hv[v] + sz[v], N - 1, comp) - hv[v];
		return bit_get(fenw[v], pref);
	}
	trans;
	return max(get_val(STL, id), get_val(STR, id));
}

int renum(int n) {
	F(i, 0, n - 1) {
		sval[0][i] = v * t[i] - a[i];
		sval[1][i] = v * t[i] + a[i];
	}
	int m[2];
	F(q, 0, 1) {
		sort(sval[q], sval[q] + n);
		m[q] = unique(sval[q], sval[q] + n) - sval[q];
	}
	F(i, 0, n - 1) {
		ll val[2] = {v * t[i] - a[i], v * t[i] + a[i]};
		a[i] = lower_bound(sval[0], sval[0] + m[0], val[0]) - sval[0];
		t[i] = lower_bound(sval[1], sval[1] + m[1], val[1]) - sval[1];
	}
	return m[0];	
}

void solve() {	
	int n;
	reads(n, v);
	++n;
	read_seq(t + 1, t + n);
	read_seq(a + 1, a + n);
	int m = renum(n);
	F(i, 0, n - 1) {
		bhv[a[i]].push_back(i);
	}
	build(1, 0, m - 1);
	set_val(1, 0, m - 1, a[0], 0, 0); 
	int ans = 0;
	F(i, 1, n - 1) {
		int dp = 1 + get_val(1, 0, m - 1, 0, a[i], i);
		id14(ans, dp);	
		set_val(1, 0, m - 1, a[i], i, dp);
	}
	println(ans);
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int st_time = clock();
	
	int t = 1;
	

	

	while (t--) {
		solve();
	}   
	
	sprintln(cerr, "time:", clock() - st_time);
	
	return 0;
}       		