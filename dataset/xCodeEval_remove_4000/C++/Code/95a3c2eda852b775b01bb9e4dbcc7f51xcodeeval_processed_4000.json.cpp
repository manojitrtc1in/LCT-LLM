




using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

inline ll rd(){
	ll x = 0; bool f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-')	f ^= 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f ? x : -x;
}

int n, m, t = 1;
int sz[maxn];
int a[maxn];
vector<int> v[maxn];



















































































































































int test[10] = 










{0, 1, 5, 4, 6, 3, 2};


inline int q2(int i, int j, int x) {
	return min(max(x, test[i]), max(x + 1, test[j]));
}
inline int q1(int i, int j, int x) {
	return max(min(x, test[i]), min(x + 1, test[j]));
}
inline void run(int op, int i, int j, int x) {
	return ;
	if(op == 1)	cout << q1(i, j, x) << endl;
	else cout << q2(i, j, x) << endl;
}
inline int query(int op, int i, int j, int x) {
	if(i < 1)	i += n;
	if(i > n)	i -= n;
	if(j < 1)	j += n;
	if(j > n)	j -= n;
	printf("? %d %d %d %d", op, i, j, x); cout << endl;
				
	run(op, i, j, x);
				
	int res; scanf("%d", &res); return res;
}
int vis[maxn];
void dfs(int now, int fa, int add) {
	if(a[now]) {
		

		return ;
	}
	if(now == n + 1)	now = 1;
	if(now == 0)	now = n;
	if(v[now][0] == a[fa] || v[now][1] == a[fa]) {
		printf("? 1 %d %d %d", fa, now, n - 1); cout << endl;
				
		run(1, fa, now, n - 1);
				
		int res; scanf("%d", &res); a[now] = res, vis[res] = 1;
		dfs(now + add, now, add);
	}
	else a[now] = max(v[now][0], v[now][1]), vis[a[now]] = 1;
















}
int num[maxn], ncnt = 0;
signed main(){
	cin >> t;
	while(t--) {
		cin >> n;
		int pos = -1;
		for(int i = 1; i <= n; i += 2) {
			int nxt = i + 1; if(nxt == n + 1) nxt = 1;
			int res = query(2, i, nxt, 1);
			if(res == 1) {
				a[i] = 1; pos = i; break;
			} 
			else if(res == 2) {
				res = query(2, nxt, i, 1);
				if(res == 1) {
					a[nxt] = 1; pos = nxt; break;
				}
			}
		}
		

		for(int i = 1; i <= n; ++ i) {
			if(i != pos) a[i] = query(1, pos, i, n - 1);
		}
		printf("! ");
		for(int i = 1; i <= n; ++ i)	printf("%d%c", a[i], " \n"[i == n]);
	}
}



















































































































































































































































































































