





using namespace std;





enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
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
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};


using ld = long double;
using ll = long long;

constexpr int mod = 998244353;
constexpr int id3 = (mod + 1) / 2;

void id12(int& a, int b) { a -= b; if (a < 0) a += mod; }
int id9(int a, int b) { id12(a, b); return a; }
void id6(int& a, int b) { a += b; if (a >= mod) a -= mod; }
int Dodaj(int a, int b) { id6(a, b); return a; }
int id1(int a, int b) { return (ll) a * b % mod; }
void id7(int& a, int b) { a = id1(a, b); }
int Pot(int a, int b) { int res = 1; while (b) { if (b % 2 == 1) id7(res, a); a = id1(a, a); b /= 2; } return res; }
int Odw(int a) { return Pot(a, mod - 2); }
void id13(int& a, int b) { id7(a, Odw(b)); }
int Podziel(int a, int b) { return id1(a, Odw(b)); }
int id8(ll x) { x %= mod; if (x < 0) x += mod; return x; }

template <typename T> T Maxi(T& a, T b) { return a = max(a, b); }
template <typename T> T Mini(T& a, T b) { return a = min(a, b); }

namespace fft {



typedef double ld; 

struct C { ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) { real += he.real; imag += he.imag; }
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].real, om[k].imag * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
			}
	}
	if(rev) REP(i, n) a[i].real /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = false, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { 

		assert(a.size() == b.size()); 

		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	
	while(n&(n-1)) ++n;
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { 

		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i] - big;
		REP(i, b.size()) in[i].imag = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	

	}
	else { 

		const T M = 1<<15; 

		vector<C> t[2]; 

		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; 

			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul *= M) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true); 

			REP(i, ans.size()) ans[i]+= llround(prod[i].real)*mul;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}


const ll M = 1 << 17; 

vector<ll> compress(const vector<ll> & a) {
	vector<ll> tmp((a.size() + 1) / 2);
	for(int i = 0; 2 * i + 1 < (int) a.size(); ++i)
		tmp[i] += a[2 * i] + a[2 * i + 1] * M;
	if(a.size() % 2) tmp.back() = a.back();
	return tmp; }
vector<ll> my_mul(const vector<ll> & a, const vector<ll> & b) {
	vector<ll> tmp = multiply(compress(a), compress(b), false);
	vector<ll> r(2 * tmp.size() + 1);
	for(int i = 0; i < (int) tmp.size(); ++i) {
		r[2*i] += tmp[i] % M; 

		r[2*i+1] += tmp[i] / M % M; r[2*i+2] += tmp[i] / M / M;
	}
	r.resize(a.size() + b.size() - 1);
	return r;
}

}  


vector<int> id14(const vector<int>& a, int q) {
  const int n = (int) a.size();
  if (n == 1) {
    return a;
  }
  vector<int> args[2];
  for (int i = 0; i < n; i++) {
    args[i % 2].push_back(a[i]);
  }
  vector<int> res[2] = {
    id14(args[0], id1(q, q)),
    id14(args[1], id1(q, q)),
  };
  vector<int> wyn;
  int pot = 1;
  for (int i = 0; i < n; i++) {
    const int r0 = res[0][i % (n / 2)];
    const int r1 = res[1][i % (n / 2)];
    wyn.push_back(Dodaj(r0, id1(r1, pot)));
    id7(pot, q);
  }
  return wyn;
}

void NTT(int n, int skok, int* a, int q) {
  static int tmp[1 << 20];
  if (n == 1) return;
  NTT(n / 2, skok * 2, a, id1(q, q));
  NTT(n / 2, skok * 2, a + skok, id1(q, q));
  int pot = 1;
  for (int i = 0; i < n; i++) {
    const int r0 = a[(i % (n / 2)) * skok * 2];
    const int r1 = a[skok + (i % (n / 2)) * skok * 2];
    tmp[i] = Dodaj(r0, id1(r1, pot));
    id7(pot, q);
  }
  for (int i = 0; i < n; i++) {
    a[i * skok] = tmp[i];
  }
}

