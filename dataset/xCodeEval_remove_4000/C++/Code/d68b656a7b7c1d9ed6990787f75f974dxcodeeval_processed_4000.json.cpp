








typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace __gnu_pbds;

template <typename A, typename B = std::less <A>> using ordered_set =
tree <A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B, typename C = std::less <A>> using ordered_map =
tree <A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

void prep();
void solv(const int curt);

const bool isT = false;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	prep();
	
	int t = 1; if (isT) { std::cin >> t; }
	for (int i = 1; i <= t; i++) { solv(i); }
	
	return 0;
}

template <typename A> std::string bs(A x, int digs) {
	std::string r(digs, '0');
	for (int i = 0; i < digs; i++) {
		r[digs - i - 1] += (x >> i) & 1;
	}
	return r;
}

template <typename A> std::string bs(A x) {
	std::string r;
	while (x) {
		r += (x & 1) + '0';
		x >>= 1;
	}
	std::reverse(r.begin(), r.end());
	return r;
}

namespace dbg_pr {
	
	std::string to_string(const std::string& s);
	std::string to_string(const char* s);
	std::string to_string(const bool& b);
	std::string to_string(const char& c);
	std::string to_string(const std::vector <bool>& v);
	template <typename A> std::string to_string(A x);
	template <typename A, typename B> std::string to_string(std::pair <A, B> p);
	template <typename A> std::string to_string(const std::vector <A>& v);
	template <typename A> std::string to_string(const std::set <A>& st);
	template <typename A, typename B> std::string to_string(const std::set <A, B>& st);
	template <typename A> std::string to_string(const std::unordered_set <A>& st);
	template <typename A, typename B> std::string to_string(const std::unordered_set <A, B>& st);
	template <typename A, typename B> std::string to_string(const std::map <A, B>& mp);
	template <typename A, typename B, typename C> std::string to_string(const std::map <A, B, C>& mp);
	template <typename A, typename B> std::string to_string(const std::unordered_map <A, B>& mp);
	template <typename A, typename B, typename C> std::string to_string(const std::unordered_map <A, B, C>& mp);
	template <typename A> std::string to_string(const std::queue <A>& q);
	template <typename A> std::string to_string(const std::priority_queue <A>& pq);
	template <typename A, typename B, typename C> std::string to_string(const std::priority_queue <A, B, C>& pq);
	template <typename A> std::string to_string(const std::stack <A>& stck);
	template <typename A> std::string to_string(const std::deque <A>& q);
	template <typename A, size_t size> std::string to_string(const std::array <A, size>& a);
	template <typename A, typename B> std::string to_string(const __gnu_pbds::tree <A, __gnu_pbds::null_type, B, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& st);
	template <typename A, typename B, typename C> std::string to_string(const __gnu_pbds::tree <A, B, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& mp);
	
	std::string to_string(const std::string& s) {
		return '"' + s + '"';
	}
	
	std::string to_string(const char* s) {
		return to_string((std::string)s);
	}
	
	std::string to_string(const bool& b) {
		return b ? "true" : "false";
	}
	
	std::string to_string(const char& c) {
		return (std::string)"'" + c + "'";
	}
	
