#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>
using namespace __gnu_pbds;
using namespace std;
using namespace __gnu_cxx;
using namespace chrono;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma Voodoo magic("superfast")
typedef long long int lt;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

   

    











#define lint long long
#define setbits(x) __builtin_popcountll(x) 

#define mem(a, b) memset(a, (b), sizeof(a)) 

#define zrobits(x) __builtin_ctzll(x) 

#define mod 1000000007
#define mod1 998244353
#define inf 2e18
#define neginf -2e18
#define sp(x, y) fixed << setprecision(x) << y
#define spt(x, y)  setfill(x) << setw(y)    

#define all(x) x.begin(), x.end()
#define fori(i, a, b) for (lt i = a; i < b; i++)
#define foro(i, a, b) for (lt i = a; i > b; i--)
#define take(a, n) \
        fori(i, 0, n) { cin >> a[i]; }
#define show(a, n) \
        fori(i, 0, n) {cout<<a[i]<<" "; } cout<<endl;
#define take1(a, n) \
        fori(i, 1, n + 1) { cin >> a[i]; }
#define show1(a, n) \
        fori(i, 1, n+1) {cout<<a[i]<<" ";} cout<<endl;
#define testcase(t) \
    lint t;         \
    cin >> t;       \
    while (t--)
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define power(a, b) (double)pow((double)a, (double)b)
#define gcd(a, b) __gcd(a, b)
#define PI 3.1415926535
#define pb push_back
#define ss second
#define ff first
#define umap unordered_map
#define ummap unordered_multimap
#define uset unordered_set
#define umset unordered_multiset
typedef unsigned long long ull;
using ld = long double;
using prlt = pair<lt, lt>;
using prld = pair<ld, ld>;
using vlt = vector<lt>;
using vld = vector<ld>;
using vstr = vector<string>;
using vch = vector<char>;
using vprlt = vector<pair<lt,lt>>;
using vvprlt = vector<vector<prlt>> ;
using vprld = vector<pair<ld,ld>>;
using vvlt = vector<vector<lt>>;
using vvch = vector<vector<char>>;
using vprch = vector<pair<char,lt>>;
using prchlt = pair<char,lt>;
#define Avengers_Assemble ios_base::sync_with_stdio(0)
void Shazam()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
}









#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#define ll lt
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
void _print(lt t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}









