
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
int n,m;
int cl,ce,v,q;
int l[Maxn],e[Maxn];
int x1,y1,x2,y2;
int Lf(int pos){
	return abs(y1-pos)+abs(y2-pos)+((abs(x2-x1)+v-1)/v);
}
int St(int pos){
	return abs(y1-pos)+abs(y2-pos)+(abs(x2-x1));
}
int main(){
	scanf("%d %d %d %d %d",&n,&m,&ce,&cl,&v);
	for (int i=0;i<ce;i++){
		scanf("%d",&e[i]);
	}
	for (int i=0;i<cl;i++){
		scanf("%d",&l[i]);
	}
	scanf("%d",&q);
	while (q--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if (x1==x2){
			printf("%d\n",abs(y1-y2));
			continue;
		}
		int p1=lower_bound(l,l+cl,y1)-l;
		int ans=2147483647;
		if (p1!=cl){
			ans=min(ans,Lf(l[p1]));
		}
		if (p1!=0){
			ans=min(ans,Lf(l[p1-1]));
		}
		int p2=lower_bound(e,e+ce,y1)-e;
		if (p2!=ce){
			ans=min(ans,St(e[p2]));
		}
		if (p2!=0){
			ans=min(ans,St(e[p2-1]));
		}
		printf("%d\n",ans);
	}
}

