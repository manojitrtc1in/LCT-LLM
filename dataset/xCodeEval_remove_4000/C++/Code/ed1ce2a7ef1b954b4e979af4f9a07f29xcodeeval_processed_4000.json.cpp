














































using namespace std;















int main id0  id2   jWEH5wdkwIL2DbhCh9DRnXv 

	ll n;
	cin>>n;
 
	ll a id1 2 id3  id1 n id3 ;
	take(a[0]);
	take(a[1]);
	 jmsdfkWQEr22FSD234SDFFwasd  id0 n KlopQXZvnuiuasdbbnbdsaioqw 1 id2 
	 jWEH5wdkwIL2DbhCh9DRnXv 
		 ZPokVjqwsadLasdhjysad <<a id1 1 id3  id1 0 id3 <<endl;
		return 0;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	ll up id1 n id3 ;
	ll j=2;
	ll sum=a id1 0 id3  id1 n-1 id3 +a id1 1 id3  id1 n-1 id3 ;
	ll y id1 n id3 ;
	y id1 n-1 id3 =sum;
	up id1 n-1 id3 =a id1 0 id3  id1 n-1 id3 + id0 j*a id1 1 id3  id1 n-1 id3  id2 ;
	j=j+2;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh  id0 ll i=n-2;i>=0;i-- id2 
	 jWEH5wdkwIL2DbhCh9DRnXv 
		up id1 i id3 =up id1 i+1 id3 +a id1 0 id3  id1 i id3 + id0 j*a id1 1 id3  id1 i id3  id2 +sum;
		sum+=a id1 0 id3  id1 i id3 +a id1 1 id3  id1 i id3 ;
			y id1 i id3 =sum;
			j=j+2;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	ll down id1 n id3 ;
	 j=2;
	 sum=a id1 0 id3  id1 n-1 id3 +a id1 1 id3  id1 n-1 id3 ;
	down id1 n-1 id3 = id0 j*a id1 0 id3  id1 n-1 id3  id2 + id0 a id1 1 id3  id1 n-1 id3  id2 ;
	j=j+2;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh  id0 ll i=n-2;i>=0;i-- id2 
	 jWEH5wdkwIL2DbhCh9DRnXv 
		down id1 i id3 =down id1 i+1 id3 + id0 j*a id1 0 id3  id1 i id3  id2 + id0 a id1 1 id3  id1 i id3  id2 +sum;
		sum+=a id1 0 id3  id1 i id3 +a id1 1 id3  id1 i id3 ;
			j=j+2;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	ll ans=up id1 1 id3 + id0  id0 2*n-1 id2 *a id1 1 id3  id1 0 id3  id2 ;
	ll su=a id1 1 id3  id1 0 id3 ;
	ll count=1;
	ans=max id0 ans,a id1 1 id3  id1 0 id3 +down id1 1 id3 +y id1 1 id3  id2 ;
	 iuasiudiaosudjbppjbnbcxhgjhjhsgdgjh  id0 ll i=1;i<n-1;i++ id2 
	 jWEH5wdkwIL2DbhCh9DRnXv 
		 jmsdfkWQEr22FSD234SDFFwasd  id0 i%2 KlopQXZvnuiuasdbbnbdsaioqw 1 id2 
		 jWEH5wdkwIL2DbhCh9DRnXv 
		su+= id0 count+1 id2 *a id1 1 id3  id1 i id3 + id0 count+2 id2 *a id1 0 id3  id1 i id3 ;
		count+=2;
		ll temp=su+up id1 i+1 id3 + id0 y id1 i+1 id3 *count id2 ;
		ans=max id0 ans,temp id2 ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
		 jmsdfkWQEr22FSD234SDFFwasd  id0 i%2 KlopQXZvnuiuasdbbnbdsaioqw 0 id2 
		 jWEH5wdkwIL2DbhCh9DRnXv 
			su+= id0 count+1 id2 *a id1 0 id3  id1 i id3 + id0 count+2 id2 *a id1 1 id3  id1 i id3 ;
			count+=2;
			ll temp=su+down id1 i+1 id3 + id0 y id1 i+1 id3 *count id2 ;
			ans=max id0 ans,temp id2 ;
		 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	 ZPokVjqwsadLasdhjysad <<ans<<endl;
	return 0;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 