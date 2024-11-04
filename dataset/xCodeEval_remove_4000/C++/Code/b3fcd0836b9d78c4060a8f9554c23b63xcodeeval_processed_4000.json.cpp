
















using namespace std;






















static unsigned rnd() {
	static int y = 124612741;
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
struct Hash {
	Hash() : x1(0), x2(0) {}
	Hash(const int& x1, const int& x2) : x1(x1), x2(x2) {}
	int x1, x2;

	static int mod1, mod2;
	static int p1, p2;
	static int id5, id4;
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
	static void init() {
		if (initCalled) return;
		initCalled = true;
		mod1 = INF + rnd() % 10000000;
		while (!prime(mod1)) ++mod1;
		mod2 = INF + rnd() % 10000000;
		while (mod2 == mod1 || !prime(mod2)) ++mod2;
		
		id5 = fpow(p1, mod1 - 2, mod1);
		id4 = fpow(p2, mod2 - 2, mod2);
		INV_UNIT = Hash(id5, id4);
	}

	inline Hash& operator +=(const Hash& other) {
		x1 += other.x1;
		x1 -= (((x1 - mod1) >> 31) + 1) * mod1;
		

		x2 += other.x2;
		

		x1 -= (((x1 - mod2) >> 31) + 1) * mod2;
		return *this;
	}
	inline Hash& operator -=(const Hash& other) {
		x1 -= other.x1;
		

		x1 -= (x1 >> 31) * Hash::mod1;
		x2 -= other.x2;
		x2 -= (x2 >> 31) * Hash::mod2;
		

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
};
bool Hash::initCalled = false;
int Hash::mod1 = 0;
int Hash::mod2 = 0;
int Hash::p1 = 23561;
int Hash::p2 = 10000019;
int Hash::id5 = -1;
int Hash::id4 = -1;
const Hash Hash::ONE(1, 1);
const Hash Hash::ZERO(0, 0);
const Hash Hash::INVALID(-1, -1);
Hash Hash::UNIT(Hash::p1, Hash::p2);
Hash Hash::INV_UNIT(-1, -1);

inline Hash operator +(const Hash& a, const Hash& b) {
	Hash ans(a.x1 + b.x1, a.x2 + b.x2);
	

	

	ans.x1 -= (((ans.x1 - Hash::mod1) >> 31) + 1) * Hash::mod1;
	ans.x2 -= (((ans.x2 - Hash::mod2) >> 31) + 1) * Hash::mod2;
	return ans;
}
inline Hash operator -(const Hash& a, const Hash& b) {
	Hash ans(a.x1 - b.x1, a.x2 - b.x2);
	

	

	ans.x1 -= (ans.x1 >> 31) * Hash::mod1;
	ans.x2 -= (ans.x2 >> 31) * Hash::mod2;
	return ans;
}
inline Hash operator *(const Hash& a, const Hash& b) {
	return Hash((long long)a.x1 * b.x1 % Hash::mod1, (long long)a.x2 * b.x2 % Hash::mod2);
}
inline Hash operator *(const Hash& a, const int &b) {
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



template<class H>
struct HashString : public string {
	HashString() : string() {
		precalc(0);
	}
	HashString(const HashString& other) : string(other) {
		precalc(size());
	}
	HashString(HashString&& other)
		: hh(std::move(other.hh)),
		string(std::move(other)) {
		precalc(size());
	}

	HashString(const string& other) : string(other)  {
		precalc(size());
		build();
	}
	HashString(string&& other) : string(std::move(other)) {
		precalc(size());
		build();
	}

	HashString(const char* other) : string(other) {
		precalc(size());
		build();
	}
	inline void clear() {
		hh.clear();
		string::clear();
	}

	inline static H getPow(int p) {
		if (p < haveN) {
			return pp[p];
		}
		else {
			return fpow(H::UNIT, p);
		}
	}
	inline static H getInvPow(size_t p) {
		if (p < invpp.size()) {
			return invpp[p];
		}
		else {
			return fpow(H::INV_UNIT, p);
		}
	}
	inline H getInvRegister(const H& p) const {
		if (p == register_) {
			return id7;
		}
		else {
			register_ = p;
			return id7 = invmod(p);
		}
	}
	static void precalc(int N = 0) {
		Hash::init();
		if (haveN >= N) return;
		pp.resize(N);
		invpp.resize(N);
		if (!haveN) {
			pp[0] = H::ONE;
			invpp[0] = H::ONE;
			haveN = 1;
		}
		for (int i = haveN; i < N; ++i) {
			pp[i] = pp[i - 1] * H::UNIT;
			invpp[i] = invpp[i - 1] * H::INV_UNIT;
		}
		haveN = N;
	}
	inline void build() {
		int curSize = size();
		if (haveN <= curSize) {
			precalc(curSize);
		}
		for (int i = hh.size(); i < curSize; ++i) {
			H pr = i ? hh.back() : H::ZERO;
			hh.push_back(pr + getPow(i) * (*this)[i]);
		}
	}

	

	

	inline H getHash(int pos, int len) const {
		if (len <= 0) return H::ZERO;
		const int S = size();
		if (pos + len - 1 < S) {
			H ans = hh[pos + len - 1];
			if (pos) {
				ans -= hh[pos - 1];
				ans *= getInvPow(pos);
			}
			return ans;
		}
		else {
			H head = hh.back();
			if (pos) {
				head -= hh[pos - 1];
				head *= getInvPow(pos);
			}
			
			int full = -1, en = -1;
			H mid = H::ZERO;
			int midlen = 0;
			if (len <= S) {
				en = pos + len - 1 - S;
				H tail = hh[en];
				full = 0;
				return head + tail * getPow(S - pos);
			}
			else {
				en = (pos + len - 1) % S;
				H tail = hh[en];
				full = (len - (S - pos) - (en + 1)) / S;
				mid = hh.back() * (H::ONE - getInvPow(full * S)) * getInvRegister(H::ONE - getInvPow(S));
				return head + mid * getPow(S - pos) + tail * getPow(len - (en + 1));
			}
		}
	}

	inline HashString& operator +=(const char& ch) {
		string::operator+=(ch);
		build();
		return *this;
	}
	inline HashString& operator +=(const HashString& other) {
		string::operator+=(other);
		build();
		return *this;
	}
	inline bool operator ==(const HashString& other) const {
		return hh.back() == other.hh.back();
	}
	inline bool operator <(const HashString& other) const {
		int s1 = size();
		int s2 = other.size();
		const int S = min(s1, s2);
		int l = 0, r = S + 1;
		while (r - l > 1) {
			int xx = (r + l) / 2;
			if (getHash(0, xx) == other.getHash(0, xx)) l = xx; else
				r = xx;
		}
		char c1 = 0, c2 = 0;
		if (l < s1) c1 = (*this)[l];
		if (l < s2) c2 = other[l];
		return c1 < c2;
	}
	inline bool operator <=(const HashString& other) const {
		return (*this == other) || (*this < other);
	}
	inline bool operator >(const HashString& other) const {
		return !(*this == other) && !(*this < other);
	}
	inline bool operator >=(const HashString& other) const {
		return !(*this < other);
	}
	inline bool operator !=(const HashString& other) const {
		return !(*this == other);
	}
	inline void reserve(int N) {
		hh.reserve(N);
		string::reserve(N);
	}

	vector<H> hh;
	static vector<H> pp, invpp;

private:
	mutable H register_, id7;
	static int haveN;
};
template<>
int HashString<Hash>::haveN = 0;
template<>
vector<Hash> HashString<Hash>::pp = vector<Hash>();
template<>
vector<Hash> HashString<Hash>::invpp = vector<Hash>();


template<class H, bool cyclic = true>
struct id1 {
	explicit id1(const HashString<H>& s, int pos, int len) : s(s), pos(pos), len(len), hash(H::INVALID) {}
	inline H getHash() const {
		if (hash == H::INVALID) hash = s.getHash(pos, len);
		return hash;
	}
	inline H getPartialHash(int needLen) const {
		return s.getHash(pos, needLen);
	}
	inline char getChar(int i) const {
		i += pos;
		const int S = s.size();
		if (i < S) return s[i];
		if (!cyclic) return 0;
		i -= S;
		if (i < S) return s[i];
		return s[i % S];
	}
	const HashString<H>& s;
	const int pos, len;
	mutable H hash;
};

template<class H, class T>
char id3(T beg, T en, int pos) {
	for (T it = beg; it != en; ++it) {
		if (pos < it->len) {
			return it->getChar(pos);
		}
		pos -= it->len;
	}
	return 0;
}

template<class H, class T>
H id6(T beg, T en, int len) {
	H ans = H::ZERO;
	int cur = 0;
	for (T it = beg; it != en; ++it) {
		if (len >= it->len) {
			ans += it->getHash() * it->s.getPow(cur);
			cur += it->len;
			len -= it->len;
		}
		else {
			ans += it->getPartialHash(len) * it->s.getPow(cur);
			break;
		}
	}
	return ans;
}

int TB, IT;
template<class H, class T>
inline int id0(T beg1, T en1, int len1, T beg2, T en2, int len2) {
	if (beg1 == en1 && beg2 == en2) return 0;
	if (beg1 == en1) return -1;
	if (beg2 == en2) return 1;
	int l = 0, r = min(len1, len2) + 1;
	while (r - l > 1) {
		int xx = (r + l) / 2;
		auto h1 = id6<H, T>(beg1, en1, xx);
		auto h2 = id6<H, T>(beg2, en2, xx);
		if (h1 == h2) l = xx; else
		r = xx;
	}
	char c1 = id3<H, T>(beg1, en1, l);
	char c2 = id3<H, T>(beg2, en2, l);
	if (c1 < c2) return -1; else
	if (c1 == c2) return 0; else
	return 1;
}

template<class H, class T>
inline int id0(T beg1, T en1, T beg2, T en2) {
	int len1 = 0;
	for (T it = beg1; it != en1; ++it) {
		len1 += it->len;
	}
	
	int len2 = 0;
	for (T it = beg2; it != en2; ++it) {
		len2 += it->len;
	}
	return id0<H, T>(beg1, en1, len1, beg2, en2, len2);
}


int a, b, c, d, n, m, k;
char str[1000002];
int bal[2000002];
HashString<Hash> s;

inline string build(pair<pii, int> a) {
	string ans = "";
	rept(i, a.x.x) ans += '(';
	rept(i, n) {
		int cur = a.y + i;
		if (cur >= n) cur -= n;
		ans += str[cur];
	}
	rept(i, a.x.y) ans += ')';
	return ans;
}

HashString<Hash> op, cl;
inline bool better(pair<pii, int> a, pair<pii, int> b, const HashString<Hash>& s) {
	id1<Hash> A[3] = { id1<Hash>(op, 0, a.x.x),
		id1<Hash>(s, a.y, n),
		id1<Hash>(cl, 0, a.x.y) };

	id1<Hash> B[3] = { id1<Hash>(op, 0, b.x.x),
		id1<Hash>(s, b.y, n),
		id1<Hash>(cl, 0, b.x.y) };

	int t = id0<Hash>(A, A + 3, B, B + 3);
	if (t == -1) return 1; else
		return 0;
}
int main() {
	

	


	gets(str);
	n = (int)strlen(str);
	

	

	HashString<Hash> s(str);
	HashString<Hash>::precalc(2 * n + 1);
	op.reserve(n + 1);
	cl.reserve(n + 1);
	rept(i, n) {
		op += '(';
		cl += ')';
	}

	c = 0;
	rept(i, n) {
		if (str[i] == '(') ++c; else
			--c;
	}
	bal[0] = 0;
	rept(i, 2 * n) {
		if (i) bal[i] = bal[i - 1];
		int cur = i;
		if (i >= n) cur = i - n;
		if (str[cur] == '(') ++bal[i]; else
			--bal[i];
	}
	int blen = INF;
	pair<pii, int> best = mp(mp(0, 0), 0);
	stack< pair<int, int> > s1, s2;
	rept(i, n) {
		int new_element = bal[i];
		int minima = s1.empty() ? new_element : min(new_element, s1.top().second);
		s1.push(make_pair(new_element, minima));
	}
	rept(cyc, n) {
		int id2 = -INF;
		if (s1.empty() || s2.empty())
			id2 = s1.empty() ? s2.top().second : s1.top().second;
		else
			id2 = min(s1.top().second, s2.top().second);

		int p = 0;
		if (cyc) p = bal[cyc - 1];
		int mn = id2 - p;
		int beg = max(0, -mn);
		int en = c + beg;
		int len = beg + en + n;
		if (len < blen || (len == blen && better(mp(mp(beg, en), cyc), best, s))) {
			blen = len;
			best = mp(mp(beg, en), cyc);
		}

		if (s2.empty()) {
			while (!s1.empty()) {
				int element = s1.top().first;
				s1.pop();
				int minima = s2.empty() ? element : min(element, s2.top().second);
				s2.push(make_pair(element, minima));
			}
		}
		s2.pop();
		int new_element = bal[cyc + n];
		int minima = s1.empty() ? new_element : min(new_element, s1.top().second);
		s1.push(make_pair(new_element, minima));
	}
	string ans = build(best);
	printf("%s\n", ans.c_str());

	

	

}
