























































    #include<bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
  
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
     #define ordered_set_pair tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
    

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
    

    

    

    

    

    

    const int N = 2e6 + 5;
    

    

    

    

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
    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int n;
    vi query(int r)
    {
        cout<<"?"<<" "<<r<<endl;
        cout.flush();
        vi v(n);
        cin>>v;
        return v;
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
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    bool possible(int len,int s,int n)
    {
        int c=1,d=n;
        int mx=0,mn=0,i;
        if((len*(len+1))/2<=s && ((n*(n+1))-(n-len)*(n-len+1))/2>=s)
        {
            return true;
        }
        return false;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    string lcs(string a,string b,int n,int m)
    {
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        string s;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                s.pb(a[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        reverse(all(s));
        return s;

    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

           
    

    

    

    

    

    

                   
    

                    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    bool comp(pii a,pii b)
    {
      if(a.x==b.x) return a.y<b.y;
      return a.x<b.x;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int dp[40][40];
    int num_square_brackets(string &s,int i,int dif,int n)
    {
        if(i==n && dif==0) return 1;
        if(i==n) return 0;
        if(dp[i][dif]!=-1) return dp[i][dif];
        int num=0;
        if(s[i]=='1')
        {
            if(dif>0)
            {
                s[i]=')';
                num+=num_square_brackets(s,i+1,dif-1,n);
                s[i]='(';
                num+=num_square_brackets(s,i+1,dif+1,n);
            }
            else
            {
                s[i]='(';
                num+=num_square_brackets(s,i+1,dif+1,n);

            }
            s[i]='1';
        }
        else
        {
            num+=num_square_brackets(s,i+1,dif+1,n);
        }
        return dp[i][dif]=num;

    }
    map<string,int > m;
    void dis_subseq(string &s,int n,int i,string ans="")
    {
        if(i==n)
        {
            m[ans]++;
            return;
        }
        if(m.count(ans))
        {
            return;
        }
        ans.pb(s[i]);
        dis_subseq(s,n,i+1,ans);
        ans.pop_back();
        dis_subseq(s,n,i+1,ans);
    }
    int mx_vis(int a,int b,int c,int ca=0,int cb=0,int cc=0,int cd=0,int ce=0,int cf=0,int cg=0)
    {
        if(a==0 && b==0 && c==0) return 0;
        int mx=0;
        if(a>0 && ca==0) mx=max(mx,1+mx_vis(a-1,b,c,ca+1,cb,cc,cd,ce,cf,cg));
        if(b>0 && cb==0) mx=max(mx,1+mx_vis(a,b-1,c,ca,cb+1,cc,cd,ce,cf,cg));
        if(c>0 && cc==0) mx=max(mx,1+mx_vis(a,b,c-1,ca,cb,cc+1,cd,ce,cf,cg));
        if(a>0 && b>0 && cd==0) mx=max(mx,1+mx_vis(a-1,b-1,c,ca,cb,cc,cd+1,ce,cf,cg));
        if(a>0 && c>0 && ce==0) mx=max(mx,1+mx_vis(a-1,b,c-1,ca,cb,cc,cd,ce+1,cf,cg));
        if(b>0 && c>0 && cf==0) mx=max(mx,1+mx_vis(a,b-1,c-1,ca,cb,cc,cd,ce,cf+1,cg));
        if(a>0 &&  b>0 && c>0 && cg==0) mx=max(mx,1+mx_vis(a-1,b-1,c-1,ca,cb,cc,cd,ce,cf,cg+1));
        return mx;
    }
    int find_al(int l,int r,string &s,char ch)
    {
        int i;
        if(r>=n || l<0) return -1;
        fo(i,l,r+1)
        {
            if(s[i]==ch) return i;
        }
        return -1;
    }
    bool ok(vi &p)
    {
        int n=p.size();
        if(n<=2) return true;
        if(n>=5) return false;
        int  i,j,k;
        fo(i,0,n)
        {
            fo(j,i+1,n)
            {
                fo(k,j+1,n)
                {
                    if((p[j]>=p[i] && p[j]<=p[k]) || (p[k]<=p[j] && p[j]<=p[i])) return false;
                }
            }
        }
        return true;
    }
    int i;
    int solve(string &s,char c)
    {
        int n=s.length();
        if(n==1)
        {
            if(s[0]==c) return 0;
            return 1;
        }
        string ne,ne2;
        int cnt1=0,cnt2=0;
        fo(i,0,n/2)
        {
            if(s[i]!=c) cnt1++;
            ne.pb(s[i]);
        }
        fo(i,n/2,n)
        {
            if(s[i]!=c) cnt2++;
            ne2.pb(s[i]);
        }
        

        

        return min(solve(ne,c+1)+cnt2,solve(ne2,c+1)+cnt1);
    }
    int binpow(int a, int b) 
    {
        a %= MOD;
        int res = 1;
        while (b > 0) 
        {
            if (b & 1) 
                res = res * a % (MOD);
            a = a * a % (MOD);
            b >>= 1;
        }
        return res;
    }
    int fact[N],invfact[N];
    void factorial()
    {
        int i;
        fact[0]=1;
        for(i=1;i<N;i++)
        {
            fact[i]=i*fact[i-1]%MOD;
        }
        i--;
        invfact[i]=binpow(fact[i],MOD-2);
        for(i--;i>=0;i--)
        {
            invfact[i]=(i+1)*invfact[i+1]%MOD;
        }
    }
    int nCr(int n,int r)
    {
        if(r>n || n<0 || r<0) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    }
    bool perform(string &s,string &p,int n,int m,int ind)
    {
       int c,i,j,f=0;
       c=1;
       if(c==m) return true;
       rfo(i,ind-1,0)
       {
         if(s[i]==p[c])
         {
            c++;
            if(c==m) return true;
         }
         else break;
       }
       c=1;
       fo(i,ind+1,n)
       {
          if(s[i]==p[c])
          {
            c++;
            if(c==m) return true;
            int k=c;
            rfo(j,i-1,0)
            {
                if(s[j]==p[c])
                {
                    c++;
                    if(c==m) return true;
                }
                else break;
            }
            c=k;
          }
          else
          {
            if(i>ind)
            {
                int k=c;
                rfo(j,i-2,0)
                {
                    if(s[j]==p[c])
                    {
                        c++;
                        if(c==m) return true;
                    }
                    else break;         
                }
                c=k;
                

                break;
            }
            else break;
          }
       }
       return false;

    }
    signed main()
    {
        thunder;
        #ifndef ONLINE_JUDGE
           freopen("Input.txt","r",stdin);
           freopen("Output.txt","w",stdout);
           freopen("Error.txt","w",stderr);
        #endif
        int t,c,m,b,f,f2,k,t2,t3,i,j,ans1,mnt,mxt,j1,a;
        cin>>t;
        while(t--)
        {
            

            string s,p;
            cin>>s>>p;
            n=s.length();
            m=p.length();
            f=0;
            fo(i,0,n)
            {
                if(s[i]==p[0])
                {
                    if(perform(s,p,n,m,i)) {f=1;break;}
                }
            }
            output(f);
        }
    }

    

    


    