#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 


#define R1 2
#define R2 2
#define C1 2
#define C2 2
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define F(a, b, i) for (ll i = a; i < b; i++)
#define FN(a, b, i) for (ll i = a; i >= b; i--)
#define read(n) ll n; cin>>n
#define readarray(a,n) ll a[n]; F(0,n,i){cin>>a[i];}
#define readvector(a,n) vector<ll> a; a.clear(); F(0,n,i){read(temp); a.push_back(temp);}
#define readmatrix(arr,n,m) ll a[n][m]; F(0,n,i) F(0,m,j) cin>>a[i][j];

const ll INF = 1000000000000000000LL;
 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 


bool sortbysec(vector<int> &a, vector<int> &b) { return a[1]<b[1]; }
 


struct cmp { bool operator()(const ll &a, const ll &b) { return a>b; } };
 


ll bexp(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
 


ll bexpM(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
 


const int P = 1000000;
int prime[P + 1];
void sieve() { prime[0] = 0; prime[1] = 0; for (int i = 2; i <= P; i++){ prime[i] = 1; } for (int i = 2; i * i <= P; i++){ if (prime[i] == 1){ for (int j = i * i; j <= P; j += i){ prime[j] = 0; } } } }
 


ll factorised[P + 1];
void primefactorisation() { factorised[0] = 0; factorised[1] = 0; for (int i = 2; i <= P; i++){ factorised[i] = -1; } for (int i = 2; i <= P; i++){ if (factorised[i] == -1){ for (int j = i; j <= P; j += i){ if(factorised[j] == -1){ factorised[j] = i; } } } } }
 


ll extendedgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } ll x1, y1; ll d = extendedgcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d; }
 


ll modInverse(ll a, ll m) { ll x, y; ll g = extendedgcd(a, m, x, y); ll res = (x % m + m) % m; return res; }
 


ll C(ll n, ll k) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res*=(n-i); res/=(i+1); } return res; }
 


ll CM(ll n, ll k, ll mod) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res = (res * (n-i))%mod; res = (res * modInverse(i+1,mod))%mod; } return res%mod; }
 


ll factorial(ll n) { ll res = 1; for (int i = 2; i <= n; i++) res = res*i; return res; }
 


ll factorialMOD(ll n, ll m) { ll res = 1; for (int i = 2; i <= n; i++) res = ((res % m) * (i % m)) % m; return res % m; }
 


bool checkperfectsquare(ll n){ if (ceil((double)sqrt(n)) == floor((double)sqrt(n))){ return true; }else{ return false; } }
 


vector<ll> divisorsofanum(ll n) { vector<ll> v; F(2, sqrt(n), i) { if (n % i == 0) { v.push_back(i); v.push_back(n / i); } } if (checkperfectsquare(n) == 1) { v.push_back(sqrt(n)); } if (n != 1) { v.pb(n); } return v; }
 


ll phi1(ll n) { ll result = n; for (int i = 2; i * i <= n; i++) { if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } } if (n > 1) result -= result / n; return result; }
 


ll *phi2=new ll[100001];
void eulerphi() { for(int i=1; i<=100000; i++) { phi2[i]=i; } for(int i=2; i<=100000; i++) { if(phi2[i]==i) { phi2[i]=i-1; for(int j=i*2; j<=100000; j+=i) { phi2[j]=(phi2[j]*(i-1))/i; } } } }
 


void matrixMultiplication(ll mat1[R1][C1], ll mat2[R2][C2]) { ll rslt[R1][C2]; F(0, R1, i) { F(0, C2, j) { rslt[i][j] = 0; F(0, R2, k) { rslt[i][j] = (rslt[i][j] + (mat1[i][k] % MOD * mat2[k][j] % MOD) % MOD) % MOD; } } } F(0, R1, i) { F(0, C2, j) { mat1[i][j] = rslt[i][j]; } } }
 


void matrixExponentiation(ll a[R1][C1], ll m[R2][C2], ll n) { if (n == 0 || n == 1) { return; } matrixExponentiation(a, m, n / 2); matrixMultiplication(a, a); if (n % 2 == 1) { matrixMultiplication(a, m); } }
 


ll calculateMex(unordered_set<ll> Set) { ll Mex = 0; while (Set.find (Mex) != Set.end()) Mex++; return (Mex); }
 


ll countSetBits(ll n) { if (n == 0) return 0; return (n & 1) + countSetBits(n >> 1); }
 


void precision(int a){ cout << setprecision(a) << fixed << endl; }
 
 


vector<ll> adj[100001];
bool visited[100001];
ll level[100001];
ll par[100001];

void dfs(ll node, vector<ll> &vec){
    visited[node]=true;
    vec.pb(node);
    for(auto x: adj[node]){
        if(!visited[x]){
          dfs(x, vec);
        }
    }
}
 
void bfs(ll node){
    queue<ll> q;
    q.push(node);
    

    level[node] = 0;
    visited[node]=true;
    while(!q.empty()){
        ll k = q.front();
        q.pop();
        for(auto x: adj[k]){
          if(!visited[x]){
            q.push(x);
            visited[x]=true;
            level[x]=1+level[k];
            par[x] = k;
          }
        }
    }
}
 


 
ll parent[1000010];
ll sizo[1000010];
 
void Make(ll node){
  parent[node]=node;
  sizo[node]=1;
}
 
ll Find(ll node){
  if(parent[node]==node) return node;
  

  return parent[node] = Find(parent[node]);
}
 
void Union(ll u,ll v){
  u = Find(u);
  v = Find(v);
  if(u!=v){
    

    if(sizo[u]<sizo[v])
      swap(u,v);
    parent[v]=u;
    sizo[u]+=sizo[v];
  }
}
 


 
ll _gcd(ll a, ll b){
  if(b==0) return a;
  return _gcd(b,a%b);
}
 





