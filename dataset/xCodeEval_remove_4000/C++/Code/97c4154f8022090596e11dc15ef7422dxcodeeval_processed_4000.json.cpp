        



using namespace std;












void show(vector<int> a)
{for (int i = 0; i < a.size(); i++)
{cout << a[i] << " ";}cout << endl;}
void show(vector<vector<int>> a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printTime(clock_t begin)
{
    printf("%.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);

}






void show(vector<int> a){return;}
void show(vector<vector<int>> a){return;}
void printTime()
{return;}




























typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int,pi> tri;
typedef pair<pi,int> rtri;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umi;
typedef map<int,int> mi;


const int MOD = 1e9 + 7;
const int md=M2;

int Power(int n, int x) {int ans = 1;while (x > 0) {if (x & 1) ans = (ans * n) % md;
n = (n * n) % md;x = x >> 1;}return ans;}

vl fact, inv;

void inverse(ll n)
{if(n>=inv.size()){ll size=inv.size();size=size==0? 1:size;
inv.resize(n + 1);inv[0] = 1;
for (ll i = size; i <= n; i++)inv[i] = Power(fact[i], md - 2);}}

void factorial(ll n)
{if(n>=fact.size()){ll size=fact.size();size=size==0? 1:size;
fact.resize(n + 1);fact[0] = 1;for (ll i = size; i <= n; i++)
fact[i] = (fact[i - 1] * i) % md;
}}

ll ncr(ll n, ll r) { return (((fact[n] * inv[r]) % md) * inv[n - r]) % md; }

vl id0(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    vl ans;
    for (int p=2; p<=n; p++)
       if (prime[p])
          ans.pb(p);
    return ans;
}
ll NcR(int n, int r)
{long long p = 1, k = 1;if (n - r < r)r = n - r;if (r != 0) {while (r) {p *= n;k *= r;
long long m = gcd(p, k);p /= m;k /= m;n--;r--;}
}else p = 1;return p;

}
bool sortasc(const rtri a,const rtri b) 

{
    return a.second<b.second;
}
bool sortdesc(const int a,const int b) 

{
    return a>b;
}






const int N = 2e5 + 5;

void q1();void q2();void q3();void q4();void q6();void q7();void q8();
void q9();void q10();void q12();void q13();

int32_t main()
{
    clock_t begin = clock();
    
	freopen("input.txt", "r", stdin);
	

    
    fast();
    

    {
        q13();
    }
    


    return 0;
}
void q13()
{
    int n;
    cin>>n;
    vi arr(n);
    for (int ni = 0; ni < n; ni++)
    {
        cin>>arr[ni];
    }
    vi digitsum;
    int ds=0;
    for (int dig = 1; dig <= 10; dig++)
    {
        ds=0;
        int factor=pow(10,dig-1);
        for (int i = 0; i < n; i++)
        {
            ds=ds + (arr[i]/factor)%10;
        }
        debug(ds);
        digitsum.pb(n*ds);
        digitsum.pb(n*ds);
    }
    show(digitsum);
    int ans=0;
    for (int i = 0; i < sz(digitsum); i++)
    {
        int factor=Power(10,i);
        debug(factor);
        ans=(ans+((digitsum[i]%M2)*factor)%M2)%M2;
        debug(ans);
    }
    cout<<ans%M2<<endl;





}
void q12()
{
    int n,b,a;
    cin>>n>>b>>a;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int currentb=b,currenta=a;
    int seg=0;
    for (int i = 0; i < n; i++)
    {
        if(currenta <=0 and currentb<=0)
        {
            cout<<seg<<endl;
            return;
            break;
        }
        if(arr[i]==1)
        {
            if(currenta<a and currentb>0)
            {
                currentb--;
                currenta++;
            }
            else if(currentb==0)
            {
                currenta--;
            }
            else if(currenta==a)
            {
                currenta--;
            }
        }
        else if(arr[i]==0)
        {
            if(currenta!=0)
            {
                currenta--;
            }
            else
            {
                currentb--;
            }

        }
        seg++;
    }
    cout<<seg<<endl;



}
void q10()
{
    int n;
    cin>>n;
    vi arr(n),brr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>brr[i];
    }
    int zerozero=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0 and brr[i]==0)
            zerozero++;
    }

    map<pi,int> mansi;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=0)
        {
            int temp=gcd(abs(brr[i]),abs(arr[i]));

            if(brr[i]==0)
            {
                mansi[{0,1}]++;
            }
            else if(arr[i]>0 and brr[i]<0)
            {
                mansi[{-1*brr[i]/temp,arr[i]/temp}]++;
            }
            else if(arr[i]>0 and brr[i]>0)
            {
                mansi[{-1*brr[i]/temp,arr[i]/temp}]++;
            }
            else if(arr[i]<0 and brr[i]<0)
            {
                mansi[{brr[i]/temp,-1*arr[i]/temp}]++;
            }
            else if(arr[i]<0 and brr[i]>0)
            {
                mansi[{brr[i]/temp,-1*arr[i]/temp}]++;
            }

        }
    }
    int maxele=0;
    for (auto &&i : mansi)
    {
        maxele=max(maxele,i.S);
    }
    cout<<maxele+zerozero<<endl;




}

