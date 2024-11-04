
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=5005;
char c[Maxn];
int cnt[27];
vector<int> pos[27];
int cc[27];
int main(){
	scanf("%s",c);
	int n=strlen(c);
	for (int i=0;i<n;i++){
		cnt[c[i]-'a']++;
		pos[c[i]-'a'].pb(i);
	}
	double res=0.0;
	for (int i=0;i<26;i++){
		double P=1.0*cnt[i]/n;
		if (!P) continue;
		double Mx=0.0;
		for (int j=1;j<n;j++){
			memset(cc,0,sizeof(cc));
			for (int k=0;k<pos[i].size();k++){
				cc[c[(pos[i][k]+j)%n]-'a']++;
			}
			int cnt2=0;
			for (int k=0;k<26;k++){
				if (cc[k]==1){
					cnt2++;
				}
			}
			Mx=max(Mx,1.0*cnt2/(double)(pos[i].size()));
		}
		res=res+Mx*P;
	}
	printf("%.10lf\n",res);
	
	return 0;
}