void buildTree(ll *arr, ll *tree, ll start, ll end, ll treeNode){
    

    if(start==end){
        tree[treeNode]=arr[end];
        return;
    }
    ll mid = (start+end)>>1;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = max(tree[2*treeNode],tree[2*treeNode+1]);
}
 
void updateTree(ll *arr, ll *tree, ll start, ll end, ll treeNode, ll idx, ll value){
    

    if(start==end){
        arr[idx]=value;
        tree[treeNode]=arr[end];
        return;
    }
    ll mid = (start+end)>>1;
    if(idx<=mid){
        updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    }else{
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }
    tree[treeNode] = max(tree[2*treeNode],tree[2*treeNode+1]);
}
 
ll queryTree(ll *tree, ll start, ll end, ll treeNode, ll left, ll right){
    

    

    if(left<=start && right>=end){
        

        return tree[treeNode];
    }else if(right<start || left>end){
        

        return INT_MIN;
    }else{
        

        ll mid = (start+end)>>1;
        return max(queryTree(tree,start,mid,2*treeNode,left,right),queryTree(tree,mid+1,end,2*treeNode+1,left,right));
    }
}

void updateLazyTree(ll* tree, ll* lazy, ll* arr, ll start, ll end, ll treeNode, ll left, ll right, ll increment){
    

    

    if(start>end){
      return;
    }
    if(lazy[treeNode]!=0){
      tree[treeNode]+=(end-start+1)*lazy[treeNode];
      if(start!=end){
        lazy[2*treeNode]+=lazy[treeNode];
        lazy[2*treeNode+1]+=lazy[treeNode];
      }
      lazy[treeNode]=0;
    }
    if(left<=start && right>=end){
      

      tree[treeNode]+=(end-start+1)*increment;
      if(start!=end){
        lazy[2*treeNode]+=increment;
        lazy[2*treeNode+1]+=increment;
      }
      return;
    }else if(right<start || left>end){
      

      return;
    }else{
      

      ll mid = (start+end)>>1;
      updateLazyTree(tree,lazy,arr,start,mid,2*treeNode,left,right,increment);
      updateLazyTree(tree,lazy,arr,mid+1,end,2*treeNode+1,left,right,increment);
      tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
    }
}

ll queryLazyTree(ll* tree, ll* lazy, ll* arr, ll start, ll end, ll treeNode, ll left, ll right){
    

    

    if(start>end){
      return 0;
    }
    if(lazy[treeNode]!=0){
      tree[treeNode]+=(end-start+1)*lazy[treeNode];
      if(start!=end){
        lazy[2*treeNode]+=lazy[treeNode];
        lazy[2*treeNode+1]+=lazy[treeNode];
      }
      lazy[treeNode]=0;
    }
    if(left<=start && right>=end){
      

      return tree[treeNode];
    }else if(right<start || left>end){
      

      return 0;
    }else{
      

      ll mid = (start+end)>>1;
      return queryLazyTree(tree,lazy,arr,start,mid,2*treeNode,left,right) + queryLazyTree(tree,lazy,arr,mid+1,end,2*treeNode+1,left,right);
    }
}
 


 


 
struct trieNode{
  trieNode* left;
  trieNode* right;
};
 
void insert(ll n, trieNode *head) { trieNode *curr = head; for (int i = 31; i >= 0; i--) { ll b = (n >> i) & 1; if (b == 0) { if (!curr->left) { curr->left = new trieNode(); } curr = curr->left; } else { if (!curr->right) { curr->right = new trieNode(); } curr = curr->right; } } }
 
ll findMaxXorPair(trieNode* head, ll n){ ll max_xor = INT_MIN; for(int i=0;i<n;i++){ ll value = n; trieNode* curr = head; ll curr_xor = 0; for(int j=31;j>=0;j--){ ll b = (n>>j)&1; if(b==0){ if(curr->right){ curr_xor += bexp(2,j); curr = curr->right; }else{ curr = curr->left; } }else{ if(curr->left){ curr_xor += bexp(2,j); curr = curr->left; }else{ curr = curr->right; } } } max_xor = max(max_xor, curr_xor); } return max_xor; }
 


 


 
ll up[200010][64];
ll lvl[200010];
 
void binary_lifting(ll src, ll par){ up[src][0] = par; F(1,32,i){ if(up[src][i-1]==-1) up[src][i]=-1; else up[src][i] = up[up[src][i-1]][i-1]; } for(auto child: adj[src]){ if(child!=par){ binary_lifting(child, src); } } }
 
ll lift_node(ll node, ll jumpsrequired){ FN(31,0,i){ if(jumpsrequired==0 || node==-1){ break; } if(jumpsrequired>=(1LL<<i)){ jumpsrequired -= (1LL<<i); node = up[node][i]; } } return node; }
 
ll lca(int u, int v) { if (lvl[u] < lvl[v]) { swap(u, v); } u = lift_node(u, lvl[u] - lvl[v]); if (u == v) return u; FN(31, 0, i) { if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; } } return lift_node(u, 1); }
 



 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t=1;
  cin>>t;
  while(t--){
    read(n);
    vector<int> miners, mines;
    F(0,2*n,i){
      int x,y; cin>>x>>y;
      if(x==0){
        miners.pb(abs(y));
      }else{
        mines.pb(abs(x));
      }
    }
    sort(all(miners));
    sort(all(mines));
    double ans = 0;
    F(0,n,i){
      ans += sqrt(mines[i]*1LL*mines[i]+miners[i]*1LL*miners[i]);
    }
    precision(9);
    cout << ans << endl;
  }
}