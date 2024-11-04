




using namespace __gnu_pbds;
using namespace std;













int f(ll a) {return g
using ll = long long; using ld = long double; using ull = unsigned long long;using pii = pair <short, short>;
using vpii = vector <pii>; using unt = unsigned int;sim> using min_queue = priority_queue<c, vector<c>, greater<c>>;
template <typename T>using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
sim,class N>bool mini(c&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,N h){if(o<h)ros=h,1;return 0;}

ostream & operator<<(ostream &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
ostream & operator<<(ostream &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}



sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">" bnt pta{using t=c;}; sim,int N>struct pta<c[N]>{using t=c*;};
sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){
int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}";} void dor(){cerr<<dec<<"\033[0m"<<endl;}
sim,class...N>void dor(c x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);}



sim>string bte(c u){stringstream o;o<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);
sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}

template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}
sim>c yyo(nep<c> o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}

ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}


sim>string bte(nep<c>o){ros.d+" = "+(o.m?ema(o.v):bte(o.v));}
sim oor nep<c>m){ros<<bte(rcu sim> nep<c> ngy(nep<c> o,string d="",int m=0){ros;}










ckx(+)ckx(-)ckx(!)ckx(~)







vsv,class = typename enable_if<!is_base_of<ios_base, c>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)

vsv> void operator o
vsv, class f> void operator o


clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)

ull mix(ull x){x += 0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
sim,class n>using gyv=c;namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&x)const{
return mix(hash<c>()(x.first))^hash<n>()(x.second);}};sim>struct hash<gyv<c, typename c::value_type>>
{size_t operator()(const c&x)const{size_t ans = x.size();for (auto &e : x) ans = mix(ans ^ hash<typename c::value_type>()(e));rans;}};};

sim, class m> using id0 = cc_hash_table<c, m, hash<c>>;


