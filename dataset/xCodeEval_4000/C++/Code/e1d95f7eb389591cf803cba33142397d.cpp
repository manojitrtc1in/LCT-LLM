


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define eps 1e-5
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fore(i,a,b) for(int i=a;i>=b;i--)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mkp make_pair
#define pb push_back
#define sz size()
#define met(a,b) memset(a,b,sizeof(a))
#define iossy ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fr freopen
#define pi acos(-1.0)
#define Vector Point
typedef pair<int,int> pii;
const long long linf=1LL<<62;
const int iinf=1<<30;
const double dinf=1e17;
const int Mod=1e9+9;
typedef long long ll;
typedef long double ld;
const int maxn=1000005;
int a[maxn];
char s[maxn];
int n;
struct Point{
	ll x,y;
	int id;
	Point(ll x=0,ll y=0):x(x),y(y) {}
	Point operator - (const Point &a)const { return Point(x-a.x,y-a.y);}
	bool operator == (const Point &a)const { return x==a.x && y==a.y; }
	bool operator < (const Point &a)const { if(x==a.x) return y<a.y; return x<a.x; }
	bool operator != (const Point &a)const {return x!=a.x || y!=a.y;}
};
ll Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
ll Dot(Vector a,Vector b) {
	return a.x*b.x+a.y*b.y;
}
bool onsg(Point p,Point a1,Point a2){
	return Cross(a1-p,a2-p)==0 && Dot(a1-p,a2-p)<0;
}
void ck(ll &c){
	if(c>0) c=1;
	else if(c<0) c=-1;
}
int Ins(Point a1,Point a2,Point b1,Point b2){
	if(a1==b1 || a1==b2 || a2==b1 || a2==b2) return 1;
	if(onsg(a1,b1,b2) || onsg(a2,b1,b2) || onsg(b1,a1,a2) || onsg(b2,a1,a2)) return 1;
	ll c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	ll c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	ck(c1);ck(c2);ck(c3);ck(c4);
	return c1*c2<0 && c3*c4<0;
}
int dcmp(double x){
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
set<pair<ll,ll> >c;
void chk(Point p,Vector p1,Point q,Vector q1){
	ll d1=Cross(q1-q,q-p),d2=Cross(q1-q,p1-p);
	if(abs(d1*(p1.x-p.x))%abs(d2)!=0 || abs(d1*(p1.y-p.y))%abs(d2)!=0) return ;
	ll xx,yy;
	xx=p.x+(p1.x-p.x)*d1/d2;
	yy=p.y+(p1.y-p.y)*d1/d2;
	c.insert(mkp(xx,yy));
}
struct segm{
	Point p1,p2;
	bool operator < (const segm &S)const{ 
		if(p1==S.p1) return p2<S.p2;
		return p1<S.p1;
	}
};
segm ss[maxn],st[maxn];
Point p1,p2;
int vis[maxn],ct;
void solve(){
	iossy;
	cin>>n;met(vis,0);ct=0;
	int ans=0;
	For(i,1,n){
		cin>>p1.x>>p1.y>>p2.x>>p2.y;
		if(p2<p1) swap(p1,p2);
		ss[i].p1=p1;ss[i].p2=p2;
		ans+=__gcd(abs(ss[i].p2.x-ss[i].p1.x),abs(ss[i].p2.y-ss[i].p1.y))+1;
	}
	
	For(i,1,n){
		c.clear();
		For(j,i+1,n){
			if(Cross(ss[i].p1-ss[i].p2,ss[j].p1-ss[j].p2)==0) continue;	
			int ct=Ins(ss[i].p1,ss[i].p2,ss[j].p1,ss[j].p2);
			if(ct) chk(ss[i].p1,ss[i].p2,ss[j].p1,ss[j].p2);
		}
		ans-=c.sz;
	}
	

	cout<<ans<<endl;
}
int main(){
    int t=1;
   

	solve();
    return 0;
}
