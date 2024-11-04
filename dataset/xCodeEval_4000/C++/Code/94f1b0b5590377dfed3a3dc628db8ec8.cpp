#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pp;

#define sz(v) ((v).size())
#define vc(r) vector< r >
#define mk(a,b) make_pair(a,b)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(v,it) for(typeof((v).begin()) it = (v).begin(); it != (v).end() ; it++)
#define vpresent(v,x) ((v).find(x) != (v).end())
#define present(v,x) (find(all(v),x) != (v).end())

#define MOD 1000000007

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
 
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >>n;

	ll arr[n][n];
	ll zero_count = 0;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = s[j] - '0';
			if(arr[i][j]==0) zero_count++;
		}
	}

	if(zero_count == n*n){
		cout << 0 << endl;
		return 0;
	}

	vl zero_r[n],zero_c[n],zero_d1[2*n-1],zero_d2[2*n-1];
	vl prod_r[n],prod_c[n],prod_d1[2*n-1],prod_d2[2*n-1];
	vl prod_r1[n],prod_c1[n],prod_d11[2*n-1],prod_d21[2*n-1];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int y = n-i+j-1;
			int z = i+j;

			if(arr[i][j] == 0){
				zero_r[i].pb(j);
				zero_c[j].pb(i);
				if(y >= n) zero_d1[y].pb(i);
				else zero_d1[y].pb(j);
				if(z >= n) zero_d2[z].pb(n-1-j);
				else zero_d2[z].pb(i);

				if(j-1 < 0) prod_r[i].pb(0);
				else prod_r[i].pb(prod_r[i][j-1]);
				if(i-1 < 0) prod_c[j].pb(0);
				else prod_c[j].pb(prod_c[j][i-1]);
				if(y >= n){
					if(i-1 < 0) prod_d1[y].pb(0);
					else prod_d1[y].pb(prod_d1[y][i-1]);
				}
				else{
					if(j-1 < 0) prod_d1[y].pb(0);
					else prod_d1[y].pb(prod_d1[y][j-1]);
				}
				if(z >= n){
					if(n-j-2 < 0) prod_d2[z].pb(0);
					else prod_d2[z].pb(prod_d2[z][n-j-2]);
				}
				else{
					if(i-1 < 0) prod_d2[z].pb(0);
					else prod_d2[z].pb(prod_d2[z][i-1]);
				}

				if(j-1 < 0) prod_r1[i].pb(0);
				else prod_r1[i].pb(prod_r1[i][j-1]);
				if(i-1 < 0) prod_c1[j].pb(0);
				else prod_c1[j].pb(prod_c1[j][i-1]);
				if(y >= n){
					if(i-1 < 0) prod_d11[y].pb(0);
					else prod_d11[y].pb(prod_d11[y][i-1]);
				}
				else{
					if(j-1 < 0) prod_d11[y].pb(0);
					else prod_d11[y].pb(prod_d11[y][j-1]);
				}
				if(z >= n){
					if(n-j-2 < 0) prod_d21[z].pb(0);
					else prod_d21[z].pb(prod_d21[z][n-j-2]);
				}
				else{
					if(i-1 < 0) prod_d21[z].pb(0);
					else prod_d21[z].pb(prod_d21[z][i-1]);
				}
			}
			else{
				if(arr[i][j]==2){
					if(j-1 < 0) prod_r[i].pb((1)%MOD);
					else prod_r[i].pb((prod_r[i][j-1]+1)%MOD);
					if(i-1 < 0) prod_c[j].pb((1)%MOD);
					else prod_c[j].pb((prod_c[j][i-1]+1)%MOD);
					if(y >= n){
						if(i-1 < 0) prod_d1[y].pb((1)%MOD);
						else prod_d1[y].pb((prod_d1[y][i-1]+1)%MOD);
					}
					else{
						if(j-1 < 0) prod_d1[y].pb((1)%MOD);
						else prod_d1[y].pb((prod_d1[y][j-1]+1)%MOD);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d2[z].pb((1)%MOD);
						else prod_d2[z].pb((prod_d2[z][n-j-2]+1)%MOD);
					}
					else{
						if(i-1 < 0) prod_d2[z].pb((1)%MOD);
						else prod_d2[z].pb((prod_d2[z][i-1]+1)%MOD);
					}
					if(j-1 < 0) prod_r1[i].pb(0);
					else prod_r1[i].pb(prod_r1[i][j-1]);
					if(i-1 < 0) prod_c1[j].pb(0);
					else prod_c1[j].pb(prod_c1[j][i-1]);
					if(y >= n){
						if(i-1 < 0) prod_d11[y].pb(0);
						else prod_d11[y].pb(prod_d11[y][i-1]);
					}
					else{
						if(j-1 < 0) prod_d11[y].pb(0);
						else prod_d11[y].pb(prod_d11[y][j-1]);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d21[z].pb(0);
						else prod_d21[z].pb(prod_d21[z][n-j-2]);
					}
					else{
						if(i-1 < 0) prod_d21[z].pb(0);
						else prod_d21[z].pb(prod_d21[z][i-1]);
					}
				}
				else if(arr[i][j]==3){
					if(j-1 < 0) prod_r1[i].pb((1)%MOD);
					else prod_r1[i].pb((prod_r1[i][j-1]+1)%MOD);
					if(i-1 < 0) prod_c1[j].pb((1)%MOD);
					else prod_c1[j].pb((prod_c1[j][i-1]+1)%MOD);
					if(y >= n){
						if(i-1 < 0) prod_d11[y].pb((1)%MOD);
						else prod_d11[y].pb((prod_d11[y][i-1]+1)%MOD);
					}
					else{
						if(j-1 < 0) prod_d11[y].pb((1)%MOD);
						else prod_d11[y].pb((prod_d11[y][j-1]+1)%MOD);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d21[z].pb((1)%MOD);
						else prod_d21[z].pb((prod_d21[z][n-j-2]+1)%MOD);
					}
					else{
						if(i-1 < 0) prod_d21[z].pb((1)%MOD);
						else prod_d21[z].pb((prod_d21[z][i-1]+1)%MOD);
					}
					if(j-1 < 0) prod_r[i].pb(0);
					else prod_r[i].pb(prod_r[i][j-1]);
					if(i-1 < 0) prod_c[j].pb(0);
					else prod_c[j].pb(prod_c[j][i-1]);
					if(y >= n){
						if(i-1 < 0) prod_d1[y].pb(0);
						else prod_d1[y].pb(prod_d1[y][i-1]);
					}
					else{
						if(j-1 < 0) prod_d1[y].pb(0);
						else prod_d1[y].pb(prod_d1[y][j-1]);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d2[z].pb(0);
						else prod_d2[z].pb(prod_d2[z][n-j-2]);
					}
					else{
						if(i-1 < 0) prod_d2[z].pb(0);
						else prod_d2[z].pb(prod_d2[z][i-1]);
					}
				}
				else{
					if(j-1 < 0) prod_r[i].pb(0);
					else prod_r[i].pb(prod_r[i][j-1]);
					if(i-1 < 0) prod_c[j].pb(0);
					else prod_c[j].pb(prod_c[j][i-1]);
					if(y >= n){
						if(i-1 < 0) prod_d1[y].pb(0);
						else prod_d1[y].pb(prod_d1[y][i-1]);
					}
					else{
						if(j-1 < 0) prod_d1[y].pb(0);
						else prod_d1[y].pb(prod_d1[y][j-1]);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d2[z].pb(0);
						else prod_d2[z].pb(prod_d2[z][n-j-2]);
					}
					else{
						if(i-1 < 0) prod_d2[z].pb(0);
						else prod_d2[z].pb(prod_d2[z][i-1]);
					}

					if(j-1 < 0) prod_r1[i].pb(0);
					else prod_r1[i].pb(prod_r1[i][j-1]);
					if(i-1 < 0) prod_c1[j].pb(0);
					else prod_c1[j].pb(prod_c1[j][i-1]);
					if(y >= n){
						if(i-1 < 0) prod_d11[y].pb(0);
						else prod_d11[y].pb(prod_d11[y][i-1]);
					}
					else{
						if(j-1 < 0) prod_d11[y].pb(0);
						else prod_d11[y].pb(prod_d11[y][j-1]);
					}
					if(z >= n){
						if(n-j-2 < 0) prod_d21[z].pb(0);
						else prod_d21[z].pb(prod_d21[z][n-j-2]);
					}
					else{
						if(i-1 < 0) prod_d21[z].pb(0);
						else prod_d21[z].pb(prod_d21[z][i-1]);
					}
				}
			}

		}
	}

	

	vc(vc(pp)) ans(n,vc(pp)(n,mk(0,0)));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(arr[i][j] == 0) continue;
			int y = n-i+j-1;
			int z = i+j;

			ll i2 = lower_bound(all(zero_c[j]),i)-zero_c[j].begin();
			ll i1;
			if(i2 < zero_c[j].size()){
				if(i2 != 0) i1 = zero_c[j][i2-1];
				else i1 = -1;
				i2 = zero_c[j][i2]-1;
			}
			else{
				i2 = n-1;
				if(zero_c[j].size() != 0) i1 = zero_c[j][zero_c[j].size()-1];
				else i1 = -1;
			}

			ll j2 = lower_bound(all(zero_r[i]),j)-zero_r[i].begin();
			ll j1;
			if(j2 < zero_r[i].size()){
				if(j2 != 0) j1 = zero_r[i][j2-1];
				else j1 = -1;
				j2 = zero_r[i][j2]-1;
			}
			else{
				j2 = n-1;
				if(zero_r[i].size() != 0) j1 = zero_r[i][zero_r[i].size()-1];
				else j1 = -1;
			}

			ll mm = min(min(abs(i-i2),abs(i-i1-1)),min(abs(j-j2),abs(j-j1-1)));
			pp temp1=mk(0,0),temp2=mk(0,0);
			temp1.first += (prod_c[j][i+mm]-(((i-mm-1)!=-1)?(prod_c[j][i-mm-1]):0));
			temp1.second += (prod_c1[j][i+mm]-(((i-mm-1)!=-1)?(prod_c1[j][i-mm-1]):0));

			temp1.first += (prod_r[i][j+mm]-(((j-mm-1)!=-1)?(prod_r[i][j-mm-1]):0));
			temp1.second += (prod_r1[i][j+mm]-(((j-mm-1)!=-1)?(prod_r1[i][j-mm-1]):0));

			ll index = i;
			if(y < n) index = j;
			i2 = lower_bound(all(zero_d1[y]),index)-zero_d1[y].begin();
			i1=0;
			if(i2 < zero_d1[y].size()){
				if(i2 != 0) i1 = zero_d1[y][i2-1];
				else i1 = -1;
				i2 = zero_d1[y][i2]-1;
			}
			else{
				i2 = prod_d1[y].size()-1;
				if(zero_d1[y].size() != 0) i1 = zero_d1[y][zero_d1[y].size()-1];
				else i1 = -1;
			}

			ll index1 = n-j-1;
			if(z < n) index1 = i;
			j2 = lower_bound(all(zero_d2[z]),index1)-zero_d2[z].begin();
			j1 = 0;
			if(j2 < zero_d2[z].size()){
				if(j2 != 0) j1 = zero_d2[z][j2-1];
				else j1 = -1;
				j2 = zero_d2[z][j2]-1;
			}
			else{
				j2 = prod_d2[z].size()-1;
				if(zero_d2[z].size() != 0) j1 = zero_d2[z][zero_d2[z].size()-1];
				else j1 = -1;
			}

			mm = min(min(abs(index-i2),abs(index-i1-1)),min(abs(index1-j2),abs(index1-j1-1)));
			

			temp2.first += (prod_d1[y][index+mm]-(((index-mm-1)!=-1)?(prod_d1[y][index-mm-1]):0));
			temp2.second += (prod_d11[y][index+mm]-(((index-mm-1)!=-1)?(prod_d11[y][index-mm-1]):0));

			temp2.first += (prod_d2[z][index1+mm]-(((index1-mm-1)!=-1)?(prod_d2[z][index1-mm-1]):0));
			temp2.second += (prod_d21[z][index1+mm]-(((index1-mm-1)!=-1)?(prod_d21[z][index1-mm-1]):0));

			if(arr[i][j] == 2){
				temp1.first--;
				temp2.first--;
			}
			else if(arr[i][j]==3){
				temp1.second--;
				temp2.second--;
			}

			double e1 = (1.0*(temp1.first-temp2.first)*log(2) + 1.0*(temp1.second - temp2.second)*log(3));
			

			if(e1 > 0) ans[i][j] = temp1;
			else ans[i][j] = temp2;
		}
	}
	

	pp max1 = mk(0,0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			double e1 = (1.0*(ans[i][j].first-max1.first)*log(2) + 1.0*(ans[i][j].second - max1.second)*log(3));
			if(e1 > 0) max1 = ans[i][j];
		}
	}

	cout << (power(2,max1.first)*power(3,max1.second))%MOD << endl;
	return 0;
}