void q9()
{
    int n,m;
    cin>>n>>m;
    vi adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i < n+1; i++)
    {
        sort(all(adj[i]),greater<int> ());
    }
    vector<bool> visited(n+1,false);
    

    

    minpq mansi;
    mansi.push(1);
    visited[1]=1;
    while(!mansi.empty())
    {
        int v=mansi.top();
        mansi.pop();
        cout<<v<<" ";
        for (auto &&i : adj[v])
        {
            if(!visited[i])
            {
                mansi.push(i);
                visited[i]=1;
            }
        }


    }
    cout<<endl;


}

void q8()
{
    int n;
    cin>>n;
    vi arr(n);
    map<int,int> roshan;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        roshan[arr[i]]++;
    }
    vi freq;
    for (auto &&i : roshan)
    {
        freq.pb(i.S);
    }
    sort(all(freq),greater<int>());
    show(freq);
    int current=freq.front()-1;
    int ans=freq.front();
    for (int i = 1; i < sz(freq); i++)
    {
        debug3(i,current,ans);
        if(current<=0)
            break;
        if(freq[i]>=current)
        {
            ans+=current;
            current--;
        }
        else
        {
            ans+=freq[i];
            current=freq[i]-1;
        }
    }
    cout<<ans<<endl;




}
void q7()
{
    int n;
    cin>>n;
    vi arr(n);
    map<int,int> roshan;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        roshan[arr[i]]++;
    }
    int maxele=0,maxfreq=0;
    for (auto &&i : roshan)
    {
        if(i.S>maxfreq)
        {
            maxfreq=i.S;
            maxele=i.F;
        }
    }
    int first=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==maxele)
        {
            first=i;
            break;
        }
    }
    cout<<n-maxfreq<<endl;
    int ptr=first-1;
    while(ptr>=0)
    {
        if(arr[ptr]==maxele)
        {
            ptr--;
            continue;
        }
        else if(arr[ptr]>maxele)
        {
            cout<<2<<" "<<ptr+1<<" "<<ptr+1+1<<endl;
            ptr--;
        }
        else if(arr[ptr]<maxele)
        {
            cout<<1<<" "<<ptr+1<<" "<<ptr+1+1<<endl;
            ptr--;
        }
    }
    ptr=first+1;
    while(ptr<n)
    {
        if(arr[ptr]==maxele)
        {
            ptr++;
            continue;
        }
        else if(arr[ptr]>maxele)
        {
            cout<<2<<" "<<ptr+1<<" "<<ptr<<endl;
            ptr++;
        }
        else if(arr[ptr]<maxele)
        {
            cout<<1<<" "<<ptr+1<<" "<<ptr<<endl;
            ptr++;
        }
    }







}

