
using namespace std;




  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {

~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};




template<typename T> T K(T a) { return a * a; }

typedef long double ll; 

typedef long double ld;


const ld eps = 1e-12;

long double read_double() {
	long double xx;
	scanf("%Lf", &xx);
	return xx;
}
struct P {
	ll x, y;
	void read() {
		x = read_double();
		y = read_double();
	}
	P operator -(const P& he) const {
		return P{x - he.x, y - he.y};
	}
	P operator +(const P& he) const {
		return P{x + he.x, y + he.y};
	}
	ll operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
	P operator *(ld mul) const {
		return P{x * mul, y * mul};
	}
	P operator /(ld mul) const {
		return P{x / mul, y / mul};
	}
	ld len() const {
		return sqrt(x * x + y * y);
	}
	ll dot(P b) { return x * b.x + y * b.y; }
	ld len() { return sqrt(K(x) + K(y)); }
	P scaleTo(ld to) { return *this * (to / len()); }
	ld dist(P & b) { return (*this - b).len(); }
	P rotate90() { return P{-y, x}; }
	ld angle() { return atan2(y, x); }
	P rotate(ld ang) {
		ld c = cos(ang), s = sin(ang);
		return P{x * c - y * s, x * s + y * c};
	}
	

	bool operator < (P he) { return make_pair(x, y) < make_pair(he.x, he.y); }
	bool below(P a, P b) { return (b - a) * (*this - a) <= 0; } 

	

	P apol_in(P b, ld ratio) { 

		return (*this + b * ratio) / (1 + ratio);
	}
	P apol_out(P b, ld ratio) {
		return (*this - b * ratio) / (1 - ratio);
	}
};
debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
struct L2 {
	P one, two;
	

	

	P dir() { return two - one; }
	P normal() { return dir().rotate90(); }
	ld dist(P he) {
		return abs((he - one) * (he - two)) / one.dist(two);
	}
	ld segDist(P he) { 

		if((he - two) * normal() < 0 && normal() * (he - one) < 0)
			return dist(he);
		return min(one.dist(he), two.dist(he));
	}
	P inter(L2 he) {
		P A = dir(), B = he.dir();
		ll den = A * B;
		assert(abs(den) > eps); 

		return (A * (he.one * he.two) - B * (one * two)) * (1.0 / den);
		

		

		

		

	}
	P project(P he) {
		P unit_normal = normal().scaleTo(1);
		return he + unit_normal * unit_normal.dot(one - he);
	}
	P reflect(P he) { return project(he) * 2 - he; }


};
L2 id2(ll a, ll b, ll c) {
	P first;
	if(abs(b) > eps) first = P{0, (ld) -c / b};
	else if(abs(a) > eps) first = P{(ld) -c / a, 0};
	else assert(false);
	return L2{first, first + P{b, -a}};
}
ll det(ll t[3][3]) { 

	ll s = 0;
	for(int i = 0; i < 3; ++i)
		for(int j = i + 1, mul = 1; j != i + 3; ++j, mul -= 2)
			s += t[0][i] * t[1][j%3] * t[2][3-i-j%3] * mul;
	return s;
}
struct L3 {
	

	ll a, b, c;
	L3 fix() { 

		assert(abs(b) > eps || abs(a) > eps);
		ll g = (b > eps || (abs(b) < eps && a > eps)) ? 1 : -1;
		

		

		

		return L3{a / g, b / g, c / g};
	}
	ld dist(P he) {
		return abs(a * he.x + b * he.y + c) / sqrt(K(a) + K(b));
	}
	P dir() { return P{b, -a}; }
	P normal() { return P{a, b}; } 

