

using namespace std;




using namespace __gnu_pbds;


	{                                            \
		string _s = 
		replace(_s.begin(), _s.end(), ',', ' '); \
		stringstream _ss(_s);                    \
		istream_iterator<string> _it(_ss);       \
		err(_it, args);                          \
	}
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}





const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
template <typename T>
struct chash
{
	int operator()(T x) { return hash<T>{}(x ^ RANDOM); }
};

template <typename T, typename Cmp = less<T>>
using oset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U, typename Cmp = less<T>>
using omap = tree<T, U, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

inline void read_(int i)
{
	return;
}
template <typename T, typename... Args>
inline void read_(int i, T &C, Args &... args)
{
	cin >> C[i];
	read_(i, args...);
}
template <typename T, typename... Args>
inline void read(T &C, Args &... args)
{
	rep(i, 0, Size(C))
	{
		cin >> C[i];
		read_(i, args...);
	}
}

inline void dec()
{
	return;
}
template <typename T, typename... Args>
inline void dec(T &C, Args &... args)
{
	for (auto &x : C)
	{
		x--;
	}
	dec(args...);
}

typedef long long lint;
typedef complex<double> point;

const mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f;
const lint INFL = 0x3f3f3f3f3f3f3f3fLL;
const double E = 1e-9, pi = 2 * acos(0);

template<typename Path> struct Centroid {
	vector<vector<int>> adj; vector<int> subtreesize;
	vector<bool> mark; vector<int> outer, layer;
	vector<vector<int>> newid; Path id7;
	vector<vector<Path>> paths;
	bool id0;
	vector<vector<Path>> adj_;
	
	

	inline void init(const vector<vector<int>> &_adj, Path id6 = Path(), const vector<vector<Path>> &_adj_ = {}) {
		adj = _adj;
		int n = adj.size();
		subtreesize.resize(n);
		mark.resize(n);
		outer.resize(n);
		layer.resize(n);
		newid.resize(n);
		id7 = id6;
		paths.resize(n);
		adj_ = _adj_;
		id0 = adj_.empty();
	}

	template<typename Func>
	void decompose(Func add, int v = 0, int o = -1, int l = 0) {
		int treesize = dfs1(v, -1);
		int c = dfs2(v, -1, treesize);
		mark[c] = true, outer[c] = o, layer[c] = l;
		paths[c].reserve(treesize);
		dfs3(c, -1, c, id0 ? add(id7, c, id7) : id7, add);
		for (int u: adj[c]) if (!mark[u]) 
			decompose(add, u, c, l + 1);
		if (l == 0) dfs1(v, -1);
	}

	int dfs1(int v, int p) {
		subtreesize[v] = 1;
		for (int u: adj[v]) if (u != p && !mark[u]) 
			subtreesize[v] += dfs1(u, v);
		return subtreesize[v];
	}

	int dfs2(int v, int p, int treesize) {
		for (int u: adj[v]) 
			if (u != p && !mark[u] && 2 * subtreesize[u] > treesize) 
				return dfs2(u, v, treesize);
		return v;
	}

	template<typename Func>
	void dfs3(int v, int p, int c, Path path, Func add) {
        newid[v].push_back(paths[c].size());
		paths[c].push_back(path);
		for (int i = 0; i < (int)adj[v].size(); i++) {
			int u = adj[v][i];
			if (u != p && !mark[u]) {
				Path w = id0 ? id7 : adj_[v][i];
                dfs3(u, v, c, add(path, u, w), add);
			}
		}
	}

	inline int get_id(int v, int c) { return newid[v][layer[c]]; }

	inline Path get_partial_path(int v, int c) {
		return paths[c][get_id(v, c)];
	}

	inline int lco(int a, int b) {
		while (a != b) if (layer[a] > layer[b]) a = outer[a]; 
					   else b = outer[b];
		return a;
	}

	inline pair<Path, Path> get_path(int a, int b) {
		int c = lco(a, b);
		return {paths[c][get_id(a, c)], paths[c][get_id(b, c)]};
	}

	inline vector<vector<int>> get_centroid_tree() {
		vector<vector<int>> graph(adj.size());
		for (int i = 0; i < (int)adj.size(); i++) {
			if (outer[i] != -1) {
				graph[outer[i]].push_back(i);
			}
		}
		return move(graph);
	}
};

