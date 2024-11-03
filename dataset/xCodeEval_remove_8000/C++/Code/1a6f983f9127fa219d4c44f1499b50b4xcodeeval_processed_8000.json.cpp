

















































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
using std::tie;
using std::get;

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







































typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;
const double pi = acos(-1);
const double eps = 1e-6;
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
tp id0(tp x) { return x ? clo(x) << 1 : 0; }
template<typename tp>
tp id12(tp x) { return x ? clo(x) : 0; }
template<typename tp>
bool id11(tp x) { return x && !(x & (x - 1)); }
ll ltor(ll l, ll len) { return l + len - 1; }
ll rtol(ll r, ll len) { return r - len + 1; }
ll length(ll l, ll r) { return (r < l) ? 0 : r - l + 1; }
bool inrange(ll x, ll l, ll r) { return r < l ? 0 : l <= x && x <= r; }

tuple<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)

pair<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)

{
	if (lef_r < lef_l || rig_r < rig_l)

		return make_tuple(0, make_pair(-1, -1));

		return make_pair(0, make_pair(-1, -1));

	if (lef_r < rig_l || rig_r < lef_l)

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

	return make_tuple(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));

}


ll midpoint(ll l, ll r) { return l + (length(l, r) >> 1); }
template<typename tp>
void id9(tp &l, tp &r) { if (r < l) swap(l, r); }

template<typename tp, class func_cmp = less<tp>>

tuple<bool, pair<ll, tp>> binary_search(
		const vector<tp> &v, ll lo, ll hi, tp key, bool dir, bool contain)

pair<bool, pair<ll, tp>> binary_search(
		const vector<tp> &v, ll lo, ll hi, tp key, bool dir, bool contain)

