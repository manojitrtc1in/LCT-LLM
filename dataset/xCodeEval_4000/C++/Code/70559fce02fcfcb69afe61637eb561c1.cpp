#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define ld long double
#define f first
#define s second
using namespace std;

double eps = 1e-6;

ll MOD = 1e9 + 7;
ll bigMod(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll res = bigMod(x, y / 2LL);
    res *= res;
    res %= MOD;
    if (y % 2)
    {
        res *= x;
        res %= MOD;
    }
    return res;
}

ll fac[1000005];
ll choose(ll x, ll y)
{
    if (x == y)
        return 1;
    if (y > x)
        return 0;
    if (y == 0)
        return 1;
    ll up = fac[x];
    ll down = fac[y] * fac[x - y];
    down %= MOD;
    ll ret = up * bigMod(down, MOD - 2);
    ret %= MOD;
    return ret;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        

        

        if (arr[mid] == x)
            return mid;

        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        

        

        return binarySearch(arr, mid + 1, r, x);
    }

    

    

    return -1;
}

int binarySearch2(pair<int , int> arr[], int l, int r, pair<int , int> x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        

        

        if (arr[mid].f == x.f && arr[mid].s == x.s)
            return mid;

        

        

        if (arr[mid].f > x.f || (arr[mid].f == x.f && arr[mid].s > x.s) )
            return binarySearch2(arr, l, mid - 1, x);

        

        

        return binarySearch2(arr, mid + 1, r, x);
    }

    

    

    return -1;
}

ll gcd(ll a, ll b) 

{
    return b == 0 ? a : gcd(b, a % b);
}

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.f - a.s < b.f - b.s);
}
bool sortbysec2(const pair<int, int> &a,
                const pair<int, int> &b)
{
    if ((a.f - a.s) == (b.f - b.s))
        return a.f < b.f;
    return (a.f - a.s < b.f - b.s);
}



void printDivisors(ll n)
{
    

    ll minn = 1e10;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            

            if (n / i == i)
                printf("%d ", i);

            else
                

                printf("%d %lld ", i, n / i);
        }
    }
}






const long long MAX_SIZE = 1000001;











vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);



ll manipulated_seive(ll N)
{
    

    isprime[0] = isprime[1] = false;

    

    for (long long int i = 2; i < N; i++)
    {
        

        

        if (isprime[i])
        {
            

            prime.push_back(i);
            if (N % i == 0)
                return i;

            

            

            SPF[i] = i;
        }

        

        

        

        

        

        

        for (long long int j = 0;
             j < (int)prime.size() &&
             i * prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i * prime[j]] = false;

            

            SPF[i * prime[j]] = prime[j];
        }
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}


vector<int> getdividors(ll n)
{
    vector<int> dividors;
    ll i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            dividors.push_back(i);
            dividors.push_back(n / i);
        }
    }
    if (i * i == n)
        dividors.push_back(i);
    return dividors;
}