int MOD;

vector<int> pow10, id5;

struct Info {
	int dir, inv, size;

	Info(): dir(0), inv(0), size(0) {}

	Info(int dir, int inv, int size): dir(dir), inv(inv), size(size) {}

	Info operator+(const Info &other) const {
		Info res(
			((lint)dir * pow10[other.size] + other.dir) % MOD, 
			((lint)other.inv * pow10[size] + inv) % MOD,
			size + other.size
		);
        return res;
	}
};



template <typename T, typename U, typename B>
struct NumberTheory
{
    mt19937_64 rand_eng;
    T gcd(T a, T b)
    {
        return a ? gcd(b % a, a) : b;
    }
    

    T egcd(T a, T b, T &x, T &y)
    {
        if (a == 0)
        {
            x = 0, y = 1;
            return b;
        }
        else
        {
            T ret = egcd(b % a, a, y, x);
            x -= y * (b / a);
            return ret;
        }
    }
    

    T mod(T x, T n)
    {
        return (x %= n) >= 0 ? x : x + n;
    }
    T inv(T a, T n)
    {
        T x, y, g = egcd(a, n, x, y);
        assert(g == 1);
        return (x %= n) >= 0 ? x : x + n;
    }
    

    T pow(T x, U y, T mod)
    {
        T ret = 1 % mod, id4 = x % mod;
        while (y)
        {
            if (y % 2)
                ret = (B)ret * id4 % mod;
            y /= 2;
            id4 = (B)id4 * id4 % mod;
        }
        return ret;
    }
    

    

