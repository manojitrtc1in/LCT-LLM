











using namespace std;



void fillArray(char a[], char n) {
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void fillArray(double a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void fillArray(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void fillArray(long long a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

int p = 41, Mod = 2000000001;



int Hash(string s) {
	long long h = 0;
	for (int i = 0; i < s.length(); i++)
	{
		h = (h * p + s[i]) % Mod;
	}
	return h;
}

void Hash(string s, long long h[], int n) {
	h[0] = s[0];
	for (int i = 1; i < n; i++)
	{
		h[i] = (h[i - 1] * p + s[i]) % Mod;
	}
}

int subHash(long long h[], int l, int r, long long step[]) {
	long long big = h[r];
	long long small = 0;
	if (l != 0) {
		small = (h[l - 1] * step[r - l + 1]) % Mod;
	}
	return (big - small + Mod) % Mod;
}

void dfs(vector<int>* a, int* b, int u, int j, int k, vector<int> &d) {
	for (int i = 0; i < a[k].size(); i++)
	{
		if (a[k][i] == u) {
			d.push_back(k);
		}
		else {
			b[k] = j;
			if (b[a[k][i]] == 0 && a[k][i] != 0) {
				dfs(a, b, u, j + 1, a[k][i], d);
			}
		}
	}
}
void dfs(vector<int>* a, int* b, int j, int k, vector<int> &c) {
	for (int i = 0; i < a[k].size(); i++)
	{
		b[k] = j;
		if (b[a[k][i]] == 0) {
			c.push_back(k);
			dfs(a, b, j, a[k][i], c);
		}
		if (a[k].size() == 1) {
			c.push_back(k);
		}

	}
}

int max(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	if (b >= a && b >= c) {
		return b;
	}
	else {
		return c;
	}
}

bool bin(vector<int>& b, int k) {
	int l = 0;
	int r = b.size();
	int m;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (b[m] <= k) {
			l = m;
		}
		else {
			r = m;
		}
	}
	if (b.size() > 0 && b[l] == k) {
		b.erase(b.begin() + l);
		return true;
	}
	else {
		return false;
	}
}



class Point {
public:
	long long x;
	long long y;


	Point() {
		x = 0;
		y = 0;

	}

	Point(long long x, long long y) {
		this->x = x;
		this->y = y;


	}

};

Point max(Point a, Point b) {
	if (a.y == -1) {
		return b;
	}
	if (b.y == -1) {
		return a;
	}
	if (a.x > b.x) {
		return a;
	}
	else {
		return b;
	}
}

class id2 {
public:
	long long* t;
	long long* a;
	long long n;
	long long* mins;
	long long* maxs;
	long long* maxs_i;
	long long* zeros;
	long long* sets;
	long long* incs;
	long long* len;
	id2(long long *a, long long n) {
		this->a = a;
		this->t = new long long[n * 4];
		this->mins = new long long[n * 4];
		this->maxs = new long long[n * 4];
		this->maxs_i = new long long[n * 4];
		this->zeros = new long long[n * 4];
		this->sets = new long long[n * 4];
		this->incs = new long long[n * 4];
		this->len = new long long[n * 4];
		for (int i = 0; i < n * 4; i++)
		{
			sets[i] = BIG;
			incs[i] = BIG;
		}
		this->n = n;
		build(0, 0, n);
	}
	id2() {
		this->t = NULL;
		this->a = NULL;
		this->mins = NULL;
		this->maxs = NULL;
		this->maxs_i = NULL;
		this->zeros = NULL;
		this->n = 0;
		this->sets = NULL;
		this->incs = NULL;
		this->len = NULL;
	}
	void build(long long v, long long l, long long r) {
		if (l == r - 1) {
			t[v] = a[l];
			mins[v] = a[l];
			maxs[v] = a[l];
			maxs_i[v] = l;
			len[v] = 1;
			return;
		}
		long long m = (r + l) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
		len[v] = len[2 * v + 1] + len[2 * v + 2];
		mins[v] = min(mins[2 * v + 1], mins[2 * v + 2]);
		maxs[v] = max(maxs[2 * v + 1], maxs[2 * v + 2]);
		if (maxs[2 * v + 1] > maxs[2 * v + 2]) {
			maxs_i[v] = maxs_i[2 * v + 1];
		}
		else {
			maxs_i[v] = maxs_i[2 * v + 2];
		}
	}

	void push_set(long long l, long long r, long long v) {
		if (r - l == 1) {
			return;
		}
		if (sets[v] == BIG)
			return;
		sets[2 * v + 1] = sets[v];
		maxs[2 * v + 1] = sets[v];
		mins[2 * v + 1] = sets[v];
		t[2 * v + 1] = sets[v] * len[2 * v + 1];
		sets[2 * v + 2] = sets[v];
		maxs[2 * v + 2] = sets[v];
		mins[2 * v + 2] = sets[v];
		t[2 * v + 2] = sets[v] * len[2 * v + 2];
		sets[v] = BIG;
	}
	void push_inc(long long l, long long r, long long v) {
		if (r - l == 1) {
			return;
		}
		if (incs[v] == BIG)
			return;

		incs[2 * v + 1] = incs[v];
		maxs[2 * v + 1] = maxs[2 * v + 1] + incs[v];
		mins[2 * v + 1] = mins[2 * v + 1] + incs[v];
		t[2 * v + 1] += incs[v] * len[2 * v + 1];
		incs[2 * v + 2] = incs[v];
		maxs[2 * v + 2] = maxs[2 * v + 2] + incs[v];
		mins[2 * v + 2] = mins[2 * v + 2] + incs[v];
		t[2 * v + 2] += incs[v] * len[2 * v + 2];
		incs[v] = BIG;

	}
	long long get_sum_func (long long v, long long l, long long r, long long xl, long long xr) {
		push_set(l, r, v);
		if (l >= xr || r <= xl) {
			return 0;
		}
		if (l >= xl && r <= xr) {
			return t[v];
		}
		long long m = (l + r) / 2;
		return get_sum_func(2 * v + 1, l, m, xl, xr) + get_sum_func(2 * v + 2, m, r, xl, xr);
	}

	long long get_min_func(long long v, long long l, long long r, long long xl, long long xr) {
		push_set(l, r, v);
		if (l >= xr || r <= xl) {
			return BIG;
		}
		if (l >= xl && r <= xr) {
			return mins[v];
		}
		long long m = (l + r) / 2;
		return min(get_min_func(2 * v + 1, l, m, xl, xr),get_min_func(2 * v + 2, m, r, xl, xr));
	}

	long long get_max_func(long long v, long long l, long long r, long long xl, long long xr) {
		if (l >= xr || r <= xl) {
			return BIG * -1;
		}
		if (l >= xl && r <= xr) {
			return maxs[v];
		}
		long long m = (l + r) / 2;
		return max(get_max_func(2 * v + 1, l, m, xl, xr), get_max_func(2 * v + 2, m, r, xl, xr));
	}

	void enc_func(long long v, long long l, long long r, long long pos, long long x) {
		if (l == r - 1) {
			t[v] += x;
			return;
		}
		long long m = (l + r) / 2;
		if (pos < m) {
			enc_func(2 * v + 1, l, m, pos, x);
		}
		else {
			enc_func(2 * v + 2, m, r, pos, x);
		}
		t[v] = t[2 * v + 1] + t[2 * v + 2];
		mins[v] = min(mins[2 * v + 1], mins[2 * v + 2]);
		maxs[v] = max(maxs[2 * v + 1], maxs[2 * v + 2]);
		if (maxs[2 * v + 1] > maxs[2 * v + 2]) {
			maxs_i[v] = maxs_i[2 * v + 1];
		}
		else {
			maxs_i[v] = maxs_i[2 * v + 2];
		}
	}

	void change_func(long long v, long long l, long long r, long long pos, long long x) {
		push_set(l, r, v);
		if (l == r - 1) {
			t[v] = x;
			mins[v] = x;
			maxs[v] = x;
			return;
		}
		long long m = (l + r) / 2;
		if (pos < m) {
			change_func(2 * v + 1, l, m, pos, x);
		}
		else {
			change_func(2 * v + 2, m, r, pos, x);
		}
		t[v] = t[2 * v + 1] + t[2 * v + 2];
		mins[v] = min(mins[2 * v + 1], mins[2 * v + 2]);
		maxs[v] = max(maxs[2 * v + 1], maxs[2 * v + 2]);
		if (maxs[2 * v + 1] > maxs[2 * v + 2]) {
			maxs_i[v] = maxs_i[2 * v + 1];
		}
		else {
			maxs_i[v] = maxs_i[2 * v + 2];
		}
	}

	Point get_max_i_func(long long v, long long l, long long r, long long xl, long long xr) {
		if (l >= xr || r <= xl) {
			return Point(-BIG, -1);
		}
		if (l >= xl && r <= xr) {
			return Point(maxs[v], maxs_i[v]);
		}
		long long m = (l + r) / 2;
		return max(get_max_i_func(2 * v + 1, l, m, xl, xr), get_max_i_func(2 * v + 2, m, r, xl, xr));
	}

	


	void set_func(long long l, long long r, long long x, long long xl, long long xr, long long v) {
		push_set(l, r, v);
		if (l >= xr || xl >= r) {
			return;
		}
		if (xl <= l && xr >= r) {
			sets[v] = x;
			maxs[v] = sets[v];
			mins[v] = sets[v];
			t[v] = sets[v] * len[v];
			return;
		}

		long long m = (l + r) / 2;
		set_func(l, m, x, xl, xr, 2 * v + 1);
		set_func(m, r, x, xl, xr, 2 * v + 2);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
		mins[v] = min(mins[2 * v + 1], mins[2 * v + 2]);
		maxs[v] = max(maxs[2 * v + 1], maxs[2 * v + 2]);

	}


	long long get_sum(long long l, long long r) {
		return get_sum_func(0, 0, n, l, r);
	}

	long long get_min(long long l, long long r) {
		return get_min_func(0, 0, n, l, r);
	}

	void inc(long long pos,long long x) {
		enc_func(0, 0, n, pos, x);
		return;
	}

	void set(long long l, long long r, long long x) {
		set_func(0, n, x, l, r, 0);
		return;
	}

	void change(long long pos, long long x) {
		change_func(0, 0, n, pos, x);
		return;
	}

	long long get_max_i(long long l, long long r){
		Point res = get_max_i_func(0, 0, n, l, r);
		return res.y;
	}

};


void dfs1(vector<int>* out, int v, bool mark[], vector<int>& sorted) {
	if (mark[v]) { return; }
	else { mark[v] = true; }
	for (int i = 0; i < out[v].size(); i++)
	{
		dfs1(out, out[v][i], mark, sorted);
	}
	sorted.push_back(v);


}

void dfs2(int res[], int v, int c, vector<int>* in) {
	if (res[v] != 0) { return; }
	res[v] = c;
	for (int i = 0; i < in[v].size(); i++)
	{
		dfs2(res, in[v][i], c, in);
	}


}



int* cond(vector<int>*in, vector<int>* out, int n) {
	vector<int> sorted;
	bool* mark = new bool[n]{0};
	for (int i = 0; i < n; i++)
	{
		if (mark[i] == false) {
			dfs1(out, i, mark, sorted);
		}
	}
	int* res = new int[n]{0};
	int c = 1;

	for (int i = sorted.size() - 1; i >= 0; i--)
	{
		if (res[sorted[i]] == 0) {
			dfs2(res, sorted[i], c, in);
			c++;
		}
	}

	
	return res;

}

void dfs(vector<int>* a, int b[], int v, int t) {
	b[v] = t;
	for (int i = 0; i < a[v].size(); i++)
	{
		if (b[a[v][i]] == -1) {
			dfs(a, b, a[v][i], t);
		}
	}
}

using ull = unsigned long long;


ull gcd(ull x, ull y) {
	return x ? gcd(y % x, x) : y;
} 

ull lcm(ull x, ull y) {
	return x * y / gcd(x, y);
} 


class id0 {
public:
	ll* a;
	ll** mins;
	ll** maxs;
	ll* d;
	vector<ll> st;
	id0(ll a[], ll n) {
		this->a = a;
		this->mins = new ll*[n];
		this->maxs = new ll*[n];
		this->d = new ll[n];
		ll k = 0;
		ll pk = 1;
		for (ll i = 0; i < n; i++)
		{
			if (pk * 2 <= i + 1) {
				k++;
				pk *= 2;
			}
			d[i] = k;
		}
		ll temp = 1;
		ll c = 0;
		st.push_back(temp);
		while (temp * 2 <= n) {
			c++;
			temp *= 2;
			st.push_back(temp);
		}
		c++;
		for (ll i = 0; i < n; i++)
		{
			mins[i] = new ll[c];
			maxs[i] = new ll[c];
		}
		for (ll i = 0; i < n; i++)
		{
			mins[i][0] = a[i];
			maxs[i][0] = a[i];
		}

		for (ll i = 1; i < c; i++)
		{
			for (ll j = 0; j <= n - st[i]; j++)
			{
				mins[j][i] = min(mins[j][i - 1], mins[j + st[i - 1]][i - 1]);
				maxs[j][i] = max(maxs[j][i - 1], maxs[j + st[i - 1]][i - 1]);
			}
		}
	}

	id0() {
		a = NULL;
		mins = NULL;
		maxs = NULL;
		d = NULL;
	}

	ll get_min(ll l, ll r) {
		ll k = d[r - l - 1];
		return min(mins[l][k], mins[r - st[k]][k]);
	}

	ll get_max(ll l, ll r) {
		ll k = d[r - l - 1];
		return max(maxs[l][k], maxs[r - st[k]][k]);
	}
};

int to_bc(int k[], vector<int> a[], int n) {
	for (int i = 0; i < n; i++)
	{
		k[i] = -1;
	}

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (k[i] == -1) {
			dfs(a, k, i, temp);
			temp++;
		}
	}
	return temp;
}





class card {
public:
	int* ch;
	int id;
	int k;
	card() {
		ch = NULL;
		id = -1;
		k = 0;
	}
	card(int n, int i) {
		ch = new int[n];
		k = n;
		id = i;
	}
	void setch(int i, int k) {
		ch[i] = k;
	}
};

class sat {
public:
	card first;
	card second;
	card third;
	sat() {

	}
	sat(card f, card s, card t) {
		first = f;
		second = s;
		third = t;
	}
};

bool is_sat(card f, card s, card t) {
	for (int i = 0; i < f.k; i++)
	{
		if (f.ch[i] == s.ch[i] && s.ch[i] == t.ch[i]) {
			continue;
		}
		if (f.ch[i] != s.ch[i] && s.ch[i] != t.ch[i] && f.ch[i] != t.ch[i]) {
			continue;
		}
		return false;
	}
	return true;
}

bool id1(sat f, sat s) {
	int res = 0;
	if (f.first.id == s.first.id) {
		res++;
	}
	if (f.first.id == s.second.id) {
		res++;
	}
	if (f.first.id == s.third.id) {
		res++;
	}
	if (f.second.id == s.first.id) {
		res++;
	}
	if (f.second.id == s.second.id) {
		res++;
	}
	if (f.second.id == s.third.id) {
		res++;
	}
	if (f.third.id == s.first.id) {
		res++;
	}
	if (f.third.id == s.second.id) {
		res++;
	}
	if (f.third.id == s.third.id) {
		res++;
	}

	if (res == 1) {
		return true;

	}
	else {
		return false;
	}
}


int main()
{
	int n, k;
	cin >> n >> k;
	card* cards = new card[n];
	vector<sat> sets;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cards[i] = card(k, i);
		for (int j = 0; j < k; j++)
		{
			cin >> temp;
			cards[i].setch(j, temp);
		}
	}

	int* a = new int[n]{0};
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int h = j + 1; h < n; h++)
			{

				if (is_sat(cards[i], cards[j], cards[h])) {
					a[i]++;
					a[j]++;
					a[h]++;

				}

			}
		}
	}

	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += (a[i] * (a[i] - 1)) / 2;
	}
	cout << res<< endl;

}