	std::string to_string(const std::vector <bool>& v) {
		if (v.empty()) {
			return "{ }";
		}
		std::string ret = "{";
		for (auto it = v.begin(); it != v.end(); it++) {
			ret += to_string(*it) + (next(it) == v.end() ? "}" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(A x) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(3) << x;
		return stream.str();
	}
	
	template <typename A, typename B> std::string to_string(std::pair <A, B> p) {
		return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}
	
	template <typename A> std::string to_string(const std::vector <A>& v) {
		if (v.empty()) {
			return "{ }";
		}
		std::string ret = "{";
		for (auto it = v.begin(); it != v.end(); it++) {
			ret += to_string(*it) + (next(it) == v.end() ? "}" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::set <A>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::set <A, B>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::unordered_set <A>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::unordered_set <A, B>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::map <A, B>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::map <A, B, C>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::unordered_map <A, B>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::unordered_map <A, B, C>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::queue <A>& q) {
		if (q.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto Q = q;
		while (!Q.empty()) {
			auto now = Q.front();
			Q.pop();
			ret += to_string(now) + (Q.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::priority_queue <A>& pq) {
		if (pq.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto PQ = pq;
		while (!PQ.empty()) {
			auto now = PQ.top();
			PQ.pop();
			ret += to_string(now) + (PQ.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::priority_queue <A, B, C>& pq) {
		if (pq.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto PQ = pq;
		while (!PQ.empty()) {
			auto now = PQ.top();
			PQ.pop();
			ret += to_string(now) + (PQ.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::stack <A>& stck) {
		if (stck.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto STCK = stck;
		while (!STCK.empty()) {
			auto now = STCK.top();
			STCK.pop();
			ret += to_string(now) + (STCK.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::deque <A>& q) {
		if (q.empty()) {
			return "[ ";
		}
		std::string ret = "[";
		for (auto it = q.begin(); it != q.end(); it++) {
			ret += to_string(*it) + (next(it) == q.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, size_t size> std::string to_string(const std::array <A, size>& a) {
		std::string ret = "(";
		for (size_t i = 0; i < size; i++) {
			ret += to_string(a[i]) + (i + size_t(1) == size ? ")" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const __gnu_pbds::tree <A, __gnu_pbds::null_type, B, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const __gnu_pbds::tree <A, B, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	void debug_out() {
		std::cerr << std::endl;
	}
	
	template <typename A, typename... B> void debug_out(A a, B... b) {
		std::cerr << "\033[96m " << to_string(a) << "\033[0m";
		debug_out(b...);
	}
	
	void id0() {
		std::cerr << std::endl;
	}
	
	void id1(const int cnt = 1) {
		for (int i = 0; i < cnt; i++) {
			std::cerr << " ";
		}
	}
	
	template <typename A> void id0(A a) {
		for (auto it = a.begin(); it != a.end(); it++) {
			id1(1);
			std::cerr << "\033[96m[ " << to_string(*it) << " ]\033[0m" << std::endl;
		}
	}
	
}









void prep() {
	
}

template <typename node> class id2 {
	
public:
	
	int size, n_size;
	std::vector <node> v;
	
	id2(int _size) :
	n_size(_size)
	{
		assert(_size > 0);
		size = 1;
		while (size < _size) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make();
	}
	
	template <typename A> id2(const std::vector <A>& _v) :
	n_size(_v.size())
	{
		assert(!_v.empty());
		size = 1;
		while (size < (int)_v.size()) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make(_v);
	}
	
	template <typename A> id2(int _size, const std::vector <A>& _v) :
	n_size(_size)
	{
		assert(_size > 0);
		size = 1;
		while (size < _size) {
			size <<= 1;
		}
		v.resize(size << 1, node { });
		make(_v);
	}
	
	void make() {
		m_make(0, 0, size);
	}
	
	template <typename A> void make(const std::vector <A>& _v) {
		m_make(_v, 0, 0, size);
	}
	
	template <typename A> void update(int l, int r, const A& arg) {
		assert(l >= 0 && l < r && r <= size);
		m_update(l, r, 0, 0, size, arg);
	}
	
	template <typename A> void update(const A& arg) {
		update(0, n_size, arg);
	}
	
	node query(int l, int r) {
		assert(l >= 0 && l < r && r <= size);
		return m_query(l, r, 0, 0, size);
	}
	
	node query() {
		return query(0, n_size);
	}
	
	int find_first(int l, int r, const std::function <bool(const node&)>& check) {
		assert(l >= 0 && l < r && r <= size);
		return m_find_first(l, r, 0, 0, size, check);
	}
	
	int find_first(const std::function <bool(const node&)>& check) {
		return find_first(0, n_size, check);
	}
	
	int find_last(int l, int r, const std::function <bool(const node&)>& check) {
		assert(l >= 0 && l < r && r <= size);
		return m_find_lsat(l, r, 0, 0, size, check);
	}
	
	int find_last(const std::function <bool(const node&)>& check) {
		return find_last(0, n_size, check);
	}
	
private:
	
	inline int m_mid(int l, int r) {
		return (l + r) >> 1;
	}
	
	inline bool m_outside(int l, int r, int tl, int tr) {
		return l >= tr || r <= tl;
	}
	
	inline node* m_child(int ind, int l, int r) {
		return r - l - 1 ? &v[ind] : nullptr;
	}
	
	inline void m_push(int now, int l, int r) {
		v[now].push(m_child((now << 1) + 1, l, r), m_child((now << 1) + 2, l, r), l, r);
	}
	
	void m_make(int now, int l, int r) {
		if (!(r - l - 1)) {
			return;
		}
		int mid = m_mid(l, r);
		m_make((now << 1) + 1, l, mid);
		m_make((now << 1) + 2, mid, r);
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
	}
	
	template <typename A> void m_make(const std::vector <A>& _v, int now, int l, int r) {
		if (!(r - l - 1)) {
			if (l < (int)_v.size()) {
				v[now].apply(_v[l], l, r);
				m_push(now, l, r);
			}
			return;
		}
		int mid = m_mid(l, r);
		m_make(_v, (now << 1) + 1, l, mid);
		m_make(_v, (now << 1) + 2, mid, r);
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
		
	}
	
	template <typename A> void m_update(int tl, int tr, int now, int l, int r, const A& arg) {
		m_push(now, l, r);
		if (l >= tr || r <= tl) {
			return;
		}
		if (l >= tl && r <= tr) {
			v[now].apply(arg, l, r);
			m_push(now, l, r);
			return;
		}
		int mid = m_mid(l, r);
		m_update(tl, tr, (now << 1) + 1, l, mid, arg);
		m_update(tl, tr, (now << 1) + 2, mid, r, arg);
		v[now] = node::merge(v[(now << 1) + 1], v[(now << 1) + 2]);
	}
	
	node m_query(int tl, int tr, int now, int l, int r) {
		m_push(now, l, r);
		if (l >= tl && r <= tr) {
			return v[now];
		}
		int mid = m_mid(l, r);
		node ret = node { };
		if (m_outside(l, mid, tl, tr)) {
			ret = m_query(tl, tr, (now << 1) + 2, mid, r);
		} else {
			if (m_outside(mid, r, tl, tr)) {
				ret = m_query(tl, tr, (now << 1) + 1, l, mid);
			} else {
				ret = node::merge(
				m_query(tl, tr, (now << 1) + 1, l, mid),
				m_query(tl, tr, (now << 1) + 2, mid, r));
			}
		}
		return ret;
	}
	
	int m_find_first_exists(int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		m_push(now, l, r);
		if (!(r - l - 1)) {
			return l;
		}
		int mid = m_mid(l, r);
		m_push((now << 1), l, mid);
		if (check(v[(now << 1) + 1])) {
			return m_find_first_exists((now << 1) + 1, l, mid, check);
		}
		return m_find_first_exists((now << 1) + 2, mid, r, check);
	}
	
	int m_find_first(int tl, int tr, int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		m_push(now, l, r);
		if (l >= tl && r <= tr) {
			if (!check(v[now])) {
				return -1;
			}
			return m_find_first_exists(now, l, r, check);
		}
		int mid = m_mid(l, r);
		if (!m_outside(l, mid, tl, tr)) {
			return m_find_first(tl, tr, (now << 1) + 1, l, mid, check);
		}
		if (!m_outside(mid, r, tl, tr)) {
			return m_find_first(tl, tr, (now << 1) + 2, mid, r, check);
		}
		return -1;
	}
	
	int m_find_last_exists(int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		v[now].push(m_child((now << 1) + 1, l, r), m_child((now << 1) + 2, l, r), l, r);
		if (!(r - l - 1)) {
			return l;
		}
		int mid = m_mid(l, r);
		m_push((now << 1) + 2, mid, r);
		if (check(v[(now << 1) +2 ])) {
			return m_find_last_exists((now << 1) + 2, mid, r, check);
		}
		return m_find_last_exists((now << 1) + 1, l, mid, check);
	}
	
	int m_find_last(int tl, int tr, int now, int l, int r,
	const std::function <bool(const node&)>& check) {
		m_push(now, l, r);
		if (l >= tl && r <= tr) {
			if (!check(v[now])) {
				return -1;
			}
			return m_find_last_exists(now, l, r, check);
		}
		int mid = m_mid(l, r);
		if (!m_outside(mid, r, tl, tr)) {
			return m_find_last(tl, tr, (now << 1) + 2, mid, r, check);
		}
		if (!m_outside(l, mid, tl, tr)) {
			return m_find_last(tl, tr, (now << 1) + 1, l, mid, check);
		}
		return -1;
	}
	
};

struct Node {
	int v = -(1 << 29), w = -1;
	inline void push(Node* x, Node* y, int l, int r) {
		if (w == -1) {
			return;
		}
		v = w;
		if (x && y) {
			x->w = w;
			y->w = w;
		}
		w = -1;
	}
	inline void apply(int val, int l, int r) {
		w = val;
	}
	static inline Node merge(const Node& x, const Node& y) {
		return { std::min(x.v, y.v), -1 };
	}
};
 
bool cmp(const std::pair <std::pair <int, int>, int>& a, const std::pair <std::pair <int, int>, int>& b) {
	return std::make_pair(a.second, a.first) < std::make_pair(b.second, b.first);
}

void solv(const int curt) {
	
	int n, m; std::cin >> n >> m;
	std::vector <std::pair <std::pair <int, int>, int>> a(n);
	for (auto& p : a) {
		std::cin >> p.first.first >> p.first.second >> p.second;
	}
	std::sort(a.begin(), a.end(), cmp);
	id2 <Node> seg(m + 2);
	int ans = 1 << 29;
	for (int i = 0; i < n; i++) {
		int l = a[i].first.first, r = a[i].first.second, w = a[i].second;
		seg.update(l, r, w);
		ans = std::min(ans, w - seg.query(1, m).v);
	}
	std::cout << ans << "\n";
	
}
