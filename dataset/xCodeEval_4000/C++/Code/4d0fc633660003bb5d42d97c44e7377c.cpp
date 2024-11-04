#define FAST_IO 1

#ifndef TEMPLATE_H
#define TEMPLATE_H

#pragma GCC optimize(2)
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
#include <utility>
#include <functional>
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
#ifdef linux
#include <ext/pb_ds/assoc_container.hpp>
#endif
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
#if 201103L <= __cplusplus
using std::move;
using std::forward;
using std::tuple;
using std::tie;
using std::get;
#endif
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
using std::bit_and;
using std::bit_or;
using std::bit_xor;
#if 201103L <= __cplusplus
using std::hash;
using std::mt19937;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
#endif
#ifdef linux
template<typename key>
using ordered_set = __gnu_pbds::tree<
						key, __gnu_pbds::null_type, less<key>, __gnu_pbds::rb_tree_tag,
						__gnu_pbds::tree_order_statistics_node_update>;
template<typename key, typename val>
using ordered_map = __gnu_pbds::tree<
						key, val, less<key>, __gnu_pbds::rb_tree_tag,
						__gnu_pbds::tree_order_statistics_node_update>;
#endif
#define fup_s(i, a, b, s) for (int i = a, foc = b; i <= foc; i += s)
#define fwn_s(i, a, b, s) for (int i = b, foc = a; foc <= i; i -= s)
#define fup_s2(i, lr, s) fup_s(i, lr, s)
#define fwn_s2(i, lr, s) fwn_s(i, lr, s)
#define fup(i, a, b) fup_s(i, a, b, 1)
#define fwn(i, a, b) fwn_s(i, a, b, 1)
#define fup2(i, lr) fup(i, lr)
#define fwn2(i, lr) fwn(i, lr)
#define fup_range(i, st, off) fup2(i, range(st, off))
#define fup_range_r(i, ed, off) fup2(i, range_r(ed, off))
#define fwn_range(i, st, off) fwn2(i, range(st, off))
#define fwn_range_r(i, ed, off) fwn2(i, range_r(ed, off))
#define it_each(obj) (obj).begin(), (obj).end()
#define it_i(obj, i) ((obj).begin() + (i))
#define it_i_rev(obj, i) ((obj).end() - 1 - (i))
#define it_seg(obj, l, r) it_i(obj, l), it_i(obj, r)
#define it_seg2(obj, lr) it_seg(obj, lr)
#define it_seg_rev(obj, l, r) it_i_rev(obj, r), it_i_rev(obj, l)
#define it_seg_rev2(obj, lr) it_seg_rev(obj, lr)
#define it_range(obj, st, off) it_seg2(obj, range(st, off))
#define it_range_r(obj, ed, off) it_seg2(obj, range_r(ed, off))
#define it_range_rev(obj, st, off) it_seg_rev2(obj, range(obj, st, off))
#define it_range_r_rev(obj, ed, off) it_seg_rev2(obj, range_r(obj, ed, off))
#define it_prefix(obj, i) (obj).begin(), it_i(obj, i)
#define it_suffix(obj, i) it_i(obj, i), (obj).end()
#define i_rev(len, i) ((len) - 1 - (i))
#define seg_rev2(len, lr) seg_rev(len, lr)
#define seg_rev(len, a, b) i_rev((len), (b)), i_rev((len), (a))
#define range(st, off) (st), ((st) + (off) - 1)
#define range_r(ed, off) ((ed) - (off) + 1), (ed)
#define range_rev(len, st, off) seg_rev2((len), range(st, off))
#define range_r_rev(len, ed, off) seg_rev2((len), range_r(ed, off))
#define finput(is, cls, obj) friend istream &operator >>(istream &is, cls &obj)
#define foutput(os, cls, obj) friend ostream &operator <<(ostream &os, const cls &obj)
#define vaddr(arr, index) &arr[(index)]
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
tp roundup_pow_of_2(tp x) { return x ? clo(x) << 1 : 0; }
template<typename tp>
tp rounddown_pow_of_2(tp x) { return x ? clo(x) : 0; }
template<typename tp>
bool is_power_of_2(tp x) { return x && !(x & (x - 1)); }
ll ltor(ll l, ll len) { return l + len - 1; }
ll rtol(ll r, ll len) { return r - len + 1; }
ll length(ll l, ll r) { return (r < l) ? 0 : r - l + 1; }
bool inrange(ll x, ll l, ll r) { return r < l ? 0 : l <= x && x <= r; }
#if 201103L <= __cplusplus
tuple<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)
#else
pair<ll, pair<ll, ll>> range_ins(ll lef_l, ll lef_r, ll rig_l, ll rig_r)
#endif
{
	if (lef_r < lef_l || rig_r < rig_l)
#if 201103L <= __cplusplus
		return make_tuple(0, make_pair(-1, -1));
#else
		return make_pair(0, make_pair(-1, -1));
#endif
	if (lef_r < rig_l || rig_r < lef_l)
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
	return make_tuple(
			min(length(lef_l, rig_r), length(rig_l, lef_r)),
			make_pair(max(lef_l, rig_l), min(lef_r, rig_r)));
#endif
}


