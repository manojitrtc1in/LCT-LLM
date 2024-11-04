




 

  

 

 

 

 

 


 

 

 

  

   


using namespace std;
















const int MOD = 1e9+7;
const int mx  = 2e5+5;
typedef long long ll;






















































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


void id0()
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
      id0();
    }
    return 0;
}