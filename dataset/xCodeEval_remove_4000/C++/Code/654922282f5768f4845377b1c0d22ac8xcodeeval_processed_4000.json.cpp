













const long double pi=2*acosl(0);
const long long mod=1e9+7;



using namespace std;


















































class unionFind{
public:
    vector<long long> parent;
    long long n,m;
    long long count=0;
    unionFind(vector<vector<long long>> &v){
        long long n=v.size();long long m=v[0].size();
        parent=vector<long long>(n*m,0);

        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){

                if(v[i][j]==1){
                    long long idx=i*m+j;
                    parent[idx]=idx;

                    count+=1;
                }
            }
        }
    }
    void unionF(long long  x,long long y){
        long long xf=findParent(x);
        long long yf=findParent(y);
        if(xf!=yf){
            parent[xf]=yf;
            count-=1;
        }}
        long long findParent(long long x){
        if(parent[x]==x){

            return x;
        }
        return parent[x]=findParent(parent[x]);

    }






};


bool id5(string s){
    long long i=0;long long j=s.length()-1;
    long long n=s.length();
    while(i<n && j>=0 && j>i){
        if(s[i]!=s[j]){
            return false;
        }
        i+=1;j-=1;
    }
    return true;
}
char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};






















































string id7(long long n)
{
    

    string s;
    for (int i = 63; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s+='1';
        else
            s+='0';
    }
    return s;
}
































bool isPrime(long long n)
{
    

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    

    

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

        return true;
}


















































































































































































































































































































































































































































































































































long long fact(long long n)
{
    long long i,fact=1;

    for(i=1; i<=n; i++)
    {
        fact=fact*i;
    }
    return fact;
}


long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}


bool id4(long long n){
    while(n%2==0 && n>1){
        n/=2;
    }
    if(n==1){
        return true;
    }
    return false;
}


long long id2(long long n){
    return n*(n-1)/2;
}


long long id0(long long x){
    long long ans=1;
    long long i=1;
    while(i<=x){
        ans*=2;
        i+=1;
    }
    return ans;


}






































































































long long findVal(vector<long long> &v,long long val){
    for(long long i=0;i<v.size();i++){
        if(v[i]==val){
            return i;
        }
    }
    return -1;
}


vector<int> id6(long long n,long long k){
    vector<int> v(64,0);
    long long i=63;
    while(n>0){
        int p=n%k;
        v[i]=p;
        n/=k;
        i-=1;

    }
    return v;
}



long long id3(long long a,long long m){
    long long cnt=0;
    while(a%m==0 && a>0){
        a/=m;
        cnt+=1;
    }
    return cnt;
}


























































bool id1(string dn,string dr ){
    long long i=0,j=0;
    if(dn.length()>dr.length()){
        return false;
    }
    long long n=dr.length(),m=dn.length();
    while(i<m && j<n){
        if(dn[i]==dr[j]){
            i+=1;j+=1;
        }
        else{
            j+=1;
        }
    }
    if(i<m){
        return false;
    }
    return true;
}

void solve(){
    long long n;
    cin>>n;
    string s;
    cin>>s;
    vector<long long> ans(n+1,0);
    vector<long long> helper;
    long long sumu=0;
    for(long long i=0;i<n;i++){
        if(s[i]=='L'){
            long long val=n-i-1-i;
            helper.push_back(val);
            sumu+=i;
        }
        else{
            int val=i-n+1+i;
            helper.push_back(val);
            sumu+=(n-i-1);
        }
    }
    sort(helper.begin(),helper.end(),greater<int>());
    int i=0;
    int cnt=1;
   
    ans[0]=sumu;

    for(int i=1;i<=n;i++){
        ans[i]=max(ans[i-1],ans[i-1]+helper[i-1]);
        cout<<ans[i]<<" ";
    }
    cout<<endl;




}

int main(){
      long long t;
      cin>>t;
      while(t--){
          solve();
      }













}