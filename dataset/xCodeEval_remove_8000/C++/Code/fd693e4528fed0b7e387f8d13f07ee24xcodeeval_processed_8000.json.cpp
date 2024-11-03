









using namespace std;





typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;












template <typename T>
inline void read (T& x)
{
	T t = 0, f = 1;
	char ch = getchar ();
	while(!isdigit (ch)){
		if(ch == '-')
			f = -1;
		ch = getchar ();
	}
	while(isdigit (ch)){
		t = (t << 3) + (t << 1) + ch - '0';
		ch = getchar ();
	}
	x = f * t;
}
template <typename T, typename... Args>
inline void read (T& t, Args &...args)
{
	read (t);
	read (args...);
}



const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 9;
const ll mod = 998244353;
string s;
int calc ()
{
	if(s == "Left") return 1;
	if(s == "Right") return 2;
	if(s == "Up") return 3;
	if(s == "Down") return 4;
	if(s == "Down-Right") return 5;
	if(s == "Down-Left") return 6;
	if(s == "Up-Left") return 7;
	if(s == "Up-Right") return 8;
	return 0;
}
int ask (int x, int y)
{
	cout << x << ' ' << y << endl;
	cout.flush ();
	cin >> s;
	return calc ();
}
int vis[10];
void solve ()
{
	while(1){
		for(int i = 1; i <= 8; i++){
			for(int j = 1; j <= 8; j++){
				if(!ask (i, (i & 1) ? j : 9 - j))
					return;
			}
		}
	}
}

signed main ()
{
	

	

	

	

	

	int T = 1;
	cin >> T;
	while(T--){
		solve ();
	}
	

	

	return 0;
}