{

	assert(lo <= hi);
	func_cmp cmp = func_cmp();
	ll locp = lo, hicp = hi, fd_index = -1;
	tp fd_value;
	bool found = 0;
	while (lo <= hi) {
		int mid = midpoint(lo, hi), now = v[mid];
		look((!dir && cmp(now, key)) || (dir && !cmp(key, now)));
	}
	int pos = dir ^ contain ? lo : hi;
	if (inrange(pos, locp, hicp)) {
		found = 1;
		fd_value = v[fd_index = pos];
	}

	return make_tuple(found, make_pair(fd_index, fd_value));

	return make_pair(found, make_pair(fd_index, fd_value));


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
template<typename tp>
tp id10(const tp *sum, int len, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = len - 1;
	return sum[r] - special(0, sum, len, l - 1, m1, m2);
}
template<typename tp>
tp id10(const vector<tp> &sum, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = sum.size() - 1;
	return sum[r] - special(0, sum, l - 1, m1, m2);
}
template<typename tp>
void id3(
						const tp *src, int l, int r,
						tp *dest, int len, int st, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = len - 1;
	for (int di = st, si = l; si <= r; ++si, ++di)
		dest[di] = special(0, dest, len, di - 1, m1, m2) + src[si];
}
template<typename tp>
void id3(
						const vector<tp> &src, int l, int r,
						vector<tp> &dest, int st, int m1 = -1, int m2 = -1)
{
	int len = length(l, r);
	if (dest.size() < st + len)
		dest.resize(st + len);
	if (!~m1 || !~m2)
		m1 = 0, m2 = dest.size() - 1;
	for (int di = st, si = l; si <= r; ++si, ++di)
		dest[di] = special(0, dest, di - 1, m1, m2) + src[si];
}
template<typename tp>
tp id6(const tp *mul, int len, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = len - 1;
	return mul[r] / special(1, mul, len, l - 1, m1, m2);
}
template<typename tp>
tp id6(const vector<tp> &mul, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = mul.size() - 1;
	return mul[r] / special(1, mul, l - 1, m1, m2);
}
template<typename tp>
void id7(
						const tp *src, int l, int r,
						tp *dest, int len, int st, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = len - 1;
	for (int di = st, si = l; si <= r; ++si, ++di)
		dest[di] = special(1, dest, len, di - 1, m1, m2) * src[si];
}
template<typename tp>
void id7(
						const vector<tp> &src, int l, int r,
						vector<tp> &dest, int st, int m1 = -1, int m2 = -1)
{
	int len = length(l, r);
	if (dest.size() < st + len)
		dest.resize(st + len);
	if (!~m1 || !~m2)
		m1 = 0, m2 = dest.size() - 1;
	for (int di = st, si = l; si <= r; ++si, ++di)
		dest[di] = special(1, dest, di - 1, m1, m2) * src[si];
}
ull id13(ull x, ull div) { return (x + div - 1) / div; }
ull id4(ull x, ull div) { return x / div; }
ull id8(ull x, ull div) { return id4(x - 1, div); }
ll round_shift(ll x, ll dist, ll l, ll r)
{
	int len = length(l, r);
	return (x - l + dist + len) % len + l;
}

class direct_io {
	static const int bsz = 1 << 20;
	char ibuf[bsz], obuf[bsz], *ihead, *itail, *ohead;
	streambuf *isb, *osb;
	int id2;
	bool status;
	void set_status(bool ok) {
		status = ok;
	}
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
		*s++ = 0;
	}
	void input(string &s) {
		s.clear();
		char ch;
		input(ch);
		if (!ok())
			return;
		do {
			s += ch;
		} while (ch = getchar(), isgraph(ch));
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
		fup_range (i, 0, s.length()) {
			char ch = s[i];
			putchar(ch);
		}
	}
	template<typename tp>
	void output(tp x) {
		static char buf[1 << 8];
		int cnt = 0;
		ll xn = ll(x);
		if (xn < 0)
			putchar('-'), xn = -xn;
		do {
			buf[++cnt] = xn % 10 | 48;
			xn /= 10;
		} while (xn);
		while (cnt)
			putchar(buf[cnt--]);

		if (std::is_same<typename std::decay<tp>::type, double>::value)

		if (tp(x + 0.5) != x)

		{
			putchar('.');
			x -= ll(x);
			fup (t, 1, id2) {
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
		ihead = itail = 0;
		ohead = obuf;
		id2 = 12;
		status = 1;
	}
	~direct_io() { osb->sputn(obuf, ohead - obuf); }
	bool ok() {
		return status;
	}
	void set_output_float_digit(int d) {
		id2 = d;
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
		for (; ~ch && ch ^ delim; ch = getchar())
			line += ch;
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
		static char buf[1 << 10];
		va_list args;
		va_start(args, fmt);
		vsprintf(buf, fmt, args);
		va_end(args);
		out((const char *)buf);
	}
};
class debuger {
	string delim;
	template<typename tp>
	void print(const tp &x) { cerr << x << delim; }
	template<typename tp>
	void print(const vector<tp> &v) {
		fup_range (i, 0, v.size()) {
			tp x = v[i];
			cerr << x << delim;
		}
	}
public:
	debuger(string s = " ") : delim(s) {}

	template<typename ...var>
	void operator ()(var &&...args) {
		initializer_list<int>{(print(forward<var>(args)), 0)...};
		cerr << '\n';
	}

	void msg(const char *fmt, ...) {
		static char buf[1 << 10];
		va_list args;
		va_start(args, fmt);
		vsprintf(buf, fmt, args);
		va_end(args);
		cerr << buf << '\n';
	}
};

template<typename tp>
class zip_vector {
public:
	int tot;
	vector<tp> data;
	vector<int> dim;
	zip_vector(const vector<int> &v) {
		dim.resize(v.size());
		copy(it_each(v), dim.begin());
		tot = 1;
		fwn (i, 0, dim.size() - 1) {
			int suf = tot;
			tot *= dim[i];
			dim[i] = suf;
		}
		data.resize(tot);
	}
	template<typename ...var>
	tp &operator ()(var &&...args) {
		return data[index(args...)];
	}
	template<typename ...var>
	int index(var &&...args) {
		assert(sizeof...(args) == dim.size());
		int idx = 0;
		auto it = dim.begin();
		auto product = [&](int val) {
			idx += *it++ * val;
		};
		initializer_list<int>{(product(forward<var>(args)), 0)...};
		return idx;
	}
	vector<tp> dimension(int idx) {
		assert(inrange(idx, 0, tot - 1));
		vector<tp> ret(dim.size());
		fup (i, 0, ret.size() - 1) {
			ret[i] = idx / dim[i];
			idx -= ret[i] * dim[i];
		}
		return ret;
	}
};
template<typename tp>
class id5 {
public:
	int tot;
	valarray<tp> data;
	valarray<int> dim;
	id5(const vector<int> &v) {
		dim.resize(v.size());
		copy(it_each(v), begin(dim));
		tot = 1;
		fwn (i, 0, dim.size() - 1) {
			int suf = tot;
			tot *= dim[i];
			dim[i] = suf;
		}
		data.resize(tot);
	}
	template<typename ...var>
	tp &operator ()(var &&...args) {
		return data[index(args...)];
	}
	template<typename ...var>
	int index(var &&...args) {
		assert(sizeof...(args) == dim.size());
		int idx = 0;
		auto it = begin(dim);
		auto product = [&](int val) {
			idx += *it++ * val;
		};
		initializer_list<int>{(product(forward<var>(args)), 0)...};
		return idx;
	}
	vector<tp> dimension(int idx) {
		assert(inrange(idx, 0, tot - 1));
		vector<tp> ret(dim.size());
		fup (i, 0, ret.size() - 1) {
			ret[i] = idx / dim[i];
			idx -= ret[i] * dim[i];
		}
		return ret;
	}
};

template<typename tp>
class descrete {
	vector<tp> data;
public:
	descrete(vector<tp> &v) {
		data.assign(it_each(v));
		sort(it_each(data));
		data.erase(unique(it_each(data)), data.end());
		fup_range (i, 0, data.size()) {
			tp &x = data[i];
			x = lower_bound(it_each(data), x) - data.begin();
		}
	}
	tp get(int i) {
		return data[i];
	}
};
template<typename tp, size_t pon = 0>
class allocator {
	int cur;
	vector<tp> mem;
	queue<tp *> cache;
public:
	allocator() {
		cur = 0;
		mem.reserve(pon);
	}
	tp *operator ()() {
		tp *ret;
		if (cache.empty()) {
			if (mem.size() <= cur)
				mem.push_back(tp());
			ret = &mem[cur++];
		} else {
			ret = cache.front();
			cache.pop();
		}
		return ret;
	}
	void operator ()(tp *o) {
		cache.push(o);
	}
	void clear() {
		cur = 0;
		while (!cache.empty())
			cache.pop();
	}
};



class task {

	do {\
		if (!(cond) || !fio.ok()) { cin.setstate(ios_base::badbit); return cin; }\
	} while(0)
	direct_io fio;
	debuger bug;
	int n, k;
	bitset<1000> index[1023];
	void preprocess() {
		fio.set_output_float_digit(12);
	}
	istream &in() {
		ioend(1);
		return cin;
	}
	int query(bitset<1000> &bs) {
		int x;
		assert(bs.count() != 0);
		fio.out("? ", bs.count());
		fup_range (i, 0, n)
			if (bs[i])
				fio.out(' ', i + 1);
		fio.out('\n');
		cout.flush();
		fio.in(x);
		return x;
	}
	bool interactive() {
		int m2, l, r, mx;
		string ac;
		fio.in(n, k);
		fup_range (i, 0, k) {
			int len;
			fio.in(len);
			index[i].reset();
			fup_range (t, 0, len) {
				int x;
				fio.in(x);
				index[i].set(x - 1);
			}
		}
		bitset<1000> all;
		fup_range (i, 0, n)
			all.set(i);
		m2 = query(all);
		l = 0;
		r = k - 1;
		while (2 <= length(l, r)) {
			int m = midpoint(l, r);
			bitset<1000> que;
			fup (i, l, m - 1)
				que |= index[i];
			mx = query(que);
			if (mx == m2)
				r = m - 1;
			else
				l = m;
		}
		bitset<1000> second = all ^ index[l];
		mx = query(second);
		fio.out("!");
		fup_range (i, 0, k)
			if (i == l)
				fio.out(' ', mx);
			else
				fio.out(' ', m2);
		fio.out('\n');
		cout.flush();
		fio.in(ac);
		return 1;
	}
public:
	task(
		bool id1 = 0,
		bool testid = 0,
		bool blankline = 0) {
		static int testcase = 1 << 30;
		static stringstream tid;
		preprocess();
		if (id1)
			fio.in(testcase);
		for (int ti = 1; ti <= testcase && in(); ++ti)
			interactive();
	}

} gkd(1, 0, 0);

int main()
{
	return 0;
}
