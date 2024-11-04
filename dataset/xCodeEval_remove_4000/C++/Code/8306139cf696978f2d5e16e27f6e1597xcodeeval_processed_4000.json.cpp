

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=1e5;
int  n,q,k,m,c[maxn+3],counter,id[maxn+3],dem[3];
ll t,d,ans,a[maxn+3],A,B;
bool kt[maxn+3];
string  s;
ld res ;

void back(int k)
{
	if (dem[k] >= n/3) return;
	for (int i= 0; i <s.length() ;++i)
	{
		int w = s[i] - '0';
		if (dem[k] < n /3 && w > k && dem[w] > n/3)
		{
			dem[k] ++;
			dem[w] --;
			s[i] = k + '0';
		}
	}
}

void fo(int k)
{
	if (dem[k] >= n/3)return;
	for (int i = s.length() -1; i >= 0; --i)
	{
		int w= s[i] - '0';
		if (dem[k] < n / 3 && w < k && dem[w] > n/3)
		{
			dem[k]++;
			dem[w] --;
			s[i] = k + '0';
		}
	}
}

int main()
{
	IOS;
	cin>>n;
	cin>>s;
	for (int i = 0 ;i < s.length() ;++i) dem[s[i] - '0']++;
	

	

	back(0);
	back(1);
	fo(2);
	fo(1);
	cout<<s;
}

