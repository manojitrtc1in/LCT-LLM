
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define IN inline
#define RE register
#define FI first
#define SE second
#define random(x) (rand()%x)
#define maxn 100005
using namespace std;
char op[10];
vi a;
int main(){
	int T,x;
	ll sum;
	scanf("%d",&T);
	while(T--){
		scanf("%s",op);
		if(op[0]=='a'){
			scanf("%d",&x);
			a.insert(lower_bound(a.begin(),a.end(),x),x);
		}else if(op[0]=='d'){
			scanf("%d",&x);
			a.erase(lower_bound(a.begin(),a.end(),x));
		}else if(op[0]=='s'){
			sum=0;
			for(int i=2;i<a.size();i+=5) sum+=a[i];
			printf("%lld\n",sum);
		}else assert(0);
	}
	return 0;
}