
















































using std::ios;
using std::ios_base;
using std::istream;
using std::ostream;
using std::getline;
using std::stringstream;
using std::streambuf;
using std::cin;
using std::cout;
using std::cerr;
using std::string;

using std::move;
using std::forward;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
using std::ignore;

using std::pair;
using std::make_pair;
using std::valarray;
using std::vector;
using std::deque;
using std::list;
using std::stack;
using std::queue;
using std::priority_queue;
using std::bitset;

using std::tr2::dynamic_bitset;

using std::set;
using std::map;
using std::multiset;
using std::multimap;

using std::unordered_set;
using std::unordered_map;
using std::unordered_multiset;
using std::unordered_multimap;
using std::initializer_list;
using std::all_of;
using std::any_of;
using std::none_of;

using std::for_each;
using std::count;
using std::count_if;
using std::mismatch;
using std::find;
using std::find_if;

using std::find_if_not;

using std::find_end;
using std::find_first_of;
using std::adjacent_find;
using std::search;
using std::search_n;
using std::copy;

using std::copy_if;
using std::copy_n;

using std::copy_backward;

using std::move;
using std::move_backward;

using std::fill;
using std::fill_n;
using std::transform;
using std::generate;
using std::generate_n;
using std::remove;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::replace;
using std::replace_if;
using std::replace_copy;
using std::replace_copy_if;
using std::swap;
using std::swap_ranges;
using std::iter_swap;
using std::reverse;
using std::reverse_copy;
using std::rotate;
using std::rotate_copy;

using std::shuffle;

using std::unique;
using std::unique_copy;

using std::is_partitioned;

using std::partition;

using std::partition_copy;

using std::stable_partition;

using std::partition_point;
using std::is_sorted;
using std::is_sorted_until;

using std::sort;
using std::partial_sort;
using std::partial_sort_copy;
using std::stable_sort;
using std::nth_element;
using std::lower_bound;
using std::upper_bound;
using std::binary_search;
using std::equal_range;
using std::merge;
using std::inplace_merge;
using std::includes;
using std::set_difference;
using std::set_intersection;
using std::set_symmetric_difference;
using std::set_union;

using std::is_heap;
using std::is_heap_until;

using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::sort_heap;
using std::max;
using std::max_element;
using std::min;
using std::min_element;

using std::minmax;
using std::minmax_element;

using std::equal;
using std::lexicographical_compare;

using std::is_permutation;

using std::next_permutation;
using std::prev_permutation;

using std::iota;

using std::accumulate;
using std::inner_product;
using std::adjacent_difference;
using std::partial_sum;

using std::begin;
using std::end;
using std::function;

using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
using std::modulus;
using std::negate;
using std::equal_to;
using std::not_equal_to;
using std::greater;
using std::less;
using std::greater_equal;
using std::less_equal;
using std::logical_and;
using std::logical_or;
using std::logical_not;

using std::bit_and;
using std::bit_or;
using std::bit_xor;
using std::hash;
using std::mt19937;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;


template<typename key>
using ordered_set = __gnu_pbds::tree<
						key, __gnu_pbds::null_type, less<key>, __gnu_pbds::rb_tree_tag,
						__gnu_pbds::tree_order_statistics_node_update>;
template<typename key, typename val>
using ordered_map = __gnu_pbds::tree<
						key, val, less<key>, __gnu_pbds::rb_tree_tag,
						__gnu_pbds::tree_order_statistics_node_update>;
using __gnu_pbds::cc_hash_table;
using __gnu_pbds::gp_hash_table;
template<typename tp, class cmp>
using pairing_heap = __gnu_pbds::priority_queue<tp, cmp, __gnu_pbds::pairing_heap_tag>;








































"\n\033[45;36;1;5m" title "\033[0m\n" \
"\033[37m"

"\033[0m" \
"\n"

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;
const double pi = acos(-1);
const double eps = 1e-6;
template<typename tp>
tp get_inf() {
	tp ret;
	if (4 < sizeof(ret))
		ret = inf64;
	else
		ret = inf32;
	return ret;
}
template<typename tp>
int bitcount(tp x)
{
	if (4 < sizeof(x))
		return __builtin_popcountll(x);
	else
		return __builtin_popcount(x);
}


