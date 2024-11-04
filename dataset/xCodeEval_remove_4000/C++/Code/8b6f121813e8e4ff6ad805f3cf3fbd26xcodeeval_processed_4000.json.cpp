



using namespace __gnu_pbds;
using namespace std;














const int                 maxn = 2e5 + 10;
const int                 modulo = 1000000007;
const int                 id1 = 998244353;
const double              pi = 3.141592653589;



typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


 


































 














int calculate(int p, int q)
{
 
    int expo = modulo - 2;
    while (expo)
    {
        if (expo & 1)
        {
            p = (p * q) % modulo;
        }
        q = (q * q) % modulo;
        expo >>= 1;
    }
    return p;
}
















int power(int x, unsigned int y)
{
    int res = 1;
    x = x % modulo;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % modulo;
        y = y >> 1;
        x = (x * x) % modulo;
    }
    return res;
}






























 






















 
 




































 












 


























 














const int NN = 1000000;
std::vector<int>primes;
bool IsPrime[NN];
void id0()
{
    

    memset(IsPrime, true, sizeof(IsPrime));
    IsPrime[1] = false;
    IsPrime[0] = false;
    for (int p = 2; p * p < NN; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < NN; i += p)
                IsPrime[i] = false;
        }
    }
    for (int p = 2; p < NN; p++)
        if (IsPrime[p] == true)
            primes.push_back(p);
}


int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}






 


















































int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
 


















































































































































 






 




















































 
 
 














































































































































 










































 


































 








 



const int INF = 1e18;
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};












































 
 
 
 
 
 
 
 
 
 
const int N = 2e5 + 10;
int a[N];
int dp[N];
std::vector<int> v[N];
int dfs(int u, int p)
{
    int sum = 0;
    for (auto it : v[u])
    {
        if (it == p)continue;
        sum += dfs(it, u);
    }
    dp[u] += sum;
    return dp[u];
}
void solve()
{
    string s; cin >> s;
    for (int i = 0; i < 3; i++)s[i] = tolower(s[i]);
    if (s == "yes")cout << "YES\n";
    else cout << "NO\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    w(t)
    solve();
}
	   					   									  	 	  	 	