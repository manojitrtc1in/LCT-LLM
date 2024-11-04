

using namespace std;
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#ifdef bhole_ka_saaya
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
	#define booga cerr << "booga" << endl;
#else
	#define debug(...) 42;
	#define booga 42;
#endif

template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
template <typename T> std::istream& operator>>(std::istream& stream, vector<T>& vec) { for(T &x : vec)stream >> x;return stream; }
template <typename T,typename U> std::ostream& operator<<(std::ostream& stream, const pair<T,U>& pr){ stream << pr.first << ' ' << pr.second; return stream; }
template <typename T,typename U> std::istream& operator>>(std::istream& stream, pair<T,U>& pr){ stream >> pr.first >> pr.second; return stream; }
template <typename T> void operator+=(vector<T>& vec, const T value) { for(T &x : vec)x += value; }
template <typename T> void operator-=(vector<T>& vec, const T value) { for(T &x : vec)x -= value; }
template <typename T> void operator++(vector<T>& vec) { vec += 1; }
template <typename T> void operator++(vector<T>& vec,T) { vec += 1; }
template <typename T> void operator--(vector<T>& vec) { vec -= 1; }
template <typename T> void operator--(vector<T>& vec,T) { vec -= 1; }
template <typename T> void operator*=(vector<T>& vec, const T value) { for(T &x : vec)x *= value; }
template <typename T> void operator/=(vector<T>& vec, const T value) { for(T &x : vec)x /= value; }
template <typename T,typename U> void operator+=(pair<T,U>& vec, const T value) { vec.first += value;vec.second += value; }
template <typename T,typename U> void operator-=(pair<T,U>& vec, const T value) { vec.first -= value;vec.second -= value; }
template <typename T,typename U> void operator++(pair<T,U>& vec) { vec += 1; } 
template <typename T,typename U> void operator++(pair<T,U>& vec,T) { vec += 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec) { vec -= 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec,T) { vec -= 1; } 
template <typename T,typename U> void operator*=(pair<T,U>& vec, const T value) { vec.first *= value;vec.second *= value; } 
template <typename T,typename U> void operator/=(pair<T,U>& vec, const T value) { vec.first /= value;vec.second /= value; } 