ll midpoint(ll l, ll r) { return l + (length(l, r) >> 1); }
template<typename tp>
void range_normalize(tp &l, tp &r) { if (r < l) swap(l, r); }

template<typename tp, class func_cmp = less<tp>>
#if 201103L <= __cplusplus
tuple<bool, pair<ll, tp>> binary_search(
		const vector<tp> &v, ll lo, ll hi, tp key, bool dir, bool contain)
#else
pair<bool, pair<ll, tp>> binary_search(
		const vector<tp> &v, ll lo, ll hi, tp key, bool dir, bool contain)
#endif
{
#define look(cond) if ((cond)) lo = mid + 1; else hi = mid - 1;
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
#if 201103L <= __cplusplus
	return make_tuple(found, make_pair(fd_index, fd_value));
#else
	return make_pair(found, make_pair(fd_index, fd_value));
#endif
#undef look
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
tp presum_range(const vector<tp> &sum, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = sum.size() - 1;
	return sum[r] - special(0, sum, l - 1, m1, m2);
}
template<typename tp>
void presum_preprocess(
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
tp premul_range(const vector<tp> &mul, int l, int r, int m1 = -1, int m2 = -1)
{
	if (!~m1 || !~m2)
		m1 = 0, m2 = mul.size() - 1;
	return mul[r] / special(1, mul, l - 1, m1, m2);
}
template<typename tp>
void premul_preprocess(
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
ull div_roundup(ull x, ull div) { return (x + div - 1) / div; }
ull div_rounddown(ull x, ull div) { return x / div; }
ull div_last_offset(ull x, ull div) { return div_rounddown(x - 1, div); }
ll round_shift(ll x, ll dist, ll l, ll r)
{
	int len = length(l, r);
	return (x - l + dist + len) % len + l;
}

class direct_io {
	static const int bsz = 1 << 20;
	char ibuf[bsz], obuf[bsz], *ihead, *itail, *ohead;
	streambuf *isb, *osb;
	int output_float_digit;
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
#if 201103L <= __cplusplus
		if (std::is_same<typename std::decay<tp>::type, double>::value)
#else
		if (tp(x + 0.5) != x)
#endif
		{
			putchar('.');
			x -= ll(x);
			fup (t, 1, output_float_digit) {
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
		output_float_digit = 12;
		status = 1;
	}
	~direct_io() { osb->sputn(obuf, ohead - obuf); }
	bool ok() {
		return status;
	}
	void set_output_float_digit(int d) {
		output_float_digit = d;
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
		for (; ~ch && ch ^ delim; ch = getchar())
			line += ch;
		return 1;
#else
		getline(cin, line, delim);
		return !cin.fail();
#endif
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
		static char buf[1 << 10];
		va_list args;
		va_start(args, fmt);
		vsprintf(buf, fmt, args);
		va_end(args);
		out((const char *)buf);
	}
} fio;
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
#if 201103L <= __cplusplus
	template<typename ...var>
	void operator ()(var &&...args) {
		initializer_list<int>{(print(forward<var>(args)), 0)...};
		cerr << '\n';
	}
#endif
	void msg(const char *fmt, ...) {
		static char buf[1 << 10];
		va_list args;
		va_start(args, fmt);
		vsprintf(buf, fmt, args);
		va_end(args);
		cerr << buf << '\n';
	}
} bug;
#if 201103L <= __cplusplus
template<typename tp>
class zip {
public:
	int tot;
	vector<tp> data;
	vector<int> dim;
	zip(const vector<int> &v) {
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
#endif
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
	vector<tp *> mem;
	queue<tp *> cache;
public:
	allocator() { mem.reserve(pon); }
	tp *operator ()() {
		tp *ret;
		if (cache.empty()) {
			mem.push_back(new tp());
			ret = mem.back();
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
		mem.clear();
		fup_range (i, 0, mem.size())
			delete mem[i];
		while (!cache.empty())
			cache.pop();
	}
};

#endif

class task {
#define ioend(cond) \
	do {\
		if (!(cond) || !fio.ok()) { cin.setstate(ios_base::badbit); return cin; }\
	} while(0)
	int n, ans;
	vector<int> data;
	void preprocess() {
		fio.set_output_float_digit(12);
	}
	istream &in() {
		fio.in(n);
		data.resize(n);
		fup_range (i, 0, n)
			fio.in(data[i]);
		ioend(1);
		return cin;
	}
	void deal() {
		int vmx = *max_element(it_each(data));
		vector<vector<int>> occ;
		zip<int> psum{{vmx + 5, n + 5}};
		occ.assign(vmx + 1, vector<int>());
		fup_range (i, 0, n) {
			int x = data[i];
			occ[x].push_back(i);
			psum(x, i) = 1;
		}
		fup (x, 1, vmx) {
			if (!occ[x].size())
				continue;
			presum_preprocess(
					psum.data, psum.index(x, 0), psum.index(x, n - 1),
					psum.data, psum.index(x, 0),
					psum.index(x, 0), psum.index(x, n - 1));
		}
		ans = 0;
		fup (x, 1, vmx) {
			int occsz = occ[x].size();
			if (!occsz)
				continue;
			ans = max(ans, psum(x, n - 1));
			fup (k, 1, occsz) {
				if (occsz < k * 2)
					break;
				int cc, pos[2];
				pos[0] = occ[x][k - 1];
				pos[1] = occ[x][i_rev(occsz, k - 1)];
				if (!length(pos[0] + 1, pos[1] - 1))
					continue;
				fup (y, 1, vmx) {
					if (!occ[y].size())
						continue;
					cc = presum_range(psum.data, psum.index(y, pos[0] + 1), psum.index(y, pos[1] - 1),
							psum.index(y, 0), psum.index(y, n - 1));
					ans = max(ans, cc + k * 2);
				}
			}
		}
	}
	void out() {
		fio.out(ans, '\n');
	}
public:
	task(
		bool multicase = 0,
		bool testid = 0,
		bool blankline = 0) {
		static int testcase = 1 << 30;
		static stringstream tid;
		preprocess();
		if (multicase)
			fio.in(testcase);
		for (int ti = 1; ti <= testcase && in(); ++ti) {
			deal();
			if (blankline && 1 < ti)
				fio.out('\n');
			if (testid) {
				tid << "Case #" << ti << ": ";
				fio.out(tid.str());
				tid.str("");
			}
			out();
		}
	}
#undef ioend
} gkd(1, 0, 0);

int main()
{
	return 0;
}