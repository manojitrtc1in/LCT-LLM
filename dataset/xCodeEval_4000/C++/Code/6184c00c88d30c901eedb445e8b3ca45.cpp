




 

  

 

 

 

 

 


 

 

 

  

   

#include<bits/stdc++.h>
using namespace std;













#define int long long int
#define double long double
#define endl "\n"
const int MOD = 1e9+7;
const int mx  = 2e5+5;
typedef long long ll;

#define inf       LLONG_MAX
#define zero      -LLONG_MAX
#define PI        acos(-1.0)  

#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b)    (a*(b/__gcd(a,b) ))
#define MP        make_pair
#define pb        push_back
#define eb      emplace_back
#define rev(v)      reverse(v.begin(),v.end());
#define srt(v)      sort(v.begin(),v.end());
#define grtsrt(v)     sort(v.begin(),v.end(),greater<ll>());
#define full(v)     (v).begin(),(v).end()
#define hellyeah    exit(0);
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
#define sz(X)         X.size()

int mod(int M){return (M % MOD + MOD)%MOD;}
int ceil(int A,int B){if(A%B==0)return A/B;else return (A/B)+1ll;}
int middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) {
  if(a.second==b.second) return a.first<b.first;
  return  a.second < b.second;
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
typedef pair<int,int> P;
typedef deque<int> Dq;
typedef set<int> St;
typedef map<int,int> M;
typedef vector<int> V;
typedef vector<bool> VB;
typedef vector<V> VV;
typedef vector<pair<int,int>> VP;
typedef priority_queue<int,vector<int>,greater<int>> Pq;

string str,str1,str2;
char ch,ch1;
bool flag,flag1,flag2;

int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,sum,sum1,sum2,ans,ma,ma1,ma2,mi,mi1,mi2,temp,temp1,temp2;


void Incurcious()
{

    cin >> n;
    V v(n);
    k = 0;
    lp(i, n) {
        v[i] = i;
        if(i % 4 == 3) {
            swap(v[i], v[i-1]);
        }
    }
    if(n == 1) {
        groot(0)
    }
    if(n == 2){
        cout << 0 << " " << 1 << endl;return;
    }
    if(n == 3) {
        cout << 2 << " " << 0 << " " << 1 << endl;return;
    }
    if(n == 4){
        cout << 0 << " " << 1 << " " << 3 << " " << 2 << endl;return;
    }
    k = 0;
    while ((1LL << k ) < n) ++k;
    

    k--;
    V d;
    lp1(i, (1LL<<k), n - 1 ){
        d.push_back(v[i]);
    }
    rev(d)
    for (auto it: d)cout << it << " ";
    lp(i, (1LL<<k)){
        cout << v[i] << " ";
    }cout << endl;





    lp(i,1000)
    {
      

    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    test=1;
    cin>>test;
    while(test--)
    {
      Incurcious();
    }
    return 0;
}