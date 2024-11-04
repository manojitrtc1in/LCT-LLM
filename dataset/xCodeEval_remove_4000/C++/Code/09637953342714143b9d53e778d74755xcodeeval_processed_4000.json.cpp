










































































template<typename T> void id7(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void id7(First& first, Rest&...rest) { std::cin >> first; id7(rest...); }

template<typename T> void id5(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void id5(int n, First& first, Rest&...rest) { first.resize(n); id5(n, rest...); }
template<typename T> void id2(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void id2(int p, First& first, Rest&...rest) { std::cin >> first[p]; id2(p, rest...); }































template<typename T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<typename T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }


void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n"; }



template<class T> std::vector<std::vector<T>> VV(int n) {
	return std::vector<std::vector<T>>(n);
}
template<class T> std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
	return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}






using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;                          

constexpr int id0 = (1LL << 31) - 1;              

constexpr ll INFLL = 1LL << 60;                          

constexpr ll id8 = (1LL << 62) - 1 + (1LL << 62);  

constexpr double EPS = 1e-9;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

template<class T, size_t N> void FILL(T(&a)[N], const T& val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T& val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T>& a, const T& val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>>& a, const T& val) { for (auto& b : a) FILL(b, val); }




struct BucketIndex {
	void set(unsigned start, unsigned last) {
		this->start = l_cur = start;
		s_cur = last;
	}

	unsigned start;
	unsigned l_cur;
	unsigned s_cur;
};

template <typename T>
struct Buckets {
	Buckets(const T* beg, const T* end, int* buf)
		: size(end - beg), buf(buf) {
		const int limit = *std::max_element(beg, end) + 1;
		idx.resize(limit + 1);

		std::vector<unsigned> freq(limit + 1, 0);
		for (const T* c = beg; c != end; c++)
			++freq[*c];

		unsigned offset = 0;
		for (unsigned i = 0; i < idx.size(); i++) {
			idx[i].set(offset, offset + freq[i] - 1);
			offset += freq[i];
		}
		idx[limit].set(offset, offset);

		memset(buf, 0, size * sizeof(int));
	}

	void initS() {
		for (unsigned i = 0; i < idx.size() - 1; i++)
			idx[i].s_cur = idx[i + 1].start - 1;
	}

	void init() {
		for (unsigned i = 0; i < idx.size() - 1; i++)
			idx[i].set(idx[i].start, idx[i + 1].start - 1);
	}

	void putL(T c, int pos) { buf[idx[c].l_cur++] = pos; }
	void putS(T c, int pos) { buf[idx[c].s_cur--] = pos; }

	std::vector<BucketIndex> idx;
	const unsigned size;
	int* buf;
};

class SAIS {
	typedef std::vector<bool> SLtypes;

public:
	SAIS(const char* str) : m_buf_len(strlen(str) + 1), m_bucket_buf(new int[m_buf_len]) {
		const unsigned char* s = reinterpret_cast<const unsigned char*>(str);
		impl<unsigned char>(s, m_buf_len, m_bucket_buf);
	}

	~SAIS() {
		delete[] m_bucket_buf;
	}

	const int* sa() const { return m_bucket_buf + 1; }
	const unsigned size() const { return m_buf_len - 1; }

private:
	template <typename T>
	void impl(const T* str, const unsigned length, int* bucket_buf) {
		Buckets<T> bkt(str, str + length, bucket_buf);
		SLtypes types(length);
		classify(str, types);
		induce(str, types, bkt);

		int *s1;
		unsigned id1;
		const bool uniq = reduce(str, types, bkt, s1, id1);

		if (!uniq) {
			impl<int>(s1, id1, bkt.buf);
			for (std::size_t i = 0; i < id1; i++)
				s1[bkt.buf[i]] = i;
		}

		for (std::size_t i = 1, j = 0; i < length; i++)
			if (isLMS(i, types))
				bkt.buf[s1[j++]] = -(int)i;
		memset(bkt.buf + id1, 0, (bkt.size - id1) * sizeof(int));

		bkt.init();
		induce(str, types, id1, bkt);
	}

	template <typename T>
	void classify(const T* str, SLtypes& types) const {
		for (int i = static_cast<int>(types.size()) - 2; i >= 0; i--)
			if (str[i] < str[i + 1])      types[i] = 0;
			else if (str[i] > str[i + 1]) types[i] = 1;
			else                        types[i] = types[i + 1];
	}

	template <typename T>
	void induce(const T* str, const SLtypes& types, unsigned id6, Buckets<T>& bkt) {
		const int* ordered_lms = bkt.buf;
		for (int i = static_cast<int>(id6) - 1; i >= 0; i--)
			bkt.putS(str[-ordered_lms[i]], -ordered_lms[i]);

		id4(str, types, bkt);
	}

	template <typename T>
	void induce(const T* str, const SLtypes& types, Buckets<T>& bkt) {
		for (std::size_t i = 1; i < types.size(); i++)
			if (isLMS(i, types))
				bkt.putS(str[i], i);

		id4(str, types, bkt);
	}

	template <typename T>
	void id4(const T* str, const SLtypes& types, Buckets<T>& bkt) {
		for (std::size_t i = 0; i < types.size(); i++) {
			const int pos = bkt.buf[i] - 1;
			if (pos >= 0 && types[pos] == 1)
				bkt.putL(str[pos], pos);
		}

		bkt.initS();
		for (std::size_t i = types.size() - 1; i > 0; i--) {
			const int pos = bkt.buf[i] - 1;
			if (pos >= 0 && types[pos] == 0)
				bkt.putS(str[pos], pos);
		}
	}

	template <typename T>
	bool reduce(const T* str, const SLtypes& types, const Buckets<T>& bkt, int *& s1, unsigned& id1) {
		int *sa = bkt.buf;
		s1 = bkt.buf + bkt.size / 2;
		id1 = bkt.size - bkt.size / 2;

		unsigned sa_len = 0;
		for (unsigned i = 0; i < bkt.size; i++)
			if (bkt.buf[i] != 0 && isLMS(bkt.buf[i], types))
				sa[sa_len++] = bkt.buf[i];
		memset(s1, -1, id1 * sizeof(int));

		unsigned order = 0;
		s1[(sa[0] - 1) / 2] = order;
		for (unsigned i = 1; i < sa_len; i++)
			s1[(sa[i] - 1) / 2] = id3(str, types, sa[i - 1], sa[i]) ? order : ++order;

		id1 = std::remove(s1, s1 + id1, -1) - s1;
		return order + 1 == id1;
	}

	template <typename T>
	bool id3(const T* str, const SLtypes& types, unsigned i1, unsigned i2) const {
		for (;; i1++, i2++)
			if (str[i1] != str[i2] || types[i1] != types[i2]) return false;
			else if (isLMS(i1 + 1, types) && isLMS(i2 + 1, types))  return str[i1 + 1] == str[i2 + 1];
	}

	bool isLMS(unsigned i, const SLtypes& types) const {
		return types[i - 1] > types[i];
	}

private:
	const unsigned m_buf_len;
	int* m_bucket_buf;
};

struct SuffixArray {
private:
	std::vector<int> tmp;
	int n, k;
public:
	std::string s;
	std::vector<int> rank, sa, lcp;
	SuffixArray() {}
	SuffixArray(const std::string& s) : n(s.size()), k(1), s(s), rank(s.size() + 1), sa(s.size() + 1, s.size()), tmp(s.size() + 1), lcp(s.size() + 1) {
		SAIS sais(s.c_str());
		

		auto x(sais.sa());
		REP(i, sa.size() - 1) sa[i + 1] = x[i];
		constructLCP();
	}

	bool compareSA(int i, int j) {
		if (rank[i] != rank[j]) return rank[i] < rank[j];
		int ri = i + k <= n ? rank[i + k] : -1;
		int rj = j + k <= n ? rank[j + k] : -1;
		return ri < rj;
	}

	void constructSA() {
		for (int i = 0; i <= n; ++i) {
			sa[i] = i;
			rank[i] = i < n ? s[i] : -1;
		}

		for (k = 1; k <= n; k *= 2) {
			std::sort(sa.begin(), sa.end(), [&](int i, int j) {return compareSA(i, j); });
			tmp[sa[0]] = 0;
			for (int i = 1; i <= n; ++i) {
				tmp[sa[i]] = tmp[sa[i - 1]] + compareSA(sa[i - 1], sa[i]);
			}
			for (int i = 0; i <= n; ++i) {
				rank[i] = tmp[i];
			}
		}
	}

	void constructLCP() {
		for (int i = 0; i <= n; ++i) rank[sa[i]] = i;

		int h = 0;
		lcp[0] = 0;
		for (int i = 0; i < n; ++i) {
			int j = sa[rank[i] - 1];
			if (h > 0) --h;
			for (; j + h < n && i + h < n; ++h) {
				if (s[j + h] != s[i + h]) break;
			}
			lcp[rank[i] - 1] = h;
		}
	}

	

	bool contain(const std::string& t) {
		int l = 0, r = s.size();
		while (r - l > 1) {
			int m = (l + r) / 2;
			

			if (s.compare(sa[m], t.size(), t) < 0) l = m;
			else r = m;
		}
	}

	void debugShow() {
		std::cerr << "idx  " << " sa  " << "LCP  " << "suffix\n";
		for (int i = 0; i < n + 1; ++i) {
			std::cerr << std::setw(3) << std::setfill(' ') << i << "  ";
			std::cerr << std::setw(3) << std::setfill(' ') << sa[i] << "  ";
			std::cerr << std::setw(3) << std::setfill(' ') << lcp[i] << "  ";
			std::cerr << s.substr(sa[i]) << "\n";
		}
	}
};

bool debug = false;

PAIR solve() {

	std::ifstream ifs("a.in");
	int n, m, k;
	std::string s, t;
	ifs >> n >> m >> k >> s >> t;

	VAR(int, n, m, k);
	VAR(std::string, s, t);


	

	auto S = s + "$" + t + "~";
	SuffixArray SS(S);
	std::vector<int> miS(std::max(m, k), INFINT);

	int baseS = 0;
	while (SS.sa[baseS] != n + 1) ++baseS;
	{ 

		if (SS.lcp[baseS] == m) {
			int idx = SS.sa[baseS + 1];
			while (idx + k + k > n) --idx;
			if (debug) { OUT(__LINE__)BR; }
			return PAIR(idx, idx + k);
		}
		if (SS.lcp[baseS - 1] == m) {
			int idx = SS.sa[baseS - 1];
			while (idx + k + k > n) --idx;
			if (debug) { OUT(__LINE__)BR; }
			return PAIR(idx, idx + k);
		}
	}
	{ 

		int p = baseS - 1;
		int mi = k;
		while (p >= 0 && SS.lcp[p] != 0) {
			CHMIN(mi, SS.lcp[p]);
			if (IN(0, SS.sa[p], n)) {
				int idx = SS.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					if (mi >= m) {
						idx = SS.sa[p];
						while (idx + k + k > n) --idx;
						if (debug) { OUT(__LINE__)BR; }
						return PAIR(idx, idx + k);
					}
					CHMIN(miS[mi], idx);
				}
			}
			--p;
		}
	}
	{ 

		int p = baseS + 1;
		int mi = k;
		int sz = SS.lcp.size();
		while (p < sz && SS.lcp[p - 1] != 0) {
			CHMIN(mi, SS.lcp[p - 1]);
			if (IN(0, SS.sa[p], n)) {
				int idx = SS.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					if (mi >= m) {
						idx = SS.sa[p];
						while (idx + k + k > n) --idx;
						if (debug) { OUT(__LINE__)BR; }
						return PAIR(idx, idx + k);
					}
					CHMIN(miS[mi], idx);
				}
			}
			++p;
		}
	}
	RFOR(i, 1, miS.size()) {
		if (miS[i] == INFINT) continue;
		int t = miS[i] - 1;
		if (t < 0) continue;
		CHMIN(miS[i - 1], t);
	}

	

	std::reverse(ALL(s));
	std::reverse(ALL(t));
	auto T = s + "$" + t + "~";
	SuffixArray TT(T);
	std::vector<int> miT(std::max(m, k), INFINT);

	int baseT = 0;
	while (TT.sa[baseT] != n + 1) ++baseT;
	{ 

		int p = baseT - 1;
		int mi = k;
		while (p >= 0 && TT.lcp[p] != 0) {
			CHMIN(mi, TT.lcp[p]);
			if (IN(0, TT.sa[p], n)) {
				int idx = TT.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					CHMIN(miT[mi], idx);
				}
			}
			--p;
		}
	}
	{ 

		int p = baseT + 1;
		int mi = k;
		int sz = TT.lcp.size();
		while (p < sz && TT.lcp[p - 1] != 0) {
			CHMIN(mi, TT.lcp[p - 1]);
			if (IN(0, TT.sa[p], n)) {
				int idx = TT.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					CHMIN(miT[mi], idx);
				}
			}
			++p;
		}
	}
	RFOR(i, 1, miT.size()) {
		if (miT[i] == INFINT) continue;
		int t = miT[i] - 1;
		if (t < 0) continue;
		CHMIN(miT[i - 1], t);
	}

	FOR(i, 1, m) { 

		int j = m - i; 

		if (miS[i] == INFINT || miT[j] == INFINT) continue;
		int ss = miS[i], tt = (n - miT[j] - 1) - k + 1;
		if (debug) {
			OUT(PAIR(ss, tt))BR;
		}
		if (ss + k - 1 < tt) {
			if (debug) { OUT(__LINE__)BR; }
			return PAIR(ss, tt);
		}
	}

	if (debug) { 
		OUT("miS")BR;
		REP(i, miS.size()) {
			if (miS[i] != INFINT) {
				OUT(i)SP OUT(miS[i])BR;
			}
		}
		OUT("miT")BR;
		REP(i, miT.size()) {
			if (miT[i] != INFINT) {
				OUT(i)SP OUT(miT[i])BR;
			}
		}
	}
	return PAIR(-1, -1);
}

signed main() {
	INIT;

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	auto p(solve());

	if (p.first == -1) {
		OUT("No")BR;
	}
	else {
		OUT("Yes")BR;
		OUT(p.first + 1)SP OUT(p.second + 1)BR;
	}

	return 0;
}