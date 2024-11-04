






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

void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;




void solve(){ 

int h;
cin>>h;
int n=0;
vector<int> a(h+1); 

fr(i,0,h+1){
	cin>>a[i]; n+=a[i];
}
vector<int> t1(n);
fr(i,0,h){
	if(a[i]>1 && a[i+1]>1){
		cout<<"ambiguous\n";
		int node=0,parent=0,flag;
		for(int j=0;j<=h;++j){
			while(a[j]--) t1[node++] = parent;
			parent=node; 
			

			

			

			

			if(j==i) {flag=node;} 

		}
		debug_arr(t1);

		

		fr(j,0,node) 

			{   if(t1[j]==flag){ cout<<flag-1<<" "; flag = -10; }
				

				

				

				else	cout<<t1[j]<<" ";
			}
			cout<<endl;
			t1.clear();
			return;

		}
	}
		
	cout<<"perfect\n";
	

 
  
  return;} 




signed main() {
	

	

	{solve();}
	
	return 0;
}





















