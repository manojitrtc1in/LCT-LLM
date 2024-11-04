



























































































































































































































































































































































































































































































































































#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int max1 = 10000 + 10;
vector < int > v [ max1 ];
vector < pair <int , int> > pos;
bool flag [ max1 ] , flag2 [ max1 ] , flag3;
int ar2 [ max1 ] , ar [ max1 ] , n , f = -1 , l = 10000 , count1 = 0;
int ghadr(int n)
{
	if(n < 0)
		return -n;
	return n;
}
bool DFS( int s , int a ) {
	for(int i = 0 ; i < v[ s ].size() ; i++)
	{
		if(ar2 [ v[ s ][ i ] ] == -1)
		{
			ar2 [ v[ s ][ i ] ] = (a + 1) % 2;
			if(DFS(v[ s ][ i ] , ar2[v[ s ][ i ]]) == false)
				return false;
		}
		else if(ar2 [ v[ s ][ i ] ] != (a+1) % 2)
		{
			return false;
		}	
	}
	return true;
}
void dfs( int a )
{
	flag2 [ a ] = true;
	for(int i = 0 ; i < v [ a ].size() ; i++)
	{
		if(flag2 [ v [ a ] [ i ] ] == false)
		{
			dfs( v [ a ] [ i ]);
		}
	}
}
bool dojob(int x , bool bb)
{
	for(int i = 0 ; i < max1 ; i++)
		ar2 [ i ] = - 1;
	for(int i = 0 ; i < n ; i++ )
		v [ i ].clear();
	for(int i = 0 ; i < pos.size() ; i++)
	{
		for(int j = i + 1 ; j < pos.size() ; j++)
		{
			if( ghadr(pos[ i ].first - pos[ j ].first) + ghadr(pos [ i ].second - pos [ j ].second ) > x )
			{
				v [ i ].push_back(j);
				v [ j ].push_back(i);
			}	
		}
	}
	if(bb == false)
	{
	for(int i = 0 ; i < n ; i++)
	{
		if(ar2 [ i ] == -1)
		{
				ar2 [ i ] = 0;
				if(DFS(i , 0) == false)
					return false;
		}
	}
	}
	else
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(flag2 [ i ] == false)
			{
				count1++;
				dfs( i );
			}
		}
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a , b;
		cin >> a >> b;
		pos.push_back(make_pair(a, b));
	}
	while(l - f > 1)
	{
		int mid = (l + f) / 2;
		int a = dojob( mid , false);
		if(a == 1)
			l = mid;
		else
			f = mid;	
	}
	cout << l << endl;
	dojob(l , true);
	long long int tavan = 1;
	for(int i = 0 ; i < count1 ; i++)
	{
		tavan *= 2;
		tavan = tavan % (1000000000 + 7);
	}
	cout << tavan;
}