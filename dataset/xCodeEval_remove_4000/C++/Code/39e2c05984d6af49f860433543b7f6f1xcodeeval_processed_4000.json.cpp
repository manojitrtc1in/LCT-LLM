


































































































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





INT id0(char* s){
	INT ha=0;
	for(int i=0;s[i];i++){
		ha=ha*19260817+s[i];
	}
	return ha;
}

int n,m,k;
map<string,int> fff;
int FFF;
int a[1005],b[1005];

int Register(string s){
	if(!fff.count(s)){
		fff[s]=++FFF;
	}
	return fff[s];
}

struct Dsu{
	int fa[1005];
	void init(){
		for(int i=0;i<1005;i++){
			fa[i]=i;
		}
	}
	int root(int x){
		return fa[x]==x?x:(fa[x]=root(fa[x]));
	}
	void conn(int a,int b){
		a=root(a);
		b=root(b);
		if(a==b){
			return;
		}
		fa[a]=b;
	}
};

struct Room{
	bool hvkey[1005];
	bool hvprs[1005];
	bool operator<(const Room& rm)const{
		for(int i=0;i<1005;i++){
			if(hvkey[i]!=rm.hvkey[i]){
				return hvkey[i]<rm.hvkey[i];
			}
		}
		return 0;
	}
	bool operator==(const Room& rm)const{
		for(int i=0;i<1005;i++){
			if(hvkey[i]!=rm.hvkey[i]||hvprs[i]!=rm.hvprs[i]){
				return 0;
			}
		}
		return 1;
	}
	void Debug(){
		for(int i=1;i<=m;i++){
			fio<<hvkey[i]<<' ';
		}
		fio<<endl;
		for(int i=1;i<=k;i++){
			fio<<hvprs[i]<<' ';
		}
		fio<<endl;
	}
};

struct State{
	Dsu dsu;
	Room room[1005];
	bool iskey(int rm,int ky){
		return room[dsu.root(rm)].hvkey[ky];
	}
	
	void addkey(int rm,int ky){
		room[dsu.root(rm)].hvkey[ky]=1;
	}
	void addprs(int rm,int pr){
		room[dsu.root(rm)].hvprs[pr]=1;
	}
	void Conn(int x,int y){
		

		if(dsu.root(x)==dsu.root(y)){
			return;
		}
		for(int i=1;i<=k;i++){
			room[dsu.root(y)].hvprs[i]|=room[dsu.root(x)].hvprs[i];
		}
		for(int i=1;i<=m;i++){
			room[dsu.root(y)].hvkey[i]|=room[dsu.root(x)].hvkey[i];
		}
		dsu.conn(x,y);
	}
	void Read(){
		for(int i=0;i<k;i++){
			string s;
			fio>>s;
			int prs=Register(s);
			int rm;
			fio>>rm;
			addprs(rm,prs);
			int keycnt;
			

			fio>>keycnt;
			while(keycnt--){
				int key;
				fio>>key;
				addkey(rm,key);
			}
		}
	}
	bool mAKe(){
		bool changed=0;
		for(int i=1;i<=m;i++){
			if((dsu.root(a[i])!=dsu.root(b[i]))&&(iskey(a[i],i)||iskey(b[i],i))){
				Conn(a[i],b[i]);
				changed=1;
			}
		}
		return changed;
	}
	void Make(){
		while(mAKe());
	}
}bg,en;

vector<Room> stt,enn;

int main(){
	fio>>n>>m>>k;
	for(int i=1;i<=m;i++){
		fio>>a[i]>>b[i];
	}
	bg.dsu.init();
	en.dsu.init();
	bg.Read();
	en.Read();
	bg.Make();
	en.Make();
	for(int i=1;i<=n;i++){
		if(bg.dsu.root(i)==i){
			stt.pb(bg.room[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(en.dsu.root(i)==i){
			enn.pb(en.room[i]);
		}
	}
	sort(ALL(stt));
	sort(ALL(enn));
	

	

	fio<<(stt==enn?"YES":"NO")<<endl;
	return 0;
}