









































































































































































































































































































































































































    










































































using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 




const int N = 2e5+1;
const int mod = 1e9+7;




void show_me(int t) {cout << t;}
void show_me(string t) {cout << t;}
void show_me(char t) {cout << t;}
void show_me(bool t) {cout << t;}
void show_me(double t) {cout << t;}
void show_me(ordered_set v) {cout << "[ "; for (auto i : v) {show_me(i); cout << " ";} cout << "]";}
template <class T, class V> void show_me(pair <T, V> p);
template <class T> void show_me(vector <T> v);
template <class T> void show_me(set <T> v);
template <class T> void show_me(multiset <T> v);
template <class T, class V> void show_me(map <T, V> v);
template <class T, class V> void show_me(multimap <T, V> v);






vector<int>g[N],level(N);
vector<bool> is_prime(N+1, true),vis(N,false);
bool id0 (int x);
int totalDigits(int n);
long long power(long long a, long long b, long long m);
int mod_inv(int n, int p); 

void id1();
void PrimeFactors(ll n, vector<pair<ll, ll>> &v);
void dfs(int vertex);
void bfs(int source);

int func(int i, int h, int g, int b, vector<int>&v, int n)
{
    if(i == n) return 0;

    int ans = 0;
    if(h > v[i])
    return func(i+1,h+v[i]/2,g,b,v,n)+1;
    if(g > 0)
    {
        ans = max(ans,func(i,h*2,g-1,b,v,n));
    }
    if(b > 0) ans = max(ans,func(i,h*3,g,b-1,v,n));
    
    return ans;
    
}
void MainCode()
{
    int n,h, ans = 0;
    cin >> n >> h;

    vector<int>v(n);
    map<int,int>m;
    for(auto &x : v)
    {
        cin >> x; 
    }
    sort(v.begin(),v.end());
    cout << func(0,h,2,1,v,n) << endl;
}


signed main()
{
    FastandFurious
    int id2 = 1;
    cin >> id2; 

    

    for(int TestCase = 1; TestCase <= id2 ; TestCase++)
    {
        

        MainCode();
    }
    return 0;
}



template <class T, class V> void show_me(pair <T, V> p) {cout << "{"; show_me(p.first); cout << ","; show_me(p.second); cout << "}";}
template <class T> void show_me(vector <T> v) {cout << "[ "; for (T i : v) {show_me(i); cout << " ";} cout << "]";}
template <class T> void show_me(set <T> v) {cout << "[ "; for (T i : v) {show_me(i); cout << " ";} cout << "]";}
template <class T> void show_me(multiset <T> v) {cout << "[ "; for (T i : v) {show_me(i); cout << " ";} cout << "]";}
template <class T, class V> void show_me(map <T, V> v) {cout << "[ "; for (auto i : v) {show_me(i); cout << " ";} cout << "]";}
template <class T, class V> void show_me(multimap <T, V> v) {cout << "[ "; for (auto i : v) {show_me(i); cout << " ";} cout << "]";}


bool id0 (int x){ 
    

return x&& (!(x&(x-1)));
}
int totalDigits(int n)
{
    if(n == 0) return 1; 
    return floor(log10(n))+1; 
}
int mod_inv(int n, int p){
return power(n, p-2, p);
}
long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void id1()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}
void PrimeFactors(ll n, vector<pair<ll, ll>> &v)
{
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i != 0)
            continue;
        ll cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            ++cnt;
        }
        v.push_back({i, cnt});
    }
    if (n != 1)
        v.push_back({n, 1});
    sort(v.begin(), v.end());
}
void dfs(int vertex)
{
    
    vis[vertex] = true;
    
    for(int child : g[vertex])
    {
        

        if(vis[child]) continue;

        dfs(child);

           
    }
    
}
void bfs(int source)
{
    queue < int > q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();

        for(int child : g[curr_v]){

            if(!vis[curr_v]){

                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v]+1;

            }
        }
    } 
}