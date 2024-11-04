
using namespace std;

template<class T = long long> struct point{
	T x, y;
	int ind;
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y), ind(otr.ind){ }
	template<class U = T, class V = T> point(U x = 0, V y = 0, int ind = -1): x(x), y(y), ind(ind){ }
	template<class U> explicit operator point<U>() const{ return point<U>(static_cast<U>(x), static_cast<U>(y)); }
	T operator*(const point &otr) const{ return x * otr.x + y * otr.y; }
	T operator^(const point &otr) const{ return x * otr.y - y * otr.x; }
	point operator+(const point &otr) const{ return {x + otr.x, y + otr.y}; }
	point &operator+=(const point &otr){ return *this = *this + otr; }
	point operator-(const point &otr) const{ return {x - otr.x, y - otr.y}; }
	point &operator-=(const point &otr){ return *this = *this - otr; }
	point operator-() const{ return {-x, -y}; }

	scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)

	scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)

	scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)

	compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)




	double norm() const{ return sqrt(x * x + y * y); }
	T squared_norm() const{ return x * x + y * y; }
	double arg() const{ return atan2(y, x); } 

	point<double> unit() const{ return point<double>(x, y) / norm(); }
	point perp() const{ return {-y, x}; }
	point<double> normal() const{ return perp().unit(); }
	point<double> rotate(const double &theta) const{ return point<double>(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
	point reflect_x() const{ return {x, -y}; }
	point reflect_y() const{ return {-x, y}; }
	point reflect(const point &o) const{ return {2 * o.x - x, 2 * o.y - y}; }
	bool operator||(const point &otr) const{ return !(*this ^ otr); }
};
template<class T> istream &operator>>(istream &in, point<T> &p){ return in >> p.x >> p.y; }
template<class T> ostream &operator<<(ostream &out, const point<T> &p){ return out << "(" << p.x << ", " << p.y << ")"; }
template<class T> double distance(const point<T> &p, const point<T> &q){ return (p - q).norm(); }
template<class T> T id9(const point<T> &p, const point<T> &q){ return (p - q).squared_norm(); }
template<class T, class U, class V> T ori(const point<T> &p, const point<U> &q, const point<V> &r){ return (q - p) ^ (r - p); }
template<class IT> auto id0(IT begin, IT end){
	class iterator_traits<IT>::value_type s = 0, init = *begin;
	for(; begin != prev(end); ++ begin) s += *begin ^ *next(begin);
	return s + (*begin ^ init);
}
template<class T> bool is_sorted(const point<T> &origin, point<T> p, point<T> q, point<T> r){
	p -= origin, q -= origin, r -= origin;
	T x = p ^ r, y = p ^ q, z = q ^ r;
	return x >= 0 && y >= 0 && z >= 0 || x < 0 && (y >= 0 || z >= 0);
}
template<class T, class IT> bool is_sorted(const point<T> &origin, IT begin, IT end){
	for(int i = 0; i < end - begin - 2; ++ i) if(!is_sorted(origin, begin + i, begin + i + 1, begin + i + 2)) return false;
	return true;
}
template<class T = long long> struct line{
	point<T> p, d; 

	template<class U = T, class V = T> line(point<U> p = {0, 0}, point<V> q = {0, 0}, bool id5 = true): p(p), d(id5 ? q - p : q){ }
	template<class U> line(point<U> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<class U> explicit operator line<U>() const{ return line<U>(point<U>(p), point<U>(d), false); }
	point<T> q() const{ return p + d; }
	bool degen() const{ return d == point<T>(); }
	tuple<T, T, T> coef() const{ return {d.y, -d.x, d.perp() * p}; } 

	bool operator||(const line<T> &L) const{ return d || L.d; }
};
template<class T> bool on_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	return (p - L.p) || L.d;
}
template<class T> bool on_ray(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * L.d <= 0;
}
template<class T> bool on_segment(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * b <= 0;
}
template<class T> double id11(const point<T> &p, const line<T> &L){
	if(L.degen()) return distance(p, L.p);
	return abs((p - L.p) ^ L.d) / L.d.norm();
}
template<class T> double id1(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	return id11(p, L);
}
template<class T> double id7(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	if((p - L.q()) * L.d >= 0) return distance(p, L.q());
	return id11(p, L);
}
template<class T> point<double> projection(const point<T> &p, const line<T> &L){ return static_cast<point<double>>(L.p) + (L.degen() ? point<double>() : (p - L.p) * L.d / L.d.norm() * static_cast<point<double>>(L.d)); }
template<class T> point<double> reflection(const point<T> &p, const line<T> &L){ return 2.0 * projection(p, L) - static_cast<point<double>>(p); }
template<class T> point<double> id15(const point<T> &p, const line<T> &L){ return (p - L.p) * L.d <= 0 ? static_cast<point<double>>(L.p) : ((p - L.q()) * L.d >= 0 ? static_cast<point<double>>(L.q()) : projection(p, L)); }
template<int TYPE> struct EndpointChecker{ };


template<> struct EndpointChecker<0>{ template<class T> bool operator()(const T& a, const T& b) const{ return true; } }; 



template<> struct EndpointChecker<1>{ template<class T> bool operator()(const T& a, const T& b) const{ return a <= b; } }; 



template<> struct EndpointChecker<2>{ template<class T> bool operator()(const T& a, const T& b) const{ return a < b; } }; 



template<int LA, int LB, int RA, int RB, class T> pair<bool, point<double>> id14(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d;
	if(!s) return {false, point<double>()};
	auto ls = (M.p - L.p) ^ M.d, rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) && EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
	return {intersect, static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d)};
}


template<class T> pair<bool, point<double>> id13(const line<T> &L, const line<T> &M){
	return id14<1, 1, 1, 1>(L, M);
}


