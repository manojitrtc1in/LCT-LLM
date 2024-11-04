
using namespace std;
















using namespace __gnu_pbds;

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
	
const int MAX = 205000;
const int NMAX = 210000, MMAX = 5002000;
int st[MMAX][2], root[NMAX];
ll val[MMAX], lazy[MMAX];
bool updated[MMAX];
	
int V = 0, N;
	
int node(){
	st[V][0] = st[V][1] = -1;
	updated[V] = true;
	lazy[V] = 0;
	val[V] = 0;
	return V++;
}
	
void initST(){
	root[0] = node();
	st[root[0]][0] = st[root[0]][1] = root[0];
}

void sub_update(int node, int l, int r) {
	if(!updated[node]) {
		val[node] += lazy[node] * (r - l + 1);
		if(l != r) {
			int nodeL = st[node][0];
			int nodeR = st[node][1];
			updated[nodeL] = updated[nodeR] = false;
			lazy[nodeL] += lazy[node];
			lazy[nodeR] += lazy[node];
		}
		updated[node] = true;
		lazy[node] = 0;
	}
}

void update(int n, int l, int r, int L, int R, ll v) {
	

	if(st[n][0] == -1) st[n][0] = node();
	if(st[n][1] == -1) st[n][1] = node();
	sub_update(n, l, r);
	if(R < l || r < L);
	else if(L <= l && r <= R) {
		updated[n] = false;
		lazy[n] = v;
		sub_update(n, l, r);
	}
	else {
		int m = l + (r - l)/2;
		update(st[n][0], l, m, L, R, v);
		update(st[n][1], m + 1, r, L, R, v);
		val[n] = val[st[n][0]] + val[st[n][1]];
	}
	

}

ll query(int n, int l, int r, int L, int R) {
	if(st[n][0] == -1) st[n][0] = node();
	if(st[n][1] == -1) st[n][1] = node();
	sub_update(n, l, r);
	if(R < l || r < L) return 0;
	else if(L <= l && r <= R) {
		

		return val[n];
	}
	else {
		int m = l + (r - l)/2;
		return query(st[n][0], l, m, L, R) + query(st[n][1], m + 1, r, L, R);
	}
}
	
void insert(int t, int v, int add) {
	if(add == 0) {
		root[t] = root[t - 1];
		return;
	}
	int actual = root[t] = node();
	int last = root[t - 1];
	int L = 1, R = N;
	while(true){
		val[actual] = val[last] + add;
		if(L == R) break;
		else{
			int M = (L + R)/2;
			if(v <= M){
				st[actual][0] = node();
				st[actual][1] = st[last][1];
				R = M;
				actual = st[actual][0];
				last = st[last][0];
			}
			else{
				st[actual][0] = st[last][0];
				st[actual][1] = node();
				L = M + 1;
				actual = st[actual][1];
				last = st[last][1];
			}
		}
	}
}
	
ll query(int current, int last, int l, int r, int L, int R) {
	if(R < l || r < L) return 0;
	else if(L <= l && r <= R) return val[current] - val[last];
	else {
		int m = (l + r)/2;
		return query(st[current][0], st[last][0], l, m, L, R) + query(st[current][1], st[last][1], m + 1, r, L, R);
	}
}
	
int a[MAX], inv[MAX];
ll ans[MAX], cross[MAX];
ll ST[4*MAX];

void up(int n, int l, int r, int pos, int v) {
	if(r < pos || pos < l) return;
	else if(l == pos &&  r == pos) ST[n] += v;
	else {
		int m = (l + r)/2;
		up(2*n, l, m, pos, v);
		up(2*n + 1, m + 1, r, pos, v);
		ST[n] = ST[2*n] + ST[2*n + 1];
	}
}


ll q(int n, int l, int r, int L, int R) {
	if(r < L || R < l) return 0;
	else if(L <= l && r <= R) return ST[n];
	else {
		int m = (l + r)/2;
		return q(2*n, l, m, L, R) + q(2*n + 1, m + 1, r, L, R);
	}
}
	
ll mq(int l, int r) {
	return (r - l + 1) - q(1, 1, N, l, r);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", a + i);
	initST();
	for(int i = 1; i <= N; i++) {
		insert(i, a[i], 1);
	}
	for(int i = 1; i <= N; i++) inv[a[i]] = i;
	for(int i = 1; i <= N; i++) {
		cross[i] = cross[i - 1];
		int j = inv[i];
		if(j != N) cross[i] += query(root[N], root[j], 1, N, 1, i - 1);
	}

	ordered_set S;
	int time = 0;

	V = 0;
	node();
	S.clear();
	for(int i = 1; i <= N; i++) {
		

		ans[i] = ans[i - 1];
		up(1, 1, N, inv[i], 1);
		

		if(i == 1);
		else if(i == 2) ans[i] = abs(inv[2] - inv[1]) - 1;
		else {
			int cantidad = i - 1;
			int m1 = S.find_by_order((cantidad - 1)/2)->st;
			int m2 = S.find_by_order(cantidad/2)->st;
			int k = S.order_of_key(mp(inv[i], 0));
			if(m1 <= inv[i] && inv[i] <= m2) ans[i] -= min(k, i - 1 - k);
			else {
				int m = (abs(inv[i] - m1) < abs(inv[i] - m2) ? m1 : m2);
				ans[i] -= min(k, i - 1 - k);
				int u = inv[i], v = m;
				if(u > v) swap(u, v);
				ans[i] += mq(u, v);
			}
			


			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			

			

			

			

			

			

		}
		S.insert(mp(inv[i], time++));
	}
	


	for(int i = 1; i <= N; i++) printf("%lld%c", ans[i] + cross[i], i == N ? '\n' : ' ');
}




















































































































































































































































































