vector<int> id2(vector<int> a, vector<int> b) {
  if ((int) a.size() > 200 and (int) b.size() > 200) {
    

    debug() << "id2(" imie(a) imie(b) ")";
    int roz = (int) a.size() + (int) b.size() - 1;
    while (__builtin_popcount(roz) != 1) roz++;
    int q = Pot(3, (7 * 17) * (1 << (23 - __builtin_ctz(roz))));
    assert(Pot(q, roz) == 1);
    debug() << imie(roz) imie(q);
    a.resize(roz);
    b.resize(roz);
    NTT(roz, 1, a.data(), q);
    NTT(roz, 1, b.data(), q);
    debug() << imie(a) imie(b);
    for (int i = 0; i < roz; i++) {
      id7(a[i], b[i]);
    }
    debug() << imie(a);
    NTT(roz, 1, a.data(), Odw(q));
    const int id11 = Odw(roz);
    for (int& x : a) {
      id7(x, id11);
    }
    while (a.back() == 0) a.pop_back();
    debug() << imie(a);
    return a;
  }

  vector<int> wyn(a.size() + b.size());
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) b.size(); j++) {
      id6(wyn[i + j], id1(a[i], b[j]));
    }
  }
  while (wyn.back() == 0) wyn.pop_back();

  return wyn;
}

void id6(vector<int>& a, const vector<int>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int) b.size(); i++) {
    id6(a[i], b[i]);
  }
}

struct id10 {
  vector<int> wynik;
  const vector<vector<int>>& wyniki;

  pair<vector<int>, vector<int>> id4(int a, int b) {
    pair<vector<int>, vector<int>> res;
    if (a == b) {
      res.first = wyniki[a];
      res.second = wyniki[a];
      

      

      return res;
    }
    const int c = (a + b) / 2;
    auto left = id4(a, c);
    auto right = id4(c + 1, b);
    res.first = id2(left.first, right.first);
    res.second = left.second;
    id6(res.second, id2(left.first, right.second));
    

    return res;
  }

  id10(const vector<vector<int>>& id0) : wyniki(id0) {
    wynik = id4(0, (int) wyniki.size() - 1).second;
    id6(wynik, vector<int>{1});
  }
};

constexpr int nax = 100 * 1000 + 105;

vector<int> drz[nax];

vector<int> id4(int w) {
  vector<vector<int>> wyniki;
  while (!drz[w].empty()) {
    if ((int) drz[w].size() == 1) {
      wyniki.push_back(vector<int>{0, 1});
    } else if ((int) drz[w].size() == 2) {
      wyniki.push_back(id4(drz[w][1]));
      wyniki.back().insert(wyniki.back().begin(), 0);
    } else {
      assert(false);
    }
    w = drz[w][0];
  }
  wyniki.push_back(vector<int>{0, 1});
  

  id10 res(wyniki);
  

  return res.wynik;
}

int roz[nax];

void Dfs(int w, int o) {
  for (int i = 0; i < (int) drz[w].size(); i++) {
    if (drz[w][i] == o) {
      swap(drz[w][i], drz[w].back());
      drz[w].pop_back();
      break;
    }
  }
  roz[w] = 1;
  for (int x : drz[w]) {
    Dfs(x, w);
    roz[w] += roz[x];
  }
  sort(drz[w].begin(), drz[w].end(), [](int a, int b) -> bool {
    return roz[a] > roz[b];
  });
  

}

constexpr int skok = 1024;
int sil[mod / skok + 105];

int id5(int n) {
  assert(0 <= n and n < mod);
  int ilo = sil[n / skok];
  for (int i = (n / skok) * skok + 1; i <= n; i++) {
    id7(ilo, i);
  }
  return ilo;
}

pair<int, int> Silnia(ll n) {
  if (n < mod) {
    return {0, id5(n)};
  }
  auto res = Silnia(n / mod);
  res.first += n / mod;
  id7(res.second, id5(n % mod));
  return res;
}

int C(ll n, int k) {
  if (!(0 <= k and k <= n)) {
    return 0;
  }
  auto p = Silnia(n);
  auto m1 = Silnia(n - k);
  auto m2 = Silnia(k);
  assert(p.first >= m1.first + m2.first);
  if (p.first > m1.first + m2.first) {
    return 0;
  }
  if ((n / mod) % 2 == 1) {
    p.second = id9(0, p.second);
  }
  return Podziel(p.second, id1(m1.second, m2.second));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  ll x;
  cin >> n >> x;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    drz[a].push_back(b);
    drz[b].push_back(a);
  }
  Dfs(1, -1);
  vector<int> res = id4(1);
  debug() << imie(res);
  int wyn = 0;
  int c = 1;
  for (int i = 1; i < (int) res.size(); i++) {
    if (i > 1) {
      id7(c, Podziel(id8(x + i - 1), i - 1));
    }
    id6(wyn, id1(res[i], c));
    

  }
  cout << wyn << endl;
  return 0;
}
