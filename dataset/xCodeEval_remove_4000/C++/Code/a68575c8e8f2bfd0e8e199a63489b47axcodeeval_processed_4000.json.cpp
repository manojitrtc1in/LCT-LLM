

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
void id0(type& val, const type& rel) { id12<type, type, greater<type>>(val, rel); }
template <typename type>
void id11(type& val, const type& rel) { id12<type, type, less<type>>(val, rel); }
ld const PI = acos(-1);














                         














namespace io {


ofstream logger_("log", ios::out);


template <typename iter_t>
void id7(std::istream& in, iter_t begin, iter_t end) {
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

int id1(std::istream& in) {
  int res;
  in >> res;
  return res;	
}

long long read_ll() {
	long long res;
	std::cin >> res;
	return res;
}

long long id4(std::istream& in) {
	long long res;
	in >> res;
	return res;
}

unsigned long long id8() {
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

char id2(istream& in) {
	char c;
	in >> c;
	return c;	
}

std::string read_str() {
	std::string str;
	std::cin >> str;
	return str;	
}

std::string id3(istream& in) {
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
void id9(std::ostream& out, iter_t begin, iter_t end) {
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
void id5(std::ostream& out, iter_t begin, iter_t end) {
	id9(out, begin, end);
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
	
	id5(logger_, begin, end);
	
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
std::ostream& id10(std::ostream& out, iter_t begin, iter_t end) {
	
	id9(out, begin, end);
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
	id7(in, value.begin(), value.end());
	return in;
}
template<typename T, size_t capacity>
std::istream& operator>>(std::istream& in, std::array<T, capacity>& value) {
	id7(in, value.begin(), value.end());
	return in;
}
template<typename T>
std::istream& operator>>(std::istream& in, std::deque<T>& value) {
	id7(in, value.begin(), value.end());
	return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
	return id10(out, value.begin(), value.end());
}
template <typename T, size_t capacity>
std::ostream& operator<<(std::ostream& out, const std::array<T, capacity>& value) {
	return id10(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& value) {
	return id10(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& value) {
	return id10(out, value.begin(), value.end());
}
template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::map<F, S>& value) {
	return id10(out, value.begin(), value.end());
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











int const N = 4e5 + 4;
int a[N], ord[N];

struct node {
	node* l = nullptr;
	node* r = nullptr;
	node* p = nullptr;
	int val, psh = 0, prior;
} nodes[N];

bool acomp(int i, int j) {
	return a[i] < a[j];
}

void set_par(node* v, node* p) {
	if (v) {
		v->p = p;
	}
}

void set_val(node* v, int x) {
	if (v) {
		v->val = v->psh = x;
	}
}

void do_push(node* v) {
	if (v->psh) {
		set_val(v->l, v->psh);
		set_val(v->r, v->psh);
		v->psh = 0;
	}
}

node* merge(node* l, node* r) {
	if (!l || !r) {
		return l ? l : r;
	}	
	if (l->prior > r->prior) {
		do_push(l);
		node* rc = l->r;
		set_par(rc, nullptr);
		l->r = merge(rc, r);
		set_par(l->r, l);
		return l;
	} 
	do_push(r);
	node* lc = r->l;
	set_par(lc, nullptr);
	r->l = merge(l, lc);
	set_par(r->l, r);
	return r;
}

void push_path(node* v) {
	static vector<node*> pth;
	for (; v; v = v->p) {
		pth.push_back(v);
	}
	for (; pth.size(); pth.pop_back()) {
		do_push(pth.back());
	}
}

pair<node*, node*> split(node* v, int pivot) {
	if (!v) {
		return {nullptr, nullptr};
	}	
	do_push(v);
	if (v->val >= pivot) {
		node* lc = v->l;
		set_par(lc, nullptr);
		auto [l, r] = split(lc, pivot);	
		v->l = r;
		set_par(r, v);
		return {l, v};
	}
	node* rc = v->r;
	set_par(rc, nullptr);
	auto [l, r] = split(rc, pivot);
	v->r = l;
	set_par(l, v);
	return {v, r};
}

node* erase_node(node* v) {
	node* l = v->l;
	node* r = v->r;
	v->l = v->r = nullptr;
	node* p = v->p;
	set_par(l, nullptr);
	set_par(r, nullptr);
	set_par(v, nullptr);
	node* tmp = merge(l, r);
	if (!p) {
		return tmp;
	}
	if (p->l == v) {
		p->l = tmp;				
	} else {
		p->r = tmp;
	}
	set_par(tmp, p);
	tmp = p;
	while (tmp->p) {
		tmp = tmp->p;
	}
	return tmp;
}

void solve() {
	int n = read_int();	
	read_seq(a, a + n);
	iota(ord, ord + n, 0);
	sort(ord, ord + n, acomp);
	node* root = nullptr;
	mt19937 rnd(time(0));
	F(i, 0, n - 1) {
		int x = ord[i];
		nodes[x].val = a[x];
		nodes[x].prior = rnd();
		root = merge(root, nodes + x);
	}
	int q = read_int();
	while (q--) {
		int t = read_int();
		if (t == 3) {
			int l, r;
			reads(l, r);
			auto [sma, tmp1] = split(root, l);
			int rmid = (l + r + 1) / 2;
			auto [lhalf, tmp2] = split(tmp1, rmid);
			auto [rhalf, big] = split(tmp2, r + 1);
			set_val(lhalf, l - 1);
			set_val(rhalf, r + 1);
			root = merge(merge(sma, lhalf), merge(rhalf, big));
			continue;
		}
		node* v = nodes + read_int() - 1;
		push_path(v);
		if (t == 2) {
			println(v->val);
			continue;
		}
		int nval = read_int();
		if (nval == v->val) {
			continue;
		}
		auto [sma, tmp1] = split(root, v->val);
		auto [eq, big] = split(tmp1, v->val + 1);
		eq = erase_node(v);
		if (nval < v->val) {
			v->val = nval;
			auto [l, r] = split(sma, nval);
			sma = merge(l, merge(v, r));
		} else {
			v->val = nval;
			auto [l, r] = split(big, nval);
			big = merge(l, merge(v, r));
		}
		root = merge(sma, merge(eq, big));
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t = 1;
	

	

	while (t--) {
		solve();
	}   
	return 0;
}       		