    U chinese_remainder(const vector<T> &inmods, const vector<T> &invals)
    {
        U mod = 1, result = 0;
        for (U v : inmods)
            mod *= v;
        for (int i = 0; i < (int)inmods.size(); ++i)
        {
            T inmod = inmods[i];
            if (inmod == 1)
                continue;
            U unit = mod / inmod;
            unit = (B)unit * inv(unit % inmod, (U)inmod) % mod;
            result = (result + (B)unit * invals[i]) % mod;
        }
        return result;
    }
    bool is_prime(T n)
    {
        if (n <= 1)
            return false;
        if (n % 2 == 0)
            return n == 2;
        for (T i = 3; i <= n / i; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
    

    bool is_probable_prime(T p)
    {
        if (p <= 1)
            return false;
        if (p % 2 == 0)
            return p == 2;
        uniform_int_distribution<T> rand_gen(1, p - 1);
        for (int rep = 0; rep < 100; ++rep)
        {
            T a = rand_gen(rand_eng);
            if (!is_probable_prime(p, a))
                return false;
        }
        return true;
    }
    bool is_probable_prime(T p, T a)
    {
        if (p <= 1)
            return false;
        if (p % 2 == 0)
            return p == 2;
        T phi = p - 1, d = phi;
        int s;
        for (s = 0; d % 2 == 0; ++s)
            d /= 2;
        T ad = pow(a, d, p);
        if (ad == 1)
            return true;
        T id2 = ad;
        for (int r = 0; r < s; ++r)
        {
            if (id2 == p - 1)
                return true;
            id2 = (B)id2 * id2 % p;
        }
        return false;
    }
    

    vector<pair<T, int>> factorize(T n)
    {
        assert(n > 0);
        vector<pair<T, int>> ret;
        if (n % 2 == 0)
        {
            int exp;
            for (exp = 0; n % 2 == 0; ++exp)
                n /= 2;
            ret.push_back({2, exp});
        }
        for (T p = 3; p <= n / p; p += 2)
            if (n % p == 0)
            {
                int exp;
                for (exp = 0; n % p == 0; ++exp)
                    n /= p;
                ret.push_back({p, exp});
            }
        if (n != 1)
            ret.push_back({n, 1});
        return ret;
    }
    

    

    vector<pair<T, int>> pollard_rho(T __n)
    {
        assert(__n >= 1);
        vector<T> factors;
        function<void(T)> run = [&](T n) {
            while (n % 2 == 0)
            {
                factors.push_back(2);
                n /= 2;
            }
            while (n % 5 == 0)
            {
                factors.push_back(5);
                n /= 5;
            }
            if (n == 1)
                return;
            if (is_probable_prime(n))
            {
                factors.push_back(n);
                return;
            }
            uniform_int_distribution<T> rand_gen(0, n - 1);
            while (true)
            {
                T x = rand_gen(rand_eng), y = x;
                do
                {
                    x = ((B)x * x + 1) % n;
                    y = ((B)y * y + 1) % n;
                    y = ((B)y * y + 1) % n;
                    T g = gcd(abs(x - y), n);
                    if (1 < g && g < n)
                    {
                        run(g);
                        run(n / g);
                        return;
                    }
                } while (x != y);
            }
        };
        run(__n);
        vector<pair<T, int>> result;
        sort(factors.begin(), factors.end());
        int j = 0;
        for (int i = j; i != (int)factors.size(); i = j)
        {
            while (j != (int)factors.size() && factors[j] == factors[i])
                ++j;
            result.push_back({factors[i], j - i});
        }
        return result;
    }
    

    T calc_phi(T n)
    {
        T result = n;
        for (auto &pexp : factorize(n))
        {
            T &p = pexp.first;
            result = result / p * (p - 1);
        }
        return result;
    }

    inline bool is_generator(T a, T n)
    {
        return is_generator(a, n, calc_phi(n));
    }

    inline bool is_generator(T a, T n, T phi)
    {
        return is_generator(a, n, phi, factorize(phi));
    }

    bool is_generator(T a, T n, T phi, const vector<pair<T, int>> &id1)
    {
        if (gcd(a, n) != 1)
            return false;
        for (auto &pexp : id1)
            if (pow(a, phi / pexp.first, n) == 1 % n)
                return false;
        return true;
    }

    inline T find_generator(T n)
    {
        return find_generator(n, calc_phi(n));
    }

    inline T find_generator(T n, T phi)
    {
        return find_generator(n, phi, factorize(phi));
    }

    T find_generator(T n, T phi, const vector<pair<T, int>> &id1)
    {
        uniform_int_distribution<T> rand_gen(0, n - 1);
        for (int rep = 0; rep < 100; ++rep)
        {
            T a = rand_gen(rand_eng);
            if (is_generator(a, n, phi, id1))
                return a;
        }
        return -1;
    }

    tuple<T, T> linear_equation(T a, T b, T n)
    {
        T g = gcd(a, n);
        if (b % g != 0)
            return make_tuple((T)-1, (T)-1);
        T x = (B)inv(a / g, n / g) * (b / g) % (n / g);
        return make_tuple(x, n / g);
    }

    T __ratiosumfloor(vector<T> ups, vector<T> downs)
    {
        int n = ups.size();
        if (n == 0)
            return 0;
        else
        {
            T up = ups.back(), down = downs.back();
            T result = 0;
            B rest = up;
            for (int i = 0; i < n - 1; ++i)
            {
                rest += (B)down * ups[i] / downs[i];
                if (rest >= down)
                    rest -= down, ++result;
                ups[i] = (B)down % downs[i] * ups[i] % downs[i];
            }
            ups.pop_back();
            downs.pop_back();
            T remain = __ratiosumfloor(ups, downs);
            result += remain / down;
            rest += remain % down;
            if (rest >= down)
                rest -= down, ++result;
            return result;
        }
    }

    T ratiosumfloor(vector<T> ups, vector<T> downs)
    {
        T result = 0;
        for (int i = 0; i < (int)ups.size(); ++i)
        {
            result += ups[i] / downs[i];
            ups[i] %= downs[i];
        }
        return result + __ratiosumfloor(ups, downs);
    }

    T chinese_reminder(const vector<T> &inmods, const vector<T> &invals, T outmod)
    {
        const int n = inmods.size();
        T multall = 1 % outmod;
        for (T v : inmods)
            multall = (B)multall * (v % outmod) % outmod;
        T result = 0;
        vector<T> value(n);
        for (int i = 0; i < n; ++i)
        {
            T mul = 1 % inmods[i], mul2 = 1 % outmod;
            for (int j = 0; j < n; ++j)
                if (j != i)
                {
                    mul = (B)mul * (inmods[j] % inmods[i]) % inmods[i];
                    mul2 = (B)mul2 * (inmods[j] % outmod) % outmod;
                }
            value[i] = (B)inv(mul, inmods[i]) * invals[i] % inmods[i];
            result = (result + (B)value[i] * mul2) % outmod;
        }
        T q = ratiosumfloor(value, inmods);
        result = (result - (B)q * multall) % outmod;
        if (result < 0)
            result += outmod;
        return result;
    }
};

NumberTheory<int, unsigned, lint> NT;

int inverse(int x) {
	return NT.pow(x, NT.calc_phi(MOD) - 1, MOD);
}

void preprocess(int n) {
	pow10.resize(n);
	id5.resize(n);
	pow10[0] = id5[0] = 1 % MOD;
	int inv10 = inverse(10 % MOD);
	rep(i, 1, n) {
		pow10[i] = (lint)pow10[i - 1] * 10 % MOD;
		id5[i] = (lint)id5[i - 1] * inv10 % MOD;
	}
}

vector<vector<pair<int, int>>> graph;
vector<vector<int>> adj, id3, children;
vector<vector<Info>> adj_;
Centroid<Info> centroid;
unordered_map<int, int> counter;

void dfs(int u, int p) {
	for (auto ed: graph[u]) {
		int v = ed.first, w = ed.second;
		if (v != p) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			Info info(w, w, 1);
			adj_[u].push_back(info);
			adj_[v].push_back(info);
			dfs(v, u);
		}
	}
}

lint calc(int u) {
	lint res = 0;
	for (int v: id3[u]) {
		res += calc(v);
	}
	counter.clear();
	for (Info x: centroid.paths[u]) {
		counter[x.inv]++;
	}
	res += counter[0] - 1;
	children[u].push_back(u);
	for (int v: id3[u]) {
		for (int c: children[v]) {
			counter[centroid.get_partial_path(c, u).inv]--;
		}
		for (int c: children[v]) {
			Info aux = centroid.get_partial_path(c, u);
			int want = (lint)(MOD - aux.dir) * id5[aux.size] % MOD;
			res += counter[want];
		}
		for (int c: children[v]) {
			counter[centroid.get_partial_path(c, u).inv]++;
		}
		children[u].insert(children[u].end(), children[v].begin(), children[v].end());
		children[v].clear();
	}
	return res;
}

bool solve(int testNumber)
{
	int n;
	if (not (cin >> n >> MOD)) {
		return false;
	}
	preprocess(n);
	graph.assign(n, {});
	adj.assign(n, {});
	adj_.assign(n, {});
	children.assign(n, {});
	rep(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		w %= MOD;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	dfs(0, -1);
	centroid.init(adj, Info(0, 0, 0), adj_);

	auto add = [&](Info path, int u, Info x) {
		return path + x;
	};

	centroid.decompose(add);
	id3 = centroid.get_centroid_tree();
	int root = min_element(centroid.layer.begin(), centroid.layer.end()) - centroid.layer.begin();
	lint res = calc(root);
	printf("%lld\n", res);
	return true;
}

void init(const char *in = nullptr, const char *out = nullptr)
{
	if (in)
		freopen(in, "r", stdin);
	if (out)
		freopen(out, "w", stdout);
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	for (int i = 1; solve(i); i++)
		;
	return 0;
}