void fre(string c) {

	freopen((c+".in").c_str(), "r", stdin);
	freopen((c+".out").c_str(), "w", stdout);

}
const int nax = 1e3 + 44;
struct bt {
	vector <int> r, c;
	vector <array <int, 4> > ans;
	int counter;
	int n;
	int left_rows, left_cols;
	vector <vector <bool> > blocked;
	vector <vector <int> > what;
	vector <bool> done_row, done_col;
	bool is_possible() {
		counter++;
		FOR(i, 1, n) {
			if (!done_row[i]) {
				pii where = {i, 1};
				bool do_next = true;
				while (true) {
					if (where.second == n + 1) {
						if (where.first != r[i]) {
							return false;
						}
						do_next = false;
						break;
					}
					int num = what[where.first][where.second];
					if (num == -1 && !blocked[where.first][where.second]) break;
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second++;
				}
				where = {r[i], n};
				if (do_next) {
					while (true) {
						if (where.second == 0) {
							return false;
						}
						int num = what[where.first][where.second];
						if (num == -1 && !blocked[where.first][where.second]) break;
						if (num != -1) {
							auto to = ans[num];
							where.first ^= to[0] ^ to[2];
							where.second ^= to[1] ^ to[3];
						}
						where.second--;
					}
				}
			}
			if (!done_col[i]) {
				pii where = {1, i};
				bool do_next = true;
				while (true) {
					if (where.first == n + 1) {
						if (where.second != c[i]) {
							return false;
						}
						do_next = false;
						break;
					}
					int num = what[where.first][where.second];
					if (num == -1 && !blocked[where.first][where.second]) break;
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first++;
				}
				where = {n, c[i]};
				if (do_next) {
					while (true) {
						if (where.first == 0) {
							return false;
						}
						int num = what[where.first][where.second];
						if (num == -1 && !blocked[where.first][where.second]) break;
						if (num != -1) {
							auto to = ans[num];
							where.first ^= to[0] ^ to[2];
							where.second ^= to[1] ^ to[3];
						}
						where.first--;
					}
				}
			}
		}
		return true;
	}
	bt(const vector <int> &_r, const vector <int> &_c)
		: r(_r)
		, c(_c)
		, counter(0)
		, n(r.size() - 1)
		, left_rows(n)
		, left_cols(n) 
		, blocked(n + 1, vector<bool>(n + 1))
		, what(n + 1, vector<int>(n + 1, -1))
		, done_row(n + 1), done_col(n + 1)
	{
		while (!go()) {
			debug("try again");
		}
	}
	bool go() {
		if (left_rows == 1 && left_cols == 1) return true;
		if (!is_possible()) return false;
		REP(_, 3) {
			bool do_row = false;
			int i = 0;
			do {
				do_row = rand() % 2;
				if (left_rows == 1) do_row = false;
				if (left_cols == 1) do_row = true;
				i = rand() % n + 1;
			}
			while (do_row ? done_row[i] : done_col[i]);
			if (do_row) {
				vector <pii> path_start, path_end;
				pii where = {i, 1};
				while (where.second != n + 1) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_start.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second++;
				}
				if (where.first == r[i]) {
					done_row[i] = 1;
					left_rows--;
					for (pii x : path_start) blocked[x.first][x.second] = 1;
					if (go()) return true;
					done_row[i] = 0;
					left_rows++;
					for (pii x : path_start) blocked[x.first][x.second] = 0;
					continue;
				}
				where = {r[i], n};
				while (where.second != 0) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_end.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second--;
				}
				if (path_start.empty() || path_end.empty()) return false;
				vpii indices = {{0, 0}};
				if (path_start.size() >= 2u)
					indices.emplace_back(1, 0);
				if (path_end.size() >= 2u)
					indices.emplace_back(0, 1);
				if (path_start.size() >= 3u)
					indices.emplace_back(rand() % (path_start.size() - 2) + 2, rand() % path_end.size());
				if (path_end.size() >= 3u)
					indices.emplace_back(rand() % path_start.size(), rand() % (path_end.size() - 2) + 2);
				for (pii x : indices) {
					int i1 = x.first, i2 = x.second;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 1;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 1;
					int num = ans.size();
					ans.push_back({FS(path_start[i1]), FS(path_end[i2])});
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = num;
					if (go()) return true;
					ans.pop_back();
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = -1;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 0;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 0;
				}
			}
			else {
				vector <pii> path_start, path_end;
				pii where = {1, i};
				while (where.first != n + 1) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_start.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first++;
				}
				if (where.second == c[i]) {
					done_col[i] = 1;
					left_cols--;
					for (pii x : path_start) blocked[x.first][x.second] = 1;
					if (go()) return true;
					done_col[i] = 0;
					left_cols++;
					for (pii x : path_start) blocked[x.first][x.second] = 0;
					continue;
				}
				where = {n, c[i]};
				while (where.first != 0) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_end.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first--;
				}
				if (path_start.empty() || path_end.empty()) return false;
				vpii indices = {{0, 0}};
				if (path_start.size() >= 2u)
					indices.emplace_back(1, 0);
				if (path_end.size() >= 2u)
					indices.emplace_back(0, 1);
				if (path_start.size() >= 3u)
					indices.emplace_back(rand() % (path_start.size() - 2) + 2, rand() % path_end.size());
				if (path_end.size() >= 3u)
					indices.emplace_back(rand() % path_start.size(), rand() % (path_end.size() - 2) + 2);
				for (pii x : indices) {
					int i1 = x.first, i2 = x.second;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 1;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 1;
					int num = ans.size();
					ans.push_back({FS(path_start[i1]), FS(path_end[i2])});
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = num;
					if (go()) return true;
					ans.pop_back();
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = -1;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 0;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 0;
				}
			}
		}
		return false;
	}
};
vector <array <int, 4> > solve(vector <int> r, vector <int> c) {
	debug(imie(r), imie(c));
	bt b(r, c);
	return b.ans;
}
void verify(vector <int> r, vector <int> c, vector <array <int, 4> > answer) {
	int n = r.size() - 1;
	assert(r.size() == c.size());
	for (auto x : answer)
		for (int y : x)
			assert(y >= 1 && y <= n);
	vector <vpii> mapa(n + 1, vpii(n + 1));
	FOR(i, 1, n)
		FOR(j, 1, n)
			mapa[i][j] = {i, j + 1};
	for (auto x : answer) {
		assert(mapa[x[0]][x[1]] == pii(x[0], x[1] + 1));
		assert(mapa[x[2]][x[3]] == pii(x[2], x[3] + 1));
		mapa[x[0]][x[1]] = {x[2], x[3] + 1};
		mapa[x[2]][x[3]] = {x[0], x[1] + 1};
	}
	FOR(i, 1, n) {
		pii where = {i, 1};
		while (where.second <= n)
			where = mapa[where.first][where.second];
		assert(r[i] == where.first);
	}
	FOR(i, 1, n)
		FOR(j, 1, n)
			mapa[i][j] = {i + 1, j};
	for (auto x : answer) {
		assert(mapa[x[0]][x[1]] == pii(x[0] + 1, x[1]));
		assert(mapa[x[2]][x[3]] == pii(x[2] + 1, x[3]));
		mapa[x[0]][x[1]] = {x[2] + 1, x[3]};
		mapa[x[2]][x[3]] = {x[0] + 1, x[1]};
	}
	FOR(i, 1, n) {
		pii where = {1, i};
		while (where.first <= n)
			where = mapa[where.first][where.second];
		assert(c[i] == where.second);
	}
}
void one_test(vector <int> r, vector <int> c) {
	auto ans = solve(r, c);
	verify(r, c, ans);
}
void run_tests() {
	FOR(n, 1, 5) {
		vector <int> r(n + 1), c(n + 1);
		REP(i, n + 1) r[i] = c[i] = i;
		do do one_test(r, c);
		while (next_permutation(1 + ALL(c))); while (next_permutation(1 + ALL(r)));
		debug("passed for ", imie(n));
	}
}
int main() {

	run_tests();

	int n;
	scanf("%d", &n);
	vector <int> r(n + 1), c(n + 1);
	FOR(i, 1, n) scanf("%d", &r[i]);
	FOR(i, 1, n) scanf("%d", &c[i]);
	auto ans = solve(r, c);
	printf("%d\n", (int) ans.size());
	for (auto x : ans) {
		for (int c : x) printf("%d ", c);
		printf("\n");
	}
}