	P project(P he) {
		ld den = K(a) + K(b); 

		return P{(b * (b * he.x - a * he.y) - a * c) / den,
				 (a * (a * he.y - b * he.x) - b * c) / den };
	}
	P reflect(P he) { return project(he) * 2 - he; }
	P inter(L3 he) {
		
		ll den = Q(a, b);
		assert(abs(den) > 1e-14); 

		return P{Q(b, c), Q(c, a)} * (1.0 / den);
		
	}
	bool operator < (L3 he) {
		

		

		

		if(abs(a * he.b - b * he.a) < eps) return b * he.c < c * he.b;
							

		return a * he.b < b * he.a;
	}
	bool below(L3 A, L3 C) {
		ll t[3][3] = { {A.a,A.b,A.c}, {a,b,c}, {C.a,C.b,C.c} };
		return det(t) <= 0; 

	}
};
L3 id0(P one, P two) {
	ll a = two.y - one.y;
	ll b = one.x - two.x;
	return L3{a, b, -(a * one.x + b * one.y)}.fix();
}
struct Circle {
	P o;
	ld r;
	vector<P> tangency(P he) {
		ld d = o.dist(he);
		assert(d > r);
		

		

		ld alpha = asin(r / d);
		P vec = (o - he) * sqrt(1 - K(r / d)); 

		

		return vector<P>{he + vec.rotate(alpha), he + vec.rotate(-alpha)};
	}
	vector<P> inter(L3 he) {
		P prim = he.project(o);
		ld d = prim.dist(o);
		if(d >= r + eps) return vector<P>{};
		if(abs(d - r) <= eps) return vector<P>{prim};
		P vec = he.dir().scaleTo(sqrt(K(r) - K(d)));
		return vector<P>{prim + vec, prim - vec};
	}	
	vector<P> inter(Circle he) {
		return inter(L3{2*(o.x-he.o.x), 2*(o.y-he.o.y),
				K(r)-K(he.r)-K(o.x)-K(o.y)+K(he.o.x)+K(he.o.y)});
	}
	vector<L2> tangency(Circle he) {
		vector<L2> ret;
		ld ratio = r / he.r;
		auto considerPoint = [&] (P p) {
			vector<P> one = tangency(p), two = he.tangency(p);
			for(int i = 0; i < (int) min(one.size(), two.size()); ++i)
				ret.push_back(L2{one[i], two[i]});
		};
		if(abs(r - he.r < 1e-9)) { 

			P dir = (he.o - o).rotate90().scaleTo(r);
			for(int tmp : {1, -1})
				ret.push_back(L2{o + dir * tmp, he.o + dir * tmp});
		}
		else considerPoint(o.apol_out(he.o, ratio));
		

		

		considerPoint(o.apol_in(he.o, ratio));
		return ret;
	}
};




int main() {
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	long long id1 = (long long) n * (n - 1) / 2 - k;
	vector<P> they(n);
	for(P& p : they) {
		p.read();
	}
	ld low = 1e-7, high = 1e5;
	for(int rep = 0; rep < 42; ++rep) {
		ld mid = (low + high) / 2;
		if(rep == 0 || high > 0.99) {
			mid = sqrt(low * high);
		}
		

		long long outside = 0;
		vector<pair<ld, ld>> intervals;
		for(P p : they) {
			P orig{0,0}; 

			if(p.dist(orig) > mid + 1e-10) {
				vector<ld> interval;
				for(P interval_end : Circle{P{0,0},mid}.tangency(p)) {
					interval.push_back(interval_end.angle());
				}
				

				

				const ld PI = 2 * acosl(0);
				auto simplify = [&](ld value) {
					return (value / PI + 1) / 2;
				};
				intervals.emplace_back(simplify(interval[0]), simplify(interval[1]));
				if(intervals.back().second < intervals.back().first) {
					swap(intervals.back().first, intervals.back().second);
					

				}
			}
		}
		debug() << imie(intervals);
		int s = intervals.size();
		vector<pair<ld, int>> values;
		for(int i = 0; i < s; ++i) {
			values.emplace_back(intervals[i].first, i);
			values.emplace_back(intervals[i].second, i);
		}
		sort(values.begin(), values.end());
		int base = 1;
		while(base <= (int) values.size()) {
			base *= 2;
		}
		vector<int> tree(2 * base);
		vector<int> where(2 * s, -1);
		for(int pos = 0; pos < (int) values.size(); ++pos) {
			int id = values[pos].second;
			if(where[id] == -1) {
				

				for(int x = (base + pos); x >= 1; x /= 2) {
					tree[x]++;
				}
				where[id] = pos;
			}
			else {
				

				

					

				

				for(int x = base + where[id]; x >= 1; x /= 2) {
					if(x % 2 == 0) {
						outside += tree[x+1];
					}
					tree[x]--;
				}
			}
		}
		
		

			

				

				

				

				

					

				

				

				

					

				

				

			

		

		
		

			

				

				

					

						

						

						

						

						

						

						

							

						

						

						

							

						

					

				

				

			

		

		
		

			

				

					

				

			

		

		

		

		if(outside <= id1) {
			

			high = mid;
		}
		else {
			low = mid;
		}
	}
	printf("%.8Lf\n", (low + high) / 2);
}
