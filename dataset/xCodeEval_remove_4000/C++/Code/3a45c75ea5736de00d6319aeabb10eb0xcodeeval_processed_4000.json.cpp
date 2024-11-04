















































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

using std::move;
using std::forward;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
using std::ignore;

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
using std::iterator_traits;
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

template<typename tp>
tp midpoint(tp l, tp r) {
	return (l | r) - ((l ^ r) >> 1);
}
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
		if (x < 0)
			putchar('-');
		ll xn = x < 0 ? ll(-x) : ll(x);
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
			if (x < 0)
				x *= -1;
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

		cout.precision(id3);

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
		if (ch == delim)
			return 1;
		g_cur = g_buf;
		for (; ~ch && ch ^ delim; ch = getchar())
			*g_cur++ = ch;
		*g_cur = 0;
		line.assign(g_buf);
		return 1;

		getline(cin, line, delim);
		return !cin.fail();

	}
	bool readline_noblank(string &line, char delim = '\n') {
		bool ret;
		do {
			if (!(ret = readline(line, delim)))
				return ret;
		} while (!line.size());
		return ret;
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




template<typename tp, class func_cmp = less<tp>>
tuple<bool, pair<ll, tp>> binary_search(
		const vector<tp> &v, ll lo, ll hi, tp key, bool dir, bool contain)
{

	assert(lo <= hi);
	func_cmp cmp = func_cmp();
	ll locp = lo, hicp = hi, fd_index = -1;
	tp fd_value;
	bool found = 0;
	while (lo <= hi) {
		int mid = midpoint(lo, hi);
		tp now = v[mid];
		look((!dir && cmp(now, key)) || (dir && !cmp(key, now)));
	}
	int pos = dir ^ contain ? lo : hi;
	if (inrange(pos, locp, hicp)) {
		found = 1;
		fd_value = v[fd_index = pos];
	}
	return make_tuple(found, make_pair(fd_index, fd_value));

}



class task {

	do {\
		if (!(cond) || !fio.ok()) { cin.setstate(ios_base::badbit); return cin; }\
	} while(0)
	int gn, gm, ans;
	vector<pair<int, int>> da;
	void preprocess() {
		fio.set_output_float_digit(12);
	}
	istream &in() {
		fio.in(gn, gm);
		da.resize(gn);
		fup_range (i, 0, gn)
			fio.in(da[i].first);
		fup_range (i, 0, gn)
			fio.in(da[i].second);
		ioend(1);
		return cin;
	}
	void deal() {
		vector<ll> psum[2];
		ll tsum;
		for (auto &o : da) {
			if (o.second == 1) {
				psum[0].push_back(o.first);
			} else {
				psum[1].push_back(o.first);
			}
		}
		tsum = 0;
		fup_range (g, 0, 2) {
			sort(it_each(psum[g]));
			reverse(it_each(psum[g]));
			tsum += accumulate(it_each(psum[g]), 0ll);
			partial_sum(it_each(psum[g]), psum[g].begin());
		}
		if (tsum < gm) {
			ans = -1;
			return;
		}
		ans = inf32;
		if (!psum[0].empty() && !psum[1].empty()) {
			fup_range (i, 0, psum[0].size()) {
				ll s0 = psum[0][i], lef = max(0ll, gm - s0);
				if (!lef) {
					ans = min(ans, (i + 1));
					continue;
				}
				auto fd = binary_search<ll>(psum[1], 0, psum[1].size() - 1, lef, 0, 1);
				if (get<0>(fd))
					ans = min(ans, int((i + 1) + (get<1>(fd).first + 1) * 2));
			}
		}
		if (!psum[0].empty()) {
			auto fd = binary_search<ll>(psum[0], 0, psum[0].size() - 1, gm, 0, 1);
			if (get<0>(fd))
				ans = min(ans, int(get<1>(fd).first + 1));
		}
		if (!psum[1].empty()) {
			auto fd = binary_search<ll>(psum[1], 0, psum[1].size() - 1, gm, 0, 1);
			if (get<0>(fd))
				ans = min(ans, int(get<1>(fd).first + 1) * 2);
		}
	}
	void out() {
		fio.msg("%d\n", ans);
	}
public:
	task(
		bool id2 = 0,
		const char *fmt_case = 0,
		bool blankline = 0) {
		static int testcase = 1 << 30;
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
