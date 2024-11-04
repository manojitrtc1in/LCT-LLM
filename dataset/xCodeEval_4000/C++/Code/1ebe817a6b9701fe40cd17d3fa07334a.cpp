#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> ii;
typedef pair<int64, int64> ii64;
typedef vector<int> vint;
typedef vector<int64> vint64;
typedef vector<uint64> vuint64;
typedef vector<vint> vvint;
typedef vector<vint64> vvint64;
typedef vector<vuint64> vvuint64;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define fork(n) for(int k = 0; k < n; ++k)
#define INF9 (int64)(1e9)
#define INF18 (int64)(1e18)

template<typename T>
struct compF{
	bool operator()(const pair<T, T> &a, const pair<T, T> &b){
		return a.first < b.first;
	}
};

template<typename T>
struct compS{
	bool operator()(const pair<T, T> &a, const pair<T, T> &b){
		return a.second < b.second;
	}
};

template<typename T>
void printMatrix(const string &txt, vector<vector<T>> &a){
	cout << txt;
	fori(a.size()){
		forj(a[i].size())
			cout << a[i][j] << ' ';

		cout << endl;
	}
}

template<typename T>
void printVector(const string &txt, vector<T> &a){
	cout << txt;
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << ' ';
	cout << endl;
}

template<typename T>
void readVector(int n, vector<T> &a){
	if (a.size() < n)
		a.resize(n);

	fori(n) cin >> a[i];
}

template<typename T>
T lb(const set<T> &a, T x){
	auto it = a.lower_bound(x);
	if (it == a.end())
		return -1;
	return *it;
}

template<typename T>
T ub(const set<T> &a, T x){
	auto it = a.upper_bound(x);
	if (it == a.end())
		return -1;
	return *it;
}

template<typename T>
T rlb(const set<T> &a, T x){
	auto it = a.lower_bound(x);

	if (it == a.begin()){
		if (*it > x)
			return -1;
		return *it;
	}

	it = prev(it);
	return *it;
}

template<typename T>
T rub(const set<T> &a, T x){
	auto it = a.lower_bound(x);

	if (it == a.begin()){
		return -1;
	}

	it = prev(it);
	return *it;
}

template<typename T1, typename T2>
bool exist(map<T1, T2> &m, T1 x){
	if (m.find(x) == m.end())
		return false;

	return true;
}

int64 gcd(int64 a, int64 b){
	while (a != 0 && b != 0){
		if (b > a)
			b %= a;
		else
			a %= b;
	}

	return a + b;
}

