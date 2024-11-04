


































































































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





const int id1=555;
char ass[300005];
string s[605];
int cost[605];
int tr[300005][35];
int val[300005];
int fail[300005];



int main(){
	int id0;
	fio>>id0;
	int cnttr=1;
	int cnt=0;
	while(id0--){
		int mode;
		fio>>mode>>ass;
		int len=strlen(ass);
		if(mode<3){
			if(len<id1){
				int now=1;
				for(int i=0;i<len;i++){
					int ch=ass[i]-'a';
					if(!tr[now][ch]){
						tr[now][ch]=++cnttr;
					}
					now=tr[now][ch];
				}
				val[now]+=3-(mode<<1);
			}else{
				s[cnt]=ass;
				s[cnt]+='(';
				cost[cnt]=3-(mode<<1);
				cnt++;
			}
		}else{
			INT ans=0;
			for(int i=0;i<len;i++){
				int now=1;
				for(int j=i;j<len;j++){
					int ch=ass[j]-'a';
					now=tr[now][ch];
					if(!now){
						break;
					}
					ans+=val[now];
				}
			}
			for(int id=0;id<cnt;id++){
				int Len=SZ(s[id]);
				Len--;
				if(Len>len){
					continue;
				}
				int now=0;
				fail[1]=0;
				for(int i=2;i<=Len;i++){
					while(now&&s[id][i-1]!=s[id][now]){
						now=fail[now];
					}
					if(s[id][i-1]==s[id][now]){
						now++;
					}
					fail[i]=now;
				}
				now=0;
				for(int i=1;i<=len;i++){
					if(now&&ass[i-1]!=s[id][now]){
						now=fail[now];
					}
					if(ass[i-1]==s[id][now]){
						now++;
					}
					if(now==Len){
						ans+=cost[id];
					}
				}
			}
			fio<<ans<<endl;
			fuck;
		}
	}
	return 0;
}