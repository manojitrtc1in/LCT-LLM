#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ll long long

using namespace std;

void solve()
{
    int n,d12,d23,d13;
    cin>>n>>d12>>d23>>d13;
    int d21=d12,d32=d23,d31=d13;
    if(n==3)
    {
        if(d12+d23+d31==4)
        {
            cout<<"Yes\n";
            if(d12==2)
               cout<<"3 1\n"<<"3 2\n";
            if(d13==2)
               cout<<"2 1\n"<<"2 3\n";
            if(d23==2)
               cout<<"1 2\n"<<"1 3\n";
            return;
        }
        cout<<"No\n";
        return;
    }
    if(d23==abs(d12-d13))
    {
        cout<<"Yes\n";
        if(d12<d13)
        {
            int last=1,next=4;
            for(int i=1; i<d12; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 2\n";
            last=2;
            for(int i=1; i<d13-d12; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 3\n";
            last=1;
            for(int i=d13+1; i<n; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            return;
        }
        int last=1,next=4;
        for(int i=1; i<d13; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=3;
        for(int i=1; i<d12-d13; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=1;
        for(int i=d12+1; i<n; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d13==abs(d21-d23))
    {
        cout<<"Yes\n";
        if(d21<d23)
        {
            int last=2,next=4;
            for(int i=1; i<d21; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 1\n";
            last=1;
            for(int i=1; i<d13; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 3\n";
            last=2;
            for(int i=d23+1; i<n; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            return;
        }
        int last=2,next=4;
        for(int i=1; i<d23; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=3;
        for(int i=1; i<d31; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=2;
        for(int i=d21+1; i<n; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d12==abs(d31-d32))
    {
        cout<<"Yes\n";
        if(d31<d32)
        {
            int last=3,next=4;
            for(int i=1; i<d31; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 1\n";
            last=1;
            for(int i=1; i<d12; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            cout<<last<<" 2\n";
            last=3;
            for(int i=d32+1; i<n; i++)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            return;
        }
        int last=3,next=4;
        for(int i=1; i<d32; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=2;
        for(int i=1; i<d21; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=3;
        for(int i=d31+1; i<n; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d13>=2 && d23==d21+d13 && d23<n)
    {
        cout<<"Yes\n";
        cout<<"4 1\n";
        int last=1,next=5;
        for(int i=1; i<d12; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=4;
        for(int i=1; i<=d13-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=3;
        for(int i=d23+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d23>=2 && d13==d12+d23 && d13<n)
    {
        cout<<"Yes\n";
        cout<<"4 2\n";
        int last=2,next=5;
        for(int i=1; i<d21; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=4;
        for(int i=1; i<=d23-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=3;
        for(int i=d13+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d12>=2 && d32==d31+d12 && d32<n)
    {
        cout<<"Yes\n";
        cout<<"4 1\n";
        int last=1,next=5;
        for(int i=1; i<d13; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=4;
        for(int i=1; i<=d12-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=2;
        for(int i=d32+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d32>=2 && d12==d13+d32 && d12<n)
    {
        cout<<"Yes\n";
        cout<<"4 3\n";
        int last=3,next=5;
        for(int i=1; i<d31; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=4;
        for(int i=1; i<=d32-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=2;
        for(int i=d12+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d21>=2 && d31==d32+d21 && d31<n)
    {
        cout<<"Yes\n";
        cout<<"4 2\n";
        int last=2,next=5;
        for(int i=1; i<d23; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        last=4;
        for(int i=1; i<=d21-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=1;
        for(int i=d31+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d31>=2 && d21==d23+d31 && d21<n)
    {
        cout<<"Yes\n";
        cout<<"4 3\n";
        int last=3,next=5;
        for(int i=1; i<d23; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        last=4;
        for(int i=1; i<=d31-2; i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        last=1;
        for(int i=d21+1;i<n;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        return;
    }
    if(d31==d32 && d12==2 && d31<=n-2)
    {
        cout<<"Yes\n";
        for(int i=4;i<=2+d31;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d31<<" 1\n";
        cout<<2+d31<<" 2\n";
        for(int i=3+d31;i<=n;i++)
            cout<<2+d31<<" "<<i<<"\n";
        return;
    }
    if(d21==d23 && d13==2 && d21<=n-2)
    {
        cout<<"Yes\n";
        if(d21==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(i!=2)
                   cout<<"2 "<<i<<"\n";
            }
            return;
        }
        cout<<"2 4\n";
        for(int i=5;i<=2+d21;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d21<<" 1\n";
        cout<<2+d21<<" 3\n";
        for(int i=3+d21;i<=n;i++)
            cout<<2+d21<<" "<<i<<"\n";
        return;
    }
    if(d12==d13 && d23==2 && d12<=n-2)
    {
        cout<<"Yes\n";
        if(d12==1)
        {
            for(int i=2;i<=n;i++)
                cout<<"1 "<<i<<"\n";
            return;
        }
        cout<<"1 4\n";
        for(int i=5;i<=2+d12;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d12<<" 2\n";
        cout<<2+d12<<" 3\n";
        for(int i=3+d12;i<=n;i++)
            cout<<2+d12<<" "<<i<<"\n";
        return;
    }
    if(d32>d31 && d32>=d21 && d12==d32-d31+2 && d32<=n-2)
    {
        cout<<"Yes\n";
        for(int i=4;i<=2+d31;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d31<<" 1\n";
        for(int i=3+d31;i<=2+d32;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d32<<" "<<2<<"\n";
        for(int i=3+d32;i<=n;i++)
            cout<<"2 "<<i<<"\n";
        return;
    }
    if(d31>d32 && d31>=d21 && d12==d31-d32+2 && d31<=n-2)
    {
        cout<<"Yes\n";
        for(int i=4;i<=2+d32;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d32<<" 2\n";
        for(int i=3+d32;i<=2+d31;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d31<<" 1\n";
        for(int i=3+d31;i<=n;i++)
            cout<<"1 "<<i<<"\n";
        return;
    }
    if(d23>d21 && d23>=d31 && d13==d23-d21+2 && d23<=n-2)
    {
        cout<<"Yes\n";
        int last=2,next=4;
        for(int i=1;i<d21;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 1\n";
        for(int i=last+1;i<=2+d23;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d23<<" 3\n";
        for(int i=3+d23;i<=n;i++)
            cout<<"3 "<<i<<"\n";
        return;
    }
    if(d21>d23 && d21>=d31 && d13==d21-d23+2 && d21<=n-2)
    {
        cout<<"Yes\n";
        int last=2,next=4;
        for(int i=1;i<d23;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        for(int i=last+1;i<=2+d21;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d21<<" 1\n";
        for(int i=3+d21;i<=n;i++)
            cout<<"1 "<<i<<"\n";
        return;
    }
    if(d13>d12 && d13>=d32 && d23==d13-d12+2 && d13<=n-2)
    {
        cout<<"Yes\n";
        int last=1,next=4;
        for(int i=1;i<d12;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 2\n";
        for(int i=last+1;i<=2+d13;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d13<<" 3\n";
        for(int i=3+d13;i<=n;i++)
            cout<<"3 "<<i<<"\n";
        return;
    }
    if(d12>d13 && d12>=d32 && d23==d12-d13+2 && d12<=n-2)
    {
        cout<<"Yes\n";
        int last=1,next=4;
        for(int i=1;i<d13;i++)
        {
            cout<<last<<" "<<next<<"\n";
            last=next,next++;
        }
        cout<<last<<" 3\n";
        for(int i=last+1;i<=2+d12;i++)
            cout<<i-1<<" "<<i<<"\n";
        cout<<2+d12<<" 2\n";
        for(int i=3+d12;i<=n;i++)
            cout<<"2 "<<i<<"\n";
        return;
    }
    for(int i=4;i<=2+d12;i++)
    {
        int k=d13-(i-2);
        if(d23==3+d12-i+k+1 && n>=d12+2+k && k>=0)
        {
            cout<<"Yes\n";
            int last=1,next=4;
            while(last<i)
            {
                cout<<last<<" "<<next<<"\n";
                last=next,next++;
            }
            if(k)
               cout<<i<<" "<<3+d12<<"\n";
            for(int j=4+d12;j<=2+d12+k;j++)
                cout<<j-1<<" "<<j<<"\n";
            cout<<2+d12+k<<" 3\n";
            for(int j=i+1;j<=2+d12;j++)
                cout<<j-1<<" "<<j<<"\n";
            cout<<2+d12<<" 2\n";
            for(int j=3+d12+k;j<=n;j++)
                cout<<i<<" "<<j<<"\n";
            return;
        }
    }
    cout<<"No\n";
}
int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }
