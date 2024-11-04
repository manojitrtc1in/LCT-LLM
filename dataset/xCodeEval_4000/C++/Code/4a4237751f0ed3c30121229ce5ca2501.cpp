
#include<bits/stdc++.h>

typedef long long ll ;

#define X   first
#define Y   second
#define mp  make_pair
#define pii pair<int , int>
#define vec vector
#define vpii vector<pair<int , int>>
#define i_n   int i = 0 ; i< n ; i++
#define cn  int n ; cin>>n
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cina int a[n] ; for(int i = 0 ; i < n ; i++) cin>>a[i]
#define pb push_back
#define SZ(x) ll(x.size())

using namespace std;
const int maxn = 1000+5 ;

int ans ; 
string s[maxn] ; 
int n , m ; 
pii st ; 
int h[maxn][maxn] , ans1 = 100000000 , mark[maxn][maxn] ,par[maxn][maxn][2] , mc[4] , cnt = 0 ;
pii sc[4] ;  
 
int dis[4][maxn][maxn]  ; 
deque<pii> q ; 
bool val(int x , int y)
{
	if(x <= n && x > 0 && y <= m && y > 0 && s[x][y] != '#' && mark[x][y] != 1) 
	{
		return true ; 
	}
	else return false ; 
}

int valid(int x , int y)
{
	int sum = 0 ; 
	for(int i = 1 ; i <= 3 ; i++)
	{
		if(dis[i][x][y] == -1) return -1 ; 
		else sum += dis[i][x][y] ; 
	}
	 
	return sum ; 
}

