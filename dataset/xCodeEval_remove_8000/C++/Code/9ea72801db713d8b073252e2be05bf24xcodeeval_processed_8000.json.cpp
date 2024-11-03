




typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=2e5;
const int MOD=998244353;
int n,q,d,a[maxn+3],id[maxn+3],v[maxn+3],t[maxn+3];
int dem[maxn+3];
int k,res =0 ;
int tong[maxn+3],ans[600][600];
string  s1;
map<int,int> m;
vector<int> edge[maxn+3];
template<typename T>
void answer(T x) {
	cout << x;exit(0);
}

int counter(int i,int j)
{
	int count = 0;
	if (i == n-i+1 || j==n-j+1) count +=2;
	if (j == n-j+1 && i == n-i+1) count +=1;
	return 4-count;
}

void write_r(int i,int j,int need)
{
	ans[i][j] = ans[n-i+1][j] = ans[i][n-j+1] = ans[n-i+1][n-j+1] = need; 	
}

int main()
{
	IOS;
	cin >> n;
	for (int i=1 ; i<= n*n;++i) cin >> a[i],m[a[i]] ++;
	int mb = 0,mbm = 0,other = 0;
	vector<pair<int,int> > d;
	for (auto&x:m)
	{
		if (x.s % 4 == 0) mb++;
		else if (x.s%4 == 1) mbm ++;
	

		d.push_back({x.s,x.f});
	}
	sort(d.begin(),d.end());
	memset(ans,0,sizeof ans);
	int chot = 0;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			if (ans[i][j] == 0) 
			{
				int need = counter(i,j),bd = 0,ppo = 0;
				for (auto&x:d)
				if (x.f >= need ) 
				{
	

				
			x.f -= need;
			write_r(i,j,x.s);
			ppo = 1;break;}
			if (ppo == 0) {answer("\nNO");
			}
			}
		}
	}
	cout << "YES\n";
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j) cout << ans[i][j] <<' ';
		cout <<"\n";
	}
}


