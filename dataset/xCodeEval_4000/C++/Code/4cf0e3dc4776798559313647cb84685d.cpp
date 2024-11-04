

#include<bits/stdc++.h>











































#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;



#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")



#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
typedef long long int ll;
typedef vector<ll> vll;
#define mininfi -1000000007   

#define plusinfi 1000000007   

#define all(x) x.begin(),x.end()
#define fix(f,n) std::fixed<<std::setprecision(n)<<f

template <typename T>
void inpA (T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void inpV (vector<T> &vec, int n)
{
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i] ;
    }
}

template <typename T, size_t SIZE>
void outA (const T (&array)[SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
        std::cout << array[i] << " ";
}

template <typename T>
void outV (const vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " ;
    }
    cout << endl ;
}

template <typename T>
void outAptr(const T array[], size_t SIZE)
{
    
    
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
}

ll zer = 0, one = 1;        

string yes = "YES", no = "NO";      





void solve()
{
  int n,l,r;
  cin>>n>>l>>r;

  vector<int> a(n);

  for(int i=0;i<n+1;i++){

    int low=l/i;
    int high=r/i;

    low*=i;
    high*=i;

    if(high<l or low>r){
        cout<<"no"; return;
    }
    else a[i-1]=high;
  }
  cout<<"yes"<<endl;

  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<endl;
}




























































































































void dummy_func(){
    int a,b;
    int c = a+b;
    a++;
    b++;
    c = a-b;
}

























































































































































































const int N=2e5+3;
int a[N],   an[N];


void compute() {
    ll a,s,d,f,g;
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(auto& c:vec)cin>>c;

    map<ll,ll> ct;


    for(auto c:vec) ct[c]++;




    while((*ct.begin()).second > 1 || ct.size()>1)
    {
        map<ll,ll> ct2;
        vector<pair<ll,ll>> srt;
        for(auto c:ct)
        {
            srt.push_back(c);
        }
        for(int i=0;i<srt.size();i++)
        {
            ct2[0ll]+=max(0ll,srt[i].second-1);
            if(i>0)ct2[srt[i].first-srt[i-1].first]++;
        }
        if(ct2[0]==0) ct2.erase(0);
        ct=ct2;
    }
    cout<<(*ct.begin()).first<<endl;
}




























































































































void callFn(){
  int n, k;
        cin >> n >> k;
        int p[n], c[n];
        for(int i=0;i<n;i++)
        {
            cin >> p[i];
        }

        int ans = 1e9;

        for(int m=1;m<3000;m++) 

        {
            


            for(int i=0;i<n;i++) 

            {
                int ch = p[i] / m;

                ch = max(ch, 1);
                ch = min(ch, k);

                


                c[i] = p[i] / ch;

                


                if (abs(c[i] - m) > abs((p[i] / max(1, ch - 1)) - m))
                {
                    c[i] = p[i] / max(1, ch - 1);
                }
                if (abs(c[i] - m) > abs((p[i] / min(k, ch + 1)) - m))
                {
                    c[i] = p[i] / min(k, ch + 1);
                }
            }

            


            sort(c, c + n);

            

            {
                

            }
            


            ans = min(ans, c[n - 1] - c[0]);
        }

        cout << ans << endl;
}






























































































































































void love_porn(){
    ll n;
    cin>>n;
    ll temp,s1=0,s2=0;
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        if(temp>=0)
        s1+=temp;
        else 
        s2-=temp;
    }
    ll ans =abs(s1-s2);
    cout<<abs(s1-s2)<<endl;
    return ;
}
















































































int main(){
    FAST_IO;
    int tt;
    cin>>tt;
    

    

    

    while(tt--){
        love_porn();
    }
    return 0;
}


























































































































void nevermind(){
    bool plagged = true;
    if(plagged==true){
        int c = plusinfi;
        int a = c+plusinfi;
    }
    int a = 0 ;

}