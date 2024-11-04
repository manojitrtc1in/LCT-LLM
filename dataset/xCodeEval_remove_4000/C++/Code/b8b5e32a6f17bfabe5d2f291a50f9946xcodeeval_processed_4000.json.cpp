
using namespace std;


using namespace __gnu_pbds;





































const ld PI=3.1415926535897932384626433;




















ll gcd(ll a, ll b)
{
   if (a == 0) return b;
   return gcd(b % a, a);
}

inline ll ceil(ll a,ll b)
{
   return (a+b-1)/b;
}

ll max(ll x,ll y,ll z)
{
   return max(x,max(y,z));
}

ll min(ll x,ll y,ll z)
{
   return min(x,min(y,z));
}






ll is_set(ll a,ll i)
{
   if( ( a & ((ll)1<<i) ) == 0 ) return 0;
   else return 1;
}
















struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};





























    














































void lps(string &pp,ll *lps)
{
   ll xx=pp.length();
   

   f(i,1,xx)
   {
       ll j=lps[i-1];
       while(j>0 && pp[j]!=pp[i]) j=lps[j-1];
       if(pp[i]==pp[j]) j++;
       lps[i]=j;
   }
}




void stoi(string &s,vll &v)
{
   stringstream str(s);
   ll x;
   while(str>>x)
   {
       v.pb(x);
   }
}




void Miden(ll **p1,ll n)
{
    ll (*x)[n]=(ll(*)[n]) p1;
    f(i,0,n)
    {
        f(j,0,n)
        {
            x[i][j]=0;
        }
        x[i][i]=1;
    }
    return;
}

