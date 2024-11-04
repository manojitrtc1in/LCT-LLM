





#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long


using namespace std;

vector <int> v;

int main()
{
	

	

	IOS;

	long long n , a , d;
	cin >> n;
	
	for ( int i=0 ; i < n ; i++ ){
		cin >> a;
		v.push_back(a);
	}
	sort ( v.begin() , v.end() );
	
	int kol = 0;
	
	for ( int i = 0 ; i < v.size() ; i++ ){
		if ( v[i] > kol ){
			kol++;
		}
	}
	cout << kol;

	return 0;
}

