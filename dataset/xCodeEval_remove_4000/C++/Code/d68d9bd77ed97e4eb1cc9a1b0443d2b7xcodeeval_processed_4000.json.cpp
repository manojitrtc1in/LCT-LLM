
using namespace std;

















using namespace __gnu_pbds;



typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct comp { 

	bool operator() (const pair <int , int> &a, const pair <int , int> &b) const {
		return a.first < b.first;
	}
};



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




vector<int> id11, id1;
void id8(int v) {
	id11[v] = v;  

	id1[v] = 0;     

}

int id9(int v) {
	if (v == id11[v])
		return v;
	return id11[v] = id9(id11[v]); 

	

}

void id10(int a, int b) {
	a = id9(a);
	b = id9(b);
	if (a != b) {
		if (id1[a] < id1[b])
			swap(a, b);
		id11[b] = a;
		if (id1[a] == id1[b])
			id1[a]++;
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
		static const uint64_t id4 = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id4);
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



double id0 = 0;
void __stime() {
	id0 = 1.0 * clock() / CLOCKS_PER_SEC;
}

void __etime() {

	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC - id0) << " s.\n";

}



long long ccccc = 0;




























void print(auto &arr) {
	for (int i = 0; i < arr.size(); i++)
		printf("%d ", arr[i]);
	printf("\n");
}



long long mod = 1e9 + 7;





int _p = 0; 


const int id3 = 0;

struct Vertex {
	int val;
	int lazy = id3;
};

const Vertex id2 = {0, id3};




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

int id5(int oldDelta, int newDelta) {
	if (_p == 0) {
		return oldDelta + newDelta;
	}
	else if (_p == 1) { 

		return newDelta;
	}
}

int id6(int value, int delta, int length) {
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
		return id2;
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
		t[_p][v * 2].val = id6(t[_p][v * 2].val, t[_p][v].lazy , (tm - tl + 1));
		t[_p][v * 2].lazy = id5(t[_p][v * 2].lazy, t[_p][v].lazy);
		t[_p][v * 2 + 1].val = id6(t[_p][v * 2 + 1].val, t[_p][v].lazy, (tr - tm));
		t[_p][v * 2 + 1].lazy = id5(t[_p][v * 2 + 1].lazy, t[_p][v].lazy);
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
		return id2;
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





vector<int> id7(vector<int> arr)
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
	







	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);





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