#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define pic pair<ll,char>
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii > 
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
signed main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    char arr[n+1][m+1];
    ll i,j;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        cin>>arr[i][j];
    pair < ll ,ll > dp[m][6];
    for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='T')
            cnt++;
          if(arr[j][i]!='A')
            k++;
        }
        else
        {
          if(arr[j][i]!='A')
            cnt++;
          if(arr[j][i]!='T')
            k++;
        }
      }
        if(cnt>k)
          dp[i][0] = mp(k,1);
        else
          dp[i][0] = mp(cnt,0);
        

      
    }
        for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='T')
            cnt++;
          if(arr[j][i]!='G')
            k++;
        }
        else
        {
          if(arr[j][i]!='G')
            cnt++;
          if(arr[j][i]!='T')
            k++;
        }}
                if(cnt>k)
          dp[i][1] = mp(k,1);
        else
          dp[i][1] = mp(cnt,0);
      
    }
        for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='T')
            cnt++;
          if(arr[j][i]!='C')
            k++;
        }
        else
        {
          if(arr[j][i]!='C')
            cnt++;
          if(arr[j][i]!='T')
            k++;
        }}
                if(cnt>k)
          dp[i][2] = mp(k,1);
        else
          dp[i][2] = mp(cnt,0);
      
    }
        for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='A')
            cnt++;
          if(arr[j][i]!='G')
            k++;
        }
        else
        {
          if(arr[j][i]!='G')
            cnt++;
          if(arr[j][i]!='A')
            k++;
        }}
                if(cnt>k)
          dp[i][3] = mp(k,1);
        else
          dp[i][3] = mp(cnt,0);
      
    }
        for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='A')
            cnt++;
          if(arr[j][i]!='C')
            k++;
        }
        else
        {
          if(arr[j][i]!='C')
            cnt++;
          if(arr[j][i]!='A')
            k++;
        }}
                if(cnt>k)
          dp[i][4] = mp(k,1);
        else
          dp[i][4] = mp(cnt,0);
      
    }
        for(i=0;i<m;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<n;j++)
      {
        if(j%2==0)
        {
          if(arr[j][i]!='G')
            cnt++;
          if(arr[j][i]!='C')
            k++;
        }
        else
        {
          if(arr[j][i]!='C')
            cnt++;
          if(arr[j][i]!='G')
            k++;
        }}
                if(cnt>k)
          dp[i][5] = mp(k,1);
        else
          dp[i][5] = mp(cnt,0);
      
    }
    ll roworcol,pehla,dusra;
    ll ans = n*m;
    ll cnt = 0,k = 0;
    for(i=0;i<m;i++)
    {
      if(i%2==0)
        cnt+=dp[i][0].fi,k+=dp[i][5].fi;
      else
        cnt+=dp[i][5].fi,k+=dp[i][0].fi;
    }
    if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 0;
        pehla = 5;
        dusra = 0;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 0;
        pehla = 0;
        dusra = 5;
      }
    }
    cnt = 0,k = 0;
    for(i=0;i<m;i++)
    {
      if(i%2==0)
        cnt+=dp[i][1].fi,k+=dp[i][4].fi;
      else
        cnt+=dp[i][4].fi,k+=dp[i][1].fi;
    }
        if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 0;
        pehla = 4;
        dusra = 1;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 0;
        pehla = 1;
        dusra = 4;
      }
    }
    cnt = 0,k = 0;
    for(i=0;i<m;i++)
    {
      if(i%2==0)
        cnt+=dp[i][2].fi,k+=dp[i][3].fi;
      else
        cnt+=dp[i][3].fi,k+=dp[i][2].fi;
    }
    if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 0;
        pehla = 3;
        dusra = 2;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 0;
        pehla = 2;
        dusra = 3;
      }
    }
    pair < ll ,ll > dpp[n][6];
    for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='T')
            cnt++;
          if(arr[i][j]!='A')
            k++;
        }
        else
        {
          if(arr[i][j]!='A')
            cnt++;
          if(arr[i][j]!='T')
            k++;
        }}
        if(cnt>k)
          dpp[i][0] = mp(k,1);
        else
          dpp[i][0] = mp(cnt,0);
      
    }
