    #include <bits/stdc++.h>
    #include<string.h>
    #include<string>
     
    using namespace std;
     
    typedef long long int lli;
     
    #define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    #define rep(i,a,b) for(lli i=a;i<b;i++)
    #define rev(i,b,a) for(lli i=b;i>=a;i--)
    #define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
    #define debug(x) cout << "\t[ " << #x  << " : " << x << " ]" << endl;
    #define debugT(x) cout << "\t" << #x  << " : " << x << endl;
    #define MOD (lli)(1000000000+7) 

    #define MAXN 1000000+1 

    #define endl "\n"
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define TEST_CASES  lli t;cin >> t;while(t--)
     
    lli max(lli a, lli b){ if(a>b) return a ; return b; }
    lli min(lli a, lli b){ if(a<b) return a ; return b; }
     
    string sing(char x)
    {
    	string s(1,x) ;
    	return s;
    }
     
    bool cmpDec(lli a,lli b)
    {
    	if(a>=b)
    	return true;
    return false;
    }
     
     
    void print1D(lli a[], lli n)
    {
    	rep(i,0,n)cout<<a[i]<<" ";
    	cout<<endl;
    }
     
    void print2D(lli **dp, lli n, lli m)
    {
    	rep(i,0,n)
    	{
    		rep(j,0,m)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}
    }
     
    void init1D(lli a[], lli n, lli k)
    {
    	rep(z,0,n)a[z]=k;
    }
     
     
    void init2D(lli **a, lli n, lli m, lli k)
    {
    	rep(i,0,n)
    	rep(j,0,m)
    	a[i][j]=k;
    }
     
     
     
    lli fastmod(lli base,lli exp, lli m)
    {
    	lli res=1;
    	while(exp)
    	{
    		if (exp&1ll)
    			res=(res*base)%m;
    		base=(base*base)%m;
    		exp/=2;
    	}
    	return res;
    }
     
     
     
    lli gcd(lli a, lli b) 
    { 
    	if (a == 0) 
    		return b; 
    	return gcd(b % a, a); 
    } 
     
    lli logBase(lli m, lli b)
    {
    	lli count=0;
    	while(m>1)
    	{
    		++count;
    		m=m/b;
    	}
    	return count;
    }
     
     
      
    

    lli spf[MAXN]; 
      
    

    

    

    void sieve() 
    { 
    	spf[1] = 1; 
    	for (lli i=2; i<MAXN; i++) 
      
    		

    		

    		spf[i] = i; 
      
    	

    	

    	for (lli i=4; i<MAXN; i+=2) 
    		spf[i] = 2; 
      
    	for (lli i=3; i*i<MAXN; i++) 
    	{ 
    		

    		if (spf[i] == i) 
    		{ 
    			

    			for (lli j=i*i; j<MAXN; j+=i) 
      
    				

    				

    				if (spf[j]==j) 
    					spf[j] = i; 
    		} 
    	} 
    } 
     
     
     
     
      
    

    

    vector<lli> getFactorization(lli x) 
    { 
    	vector<lli> ret; 
    	while (x != 1) 
    	{ 
    		ret.push_back(spf[x]); 
    		x = x / spf[x]; 
    	} 
    	return ret; 
    } 
     
     
      
    

    lli sumofFactors(lli n) 
    { 
    	

    	lli res = 1; 
    	for (lli i = 2; i <= sqrt(n); i++) 
    	{ 
      
    		  
    		lli curr_sum = 1; 
    		lli curr_term = 1; 
    		while (n % i == 0) { 
      
    			

    			

    			

    			n = n / i; 
      
    			curr_term *= i; 
    			curr_sum += curr_term; 
    		} 
      
    		res *= curr_sum; 
    	} 
      
    	

    	

    	

    	if (n >= 2) 
    		res *= (1 + n); 
      
    	return res; 
    } 
     
     
     
    void SUM(lli *a, lli n)
    {
    	lli sum=0;
    	rep(i,0,n)sum+=a[i];
    	cout<<sum<<endl;
    }
     
     
    void addEdge(vector<lli> adj[], lli u, lli v) 
    { 
    	adj[u].push_back(v); 
    	adj[v].push_back(u); 
    } 
     
     
    void printGraph(vector<lli> adj[], lli V) 
    { 
    	for (lli v = 1; v < V; ++v) 
    	{ 
    		cout << "\n Adjacency list of vertex "
    			 << v << "\n head ("<<v<<")"; 
    		rep(x,0,adj[v].size()) 
    		   cout << " -> " << adj[v][x]; 
    		printf("\n"); 
    	} 
    } 
     
     
    bool cycle(vector<lli> adj[], lli vis[], lli n, lli parent)
    {
    	vis[n]=1;
    	if(adj[n].empty())return false;
    	bool value=false;
    	rep(i,0,adj[n].size())
    	{
    		if(adj[n][i]!=parent)
    		{
    			if(vis[adj[n][i]]==1)return true;
    			else
    				value|=cycle(adj,vis,adj[n][i],n);
    		}
    	}
    	return value;
    }
     
     
    typedef struct num{
    	lli index;
    	lli value;
    }num;
     
     
    lli countFactors(lli n)
    {
    	lli count=0;
    	lli ans=1;
    	rep(i,2,sqrt(n)+1)
    	{
    		count=0;
    		while(n%i==0)
    		{
    			n/=i;
    			++count;
    		}
    		ans*=count;
    	}
    	if(n>1)ans*=2;
    	return ans;
    }
     
     
    lli kthFactor(lli n, lli k)
    {
    	vector <lli> v;
    	rep(i,2,(lli)sqrt(n)+1)
    	{
    		if(n%i==0)
    		{
    			v.pb(i);
    			if(i<n/i) v.pb(n/i);
    		}
    	}
    	v.pb(1);
    	v.pb(n);
    	sort(v.begin(),v.end());
    	

    	if(v.size()<k)return -1;
    	return v[k-1];
     
    }
     
     
     
     
    lli binSmaller(lli a[], lli n, lli k)
    {
    	lli l,r;
    	l=0;
    	r=n-1;
    	lli mid=(l+r)/2;
    	if(a[r]<=k)return r;
    	if(a[l]>k)return -1;
    	while(l<r)
    	{
    		if(a[mid]>k && a[mid-1]<=k)return mid-1;
    		if(k>=a[mid] && a[mid+1]>k)return mid;
    		if(k<a[mid])r=mid-1;
    		else l=mid+1;
    		mid=(l+r)/2;
     
    	}
    	return -1;
    }
     
     
    

    lli binarySearchCount(lli arr[], lli n, lli key) 
    { 
    	lli left = 0; 
    	lli right = n - 1; 
      
    	lli count = 0; 
    	lli mid=0;
    	while (left <= right) { 
    		mid = (right + left) / 2; 
      
    		

    		

    		if (arr[mid] <= key) { 
      
    			

    			

    			

    			count = mid + 1; 
    			left = mid + 1; 
    		} 
      
    		

    		else
    			right = mid - 1; 
    	} 
      
    	return count; 
    } 
     
     
     
    lli binomialCoeff(lli n, lli k)  
    {  
    	lli res = 1;  
      
    	

    	if ( k > n - k )  
    		k = n - k;  
      
    	

    	

    	for (lli i = 0; i < k; ++i)  
    	{  
    		res *= (n - i);  
    		res /= (i + 1);  
    	}  
      
    	return res;  
    }  
     
    lli modInverse(lli a, lli m= MOD )
    { 
    	lli m0 = m , y = 0, x = 1; if (m == 1) return 0; 
    	while (a > 1)
    	{
    		lli q = a / m; 
    		lli t = m;
    		m = a % m, a = t;   
    		t = y; 
    		y = x - q * y; 
    		x = t; 
    	} 
    	if (x < 0)  x += m0; return x; 
    } 
     
     

    const int N = 10e5+1;
    lli factorialNumInverse[N + 1];  lli naturalNumInverse[N + 1]; lli fact[N + 1]; 
     
     
    void InverseofNumber(lli p) 
    { 
    	naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    	for (lli i = 2; i <= N; i++)
    		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    } 
     
     
     
    void InverseofFactorial(lli p) 
    { 
    	factorialNumInverse[0] = factorialNumInverse[1] = 1; 
    	for (lli i = 2; i <= N; i++)
    		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
    } 
     
     
    void factorial(lli p) 
    { 
    	fact[0] = 1; 
    	for (lli i = 1; i <= N; i++)
    	{
    		fact[i] = (fact[i - 1] * i) % p; 
    	} 
    } 
     
     
    lli nCr(lli N, lli R, lli p = MOD)
    { 
    	if(R==0) return 1;
    	lli ans = ((fact[N] * factorialNumInverse[R])  % p * factorialNumInverse[N - R]) % p; 
    	return ans; 
    } 
    

     
    lli numberOfPaths(lli m, lli n) 
    { 
    	

    	

    	lli path = 1; 
    	for (lli i = n; i < (m + n - 1); i++) { 
    		path *= i; 
    		path /= (i - n + 1); 
    	} 
    	return path; 
    } 
     
    

     
     
    lli findmin(string &s, lli l, lli r, lli scii, lli **ks)
    {
    	lli mid=(l+r)/2;
    	if(r-l==1)
    	{	
    		

    		if(s[l]=='a'+scii)
    		{	
    			

    			

    			return 0;
    		}
    		

    	

    	return 1;	
     
    	}
    	lli h1=0, h2=0;
    	

    	

    	

    	

    	

    		h1=ks[scii][mid]-ks[scii][l];
    	h1=(r-l)/2-h1;
    	if(mid==0)h2=ks[scii][r];
    	else h2=ks[scii][r]-ks[scii][mid];
    	h2=(r-l)/2-h2;
    	

    	

    	

    	return min(h1+findmin(s,mid,r,(scii+1)%26, ks), h2+findmin(s,l,mid,(scii+1)%26,ks));
    	

     
    }
     
     
    lli calc(const string &s, char c) {
    	if (s.size() == 1) {
    		return s[0] != c;
    	}
    	lli mid = s.size() / 2;
    	lli cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
    	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
    	lli cntr = calc(string(s.begin() + mid, s.end()), c + 1);
    	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
    	return min(cntl, cntr);
    }
     
     
     
    lli solve(string &s, lli n,lli **ks)
    {
    	return findmin(s,0,n,0,ks);
    }
     
     
     
     
    int main()
    {
    	fio;
    	
    	TEST_CASES
    	{
    		lli n;
    		cin>>n;
    		lli k=logBase(n,2);
    		string s;
    		cin>>s;
    		

    		lli **ks;
    		ks=new lli*[26];
    		rep(i,0,26)ks[i]=new lli[n+1];
    		init2D(ks,26,n+1,0);
    		rep(i,0,n)
    		{
    			ks[s[i]-'a'][i+1]=1;
    		}
    		rep(i,0,26)
    		{
    			rep(j,1,n+1)
    			ks[i][j]+=ks[i][j-1];
    			

    		}
     
    		

    		lli ans=solve(s,n,ks);
    		

    		cout<<ans<<endl;
    		

     
    	}
     
    	
    }	