template<typename tp>
tp clz(tp x)
{
	if (4 < sizeof(x))
		return __builtin_clzll(x);
	else
		return __builtin_clz(x);
}
template<typename tp>
tp ctz(tp x)
{
	if (4 < sizeof(x))
		return __builtin_ctzll(x);
	else
		return __builtin_ctz(x);
}
template<typename tp>
tp clo(tp x)
{
	if (4 < sizeof(x))
		return x ? 1ll << (64 - 1 - __builtin_clzll(x)) : 0;
	else
		return x ? 1 << (32 - 1 - __builtin_clz(x)) : 0;
}
template<typename tp>
tp cto(tp x)
{
	if (4 < sizeof(x))
		return x ? 1ll << __builtin_ctzll(x) : 0;
	else
		return x ? 1 << __builtin_ctz(x) : 0;
}
template<typename tp>
tp id0(tp x) { return x ? clo(x) << bool(x - clo(x)) : 0; }
template<typename tp>
tp id8(tp x) { return x ? clo(x) : 0; }
bool id7(ll x) { return x && !(x & (x - 1)); }
int id1(int x)
{
	return ctz(id0(x) >> bool(x ^ 1));
}
ull id9(ull x, ull div) { return (x + div - 1) / div; }
ull id4(ull x, ull div) { return x / div; }
ull id5(ull x, ull div) { return id4(x - 1, div); }
ll ltor(ll l, ll len) { return l + len - 1; }
ll rtol(ll r, ll len) { return r - len + 1; }
ll length(ll l, ll r) { return (r < l) ? 0 : r - l + 1; }


ll midpoint(ll l, ll r) { return l + (length(l, r) >> 1); }
template<typename tp>
void id6(tp &l, tp &r) { if (r < l) swap(l, r); }
ll round_shift(ll x, ll dist, ll l, ll r)
{
	int len = length(l, r);
	return (x - l + dist + len) % len + l;
}
bool inrange(ll x, ll l, ll r) { return r < l ? 0 : l <= x && x <= r; }

tuple<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)

pair<ll, pair<ll, ll> > range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)

{
	if (!length(lef_l, lef_r) || !length(rig_l, rig_r) ||
		(lef_r < rig_l || rig_r < lef_l))

		return make_tuple(0, make_pair(-1, -1));

		return make_pair(0, make_pair(-1, -1));

	if (rig_l <= lef_l && lef_r <= rig_r)

		return make_tuple(length(lef_l, lef_r), make_pair(lef_l, lef_r));

		return make_pair(length(lef_l, lef_r), make_pair(lef_l, lef_r));

	if (lef_l <= rig_l && rig_r <= lef_r)

		return make_tuple(length(rig_l, rig_r), make_pair(rig_l, rig_r));

		return make_pair(length(rig_l, rig_r), make_pair(rig_l, rig_r));


	return make_tuple(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));

	return make_pair(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));

}
template<typename tp>
tp special(tp val, const tp *arr, int len, int i, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = len - 1;
	if (inrange(i, m1, m2))
		return arr[i];
	return val;
}
template<typename tp>
tp special(tp val, const vector<tp> &v, int i, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = v.size() - 1;
	if (inrange(i, m1, m2))
		return v[i];
	return val;
}

