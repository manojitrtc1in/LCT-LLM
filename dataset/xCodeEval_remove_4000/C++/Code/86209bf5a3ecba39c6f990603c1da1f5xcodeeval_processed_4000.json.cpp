

using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;



const int maxn=100005;
char s[maxn],ans[20];
int cnt[32][13][3],dy[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int gtn(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='-') return -1;
		ans=ans*10+s[i]-48;
	}
	return ans;
}
int main(){
	scanf("%s",s);
	int n=strlen(s),d,m,y,mx=-1,mxp=0;
	for(int i=9;i<n;i++){
		if(s[i-7]!='-'||s[i-4]!='-') continue;
		d=gtn(i-9,i-8);
		m=gtn(i-6,i-5);
		y=gtn(i-3,i);
		if(y<2013||y>2015) continue;
		if(m<=0||m>12) continue;
		if(d<=0||d>dy[m]) continue;
		y-=2013;
		cnt[d][m][y]++;
		if(mx<cnt[d][m][y]){
			mx=cnt[d][m][y];
			mxp=i-9;
		}
	}
	for(int i=mxp;i<mxp+10;i++){
		ans[i-mxp]=s[i];
	}
	printf("%s\n",ans);
	return 0;
}