void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m)
{
    ll (*a)[y]=(ll (*)[y])p1;
    ll (*b)[z]=(ll (*)[z])p2;
    ll (*c)[z]=(ll (*)[z])ans;
    f(i,0,x)
    {
        f(j,0,z)
        {
            c[i][j]=0;
            f(k,0,y)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return;
}

void Mpow(ll **p1,ll **ans,ll n,ll y,ll m)
{
    if(y==0)
    {
        Miden(ans,n);
        return;
    }
    ll t[n][n];
    Mpow(p1,(ll **)t,n,y/2,m);
    ll z[n][n];
    Mmult((ll **)t,(ll **)t,(ll **)z,n,n,n,m);
    if(y%2)
    {
        Mmult((ll **)z,p1,ans,n,n,n,m);
    }
    else
    {
        Miden((ll **)t,n);
        Mmult((ll **)z,(ll **)t,ans,n,n,n,m);
    }
    return;
}



void debg(ll *arr,ll l,ll r)
{
  f(i,l,r+1) pr1(arr[i])
  nl
}


void exit()
{
  cout<<"-1\n";
  exit(0);
}




    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        

    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }



 



string s,s1,s2,s3;
ll n,m,r,l,dp[252][252][252],q;
ll nearest[100005][26];




ll Get(ll idx,ll c)
{
  if(idx>l-1) return -1;
  if(nearest[idx][c]==infi) return -1;
  return nearest[idx][c];
}

void func()
{
  cin>>l>>q;
  cin>>s;
  
  ll x[26];
  f(i,0,26) x[i]=infi;

  fi(i,0,l) 
  {
    x[s[i]-'a']=i;
    f(j,0,26) nearest[i][j]=x[j];
  }
  
  f(i,0,252) f(j,0,252) f(z,0,252) dp[i][j][z]=infi;
  dp[0][0][0]=-1;

  


  while(q--)
  {
    char ch;
    cin>>ch;
    if(ch=='+')
    {
       ll idx;
       char xx;
       cin>>idx>>xx;
       if(idx==1)
       {
         s1.pb(xx);
         ll tt=sz(s1);
         f(j,0,sz(s2)+1)
         {
           f(z,0,sz(s3)+1)
           {
              if(tt>0 && dp[tt-1][j][z]!=infi && Get(dp[tt-1][j][z]+1,s1[tt-1]-'a')!=-1) 
              {
                dp[tt][j][z]=min(dp[tt][j][z],Get(dp[tt-1][j][z]+1,s1[tt-1]-'a'));
              } 

              if(j>0 && dp[tt][j-1][z]!=infi && Get(dp[tt][j-1][z]+1,s2[j-1]-'a')!=-1 )
              {
                dp[tt][j][z]=min(dp[tt][j][z],Get(dp[tt][j-1][z]+1,s2[j-1]-'a'));
              }

              if(z>0 && dp[tt][j][z-1]!=infi && Get(dp[tt][j][z-1]+1,s3[z-1]-'a')!=-1)
              {
                dp[tt][j][z]=min(dp[tt][j][z],Get(dp[tt][j][z-1]+1,s3[z-1]-'a'));
              }
           }
         }


         if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
         else cout<<"YES\n";

       }
       else if(idx==2)
       {
         s2.pb(xx);
         ll tt=sz(s2);
         f(i,0,sz(s1)+1)
         {
           f(z,0,sz(s3)+1)
           {
              if(i>0 && dp[i-1][tt][z]!=infi && Get(dp[i-1][tt][z]+1,s1[i-1]-'a')!=-1) 
              {
                dp[i][tt][z]=min(dp[i][tt][z],Get(dp[i-1][tt][z]+1,s1[i-1]-'a'));
              } 

              if(tt>0 && dp[i][tt-1][z]!=infi && Get(dp[i][tt-1][z]+1,s2[tt-1]-'a')!=-1 )
              {
                dp[i][tt][z]=min(dp[i][tt][z],Get(dp[i][tt-1][z]+1,s2[tt-1]-'a'));
              }

              if(z>0 && dp[i][tt][z-1]!=infi && Get(dp[i][tt][z-1]+1,s3[z-1]-'a')!=-1)
              {
                dp[i][tt][z]=min(dp[i][tt][z],Get(dp[i][tt][z-1]+1,s3[z-1]-'a'));
              }
           }
         }

         if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
         else cout<<"YES\n";
       }
       else
       {
         s3.pb(xx);
         ll tt=sz(s3);
         f(i,0,sz(s1)+1)
         {
           f(j,0,sz(s2)+1)
           {
              if(i>0 && dp[i-1][j][tt]!=infi && Get(dp[i-1][j][tt]+1,s1[i-1]-'a')!=-1) 
              {
                dp[i][j][tt]=min(dp[i][j][tt],Get(dp[i-1][j][tt]+1,s1[i-1]-'a'));
              } 

              if(j>0 && dp[i][j-1][tt]!=infi && Get(dp[i][j-1][tt]+1,s2[j-1]-'a')!=-1 )
              {
                dp[i][j][tt]=min(dp[i][j][tt],Get(dp[i][j-1][tt]+1,s2[j-1]-'a'));
              }

              if(tt>0 && dp[i][j][tt-1]!=infi && Get(dp[i][j][tt-1]+1,s3[tt-1]-'a')!=-1)
              {
                dp[i][j][tt]=min(dp[i][j][tt],Get(dp[i][j][tt-1]+1,s3[tt-1]-'a'));
              }
           }
         }

         if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
         else cout<<"YES\n";
       }

    }

    else
    {
      ll idx;
      cin>>idx;
      if(idx==1)
      { 
        ll tt=sz(s1);
        f(j,0,sz(s2)+1) f(z,0,sz(s3)+1) dp[tt][j][z]=infi;
        s1.pop_back();
        if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
        else cout<<"YES\n";
      }
      else if(idx==2)
      {
        ll tt=sz(s2);
        f(i,0,sz(s1)+1) f(z,0,sz(s3)+1) dp[i][tt][z]=infi;
        s2.pop_back();
        if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
        else cout<<"YES\n";
      }
      else
      {
        ll tt=sz(s3);
        f(i,0,sz(s1)+1) f(j,0,sz(s2)+1) dp[i][j][tt]=infi;
        s3.pop_back();
        if(dp[sz(s1)][sz(s2)][sz(s3)]==infi) cout<<"NO\n";
        else cout<<"YES\n";
      }
    }

  }
  

}


int main()
{
    fast

    

    

    

    


    
    ll ntc=1;
    


    f(i,1,ntc+1)
    {
      

      func();
    }
    return 0;
}
