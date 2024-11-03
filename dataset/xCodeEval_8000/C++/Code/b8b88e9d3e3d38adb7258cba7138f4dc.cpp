

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
#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pb push_back
#define eb emplace_back
#define f first
#define s second


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


template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}



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
    int n;cin>>n;
    int temp,s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp>=0)
        s1+=temp;
        else 
        s2-=temp;
    }
    int ans =abs(s1-s2);
    cout<<abs(s1-s2)<<endl;
    return ;
}






































































































































































int arr[200005];
int brr[200005];
int crr[200005];
map<pair<ll,ll>,vector<int> > m;

bool check(pair<ll,ll>a,ll l,ll r){
	auto it=lower_bound(all(m[a]),l);
	if (it!=m[a].end() && *it<=r) 
	return true;
	else 
	return false;
}


























































void solve456(){
     int n;
        cin>>n;
        string str1;
    cin >> str1;
    string str2;
    cin >> str2;
    bool equi = (str1 == str2);
    bool flag = true;
    for (int i = 0; i < n; i++) {
      flag &= (str1[i] != str2[i]);
    }
    if (!equi && !flag) {
      cout << "NO" << endl;
     

    }
    vector<pair<int, int>> ops;
    for (int i = 1; i < n; i++) {
      if (str2[i] != str2[i - 1]) {
        ops.eb(0, i - 1);
        swap(equi, flag);
      }
    }
    if (str2[0] == '1') {
      ops.eb(0, 0);
      ops.eb(1, n - 1);
    }
    if (flag==true) {
      ops.eb(0, n - 1);
    }
    cout << "YES" <<endl;
    cout << ops.size() <<endl;
    for (auto& _ : ops) {
      cout << _.f + 1 << " " << _.s + 1 <<endl;
    }
}


























































































































































ll binpow(ll a,ll b){
    ll rem =1;
    for(;b;b>>=1,a=a*a%998244353)
    if(b&1)
    rem=rem*a%998244353;
    return rem;
}




























































































void computed(){
    ll n;
    string str;
    cin >> n >> str;
 
    ll res = 0;
    for(int i=n-1;i>=0;i--) {
        if (str[i] == 'A') {
            res++;
        } else {
            if (res == 0) {
                cout << "NO" << endl;
                return ;
            }
            res--;
        }
    }
 
    cout << "YES" << endl;
}


































































#define MOD 998244353
int main(){
    FAST_IO;
    

    

    

    

    

   

        int n,m;
        cin>>n;
        ll arr[10000000];
        int a,b,c,d;
        int i,j,k;






















































        	for (i = 0, j = n - 1; i < j; i++, j--) {
		for (k = j - 1; k >= i; k--)
			arr[m++] = k;
		for (k = i + 1; k < j; k++)
			arr[m++] = k;
	}
	for (i = 0, j = n - 1; i + 1 < j; i++, j--)
		arr[m++] = i;
	for (i = n / 2 - 1, j = n - 1 - i; i >= 0; i--, j++) {
		for (k = i - 1; k >= j - n; k--)
			arr[m++] = (k + n) % n;
		for (k = j - n + 1; k < i; k++)
			arr[m++] = (k + n) % n;
	}






















































for (i = n / 2 - 1, j = n - 1 - i; i > 0; i--, j++)
		arr[m++] = j;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		for (k = j - 1; k >= i; k--)
			arr[m++] = k;
		for (k = i + 1; k < j; k++)
			arr[m++] = k;
	}
	for (i = 0, j = n - 1; i + 1 < j; i++, j--)
		arr[m++] = i;
        cout<<m<<endl;
        for(int i=0;i<m;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
	

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