
    
    
    
    
    

    
    
    
    using namespace std;


    int maxx(map<int,int> &x){
        int maax=0;
        for(int i=0;i<x.size();i++)
            if(x[i]>maax)
            maax=x[i];
     return maax;}

    int minn(map<int,int> &x){
        int maax=10000000000000;
        for(int i=0;i<2000005;i++)
            if(x[i]<maax)
            maax=x[i];
     return maax;}
    ll gcd(ll a, ll b) {
        if (a == 0 || b == 0)return abs(a - b);
        ll res = a % b;
        while (res) {
            a = b;
            b = res;
            res = a % b;
        }
        return b;
    }
    ll lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    int to_int(string s){
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;}
    void ff(string t){string x;
    for(int i=t.size();i>=0;i--)
        x+=t[i];
    t=x;
    }
    void copy_array(int *a,int *b,int n){
    f(i,0,n)
    b[i]=a[i];}

    int prime(int x){bool f=true;
    for(int i=2;i<x;i++)
        if(x%i==0)
        {f=false;break;}
        return f;}
    int diff(string s,int n){
    bool f=false;
    for(int i=0;i<n-1;i++)
        if(s[i]!=s[i+1])
            f=true;
        return f;}

    bool id2(double N)
    {    int X = N;
        double temp2 = N - X;
        if (temp2 > 0) {
            return true;}
    return false;
    }
    void sort_row(int a[][101],int x,int m){
       for(int j=0;j<m;j++)
        for(int i=j+1;i<m;i++)
        if(a[x][i]<a[x][j])
        swap(a[x][i],a[x][j]);
       }
       void id1(int a[][101],int x,int m){
       for(int j=m-1;j>=0;j--)
        for(int i=j-1;i>=0;i--)
        if(a[x][i]<a[x][j])
        swap(a[x][i],a[x][j]);
       }
       ll fact(ll x){
       ll sum=1;
       for(int i=1;i<=x;i++)
        sum*=i;
        return sum;
       }
          ll id3(ll n,ll r){
       return fact(n)/(fact(n-r)*fact(r))*1ll;}

    int id0(int n)
    {   int num = n;
        int dec_value = 0;
        int base = 1;
        int temp = num;
        while (temp) {
            int last_digit = temp % 10;
            temp = temp / 10;
            dec_value += last_digit * base;
            base = base * 2;}
            return dec_value;}

    int pprime(int x){
    for(int i=x+1;;i++)
        if(prime(i))
        return i;}
int m;
    bool cm(pair<string,int> x,pair<string,int> y){
    string a=x.first;
    string b=y.first;
    for(int j=1;j<=m;j++){
        int i=j-1;
        if(a[i]>b[i]&&!(j&1))
        return 1;
    else if(a[i]<b[i]&&!(j&1))
        return 0;
    if(a[i]<b[i]&&(j&1))
        return 1;
    else if(a[i]>b[i]&&(j&1))
        return 0;}
          assert(0);
          }
    signed main()
    {
    

    


    ios::sync_with_stdio(0);
    cin.tie(0);

    typedef vector<int> vi;
    typedef multiset<int> msi;
    typedef vector<char> vc;
    typedef set<int> si;
    typedef set<char> sc;
    typedef multiset<char> msc;

    int T=1;

    while(T--){
      int n;
      cin>>n>>m;
     pair<string,int> s[n];
      for(int i=0;i<n;i++)
        cin>>s[i].first,s[i].second=i+1;
sort(s,s+n,cm);

for(auto g:s)cout<<g.second<<" ";cout<<endl;


    }
        return 0;}
