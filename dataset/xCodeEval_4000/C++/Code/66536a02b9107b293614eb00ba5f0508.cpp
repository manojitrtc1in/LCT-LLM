#define FAST_IO 1
#include <cstddef>
#if 201103L <= __cplusplus
#include <cstdint>
#endif
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <limits>
#include <utility>
#include <functional>
#include <chrono>
#include <algorithm>
#include <numeric>
#if 201103L <= __cplusplus
#include <random>
#endif
#include <valarray>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#if 201103L <= __cplusplus
#include <unordered_set>
#include <unordered_map>
#endif
#include <stack>
#include <queue>
#include <bitset>
#if 201103L <= __cplusplus
#include <tr2/dynamic_bitset>
#endif
#ifdef __linux__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#include <iterator>
using std::ios;
using std::ios_base;
using std::istream;
using std::ostream;
using std::ws;
using std::getline;
using std::stringstream;
using std::streambuf;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
#if 201103L <= __cplusplus
using std::move;
using std::forward;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
using std::ignore;
#endif
using std::numeric_limits;
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
#if 201103L <= __cplusplus
using std::tr2::dynamic_bitset;
#endif
using std::set;
using std::map;
using std::multiset;
using std::multimap;
#if 201103L <= __cplusplus
using std::unordered_set;
using std::unordered_map;
using std::unordered_multiset;
using std::unordered_multimap;
using std::initializer_list;
using std::iterator_traits;
using std::all_of;
using std::any_of;
using std::none_of;
#endif
using std::for_each;
using std::count;
using std::count_if;
using std::mismatch;
using std::find;
using std::find_if;
#if 201103L <= __cplusplus
using std::find_if_not;
#endif
using std::find_end;
using std::find_first_of;
using std::adjacent_find;
using std::search;
using std::search_n;
using std::copy;
#if 201103L <= __cplusplus
using std::copy_if;
using std::copy_n;
#endif
using std::copy_backward;
#if 201103L <= __cplusplus
using std::move;
using std::move_backward;
#endif
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
#if 201103L <= __cplusplus
using std::shuffle;
#endif
using std::unique;
using std::unique_copy;
#if 201103L <= __cplusplus
using std::is_partitioned;
#endif
using std::partition;
#if 201103L <= __cplusplus
using std::partition_copy;
#endif
using std::stable_partition;
#if 201103L <= __cplusplus
using std::partition_point;
using std::is_sorted;
using std::is_sorted_until;
#endif
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
#if 201103L <= __cplusplus
using std::is_heap;
using std::is_heap_until;
#endif
using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::sort_heap;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
#if 201103L <= __cplusplus
using std::minmax;
using std::minmax_element;
#endif
using std::equal;
using std::lexicographical_compare;
#if 201103L <= __cplusplus
using std::is_permutation;
#endif
using std::next_permutation;
using std::prev_permutation;
#if 201103L <= __cplusplus
using std::iota;
#endif
using std::accumulate;
using std::inner_product;
using std::adjacent_difference;
using std::partial_sum;
#if 201103L <= __cplusplus
using std::begin;
using std::end;
using std::function;
#endif
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
#if 201103L <= __cplusplus
using std::bit_and;
using std::bit_or;
using std::bit_xor;
using std::hash;
using std::mt19937;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
#endif
#ifdef __linux__
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
#endif
#define fup_s(i, a, b, s) for (int i = a, foc = b; i <= foc; i += s)
#define fwn_s(i, a, b, s) for (int i = b, foc = a; foc <= i; i -= s)
#define fup_s2(i, lr, s) fup_s(i, lr, s)
#define fwn_s2(i, lr, s) fwn_s(i, lr, s)
#define fup(i, a, b) fup_s(i, a, b, 1)
#define fwn(i, a, b) fwn_s(i, a, b, 1)
#define fup2(i, lr) fup(i, lr)
#define fwn2(i, lr) fwn(i, lr)
#define fup_range_s(i, st, off, s) fup_s2(i, range(st, off), s)
#define fup_range_rs(i, ed, off, s) fup_s2(i, range_r(ed, off), s)
#define fwn_range_s(i, st, off, s) fwn_s2(i, range(st, off), s)
#define fwn_range_rs(i, ed, off, s) fwn_s2(i, range_r(ed, off), s)
#define fup_range(i, st, off) fup2(i, range(st, off))
#define fup_range_r(i, ed, off) fup2(i, range_r(ed, off))
#define fwn_range(i, st, off) fwn2(i, range(st, off))
#define fwn_range_r(i, ed, off) fwn2(i, range_r(ed, off))
#define it_each(obj) (obj).begin(), (obj).end()
#define it_i(obj, i) ((obj).begin() + (i))
#define it_i_rev(obj, i) ((obj).end() - 1 - (i))
#define it_seg(obj, l, r) it_i(obj, l), (it_i(obj, r) + 1)
#define it_seg2(obj, lr) it_seg(obj, lr)
#define it_seg_rev(obj, l, r) it_i_rev(obj, r), (it_i_rev(obj, l) + 1)
#define it_seg_rev2(obj, lr) it_seg_rev(obj, lr)
#define it_range(obj, st, off) it_seg2(obj, range(st, off))
#define it_range_r(obj, ed, off) it_seg2(obj, range_r(ed, off))
#define it_range_rev(obj, st, off) it_seg_rev2(obj, range(obj, st, off))
#define it_range_r_rev(obj, ed, off) it_seg_rev2(obj, range_r(obj, ed, off))
#define it_prefix(obj, i) (obj).begin(), it_i(obj, i)
#define it_suffix(obj, i) it_i(obj, i), (obj).end()
#define it_vtp(it) typename iterator_traits<it>::value_type
#define i_rev(len, i) ((len) - 1 - (i))
#define seg_rev2(len, lr) seg_rev(len, lr)
#define seg_rev(len, a, b) i_rev(len, b), i_rev(len, a)
#define range(st, off) (st), ((st) + (off) - 1)
#define range_r(ed, off) ((ed) - (off) + 1), (ed)
#define range_rev(len, st, off) seg_rev2(len, range(st, off))
#define range_r_rev(len, ed, off) seg_rev2(len, range_r(ed, off))
#define finput(is, cls, obj) friend istream &operator >>(istream &is, cls &obj)
#define foutput(os, cls, obj) friend ostream &operator <<(ostream &os, const cls &obj)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;
const double pi = acos(-1);
const double eps = 1e-6;
int fcmp(double x)
{
	return fabs(x) < eps ? 0 : x < 0 ? -1 : 1;
}
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
tp roundup_pow_of_2(tp x) { return x ? clo(x) << bool(x - clo(x)) : 0; }
template<typename tp>
tp rounddown_pow_of_2(tp x) { return x ? clo(x) : 0; }
bool is_power_of_2(ll x) { return x && !(x & (x - 1)); }
int half2xp(int x)
{
	return ctz(roundup_pow_of_2(x) >> bool(x ^ 1));
}
ull div_roundup(ull x, ull div) { return (x + div - 1) / div; }
ull div_rounddown(ull x, ull div) { return x / div; }
ull div_last_offset(ull x, ull div) { return div_rounddown(x - 1, div); }
ll ltor(ll l, ll len) { return l + len - 1; }
ll rtol(ll r, ll len) { return r - len + 1; }
ll length(ll l, ll r) { return (r < l) ? 0 : r - l + 1; }

