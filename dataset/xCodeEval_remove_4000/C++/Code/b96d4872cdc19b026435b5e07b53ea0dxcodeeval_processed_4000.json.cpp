

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;



int n,n2,id=0,c[N];
char ans[N],s[N*N][N];
struct Node{
	int u,v,s;
	Node(){}
	Node(int uu,int vv,int ss){u=uu;v=vv;s=ss;}
	
};
vector<Node> v[3],cal;

inline void init(int r){
	printf("? 1 %d\n",r);
	FF;
	int len=r*(r+1)/2,p,sum=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<=len;++i){
		scanf("%s",s[i]);
		p=strlen(s[i]);
		for(int j=0;j<p;++j) c[p]+=s[i][j];
	}
	p=0;
	for(int i=2;i<=(r+1)/2;++i){
		sum=p+c[1]-c[i]+c[i-1];
		v[id].push_back(Node(i-1,r-i+2,sum));
		p-=sum;
	}
	p+=c[1];
	v[id].push_back(Node((r+1)/2,(r+2)/2,p));
}
int main(){
	scanf("%d",&n);
	n2=n/2;
	if(n2>0) init(n2);
	
	++id;
	if(n2-1>0) init(n2-1);
	if(n2&1) cal.push_back(v[0][n2/2]);
	for(int i=n2/2-1;i>=0;--i){
		cal.push_back(v[1][i]);
		cal.push_back(v[0][i]);
	}
	for(int i=0;i<cal.size();++i){
		

		if(ans[cal[i].u]){
			ans[cal[i].v]=cal[i].s-ans[cal[i].u];
		}else{
			ans[cal[i].u]=cal[i].s-ans[cal[i].v];
		}
	}
	

	++id;
	init(n);
	for(int i=0;i<v[2].size();++i){
		ans[v[2][i].v]=v[2][i].s-ans[v[2][i].u];
	}
	printf("! %s\n",ans+1);
	FF;
    return 0;
}