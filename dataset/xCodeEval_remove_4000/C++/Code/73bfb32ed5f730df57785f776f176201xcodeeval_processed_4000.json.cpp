
















































































using namespace std;
const int Maxn=10005;
char c[Maxn];
vector<int> G[Maxn];
bool dop;
vector<pair<int,int> > solve(int lo,int hi){
	if (lo==hi){
		vector<pair<int,int> > ret;
		ret.resize(101,mp(-1e9,1e9));
		ret[0]=mp(c[lo]-'0',c[lo]-'0');
		return ret;
	}
	int cur=0,pos;
	for (int i=lo+1;i<hi;i++){
		if (!cur && c[i]=='?'){
			pos=i;
			break;
		}
		if (c[i]=='(') cur++;
		else if (c[i]==')') cur--;
	}
	vector<pair<int,int> > lans=solve(lo+1,pos-1),rans=solve(pos+1,hi-1),fans;
	fans.resize(101,mp(-1e9,1e9));
	for (int i=0;i<=100;i++){
		for (int uu=0;uu<2;uu++){
			for (int j=0;j<=i-uu;j++){
				if (dop^uu)
					fans[i].first=max(fans[i].first,lans[j].first-rans[i-j-uu].second),
					fans[i].second=min(fans[i].second,lans[j].second-rans[i-j-uu].first);
				else
					fans[i].first=max(fans[i].first,lans[j].first+rans[i-j-uu].first),
					fans[i].second=min(fans[i].second,lans[j].second+rans[i-j-uu].second);
			}
		}
	}
	return fans;
}
int main(){
	scanf("%s",c);
	int l=strlen(c);
	int P,M;
	scanf("%d %d",&P,&M);
	if (P<=100) dop=true;
	vector<pair<int,int> > ans=solve(0,l-1);
	int lp=(dop)?P:M;
	printf("%d\n",ans[lp].first);
	return 0;
}



