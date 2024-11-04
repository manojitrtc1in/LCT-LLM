





#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define pb push_back


using namespace std;

int Nod ( int a , int b ){
	while ( a && b ){
		if ( a > b ){
			a = a % b;
		}
		else{
			b = b % a;
		}
	}

	return a | b;
}

int main()
{
	

	

	IOS;

	int a , z = 0 , o = 0;
	int x[200010];
	cin >> a;
	
	for ( int i=1 ; i <= a ; i++ ){
		cin >> x[i];
		if(x[i]==0)
		z=i;
		else o=i;
	}
	if(z>=o)
	cout << o;
	else cout << z;

	return 0;
}

