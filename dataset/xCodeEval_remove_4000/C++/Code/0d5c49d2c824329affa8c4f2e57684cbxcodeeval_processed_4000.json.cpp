




























































































using namespace std;
































typedef struct{ int sum,suf,pre,max;} Node;
int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
const int MAXN = 2e5+100;
const int UP = 31;




const ll highest = 1e18;    






const double Phi =  1.618033988749894;
const int logn = 20;
const double root5 = 2.236067977;   


const int mod = 1e9+7;  
const int ini = -1e9;

const int inf = 1e9;


int dp[128][128][12];
int par[128][128][12];
char a[128][128];
int n,m,k;
int go(int x,int y,int r){
	if(x==0){
		return r == 0?0:-1e9;
	}
	int &res = dp[x][y][r];
	if(res != -1)return res;
	res = -(1e9);
	if(y-1>=0){
		int next = (a[x-1][y-1]-'0')+go(x-1,y-1,(r + a[x-1][y-1]-'0')%(k+1));
		if(next>res){
			res = next;
			par[x][y][r] = -1;
		}
	}
	if(y+1<m){
		int next = (a[x-1][y+1]-'0')+go(x-1,y+1,(r+a[x-1][y+1]-'0')%(k+1));
		if(next>res){
			res = next;
			par[x][y][r] = 1;
		}
	}
	return res;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i){
		scanf("%s",a[i]);
	}
	int res = -1;
	int ma = -1;
	for(int i=0;i<m;++i){
		int now = a[n-1][i] - '0' + go(n-1,i,(a[n-1][i]-'0')%(k+1));
		if(res<now){
			res = now;
			ma = i;
		}
	}
	printf("%d\n",res);
	if(res != -1){
		printf("%d\n",ma+1);
		int y = ma;
		int r = (a[n-1][ma]-'0')%(k+1);
		for(int i=n-1;i>0;--i){
			printf("%c",par[i][y][r]==-1?'L':'R');
			y += par[i][y][r];
			r = (r + a[i-1][y]-'0')%(k+1);
		}
		printf("\n");
	}
	return 0;
}






















































































































































































































        












        








 



































        































































































































































































































































































































































































































































