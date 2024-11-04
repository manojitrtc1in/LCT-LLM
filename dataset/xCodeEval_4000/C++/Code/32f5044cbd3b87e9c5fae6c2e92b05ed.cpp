



 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9+7;
const int mx  = 1e5+5;
typedef long long ll; 

#define SEIVE
vector<int>prime;
int isPrime[mx];
void seive(){ 
  for(int i=2;i<mx;++i)
  {
    if(isPrime[i]==0)
    {
      prime.push_back(i);
      for(int j=i*i;j<mx;j+=i)
      {
        isPrime[j]=1;
      }
    }
    isPrime[i]^=1;
  }
}

#define inf       9e18
#define zero      -9e18
#define PI        acos(-1.0)  

#define max3(a,b,c)   max(a,max(b,c))
#define min3(a,b,c)   min(a,min(b,c))
#define GCD(a,b)    __gcd(a,b)
#define LCM(a,b)    (a*(b/__gcd(a,b) ))
#define MP        make_pair
#define pb        push_back
#define rev(v)      reverse(v.begin(),v.end());
#define srt(v)      sort(v.begin(),v.end());
#define grtsrt(v)     sort(v.begin(),v.end(),greater<ll>());
#define full(v)     (v).begin(),(v).end()
#define hellyeah    {return;}
#define vmax(V)     *max_element(V.begin(),V.end());
#define vmin(V)     *min_element(V.begin(),V.end());
#define Mem(X,D_type) memset(X, D_type, sizeof(X))
#define groot(A)    {cout<<A<<endl;return;}
#define vins(V)     srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           cout<<"Avengers Assemble"<<endl;
#define lol       cout<<endl;
#define meem(X)     cout<<(X?"Yes":"No")<<endl;
#define joker(V)    for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp)    for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;
#define lp(i,a)     for(int i=0; i<a;i++)
#define LP(it,S)      for(auto it:S)
#define lp1(i,a,b)    for(int i=(a);i<=(b);++i)
#define rlp(i,b,a)    for(int i=(b);i>=(a);--i) 
#define Mat(mat,N,M)  lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
#define debug(a)    cout<<"*"<<a<<"$"<<endl;
#define debug2(a,b)     cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define debug3(a,b,c)     cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define fr(i,a,b)       for(int i = (a); i <= (b); i++)
#define pb              push_back
#define f               first
#define se              second
#define pii             pair < int , int >
#define mp              make_pair
#define LOGMAX          17
#define FIND(N,pos)     ((N) & (1 << (pos)))
#define sf(h)           scanf("%d",&h)
#define sff(h,b)        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)     for(int z = 1;z <= test;z++)
#define PRINT           printf("Case %d:\n",z)
#define en              "\n"
#define lwb             lower_bound
#define upb             upper_bound
#define IOS             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      for(int i = (l);i <= (r);i++)
#define all(x)          (x).begin(), (x).end()
#define SZ(x) x.size()
typedef long long ll;
typedef long double ld;
int mod(int M){return (M % MOD + MOD)%MOD;}
int ceil(int A,int B){if(A%B==0)return A/B;else return (A/B)+1ll;}
int middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool as_second(const pair<int,int> &a, const pair<int,int> &b) {return (a.second < b.second); }
bool ds_first(const pair<int,int> &a, const pair<int,int> &b){ return (a.first > b.first);}
bool ds_second(const pair<int,int> &a, const pair<int,int> &b) {return a.second>b.second;}
 
int ncr(int n,int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
typedef deque<int> Dq;
typedef unordered_set<int> St;
typedef unordered_map<int,int> M;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<pair<int,int>> VP;
typedef priority_queue<int,vector<int>,greater<int>> Pq;
string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;

int a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;





void Incurcious()
{ 
  cin>>n>>m;
  V v(n);
  sum=0;
  lp(i,n)cin>>v[i],sum+=v[i];
  if(sum==m)groot("NO")
  srt(v)
  cout<<"YES\n";
  j=n-1;
  sum=0;
  lp(i,j+1){
  	if(sum+v[i]==m){
  		cout<<v[j--]<<" ";
  	}
  	sum+=v[i];
  	cout<<v[i]<<" ";
  }






  lp(i,1000)
  {
    

  }
  lol
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
        #endif
  
  #ifdef SEIVE
    seive();
  #endif
        test=1;
  cin>>test;
  while(test--)
  {
    Incurcious();
  }
  return 0;
}