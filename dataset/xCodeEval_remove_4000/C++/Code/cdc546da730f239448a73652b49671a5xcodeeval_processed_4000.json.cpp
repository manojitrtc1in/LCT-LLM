



 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   


using namespace std;

const long long mod = 1e9+7;
const long long mx  = 2e5+5;
typedef long long ll; 


vector<ll>prime;
ll isPrime[mx];
void seive(){	
	for(ll i=2;i<mx;++i)
	{
		if(isPrime[i]==0)
		{
			prime.push_back(i);
			for(ll j=i*i;j<mx;j+=i)
			{
				isPrime[j]=1;
			}
		}
		isPrime[i]^=1;
	}
}





















































typedef long long ll;
typedef long double ld;
long long ceil(ll A,ll B){if(A%B==0)return A/B;else return (A/B)+1ll;}
long long middle(ll a, ll b, ll c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool id0(string s) {transform(s.begin(),s.end(),s.begin(),::tolower);return (s[0]==s[s.size()-1]?1:0);}
bool as_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second); }
bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}
bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}
 
ll ncr(ll n,ll k) {
    double res = 1;
    for (ll i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
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
typedef deque<ll> Dq;
typedef set<ll> St;
typedef map<ll,ll> M;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<pair<ll,ll>> VP;
typedef priority_queue<ll,vector<ll>,greater<ll>> Pq;

string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;
long long a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;



void id1()
{	
 	cin>>n;
 	temp=2050;
 	if(n<2050)groot(-1)
 	cnt=0;
 	while(n>0){
 		temp=2050;
	 	cnt++;
 		while(true){
	 		if(n/temp==0){
	 			temp/=10;break;
	 		}
	 		temp*=10;
	 	}	
	 	if(temp<2050)groot(-1)
	 	n-=temp;
	 	

 	}
 	if(n<0)groot(-1);
 	cout<<cnt;


	lp(i,1000)
	{
		

	}
	lol
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  
	

	
		seive();
	
	cin>>test;
	while(test--)
	{
		id1();
	}
	return 0;
}