int64 minFactor(int64 x){
	for (int64 i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return i;

	return x;
}

int64 allFactors(int64 x, vint64 &prms, vint64 &prm_cnt){
	prms.clear();
	prm_cnt.clear();
	while (x > 1){
		int64 t = minFactor(x);
		prms.push_back(t);
		int s = prms.size() - 1;
		prm_cnt.push_back(0);
		while (x % t == 0){
			x /= t;
			++prm_cnt[s];
		}
	}

	return 0;
}

#define MOD 998244353

int64 add(int64 a, int64 b){
	if (a > MOD) a %= MOD;
	if (b > MOD) b %= MOD;

	return (a + b) % MOD;
}

int64 sub(int64 a, int64 b){
	if (a > MOD) a %= MOD;
	if (b > MOD) b %= MOD;

	int64 x = a - b;
	while (x < 0)
		x += MOD;

	return x;
}

int64 mul(int64 a, int64 b){
	if (a > MOD) a %= MOD;
	if (b > MOD) b %= MOD;

	return (a * b) % MOD;
}

int64 pow_(int64 a, int64 b){
	if (b == 0)
		return 1ll;
	if (b % 2 == 0){
		int64 k = pow_(a, b / 2);
		return mul(k, k);
	}
	else{
		int64 k = pow_(a, b - 1);
		return mul(a, k);
	}
}

#define N 3*(int)(1e5)

int n, m;
map<int, int> ind;

struct Triple{
	int i, l, r;
	Triple(int i, int l, int r){
		this->i = i;
		this->l = l;
		this->r = r;
	}

	Triple(){
		i = l = r = 0;
	}
};

istream& operator>> (istream& o, Triple &t){
	o >> t.i >> t.l >> t.r;
	return o;
}

Triple Data[N];
ii tree[2 * (4 * (N + 1) + 1)];
ii lazy[2 * (4 * (N + 1) + 1)];

void buildTree(ii *tree, int *a, int index, int s, int e)
{
	

	

	if (s>e)
		return;

	

	if (s == e)
	{
		tree[index] = { 0, 0 };
		lazy[index] = { -1, -1 };
		return;
	}
	

	int m = (s + e) / 2;
	buildTree(tree, a, 2 * index, s, m);
	buildTree(tree, a, 2 * index + 1, m + 1, e);
	tree[index] = max(tree[2 * index], tree[2 * index + 1]);
	lazy[index] = { -1, -1 };
	return;
}

void push(ii *tree, int index){
	if (lazy[index].first > -1){
		

		tree[index] = lazy[index];
		

		

		lazy[2 * index] = lazy[2 * index + 1] = lazy[index];
		lazy[index] = { -1, -1 };
	}
}



ii query(ii *tree, int index, int s, int e, int qs, int qe)
{
	push(tree, index);
	

	if (qs>e || s>qe)
		return{ -1, -1 };
	

	if (s >= qs && e <= qe)
		return tree[index];
	

	int m = (s + e) / 2;
	ii left_ans = query(tree, 2 * index, s, m, qs, qe);
	ii right_ans = query(tree, 2 * index + 1, m + 1, e, qs, qe);
	return max(left_ans, right_ans);
}



void updateNode(ii *tree, int index, int s, int e, int pos, ii val)
{
	if (pos<s || pos>e)
		return;

	if (s == e)
	{
		tree[index] = val;
		lazy[index] = { -1, -1 };
		return;
	}
	push(tree, index);

	int m = (s + e) / 2;
	updateNode(tree, 2 * index, s, m, pos, val);
	updateNode(tree, 2 * index + 1, m + 1, e, pos, val);
	tree[index] = max(tree[2 * index], tree[2 * index + 1]);
	return;
}



void updateRange(ii *tree, int index, int s, int e, int rs, int re, ii inc)
{
	

	if (s>re || e<rs)
		return;

	if (s >= rs && e <= re)
	{
		lazy[index] = inc;
		tree[index] = inc;
		if (s != e)
			push(tree, index);
		return;
	}

	push(tree, index);
	int mid = (s + e) / 2;
	updateRange(tree, 2 * index, s, mid, rs, re, inc);
	updateRange(tree, 2 * index + 1, mid + 1, e, rs, re, inc);
	tree[index] = max(tree[2 * index], tree[2 * index + 1]);
	return;
}

struct Comp{
	bool operator()(const Triple& a, const Triple& b){
		return a.i < b.i;
	}
};


int dp[N];
int par[N];




#ifndef _SEG_TREE_LAZY_
#define _SEG_TREE_LAZY_
namespace seg_tree{
	template<typename T, class Oper, class LazyOper, class LazyClear>
	class SegTreeLazy{
	public:
		SegTreeLazy(){}
		SegTreeLazy(const vector< T > &src){
			this->build(src);
		}

		void build(const vector<T> &src){
			data_size = src.size();
			this->tree.resize(4 * src.size());
			this->lazy.resize(4 * src.size());
			this->hasProp.resize(4 * src.size());
			pBuild(0, data_size - 1, 0, src);
		}

		void update(int ind, T val){
			pUpdate(0, data_size - 1, 0, ind, val);
		}

		void update(int l, int r, T val){
			pUpdateRange(l, r, 0, val, 0, data_size - 1);
		}

		T get(int ind){
			return pGet(0, data_size - 1, 0, ind);
		}

		T get(int l, int r, T out_val){
			return pGet(l, r, 0, data_size - 1, 0, out_val);
		}

	private:

		void pBuild(int l, int r, int v, const vector<T> &src){
			lazy[v] = LazyClear()();
			hasProp[v] = false;

			if (l == r){
				this->tree[v] = src[l];
			}
			else{
				int mid = (l + r) / 2;
				this->pBuild(l, mid, 2 * v + 1, src);
				this->pBuild(mid + 1, r, 2 * v + 2, src);
				Oper _oper;

				this->tree[v] = _oper(this->tree[2 * v + 1], this->tree[2 * v + 2]);
			}
		}

		T pGet(int l, int r, int v, int ind){
			pPush(v, l, r);

			if (l == r)
				return this->tree[v];
			else{
				int mid = (l + r) / 2;
				if (ind <= mid)
					return this->pGet(l, mid, 2 * v + 1, ind);
				else
					return this->pGet(mid + 1, r, 2 * v + 2, ind);
			}
		}

		T pGet(int l, int r, int tl, int tr, int v, T out_val){
			if (l > r){
				return out_val;
			}
			pPush(v, tl, tr);

			if (tl == l && tr == r)
				return this->tree[v];

			int mid = (tl + tr) / 2;
			Oper _oper;

			return _oper(pGet(l, min<int>(r, mid), tl, mid, 2 * v + 1, out_val), \
				pGet(max<int>(mid + 1, l), r, mid + 1, tr, 2 * v + 2, out_val));
		}

		void pPush(int v, int tl, int tr){
			if (hasProp[v]){
				tree[v] = LazyOper()(tree[v], lazy[v]);
				if (tl != tr){
					lazy[2 * v + 1] = LazyOper()(lazy[2 * v + 1], lazy[v]);
					lazy[2 * v + 2] = LazyOper()(lazy[2 * v + 2], lazy[v]);
					hasProp[2 * v + 1] = hasProp[2 * v + 2] = true;
				}

				hasProp[v] = false;
				lazy[v] = LazyClear()();
			}
		}

		void pUpdateRange(int l, int r, int v, T val, int tl, int tr){
			if (l > tr || r < tl)
				return;

			pPush(v, tl, tr);
			if (tl >= l && tr <= r){
				

				lazy[v] = LazyOper()(lazy[v], val);
				hasProp[v] = true;

				pPush(v, tl, tr);
				return;
			}

			int mid = (tl + tr) / 2;
			pUpdateRange(l, r, 2 * v + 1, val, tl, mid);
			pUpdateRange(l, r, 2 * v + 2, val, mid + 1, tr);

			tree[v] = Oper()(tree[2 * v + 1], tree[2 * v + 2]);
		}

		void pUpdate(int l, int r, int v, int ind, T val){
			pPush(v, l, r);

			if (l == r)
				this->tree[v] = val;
			else{
				int mid = (l + r) / 2;
				if (ind <= mid)
					this->pUpdate(l, mid, 2 * v + 1, ind, val);
				else
					this->pUpdate(mid + 1, r, 2 * v + 2, ind, val);

				Oper _oper;
				this->tree[v] = _oper(this->tree[2 * v + 1], this->tree[2 * v + 2]);
			}
		}

		vector<T> tree, lazy;
		vector<bool> hasProp;
		int data_size;
	};
}

template<typename T>
struct Sum{
	T operator()(T a, T b){
		return a + b;
	}
};

template<typename T>
struct Mul{
	T operator()(T a, T b){
		return a * b;
	}
};

template<typename T>
struct Assign{
	T operator()(T old, T curr){
		return curr;
	}
};

template<typename T>
struct Min{
	T operator()(T a, T b){
		return min(a, b);
	}
};

template<typename T>
struct Max{
	T operator()(T a, T b){
		return max(a, b);
	}
};

template<typename T>
struct SetZero{
	T operator()(){
		return static_cast<T>(0);
	}
};

template<typename T>
struct SetOne{
	T operator()(){
		return static_cast<T>(1);
	}
};

template<typename T, T val>
struct SetPair{
	pair<T, T> operator()(){
		return make_pair(val, val);
	}
};

#endif _SEG_TREE_LAZY_

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie();
#ifndef DEBUG
	cin >> n >> m;
	
#else
	n = m = N;
#endif
	fori(n) par[i] = -1;
	fori(m){
#ifndef DEBUG
		cin >> Data[i];
#else
		Data[i] = Triple(i + 1, i + 1, 1e9 - 1);
#endif
		Data[i].i--;
	}
	sort(Data, Data + m, Comp());

	{
		set<int> vals;
		fori(m) {
			vals.insert(Data[i].l);
			vals.insert(Data[i].r);
		}

		int i = 0;
		for (auto x : vals)
			ind[x] = i++;

		fori(m){
			Data[i].l = ind[Data[i].l];
			Data[i].r = ind[Data[i].r];
		}
	}
	int s = 0, e = ind.size() - 1;
	int index = 1;
	


	seg_tree::SegTreeLazy<ii, Max<ii>, Assign<ii>, SetPair<int, -1>> st(vector<ii>(ind.size(), { 0, 0 }));

	fori(n){
		dp[i] = 1;
		

		auto it = lower_bound(Data, Data + m, Triple(i, 0, 0), Comp()) - Data;
		if (it < m && Data[it].i == i){
			int ii = Data[it].i;
			int oit = it;
			int mv = 0;
			int mind = -1;
			while (it < m && Data[it].i == ii){
				int l = Data[it].l, r = Data[it].r;

				

				

				pair<int, int> v = st.get(l, r, { -1, -1 });
				if (v.first > mv){
					mv = v.first;
					mind = v.second;
				}
				
				++it;
			}

			mv += 1;
			it = oit;
			while (it < m && Data[it].i == ii){
				int l = Data[it].l, r = Data[it].r;

				

				st.update(l, r, { mv, i });
				++it;
			}

			dp[i] = mv;
			par[i] = mind;
		}
	}

	auto it = max_element(dp, dp + n) - dp;
	int cnt = n - dp[it];
	vint pars;
	int v = it;
	while (v != -1){
		pars.push_back(v);
		v = par[v];
	}

	cout << cnt << endl;
	sort(ALL(pars));
	fori(n){
		auto it = lower_bound(ALL(pars), i);
		if (it == pars.end() || *it != i){
			cout << i + 1 << " ";
		}
	}

	return 0;
}