template<typename tp>
tp midpoint(tp l, tp r) {
	return (l | r) - ((l ^ r) >> 1);
}
template<typename tp>
void range_normalize(tp &l, tp &r) { if (r < l) swap(l, r); }
ll round_shift(ll x, ll dist, ll l, ll r)
{
	int len = length(l, r);
	return (x - l + dist + len) % len + l;
}
bool inrange(ll x, ll l, ll r) { return r < l ? 0 : l <= x && x <= r; }
#if 201103L <= __cplusplus
tuple<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)
#else
pair<ll, pair<ll, ll> > range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)
#endif
{
	if (!length(lef_l, lef_r) || !length(rig_l, rig_r) ||
		(lef_r < rig_l || rig_r < lef_l))
#if 201103L <= __cplusplus
		return make_tuple(0, make_pair(-1, -1));
#else
		return make_pair(0, make_pair(-1, -1));
#endif
	if (rig_l <= lef_l && lef_r <= rig_r)
#if 201103L <= __cplusplus
		return make_tuple(length(lef_l, lef_r), make_pair(lef_l, lef_r));
#else
		return make_pair(length(lef_l, lef_r), make_pair(lef_l, lef_r));
#endif
	if (lef_l <= rig_l && rig_r <= lef_r)
#if 201103L <= __cplusplus
		return make_tuple(length(rig_l, rig_r), make_pair(rig_l, rig_r));
#else
		return make_pair(length(rig_l, rig_r), make_pair(rig_l, rig_r));
#endif
#if 201103L <= __cplusplus
	return make_tuple(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));
