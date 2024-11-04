



























using namespace std;






















static unsigned rnd() {
	static unsigned y = 124612741;
	y ^= y << 13;
	y ^= y >> 17;
	return y ^= y << 5;
}
inline int fpow(int a, int st, int mod) {
	int ans = 1;
	while (st) {
		if (st % 2) ans = (long long)ans * a % mod;
		a = (long long)a * a % mod;
		st /= 2;
	}
	return ans;
}



int invmod(int x, int y) {
	int a = 1, b = 0, k;
	for (; y; swap(x, y), swap(a, b)) {
		k = x / y;
		x -= y * k;
		a -= b * k;
	}
	return a + max(b, 0);
}

inline int calcBits(int a) {

	return _mm_popcnt_u32(a);

	return __builtin_popcount(a);

}
struct Hash {
	Hash() : x1(0), x2(0) {}
	Hash(const int& x1, const int& x2) : x1(x1), x2(x2) {}
	int x1, x2;

	static int mod1, mod2;
	static int p1, p2;
	static int id1, id0;
	static bool initCalled;
	static const Hash ONE, ZERO, INVALID;
	static Hash UNIT, INV_UNIT;
	static bool prime(int a) {
		if (a == 1) return 0;
		for (int i = 2; i * i <= a; ++i) {
			if (a % i == 0) return false;
		}
		return true;
	}
	static int pickModHelper(int start, int bad) {
		int mn = INF, best = -1;
		FOR(i, start, start + 5000) {
			if (i == bad || !prime(i)) continue;
			int cur = calcBits(i);
			if (cur < mn) {
				mn = cur;
				best = i;
			}
		}
		return best;
	}
	static void init() {
		if (initCalled) return;
		initCalled = true;
		mod1 = pickModHelper(INF + rnd() % 10000000, -1);
		mod2 = pickModHelper(INF + rnd() % 10000000, mod1);

		id1 = invmod(p1, mod1);
		id0 = invmod(p2, mod2);
		INV_UNIT = Hash(id1, id0);
	}

	inline Hash& operator +=(const Hash& other) {
		x1 += other.x1;
		if (x1 >= Hash::mod1) x1 -= Hash::mod1;
		x2 += other.x2;
		if (x2 >= Hash::mod2) x2 -= Hash::mod2;
		return *this;
	}
	inline Hash& operator -=(const Hash& other) {
		x1 -= other.x1;
		if (x1 < 0) x1 += Hash::mod1;
		x2 -= other.x2;
		if (x2 < 0) x2 += Hash::mod2;
		return *this;
	}
	inline Hash& operator *=(const Hash& other) {
		x1 = (ll)x1 * other.x1 % Hash::mod1;
		x2 = (ll)x2 * other.x2 % Hash::mod2;
		return *this;
	}
	inline Hash& operator *=(const int& other) {
		x1 = (ll)x1 * other % Hash::mod1;
		x2 = (ll)x2 * other % Hash::mod2;
		return *this;
	}
	inline Hash& operator^=(const int& power) {
		int st = power;
		Hash ans(1, 1);
		while (st) {
			if (st % 2) ans *= *this;
			x1 = (long long)x1 * x1 % Hash::mod1;
			x2 = (long long)x2 * x2 % Hash::mod2;
			st /= 2;
		}
		return *this;
	}
	inline bool operator ==(const Hash& other) const {
		return x1 == other.x1 && x2 == other.x2;
	}
	inline bool operator <(const Hash& other) const {
		return x1 < other.x1 || (x1 == other.x1 && x2 < other.x2);
	}
	inline unsigned ll getULL() const {
		return ((unsigned ll)x1 << 31) + x2;
	}
};
bool Hash::initCalled = false;
int Hash::mod1 = 0;
int Hash::mod2 = 0;
int Hash::p1 = 23561;
int Hash::p2 = 10000019;
int Hash::id1 = -1;
int Hash::id0 = -1;
const Hash Hash::ONE(1, 1);
const Hash Hash::ZERO(0, 0);
const Hash Hash::INVALID(-1, -1);
Hash Hash::UNIT(Hash::p1, Hash::p2);
Hash Hash::INV_UNIT(-1, -1);



inline Hash operator +(const Hash& a, const Hash& b) {
	Hash ans(a.x1 + b.x1, a.x2 + b.x2);
	if (ans.x1 >= Hash::mod1) ans.x1 -= Hash::mod1;
	if (ans.x2 >= Hash::mod2) ans.x2 -= Hash::mod2;
	return ans;
}
inline Hash operator -(const Hash& a, const Hash& b) {
	Hash ans(a.x1 - b.x1, a.x2 - b.x2);
	if (ans.x1 < 0) ans.x1 += Hash::mod1;
	if (ans.x2 < 0) ans.x2 += Hash::mod2;
	return ans;
}
inline Hash operator *(const Hash& a, const Hash& b) {
	return Hash((long long)a.x1 * b.x1 % Hash::mod1, (long long)a.x2 * b.x2 % Hash::mod2);
}
inline Hash operator *(const Hash& a, const int& b) {
	return Hash((long long)a.x1 * b % Hash::mod1, (long long)a.x2 * b % Hash::mod2);
}
inline Hash operator^(const Hash& a, const int& power) {
	int st = power;
	Hash ans(1, 1), cur(a);
	while (st) {
		if (st % 2) ans *= cur;
		cur *= cur;
		st /= 2;
	}
	return ans;
}
inline Hash fpow(const Hash& a, const int& power) {
	return a ^ power;
}
inline Hash invmod(const Hash& a) {
	return Hash(invmod(a.x1, Hash::mod1), invmod(a.x2, Hash::mod2));
}