for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='T')
            cnt++;
          if(arr[i][j]!='G')
            k++;
        }
        else
        {
          if(arr[i][j]!='G')
            cnt++;
          if(arr[i][j]!='T')
            k++;
        }}
                if(cnt>k)
          dpp[i][1] = mp(k,1);
        else
          dpp[i][1] = mp(cnt,0);
      
    }
    for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='T')
            cnt++;
          if(arr[i][j]!='C')
            k++;
        }
        else
        {
          if(arr[i][j]!='C')
            cnt++;
          if(arr[i][j]!='T')
            k++;
        }}
                if(cnt>k)
          dpp[i][2] = mp(k,1);
        else
          dpp[i][2] = mp(cnt,0);
      
    }
    for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='A')
            cnt++;
          if(arr[i][j]!='G')
            k++;
        }
        else
        {
          if(arr[i][j]!='G')
            cnt++;
          if(arr[i][j]!='A')
            k++;
        }}
                if(cnt>k)
          dpp[i][3] = mp(k,1);
        else
          dpp[i][3] = mp(cnt,0);
      
    }
    for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='A')
            cnt++;
          if(arr[i][j]!='C')
            k++;
        }
        else
        {
          if(arr[i][j]!='C')
            cnt++;
          if(arr[i][j]!='A')
            k++;
        }}
                if(cnt>k)
          dpp[i][4] = mp(k,1);
        else
          dpp[i][4] = mp(cnt,0);
      
    }
    for(i=0;i<n;i++)
    {
      ll cnt = 0;
      ll k = 0;
      for(j=0;j<m;j++)
      {
        if(j%2==0)
        {
          if(arr[i][j]!='G')
            cnt++;
          if(arr[i][j]!='C')
            k++;
        }
        else
        {
          if(arr[i][j]!='C')
            cnt++;
          if(arr[i][j]!='G')
            k++;
        }}
                if(cnt>k)
          dpp[i][5] = mp(k,1);
        else
          dpp[i][5] = mp(cnt,0);
      
    }
    cnt = 0,k = 0;
    for(i=0;i<n;i++)
    {
      if(i%2==0)
        cnt+=dpp[i][0].fi,k+=dpp[i][5].fi;
      else
        cnt+=dpp[i][5].fi,k+=dpp[i][0].fi;
    }
        if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 1;
        pehla = 5;
        dusra = 0;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 1;
        pehla = 0;
        dusra = 5;
      }
    }
    cnt = 0,k = 0;
    for(i=0;i<n;i++)
    {
      if(i%2==0)
        cnt+=dpp[i][1].fi,k+=dpp[i][4].fi;
      else
        cnt+=dpp[i][4].fi,k+=dpp[i][1].fi;
    }
        if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 1;
        pehla = 4;
        dusra = 1;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 1;
        pehla = 1;
        dusra = 4;
      }
    }
    cnt = 0,k = 0;
    for(i=0;i<n;i++)
    {
      if(i%2==0)
        cnt+=dpp[i][2].fi,k+=dpp[i][3].fi;
      else
        cnt+=dpp[i][3].fi,k+=dpp[i][2].fi;
    }
        if(cnt>k)
    {
      if(ans>k)
      {
        ans = k;
        roworcol = 1;
        pehla = 3;
        dusra = 2;
      }
    }
    else
    {
      if(ans>cnt)
      {
        ans = cnt;
        roworcol = 1;
        pehla = 2;
        dusra = 3;
      }
    }
    if(roworcol==0)
    {
  char ans[n+1][m+1];
      if(pehla==0)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][0].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'A');
            else
              ans[j][i] = ((j%2==1) ? 'T':'A');

          }
        }
      }
      if(pehla==1)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][1].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'G');
            else
              ans[j][i] = ((j%2==1) ? 'T':'G');

          }
        }
      }
      if(pehla==2)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][2].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'C');
            else
              ans[j][i] = ((j%2==1) ? 'T':'C');

          }
        }
      }
      if(pehla==3)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][3].sec==0)
              ans[j][i] = ((j%2==0) ? 'A':'G');
            else
              ans[j][i] = ((j%2==1) ? 'A':'G');

          }
        }
      }
            if(pehla==4)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][4].sec==0)
              ans[j][i] = ((j%2==0) ? 'A':'C');
            else
              ans[j][i] = ((j%2==1) ? 'A':'C');

          }
        }
      }
            if(pehla==5)
      {
        for(i=0;i<m;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][5].sec==0)
              ans[j][i] = ((j%2==0) ? 'G':'C');
            else
              ans[j][i] = ((j%2==1) ? 'G':'C');

          }
        }
      }
