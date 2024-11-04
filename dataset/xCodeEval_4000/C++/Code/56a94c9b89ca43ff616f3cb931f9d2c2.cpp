

#include<bits/stdc++.h>
#include<map>
#include<set>
#include<stack>

using namespace std;

#define night_rider ios::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define double long double
#define en "\n"
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define toUpper(x) transform(x.begin(), x.end(), x.begin(),::toupper);
#define toLower(x) transform(x.begin(), x.end(), x.begin(),::tolower);
#define rep(i,x,y) for(int i=x ; i<y ; i++)
#define erep(i,x,y) for(int i=x ; i<=y ; i++)
#define erepr(i,x,y) for(int i=x ; i>=y ; i--)
#define repr(i,x,y) for(int i=x ; i>y ; i--)
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> pii;
bool secdes(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi>b.fi;}else{return a.se>b.se;}}

bool sir(const pair<int,int>&a , const pair<int,int>&b){if(a.fi==b.fi){return a.se>b.se;}else{return a.first>b.first;}}

bool bysec(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi<b.fi;} else{return a.se<b.se;}}





const int no=1e6+5;
const int modulo=1e9+7;
const int inf=1e18;
const int N=2001;
int ar[no+10],br[no+10],cr[no+10],mat[N][N];
int dx[]={-1 , 0 , 1 , 0};
int dy[]={0 , 1 , 0 , -1};
char dc[]={'L', 'D' , 'R' ,'U'};



int mul(int x , int y , int mod) {
	return ((x%mod)*(y%mod))%mod;
}

int powwmod(int x, int y , int mod) { int res=1; while (y) { if (y & 1){ y--; res=mul(res,x,mod); res%=mod; } else { y/=2; x=mul(x,x,mod); x%=mod; } } return res%mod; }

int poww(int x , int y) { int res=1; while(y) { if(y%2) { y--; res=res*x; } else { y/=2; x=x*x; } } return res; }

int div(int x , int y , int mod) {
	return (x*powwmod(y,mod-2,modulo))%mod ;
}

int add(int x, int y, int mod) {
	return (x%mod+y%mod)%mod;
}
bool comp(int x, int y) {
	return (x < y);
}

int gcd(int x, int y) { if(y==0) return x; else return gcd(y,x%y); }

int lcm(int x, int y) { return (x*y)/gcd(x,y);}



vi adj[no];
int used[no],color[no],parent[no];
int ans=0,ok=0;

void solve () {
	int n=0,m=0,a=0,b=0,c=0,x=0,y=0,z=0,w=0,k=0;
	cin>>n>>m;
	

	if(m<=n) cout<<"YES"<<en;
	else {
        set<int> s;
        while(n) {
            if(n%2==0) n/=2 , n*=3 ;
            else n--;
            if(s.find(n)!=s.end()) {
                cout<<"NO"<<en;
                return ;
            }
            else s.insert(n);
            if(m<=n) {
                cout<<"YES"<<en;
                return ;
            }
        }
        cout<<"NO"<<en;
	}
}

inline void runn(){
	#ifndef ONLINE JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

signed main()
{
	night_rider
	

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}


