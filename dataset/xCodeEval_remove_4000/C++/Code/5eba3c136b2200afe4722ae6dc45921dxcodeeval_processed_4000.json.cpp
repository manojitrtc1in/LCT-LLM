































































 

 




using namespace std;
 





 
const int MAX_N = 2e5 + 5;
const int id0 = 2e5 + 7;
const ll MOD = 10e9 + 7;
const ll INF = 1e9;




























const double pi=acos(-1.0);

typedef pair<long,long> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<vector<ll>> VII;
typedef vector<pair<int,int>>VPII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;


typedef map<int,int> MPII;
typedef set<long long> seti;
typedef multiset<int> MSETI;
typedef priority_queue<pair<int,int>> PQPII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


 
 

 













 










 

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
 

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
 
 
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
 
 
 

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
bool isprime(ll n)
{
    ll x=sqrt(n);
    for(int i=2;i<=x;i++)
    {if(n%i==0)return true;}
    return false;
}
 
 
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.second<y.second;
}
 
 
void id2() 
{
    

    int n,m;cin>>n>>m;
    int a[n][m],prefix[n][m];
    f1(i,0,n)
    {
        f1(j,0,m)
        {
            cin>>a[i][j];
        }
    }
 
    

    f1(i,0,n)
    {
        f1(j,0,m)
        {
            prefix[i][j]=a[i][j];
            if(i-1>=0)prefix[i][j]+=prefix[i-1][j];
            if(j-1>=0)prefix[i][j]+=prefix[i][j-1];
 
            if(i-1>=0 and j-1>=0)
            {
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int i1,i2,j1,j2;cin>>i1>>i2>>j1>>j2;
    }
}
 
 


void id1()
{
    int n;cin>>n;
    int a[n];
    f1(i,0,n)cin>>a[i];
 
    int prefixSum[n+1];
    int q;cin>>q;
    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        prefixSum[l]+=x;
        prefixSum[r+1]-=x;
    }
    int s=0;
    f1(i,0,n)
    {
        s+=prefixSum[i];
        a[i]+=s;
    }
    f1(i,0,n)cout<<a[i]<<" ";
}


int findMin(vector<bool>&vis,VI distance)
{
    int start=-1;
    int n=vis.size();
    f1(i,0,n)
    {
        if(start==-1 or distance[start]>distance[i])
            start=i;
    }
    return start;
}

int dist(VPII vis,int n)
{
    vector<bool>ar(n,false);
    VI temp(n,INF);
    ar[1]=0;

    int val=findMin(ar,temp);
    if(val==-1)return 0;
    ar[val]=true;
    cf(i,0,n)
    {
        return temp[n];
    }
}


bool binarySearch(ll mid,ll k,ll x)
{
    ll tot=0;
    mid-=1;
    if(mid<=k)
        tot=(mid*(mid+1))/2;
    else
    {
        tot=(k*(k+1))/2;
        mid=2*k-1-mid;
        tot+=((k*(k-1))/2-(mid*(mid+1))/2);
    }
    return tot<x;
}

int power(int b, int e)
{
    int ret = 1;
    for(int i=0; i<e; ++i) ret *= b;
    return ret;
}


ll help( long long x )
{
    ll sum = 0 ;
    while ( x )
    { 
        sum += x % 10 ;
        x /= 10 ;
    }
    return sum ;
}
 



void test()
{
    int a[8][8];
    f1(i,0,8)
    {
        f1(j,0,8)
        {a[i][j]=0;}
    }
    int row,cols;cin>>row>>cols;
    a[row][cols]=1;
    

    if(cols>=2 and cols<=8)
    {
        
        a[row+1][cols+2]=2;
        a[row+1][cols-2]=2;
        a[row-1][cols+2]=2;
        a[row-1][cols-2]=2;
    }
    

    else if(cols<=2){a[row+1][cols+2]=2;a[row-1][cols+2]=2;}
    f1(i,0,8)
    {
        f1(j,0,8)
        {cout<<a[i][j]<<" ";}cout<<nl;
    }
}


bool c2(pair<string,pair<int,int>> &x,pair<string,pair<int,int>>&y)
{
    if(x.second.first!=y.second.first)
     return (x.second.first < y.second.first);
     else
     return (x.second.second < y.second.second);

}
bool c1(pair<string,pair<int,int>> &x,pair<string,pair<int,int>>&y)
{
    if(x.first!=y.first)
     return (x.first < y.first);
     else
      return (x.second.second < y.second.second);

}

void solve()
{
    int n;cin>>n;
    vi dp(n);
    f1(i,0,n)cin>>dp[i];

    int maximum=0;
    


    f1(i,0,n)
    {
        f1(j,i+1,n)
        {
            

            if(dp[i]>=dp[j])
                

                


                

                

                

                

                

        

        

        

        

        

        

        

        

        

        


                maximum++;
    }
}
cout<<maximum<<nl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

freopen("input.txt","r",stdin); 

freopen("output.txt","w",stdout);  


    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        

       solve();
    }
    return 0;
}