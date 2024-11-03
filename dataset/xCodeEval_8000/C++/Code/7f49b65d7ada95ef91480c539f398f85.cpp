#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

const int N = 1e5 + 9;

vector<ll> v[N];

int m = 0;

ll check(int x){
	int need = x - v[0].size();
	ll res = 0;
	vector<ll> f;
	for(int i = 1;i <= m ;i++)
	 for(int j = 0;j < v[i].size();j++){
	 	 if(v[i].size() - j >= x){
	 	 	res += v[i][j];
	 	 	--need;
		  }
		  else f.push_back(v[i][j]);
	 }
	 sort(f.begin(),f.end());

	 for(int k = 0;k <need;k++)
	 	res += f[k];
    return res;
}

int main(){
	int n,a;
	ll b;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %lld",&a,&b);
		m = max(m,a);
		v[a].push_back(b);
	}

	for(int i = 1;i <= m;i++) sort(v[i].begin(),v[i].end());

	int l = 0,r = n;
	while(l + 1 < r){
		int ml = (l + r) >> 1;
		int mr = (ml + r) >> 1;
		if(check(ml) > check(mr))
            l = ml;
		else r = mr;
	}
	printf("%d\n",check(r));
	return 0;
}























































































































































































