template <typename A, typename B>string to_string(pair<A, B> p);
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) {string s;s += c;return s; }
string to_string(const char* s) {return to_string((string) s); }
string to_string(bool b) {return (b ? "1" : "0"); }
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void debug_out() { cerr << endl; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
void bharo(int N_N) { return; }template <typename Head, typename... Tail>void bharo(int N_N, Head &H, Tail & ... T) {H.resize(N_N);bharo(N_N,T...);}
void safai() { return; }template <typename Head, typename... Tail>void safai(Head &H, Tail & ... T) {H.clear();safai(T...);}


class segtree {
 public:
	struct node {
		

		

		int lar = 0; 

		int add = 0; 

		void apply(int l, int r, int v) { 

			lar = v;
			

		}
		void push(int l, int r, int v) { 

			lar += v;
			add += v;
		}
	};
	node unite(const node &a, const node &b) const { 

		node res;
		res.lar = max(a.lar,b.lar);
		return res;
	}
	inline void push(int x, int l, int r) {
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		if (tree[x].add != 0) {
			tree[x + 1].push(l, y, tree[x].add);
			tree[z].push(y + 1, r, tree[x].add);
			tree[x].add = 0;
		}
		
		

	}
	inline void pull(int x, int z) {
		tree[x] = unite(tree[x + 1], tree[z]);
	}

	int n;
	vector<node> tree;
	void build(int x, int l, int r) {
		if (l == r) {
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		build(x + 1, l, y);
		build(z, y + 1, r);
		pull(x, z);
	}
	template <typename M>
	void build(int x, int l, int r, const vector<M> &v) {
		if (l == r) {
			tree[x].apply(l, r, v[l]);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		build(x + 1, l, y, v);
		build(z, y + 1, r, v);
		pull(x, z);
	}
	node find(int x, int l, int r, int lx, int rx) {
		if (lx <= l && r <= rx) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		push(x, l, r);
		node res{};
		if (rx <= y) {
			res = find(x + 1, l, y, lx, rx);
		} else {
			if (lx > y) {
			res = find(z, y + 1, r, lx, rx);
			} else {
			res = unite(find(x + 1, l, y, lx, rx), find(z, y + 1, r, lx, rx));
			}
		}
		pull(x, z);
		return res;
	}
	template <typename... M>
	void update(int x, int l, int r, int lx, int rx, const M&... v) {
		if (lx <= l && r <= rx) {
			tree[x].apply(l, r, v...);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		push(x, l, r);
		if (lx <= y) {
			update(x + 1, l, y, lx, rx, v...);
		}
		if (rx > y) {
			update(z, y + 1, r, lx, rx, v...);
		}
		pull(x, z);
	}
	template <typename... M>
	void add(int x, int l, int r, int lx, int rx, const M&... v) {
		if (lx <= l && r <= rx) {
			tree[x].push(l, r, v...);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		push(x, l, r);
		if (lx <= y) {
			add(x + 1, l, y, lx, rx, v...);
		}
		if (rx > y) {
			add(z, y + 1, r, lx, rx, v...);
		}
		pull(x, z);
	}
	int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
		if (l == r) {
			return l;
		}
		push(x, l, r);
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res;
		if (f(tree[x + 1])) {
			res = find_first_knowingly(x + 1, l, y, f);
		}
		else {
			res = find_first_knowingly(z, y + 1, r, f);
		}
		pull(x, z);
		return res;
	}
	int find_first(int x, int l, int r, int lx, int rx, const function<bool(const node&)> &f) {
		if (lx <= l && r <= rx) {
			if (!f(tree[x]))return -1;
			return find_first_knowingly(x, l, r, f);
		}
		push(x, l, r);
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res = -1;
		if (lx <= y) {
			res = find_first(x + 1, l, y, lx, rx, f);
		}
		if (rx > y && res == -1) {
			res = find_first(z, y + 1, r, lx, rx, f);
		}
		pull(x, z);
		return res;
	}
	int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
		if (l == r)return l;
		push(x, l, r);
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res;
		if (f(tree[z]))res = find_last_knowingly(z, y + 1, r, f);
		else res = find_last_knowingly(x + 1, l, y, f);
		pull(x, z);
		return res;
	}
	int find_last(int x, int l, int r, int lx, int rx, const function<bool(const node&)> &f) {
		if (lx <= l && r <= rx) {
			if (!f(tree[x]))return -1;
			return find_last_knowingly(x, l, r, f);
		}
		push(x, l, r);
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res = -1;
		if (rx > y) {
			res = find_last(z, y + 1, r, lx, rx, f);
		}
		if (lx <= y && res == -1) {
			res = find_last(x + 1, l, y, lx, rx, f);
		}
		pull(x, z);
		return res;
	}
	segtree(int _n) : n(_n) {
		assert(n > 0);
		tree.resize(2 * n - 1);
		build(0, 0, n - 1);
	}
	template <typename M>
	segtree(const vector<M> &v) {
		n = v.size();
		assert(n > 0);
		tree.resize(2 * n - 1);
		build(0, 0, n - 1, v);
	}
	node find(int p) { 

		assert(0 <= p && p <= n - 1);
		return find(0, 0, n - 1, p, p);
	}
	template <typename... M>
	void update(int lx, int rx, const M&... v) {
		assert(0 <= lx && lx <= rx && rx <= n - 1);
		update(0, 0, n - 1, lx, rx, v...);
	}
	void add(int i, int v){
		assert(i >= 0 && i < n);
		add(i,i,v);
	}
	

	void update(int i, int v){ 

		assert(i >= 0 && i < n);
		update(i,i,v);
	}
	template <typename... M>
	void add(int lx, int rx, const M&... v) { 

		assert(0 <= lx && lx <= rx && rx <= n - 1);
		add(0, 0, n - 1, lx, rx, v...);
	}
	node find(int lx, int rx) { 

		assert(0 <= lx && lx <= rx && rx <= n - 1);
		return find(0, 0, n - 1, lx, rx);
	}
	

	

	int find_first(int lx, int rx, const function<bool(const node&)> &f) {
		assert(0 <= lx && lx <= rx && rx <= n - 1);
		return find_first(0, 0, n - 1, lx, rx, f);
	}
	int find_last(int lx, int rx, const function<bool(const node&)> &f) {
		assert(0 <= lx && lx <= rx && rx <= n - 1);
		return find_last(0, 0, n - 1, lx, rx, f);
	}
};


void testcase(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n*k);cin >> a;a--;
	segtree tr(n*k);
	vector<pair<int,int>> ans(n,{-1,-1});
	vector<int> last(n,-1);
	int ulim = (n + k - 2) / (k-1);
	for(int i = 0; i < n*k; i++){
		if(ans[a[i]] != make_pair(-1,-1))continue;
		if(last[a[i]] == -1)goto done;
		if(tr.find(last[a[i]],i).lar < ulim){
			ans[a[i]] = {last[a[i]],i};
			tr.add(last[a[i]],i,1);
		}
		done:
		last[a[i]] = i;
	}
	for(int i = 0; i < n; i++){
		ans[i]++;
		cout << ans[i] << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	

	while(tt--){
		testcase();
	}
	return 0;
}