vector<int> factorize(ll n)
{
    vector<int> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
            factors.push_back(i), n /= i;
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
vector<vector<int> > v(200005);
vector<int> d;
int N = 2000005;
vector<int> mem(2000005);
vector<bool> visited(2000005);
vector<bool> recStack(2000005);

set<int> s;
queue<int> q;

void dfs(int node)
{
    visited[node] = 1;
    for (int i = 0; i < (int)v[node].size(); i++)
    {
        if (!visited[v[node][i]])
        { 

            dfs(v[node][i]);
        }
    }
}

bool isCyclicUtil(int node)
{

    if (visited[node] == false)
    {
        

        visited[node] = true;
        recStack[node] = true;

        

        for (int i = 0; i < (int)v[node].size(); i++)
        {
            

            

            

            

            

            

            

            if (!visited[v[node][i]] && isCyclicUtil(v[node][i]))
                return true;
            else if (recStack[v[node][i]])
                return true;
        }
    }
    recStack[node] = false; 

    return false;
}




bool isCyclic()
{
    

    

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    

    

    for (int i = 0; i < N; i++)
    {
        if (isCyclicUtil(i))
            return true;
    }
    return false;
}
void connected_components()

{
    int counter = 1, node;
    set<int>::iterator t = s.begin();
    while (t != s.end())
    {
        node = *t;
        if (visited[node] != 1)
        {
            counter++;
            dfs(node);
        }
        t++;
    }
    cout << " connected components=" << counter << endl;
}

vector<pair<int, int> > bfs(int node, int D)
{
    int fir_node = node;
    vector<pair<int, int> > ans;
    visited[node] = 1;
    int i = 0, x;
    q.push(node);

    while (!q.empty())
    {
        x = q.front();
        q.pop();

        visited[x] = 1;
        if (x != fir_node)
            for (int i = 0; i < (int)v[x].size(); i++)
            {
                if (!visited[v[x][i]])
                {
                    

                    ans.push_back(make_pair(x, v[x][i]));
                    q.push(v[x][i]);
                    visited[v[x][i]] = 1;
                }
            }
        else
        {
            for (int i = 0; i < D; i++)
            {
                if (!visited[v[x][i]])
                {
                    

                    ans.push_back(make_pair(x, v[x][i]));
                    q.push(v[x][i]);
                    visited[v[x][i]] = 1;
                }
            }
        }
    }
    return ans;
}

int primeArr[1000];
void generatePrime()
{
    for (int i = 0; i < 1e3; i++)
    {
        primeArr[i] = 2;
    }
    memset(primeArr, 2, sizeof(primeArr));
    int i, n = 1e3 + 1;
    bool isPrime = true;
    

    if (n == 0 || n == 1)
    {
        isPrime = false;
    }
    else
    {
        for (i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";
}



class DSU {
    vector < pair<int , int> > old;
    public:
        vector<int> parent, _size;

        DSU(int n);
        void join_sets(int a, int b);
        int get_root(int a);
        int solve();
};

DSU::DSU(int n)
{       old.clear();
        parent.resize(n + 1);
        _size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
                parent[i] = i;
}

void DSU::join_sets(int a, int b)
{
        int aa = a, bb = b;
        a = get_root(a);
        b = get_root(b);

        if (_size[a] > _size[b])
                swap(a, b);

        if (a != b) {
                parent[a] = b;
                _size[b] += _size[a];
        }else{ 

            old.push_back({aa,bb});
        }
}

int DSU::get_root(int a)
{
        if (a != parent[a])
                parent[a] = get_root(parent[a]);
        return parent[a];
}

int DSU::solve()
{
    for(int i=1;i<parent.size();i++){
        get_root(i);
    }
    vector< pair<int ,int > > ans;
    for(int i = 1;i<parent.size();i++){
        ans.push_back({parent[i],i});
    }
    
    cout<<old.size()<<endl;
    sort(ans.begin(),ans.end());
    auto prev = ans[0];
    for(auto i : ans){
        if (i.f != prev.f){
            auto x = old.back();
            old.pop_back();
            cout<<x.f <<" "<< x.s<<" "<<i.f<<" "<<prev.f<<endl; 
        }
        prev = i;
    }
}

void cincout()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
}
































































































































ll maxxM(ll n){
    if (n <= 1){
        return 0;
    }else{
        ll nn = n%2 == 1 ? n-1 : n;
        return nn/2 * nn/2 + ((nn/2)*((nn/2)-1)/2) * 2 + ( (n%2 == 1) ? (n-1) : 0 );
    }

}
int main()
{
    cincout();
    vector<int> maxx;
    ll x = 0;
    int i = 0;
    int nn = 63243;
    

    

    

    

    

    

    

        

    ll t = 1;
    cin >> t;
    int jj = 1;
    while (t--)
    {
        ll n,m,k; cin>>n>>m>>k;
        

        

        

        

        ll d = 1e9; bool f = false;
        

        if (m == 0){
            d = 0;
        }
        else if(m<n-1){
                        

            d = 0;
            f = true;
        }else if (m < maxxM(n)){
            

            d = 2;
        }else if (m == maxxM(n)){
            

            d = 1;
        }else {
                        

            f = true;
        }
        if (d>=k-1 || f || (m == 0 && n != 1)){
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
        }

    }

    return 0;
}








































  




































  




































  









  










































  












  























  






















  






















  


















  










  







  







  










  







  























































  































  


















  














  









  






















    






