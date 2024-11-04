
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=65;
LL r[Maxn];
int main(){
	int q;
	scanf("%d",&q);
	while (q--){
		int tp;
		scanf("%d",&tp);
		if (tp==3){
			LL x;
			scanf("%I64d",&x);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			

			x+=r[lvl];
			if (x>=(1ll<<lvl)) x-=(1ll<<(lvl-1));
			LL ans=0;
			for (int i=lvl;i>=1;i--){
				LL nd=x-r[i];
				if (nd>=(1ll<<i)){
					nd-=(1ll<<(i-1));
				}
				if (nd<(1ll<<(i-1)))nd+=1ll<<(i-1);
				printf("%I64d ",nd);
				x>>=1;
			}
			printf("\n");
		}
		else if (tp==1){
			LL x,k;
			scanf("%I64d %I64d",&x,&k);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			r[lvl]+=k;
			LL siz=1ll<<(lvl-1);
			r[lvl]=(r[lvl]%siz+siz)%siz;
		}
		else if (tp==2){
			LL x,k;
			scanf("%I64d %I64d",&x,&k);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			k%=1ll<<(lvl-1);
			if (k<0) k+=(1ll<<(lvl-1));
			for (int i=lvl;i<=63;i++){
				r[i]+=k;
				LL siz=1ll<<(i-1);
				k*=2;
				r[i]=(r[i]%siz+siz)%siz;
			}
		}
	}
}