vector<Hash> pmem;
inline Hash cpow(int pw) {
	if (pw < L(pmem)) return pmem[pw];
	if (pmem.empty()) {
		pmem.push_back(Hash::ONE);
	}
	pmem.resize(pw + 1);
	rep(i, pw) {
		pmem[i] = pmem[i - 1] * Hash::UNIT;
	}
	return pmem[pw];
}

struct node;

void* GP;

class pnode;

inline void id3(pnode& p);
inline void id2(pnode& p);

class pnode {
public:
	pnode(node* p) : step(p ? (int)((size_t)p - (size_t)GP) : -1) {
		id2(*this);
	}

	inline pnode& operator=(node* p) {
		id3(*this);
		step = p ? (int)((size_t)p - (size_t)GP) : -1;
		id2(*this);
		return *this;
	}

	pnode(const pnode& other) : step(other.step) {
		id2(*this);
	}

	inline pnode& operator=(const pnode& other) {
		id3(*this);
		step = other.step;
		id2(*this);
		return *this;
	}

	pnode() : step(-1) {}

	pnode(pnode&& other) {
		step = other.step;
		other.step = -1;
	}

	inline pnode& operator=(pnode&& other) {
		id3(*this);
		step = other.step;
		other.step = -1;
		return *this;
	}

	~pnode() {
		id3(*this);
	}

	inline node* operator->() {
		return (node*)((size_t)GP + step);
	}

	inline node& operator*() {
		return *((node*)((size_t)GP + step));
	}

	inline operator bool() {
		return step != -1;
	}
private:
	int step;
};

struct node {
	Hash hs;
	int cnt;
	int hval;
	pnode l, r;
	int ref;
};

void id3(pnode& p) {
	if (!p) return;
	--p->ref;
	

	
}

void id2(pnode& p) {
	if (!p) return;
	++p->ref;
}

inline int cnt(pnode a) {
	if (!a) return 0;
	return a->cnt;
}

const int N = 2000000;
node tr[N];
int tc;

inline void cl(pnode t) {
	t->cnt = 0;
	t->hs = Hash::ZERO;
	t->hval = 0;
	t->l = NULL;
	t->r = NULL;
}

inline pnode cp(pnode a) {
	if (tc >= N) {
		tc = 0;
	}
	while (tc < N && tr[tc].ref > 0) ++tc;
	if (tc >= N) {
		tc = 0;
	}
	while (tc < N && tr[tc].ref > 0) ++tc;
	if (tc >= N) {
		throw std::runtime_error("Oops");
	}
		
	pnode t = &tr[tc++];
	cl(t);
	if (!a) return t;
	t->cnt = a->cnt;
	t->hval = a->hval;
	t->hs = a->hs;
	t->l = a->l;
	t->r = a->r;
	return t;
}

inline void upd(pnode root) {
	if (root == NULL) return;
	root->cnt = 1;
	if (root->l) root->cnt += root->l->cnt;
	if (root->r) root->cnt += root->r->cnt;


	root->hs = Hash::ZERO;
	if (root->l) {
		root->hs = root->l->hs;
	}
	root->hs *= Hash::UNIT;
	root->hs += Hash(root->hval, root->hval);

	if (root->r) {
		root->hs *= cpow(root->r->cnt);
		root->hs += root->r->hs;
	}
}

pnode merge(pnode a, pnode b) {
	if (a == NULL && b == NULL) return NULL;
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (rnd() % (a->cnt + b->cnt) < a->cnt) {
		pnode root = cp(a);
		root->r = merge(a->r, b);
		upd(root);
		return root;
	}
	else {
		pnode root = cp(b);
		root->l = merge(a, b->l);
		upd(root);
		return root;
	}
}

void split(pnode root, pnode& a, pnode& b, int cnt) {
	if (root == NULL) {
		a = b = NULL;
		return;
	}
	if ((root->l ? root->l->cnt : 0) >= cnt) {
		b = cp(root);
		split(root->l, a, b->l, cnt);
		upd(b);
	}
	else {
		a = cp(root);
		split(root->r, a->r, b, cnt - (root->l ? root->l->cnt : 0) - 1);
		upd(a);
	}
}


int a, b, c, d, n, m, k;
int mas[100002];