void q6()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int i = 1; i < n; i++)
    {
        if(s[i]==s[i-1])
        {
            ans++;
            s[i]='
        }

    }
    cout<<ans<<endl;
    for (int i = 0; i < n; i++)
    {
        if(s[i]!='
            cout<<s[i];
        else
        {
            if(i!=n-1)
            {
                if(s[i-1]!='G' and s[i+1]!='G')
                {
                    cout<<"G";
                    s[i]='G';
                }
                else if(s[i-1]!='R' and s[i+1]!='R')
                {
                    cout<<"R";
                    s[i]='R';
                }
                else if(s[i-1]!='B' and s[i+1]!='B')
                {
                    cout<<"B";
                    s[i]='B';
                }
            }
            if(i==n-1)
            {
                if(s[i-1]!='G')
                {
                    cout<<"G";
                    s[i]='G';
                }
                else if(s[i-1]!='R')
                {
                    cout<<"R";
                    s[i]='R';
                }
                else if(s[i-1]!='B')
                {
                    cout<<"B";
                    s[i]='B';
                }

            }
        }

    }
    cout<<endl;

}

void q4()
{
    int m;
    cin>>m;
    map<pi,int> value;
    vpi arr(m);
    for (int j = 0; j < m; j++)
    {

        string s;
        cin>>s;
        int n=sz(s);
        int a=0,b=0,c=0;
        if(s[n-2]=='/')
        {
            c=s[n-1]-'0';
        }
        else
        {
            c=s[n-1]-'0'+10*(s[n-2]-'0');
        }
        int i=1;
        vi arr_a;
        while(s[i]!='+')
        {
            arr_a.pb(s[i]-'0');
            i++;
        }
        i++;
        vi arr_b;
        while(s[i]!=')')
        {
            arr_b.pb(s[i]-'0');
            i++;
        }
        reverse(all(arr_a));
        reverse(all(arr_b));
        for (int i = 0; i < sz(arr_a); i++)
        {
            a+=pow(10,i)*arr_a[i];
        }
        for (int i = 0; i < sz(arr_b); i++)
        {
            b+=pow(10,i)*arr_b[i];
        }
        int temp1=a+b;
        int temp2=gcd(temp1,c);
        arr[j]={temp1/temp2,c/temp2};
        value[{temp1/temp2,c/temp2}]++;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<value[arr[i]]<<" ";
    }
    cout<<endl;



}

void q3()
{
    int n;
    cin>>n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int maxele=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxele=max(maxele,arr[i]);
    }
    debug(maxele);
    vi diff(n);
    int mindiff;
    for (int i = 0; i < n; i++)
    {
        diff[i]=maxele-arr[i];
        

    }
    show(diff);
    int z=diff[0];
    for (auto &&i : diff)
    {
        if(i!=0)
        z=gcd(z,i);
    }
    debug(z);
    int y=0;
    for (auto &&i : diff)
    {
        y+=i/z;

    }
    cout<<y<<" "<<z<<endl;

}

void q2()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i = 2; i <= n-1; i++)
    {
        ans+=(i*(i+1));
    }
    cout<<ans<<endl;

}

void q1()
{
    int n;
    cin>>n;
    vi choc(n);
    for (int i = 0; i < n; i++)
    {
        cin>>choc[i];
    }
    vi prizes(5);
    for (int i = 0; i < 5; i++)
    {
        cin>>prizes[i];
    }
    vi freq(5);
    int points=0;
    for (auto &&i : choc)
    {
        points+=i;
        int index=upper_bound(all(prizes),points)-prizes.begin()-1;
        if(index<0)
            continue;
        while(index>=0)
        {
            int num=points/prizes[index];
            freq[index]+=num;
            points-=prizes[index]*num;
            index=upper_bound(all(prizes),points)-prizes.begin()-1;

        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<freq[i]<<" ";
    }
    cout<<endl<<points<<endl;




}
