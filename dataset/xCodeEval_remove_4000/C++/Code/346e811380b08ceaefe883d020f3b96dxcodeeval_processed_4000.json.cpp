


















using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;














int a[100005];
int main()
{
    




    
    int n;
    cin>>n;
    while(n--){
            int si;
            cin>>si;
    char s[si];
    forn(i,si)cin>>s[i];
    int su=0;
    int freq[26]= {0};
    forn(i,si)
    ++freq[s[i]-'A'];


    forn(i,26)
    {
        if(freq[i]==1)su+=2;
        if(freq[i]>1)
        {
            su+=freq[i]+1;
        }

    }
    cout<<su<<endl;
}


}



































































































































































































 	 				     	  				 	  		 				