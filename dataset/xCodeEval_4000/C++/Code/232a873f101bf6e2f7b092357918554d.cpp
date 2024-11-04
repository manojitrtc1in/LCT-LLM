#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define F(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define f(i, a, b) for(int i = (int)a; i >= (int)b; i--)
#define Fk(k, i, a, b) for(int i = (int)a; i <= (int)b; i += k)
#define fk(k, i, a, b) for(int i = (int)a; i >= (int)b; i -= k)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define strans int tm = (tl + tr)>>1
#define trans int tm = (tl + tr)>>1, l = v<<1, r = l|1
#define STL l, tl, tm, ql, min(qr, tm)
#define STR r, tm + 1, tr, max(ql, tm + 1), qr
#define STqseg v, int tl, int tr, int ql, int qr
#define STqmtch ql == tl && tr == qr
#define STqp v, int tl, int tr, int i
#define by(field) [](const auto& lhs, const auto& rhs) { return lhs.field < rhs.field; }
#define dby(field) [](const auto& lhs, const auto& rhs) { return lhs.field > rhs.field; }
#define all(x) (x).begin(), (x).end()
template <typename value_type, typename relax_type = value_type, typename predictor = less<value_type>>
void relax_pred(value_type& val, const relax_type& rel) { static predictor pred; if (pred(val, rel)) val = rel; }
template <typename type>
void relax_min(type& val, const type& rel) { relax_pred<type, type, greater<type>>(val, rel); }
template <typename type>
void relax_max(type& val, const type& rel) { relax_pred<type, type, less<type>>(val, rel); }
ld const PI = acos(-1);


#ifndef LIB_IO_H
#define LIB_IO_H

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <array>
                         








#ifdef USE_ENDL
#define NLINE std::endl
#else
#define NLINE '\n'
#endif

