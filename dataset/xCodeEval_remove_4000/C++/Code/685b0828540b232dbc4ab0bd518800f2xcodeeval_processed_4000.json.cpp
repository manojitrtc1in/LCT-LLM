
















































using namespace std;
int main()
{	 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin >> t;
    while(t--)
    {
    	string s,t;
    	cin >> s;
    	cin >> t;
    	map<char,long long int> m;
    	string res;
    	for(int i=0;i<s.length();i++)
    	{
    		m[s[i]]++;
    	}
    	s="";
    	if(t!="abc" || m['a']==0 || m['b']==0 || m['c']==0)
    	{
    		for(auto pr :m)
    		{
    			while(pr.second--)
    			{
    				s+=pr.first;
    			}
    		}
    		cout << s;
    	}
    	else
    	{
    		while(m['a']--)
    		{
    			cout << 'a';
    		}
    		while(m['c']--)
    		{
    			cout << 'c';
    		}
    		while(m['b']--)
    		{
    			cout << 'b';
    		}
    		for(auto pr:m)
    		{
    			if(pr.first!='a' && pr.first!='b' && pr.first!='c')
    			{
    				while(pr.second--)
    				{
    					cout << pr.first;
    				}
    			}
    		}
    	}
    	
    	cout << endl;
    }
}