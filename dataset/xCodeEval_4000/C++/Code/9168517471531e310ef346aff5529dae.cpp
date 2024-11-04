#include <bits/stdc++.h>
using namespace std;





#define lsb(x) (x&-x)
#define lsbu(x) (x&(x+1))
#define msb(x) __lg(x)
#define msbu(x)






#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int,int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct comp { 

	bool operator() (const pair <int , int> &a, const pair <int , int> &b) const {
		return a.first < b.first;
	}
};


#define INF 1e9+9
int nmax() {return -1 * INF;}
template<typename Arg, typename... Args>
int nmax(Arg a, Args... args) { return std::max(a, nmax(args...)); }

int nmin() {return INF;}
template<typename Arg, typename... Args>
int nmin(Arg a, Args... args) { return std::min(a, nmin(args...)); }


void ans22(bool x) {if (x) cout << "YES" << endl; else cout << "NO" << endl;}




bool onsegment(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	if (q.first <= max(p.second, r.first) && q.first >= min(p.first, r.first) &&
	        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
		return true;

	return false;
}









int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	int val = (q.second - p.second) * (r.first - q.first) -
	          (q.first - p.first) * (r.second - q.second);

	if (val == 0) return 0;  


	return (val > 0) ? 1 : 2; 

}



#define dsu(n) parent_dsu.resize(n);rank_dsu.resize(n,0);iota(parent_dsu.begin(),parent_dsu.end(),0)
vector<int> parent_dsu, rank_dsu;
void make_set_dsu(int v) {
	parent_dsu[v] = v;  

	rank_dsu[v] = 0;     

}

int find_set_dsu(int v) {
	if (v == parent_dsu[v])
		return v;
	return parent_dsu[v] = find_set_dsu(parent_dsu[v]); 

	

}

void union_sets_dsu(int a, int b) {
	a = find_set_dsu(a);
	b = find_set_dsu(b);
	if (a != b) {
		if (rank_dsu[a] < rank_dsu[b])
			swap(a, b);
		parent_dsu[b] = a;
		if (rank_dsu[a] == rank_dsu[b])
			rank_dsu[a]++;
	}
}

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const vector<int>& x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}


template<typename T>void __print(stack<T> st) {while (!st.empty()) {cerr << st.top() << " "; st.pop();};}
template<typename T>void __print(queue<T> st) {while (!st.empty()) {cerr << st.front() << " "; st.pop();};}
template<typename T>void __print(deque<T> st) {while (!st.empty()) {cerr << st.front() << " "; st.pop_front();};}


void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}



double __start_time = 0;
void __stime() {
	__start_time = 1.0 * clock() / CLOCKS_PER_SEC;
}

void __etime() {
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC - __start_time) << " s.\n";
#endif
}



long long ccccc = 0;
#ifndef ONLINE_JUDGE
#define tle ccccc++;assert(ccccc<1e7)
#define wd(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define tle
#define wd(x...)
#endif





#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define unique(a) (a).erase(std::unique((a).begin(),(a).end()),(a).end())
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vil vector<long long>
#define vii vector<pair<int,int>>
#define viil vector<pair<long long,long long>>
#define si set<int>


void print(auto &arr) {
	for (int i = 0; i < arr.size(); i++)
		printf("%d ", arr[i]);
	printf("\n");
}

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
long long mod = 1e9 + 7;









int _p = 0; 

int __nn = 2; 




struct Vertex {
	int val;
	int pos;
	int lazy;
	Vertex() {
		

		if (_p == 0) {
			val = INT_MIN;
			pos = -1;
			lazy = 0;
		}
		if (_p == 1) {
			val = INT_MAX;
			lazy = 0;
		}
	}
};







vector<vector<Vertex>> t(__nn, vector<Vertex>(4 * (1e6 + 5)));

Vertex merge(Vertex left, Vertex right) {
	if (_p == 0) {
		Vertex cur;
		if (left.val < right.val) {
			cur.pos = right.pos;
			cur.val = right.val;
		}
		else {
			cur.pos = left.pos;
			cur.val = left.val;
		}
		return cur;
	}
	else if (_p == 1) {
		Vertex cur;
		cur.val = min(left.val , right.val);
		return cur;
	}
}

int joinDeltas(int oldDelta, int newDelta) {
	if (_p == 0) {
		return oldDelta + newDelta;
	}
	else if (_p == 1) { 

		return newDelta;
	}
}

int joinValueWithDelta(int value, int delta, int length) {
	if (_p == 0) {
		return value + length * delta;
	}
	else if (_p == 1) { 

		return (length) * delta;
	}
}





