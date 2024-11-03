

#include <bits/stdc++.h>
#define ff first
#define ss second
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define int long long
#define pb push_back
#define pp pop_back
#define pf pop_front
#define ll long long
using namespace std ;

const int N=5e5;
int a[N],b[N];
deque< pair< int , int > >dq,dq2;
pair<int ,int>all[N],p[N];
map<int,int>ind;
 int ans[N];
int32_t main()
{
     int t; cin>>t;
     while(t--)
     {
         dq.clear();
         dq2.clear();
           ind.clear();

          int n; cin>>n;
          for( int i=1;i<=n;i++)
          {
               cin>>a[i];
                 ind[ a[i] ]=i;
                 p[i].ff=a[i];
            dq.pb( { a[i],i } );
               ans[i]=0;
          }
          for( int i=1;i<=n;i++)
          {
                cin>>b[i];
                p[i].ss=b[i];
                all[i].ff=a[i];
                all[i].ss=b[i];
                dq2.pb( { b[i],i } );

          }
          sort(dq.begin(),dq.end());
          sort(dq2.begin(),dq2.end());
          sort(p+1,p+n+1);
           int mxf=0,mxs=0;
           for( int i=1;i<=n;i++)
           {

                mxf=max( mxf, p[i].ff );
                mxs=max( mxs , p[i].ss );
                while(1)
                {
                     bool is=1;
                     if( dq.size() )
                     {
                         while( dq.size() && dq.front().ff<=mxf )
                         {
                             mxs=max( mxs, all[ dq.front().ss ].ss );
                             dq.pf();

                         is=0;
                         }

                     }
                     if( dq2.size() )
                     {
                         while( dq2.size() && dq2.front().ff<=mxs )
                         {
                             mxf=max(mxf,   all[ dq2.front().ss ].ff  );
                             dq2.pf();
                     is=0;
                         }

                     }

                    if(is) break;

                }
                if(dq.size() ==0 || dq2.size() ==0 )ans[ ind[ p[i].ff ] ]=1;

           }
           for( int i=1;i<=n;i++)cout<<ans[i]; cout<<endl;


     }

}
