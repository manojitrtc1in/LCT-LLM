



























































































































































































































































































































































































































































































































































#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 1e5 + 100;
int ans = -1 , st1 , end1;
bool check [ MAXN ] , flag [ MAXN ];
vector < int > v [ MAXN ];
set <pair < int , pair < int , int > > > st;
void bfs (int a)
{
	

	st.insert(make_pair(0 , make_pair(a , 0)));
	while(st.size() > 0)
	{
		int salar = ( *(st.begin())).second.first , alessia = (*(st.begin())).second.second , logic =  (*(st.begin())).first;
		st.erase(st.begin());
		if(flag [ salar ] == false)
		{
			flag [ salar ] = true;
			for(int j = 0 ; j < v [ salar ].size() ; j++)
			{
				if(flag [ v [ salar ][ j ] ] == false)
				{
					if(v [ salar ][ j ] == end1)
					{
				

				

						ans = max(logic + 1 , alessia);
						return ;
					}
					if(check [ v [ salar ][ j ] ] == true)
					{
						st.insert(make_pair(0 , make_pair(v [ salar ][ j ] , max(logic + 1 , alessia))));
					

					if(check [ salar ] == false)
						flag [ salar ] = false;
					}
					else {
						st.insert(make_pair(logic + 1 , make_pair(v [ salar ][ j ] , max(logic + 1 , alessia))));
					

					}
				}
			}
		}
		
	}
}
int main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n , m , k;
	cin >> n >> m >> k;
for(int i = 0 ; i < k ; i++)
	{
		int a;
		cin >> a;
		check [ a ] = true;
	}
	for(int i = 0 ; i < m; i++)
	{
		int a = n , b = i;
		cin >> a >> b;
		v [ a ].push_back(b);
		v [ b ].push_back(a);
	}
	cin >> st1 >> end1;
	bfs(st1);
	cout  << ans;
}