lt poww(lt x, lt y,lt p) 
{ 
    lt res = 1;    x = x % p; 
    while (y > 0) {  
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;               

        x = (x * x) % p; 
    } return res; 
} 
lt modInverse(lt n, lt p) {return poww(n, p - 2, p); }  
lt nCr(lt n, lt r, lt p) 
{ 
    if (r == 0) return 1;   if(r>n)return 0;
    lt fac[n + 1];  fac[0] = 1; 
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
lt lcm(lt a,lt b){return (a*b)/gcd(a,b);}
lt  modDivide(long long int a,long long int b,long long int m) 

{  a = a % m;   long long int inv = modInverse(b, m); 
    if (inv == -1)    return -1;
    else  return (inv * a) % m; 
}
vector<lt> Centroid(vector<vector<lt>> &g) {
        lt n = g.size(); vector<lt> centroid; vector<lt> sz(n);
        function<void (lt, lt)> dfs1 = [&](lt u, lt prev) {
                sz[u] = 1; bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs1(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs1(0, -1);  return centroid;
}
lt maxSubArraySum(vlt a, lt size) 
{ 
    if(size==0)return 0; lt max_so_far = a[0], curr_max = a[0]; 
   for (lt i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
}
lt phi_calculation(lt n) {  

    lt result = n;
    for (lt i = 2; i * i <= n; i++)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    if (n > 1) result -= result / n;
    return result;
}
vlt phi_1_to_n(lt n) {    

    vector<lt> phi(n + 1);  phi[0] = 0;  phi[1] = 1;
    for (lt i = 2; i <= n; i++) phi[i] = i;
    for (lt i = 2; i <= n; i++) 
        if (phi[i] == i) {
            for (lt j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    return phi;
}
bool isprime (lt n) {
	if (n < 2) return false;  if (n == 2 || n == 3) return true;
	if (n%2 == 0) return false;  if (n%3 == 0) return false;
	for (lt i=5; i<=sqrt(n); i+=6) {
		if (n%i == 0 || n%(i+2) == 0) return false;
	}
	return true;
}
vlt simple_sieve (lt n) {
    vlt primes; if (n < 2) return primes;
	if (n < 3) {
	primes.push_back(2); return primes; }
	vector<bool> mark(n+1, true);
	mark[2] = true; 	mark[3] = true;
	primes.push_back(2);  primes.push_back(3);
	for (lt i=5; i*i<n; i+=6) {
		if (mark[i]) {
			for (lt j=i*i; j<n; j+=i) mark[j] = false;
		}
		if (mark[i+2] && (i+2)<sqrt(n)) {
			for (lt j=(i+2)*(i+2); j<n; j+=(i+2)) mark[j] = false;
		}
	}
	for (lt i=5; i<n; i+=6) {
		if (mark[i]) primes.push_back(i);
		if (mark[i+2] && (i+2)<n) primes.push_back(i+2);
	} 
	return primes;
}
void dijkstra(vector<vprlt> &adj, vlt &vis, lt s, vvlt &dis) 
{
    priority_queue<prlt, vector<prlt>, greater<prlt>> q;
    q.push({0, s});   

    while (!q.empty()) {
        auto k=q.top();   q.pop();
        if(vis[k.ss]==1)continue;
        vis[k.ss]=1; dis[s][k.ss]=k.ff;
        for (auto x : adj[k.ss]) {
            q.push({k.ff+x.ff,x.ss});
        }
    }
}
void bfs2(vector<vector<lt>> &adj, vlt &vis, lt node, vlt &dis)
{
    std::queue<lt>q ;
    q.push(node);vis[node]=1;dis[node]=0;
    while(q.size()>0)
    {
        lt k=q.front();    q.pop(); 
        for(auto x: adj[k])
        {
            if(vis[x]==1)continue;
            q.push(x); vis[x]=1; dis[x]=dis[k]+1;
        }
    }
}


#define MAXN 500005
vlt spf,big,max_div;
void sieve() 
{ 
    spf.resize(MAXN);   spf[1] = 1;  

    for (lt i=2; i<MAXN; i++) spf[i] = i; 
    for (lt i=4; i<MAXN; i+=2)  spf[i] = 2; 
    for (lt i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) { 
            for (lt j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j)  spf[j] = i; 
        } 
    } 
}
void getFactorization(lt x, map<lt,lt>&m) 
{ 
    while (x != 1) { m[spf[x]]++; x = x / spf[x]; }                                       
} 
void sieve22()
{
    big.resize(MAXN);
    for(auto &x: big)x=1;   

    for (int i = 1; i < MAXN; ++i)
    if(big[i]==1)
    for (int j = i; j < MAXN; j += i)
    big[j] = i;
}
void eratosthenes() {  

    lt limit=MAXN-1;   max_div.assign(MAXN, 0);  
    max_div[0] = limit + 10;   max_div[1] = 1;
    for (int i = 2; i <= limit; ++i) {
        if (max_div[i]) continue;
        for (int j = i; j <= limit; j += i) {
            if (max_div[j]) continue;
            max_div[j] = j / i;
        }
    }
} 
void dfs1(vvlt &adj, lt u, lt p, vlt &dpl, vlt &dpr, vlt &l, vlt &r)
{
    lt al=0,ar=0;
    for(auto x:adj[u])
    {
        if(x==p)continue;
        dfs1(adj,x,u,dpl,dpr,l,r);
        al+=max(abs(l[u]-l[x])+dpl[x], abs(l[u]-r[x])+dpr[x]);
        ar+=max(abs(r[u]-l[x])+dpl[x], abs(r[u]-r[x])+dpr[x]);
    }
    dpl[u]=al; dpr[u]=ar;
}









#define endl "\n"
void solve()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lt n;
    cin>>n;
    lt a[n];
    take(a,n)
    set<prlt>s;
    vlt nxt(n), prev(n);
    fori(i,0,n)
    {
        nxt[i]=(i+1)%n;
        prev[i]=(i-1+n)%n;
        if(gcd(a[i], a[nxt[i]])==1)s.insert({i,nxt[i]});
    }
    lt k=-1;
    vlt v;
    while(!s.empty())
    {
        

        auto it=s.lower_bound({k,-1});
        if(it==s.end())it=s.begin();
        lt i=it->ff, j=it->ss;
        if(i==j)
        {
            if(a[i]==1)v.pb(i+1);
            break;
        }
        s.erase(it);
        auto ik=s.find({j,nxt[j]});
        if(ik!=s.end())s.erase(ik);
        v.pb(j+1);
        nxt[i]=nxt[j];
        if(gcd(a[i], a[nxt[i]])==1)s.insert({i,nxt[i]});
        k=nxt[i];
    }
    cout<<v.size()<<" ";
    show(v,v.size())
    

}








signed main()
{
    #ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
    Shazam();                  

    Avengers_Assemble ;
    clock_t start, end;         

    start = clock();              

    lt tx=1;                       

    cin>>tx;                    

    fori(i,0,tx)                 

    {
        

        solve();
    }                     
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "\nTime taken by program is : " << fixed << time_taken << setprecision(5) << " sec " << endl;
    time_taken*=1000.00;
    cerr << "Time taken by program is : " << fixed << time_taken << setprecision(5) << " milli-sec " << endl;
    return 0;
}






