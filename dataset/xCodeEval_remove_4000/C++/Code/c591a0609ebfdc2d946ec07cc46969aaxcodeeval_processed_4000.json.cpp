
































































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
struct fastIO
{
	inline fastIO operator>>(int& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(INT& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(float& num)
	{
		scanf("%f",&num);
		return *this;
	}
	inline fastIO operator>>(double& num)
	{
		scanf("%lf",&num);
		return *this;
	}
	inline fastIO operator>>(long double& num)
	{
		scanf("%Lf",&num);
		return *this;
	}
	inline fastIO operator>>(char& num)
	{
		num=getchar();
		while(num==' '||num=='\n')num=getchar();
		return *this;
	}
	inline fastIO operator>>(char* num)
	{
		int cnt=0;
		char c=getchar();
		while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n')
		{
			num[cnt++]=c;
			c=getchar();
		}
		num[cnt]=0;
		return *this;
	}
	inline fastIO operator>>(string& num)
	{
		cin>>num;
		return *this;
	}
	inline void printInt(const int& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printInt(num/10);
		putchar((num%10)+'0');
	}
	inline void printINT(const INT& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printINT(num/10);
		putchar((num%10)+'0');
	}
	inline fastIO operator<<(const int& num)
	{
		if(num<0)putchar('-'),printInt(-num);
		else printInt(num);
		return *this;
	}
	inline fastIO operator<<(const INT& num)
	{
		if(num<0)putchar('-'),printINT(-num);
		else printINT(num);
		return *this;
	}
	inline fastIO operator<<(const float& num)
	{
		printf("%.10f",num);
		return *this;
	}
	inline fastIO operator<<(const double& num)
	{
		printf("%.16lf",num);
		return *this;
	}
	inline fastIO operator<<(const long double& num)
	{
		printf("%.20Lf",num);
		return *this;
	}
	inline fastIO operator<<(const char& num)
	{
		putchar(num);
		return *this;
	}
	inline fastIO operator<<(const char* num)
	{
		for(int i=0;num[i];i++)
			putchar(num[i]);
		return *this;
	}
	inline fastIO operator<<(const string& num)
	{
		cout<<num;
		return *this;
	}
}fio;





INT a[107][123456];
INT len[107];
INT n;
INT p[107],b[107];
INT V;

void id2(INT f1,INT f2,INT to){
	INT cur=0,cur1=0,cur2=0;
	while(cur1<len[f1]||cur2<len[f2]){
		if(a[f1][cur1]<a[f2][cur2]){
			a[to][cur]=a[f1][cur1];
			cur++;
			cur1++;
		}else{
			a[to][cur]=a[f2][cur2];
			cur++;
			cur2++;
		}
	}
	len[to]=cur;
	a[to][cur]=INF;
}

INT id0(INT a,INT b){
	if(!b){
		return 1;
	}
	INT fuck=id0(a,b/2);
	fuck*=fuck;
	if(b%2){
		fuck*=a;
	}
	return fuck;
}

INT fitch(INT start,INT djg){
	vector<INT> fch;
	fch.pb(b[djg]);
	INT cur=start;
	while(1){
		INT lst=fch[SZ(fch)-1];
		if(!lst){
			break;
		}else if(lst%2){
			fch.pb(lst/2);
		}else{
			fch.pb(lst-1);
		}
	}
	for(INT i=SZ(fch)-2;i>=0;i--){
		INT now=fch[i],nxt=fch[i+1];
		if(now==2*nxt+1){
			INT fus=id0(p[djg],nxt+1);
			for(INT i=0;i<len[cur];i++){
				a[cur+1][i]=a[cur][i]*fus;
			}
			len[cur+1]=len[cur];
			a[cur+1][len[cur+1]]=INF;
			id2(cur,cur+1,cur+2);
			cur+=2;
		}else{
			for(INT i=0;i<len[cur];i++){
				a[cur][i]*=p[djg];
			}
			id2(start,cur,cur+1);
			cur++;
		}
	}
	return cur;
}

INT ins[123456],cntin;
map<INT,pair<PII,PII> > id1;

void func(){
	INT c213=cntin-1;
	pair<PII,PII> ans;
	ans.first.first=INF;
	for(INT c1=0;c1<cntin;c1++){
		INT lst=V/ins[c1];
		while(lst/ins[c213]/ins[c213]==0){
			c213--;
		}
		for(INT c2=c213;c2>=c1;c2--){
			if(lst%ins[c2]){
				continue;
			}
			INT a1=ins[c1],a2=ins[c2];
			INT a3=V/a1/a2;
			ans=min(ans,mp(mp(2*(a1*(a2+a3)+a2*a3),a1),mp(a2,a3)));
			break;
		}
	}
	id1[V]=ans;
	fio<<ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
}

int main(){
	INT T;
	fio>>T;
	while(T--){
		fio>>n;
		V=1;
		a[0][0]=1;
		a[0][1]=INF;
		len[0]=1;
		for(INT i=0;i<n;i++){
			fio>>p[i]>>b[i];
			for(INT j=0;j<b[i];j++){
				V*=p[i];
			}
		}
		if(id1.count(V)){
			pair<PII,PII> ans=id1[V];
			fio<<ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
			continue;
		}
		INT xxx=0;
		for(INT i=0;i<n;i++){
			xxx=fitch(xxx,i);
		}
		for(INT i=0;i<len[xxx];i++){
			ins[i]=a[xxx][i];
		}
		cntin=len[xxx];
		func();
	}
	return 0;
}