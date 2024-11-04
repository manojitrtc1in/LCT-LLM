



#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<time.h>
#include<cstdlib>
#include<cmath>
#include<list>
using namespace std;
#define MAXN 10000006
#define eps 0
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fore(i,a,b) for(int i=a;i>=b;i--)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mkp make_pair
#define pb push_back
#define cr clear()
#define sz size()
#define met(a,b) memset(a,b,sizeof(a))
#define iossy ios::sync_with_stdio(false)
#define fr freopen
#define pi acos(-1.0)
#define Vector Point
#define fir first
#define sec second
#define it_s_too_hard main
const long long inf=1LL<<62;
const int iinf=1<<30;
const double dinf=1e17;
const int Mod=1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
int n,a[2000005];
ll t[2000005*4];
void up(int rt){
	t[rt]=t[rt<<1]+t[rt<<1|1];
}
void Change(int x,int l,int r,int rt){
	int mid=l+r>>1;
	if(l==r && r==x){
		t[rt]++;
		return ;
	}
	if(x<=mid) Change(x,lson);
	else Change(x,rson);
	up(rt);
}
ll query(int L,int R,int l,int r,int rt){
	int mid=l+r>>1;
	if(L<=l && r<=R) return t[rt];
	if(R<=mid) return query(L,R,lson);
	else if(L>mid) return query(L,R,rson);
	else return query(L,mid,lson)+query(mid+1,R,rson);
}
void I_can_t_solve_it(){
	cin>>n;met(t,0);
	For(i,1,n) cin>>a[i];
	ll ans=0;
	Fore(i,n,1){
		ans+=query(1,a[i],1,n,1);
		Change(a[i],1,n,1);
	}
	if((3*n-ans)%2==0) cout<<"Petr"<<endl;
	else cout<<"Um_nik"<<endl;
}
int it_s_too_hard(){
	int tt=1;
	iossy;
	For(i,1,tt){
		I_can_t_solve_it();
	}
	return 0;
}
