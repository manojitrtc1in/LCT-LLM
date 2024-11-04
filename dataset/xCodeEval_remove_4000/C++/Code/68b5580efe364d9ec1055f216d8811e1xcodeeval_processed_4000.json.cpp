









































using namespace std;





using namespace tr1;










using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 1 }, {
		1, 1 }, { 1, -1 }, { -1, -1 } };

template<class T> inline T abs1(T a) {
	return a < 0 ? -a : a;
}


template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template<typename t, typename t1>
t min1(t a, t1 b) {
	return a < b ? a : b;
}
template<typename t, typename ... arg>
t min1(t a, arg ... arr) {
	return min1(a, min1(arr...));
}
template<typename t, typename t1>
t max1(t a, t1 b) {
	return a > b ? a : b;
}
template<typename t, typename ... arg>
t max1(t a, arg ... arr) {
	return max1(a, max1(arr...));
}


inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps)
		return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template<typename t> inline int jud(t a, t b) {
	if (a < b) return -1;
	if (a == b) return 0;
	return 1;
}



template<typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if (na == 0) return 0;
	int be = 0, en = na - 1;
	if (*a <= *(a + na - 1)) {
		if (f_lb == 0)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != 1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != -1)
					en = mid;
				else
					be = mid + 1;
			}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if (f_lb)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != -1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != 1)
					en = mid;
				else
					be = mid + 1;
			}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template<class T> inline T lowb(T num) {
	return num & (-num);
}