void build(auto &a, int v, int tl, int tr) {

	if (tl == tr) {

		if (_p == 0) {
			t[_p][v].val = a[tl];
			t[_p][v].pos = tl;
		}
		else if (_p == 1) {
			t[_p][v].val = a[tl];
			t[_p][v].pos = tl;
		}
	}

	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[_p][v] = merge(t[_p][v * 2] , t[_p][v * 2 + 1]);
	}
}




Vertex sum(int v , int tl , int tr , int l, int r) {
	if (l > r)
		return Vertex();    

	if (l == tl && r == tr) {
		return t[_p][v];
	}
	int tm = (tl + tr) / 2;
	return merge(sum(v * 2, tl, tm, l, min(r, tm))
	             , sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}



void update(int v , int tl , int tr , int pos, int new_val) {
	if (tl == tr) {

		t[_p][v].val = new_val; 

	}

	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[_p][v] = merge(t[_p][v * 2] , t[_p][v * 2 + 1]);
	}
}


vi _nn(__nn);


void build(auto &arr) {
	_nn[_p] = (int)arr.size();
	build(arr, 1, 0, _nn[_p] - 1);
}


Vertex sum(int l, int r) {
	return sum(1, 0, _nn[_p] - 1, l, r);
}


void update(int pos, int val) {
	update(1, 0, _nn[_p] - 1, pos, val);
}




void push(int v, int tl, int tr) { 

	if (_p == 0) {
		int tm = (tl + tr) / 2;
		t[_p][v * 2].val = joinValueWithDelta(t[_p][v * 2].val, t[_p][v].lazy , (tm - tl + 1));
		t[_p][v * 2].lazy = joinDeltas(t[_p][v * 2].lazy, t[_p][v].lazy);
		t[_p][v * 2 + 1].val = joinValueWithDelta(t[_p][v * 2 + 1].val, t[_p][v].lazy, (tr - tm));
		t[_p][v * 2 + 1].lazy = joinDeltas(t[_p][v * 2 + 1].lazy, t[_p][v].lazy);
		t[_p][v].lazy = 0;
	}
	else if (_p == 1) {

	}
}


void update(int v, int tl, int tr, int l, int r, auto addend) {
	if (l > r)
		return;
	if (l == tl && tr == r) {

		t[_p][v].val += (tr - tl + 1) * addend;
		t[_p][v].lazy += addend;
	}

	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		update(v * 2, tl, tm, l, min(r, tm), addend);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
		t[_p][v] = merge(t[_p][v * 2] , t[_p][v * 2 + 1]);
	}
}

Vertex query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return Vertex(); 

	if (l <= tl && tr <= r)
		return t[_p][v];
	int tm = (tl + tr) / 2;
	push(v, tl, tr);
	return merge(query(v * 2, tl, tm, l, min(r, tm)) ,
	             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}




void update(int l, int r, auto val) {
	update(1, 0 , _nn[_p] - 1, l, r, val);
}
Vertex query(int l, int r) {
	return query(1, 0, _nn[_p] - 1, l, r);
}



vector<array<int, 2>> maxrange;
vi arr;
vi nse, pse, nsee;

void preprocess(int n) {
	{
		stack<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && arr[st.top()] < arr[i])
				st.pop();

			maxrange[i] = {(st.empty() ? 0 : st.top() + 1), maxrange[i][1]};
			st.push(i);
		}
	}
	{
		stack<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && arr[st.top()] <= arr[i])
				st.pop();

			maxrange[i] = {maxrange[i][0], (st.empty() ? n - 1 : st.top() - 1)};
			st.push(i);
		}
	}

	{
		stack<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop();

			pse[i] = (st.empty() ? 0 : st.top() + 1);
			st.push(i);
		}
	}
	{
		stack<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop();

			nse[i] = (st.empty() ? n - 1 : st.top() - 1);
			st.push(i);
		}
	}
	{
		stack<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && arr[st.top()] > arr[i])
				st.pop();

			nsee[i] = (st.empty() ? n - 1 : st.top() - 1);
			st.push(i);
		}
	}
}


const int K = 25;
const int MAXN = 5e5 + 7;
int lg[MAXN + 1];
int st1[K + 1][MAXN];




int rmin(int L, int R) {
	int j = lg[R - L + 1];
	return min(st1[j][L], st1[j][R - (1 << j) + 1]);
}