if(dusra==0)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][0].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'A');
            else
              ans[j][i] = ((j%2==1) ? 'T':'A');

          }
        }
      }
if(dusra==1)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][1].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'G');
            else
              ans[j][i] = ((j%2==1) ? 'T':'G');

          }
        }
      }
if(dusra==2)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][2].sec==0)
              ans[j][i] = ((j%2==0) ? 'T':'C');
            else
              ans[j][i] = ((j%2==1) ? 'T':'C');

          }
        }
      }
if(dusra==3)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][3].sec==0)
              ans[j][i] = ((j%2==0) ? 'A':'G');
            else
              ans[j][i] = ((j%2==1) ? 'A':'G');

          }
        }
      }
      if(dusra==4)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][4].sec==0)
              ans[j][i] = ((j%2==0) ? 'A':'C');
            else
              ans[j][i] = ((j%2==1) ? 'A':'C');

          }
        }
      }
      if(dusra==5)
      {
        for(i=0;i<m;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<n;j++){
            if(dp[i][5].sec==0)
              ans[j][i] = ((j%2==0) ? 'G':'C');
            else
              ans[j][i] = ((j%2==1) ? 'G':'C');

          }
        }
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
          cout<<ans[i][j];
        }
        cout<<"\n";
      }
    }
    else
    {
            char ans[n+1][m+1];
      if(pehla==0)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][0].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'A');
            else
              ans[i][j] = ((j%2==1) ? 'T':'A');

          }
        }
      }
      if(pehla==1)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][1].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'G');
            else
              ans[i][j] = ((j%2==1) ? 'T':'G');

          }
        }
      }
      if(pehla==2)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][2].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'C');
            else
              ans[i][j] = ((j%2==1) ? 'T':'C');

          }
        }
      }
      if(pehla==3)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][3].sec==0)
              ans[i][j] = ((j%2==0) ? 'A':'G');
            else
              ans[i][j] = ((j%2==1) ? 'A':'G');

          }
        }
      }
            if(pehla==4)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][4].sec==0)
              ans[i][j] = ((j%2==0) ? 'A':'C');
            else
              ans[i][j] = ((j%2==1) ? 'A':'C');

          }
        }
      }
            if(pehla==5)
      {
        for(i=0;i<n;i++)
        {
          if(i%2)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][5].sec==0)
              ans[i][j] = ((j%2==0) ? 'G':'C');
            else
              ans[i][j] = ((j%2==1) ? 'G':'C');

          }
        }
      }
if(dusra==0)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][0].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'A');
            else
              ans[i][j] = ((j%2==1) ? 'T':'A');

          }
        }
      }
if(dusra==1)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][1].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'G');
            else
              ans[i][j] = ((j%2==1) ? 'T':'G');

          }
        }
      }
if(dusra==2)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][2].sec==0)
              ans[i][j] = ((j%2==0) ? 'T':'C');
            else
              ans[i][j] = ((j%2==1) ? 'T':'C');

          }
        }
      }
if(dusra==3)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][3].sec==0)
              ans[i][j] = ((j%2==0) ? 'A':'G');
            else
              ans[i][j] = ((j%2==1) ? 'A':'G');

          }
        }
      }
      if(dusra==4)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][4].sec==0)
              ans[i][j] = ((j%2==0) ? 'A':'C');
            else
              ans[i][j] = ((j%2==1) ? 'A':'C');

          }
        }
      }
      if(dusra==5)
      {
        for(i=0;i<n;i++)
        {
          if(i%2==0)
            continue;
          for(j=0;j<m;j++){
            if(dpp[i][5].sec==0)
              ans[i][j] = ((j%2==0) ? 'G':'C');
            else
              ans[i][j] = ((j%2==1) ? 'G':'C');

          }
        }
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
          cout<<ans[i][j];
        }
        cout<<"\n";
      }
    }
    

}