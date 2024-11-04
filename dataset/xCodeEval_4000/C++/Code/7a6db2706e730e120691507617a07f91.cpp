



#include <bits/stdc++.h>






#define ll long long






#define pb push_back

using namespace std;










int main()








{








	ll n , m ,d ;








	cin>>n>>m>>d;












	map < ll, ll  > mp  ;








	ll ans [n];






	ll a [n];








	ll i ;
















	for (i=0 ; i<n ;i++)






	{






		cin>>a[i] ;








		mp.insert(make_pair(a[i],i));








	}






	int day = 1 ;


















	while (!mp.empty())










	{
		map  <ll ,ll>  :: iterator itr ;








		bool valid = true ;






		itr = mp.begin();










		ans [itr -> second] = day;








		int curr = itr -> first;














		mp.erase(itr);
		













		while (valid)








		{






			int val = curr + d +1 ;








			itr = mp.lower_bound(val);














			if (itr == mp.end() || itr->first > m )






			{






				day ++ ;










				valid = false ;






			}






			else












			{
				ans [itr->second] = day ;








				curr = itr->first;






				mp.erase(itr);










			}
		}






	}











	cout<<day-1<<endl;











	for (i=0 ; i<n ;i++)










		cout<<ans[i]<<" ";






	

	return 0;






}
