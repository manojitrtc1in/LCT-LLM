

#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 2000000000
#define MOD 1000000007
#define N 194698
#define MAX 5032117	
#define LOG 30
#define KOK 200
using namespace std;

int x,n,ans=1;
set<int> L,M,R;

int main() {

	


	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		char s[20];

		scanf("%s %d",s+1,&x);

		if(s[2]=='C') {

			if((sz(L) && x<*L.rbegin()) || (sz(R) && x>*R.begin())) {

				printf("0");

				return 0;

			}

			if(sz(L) && x==*L.rbegin()) {

				L.erase(L.find(x));

				for(auto val:M) R.insert(val);

				M.clear();

			}
			else if(sz(R) && x==*R.begin()) {

				R.erase(R.find(x));

				for(auto val:M) L.insert(val);

				M.clear();

			}
			else {

				ans=ans*2%MOD;

				for(auto val:M) {

					if(val<x) L.insert(val);
					if(val>x) R.insert(val);

				}

				M.clear();

			}

		}
		else {

			if(sz(L) && x<*L.rbegin()) L.insert(x);
			else if(sz(R) && x>*R.begin()) R.insert(x);
			else M.insert(x);

		}

	}

	if(sz(M)) ans=1ll*ans*(sz(M)+1)%MOD;

	printf("%d",ans);

}