#else
	return make_pair(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));
#endif
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
	int output_float_digit;
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
		if (x < 0)
			putchar('-');
		ll xn = x < 0 ? ll(-x) : ll(x);
		do {
			*g_cur++ = xn % 10 | 48;
			xn /= 10;
		} while (xn);
		while (g_buf != g_cur)
			putchar(*--g_cur);
#if 201103L <= __cplusplus
		if (std::is_same<typename std::decay<tp>::type, double>::value)
#else
		if (tp(x + 0.5) != x)
#endif
		{
			putchar('.');
			x -= ll(x);
			if (x < 0)
				x *= -1;
			fup (t, 1, output_float_digit) {
				putchar(char(x *= 10) | 48);
				x -= char(x);
			}
		}
	}
public:
	direct_io() {
#if !FAST_IO
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cout.setf(ios::fixed);
		cout.precision(12);
#endif
		isb = cin.rdbuf();
		osb = cout.rdbuf();
		ihead = itail = ibuf;
		ohead = obuf;
		output_float_digit = 12;
		status = 1;
		g_buf = (char *)malloc(1 << 20);
	}
	~direct_io() { flush(); }
	bool ok() {
		return status;
	}
	void set_output_float_digit(int d) {
		output_float_digit = d;
#if !FAST_IO
		cout.precision(output_float_digit);
#endif
	}
	void set_bufsize(int size) {
		g_buf = (char *)realloc(g_buf, size);
	}
#if 201103L <= __cplusplus
	template<typename ...var>
	bool in(var &&...args)
#else
	template<typename tp>
	bool in(tp &x)
#endif
	{
#if 201103L <= __cplusplus
#  if FAST_IO
		initializer_list<int>{(input(forward<var>(args)), 0)...};
		return ok();
#  else
		initializer_list<int>{(cin >> forward<var>(args), 0)...};
		return cin.good();
#  endif
#else
#  if FAST_IO
		input(x);
		return ok();
#  else
		cin >> x;
		return cin.good();
#  endif
#endif
	}
	bool readline(string &line, char delim = '\n') {
#if FAST_IO
		line.clear();
		char ch = getchar();
		set_status(~ch);
		if (ch == -1)
			return 0;
		if (ch == delim)
			return 1;
		g_cur = g_buf;
		for (; ~ch && ch ^ delim; ch = getchar())
			*g_cur++ = ch;
		*g_cur = 0;
		line.assign(g_buf);
		return 1;
#else
		getline(cin, line, delim);
		return !cin.fail();
#endif
	}
	bool readline_noblank(string &line, char delim = '\n') {
		bool ret;
		do {
			if (!(ret = readline(line, delim)))
				return ret;
		} while (!line.size());
		return ret;
	}
#if 201103L <= __cplusplus
	template<typename ...var>
	void out(var &&...args)
#else
	template<typename tp>
	void out(tp x)
