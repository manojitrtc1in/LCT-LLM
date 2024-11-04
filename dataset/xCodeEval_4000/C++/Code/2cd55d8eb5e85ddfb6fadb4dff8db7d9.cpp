# include<bits/stdc++.h>


# define MOD 1000000007
# define endl '\n'
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
# define f first
# define s second
using namespace std ;
 
int main()
{
 	fastio
    int n,k ; cin>>n>>k ;
    deque<int> q ;
    map<int,int> mp ;
    int x ;
    for(int i=0;i<n;i++)
    {
    	cin>>x ;
    	if(mp[x]==0)
    	{
    		if(q.size()==k)
    		{
    			int num1 = q.front();
    			q.pop_front();
    			mp[num1] = 0;
    		}
    		q.push_back(x) ;
    		mp[x] = true ;
    	}
    	else
    	{
    		continue;
    	}
    }
 
 	cout << q.size() << endl;

 	while(q.size()>0)
 	{
 		cout << q.back() << " ";
 		q.pop_back();
 	}
 	cout << endl;
    
}









































