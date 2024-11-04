















































































































































































































































































































































































































































































































































































































































































































using namespace std;




void faltu() {
	cerr << endl;
}

template <typename T>
void faltu(T a[], int n) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename First, typename ... hello>
void faltu(First arg, const hello&... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}





















typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;










inline bool checkBit(ll n, int i) { return n & (1LL << i); }
inline ll setBit(ll n, int i) { return n | (1LL << i); }
inline ll resetBit(ll n, int i) { return n & (~ (1LL << i)); }
inline bool EQ(double a, double b) { return fabs(a-b) < EPS; }
inline double dist(double ix, double iy, double jx, double jy) { return sqrt(SQR(ix - jx) + SQR(iy - jy)); }



int marked[PMX/64+2];




bool isPrime(int x)
{
    return (x>1) && ((x==2) || ((x&1) && (!(check(x)))));
}

void seive(int n)
{
    int i, j;
    for(i=3; i*i<=n; i+=2)
    {
        if(!check(i))
        {
            for(j=i*i; j<=n; j+=i<<1)
            {
                mark(j);
            }
        }
    }
}

ll bigMod(ll a, ll b)
{
	ll r = 1;
	while(b) {
		if(b & 1) (r *= a) %= MOD;
		b >>= 1;
		(a *= a) %= MOD;
	}
	return r;
}

ll add(ll a, ll b)
{
	ll ret = a + b;
	if(ret >= MOD) ret -= MOD;
	return ret;
}

ll sub(ll a, ll b)
{
	ll ret = a - b;
	if(ret < 0) ret += MOD;
	return ret;
}





int cnt, l, f[MX2], nxt[MX2][26];
vector<int> edge[MX1];
char t[MX2], in[MX2];
string s[MX1];

void kmp()
{
	int i, j;

	f[0] = f[1] = 0;
	for(i = 2; i <= l; i ++) {

		j = f[i - 1];

		while(true) {

			if(t[i - 1] == t[j]) {

				f[i] = j + 1;
				break;
			}
			if(j == 0) {

				f[i] = 0;
				break;
			}
			j = f[j];
		}
	}
	for(i = 0; i < l; i ++)
		for(j = 0; j < 26; j ++)
			nxt[i][j] = (t[i] - 'a' == j) ? i + 1 : nxt[ f[i] ][j];
			
}

void dfs(int nd, int k)
{
	int i, j;
	for(auto it : edge[nd]) {

		i = k;
		for(j = 0; j < s[it].size(); j ++) {

			i = nxt[i][ s[it][j] - 'a'];
			if(i == l) {

				cnt ++;
				i = f[i];
			}

			
		}
		dfs(it, i);
	}
}

int main()
{

	


	int n, i, x;

	scanf("%d", &n);
	for(i = 2; i <= n; i ++) {

		scanf("%d %s", &x, in);
		edge[x].PB(i);
		s[i] = string(in);
	}
	scanf("%s", t);
	l = strlen(t);
	kmp();
	dfs(1, 0);
	printf("%d\n", cnt);
        return 0;
}