#endif
	{
#if 201103L <= __cplusplus
#  if FAST_IO
		initializer_list<int>{(output(forward<var>(args)), 0)...};
#  else
		initializer_list<int>{(cout << forward<var>(args), 0)...};
#  endif
#else
#  if FAST_IO
		output(x);
#  else
		cout << x;
#  endif
#endif
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


template<typename info>
struct graph_node {
	typedef info info_t;
	static graph_node *base_addr;
	vector<int> link;
	info meta;
	graph_node() : link(vector<int>()), meta(info()) {}
	int id() {
		return this - base_addr;
	}
};
template<typename _1>
graph_node<_1> *graph_node<_1>::base_addr;

template<typename info>
struct graph_edge {
	typedef info info_t;
	int from, to;
	info meta;
	graph_edge() {}
	graph_edge(int _1, int _2, info _3 = info()) : from(_1), to(_2), meta(_3) {}
};

template<typename node, typename edge>
struct graph {
	typedef node node_t;
	typedef edge edge_t;
	typedef typename node::info_t nif;
	typedef typename edge::info_t eif;
	vector<node> nodes;
	vector<edge> edges;
	node *&node_base;
	graph(int vn = 0) : node_base(node::base_addr) {
		clear();
		nodes.assign(vn, node());
		node_base = &nodes[0];
		edges.reserve(vn);
	}
	node &operator [](int i) {
		node_base = &nodes[0];
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
	void add(int from, int to, eif meta = eif()) {
		assert(inrange(from, range(0, nodes.size())));
		assert(inrange(to, range(0, nodes.size())));
		add_edge_only(from, to, meta);
		nodes[from].link.push_back(edges.size() - 1);
	}
	void add2(int from, int to, eif meta = eif()) {
		add(from, to, meta);
		add(to, from, meta);
	}
	void add_edge_only(int from, int to, eif meta = eif()) {
		edges.push_back({from, to, meta});
	}
	pair<node *, edge *> extend(int i) {
		pair<node *, edge *> ret;
		ret.first = &nodes[(ret.second = &edges[i])->to];
		return ret;
	}
};


struct nif {
	int dist, ans;
	bool vis;
	nif() : dist(inf32), vis(0) {}
};
struct eif {
	int cost;
	eif() : cost(1) {}
	eif(int _1) : cost(_1) {}
};
typedef graph<graph_node<nif>, graph_edge<eif>> graph_t;
typedef graph_t::node_t node;
typedef graph_t::edge_t edge;

class task {
#define ioend(cond) \
	do {\
		if (!(cond) || !fio.ok()) { cin.setstate(ios_base::badbit); return cin; }\
	} while(0)
	int gn, gm;
	graph_t gg;
	void preprocess() {
		fio.set_output_float_digit(12);
	}
	istream &in() {
		fio.in(gn, gm);
		gg.resize(gn);
		fup_range (t, 0, gm) {
			int a, b;
			fio.in(a, b);
			a--, b--;
			gg.add(a, b);
		}
		ioend(1);
		return cin;
	}
	void deal() {
		auto bfs = [&]() {
			node *v;
			edge *e;
			queue<int> que;
			gg[0].meta.dist = 0;
			que.push(0);
			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (int ei : gg[u].link) {
					tie(v, e) = gg.extend(ei);
					if (gg[u].meta.dist + 1 < v->meta.dist) {
						v->meta.dist = gg[u].meta.dist + 1;
						que.push(v->id());
					}
				}
			}
		};
		function<void(int)> dfs = [&](int u) {
			node *v;
			edge *e;
			auto &mt = gg[u].meta;
			mt.ans = mt.dist;
			mt.vis = 1;
			for (int ei : gg[u].link) {
				tie(v, e) = gg.extend(ei);
				if (!v->meta.vis && mt.dist < v->meta.dist) {
					dfs(v->id());
				}
			}
			for (int ei : gg[u].link) {
				tie(v, e) = gg.extend(ei);
				if (mt.dist < v->meta.dist) {
					mt.ans = min(mt.ans, v->meta.ans);
				} else {
					mt.ans = min(mt.ans, v->meta.dist);
				}
			}
		};
		bfs();
		dfs(0);
	}
	void out() {
		fup_range (i, 0, gg.size())
			fio.msg("%d%c", gg[i].meta.ans, " \n"[i == gg.size() - 1]);
	}
public:
	task(
		bool multicase = 0,
		const char *fmt_case = 0,
		bool blankline = 0) {
		static int testcase = 1 << 30;
		preprocess();
		if (multicase)
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
#undef ioend
};

int main()
{
	new task(1);
	return 0;
}
