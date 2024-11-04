



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

void id3(vector<ll> &spf)
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
struct Node {
	ll sum;
	ll prefix;
};





void build(vector<Node*> &tree,vector<ll> &a, int index, int beg, int end1)
{
	if (beg == end1) {

		

		

		

		tree[index]=new Node();
		tree[index]->sum = a[beg];
		tree[index]->prefix = a[beg];
	} else {
		int mid = (beg + end1) / 2;
        tree[index]=new Node();
		

		

		build(tree,a, 2 * index + 1, beg, mid);
		build(tree,a, 2 * index + 2, mid + 1, end1);

		

		

		tree[index]->sum = tree[2 * index + 1]->sum +
						tree[2 * index + 2]->sum;

		

		

		tree[index]->prefix = max(tree[2 * index + 1]->prefix,
								tree[2 * index + 1]->sum +
								tree[2 * index + 2]->prefix);
	}
}





Node* query(vector<Node*> &tree,int index, int beg, int end1, int l, int r)
{
	Node*  result=new Node();
	result->sum = -99999999999;
	result->prefix = -99999999999;
	


	

	

	if (beg > r || end1< l)
		{

	

		return result;}

	

	

	if (beg >= l && end1 <= r)
		{

	

	return tree[index];}

	ll mid = (beg + end1) / 2;

	

	

	



	

	

	Node *left = query(tree,2 * index + 1, beg, mid,
										l, r);
	Node *right = query(tree,2 * index + 2, mid + 1,
								end1, l, r);
    if(left->sum==-99999999999)
        return right;
    else if(right->sum==-99999999999)
        return left;

	

	

	

	

	result->sum = left->sum + right->sum;

	

	result->prefix = max(left->prefix, left->sum +
							right->prefix);
    


	

	return result;
}
struct Node1 {
	ll sum;
	ll suffix;
};





void id1(vector<Node1*> &tree,vector<ll> &a, int index, int beg, int end1)
{
	if (beg == end1) {

		

		

		

		tree[index]=new Node1();
		tree[index]->sum = a[beg];
		tree[index]->suffix = a[beg];
	} else {
		int mid = (beg + end1) / 2;
        tree[index]=new Node1();
		

		

		id1(tree,a, 2 * index + 1, beg, mid);
		id1(tree,a, 2 * index + 2, mid + 1, end1);

		

		

		tree[index]->sum = tree[2 * index + 1]->sum +
						tree[2 * index + 2]->sum;

		

		

		tree[index]->suffix = max(tree[2 * index + 2]->suffix,
								tree[2 * index + 2]->sum +
								tree[2 * index + 1]->suffix);
	}
}





Node1* id2(vector<Node1*> &tree,int index, int beg, int end1, int l, int r)
{
	Node1*  result=new Node1();
	result->sum = -99999999999;
	result->suffix = -99999999999;
	


	

	

	if (beg > r || end1< l)
		{

	

		return result;}

	

	

	if (beg >= l && end1 <= r)
		{

	

	return tree[index];}

	ll mid = (beg + end1) / 2;

	

	

	



	

	

	Node1 *left = id2(tree,2 * index + 1, beg, mid,
										l, r);
	Node1 *right = id2(tree,2 * index + 2, mid + 1,
								end1, l, r);
    if(left->sum==-99999999999)
        return right;
    else if(right->sum==-99999999999)
        return left;

	

	

	

	

	result->sum = left->sum + right->sum;

	

	result->suffix = max(right->suffix, right->sum +
							left->suffix);
    


	

	return result;
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

int main()
{   ios_base::sync_with_stdio(false);
    

    ll MAX=	9223372036854775807 ;
    ll p= 998244353;

    int t=1;
   cin>>t;

    

    

    

   

   while(t--)
    {
        ll n;
        cin>>n;
        
       vector<ll> a(n);
        bool en=false;
        bool st=false;
        ll cnt=0;
       forn(i,n)
       {cin>>a[i];
        
        if(a[i]==i+1)
        {cnt++;
        if(i==n-1)
        en=true;
        if(i==0)
        st=true;

       }
       }

    if(cnt==n)
    {cout<<0<<"\n";
    continue;}
    else if(cnt==0)
    {cout<<1<<"\n";
    continue;}
    
    ll i=0;
    ll z2=0;
    while(i<n && a[i]==i+1)
    {i++;
    z2++;}


   

    i=n-1;
    ll z1=0;
    while(i>=0 && a[i]==i+1)
    {i--;
    z1++;}

    

    if(z1+z2==cnt)
    cout<<1<<"\n";
    else
    {
        cout<<2<<"\n";
    }
    


    
    




    }
}
