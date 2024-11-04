


































#include <bits/stdc++.h>
using namespace std;
#define fro for
#define itn int
#define mp make_pair
#define pb push_back
#define one first
#define two second
#define fi(n) n.begin()
#define se(n) n.end()
#define all(n) (n).begin(),(n).end()
#define po(n) n.pop()
#define PI 3.141592653
#define son(n) int lf=2*n,ri=2*n+1
#define pr (int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37})
#define sz(n) n.size()
#define big int maxi=-1
#define rep(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define small int mini=1e9+7
#define op(x) freopen(x,"r",stdin)
#define wr(x) freopen(x,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> sti;
typedef set<int> jihe;
typedef queue<int> qi;
typedef vector<pair<int,int> > vp;
typedef priority_queue<int,vector<int>,greater<int> > pqi;
typedef priority_queue<pii,vector<pii>,greater<pii> > pqpi;
const int inf=1e9+7;
const int maxn=5005;
const int maxm=200005;

struct edge{
	int x,y,g,s;
};
int n,m;
ll gc,sc;
edge e[50005];

bool cmpG(edge a,edge b){
	return a.g<b.g;
}

ostream& operator<<(ostream& os,edge& ed){
	os<<"Edge["<<ed.x<<","<<ed.y<<","<<ed.g<<","<<ed.s<<"]";
	return os;
}
template<typename T> ostream& operator<<(ostream& o,vector<T> vec){
	o<<"{";
	for(int i=0;i<vec.size();i++){
		o<<vec[i]<<" ";
	}
	o<<"}";
	return o;
}

vector<edge> v;

int fa[205];
bool del[50005];

int getFa(int pos){
	if(fa[pos]==pos){
		return fa[pos];
	}
	return fa[pos]=getFa(fa[pos]);
}

void Union(int a,int b){
	fa[getFa(a)]=fa[getFa(b)];
}

ll ans=2000000000000000000ll;

int main(int argc,char* argv[]){
	cin>>n>>m>>gc>>sc;
	for(int i=0;i<m;i++){
		cin>>e[i].x>>e[i].y>>e[i].g>>e[i].s;
		e[i].x--;
		e[i].y--;
	}
	
	sort(e,e+m,cmpG);
	
	for(int i=0;i<m;i++){
		
		int gcc=e[i].g;
		int scc=0;
		
		v.push_back(e[i]);
		int p=v.size()-1;
		while(p!=0 && v[p].s<v[p-1].s){
			swap(v[p],v[p-1]);
			p--;
		}
		
		
		for(int j=0;j<n;j++){
			fa[j]=j;
		}
		memset(del,0,sizeof(del));
		
		int cnt=0;
		
		for(int j=0;j<v.size();j++){
			
			if(getFa(v[j].x)==getFa(v[j].y)){
				del[j]=true;
				continue;
			}else{
				Union(v[j].x,v[j].y);
				cnt++;
				scc=v[j].s;
			}
			
			if(cnt==n-1){
				break;
			}
		}
		
		if(cnt==n-1){
			
			
			ans=min(ans,scc*sc+gcc*gc);
		}
		
		int xo=0;
		for(int j=0;j<v.size();j++){
			if(!del[j]){
				 v[xo]=v[j];
				 xo++;
			}
		}
		
		v.resize(xo);
		
	}
	
	cout<<(ans==2000000000000000000ll?-1:ans);
	return 0;
}
