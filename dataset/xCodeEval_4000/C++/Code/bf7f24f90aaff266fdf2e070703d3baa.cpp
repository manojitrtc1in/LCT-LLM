























































    #include<bits/stdc++.h>
    using namespace std;
    

    

    

  
    

     

    

    #define int         long long
    #define double      long double
    #define pb          push_back
    #define pf          push_front
    #define pii         pair<int,int>
    #define vi          vector<int>
    #define vnn         vector<vector<int>>
    #define vii         vector<pii>
    #define vs          vector<string>
    #define all(a)      (a).begin(),(a).end()
    #define rall(a)     (a).rbegin(),(a).rend()
    #define x           first
    #define y           second
    #define endl        '\n'
    #define sz(x)       (int)(x).size()
    #define thunder     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
    #ifndef ONLINE_JUDGE
       #define debug(x)    cerr<<#x<<" "<<x<<endl;
    #else 
       #define debug(x)
    #endif  
    

    

    

    

    

    

    

    

    

    

    

    #define fo(i,l,u)   for(i=l;i<u;i++)
    #define rfo(i,l,u)  for(i=l;i>=u;i--)
    #define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
    #define _init(b)     memset(b,-1,sizeof(b))
    #define _init0(b)     memset(b,0,sizeof(b))
    #define MOD         1000000007
    #define hell        998244353
    #define output(x) cout << (x ? "YES" : "NO")<<endl;
    #define Output(x) cout << (x ? "Yes" : "No")<<endl;
    

    

    #define MOD2 (998244353)
    #define MOD3 (1000000009)
    #define PI acos(-1)
    #define eps (1e-8)
    #define INF (1e18) 
    template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
    template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
    template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
    template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
    ifstream cinn("in.txt");ofstream coutt("out.txt");
    int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 
    

    int gcd(int a, int b) 
    { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);    
    }
    int _sum(int n)
    {
        return (n*(n+1))/2;
    }
    int distSq(pii p, pii q) 
    { 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);  
    }
    

    

    

    

    

    

    const int N = 2e5 + 5;
    

    

    

    

    int isPalindrome(string str)
    {
    int low = 0;
    int high = str.length() - 1;
 
    while (low < high)
    {
        

        if (str[low] != str[high]) {
            return -1;
        }
 
        low++;
        high--;
    }
    return str.length();
    }
    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int query(int l,int r)
    {
        cout<<"?"<<" "<<l<<" "<<r<<endl;
        cout.flush();
        int s;
        cin>>s;
        return s;
    }
    bool isprime(int n)
    {
        int i;
        if(n==1) return false;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        

        

        

        

            

        

        

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    bool areBracketsBalanced(string expr)
{ 
    stack<char> s;
    char x;
 
    

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            

            s.push(expr[i]);
            continue;
        }
 
        

        

        

        if (s.empty())
            return false;
 
        switch (expr[i]) {
        case ')':
             
            

            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            

            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            

            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
    

    return (s.empty());
}
    signed main()
    {
        thunder;
        int t,c,b,f,f2,k,t2,t3,i,j,ans1,mnt,mxt,j1,a,n,m;
        cin>>t;
        

        while(t--)
        {
        	cin>>n;
        	vi v(n);
        	cin>>v;
        	f=1;
        	int lcm=1;
        	fo(i,0,n) {
        		int g = gcd(lcm,i+2);
        		int cur = ((i+2)*lcm)/g;
        		lcm = cur;
        		if(lcm>1e9) break;
        		if(v[i]%lcm==0) f=0; 
        		
        	}
        	output(f);
        }
        
        
	}
	        
