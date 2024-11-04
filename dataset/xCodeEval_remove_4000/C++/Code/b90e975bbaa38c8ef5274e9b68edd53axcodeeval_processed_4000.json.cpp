



 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   


using namespace std;



const int MOD = 1e9+7;
const int mx  = 2e5+5;
typedef long long ll; 


































































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





void id0()
{ 	
	cin>>n;
	cout<<2<<" "<<(n/2)*2<<endl;

    lp(i,1000)
    {
      

    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
          
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    
    test=1;
    cin>>test;
    while(test--)
    {
      id0();
    }
    return 0;
}