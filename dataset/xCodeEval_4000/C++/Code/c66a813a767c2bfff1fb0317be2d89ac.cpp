
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define mii map<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define int long long
#define float long double
#define ii pair<int,int>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define rloop(i,a,b) for(int i=(a);i>(b);i--)
#define tr(it,c) for(decltype((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
#define mod11 998244353ll
#define mod2 1000000007ll
#define mem(a,b) memset(a,b,sizeof(a))
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PI 3.1415926535
#define ll unsigned long long
#define pq priority_queue
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 





 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
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


 

int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} 

int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 


int power(long long x, unsigned int y, int p)
{

	
    int res = 1;     

 
    x = x % p; 

                

  
    if (x == 0) return 0; 

 
    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;
 
        

        y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}
int fac(int n)
{
    

    return (n==1 || n==0) ? 1: n * fac(n - 1);
}
void decToBinary(int n)
{
    

    int binaryNum[64];

    

    int i = 0;
    while (n > 0) {

        

        if(n%2==0) binaryNum[i] = 0;
        else binaryNum[i]=1;
        n = n / 2;
        i++;
    }
      for (int j = 5; j >= 0; j--)
        cout << binaryNum[j];
}
bool isNonHypotenuse(int n)
{
    

    

    

    

    while (n % 2 == 0) {
        n = n / 2;
    }
  
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2) {
  
        

        

        

  
        if (n % i == 0) {
            if ((i - 1) % 4 == 0)
                return false;
  
            

            

            

            while (n % i == 0) {
                n = n / i;
            }
        }
    }
  
    

    

    if (n > 2 && (n - 1) % 4 == 0)
        return false;
  
    else
        return true;
}
int countDigit(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}
long long binpow(long long a, long long b, long long m) {
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


void bfsOfGraph(int V, vector<int> adj[],vi v,vi &dis,vi &par){
	    vector<int> vis(V+1, 0); 
	    queue<int> q; 
	    loop(i,0,v.size())
	    {
		
	    q.push(v[i]); 
	    vis[v[i]] = 1; 
	    dis[v[i]]=0;
		}
		int d=0;
	    while(!q.empty()) {
	    	d++; 
	        int z=q.size();
	        loop(i,0,z)
	        {
			
	        int node = q.front();
	        q.pop(); 
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                
	                vis[it] = 1;
	                if(d<dis[it])
	            	{
	            		par[it]=node;q.push(it);
					}
					dis[it]=min(dis[it],d);
	            }
	            else
	            {
	            	if(d<dis[it])
	            	{
	            		par[it]=node;
					}
	            	dis[it]=min(dis[it],d); 
				}
	        }
			}
	    
		}
	    
	    
	}

	

const int B = 350;
struct Query {
	int l, r;
	int idx;
	bool operator <(Query &other) {
		if(l/B < other.l/B) return true;
		else if(l/B == other.l/B)
		{
		return (l/B%2?r>other.r:r<other.r);
		}
		else return false;
	}
};
double Convert(double degree)
{
    double pi = 2*acos(0.0);
    return (degree * (pi / 180));
}

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
bool isPrime(int n)
{
    

    if (n <= 1)
        return true;
    if (n <= 3)
        return true;
  
    

    

    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}