struct Node {
	pnode fr;
	pnode bk;
	bool bad;
};

Node TR[262144 + 2];


inline void un(Node& lf, Node& rt, Node& s) {
	s.fr = 0;
	s.bk = 0;
	s.bad = 0;
	if (lf.bad || rt.bad) {
		s.bad = 1;
		return;
	}

	if (cnt(lf.bk) < cnt(rt.fr)) {
		pnode t = cp(rt.fr);
		pnode t1 = 0, t2 = 0;
		split(t, t1, t2, cnt(rt.fr) - cnt(lf.bk));

		if (t2 != 0 && (lf.bk == 0 || !(t2->hs == lf.bk->hs))) {
			s.bad = 1;
			return;
		}
		
		s.fr = t1;
		s.fr = merge(s.fr, lf.fr);
		s.bk = rt.bk;
	}
	else if (cnt(lf.bk) > cnt(rt.fr)) {
		pnode t = cp(lf.bk);
		pnode t1 = 0, t2 = 0;
		split(t, t1, t2, cnt(lf.bk) - cnt(rt.fr));

		if (t2 != 0 && (rt.fr == 0 || !(t2->hs == rt.fr->hs))) {
			s.bad = 1;
			return;
		}

		s.bk = t1;
		s.bk = merge(s.bk, rt.bk);
		s.fr = lf.fr;
	}
	else {
		if (cnt(lf.bk) > 0) {
			if (!(lf.bk->hs == rt.fr->hs)) {
				s.bad = 1;
				return;
			}
		}

		s.fr = lf.fr;
		s.bk = rt.bk;
	}
}

void build(int l, int r, int v) {
	if (l == r - 1) {
		TR[v].fr = 0;
		TR[v].bk = 0;
		TR[v].bad = 0;
		if (mas[l] < 0) {
			pnode nfr = cp(0);
			nfr->cnt = 1;
			nfr->l = nfr->r = 0;
			nfr->hval = -mas[l];
			nfr->hs = Hash(-mas[l], -mas[l]);
			TR[v].fr = nfr;
		}
		else {
			pnode nfr = cp(0);
			nfr->cnt = 1;
			nfr->l = nfr->r = 0;
			nfr->hval = mas[l];
			nfr->hs = Hash(mas[l], mas[l]);
			TR[v].bk = nfr;
		}
		return;
	}

	int xx = (r + l) / 2;
	build(l, xx, v * 2);
	build(xx, r, v * 2 + 1);

	un(TR[v * 2], TR[v * 2 + 1], TR[v]);
}

inline void upd(int l, int r, int pos, int val, int v) {
	if (l == r - 1) {
		TR[v].fr = 0;
		TR[v].bk = 0;
		TR[v].bad = 0;
		if (mas[l] < 0) {
			pnode nfr = cp(0);
			nfr->cnt = 1;
			nfr->l = nfr->r = 0;
			nfr->hval = -mas[l];
			nfr->hs = Hash(-mas[l], -mas[l]);
			TR[v].fr = nfr;
		}
		else {
			pnode nfr = cp(0);
			nfr->cnt = 1;
			nfr->l = nfr->r = 0;
			nfr->hval = mas[l];
			nfr->hs = Hash(mas[l], mas[l]);
			TR[v].bk = nfr;
		}
		return;
	}

	int xx = (r + l) / 2;
	if (pos < xx) upd(l, xx, pos, val, v * 2); else
		upd(xx, r, pos, val, v * 2 + 1);

	un(TR[v * 2], TR[v * 2 + 1], TR[v]);
}

Node fnd(int l, int r, int a, int b, int v) {
	if (l == a && b == r - 1) {
		return TR[v];
	}

	int xx = (r + l) / 2;
	if (b < xx) return fnd(l, xx, a, b, v * 2); else
		if (a >= xx) return fnd(xx, r, a, b, v * 2 + 1);

	auto a1 = fnd(l, xx, a, xx - 1, v * 2);
	if (a1.bad) return a1;
	auto a2 = fnd(xx, r, xx, b, v * 2 + 1);
	if (a2.bad) return a2;

	Node res;
	un(a1, a2, res);
	return res;
}

inline bool check(int l, int r) {
	auto t = fnd(0, n, l, r, 1);
	if (t.bad) return false;
	if (cnt(t.fr) || cnt(t.bk)) return 0;
	return true;
}
int main() {
	Hash::init();
	

	


	scanf("%d%d", &n, &k);

	rept(i, n) {
		scanf("%d", &mas[i]);
	}

	pmem.clear(); tc = 0; GP = tr;
	cpow(n + 1);
	build(0, n, 1);

	int ov = 0;
	scanf("%d", &m);
	rept(iter, m) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d", &a, &b); --a;
			mas[a] = b;
			upd(0, n, a, b, 1);
		}
		else {
			scanf("%d%d", &a, &b); --a; --b;
			bool ans = check(a, b);
			if (ans) puts("Yes"); else puts("No");
		}
	}
}
