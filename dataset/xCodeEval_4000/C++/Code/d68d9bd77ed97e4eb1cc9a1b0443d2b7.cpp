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


#define int long long

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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rrep(i,n) for(int (i)=(int)(n)-1;(i)>=0;--(i))
#define forn(i,l,r) for(int (i)=l;(i)<=(int)(r);++(i))


void print(auto &arr) {
	for (int i = 0; i < arr.size(); i++)
		printf("%d ", arr[i]);
	printf("\n");
}

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
long long mod = 1e9 + 7;





int _p = 0; 


const int NEUTRAL_DELTA = 0;

struct Vertex {
	int val;
	int lazy = NEUTRAL_DELTA;
};

const Vertex NEUTRAL_NODE = {0, NEUTRAL_DELTA};




vector<vector<Vertex>> t(2, vector<Vertex>(4 * (1e6 + 5)));

Vertex merge(Vertex left, Vertex right) {
	if (_p == 0) {
		Vertex cur;
		cur.val = left.val + right.val;
		return cur;
	}
	else {
		Vertex cur;
		cur.val = left.val + right.val;
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





void build(vector<int> &a, int v, int tl, int tr) {

	if (tl == tr) {

		

		t[_p][v].val = a[tl];
		

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
		return NEUTRAL_NODE;
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


vi _nn(2);


void build(vector<int> &arr) {
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


void update(int v, int tl, int tr, int l, int r, int addend) {
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
		return NEUTRAL_NODE;
	if (l <= tl && tr <= r)
		return t[_p][v];
	int tm = (tl + tr) / 2;
	push(v, tl, tr);
	return merge(query(v * 2, tl, tm, l, min(r, tm)) ,
	             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}




void update(int l, int r, int val) {
	update(1, 0 , _nn[_p] - 1, l, r, val);
}
Vertex query(int l, int r) {
	return query(1, 0, _nn[_p] - 1, l, r);
}





vector<int> getNGE(vector<int> arr)
{
	int n = arr.size();
	stack<pair<int, int>> s;
	vector<int> ans(n);

	s.push({arr[0], 0});

	for (int i = 1; i < n; i++) {

		if (s.empty()) {
			s.push({arr[i], i});
			continue;
		}

		while (s.empty() == false && s.top().first < arr[i]) {
			ans[s.top().second] = i;
			s.pop();
		}
		s.push({arr[i], i});
	}

	while (s.empty() == false) {
		ans[s.top().second] = n + 1;
		s.pop();
	}
	return ans;
}



int32_t main() {
	






#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif




	int n;
	scanf("%lld", &n);
	vector<int> arr(n), brr(n) , aux(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		brr[i] = i + 1 - arr[i] + 1;
	}

	vi premin(n);
	brr[0] = 1;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			premin[i] = brr[i];
		else
			premin[i] = max(premin[i - 1], brr[i]);
	}


	for (int i = 0; i < n; i++) {
		ans += i + 1 - premin[i] + 1;
	}

	for (int i = 1; i < n; i++) {
		if (brr[i] > premin[i - 1]) {
			int j = i + 1;
			int x = premin[i - 1];
			aux[i] = premin[i - 1];
			while (j < n && brr[j] <= brr[i]) {
				aux[j] = max(x, brr[j]);
				x=aux[j];
				j++;
			}
		}
	}

	_p = 0;
	build(premin);
	_p = 1;
	build(aux);
	

	wd(aux);

	int q;
	scanf("%lld", &q);
	wd(premin);
	


	


	for (int i = 0; i < q; i++) {
		int p, x;
		scanf("%lld %lld", &p, &x);
		p--;

		x = p + 1 - x + 1;

		int newmax = (p == 0) ? 1 : max(premin[p - 1], x);


		wd(x, newmax, premin[p]);
		if (newmax == premin[p]) {
			printf("%lld\n", ans);
			continue;
		}

		wd(newmax, premin[p]);
		if (newmax  > premin[p]) {
			int y = upper_bound(all(premin), newmax) - premin.begin();
			

			_p = 0;
			
			printf("%lld\n", ans + sum(p, y - 1).val - newmax * (y - p));
		}

		if (newmax < premin[p] && newmax > premin[p - 1]) {
			int y = upper_bound(all(premin), premin[p]) - premin.begin();
			_p = 1;
			wd( p, y, query(p, y - 1).val);
			int ans2 = ans - sum(p, y - 1).val + premin[p] * (y - p);
			_p = 1;
			

			

			int z  = upper_bound(all(premin), premin[p]) - premin.begin();
			y = upper_bound(aux.begin()+p,aux.begin()+z,newmax) - aux.begin();
			
			printf("%lld\n", ans2 + sum(p, y - 1 ).val - newmax * (y - p ));
			

			continue;
		}

		if (newmax  < premin[p]) {
			int y = upper_bound(all(premin), premin[p]) - premin.begin();
			_p = 1;
			

			
			printf("%lld\n", ans - sum(p, y - 1).val + premin[p] * (y - p));
		}
	}





	






	return 0;
}