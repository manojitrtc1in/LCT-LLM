



































































































































































































































































































































































































































































































































































using namespace std;
const int MAXN = 1e2;
char ch[ MAXN ][ MAXN ];
map < char , char > mp;
	int n , m , ans = 0;
bool ok( int a , int b)
{
	if(a < n && b < m)
	{
		if(a >= 0 && b >=0)
			if(ch [ a ][ b ] != '
				return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);

	string s;
	pair < int , int > s1 , e , pos;
	cin >> n>> m;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			cin >> ch [ i ] [ j ];
			if(ch [ i ][ j ] == 'S')
				s1 = make_pair(i , j);
			if(ch [ i ][ j ] == 'E')
				e = make_pair( i , j);
		}
	}
	cin >> s;
	for(int i = 0 ; i < 4 ; i++)
	{
		mp [ i + '0'] = 'u';
		
		for(int j = 0 ; j < 4 ; j++)
		{
			if(j != i)
			{
				mp [ j + '0'] = 'd';
				for(int x = 0 ; x < 4 ; x++)
				{
					if(x != i && x != j)
					{
						mp [ x + '0' ] = 'r';
							for(int y = 0 ; y < 4 ; y++)
							{
								pos = s1;
								if(y != i && (y != x && y != j))
								{
									bool flag = false;
									mp [ y + '0'] = 'l';
									for(int g = 0 ; g < s.size() ; g++)
									{
										int x1 = 0, y1= 0;
										if(mp [ s [ g ]] == 'l')
											y1 = -1;
										if(mp [ s [ g ]] == 'r')
										y1 = 1;
										if(mp [ s [ g ]] == 'd')
										x1 = 1;
										if(mp [ s [ g ]] == 'u')
										x1 = -1;	
										if(ok(pos.first + x1 , pos.second + y1))
										{
											pos.first += x1;
											pos.second += y1;
											if(pos == e)
											{
												ans++;
												break;
											}	
										}
										else
											break;

									}
									

								}
							}
					}
				}	
			}	
		}
	}
	cout << ans;
}