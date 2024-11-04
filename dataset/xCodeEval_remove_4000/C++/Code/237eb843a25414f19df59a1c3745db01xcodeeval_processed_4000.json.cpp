



 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   


using namespace std;

const int MOD = 1e9+7;
const int mx  = 2e5+5;
typedef long long ll; 


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
typedef vector<char> V;
typedef vector<V> VV;
typedef vector<pair<int,int>> VP;
typedef priority_queue<int,vector<int>,greater<int>> Pq;
string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;

int a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;





void id0()
{ 
	cin>>a>>b;
	cin>>str;
	n=str.size();
	lp(i,n){
		if(str[i]=='0')a--;
		else if(str[i]=='1')b--;
	}
	flag=true;
	lp(i,n/2){
		if(str[i]=='1'){
				if(str[n-1-i]=='1')continue;
				if(str[n-1-i]=='?' and b>0){
					str[n-1-i]='1',b--;
				}else{
					flag=false;
				}
			}

		else if(str[i]=='0'){
			if(str[n-1-i]=='0')continue;
			if(str[n-1-i]=='?' and a>0){
				str[n-1-i]='0',a--;
			}else{
				flag=false;
			}
		}
		else{
			if(str[n-1-i]=='0' and a>0)str[i]='0',a--;
			else if(str[n-1-i]=='1' and b>0)str[i]='1',b--;
		}
	}
	if(!flag)groot(-1)
	lp(i,n/2){
		if(str[i]=='?' and str[n-1-i]=='?'){
			if(a>=2)str[i]='0',str[n-1-i]='0',a-=2;
			else if(b>=2)str[i]='1',str[n-1-i]='1',b-=2;
			else flag=false;
		}
	}
	if(n&1 and str[n/2]=='?'){
		if(a>0)str[n/2]='0',a--;
		else if(b>0)str[n/2]='1',b--;
		else flag=false;
	}
	if(!flag or a!=0 or b!=0)groot(-1)

	cout<<str<<'\n';














  lp(i,1000)
  {
    

  }
  

}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
        
  
  
    seive();
  
        test=1;
  cin>>test;
  while(test--)
  {
    id0();
  }
  return 0;
}