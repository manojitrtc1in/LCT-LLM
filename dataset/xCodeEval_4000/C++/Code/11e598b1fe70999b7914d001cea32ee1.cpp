



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
struct Point{
	ll x,y;
	double ang;
	Point(ll x=0,ll y=0):x(x),y(y) {}
	Point operator - (const Point &a)const { return Point(x-a.x,y-a.y);}
};
ll Cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x;}
int n; 
Point o;
Vector v1,v2;
bool cmp(Point a,Point b){
	return a.ang<b.ang;
}
Point p[2050],tp[5050];
void I_can_t_solve_it(){
	cin>>n;
	ll ans=0,cnt1,l,r,ct;
	For(i,1,n) cin>>p[i].x>>p[i].y;
	For(i,1,n){
		For(j,1,n) {
			if(j==i) continue;
			if(j>i) tp[j-1]=p[j]-p[i],tp[j-1].ang=atan2(tp[j-1].y,tp[j-1].x);
			else tp[j]=p[j]-p[i],tp[j].ang=atan2(tp[j].y,tp[j].x);
		}
		ct=n-1;cnt1=1;
		sort(tp+1,tp+ct+1,cmp);
		For(j,1,ct) tp[j+ct]=tp[j];
		For(j,1,ct){
			if(j>cnt1) cnt1=j;
			if(cnt1>ct*2) break;
			while(cnt1-j+2<=ct && cnt1<ct*2 && Cross(tp[j],tp[cnt1+1])>0) cnt1++;
			l=cnt1-j;r=n-1-l-1;
			ans+=l*(l-1)*r*(r-1)/4;
		}
	}
	cout<<ans/2<<endl;
	
}
int it_s_too_hard(){
	int t=1;
	iossy;
	For(i,1,t){
		I_can_t_solve_it();
	}
	return 0;
}
