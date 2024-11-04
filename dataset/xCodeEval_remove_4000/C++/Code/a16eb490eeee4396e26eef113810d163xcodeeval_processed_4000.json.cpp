
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=55;
char c[Maxn][Maxn];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",c[i]);
	}
	bool flag=true;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			bool f1=true,f2=true;
			for (int k=0;k<m;k++){
				if (c[i][k]!=c[j][k]) f1=false;
				if (c[i][k]==c[j][k] && c[i][k]=='
			}
			if (!f1 && !f2) flag=false;
		}
	}
	if (!flag){
		printf("No\n");
	}
	else{
		printf("Yes\n") ;
	}
	return 0;
}
