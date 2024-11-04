#include<bits/stdc++.h>
#define MOD 1e9+7
#define PR 998244353
#define INF INT_MAX
#define endl "\n"
#define newl cout<<"\n"
#define space cout<<" "
#define bar cout<<"-"
#define mt make_tuple 
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define vi vector<lli>
#define pll pair <lli,lli>
#define vpi vector<pll >
#define all(p) p.begin(),p.end()
#define lli long long int
#define sz(a) int((a).size())
#define form(i, l, r) for (i = l; i > r; --i)
#define forl(i, l, r) for (i = l; i < r; ++i)
#define pat(i, l, r, a); for (i = l; i < r; ++i){cout<<a[i]<<" ";}cout<<endl;
#define ppt(i, l, r, a); for (i = l; i < r; ++i){cout<<a[i].ff<<"-"<<a[i].ss<<" ";}cout<<endl;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 




 




 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 




 








 






 




 






 






 
















const int N=1000; 

inline lli powmod(lli base,lli exponent,lli mod=(1e9+7))
{ 
	lli ans=1;
	while(exponent)
	{
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent>>=1;
	}
	return ans;
}

lli fs[N][N]={{1,1,1},{1,0,0},{0,1,0}};
lli cs[N][N]={{1,1,1,2,-4},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};





lli temp[N][N];
lli ret[N][N];

void matmod(lli n,lli exponent,lli arr[N][N])
{
	lli i,j,k,ans,mod=MOD-1;
	while(exponent>0)
	{
		if(exponent&1) 
		{
			forl(i,0,n)
			{
				forl(j,0,n)
				{
					ans=0;
					forl(k,0,n)
					{
						ans+=ret[i][k]*(arr)[k][j];
						ans%=mod;
					}
					temp[i][j]=ans;
				}
			}
			forl(i,0,n)
			{
				forl(j,0,n) ret[i][j]=temp[i][j];
			}
		}

		exponent>>=1;
		forl(i,0,n)
		{
			forl(j,0,n)
			{
				ans=0;
				forl(k,0,n)
				{
					ans+=(arr)[i][k]*(arr)[k][j];
					ans%=mod;
				}
				temp[i][j]=ans;
			}
		}
		forl(i,0,n)
		{
			forl(j,0,n) (arr)[i][j]=temp[i][j];
		}
	}
}


















































vi Pr;
vector<vector<int>> vst(200009);
inline void siv(lli n)
{
	lli i,p;
	vector <bool> prime(n,1);

	for (p=2; p<=n; p++) 
	{ 
		if (prime[p] == true)
		{ 
			Pr.push_back(p);
			for (i=p; i<=n; i += p)

			{
				prime[i] = false;
				vst[i].pb(p);
			} 
		} 
	} 
	

	

	

	

	

	

	

	

}





































































int main() 
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli t,a,b,c,d,e,q,h,i,j,k,n,m,n1,n2,n3;
	lli mod=MOD, inf=LLONG_MAX, pr=998244353;
	siv(200005);
	for(cin>>t;t--;newl)
	{
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		cin>>n;
		lli ar[n];
		
		forl(i,0,n) cin>>ar[i];
		sort(ar,ar+n);
		
		lli prev=0;
		unordered_map<lli,lli> mp;
		vi alf;
		lli ans=-1;
		

		forl(k,0,n)
		{
			b=ar[k];
			if(b==prev)
			{
				mp[b]=mp[b]+1;
				

			}
			else 
			{
				alf.pb(1);
				

				for(auto x:vst[b])
				{
					

					lli tp=x;
					vi v2;
					while(b%x==0)
					{
						v2.pb(x);
						x*=tp;
					}
					n1=sz(alf);n2=sz(v2);
					forl(i,0,n1)
					{
						forl(j,0,n2)
						{
							alf.pb(alf[i]*v2[j]);
						}
					}
				}
				

				lli cur=-1;
				forl(i,0,sz(alf))
				{
					cur=max(cur,mp[alf[i]]);
				}
				mp[b]=cur+1;
			}
			prev=b;
			

			alf.clear();	
			ans=max(ans,mp[b]);
		}
		cout<<n-ans;







		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		














		
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		




		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

 
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

	}
}



