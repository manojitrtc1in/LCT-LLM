




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
int used[no],color[no];
int ans=0;

void solve () {
	int n=0,m=0,a=0,b=0,c=0,x=0,y=0,z=0,w=0,k=0;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	rep(i,0,n) {
		ar[s1[i]-'a']++;
		ar[s2[i]-'a']++;
	}
	rep(i,0,26) {
		if(ar[i]%2) {
			cout<<"NO"<<en;
			return ;
		}
	}
	cout<<"YES"<<en;
	pii v;
	rep(i,0,n) {
		k=0;
		if(s1[i]==s2[i]) continue;
		rep(j,i+1,n) {
			if(s1[i]==s1[j]) {
				v.PB({j+1,i+1});
				swap(s1[j],s2[i]);
				k=1;
				break;
			}
		}
		if(!k) {
			rep(j,i+1,n) {
				if(s1[i]==s2[j]) {
					swap(s1[j],s2[j]);
					swap(s1[j],s2[i]);
					v.PB({j+1,j+1});
					v.PB({j+1,i+1});
					break;
				}
			}
		}
	}
	if(s1!=s2 || v.size()>2*n) {
		cout<<"NO"<<en;
		return;
	}
	cout<<v.size()<<en;
	rep(i,0,v.size()) cout<<v[i].fi<<" "<<v[i].se<<en;
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
		rep(i,0,26) ar[i]=0;
		solve();
	}
}
