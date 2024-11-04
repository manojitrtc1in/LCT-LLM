

















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=1005;
char s[Maxn][Maxn];
int dw[Maxn][Maxn];
int rt[Maxn][Maxn];
struct rec{
	short X1,Y1,X2,Y2;
	rec(short a,short b,short c,short d){
		X1=a;Y1=b;X2=c;Y2=d;
	}
};
void print(rec x){
	printf("%d %d %d %d\n",x.X1+1,1+x.Y1,1+x.X2,1+x.Y2);
}
int f(rec x){
	return 2*abs(x.X1-x.X2)+2*abs(x.Y1-x.Y2);
}
vector<pair<int,int> > av;
int g[Maxn][Maxn];
int dc;
inline void Add(int x,int y,int v){
	if (!g[x][y]) dc++;
	g[x][y]+=v;
	if (!g[x][y]) dc--;
}
void Paint(rec x,int v=1){
	for (int i=x.X1;i<=x.X2;i++){
		Add(i,x.Y1,v);
		Add(i,x.Y2,v);
	}
	for (int i=x.Y1+1;i<x.Y2;i++){
		Add(x.X1,i,v);
		Add(x.X2,i,v);
	}
}
bool check(rec a,rec b){
	Paint(a);
	Paint(b);
	int c2=0;
	for (int i=0;i<av.size();i++){
		int x=av[i].first,y=av[i].second;
		if (g[x][y]) c2++;
		else{
			Paint(a,-1);
			Paint(b,-1);
			return false;
		}
	}
	bool ret=c2==dc;


	Paint(a,-1);
	Paint(b,-1);
	return ret;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt=0;
	pair<int,int> lo,hi;
	lo=mp(23333,23333),hi=mp(0,0);

	for (int i=0;i<n;i++){
		scanf("%s",s[i]);
		for (int j=0;j<m;j++){
			if (s[i][j]=='
				cnt++;
				lo=min(lo,mp(i,j));
				if (j>hi.second || (j==hi.second && i>hi.first)){
					hi=mp(i,j);
				}
				av.pb(mp(i,j));
			}
		}
	}
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<m;j++){
			if (s[i][j]=='
				dw[i][j]=dw[i+1][j]+1;
			}
			else{
				dw[i][j]=0;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=m-1;j>=0;j--){
			if (s[i][j]=='
				rt[i][j]=rt[i][j+1]+1;
			}
			else{
				rt[i][j]=0;
			}
		}
	}
	if (cnt>8000 || cnt<8){
		printf("NO\n");
		return 0;
	}
	vector<pair<rec,rec> > V;
	for (int i=3;i+lo.first<=n && i<=dw[lo.first][lo.second];i++){
		for (int j=3;j+lo.second<=m && j<=rt[lo.first][lo.second];j++){
			int ex=i+lo.first-1,ey=j+lo.second-1;
			if (rt[ex][lo.second]>=j&& dw[lo.first][ey]>=i){
			

				if (mp(ex,ey)!=hi){
					for (int k=0;k<av.size();k++){
						int X=av[k].first,Y=av[k].second;
					

						if (X+2<=hi.first && Y+2<=hi.second && dw[X][Y]+X-1>=hi.first && rt[X][Y]+Y-1>=hi.second && rt[hi.first][Y]+Y-1>=hi.second && dw[X][hi.second]+X-1>=hi.first){
							
							V.pb(mp(rec(lo.first,lo.second,lo.first+i-1,lo.second+j-1),rec(X,Y,hi.first,hi.second)));
							pair<rec,rec> xx=V.back();
							rec _1=xx.first,_2=xx.second;
							int cc=f(_1)+f(_2);
							if (cc<cnt){
								V.pop_back();
							}
						}
					}
				}
				else{
					

					for (int k=0;k<av.size();k++){
						int X=av[k].first,Y=av[k].second;
						int nd=cnt-f(rec(lo.first,lo.second,lo.first+i-1,lo.second+j-1));
						for (int p=3;X+p<=n && p<=dw[X][Y];p++){
							for (int q=max(3,(nd-2*(p-1))/2+1);Y+q<=m && q<=rt[X][Y];q++){
								

								if (rt[X+p-1][Y]>=q && dw[X][Y+q-1]>=p){
								
									V.pb(mp(rec(lo.first,lo.second,lo.first+i-1,lo.second+j-1),rec(X,Y,X+p-1,Y+q-1)));
									pair<rec,rec> xx=V.back();
									rec _1=xx.first,_2=xx.second;
									int cc=f(_1)+f(_2);
									if (cc<cnt){
										V.pop_back();
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i=0;i<V.size();i++){
		rec _1=V[i].first,_2=V[i].second;
	

	

		int cc=f(_1)+f(_2);
		if (cc<cnt){
			continue;
		}
		

		if (check(_1,_2)){
			printf("YES\n");
			print(_1);
			print(_2);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
