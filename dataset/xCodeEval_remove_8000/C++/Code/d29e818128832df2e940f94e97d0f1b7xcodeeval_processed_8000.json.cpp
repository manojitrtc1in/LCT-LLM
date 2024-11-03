

using namespace std;























































[[noreturn]] __attribute__((always_inline)) inline void undefinedBehaviour() {}














typedef long long ll;typedef long double ld;typedef complex<ld> cd;typedef pair<int, int> pi;
typedef long long ll;typedef long double ld;typedef complex<ld> cd;typedef pair<int, int> pi;
typedef pair<ll,ll> pl;typedef pair<ld,ld> pd;
typedef vector<int> vi;typedef vector<ld> vd;typedef vector<ll> vl;
typedef vector<pi> vpi;typedef vector<pl> vpl;
typedef vector<cd> vcd; template<class T> using pq = priority_queue<T>; template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;












 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");} template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>


























    
    
    
    
    

    
    
    
void id1()
{
    string id1[3]= { "RIGHT\n", "LEFT\n", "PRINT " };
    char s[10001];
    int n, b, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }
    if(k > n / 2)
    {

        for(int i = k; i < n; i++)
        {
            cout << id1[0];
        }

        for(int i = n - 1; i >= 0; i--)
        {

            cout << id1[2] << s[i]<<endl;

            if(i > 0)
            {
                cout << id1[1];
            }
        }
    }
    else
    {
        for(int i = 1; i < k; i++)
        {
            cout << id1[1];
        }
        for(int i = 0; i < n; i++ )
        {
            cout << id1[2] << s[i] << endl;
            if(i < n - 1)
            {
                cout << id1[0];
            }
        }
    }
}
void id2()
{
    int r, c, k = 0, f = 0, h = 0, l = 0;
    cin >> r >> c;
    char a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++)
    {
        int f = 0;
        for (int j = 0; j < c; j++)
            if (a[i][j] == '.')
                f++;
        if (f == c)
            k++;
    }
    for (int i = 0; i < c; i++)
    {
        int l = 0;
        for (int j = 0; j < r; j++)
            if (a[j][i] == '.')
                l++;
        if (l == r)
            h++;
    }
    cout << k * c + h * r - k * h;
}
void id3()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n + 1001];
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
        int k = 2;
        for(int i = 1 ; i <= n ; i++)
        {
            if(is_sorted(a + 1, a + n + 1))   

            {
                k = 0;
            }
            else if(a[1] == 1 || a[n] == n)
            {
                k = 1;
            }
            else if(a[1] == n && a[n] == 1)
            {
                k = 3;
            }
        }
        cout << k << "\n";
    }
}
void id0()
{
    ll f, k = 0, i, n = 5, max = 0, m, sum1 = 0, sum2 = 0;        

    ll a[999];
    string s, s2;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = i ; j < s.size() - 1 ; j ++)
        {
            if(s[i] == s[j + 1])
            {
                s[j + 1] -= s[j + 1];
            }
        }
    }
}
void q()
{
    int k = 0;
    string l, v;
    cin >> l >> v;
    reverse(l.begin(), l.end());
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] != l[i])
        {
            k ++;
        }
    }
    cout << k;
}
void w()
{
    int n;
    cin >> n;
    cout << ((n + 3) % 7) + 1;
}
void e()
{
    int a, b; cin >> a >> b;
    if(b % a != 0)
    {
        cout << b / a + 1 << " " << b - ((b / a) * a);
    }
    else
    {
        cout << b / a << " " << a;
    }
}
void r()
{
    long long n;
    cin >> n;
    long long a[n + 1937];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int t = unique(a, a + n) - a; 

    for(int i = 0 ; i < t ; i++)
    {
        cout << a[i] << " ";
    }
}
void t()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        long long a[n];
        long long mn = 0,mx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mn += a[i];
            mx += (a[i] + x - 1) / x;
        }
        mn = (mn + x - 1) / x;
        cout << mn << " " << mx << "\n";
    }
}
void y()
{
    long long t, f, a, b, mx = -1e9, k = 0;
    cin >> t >> f;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b;
        if(b > f)
        {
            mx = max(mx, (a - (b - f)));
        }
        else
        {
            mx = max(mx, a);
        }
    }
    cout << mx;
    n1
}
void u()
{
    int n, j = 0, k = 0;

    cin >> n;

    for( ; ; )
    {
        if(j == n)
        {
            break;
        }
        else
        {
            k ++;
        }
        j = 0;
        for(int i = 1 ; i <=  n ; i++)
        {
            if(k % i == 0)
            {
                j ++;
            }
        }
    }
    cout << k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a >= d && b >= c)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    n1
}
void klop()
{
    int k, l;
    string a, b, p, j;
    cin >> a >> b;
    for(int i = 0 ; i <= a.size(); i++)
    {
        if(int(a[i]) < 97)
        {
            a[i] += 32;
            p += a[i];
        }
    }
    for(int i = 0 ; i <= b.size() ; i++)
    {
        if(int(b[i]) < 97)
        {
            b[i] += 32;
            j += b[i];
        }
    }
    if(a < b)
    {
        cout << -1;
    }
    else if(a > b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
signed int main()
{
    

    
    
    
    
    

    
    
    
  
    ll t , n;
    char s[10001];
cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n;
		for (int i = 1;i <= n;i++){
                cin >> s[i];
			cnt += (s[i] != '?');
			}
		if (cnt < 1){
			s[1] = 'R';
		}
		for (int i = 2 ; i <= n ; i++){
			if (s[i] == '?' && s[i - 1] != '?')
				s[i] = s[i-1] ^ ('B' ^ 'R');
		}
		for (int i = n - 1 ; i >= 1 ;i--)
			if (s[i] == '?' && s[i + 1] != '?'){
				s[i] = s[i + 1] ^ ('B' ^ 'R');
			}
		for(int i = 1 ;i <= n ; i++){
            cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}






