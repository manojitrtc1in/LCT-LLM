



using namespace std;

using namespace __gnu_pbds;












ll minimum(ll x,ll y)
{
    return min(x,y);
}
ll maximum(ll x,ll y)
{
    return max(x,y);
}



using namespace std;


ll power(ll x, ll y, ll p)
{
    ll res = 1;     


    x = x % p; 

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;

        

        y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}




ll p=1000000007;
ll modinv(ll a,ll m)
{


    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        

        ll q = a / m;
        ll t = m;

        

        

        m = a % m, a = t;
        t = y;

        

        y = x - q * y;
        x = t;
    }

    

    if (x < 0)
       x += m0;

    return x;




}


void dfs(ll i,vector<vector<ll> > &g,vector<bool> &vis,ll x,vector<ll> &a)
{
    if(!vis[i])
    {

        vis[i]=true;
        a[i]=minimum(a[i],x);
       



        forn(j,g[i].size())
        {
            if(!vis[g[i][j]])
            dfs(g[i][j],g,vis,minimum(a[i],x),a);



        }




    }


}
pair<ll,ll>  dfs1(ll i,vector<vector<ll> > &g,vector<bool> &vis,vector<ll> &a,vector<ll> &b,vector<ll> &c,ll &ans)
{
    if(!vis[i])
    {
        vis[i]=true;
        pair<ll,ll> p;
        p.first=0;
        p.second=0;
         if(b[i]!=c[i])
        {
            if(b[i]==1)
                p.first++;
            else
                p.second++;
        }
        forn(j,g[i].size())
        {   if(!vis[g[i][j]])
            {pair<ll,ll> z=dfs1(g[i][j],g,vis,a,b,c,ans);
            p.first+=z.first;
            p.second+=z.second;
            }
        }

        


        if(p.first!=0 && p.second!=0)
        {
            ll z=minimum(p.first,p.second);
            ans+=a[i]*2*z;
            p.first-=z;
            p.second-=z;
        }
        return p;

    }

}


bool cmp1(pair<ll,ll> p1,pair<ll,ll> p2){
             return (p1.first-p1.second)<(p2.first-p2.second);
             }
bool f(ll st,vector<ll> &a,ll n)
{
    vector<ll> cnt(n+1,0);
    if(st<=0 || st>n)
        return false;
    ll sum1=st;
    cnt[st]++;
    forn(i,n-1)
    {
        sum1+=a[i];
        if(sum1<=0 || sum1>n)
            return false;
        cnt[sum1]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]!=1)
            return false;
    }
    return true;










}
void prime_fac(ll z,vector<ll> &fac,ll n)
{
        ll cnt=0;
        ll p=1;
        while(z%2==0)
        {
            z/=2;
            cnt++;
            p*=2;
            fac.push_back(p);
        }
        if(cnt>0 && p*2<=n)
            fac.push_back(p*2);




        ll x=(ll)sqrt(z);
        for(int i=3;i<=x;i+=2)
        {
            ll cnt=0;
            ll p=1;
            while(z%i==0)
            {
                cnt++;
                z/=i;
                p*=i;
                fac.push_back(p);
            }
            if(cnt>0 && p*i<=n)
                fac.push_back(p*i);




        }

        if(z>2)
        {
            fac.push_back(z);
            if(z*z<=n)
            fac.push_back(z*z);

        }

}
bool prime(ll l)
{
    for(int i=2;i<=sqrt(l);i++)
    {
        if(l%i==0)
            return false;
    }
    return true;



}
ll id0(ll x)
{
    ll l = 0, r = 1000005;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}
void sp(ll i, vector<vector<bool> > &dp,ll j,vector<ll> &a)
{
    ll n=dp.size();
     cout<<j<<" ";
    if(i==n-1)
    return ;

    if(a[i]<a[i+1])
    {
        for(int j1=j+1;j1<=5;j1++)
        {
            if(dp[i+1][j1])
                {sp(i+1,dp,j1,a);
                break;}
        }
    }
    else if(a[i]>a[i+1])
    {
          for(int j1=1;j1<=j-1;j1++)
        {
            if(dp[i+1][j1])
                {sp(i+1,dp,j1,a);
                break;}
        }

    }
    else
    {
           for(int j1=1;j1<=5;j1++)
        {
            if(dp[i+1][j1] && j1!=j)
                {sp(i+1,dp,j1,a);
                break;}
        }

    }
    return ;



    





}
void sieve(vector<bool> &prime,ll n)
{
    

    

    

    cout<<"yes"<<endl;


    for (int p=2; p*p<=n; p++)
    {
        

        if (prime[p] == true)
        {
            

            

            

            

            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }

    }

    

    ll cnt1=0;
    for (int p=2; p<=n; p++)
       {
           

           if (prime[p])
          {cout << p << " ";
          cnt1++;
          }
       }
    cout<<cnt1<<endl;
}