class direct_io {
	static const int bsz = 1 << 20;
	char ibuf[bsz], obuf[bsz], *ihead, *itail, *ohead, *g_buf, *g_cur;
	streambuf *isb, *osb;
	int id3;
	bool status;
	void set_status(bool ok) {
		status = ok;
	}
	void flush() { osb->sputn(obuf, ohead - obuf); }
	char getchar() {
		if (ihead == itail)
			itail = (ihead = ibuf) + isb->sgetn(ibuf, bsz);
		return (ihead == itail) ? -1 : *ihead++;
	}
	void putchar(char ch) {
		if (ohead - obuf == bsz)
			osb->sputn(ohead = obuf, bsz);
		*ohead++ = ch;
	}
	void input(char &ch) {
		for (; ch = getchar(), ~ch && !isgraph(ch););
		set_status(~ch);
	}
	void input(char *s) {
		char ch;
		input(ch);
		if (!ok())
			return;
		do {
			*s++ = ch;
		} while (ch = getchar(), isgraph(ch));
		*s = 0;
	}
	void input(string &s) {
		s.clear();
		input(g_cur = g_buf);
		if (!ok())
			return;
		s.assign(g_buf);
	}
	template<typename tp>
	void input(tp &ret) {
		char ch;
		int sgn;
		tp bit = 0.1;
		input(ch);
		if (!ok())
			return;
		sgn = (ch == '-') ? -1 : 1;
		ret = isdigit(ch) ? (ch ^ 48) : 0;
		if (ch == '.')
			goto read_float;
		for (; ch = getchar(), isdigit(ch);)
			ret = ret * 10 + (ch ^ 48);
		if (ch ^ '.')
			goto end;
read_float:
		for (; ch = getchar(), isdigit(ch);)
			ret += (ch ^ 48) * bit, bit /= 10;
end:
		ret *= sgn;
	}
	void output(char ch) {
		putchar(ch);
	}
	void output(const char *s) {
		for (; *s; s++)
			putchar(*s);
	}
	void output(const string &s) {
		fup_range (i, 0, s.length())
			putchar(s[i]);
	}
	template<typename tp>
	void output(tp x) {
		g_cur = g_buf;
		ll xn = ll(x);
		if (xn < 0)
			putchar('-'), xn = -xn;
		do {
			*g_cur++ = xn % 10 | 48;
			xn /= 10;
		} while (xn);
		while (g_buf != g_cur)
			putchar(*--g_cur);

		if (std::is_same<typename std::decay<tp>::type, double>::value)

		if (tp(x + 0.5) != x)

		{
			putchar('.');
			x -= ll(x);
			fup (t, 1, id3) {
				putchar(char(x *= 10) | 48);
				x -= char(x);
			}
		}
	}
public:
	direct_io() {

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cout.setf(ios::fixed);
		cout.precision(12);

		isb = cin.rdbuf();
		osb = cout.rdbuf();
		ihead = itail = ibuf;
		ohead = obuf;
		id3 = 12;
		status = 1;
		g_buf = (char *)malloc(1 << 20);
	}
	~direct_io() { flush(); }
	bool ok() {
		return status;
	}
	void set_output_float_digit(int d) {
		id3 = d;
	}
	void set_bufsize(int size) {
		g_buf = (char *)realloc(g_buf, size);
	}

	template<typename ...var>
	bool in(var &&...args)

	template<typename tp>
	bool in(tp &x)

	{


		initializer_list<int>{(input(forward<var>(args)), 0)...};
		return ok();

		initializer_list<int>{(cin >> forward<var>(args), 0)...};
		return cin.good();



		input(x);
		return ok();

		cin >> x;
		return cin.good();


	}
	bool readline(string &line, char delim = '\n') {

		line.clear();
		char ch = getchar();
		set_status(~ch);
		if (ch == -1)
			return 0;
		g_cur = g_buf;
		for (*g_cur++ = ch; ~ch && ch ^ delim; ch = getchar())
			*g_cur++ = ch;
		*g_cur = 0;
		line.assign(g_buf);
		return 1;

		getline(cin, line, delim);
		return !cin.fail();

	}

	template<typename ...var>
	void out(var &&...args)

	template<typename tp>
	void out(tp x)

	{


		initializer_list<int>{(output(forward<var>(args)), 0)...};

		initializer_list<int>{(cout << forward<var>(args), 0)...};



		output(x);

		cout << x;


	}
	void msg(const char *fmt, ...) {
		assert(g_buf);
		va_list args;
		va_start(args, fmt);
		vsprintf(g_buf, fmt, args);
		va_end(args);
		out((const char *)g_buf);
	}
} fio;

struct fake_type {};


usage_begin("debug tips!!!") \
line("io类默认输出缓冲区大小: 1 << 20, 通过fio.set_bufsize(int)重置.") \
usage_end()







