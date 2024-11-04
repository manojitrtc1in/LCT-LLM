























































    
    using namespace std;
    

    

    

  
    

     

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
       
    
       
    
    

    

    

    

    

    

    

    

    

    

    

    
    
    
    
    
    
    
    
    
    

    

    
    
    
    
    
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
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        

        

        

        

            

        

        

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    bool id0(string expr)
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
	        
