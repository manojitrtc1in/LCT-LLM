





std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
namespace io
{
	template<typename T> inline void read(T&a){
		int c = getchar(),sign = 0;
		a = 0;
		while(c < '0' || c >'9') sign += (c == '-'),c = getchar();
		while (c >='0' && c <='9') a = (a << 1) + (a << 3) + c-48,c = getchar();
		if (sign&1) a = -a;
	}
	template<typename T,typename... _T>
	inline void read(T&a,_T& ...argc)
	{
		read(a);read(argc...);
	}
	template<typename T>
	inline void Write(T a)
	{
		if (a > 9) Write(a/10);
		putchar(a % 10 + '0');
	}
	template<typename T>
	inline void write(T a,char ch = ' ')
	{
		if (a < 0) putchar('-'),a = -a;
		Write(a);
		putchar(ch);
	}
	template<typename T> inline void Min(T&a,T b){a = min(a,b);}
	template<typename T> inline void Max(T&a,T b){a = max(a,b);}
	template<typename T,typename... _T> inline void Min(T&a,T b,_T ...c){Min(a,b);Min(a,c...);}
	template<typename T,typename... _T> inline void Max(T&a,T b,_T ...c){Max(a,b);Max(a,c...);}
}
using namespace io;
const int maxn= 2e5 + 3 ;
const int N = 2e5 + 3;
const int mod=998244353;
int n,m,q;
int dem[N],id[N],chot[N],a[N];
int k,h;
ll t[N + 3];
int dp[N];
string  s;
bool kt[N];
map<ll,int> maps;
vector<pair<int,int>> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

ll st[N * 4];

void build (int id,int l,int r)
{
	if (l == r)
	{
		st[id] = l-1;
		return ;
	}
	int mid = l + r >> 1;
	build(id << 1,l,mid);
	build(id << 1|1,mid + 1,r);
	st[id] = st[id << 1] + st[id << 1|1];
}

void update(int id,int l,int r,int pos,int val)
{
	if (l > pos || r < pos) return ;
	if (l == pos && r == pos)
	{
		st[id] = val ;
		return ;
	}
	int mid = l + r >> 1;
	update(id << 1,l,mid,pos,val);
	update(id << 1|1,mid +1,r,pos,val);
	st[id] = st[id << 1] + st[id << 1|1];
}

ll get(int id,int l,int r,int L,int R)
{
	if (L > r || R < l) return 0;
	if (L <= l && r <= R) return st[id];
	int mid = l + r >> 1;
	return get(id << 1,l,mid,L,R) + get(id << 1|1,mid + 1,r,L,R);
}

int find(int u)
{
	return !kt[u] ? u : id[u] = find(id[u]);
}

int main()
{
	IOS;
	cin >> n;
	for (int i = 1;i <= n;++i) cin >> t[i],id[i] = i-1;
	build(1,1,n);
	for (int i =n;i >= 1;--i)
	{
		int l = 1,r = n;
		while  (l <= r)
		{
			int mid = l + r >> 1;
			if (get(1,1,n,1,mid) <= t[i]) l = mid + 1;
			else r = mid-1;
		}
		r = find(r);
		chot[i] = r;
		kt[r] = true;
		update(1,1,n,r+1,0);
	}
	for (int i = 1;i <= n;++i) cout << chot[i] <<" ";
}