bool isPowerOfTwo (int x)
{
    
    return x && (!(x&(x-1)));
}
unsigned int nextPowerOf2(unsigned int n)
{
    unsigned count = 0;
     
    

    

    if (n && !(n & (n - 1)))
        return n;
     
    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }
     
    return 1 << count;
}
class Solution {
public:
	int topoSortBFS(int V, vector<vi> adj,string s){
	    vector<int> bfs; int z=0;
	    vector<int> vis(V+1, 0),vis2(V+1,0); 
	    for(int i=1;i<=V;i++)
	    {
	    	for(auto it:adj[i])
	    	{
	    		vis2[it]++;
			}
		}
	    for(int i=1;i<=V;i++)
	    {
		if(vis[i]==0&&vis2[i]==0)
		{
		
	    queue<int> q; 
	    q.push(i); 
	    vis[i] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	        	vis2[it]--;
	            if(!vis2[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }}
		}
		vi v1(V+1,0),v2(V+1,0);
		
		
		loop(i,0,V)
		{
			if(s[bfs[i]-1]=='W')v1[bfs[i]]++;
	        else v2[bfs[i]]++;
			for(auto it:adj[bfs[i]])
			{
				v1[it]+=v1[bfs[i]];
				v2[it]+=v2[bfs[i]];
			}
		}
	    loop(i,1,V+1)
	    {
	    	if(v1[i]==v2[i])
	    	{
	    		z++;
			}
		}
		return z;
	    
	}
public:
	vector<int> topoSortBFS(int V, vector<vi> adj){
	    vector<int> bfs; 
	    vector<int> vis(V+1, 0),vis2(V+1,0); 
	    for(int i=1;i<=V;i++)
	    {
	    	
	    	for(auto it:adj[i])
	    	{
	    		vis2[it]++;
			}
			
		}
	    for(int i=1;i<=V;i++)
	    {
		if(vis[i]==0&&vis2[i]==0)
		{
		
	    queue<int> q; 
	    q.push(i); 
	    vis[i] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	        	vis2[it]--;
	            if(!vis2[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }}
		}
	    
	    return bfs; 
	}
};
int reverse(int num)
{
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    return rev;
}
 




bool isPalindrome(int num)
{
 
    

    

    

    if (num == reverse(num))
        return true;
 
    return false;
}
class Node{
     
public:
    int val;
    int count;
    Node* left;
    Node* right;
     
    

    Node(int num1, int num2)
    {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
};
 




int addNode(Node*& root, int value,
                         int countSmaller)
{
     
    

    if (root == NULL)
    {
        root = new Node(value, 0);
        return countSmaller;
    }
    if (root->val < value)
    {
        return root->count +
       addNode(root->right,
               value,
               countSmaller + 1);
    }
    else
    {
        root->count++;
        return addNode(root->left, value,
                       countSmaller);
    }
}
class solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[],int &z,string s) {
        

        

        vis[node] = 1; 
        int c=0,d=0;
        if(s[node-1]=='W')c++;
        else d++;
        for(auto it : adj[node]) {
            if(!vis[it]) {
            	if(s[it-1]=='W')c++;
                else d++;
                dfs(it, vis, adj, z,s); 
                
            }
        }
        cout<<node<<" "<<c<<" "<<d<<endl;
        if(c==d)
        {
        	
        	z++;
		}
        
        
    }
public:
	int dfsOfGraph(int V, vector<int> adj[],string s){
	    

	    vi b(V+1,0),w(V+1,0);
	    vector<int> vis(V+1, 0); int z=0;
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj,z,s ); 
      }
	    return z; 
	}
};
bool checkcycledfs(int x,vi v1,int node, int parent,vector<int> &vis, vector<vi> adj,vector<int> &vis2) {
        

        
        vis[node] = 1; vis2[node]=1;
        

        

        if(adj[node].size()>0&&v1[node]<=x)
        {
		
        for(auto it : adj[node]) {
            if(vis[it]==0&&v1[it]<=x) {
                if(checkcycledfs(x,v1,it,node, vis, adj,vis2))
				{
					return true;
				 } 
            }
            else 
            {
               if(vis2[it]==1)
               {
               	return true;
			   }
			}
        }
        
        
		}
		vis2[node]=0;
        return false;
    }

bool cycle(int x,vi v1,int V, vector<vi> adj){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
	    vector<int> v(V+1,0);
      for(int i = 1;i<=V;i++) {
        if(vis[i]==0&&v1[i]<=x)
		{
			vector<int> vis2(V+1, 0);
			if(checkcycledfs(x,v1,i,-1,vis,adj,vis2))
			{
			
				return 1;
			}
		 } 
      }
	    return 0; 
	}
	
void solve()
{
int n,m;ll k;cin>>n>>m>>k;
vi v1;v1.pb(0);vector<vi> v(n+1);
loop(i,0,n)
{
	int x;cin>>x;v1.pb(x);
}



loop(i,0,m)
{
	int a,b;cin>>a>>b;
	v[a].pb(b);
}
int l=0,r=10000000000;
if(n==1)
{
	
    if(k==1)cout<<v1[1];
    else cout<<-1;
	return;
}



while(r-l>1)
{
	int d=0;
	int mid=(l+r)/2;
	vector<vi> v2(n+1);
	loop(i,1,n+1)
	{
		if(v1[i]<=mid)
		{
			for(auto it:v[i])
			{
				if(v1[it]<=mid)
				{
					v2[i].pb(it);
				}
			}
		}
	}


        Solution obj;

	    vector<int>ans=obj.topoSortBFS(n,v2);
	    if(ans.size()!=n)
	    {
	    	d++;
		}
		else
		{
		
        vi v3(n+1,0);
        reverse(ans.begin(),ans.end());
        loop(i,0,n)
        {
		if(v1[ans[i]]<=mid)
         {
		 v3[ans[0]]=1;break;}
		}
        loop(j,0,ans.size())
        {
        	for(auto it:v2[ans[j]])
        	{
        		v3[ans[j]]=max(v3[ans[j]],v3[it]+1);
			}
		}
		int mx=0;
		loop(i,0,n+1)
		{
			mx=max(mx,v3[i]);
		}
		if(mx>=k-1)
		{
			d++;
		}
		}
 
	
	
	if(d==0)
	{
		l=mid;
	}
	else
	{
		r=mid;
	}
	

}
if(r==10000000000)
{
	cout<<-1;return;
}
cout<<r;
}
   





signed main()
{


	SYNC;






	int t1=1;
	

   

	loop(i,1,t1+1)
	{
		
		

		solve();
	   
		cout<<"\n";
	}
	return 0;
}


