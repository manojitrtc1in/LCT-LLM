























using namespace std;






















































































































































template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} 

inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;} 


const int inf = 0x3f3f3f3f; 

const long long llinf = 0x3f3f3f3f3f3f3f3fLL; 

const double pi = acos(-1.0);















































typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p2;
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vector<int>, greater<int> > spqi; 







































int cas;
const int mx = 1e5 + 5;


typedef long long ll;

const int N = 1e5 + 10;
int a[N];

set<int> pos[18];
set<int>::iterator low, up;
ll sum[18];

void one(int p, int v)
{
	pos[p].erase(v);
    low = up = pos[p].upper_bound(v);
	sum[p] += ll(v - *--low) * (*up - v);



}

void zero(int p, int v)
{
    low = up = pos[p].upper_bound(v);
	sum[p] -= ll(v - *--low) * (*up - v);
	pos[p].insert(v);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 18; i++) for (int j = 0; j <= n + 1; j++) pos[i].insert(j); 

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 18; i++) for (int j = 0; j <= n + 1; j++) if (a[j] >> i & 1) one(i, j);
	while (m--)
	{
		int p, v;
		scanf("%d%d", &p, &v);
		for (int i = 0; i < 18; i++)
		{
			if (v >> i & 1) {if (pos[i].count(p)) one(i, p);} 

			else if (!pos[i].count(p)) zero(i, p); 

		}
		ll ans = 0;
		for (int i = 0; i < 18; i++) ans += sum[i] * (1 << i);
		cout << ans << '\n';
	}
	return 0;
}
