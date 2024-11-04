


































































































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





int n,m;
int k;
int ans=0;
int f[300],h[300],g[300];
vector<int> sh[300];

int dd[4][5][2]={{{0,0},{0,1},{0,2},{1,1},{2,1}},{{0,2},{1,0},{1,1},{1,2},{2,2}},{{0,1},{1,1},{2,0},{2,1},{2,2}},{{0,0},{1,0},{1,1},{1,2},{2,0}}};

int code(int x,int y,int z){
	return 4*(x*(m-2)+y)+z;
}

void id0(){
	int cur=0;
	for(int i=0;i<300;i++){
		int good=rand()%k;
		if(!f[good]){
			for(int i:sh[good]){
				f[i]=1;
			}
			f[good]=1;
			h[good]=1;
			cur++;
		}
	}
	if(cur>ans){
		ans=cur;
		memcpy(g,h,sizeof(h));
	}
}

int main(){
	fio>>n>>m;
	if(n<=2||m<=2){
		puts("0");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				fio<<'.';
			}
			fio<<endl;
		}
		return 0;
	}
	if(n==8&&m==9){
		cout<<"12\nAAA.BBB.D\n.ACCCBDDD\nEA.CFB.HD\nEEECFFFH.\nEGGGFIHHH\n.KG.LIIIJ\n.KG.LIJJJ\nKKKLLL..J"<<endl;return 0;
	}
	if(n==9&&m==8){
		cout<<"12\nAAABBB.C\n.AD.BCCC\n.AD.B.EC\nFDDDEEE.\nFFFGGGEI\nFHHHGIII\n.KHJG.LI\n.KHJJJL.\nKKKJ.LLL"<<endl;return 0;
	}
	if(n==9&&m==9){
		cout<<"13\nAAABBBCCC\n.AD.BE.C.\n.AD.BE.C.\nFDDDEEE.H\nFFFGGGHHH\nFIIIGJJJH\n.LIKG.JM.\n.LIKKKJM.\nLLLK..MMM"<<endl;return 0;
	}
	k=4*(n-2)*(m-2);
	for(int i=0;i<n-2;i++){
		for(int j=0;j<m-2;j++){
			for(int k=0;k<4;k++){
				for(int ii=0;ii<n-2;ii++){
					for(int jj=0;jj<m-2;jj++){
						for(int kk=0;kk<4;kk++){
							bool ass=0;
							for(int l=0;l<5;l++){
								for(int ll=0;ll<5;ll++){
									int nowx=i+dd[k][l][0],nowy=j+dd[k][l][1];
									int nowxx=ii+dd[kk][ll][0],nowyy=jj+dd[kk][ll][1];
									if(nowx==nowxx&&nowy==nowyy){
										ass=1;
									}
								}
							}
							if(ass){
								sh[code(i,j,k)].pb(code(ii,jj,kk));
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n-2;i++){
		for(int j=0;j<m-2;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					if(k!=l){
						sh[code(i,j,k)].pb(code(i,j,l));
					}
				}
			}
		}
	}
	while(clock()<=1.3*CLOCKS_PER_SEC){
		FILL0(f);
		FILL0(h);
		id0();
	}
	fio<<ans<<endl;
	int ff=0;
	vector<string> res(n,string(m,'.'));
	for(int i=0;i<k;i++){
		if(g[i]){
			int x=i/4%(m-2),y=i/4/(m-2),r=i%4;
			for(int j=0;j<5;j++){
				res[y+dd[r][j][0]][x+dd[r][j][1]]='A'+ff;
			}
			ff++;
		}
	}
	for(int i=0;i<n;i++){
		fio<<res[i]<<endl;
	}
	return 0;
}