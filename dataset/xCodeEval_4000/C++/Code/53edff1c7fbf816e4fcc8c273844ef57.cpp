







#include <bits/stdc++.h>
using namespace std;


#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;
int n,k;
v(v(int)) graph;
v(int) course;
v(int) ans,color; 

int cycle=0;

void dfs(int s){
	color[s]=1;
	for(auto v:graph[s]){
		if(color[v]==0){
			color[v] = 1;
			dfs(v);
			color[v]=2;
		}
		else if (color[v]==1){ cycle=1; }
	}
	color[s]=2;
	ans.pb(s);
}



void solve(){ 
cin>>n>>k;
color.resize(n+1);
graph.resize(n+1);

course.resize(k);
fr(i,0,k){
	cin>>course[i];
}
fr(i,1,n+1){
int a; cin>>a;
fr(j,0,a){
	int x; cin>>x;
	graph[i].pb(x);

}
}
fr(i,0,k){
	if(!color[course[i]] && !cycle) {
		dfs(course[i]);

	}
}
if(cycle) {cout<<-1<<endl; return;}

cout<<ans.size()<<endl;
debug_arr(ans);

  
  return;} 




signed main() {
	

	fast
	

	{solve();}
	
	return 0;
}






















