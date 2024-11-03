





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

int x[100500];

int main()
{
	

	

	IOS;

	int a;
	cin >> a;
	
	if ( a == 1 ){
		cout << 1 << endl << 1;
		return 0;
	}
	
	if ( a % 2 == 0 ){
		cout << a / 2 << endl;
		for ( int i=1 ; i<=a/2 ; i++ ){
			cout << 2 << " ";
		}
	}
	else if ( a % 3 == 0 ){
		cout << a / 3 << endl;
		for ( int i=1 ; i<=a/3 ; i++ ){
			cout << 3 << " ";
		}
	}
	else if ( a % 5 == 0 ){
		cout << a / 5 << endl;
		for ( int i=1 ; i<=a/5 ; i++ ){
			cout << 5 << " ";
		}
	}
	
	else{
		cout << a << endl;
		for ( int i=1 ; i<=a ; i++ ){
			cout << 1 << " ";
		}
	}
		
	return 0;
}