template<class T> pair<bool, line<double>> id3(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d, ls = (M.p - L.p) ^ M.d;
	if(!s){
		if(ls) return {false, line<double>()};
		auto Lp = L.p, Lq = L.q(), Mp = M.p, Mq = M.q();
		if(Lp > Lq) swap(Lp, Lq);
		if(Mp > Mq) swap(Mp, Mq);
		line<double> res(max(Lp, Mp), min(Lq, Mq));
		return {res.d >= point<double>(), res};
	}
	auto rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
	return {intersect, line<double>(static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d), point<double>())};
}
template<class T> double id6(const line<T> &L, const line<T> &M){
	if(L || M){
		if(L.d * M.d >= 0 || (M.p - L.p) * M.d <= 0) return id11(L.p, M);
		else return distance(L.p, M.p);
	}
	else{
		if(id14<1, 0, 1, 0, long long>(L, M).first) return 0;
		else return min(id1(L.p, M), id1(M.p, L));
	}
}
template<class T> double id2(const line<T> &L, const line<T> &M){
	if(id3(L, M).first) return 0;
	return min({id7(L.p, M), id7(L.q(), M), id7(M.p, L), id7(M.q(), L)});
}
template<class P> struct id10{
	const P origin;
	id10(const P &origin = P()): origin(origin){ }
	bool operator()(const P &p, const P &q) const{ return ori(origin, p, q) > 0; }
};
template<class It, class P> void id8(It begin, It end, const P &origin){
	begin = partition(begin, end, [&origin](const decltype(*begin) &point){ return point == origin; });
	auto pivot = partition(begin, end, [&origin](const decltype(*begin) &point) { return point > origin; });
	id10<P> cmp(origin);
	sort(begin, pivot, cmp), sort(pivot, end, cmp);
}


template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree{
	segment_tree(): segment_tree(0){}
	segment_tree(int n): segment_tree(vector<Q>(n)){}
	segment_tree(const vector<Q> &v): n((int)v.size()){ 

		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ 

		assert(0 <= p && p < n);
		val[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ 

		assert(0 <= p && p < n);
		return val[p + size];
	}
	Q query(int l, int r){ 

		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } 

	template<class F> int max_pref(int l, F f){ 

		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, val[l]))){
				while(l < size){
					l = l << 1;
					if(f(sm + val[l])) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l ++]);
		}while((l & -l) != l);
		return n;
	} 

	template<class F> int id4(int r, F f){ 

		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(val[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} 

	int n, size, log;
	vector<Q> val;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
};
using Q = int; 

Q merge(Q x, Q y){ 

	return x + y;
}
Q identity(){ 

	return 0;
}






template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void id12(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void id12(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; id12(T...); }









int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n;
	long long k;
	cin >> n >> k;
	using P = point<double>;
	vector<P> init(n);
	for(auto &p: init){
		cin >> p.x >> p.y;
	}
	const double eps = 1e-6;
	const double pi = acos(-1);
	auto test = [&](double rad){ 

		debug(rad);
		vector<P> points;
		for(auto &p: init){
			if(p.norm() > rad){
				points.push_back(p);
			}
		}
		debug(points);
		long long res = 1LL * n * (n - 1) / 2;
		int n = (int)points.size();
		vector<array<double, 2>> range(n);
		vector<double> cmpr;
		vector<tuple<double, double, int>> event;
		for(auto p: points){
			double sz = p.norm();
			double ca = p.x / sz, sa = p.y / sz;
			double ct = sqrt(sz * sz - rad * rad) / sz, st = rad / sz;
			P u{ca * ct - sa * st, ca * st + sa * ct};
			debug(u);
			assert(abs((p - u.normal().normal().normal() * rad) * u.normal().normal().normal() * rad) < eps);
			ca = -ca, sa = -sa;
			st = -st;
			P v{ca * ct - sa * st, ca * st + sa * ct};
			debug(v);
			assert(abs((p - v.normal().normal().normal() * rad) * v.normal().normal().normal() * rad) < eps);
			assert((u ^ v) > 0);
			assert(abs(u.norm() - 1) < eps && abs(v.norm() - 1) < eps);
			double alpha = atan2(u.y, u.x) / (2 * pi), beta = atan2(v.y, v.x) / (2 * pi);
			debug(alpha, beta);
			if(alpha < 0){
				alpha += 1;
			}
			if(beta < 0){
				beta += 1;
			}
			if(beta < alpha){
				beta += 1;
			}
			debug(alpha, beta);
			cmpr.insert(cmpr.end(), {alpha, beta, alpha + 1, beta + 1});
			event.push_back({alpha, beta, 0});
			event.push_back({beta, alpha, 1});
			event.push_back({alpha + 1, beta + 1, 0});
			event.push_back({beta + 1, alpha + 1, 1});
		}
		sort(cmpr.begin(), cmpr.end());
		auto ind = [&](double x){
			return lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin();
		};
		sort(event.begin(), event.end());
		segment_tree<int, merge, identity> seg(4 * n);
		for(auto [t, tt, type]: event){
			if(!type){
				res -= seg.query(ind(t), ind(tt));
				if(t < 1){
					int pos = ind(tt);
					seg.set(pos, seg.query(pos) + 1);
				}
			}
			else{
				if(tt < 1){
					int pos = ind(t);
					seg.set(pos, seg.query(pos) - 1);
				}
			}
		}
		debug(res, "\n");
		return res >= k;
	};
	double low = 0, high = 1e9;
	for(auto rep = 0; rep < 60; ++ rep){
		double mid = (low + high) / 2;
		(test(mid) ? high : low) = mid;
	}
	cout << low << "\n";
	return 0;
}