void id1(vector<ll> &spf)
{
    spf[1] = 1;
    ll MAXN=spf.size();
    for (int i=2; i<MAXN; i++)

        

        

        spf[i] = i;

    

    

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
                

        if (spf[i] == i)
        {
            

            for (int j=i*i; j<MAXN; j+=i)

                

                

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}





ll gen_fac(int x,vector<ll> &res,vector<ll> &spf)
{
    


    while (x != 1)
    {
        res.push_back(spf[x]);
        


        

        x = x / spf[x];

    }
    return 0;


}





ll q(vector<ll> &x)
{
    cout<<"? "<<x.size()<<" ";
    forn(i,x.size())
    cout<<x[i]<<" ";
    cout<<"\n";
    cout.flush();
    ll in;
    cin>>in;
    return in;





}
bool check(ll mask1,ll mask2,ll n)
{
    vector<vector<ll> > m(2,vector<ll>(n,0));
    ll i=0;
    while(mask1!=0)
    {
        m[0][i++] = mask1%2;
        mask1/=2;

    }
    i=0;
    while(mask2!=0)
    {

        m[1][i++] = mask2%2;
        mask2/=2;

    }
    i=0;
    while(i<n-1)
    {
        ll cnt1=0;
        if(m[0][i]==1)
        cnt1++;
        if(m[1][i]==1)
        cnt1++;
        if(m[1][i+1]==1)
        cnt1++;
        if(m[0][i+1]==1)
        cnt1++;

        if(cnt1%2==0)
            return false;

        i++;



    }

    return true;







}
ll sp(int i,vector<ll> &a,ll n,ll m,ll d,vector<ll> &dp)
{
    if(i>=n)
        return 0;

    if(dp[i]!=-1)
        return dp[i];
    ll ans=0;
    ans = sp(i+1,a,n,m,d,dp);

    if(a[i]<=m)
        ans = maximum(ans,a[i] + sp(i+1,a,n,m,d,dp));
    else
    {
        ans = maximum(ans,a[i] + sp(i+d+1,a,n,m,d,dp));
    }

    return ans;







}



ll sp(ll l,ll h,vector<ll> &a)
{
    if(l>h)
        return 0;
    if(l==h)
        return 1;

    else
    {
        ll mini=99999999999999;
        ll ind=0;
        ll cnt=0;
        for(ll i=l;i<=h;i++)
        {
            if(a[i]<mini)
            {mini=a[i];
                ind=i;
                }
            if(a[i]>0)
                cnt++;
        }

        return minimum(cnt,mini+sp(l,ind-1,a)+sp(ind+1,h,a));




    }


}

ll stringll(string x)
{

    ll ans=0;
    ll p=1;
    for(int i=x.length()-1;i>=0;i--)
    {
        ans+=(x[i]-'0')*p;
        p*=10;

    }
    return ans;


}

void dfs12(int i,vector<vector<ll> > &g,vector<bool> &vis,pair<ll,ll> &p)
{

    if(!vis[i])
    {

        vis[i]=true;

        p.first+=1;

        for(int j=0;j<g[i].size();j++)
        {
            if(!vis[g[i][j]])
            {

                dfs12(g[i][j],g,vis,p);

            }
            p.second+=1;


        }





    }



}

pair<ll,ll> getMax(vector<pair<ll,ll> > &st,ll ql,ll qh,ll l,ll h,ll i )
{

    if (ql <= l && qh >= h)
        return st[i];


    if (h < ql || l > qh)
        {
            pair<ll,ll> p;
            p.first=-1;
            return p;

        }


    ll mid = l+(h-l)/2;

    pair<ll,ll> pl=getMax(st, ql,qh, l, mid,2*i + 1);
    pair<ll,ll> pr=getMax(st,ql,qh,mid+1,h,2*i+2);

    if(pl.first>pr.first)
        return pl;
    else
        return pr;



}




pair<ll,ll> helper(vector<pair<ll,ll> > &st,vector<ll> &a,ll l,ll h,ll i)
{

    if(l==h)
    {
        st[i].first=a[l];
        st[i].second=l;
        return st[i];

    }
    ll mid=l+(h-l)/2;
    pair<ll,ll> pl=helper(st,a,l,mid,2*i+1);
      pair<ll,ll> pr=helper(st,a,mid+1,h,2*i+2);

    if(pl.first>pr.first)
        st[i]=pl;
    else
        st[i]=pr;
    return st[i];


}


vector<pair<ll,ll> > constructST(vector<ll> &a, ll n)
{

    vector<pair<ll,ll> > st(1000000,{-1,-1});



    helper(st,a,0,n-1,0);
    return st;

}

bool f(vector<ll> &a,ll mid,ll s)
{
    ll sum=0;
    int i=0;
    while(i<mid)
    {
        sum+=a[i] + (i+1)*mid;
        i++;
    }
    for(int i=mid;i<a.size();i++)
    {
        if(sum<=s)
            return true;
        sum-=a[i-mid] + (i-mid+1)*mid;
        sum+=a[i] + (i+1)*mid;


    }
    if(sum<=s)
            return true;
    return false;








}



int main()
{   ios_base::sync_with_stdio(false);
    

    ll MAX=	9223372036854775807 ;
    ll p= 998244353;
    ll mod = 1000000007;

    int t=1;

    cin>>t;

    

    

    

   


        vector<ll> apha(1000,0);
        vector<pair<ll,ll> > st;
            st=constructST(apha,1000);
             st=constructST(apha,1000);
                st=constructST(apha,1000);

   ll test=1;
   while(t--)
    {
            ll  n;
        cin>>n;


        vector<ll> a(105,0);
        ll a1;
                for(int i=0;i<n;i++){
                    cin>>a1;
                    a[a1]++;
                }
        ll ans=0;
        ll current=0;


                for(ll i=0;i<=101;i++){
                    if(current==1&&a[i]==1){
                    continue;
                }
                            if(a[i]<2&&current<2){

                                ans+=i*min(2-current,2-a[i]);
                                current+=min(2-current,2-a[i]);
                            }
                            if(current==2)break;
                        }

        cout<<ans<<endl;








    }


}