inline int bitnum(ui nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(int nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(ull nValue) {
	return __builtin_popcountll(nValue);
}
inline int bitnum(ll nValue) {
	return __builtin_popcountll(nValue);
}
inline int id1(ui a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int id1(int a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int id1(ull a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}
inline int id1(ll a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}



long long pow(long long n, long long m, long long mod = 0) {
	if (m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if (m & 1) {
			ans *= k;
			if (mod) ans %= mod;
		}
		k *= k;
		if (mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod)
		a -= mod;
	while (a < 0)
		a += mod;
}
template<class t>
void output1(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		output1(arr[i]);
}




const int maxn = 800100;

namespace __treap {

const int SEED = 1537;
const int MAXTN = maxn * 3;

int nextRandom() {
	static int result = 1;
	result = ((result | 1) * SEED) ^ 123;

	return result;
}
struct id3 {
	id3 *l, *r;
	int key, weight;
	int sz, h, minv, maxv;
	ll sum, add;

	id3() {}

	void Reset(int h) {
		this->sz = 1;
		this->l = this->r = NULL;
		this->maxv = this->minv = this->sum = this->h = h;
		this->weight = nextRandom();
	}

	void PushDown() {
		if (add == 0) return;
		if (l) {
			l->sum += l->sz * add;
			l->minv += add;
			l->maxv += add;
			l->h += add;
			l->add += add;
		}
		if (r) {
			r->sum += r->sz * add;
			r->minv += add;
			r->maxv += add;
			r->h += add;
			r->add += add;
		}
		add = 0;
	}

	void PushUp() {
		sz = 1;
		minv = h;
		maxv = h;
		sum = h;

		if (l != NULL) {
			sz += l->sz;
			sum += l->sum;
			minv = min(minv, l->minv);
			maxv = max(maxv, l->maxv);
		}

		if (r != NULL) {
			sz += r->sz;
			sum += r->sum;
			minv = min(minv, r->minv);
			maxv = max(maxv, r->maxv);
		}
	}

} treapNode[MAXTN];

int GetSize(id3 *x) {
	if (NULL == x) {
		return 0;
	}
	return x->sz;
}

int id4(id3 *x) {
	if (NULL == x) {
		return 1 << 30;
	}
	return x->minv;
}

int id5(id3 *x) {
	if (NULL == x) {
		return 0;
	}
	return x->maxv;
}

ll GetSum(id3 *x) {
	if (NULL == x) {
		return 1 << 30;
	}
	return x->sum;
}



int ptr = 0;
id3* GetNode(int h) {
	treapNode[ptr].Reset(h);
	return &treapNode[ptr++];
}



id3* Merge(id3 *x, id3 *y) {
	if (x == NULL) {
		return y;
	}
	if (y == NULL) {
		return x;
	}
	if (x->weight < y->weight) {
		x->PushDown();
		x->r = Merge(x->r, y);
		x->PushUp();

		return x;
	} else {
		y->PushDown();
		y->l = Merge(x, y->l);
		y->PushUp();

		return y;
	}
}

void AddVal(id3 *p, ll val) {
	if (!p) return;
	p->add += val;
	p->sum += val * p->sz;
	p->maxv += val;
	p->minv += val;
	p->h += val;
}

void Split(id3 *p, id3 *&x, id3 *&y, ll val) {
	if (!p) {
		x = nullptr;
		y = nullptr;
		return;
	}
	if (val < p->minv) {
		x = NULL;
		y = p;
	} else if (val > p->maxv) {
		x = p;
		y = NULL;
	} else {
		p->PushDown();
		if (p->h > val || (p->l && p->l->maxv >= val)) {
			y = p;
			Split(p->l, x, y->l, val);
			y->PushUp();
		} else {
			x = p;
			Split(p->r, x->r, y, val - (p->h == val));
			x->PushUp();
		}
	}
}

void id2(id3 *p, id3 *&x, id3 *&y, ll k) {
	if (id4(p) >= k) {
		x = NULL;
		y = p;
	} else {
		p->PushDown();
		if (id4(p->r) < k || p->h < k) {
			x = p;
			id2(p->r, x->r, y, k);
			x->PushUp();
		} else {
			y = p;
			id2(p->l, x, y->l, k);
			y->PushUp();
		}
	}
}



id3* id0(id3 *p, int k) {
	if (k == 0) {
		return nullptr;
	} else if (k > GetSize(p)) {
		return nullptr;
	} else {
		p->PushDown();
		if (GetSize(p->l) >= k) {
			return id0(p->l, k);
		} else if (GetSize(p->l) + 1 == k) {
			return p;
		} else {
			return id0(p->r, k - GetSize(p->l) - 1);
		}
	}
}


}  


using namespace __treap;

int n;
pii orig[maxn];
id3 *l, *r;
ll lpos, rpos, best_ans;

int main() {




	ios_base::sync_with_stdio(0);


	freopen("input.txt", "r", stdin);




	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &orig[i].first, &orig[i].second);
	}
	sort(orig, orig + n, [&](const pii& a, const pii& b) {
		if (a.first + a.second == b.first + b.second) {
			return a.first < b.first;
		}
		return a.first + a.second < b.first + b.second;
	});

	l = r = nullptr;
	lpos = 0, rpos = 1000000000;
	best_ans = 0;
	for (ll i = 0, last_sum = 0; i < n; ) {
		int ri = i;
		while (ri < n && orig[i].first + orig[i].second == orig[ri].first + orig[ri].second) {
			ri++;
		}
		ll sum = orig[i].first + orig[i].second;
		lpos = max(0ll, lpos - (sum - last_sum));

		for (int j = i; j < ri; j++) {
			ll pos = orig[j].first - (sum - 1000000000);
			if (pos <= lpos) {
				id3 *xll, *lr;
				Split(l, xll, lr, lpos - pos);
				best_ans += lpos - pos;

				AddVal(r, rpos - lpos);
				r = Merge(GetNode(rpos - lpos), r);

				lr = Merge(GetNode(lpos - pos), lr);
				lr = Merge(GetNode(lpos - pos), lr);
				if (xll) {
					id3 *lll, *llr;
					rpos = lpos;
					ll delta = id4(xll);
					lpos -= delta;
					Split(xll, lll, llr, delta);
					l = Merge(llr, lr);
					AddVal(l, -delta);
				} else {
					id3 *lrl, *lrr;
					rpos = lpos;
					ll delta = id4(lr);
					lpos -= delta;
					Split(lr, lrl, lrr, delta);
					l = lrr;
					AddVal(l, -delta);
				}
			} else if (pos < rpos) {
				AddVal(l, pos - lpos);
				l = Merge(GetNode(pos - lpos), l);
				AddVal(r, rpos - pos);
				r = Merge(GetNode(rpos - pos), r);
				lpos = rpos = pos;
			} else {
				id3 *rl = nullptr, *rr = nullptr;
				Split(r, rl, rr, pos - rpos);
				best_ans += pos - rpos;

				AddVal(l, rpos - lpos);
				l = Merge(GetNode(rpos - lpos), l);

				rr = Merge(GetNode(pos - rpos), rr);
				rr = Merge(GetNode(pos - rpos), rr);
				if (rl) {
					id3 *rll, *rlr;
					lpos = rpos;
					ll delta = id4(rl);
					rpos += delta;
					Split(rl, rll, rlr, delta);
					r = Merge(rlr, rr);
					AddVal(r, -delta);
				} else {
					id3 *rrl, *rrr;
					lpos = rpos;
					ll delta = id4(rr);
					rpos += delta;
					Split(rr, rrl, rrr, delta);
					r = rrr;
					AddVal(r, -delta);
				}
			}
		}

		i = ri;
		last_sum = sum;
	}

	printf("%I64d\n", best_ans);

	return 0;
}
