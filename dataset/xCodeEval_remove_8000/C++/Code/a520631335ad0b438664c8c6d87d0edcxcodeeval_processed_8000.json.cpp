








using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> inline void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) {x = min(x, y); }

const int N = 1e5 + 10;
int n;
ll a[N], b[1010][1010];








bool vis[N];
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }




int rnd(int x) { return (ll) (rand() + rand()) % x + 1;}
ll query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	ll z;
	cin >> z;
	

	

	return z;
}
ll getmax(ll x) {
	ll ans = 1;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ans = i;
			while (x % i == 0) x /= i;
		}
	chkmax(ans, x);
	return ans;
}

signed main() {
	srand(time(NULL));
	int _; 
	cin >> _;
	

	while (_--) {
		cin >> n;
		

		if (n < 100) {
			F(i, 1, n) {
				a[i] = 0;
				F(j, 1, n)
					if (i != j) {
						if (i < j) b[i][j] = query(i, j);
						else b[i][j] = b[j][i];
						a[i] = gcd(a[i], b[i][j]);
					}
			}
			cout << "! ";
			if (n == 3) {
				int mx = 0, x;
				F(i, 1, n)
					if (a[i] > mx) {
						mx = a[i];
						x = i;
					}
				if (a[x] % 2 == 0) a[x] /= 2;
			}
			F(i, 1, n) cout << a[i] << " "; cout << endl;
		} else {
			F(i, 1, n) vis[i] = false;
			ll z = 0; int kx, ky;
			F(i, 1, 2000) {
				if (i * 2 + 5 >= n) break;
				

				int x = rnd(n), y = rnd(n);
				

				while (x == y || vis[x] || vis[y]) x = rnd(n), y = rnd(n);
				vis[x] = true; vis[y] = true;
				ll k = getmax(query(x, y));
				if (k > z) {
					z = k;
					kx = x; ky = y;
				}
				

				

			}
			int kz = rnd(n), ans;
			while (kz == kx || kz == ky) kz = rnd(n);
			if (query(kx, kz) % z == 0) ans = kx;
			else ans = ky;
			

			F(i, 1, n)
				if (i == ans) a[i] = z;
				else a[i] = query(i, ans) / z;
			cout << "! ";
			F(i, 1, n) cout << a[i] << " "; cout << endl;
		}
	}
	return 0;
}