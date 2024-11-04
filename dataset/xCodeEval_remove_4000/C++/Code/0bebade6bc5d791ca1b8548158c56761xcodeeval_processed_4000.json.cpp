

























using namespace std;





 





 

 
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
void id0(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id0(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

int id6(int a, int b) {int arr[3]; id0(a, b, arr); return arr[0];} 

int id3(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case 
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, id3(b, m), m) + m) % m;}  

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
void id5(int n)
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
bool id4(int n)
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


  void id1(int V, vector<int> adj[],vi v,vi &dis,vi &par){
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

bool id7(const pair<int,int> &a,const pair<int,int> &b)
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
int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int y = sum / 2 + 1;
    

    

    

    bool dp[y], dd[y];
 
    

    for (int i = 0; i < y; i++) {
        dp[i] = dd[i] = false;
    }
 
    

    dd[0] = true;
    for (int i = 0; i < n; i++) {
        

        

        for (int j = 0; j + arr[i] < y; j++) {
            if (dp[j])
                dd[j + arr[i]] = true;
        }
        

        for (int j = 0; j < y; j++) {
            if (dd[j])
                dp[j] = true;
            dd[j] = false; 

        }
    }
    

    

 
    for (int i = y - 1; i >= 0; i--) {
        if (dp[i])
            return (sum - 2 * i);
        

        

        

    }
}
int findMin(int arr[], int n)
{
    

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    

    bool dp[n + 1][sum + 1];
 
    

    

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    

    

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            

            dp[i][j] = dp[i - 1][j];
 
            

            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
 
    

    int diff = INT_MAX;
 
    

    

    for (int j = sum / 2; j >= 0; j--) {
        

        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
 


bool id2 (int x)
{
    
    return x && (!(x&(x-1)));
}
unsigned int id8(unsigned int n)
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

void solve()
{
int n,m;cin>>n>>m;
if(m<n)
{
	cout<<0;return;
}
if(n==0)
{
	cout<<m+1;return;
}
if(id2(m+1))
{
	cout<<m+1;return;
}
int n1=n,m1=m;
int binaryNum[64],binaryNum1[64];
    

    int i = 0;
    while (m1 > 0) {

        

        if(m1%2==0) binaryNum[i] = 0;
        else binaryNum[i]=1;
        m1 = m1 / 2;
        i++;
    }
    vi v1(i,0),v2(i,0);
      for (int j = i-1; j >= 0; j--)
        {
		v1[i-1-j]=binaryNum[j];
		}
        int s=i;
    i=0;
     while (n1 > 0) {

        

        if(n1%2==0) binaryNum1[i] = 0;
        else binaryNum1[i]=1;
        n1 = n1 / 2;
        i++;
    }
      for (int j = i-1; j >= 0; j--)
        {
		 v2[s-1-j]=binaryNum1[j];
		  }
		  
		  
		  
		  
	
	vi v;
	int p=pow(2,s-1);i=0;m++;
	while(i<s)
	{
		if(v2[i]==0)
		{
			int z=m/p;
			if(m%p==0)
			{
				v.pb(1);
			
			loop(j,i+1,s)
		   	{
		    	v.pb(0);
			}
	        i=s+1;break;
			}
			else
			{
				if(z%2==0)
				{
					v.pb(0);
				}
				else
				{
					v.pb(1);
				}
			}
		}
		else
		{
			int z=m/p;
		    if(m%p==0||z%2==0)
		    {
		    	loop(j,i,s)
		    	{
		    		v.pb(0);
				}
				i=s+1;break;
			}
			else
			{
				v.pb(0);
			}
		}
		i++;p=p/2;
	}

	reverse(v.begin(),v.end());
	int ans=0;
	loop(i,0,s)
	{
		if(v[i]==1)
		{
			ans+=pow(2,i);
		}
	}
	cout<<ans;
}

signed main()
{


	SYNC;






	int t1=1;
	cin>>t1;
	loop(i,1,t1+1)
	{
		
		

		
		solve();
		cout<<"\n";
	}
	return 0;
}

