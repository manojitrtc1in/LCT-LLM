


































#include <bits/stdc++.h>
using namespace std;



#define fro for
#define itn int
#define mp make_pair
#define pb push_back
#define on first
#define tw second
#define be(n) n.begin()
#define en(n) n.end()
#define all(n) (n.begin(),n.end())
#define po(n) n.pop()
#define PI 3.141592653
#define son(n) int lf=2*n,ri=2*n+1
#define pr int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37}
#define sz(n) n.size()
#define big int maxi=-1
#define small int mini=1e9+7
#define op(x) freopen(x,"r",stdin)
#define wr(x) freopen(x,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> st;
typedef set<int> jihe;
typedef queue<int> qi;
typedef vector<pair<int,int> > vp;
const int inf=1e9+7;
const int maxn=5005;
const int maxm=200005;




int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max1,maxi=-1;
	for(int i=1;i<=n;i++)
	{
		if(maxi<a[i])
		{
			maxi=a[i];
			max1=i;
		}
	}
	a[max1]=-1;
	maxi=-11;
	for(int i=1;i<=n;i++)
	{
		maxi=max(maxi,a[i]);
	}
	cout<<max1<<" "<<maxi<<endl;
    return 0;
}
