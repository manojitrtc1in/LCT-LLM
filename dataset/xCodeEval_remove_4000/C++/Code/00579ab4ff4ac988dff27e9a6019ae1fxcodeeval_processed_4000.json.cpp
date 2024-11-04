




using namespace std;

















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

int id0(int x, int y , int mod) { int res=1; while (y) { if (y & 1){ y--; res=mul(res,x,mod); res%=mod; } else { y/=2; x=mul(x,x,mod); x%=mod; } } return res%mod; }

int poww(int x , int y) { int res=1; while(y) { if(y%2) { y--; res=res*x; } else { y/=2; x=x*x; } } return res; }

int div(int x , int y , int mod) {
	return (x*id0(y,mod-2,modulo))%mod ;
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
int used[no],parent[no];
int ans=0;

void solve () {
	int n=0,m=0,a=0,b=0,c=0,x=0,y=0,z=0,w=0,k=0;
	cin>>n;
	string s;
	cin>>s;
	s+=s;
	rep(i,0,n) {
		if(s[i]=='>') x++;
		else if(s[i]=='<') y++;
		else z++;
	}
	if(!x && !y) {
		cout<<z<<en;
	}
	else if(!y && !z) {
		cout<<x<<en;
	}
	else if(!x && !z) {
		cout<<y<<en;
	}
	else if(!x) {
		cout<<y+z<<en;
	}
	else if(!y) {
		cout<<x+z<<en;
	}
	else if(!z) {
		cout<<0<<en;
	}
	else {
		rep(i,0,n) {
			if(s[i]=='-') {
				if(i==n-1 && (s[i+1]=='<' || s[i+1]=='>')) w+=2;
				else if(s[i+1]=='>' || s[i+1]=='<') {
					w+=2;
					i++;
				}
				else w++;
			}
		}
		cout<<w<<en;
	}
}

inline void runn(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
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