template<typename v_info, typename e_info>
struct graph {
	struct node {
		static node *baseaddr;
		vector<int> link;
		v_info meta;
		node() : link(vector<int>()), meta(v_info()) {}
		int id() {
			return this - baseaddr;
		}
	};
	struct edge {
		int from, to;
		e_info meta;
		edge() {}
		edge(int _1, int _2, e_info _3) : from(_1), to(_2), meta(_3) {}
	};
	vector<node> nodes;
	vector<edge> edges;
	node *&baseaddr = node::baseaddr;
	graph(int vn = 0) {
		clear();
		nodes.assign(vn, node());
		baseaddr = &nodes[0];
		edges.reserve(vn);
	}
	node &operator [](int i) {
		return nodes[i];
	}
	void clear() {
		nodes.clear();
		edges.clear();
	}
	int size() {
		return nodes.size();
	}
	void resize(int vn) {
		new (this) graph(vn);
	}
	void add(int from, int to, e_info e_if = e_info()) {
		assert(inrange(from, range(0, nodes.size())));
		assert(inrange(to, range(0, nodes.size())));
		

		add_edge_only(from, to, e_if);
		nodes[from].link.push_back(edges.size() - 1);
	}
	void add2(int from, int to, e_info e_if = e_info()) {
		add(from, to, e_if);
		add(to, from, e_if);
	}
	void add_edge_only(int from, int to, e_info e_if = e_info()) {
		edges.push_back({from, to, e_if});
	}
	pair<node *, edge *> extend(int i) {
		pair<node *, edge *> ret;
		ret.first = &nodes[(ret.second = &edges[i])->to];
		return ret;
	}
};
GRAPH_T
GRAPH_NODE_C *GRAPH_NODE_T::baseaddr;










template<typename graph>
struct topo {
	using node = NODE_C;
	using edge = EDGE_C;

	graph *g;
	node *nd;

	topo(graph *g_) : g(g_), nd(&g->nodes[0]) {}
	pair<bool, vector<int>> sort() {

		if (!o.meta.in) \
			que.push(o.id())
		node *v;
		edge *e;
		vector<int> ret;
		queue<int> que;
		fup_range (u, 0, g->size())
			add(u[nd]);
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			ret.push_back(u);
			for (int ei : u[nd].link) {
				tie(v, e) = g->extend(ei);
				v->meta.in--;
				add(v->id()[nd]);
			}
		}
		return {ret.size() == g->size(), ret};

	}
};




struct vif {
	int in, pos;
	vif() : in(0) {}
};

using graph_t = graph<vif, fake_type>;
using node = typename graph_t::node;
using edge = typename graph_t::edge;

class task {

	do {\
		if (!(cond) || !fio.ok()) { cin.setstate(ios_base::badbit); return cin; }\
	} while(0)
	graph_t g;
	node *nd;
	bool ok;
	void preprocess() {
		fio.set_output_float_digit(12);
	}
	istream &in() {
		int n, m;
		fio.in(n, m);
		g.resize(n);
		nd = &g[0];
		fup_range (mi, 0, m) {
			int d, a, b;
			fio.in(d, a, b);
			a--, b--;
			if (d) {
				g.add(a, b);
				g[b].meta.in++;
			} else {
				g.add_edge_only(a, b);
			}
		}
		ioend(1);
		return cin;
	}
	void deal() {
		topo<graph_t> sst(&g);
		auto ret = sst.sort();
		ok = ret.first;
		fup_range (i, 0, ret.second.size()) {
			int u = ret.second[i];
			u[nd].meta.pos = i;
		}
	}
	void out() {
		if (ok) {
			fio.msg("YES\n");
			fup_range (i, 0, g.edges.size()) {
				edge *e;
				tie(ignore, e) = g.extend(i);
				int u, v, pu, pv;
				u = e->from;
				v = e->to;
				pu = u[nd].meta.pos;
				pv = v[nd].meta.pos;
				if (pu < pv) {
					fio.msg("%d %d\n", u + 1, v + 1);
				} else {
					fio.msg("%d %d\n", v + 1, u + 1);
				}
			}
		} else {
			fio.msg("NO\n");
		}
	}
public:
	task(
		bool id2 = 0,
		const char *fmt_case = 0,
		bool blankline = 0) {
		static int testcase = 1 << 30;
		static stringstream tid;
		preprocess();
		if (id2)
			fio.in(testcase);
		for (int ti = 1; ti <= testcase && in(); ++ti) {
			deal();
			if (blankline && 1 < ti)
				fio.out('\n');
			if (fmt_case)
				fio.msg(fmt_case, ti);
			out();
		}
	}

};

int main()
{
	new task(1);
	return 0;
}