int firstgreaterleft(int i, int val) {
	int low = 0, high = i, mid = (low + high) / 2;
	_p = 0;
	while (low <= high) {
		if (sum(mid, i).val < val) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	return low;
}

int firstgreaterright(int i, int val, int n) {
	int low = i, high = n - 1, mid = (low + high) / 2;
	if (i < 0) {
		return i + 1;
	}
	_p = 0;
	while (low <= high) {
		if (sum(i, mid).val <= val) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	low--;
	return low;
}




void maxrangecalc(int l, int r) {
	

	

	

	

	

	


	int n = r + 1;
	for (int i = 0; i < n; i++) {
		int left = firstgreaterleft(i - 1, arr[i]) ;
		int right = firstgreaterright(i, arr[i], n) ;
		maxrange[i] = {left, right};
	}
}

int highestminbs(int start, int l, int r, int val) {
	int low = l, high = r, mid = (low + high) / 2;
	_p = 1;
	while (low <= high) {
		if (rmin(start, mid) == val) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	low--;
	return low;
}


int lowestminbs(int endd, int l, int r, int val) {
	int low = l, high = r, mid = (low + high) / 2;
	_p = 1;
	while (low <= high) {
		if (rmin(mid, endd) == val) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	return low;
}


int auxhighestminbs(int start, int l, int r, int val) {
	int low = l, high = r, mid = (low + high) / 2;
	_p = 1;
	while (low <= high) {
		if (rmin(start, mid) > val) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	low--;
	return low;
}


int auxlowestminbs(int endd, int l, int r, int val) {
	int low = l, high = r, mid = (low + high) / 2;
	_p = 1;
	while (low <= high) {
		if (rmin(mid, endd) >= val) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	_p = 0;

	return low;
}






int log2_floor(unsigned long long i) {
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}


int32_t main() {
	






#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif




	int t;
	scanf("%d", &t);

	int N = 1e6 + 7;

	vector<vector<int>> divisors(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			divisors[j].push_back(i);
		}
	}

	vector<vi> brr(N);

	while (t--) {
		int n;
		scanf("%d", &n);
		maxrange.clear();
		maxrange.assign(n + 2, {0, 0});
		arr.clear();
		arr.resize(n);
		nse.clear(); pse.clear(); nsee.clear();
		nse.resize(n + 2); pse.resize(n + 2); nsee.resize(n + 2);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			brr[arr[i]].pb(i);
		}

		

		

		_p = 1;
		


		preprocess(n);

		


		long long ans  = 0;
		_p = 0;


		lg[1] = 0;
		for (int i = 2; i <= MAXN; i++)
			lg[i] = lg[i / 2] + 1;

		std::copy(arr.begin(), arr.end(), st1[0]);
		


		for (int j = 1; j <= K; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				st1[j][i] = min(st1[j - 1][i], st1[j - 1][i + (1 << (j - 1))]);


		

		

		



		


		for (int i = 0; i < n; i++) {
			vector<array<int, 3>> rigthtranges, leftranges;
			for (auto &x : divisors[arr[i]]) {
				if (brr[x].size() == 0)
					continue;

				

				{
					int l = lower_bound(all(brr[x]), i) - brr[x].begin();
					

					int r = maxrange[i][1];
					if(l < brr[x].size())
					r = min(nse[brr[x][l]], r);
					if (l < brr[x].size()) {
						l = brr[x][l];

						if (l <= r && rmin(i, l) == x) {
							

							int last = r;
							if (last < l)
								last = -1;
							if (last != -1) {
								rigthtranges.pb({l, last, x});
							}
						}
					}
				}

				

				{
					

					int r = lower_bound(all(brr[x]), i) - brr[x].begin() - 1;
					int l = maxrange[i][0];
					if(r < brr[x].size())
					l = max(pse[brr[x][r]], l);

					if (r < brr[x].size()) {
						r = brr[x][r];
						if (l <= r && rmin(r, i) == x) {
							

							int last = l;
							if (last > r)
								last = -1;
							if (last != -1) {
								leftranges.pb({last, r, x});
							}
						}
					}
				}
			}

			

			


			{
				for (auto [l, r, x] : rigthtranges) {
					ans += (long long)(r - l + 1) * (1 + i - max(maxrange[i][0], pse[l]));
				}
			}

			{
				for (auto [l, r, x] : leftranges) {
					ans += (long long)(r - l + 1) * (min(maxrange[i][1], nsee[r]) - (i - 1));
				}
			}

		}


		

		

		printf("%lld\n", ans);

		for (int i = 0; i < n; i++) {
			brr[arr[i]].erase(brr[arr[i]].begin(), brr[arr[i]].end());
		}
	}




	return 0;
}