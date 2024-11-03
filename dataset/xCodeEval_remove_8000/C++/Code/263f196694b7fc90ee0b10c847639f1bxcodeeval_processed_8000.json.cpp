






















using namespace std;


using namespace __gnu_pbds;





template<class T> using ordered_class_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int n,m,k,s,t,d[sz],chos[sz];
ll dp[sz][205],w[sz];
set<pair<pair<int,int>,int> >st;
deque<pair<bool,int>>v[sz];


ll solve(ll tim ,ll rim)
{ if(tim>n) re 0;
  if(dp[tim][rim]!=-1)
  re dp[tim][rim];
  

  ll fi=OO,se=OO,i=chos[tim];
    if(i)
    {fi=solve(d[i]+1,rim)+w[i];
      if(rim)
      se=solve(tim+1,rim-1);
    }
    else
      fi=solve(tim+1,rim);
  

  re dp[tim][rim]=min(fi,se);
}


void push(ll tim)
{ for(int y=0;y<v[tim].size();y++)
  {int idx=v[tim][y].S;
     if(v[tim][y].F==0)
     st.insert({{-w[idx],-d[idx]},idx});
  }
}
void in(ll tim)
{if(!st.empty())
 chos[tim]=(*st.begin()).S;
}
void del(ll tim)
{ for(int y=0;y<v[tim].size();y++)
  {int idx=v[tim][y].S;
    if(v[tim][y].F)
    st.erase({{-w[idx],-d[idx]},idx});
  }
}


void choose()
{ for(int tim=1;tim<=n;tim++)
  {
    push(tim);
    in(tim);
    del(tim);
  }
}


int main()
{
    yalla;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
     {cin>>s>>t>>d[i]>>w[i];
      v[s].push_back({0,i});
      v[t].push_back({1,i});
     }
    

    choose();
    memset(dp,-1,sizeof dp) ;
    cout<<solve(1,m)<<endl;
    re 0;
}