int main()
{
	migmig ;
	cin>>n>>m ; 
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>s[i] ; 
		string t = "-" ; 
		t+=s[i] ; 
		s[i] = t;
	}
	

	#define ans ans1
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] == '1') 
			{
				q.pb({i , j}) ; 
				

			}
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		if(s[v.X][v.Y] == '2' && mc[2] == 0)
		{
			mc[2] = 1 ; 
			sc[2]=  v ; 
		}
		if(s[v.X][v.Y] == '3' && mc[3] == 0)
		{
			mc[3] = 1 ; 
			sc[3]= v ; 
		}
		
		if(val(v.X + 1 , v.Y) )
		{
			mark[v.X + 1][v.Y] = 1 ; 
			q.pb({v.X + 1 , v.Y}) ; 
			h[v.X + 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X + 1][v.Y][0] = v.X ; 
			par[v.X + 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X - 1 , v.Y) )
		{
			mark[v.X - 1][v.Y] = 1 ; 
			q.pb({v.X - 1 , v.Y}) ; 
			h[v.X - 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X - 1][v.Y][0] = v.X ; 
			par[v.X - 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  + 1) )
		{
			mark[v.X ][v.Y + 1] = 1 ; 
			q.pb({v.X , v.Y + 1}) ; 
			h[v.X ][v.Y + 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y + 1][0] = v.X ; 
			par[v.X ][v.Y + 1][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  - 1) )
		{
			mark[v.X ][v.Y - 1] = 1 ; 
			q.pb({v.X   , v.Y - 1}) ; 
			h[v.X ][v.Y - 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y - 1][0] = v.X ; 
			par[v.X ][v.Y - 1][1] = v.Y ; 
		}
		
	}
	
	if(sc[2].X == 0 || sc[3].X == 0)
	{
		cout<<-1 ; 
		return 0 ; 
	}
	
	pii p2 = sc[2] , p3= sc[3] ; 
	

	

	while(s[p2.X][p2.Y] != '1')
	{
		

		int w = p2.X ; 
		p2.X = par[p2.X][p2.Y][0] ;
		p2.Y = par[w][p2.Y][1] ;  
		mark[p2.X][p2.Y] = 2 ;
	}
	mark[p2.X][p2.Y] = 1 ; 
	

	

	while(s[p3.X][p3.Y] != '1')
	{
	

	int w = p3.X ; 
		p3.X = par[p3.X][p3.Y][0] ;
		p3.Y = par[w][p3.Y][1] ;
		mark[p3.X][p3.Y] = 2 ; 
	  
	}
	mark[p3.X][p3.Y] = 1 ; 
	

	for(int i  = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(mark[i][j] == 2) 
			{
				
				cnt ++ ; 
				

			}
		}
	}
	
	ans = min(ans , cnt) ; 
	
	
	

	
	q.clear() ; 
	cnt = 0 ; 
	memset(mark , 0 , sizeof mark) ;
	memset(par , 0 , sizeof par) ;  
	mc[2] = 0 ; 
	mc[3] = 0 ; 
	sc[2].X = 0 ; 
	sc[2].Y = 0 ; 
	sc[3].X = 0 ; 
	sc[3].Y = 0 ;  
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] == '2') 
			{
				q.pb({i , j}) ; 
				

			}
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		if(s[v.X][v.Y] == '1' && mc[1] == 0)
		{
			mc[1] = 1 ; 
			sc[1]=  v ; 
		}
		if(s[v.X][v.Y] == '3' && mc[3] == 0)
		{
			mc[3] = 1 ; 
			sc[3]= v ; 
		}
		
		if(val(v.X + 1 , v.Y) )
		{
			mark[v.X + 1][v.Y] = 1 ; 
			q.pb({v.X + 1 , v.Y}) ; 
			h[v.X + 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X + 1][v.Y][0] = v.X ; 
			par[v.X + 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X - 1 , v.Y) )
		{
			mark[v.X - 1][v.Y] = 1 ; 
			q.pb({v.X - 1 , v.Y}) ; 
			h[v.X - 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X - 1][v.Y][0] = v.X ; 
			par[v.X - 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  + 1) )
		{
			mark[v.X ][v.Y + 1] = 1 ; 
			q.pb({v.X , v.Y + 1}) ; 
			h[v.X ][v.Y + 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y + 1][0] = v.X ; 
			par[v.X ][v.Y + 1][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  - 1) )
		{
			mark[v.X ][v.Y - 1] = 1 ; 
			q.pb({v.X   , v.Y - 1}) ; 
			h[v.X ][v.Y - 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y - 1][0] = v.X ; 
			par[v.X ][v.Y - 1][1] = v.Y ; 
		}
		
	}
	
	
	pii p1 = sc[1]  ;   p3= sc[3] ;  
	

	

	while(s[p1.X][p1.Y] != '2')
	{
		

		int w = p1.X ; 
		p1.X = par[p1.X][p1.Y][0] ;
		p1.Y = par[w][p1.Y][1] ;  
		mark[p1.X][p1.Y] = 2 ;
	}
	mark[p1.X][p1.Y] = 1 ; 
	



	while(s[p3.X][p3.Y] != '2')
	{
		

		int w = p3.X ; 
		p3.X = par[p3.X][p3.Y][0] ;
		p3.Y = par[w][p3.Y][1] ;
		mark[p3.X][p3.Y] = 2 ; 
	  
	}
	mark[p3.X][p3.Y] = 1 ; 
	

	for(int i  = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(mark[i][j] == 2) 
			{
				
				cnt ++ ; 
				

			}
		}
	}
	
	ans = min(ans , cnt) ; 
	

	
	
	q.clear() ; 
	cnt = 0 ; 
	memset(mark , 0 , sizeof mark) ;
	memset(par , 0 , sizeof par) ;  
	mc[1] = 0 ; 
	mc[2] = 0 ; 
	mc[3] = 0 ; 
	sc[1].X = 0 ; 
	sc[1].Y = 0 ; 
	sc[2].X = 0 ; 
	sc[2].Y = 0 ; 
	sc[3].X = 0 ; 
	sc[3].Y = 0 ;  
	
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] == '3') 
			{
				q.pb({i , j}) ; 
				

			}
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		if(s[v.X][v.Y] == '2' && mc[2] == 0)
		{
			mc[2] = 1 ; 
			sc[2]=  v ; 
		}
		if(s[v.X][v.Y] == '1' && mc[1] == 0)
		{
			mc[1] = 1 ; 
			sc[1]= v ; 
		}
		
		if(val(v.X + 1 , v.Y) )
		{
			mark[v.X + 1][v.Y] = 1 ; 
			q.pb({v.X + 1 , v.Y}) ; 
			h[v.X + 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X + 1][v.Y][0] = v.X ; 
			par[v.X + 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X - 1 , v.Y) )
		{
			mark[v.X - 1][v.Y] = 1 ; 
			q.pb({v.X - 1 , v.Y}) ; 
			h[v.X - 1][v.Y] = h[v.X][v.Y] + 1 ; 
			par[v.X - 1][v.Y][0] = v.X ; 
			par[v.X - 1][v.Y][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  + 1) )
		{
			mark[v.X ][v.Y + 1] = 1 ; 
			q.pb({v.X , v.Y + 1}) ; 
			h[v.X ][v.Y + 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y + 1][0] = v.X ; 
			par[v.X ][v.Y + 1][1] = v.Y ; 
		}
		
		if(val(v.X , v.Y  - 1) )
		{
			mark[v.X ][v.Y - 1] = 1 ; 
			q.pb({v.X   , v.Y - 1}) ; 
			h[v.X ][v.Y - 1] = h[v.X][v.Y] + 1 ; 
			par[v.X ][v.Y - 1][0] = v.X ; 
			par[v.X ][v.Y - 1][1] = v.Y ; 
		}
		
	}
	
	 p2 = sc[2] , p1= sc[1] ; 
	

	

	while(s[p2.X][p2.Y] != '3')
	{
		

		int w = p2.X ; 
		p2.X = par[p2.X][p2.Y][0] ;
		p2.Y = par[w][p2.Y][1] ;  
		mark[p2.X][p2.Y] = 2 ;
	}
	mark[p2.X][p2.Y] = 1 ; 
	

	

	while(s[p1.X][p1.Y] != '3')
	{
	

		int w = p1.X ; 
		p1.X = par[p1.X][p1.Y][0] ;
		p1.Y = par[w][p1.Y][1] ;
		mark[p1.X][p1.Y] = 2 ; 
	  
	}
	mark[p1.X][p1.Y] = 1 ; 
	

	for(int i  = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(mark[i][j] == 2) 
			{
				
				cnt ++ ; 
				

			}
		}
	}
	
	ans = min(ans , cnt) ; 
	
	

	




	#define ans ans
	memset(dis , -1 , sizeof dis) ; 
	q.clear() ; 
	memset(mark , 0 , sizeof mark) ; 
	

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] =='1') 
			{
				q.pb({i , j}) ;
				mark[i][j] = 1 ; 
				dis[1][i][j] =  0 ; 
			 } 
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		
		if(val(v.X + 1 , v.Y))
		{
			q.pb({v.X + 1  , v.Y}) ; 
			dis[1][v.X+1][v.Y] = dis[1][v.X][v.Y] ; 
			if(s[v.X+1][v.Y] == '.')
			dis[1][v.X+1][v.Y] += 1 ; 
			mark[v.X + 1][v.Y] = 1 ; 
		}
		
		if(val(v.X - 1 , v.Y))
		{
			dis[1][v.X-1][v.Y] = dis[1][v.X][v.Y] ; 
			q.pb({v.X - 1  , v.Y}) ; 
			if(s[v.X-1][v.Y] == '.')
			dis[1][v.X-1][v.Y] += 1  ;
			mark[v.X-1][v.Y] = 1 ;  
		}
		
		if(val(v.X , v.Y + 1))
		{
			q.pb({v.X , v.Y + 1}) ; 
			dis[1][v.X][v.Y+1] = dis[1][v.X][v.Y] ; 
			if(s[v.X][v.Y+1] =='.')
			dis[1][v.X][v.Y+1]  +=  1  ; 
			mark[v.X][v.Y+1] = 1 ; 
		}
		
		if(val(v.X , v.Y - 1))
		{
			q.pb({v.X , v.Y - 1}) ; 
			dis[1][v.X][v.Y-1] = dis[1][v.X][v.Y] ; 
			if(s[v.X][v.Y-1] == '.')
			dis[1][v.X][v.Y-1]  +=  1 ; 
			mark[v.X][v.Y-1] = 1 ; 
		}
		
	}
	
	

	q.clear() ; 
	memset(mark , 0 , sizeof mark) ; 
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] =='2') 
			{
				q.pb({i , j}) ;
				mark[i][j] = 1; 
				dis[2][i][j] = 0 ; 
			 } 
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		
		if(val(v.X + 1 , v.Y))
		{
			q.pb({v.X + 1  , v.Y}) ; 
			dis[2][v.X+1][v.Y] = dis[2][v.X][v.Y] ; 
			if(s[v.X+1][v.Y] == '.')
			dis[2][v.X+1][v.Y] += 1 ; 
			mark[v.X + 1][v.Y] = 1 ; 
		}
		
		if(val(v.X - 1 , v.Y))
		{
			dis[2][v.X-1][v.Y] = dis[2][v.X][v.Y] ; 
			q.pb({v.X - 1  , v.Y}) ; 
			if(s[v.X-1][v.Y] == '.')
			dis[2][v.X-1][v.Y] += 1  ;
			mark[v.X-1][v.Y] = 1 ;  
		}
		
		if(val(v.X , v.Y + 1))
		{
			q.pb({v.X , v.Y + 1}) ; 
			dis[2][v.X][v.Y+1] = dis[2][v.X][v.Y] ; 
			if(s[v.X][v.Y+1] =='.')
			dis[2][v.X][v.Y+1]  +=  1  ; 
			mark[v.X][v.Y+1] = 1 ; 
		}
		
		if(val(v.X , v.Y - 1))
		{
			q.pb({v.X , v.Y - 1}) ; 
			dis[2][v.X][v.Y-1] = dis[2][v.X][v.Y] ; 
			if(s[v.X][v.Y-1] == '.')
			dis[2][v.X][v.Y-1]  +=  1 ; 
			mark[v.X][v.Y-1] = 1 ; 
		}
		
	}
	

		q.clear() ; 
	memset(mark , 0 , sizeof mark) ; 
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i][j] =='3') 
			{
				q.pb({i , j}) ;
				mark[i][j] = 1; 
				dis[3][i][j] = 0 ; 
			}
		}
	}
	
	while(q.size())
	{
		pii v = q.front() ; 
		q.pop_front() ; 
		
		if(val(v.X + 1 , v.Y))
		{
			q.pb({v.X + 1  , v.Y}) ; 
			dis[3][v.X+1][v.Y] = dis[3][v.X][v.Y] ; 
			if(s[v.X+1][v.Y] == '.')
			dis[3][v.X+1][v.Y] += 1 ; 
			mark[v.X + 1][v.Y] = 1 ; 
		}
		
		if(val(v.X - 1 , v.Y))
		{
			dis[3][v.X-1][v.Y] = dis[3][v.X][v.Y] ; 
			q.pb({v.X - 1  , v.Y}) ; 
			if(s[v.X-1][v.Y] == '.')
			dis[3][v.X-1][v.Y] += 1  ;
			mark[v.X-1][v.Y] = 1 ;  
		}
		
		if(val(v.X , v.Y + 1))
		{
			q.pb({v.X , v.Y + 1}) ; 
			dis[3][v.X][v.Y+1] = dis[3][v.X][v.Y] ; 
			if(s[v.X][v.Y+1] =='.')
			dis[3][v.X][v.Y+1]  +=  1  ; 
			mark[v.X][v.Y+1] = 1 ; 
		}
		
		if(val(v.X , v.Y - 1))
		{
			q.pb({v.X , v.Y - 1}) ; 
			dis[3][v.X][v.Y-1] = dis[3][v.X][v.Y] ; 
			if(s[v.X][v.Y-1] == '.')
			dis[3][v.X][v.Y-1]  +=  1 ; 
			mark[v.X][v.Y-1] = 1 ; 
		}
		
	}
	
	
	

	ans = 1e9 + 6 ; 
	for(int k = 1 ; k <= 3 ; k++)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				if(valid(i, j) != -1)
				{
					if(s[i][j] =='.')
					ans = min(ans , valid(i , j)  - 2 );
					else
					{
						ans = min(ans , valid(i , j) );
					}
				}
			}
		}
	}
	if(ans > 1e9 ) cout<<-1 ; 
	else cout<<min(ans , ans1) ;
	

	
	cout<<endl ; 
	

	
}