namespace io {

#ifdef LOGGING
ofstream logger_("log", ios::out);
#endif

template <typename iter_t>
void sread_seq(std::istream& in, iter_t begin, iter_t end) {
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

int sread_int(std::istream& in) {
  int res;
  in >> res;
  return res;	
}

long long read_ll() {
	long long res;
	std::cin >> res;
	return res;
}

long long sread_ll(std::istream& in) {
	long long res;
	in >> res;
	return res;
}

unsigned long long read_ull() {
	unsigned long long res;
	std::cin >> res;
	return res;
}

unsigned long long sread_ull(std::istream& in) {
	unsigned long long res;
	in >> res;
	return res;
}

char read_char() {
	char c;
	std::cin >> c;
	return c;	
}

char sread_char(istream& in) {
	char c;
	in >> c;
	return c;	
}

std::string read_str() {
	std::string str;
	std::cin >> str;
	return str;	
}

std::string sread_str(istream& in) {
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
void sprint_seq(std::ostream& out, iter_t begin, iter_t end) {
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
void sprintln_seq(std::ostream& out, iter_t begin, iter_t end) {
	sprint_seq(out, begin, end);
	out << NLINE;
}

template <typename... types>
void LOG(types&&... values) {
	#ifdef LOGGING
	sprint(logger_, std::forward<types>(values)...);
	#endif
}

template <typename... types>
void LOGln(types&&... values) {
	#ifdef LOGGING
	sprintln(logger_, std::forward<types>(values)...);
	#endif
}


#define NLOG1(a) LOGln(#a" =", a)
#define NLOG2(a, b) LOGln(#a" =", a, "| "#b" =", b)
#define NLOG3(a, b, c) LOGln(#a" =", a, "| "#b" =", b, "| "#c" =", c)
#define NLOG4(a, b, c, d) LOGln(#a" =", a, "| "#b" =", b, "| "#c" =", c, "| "#d" =", d)
#define NLOG5(a, b, c, d, e) LOGln(#a" =", a, "| "#b" =", b, "| "#c" =", c, "| "#d" =", d, "| "#e" =", e)


#define EMPTY(...)
#define DEFER(...) __VA_ARGS__ EMPTY()

#define SECOND(a, b, ...) LOG_##b

#define LOG_3() LOG_0
#define LOG_2() LOG_1
#define LOG_0(...)
#define LOG_1(a, ...) logger_ << #a << ": " << a << ",   "; DEFER(SECOND(__VA_OPT__(,) 2, 3))()(__VA_ARGS__)

#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

#define NLOG(...) EVAL(LOG_1(__VA_ARGS__)); logger_ << "\n";

template <typename iter_t>
void LOG_seq(iter_t begin, iter_t end) {
	#ifdef LOGGING
	sprintln_seq(logger_, begin, end);
	#endif
}




template <typename F, typename S>
std::istream operator>>(std::istream& in, std::pair<F, S>& value) {
	return in >> value.first >> value.second;
}

template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::pair<F, S>& value) {
	#ifdef HUMAN_READABLE
	return out << "(" << value.first << ", " << value.second << ")";
	#else
	return out << value.first << ' ' << value.second;
	#endif
}

template <typename iter_t>
std::ostream& stl_container_print_impl(std::ostream& out, iter_t begin, iter_t end) {
	#ifndef HUMAN_READABLE
	sprint_seq(out, begin, end);
	return out;
	#else
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
	#endif
}

template<typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& value) {
	sread_seq(in, value.begin(), value.end());
	return in;
}
template<typename T, size_t capacity>
std::istream& operator>>(std::istream& in, std::array<T, capacity>& value) {
	sread_seq(in, value.begin(), value.end());
	return in;
}
template<typename T>
std::istream& operator>>(std::istream& in, std::deque<T>& value) {
	sread_seq(in, value.begin(), value.end());
	return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
	return stl_container_print_impl(out, value.begin(), value.end());
}
template <typename T, size_t capacity>
std::ostream& operator<<(std::ostream& out, const std::array<T, capacity>& value) {
	return stl_container_print_impl(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& value) {
	return stl_container_print_impl(out, value.begin(), value.end());
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& value) {
	return stl_container_print_impl(out, value.begin(), value.end());
}
template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::map<F, S>& value) {
	return stl_container_print_impl(out, value.begin(), value.end());
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
				#ifdef HUMAN_READABLE
				out << ", ";
				#else
				out << ' ';
				#endif
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
	#ifdef HUMAN_READABLE 
	out << "(";
	#endif
	tuple_io_impl<0, types...>::print(out, value);
	#ifdef HUMAN_READABLE
	out << ")";
	#endif
	return out;		
}

} 


#endif 

using namespace io;











int const N = 1e5 + 4;

struct node {
	node* l = nullptr;
	node* r = nullptr;
	int prior, sz = 1;
	ll val, sum;
} nodes[N];

ll get_sum(node* v) {
	return v ? v->sum : 0ll;
}

int get_sz(node* v) {
	return v ? v->sz : 0;
}

void recalc(node* v) {
	if (v) {
		v->sz = 1 + get_sz(v->l) + get_sz(v->r);
		v->sum = get_sum(v->l) + get_sum(v->r) + v->val;
	}
}

node* merge(node* l, node* r) {
	if (!l || !r) {
		return l ? l : r;
	}	
	if (l->prior > r->prior) {
		l->r = merge(l->r, r);
		recalc(l);
		return l;
	} 
	r->l = merge(l, r->l);
	recalc(r);
	return r;
}

pair<node*, node*> split_sum(node* v, ll pivot) {
	if (!v) {
		return {nullptr, nullptr};
	}	
	ll rsum = get_sum(v->r);
	if (rsum >= pivot) {
		auto [l, r] = split_sum(v->r, pivot);	
		v->r = l;
		recalc(v);
		return {v, r};
	}
	auto [l, r] = split_sum(v->l, pivot - rsum - v->val);
	v->l = r;
	recalc(v);
	return {l, v};
}

pair<node*, node*> cut_first(node* v) {
	if (v->l) {
		auto [ans, tmp] = cut_first(v->l);
		v->l = tmp;
		recalc(v);
		return {ans, v};
	}
	node* r = v->r;
	v->r = nullptr;
	recalc(v);
	return {v, r};
}

void rprint_tree(node* v) {
	if (v) {
		rprint_tree(v->l);
		sprint(cerr, v->val, "");
		rprint_tree(v->r);
	}
}

void print_tree(node* v) {
	rprint_tree(v);
	sprintln(cerr);
}

ll solve() {
	int n = read_int();	
	ll to_add = 0, ans = 0;
	mt19937 rnd(time(0));
	ll a1 = read_ll();
	if (a1 < 0) {
		return -1;
	}
	if (n == 1) {
		return 0;
	}
	nodes[0].prior = rnd();
	nodes[0].val = nodes[0].sum = a1;
	node* root = nodes;
	F(i, 1, n - 2) {
		node* v = nodes + i;
		v->prior = rnd();
		ll x = read_ll() + to_add;
		to_add = 0;
		if (x < 0) {
			if (get_sum(root) + x < 0) {
				return -1;		
			}
			auto [pref, tmp] = split_sum(root, -x);
			to_add = x;
			int sz = get_sz(tmp);
			ans += sz;
			

			if (sz == 1) {
				tmp->val += x;
				tmp->sum += x;
				v->val = v->sum = -x;
				root = merge(pref, merge(tmp, v));
			} else {
				ll sum = get_sum(tmp) + x;
				auto [fi, mid] = cut_first(tmp);
				v->val = v->sum = fi->val - sum;
				fi->val = fi->sum = sum;
				root = merge(merge(pref, fi), merge(v, mid));
			}
		} else {
			v->val = v->sum = x;
			root = merge(root, v);
		}
		

		

	}
	ll an = read_ll() + to_add;
	return an < 0 ? -1 : ans;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	int t = 1;
	

	

	while (t--) {
		println(solve());
	}   
	return 0;
}       		