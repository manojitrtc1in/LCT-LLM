 


 
#include<bits/stdc++.h>
using namespace std;
 









#define lli long long int






 


#define f(i,x,n) for(i = x; i < n; i++)
#define rf(i,x,n) for(i = x; i >= n; i--)
#define fr(i,m) for(auto i:m)
 


#define vl vector<lli>
#define vs vector<string>
#define vpl vector<pair<lli,lli>>
#define pb push_back
 
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))


#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))


#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
 
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())


#define sumv(x) accumulate(v.begin(), v.end(), x)
 


#define all(v) (v).begin(),(v).end()
#define rall(a) (a).rbegin(), (a).rend()
 










 


#define sl set<lli>
#define ss set<string>
 






 


#define mll map<lli,lli>
#define mss map<string,string>
#define msl map<string,lli>
#define mls map<lli,string>
 


#define pi pair<int,int>
#define pl pair<long long,long long>
 
#define fi first
#define se second
 






 


 
#define pie (3.141592653589)
 


 
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
 


 
#define maxar *max_element
#define minar *min_element
#define sumar(x) accumulate(a, a+n, x)












 


 
#define gl(s) getline(cin,s)
#define le(s) s.length()
#define str(p,q) s.erase(p,q)




 


 
#define gcd2(a,b) __gcd(a,b)
#define lcm2(a,b) ((a*b)/(__gcd(a,b)))
 
#define Khopdi_tod_saale_ki ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

 











 


 

#define N 1000000007
lli power(lli n,lli a){ lli res=1; while(a){ if(a%2){ res*=n,a--;}else{n*=n,a/=2;}} return res;}
lli modpower(lli n,lli a){ lli res=1; while(a){ if(a%2){ res= ((res*n)%N) ,a--;}else{n=((n*n)%N),a/=2;}} return res;}
lli binmodpower(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    lli n=lcm2(s1.size(),s2.size()),c1=0,c2=0,i,j;
    string s;
    n/=min(s1.size(),s2.size());
    f(i,0,n){
        if(s1.size()<s2.size()){
            for(j=0;j<s1.size();j++){
                s.pb(s1[j]);
            }
            c1=1;
        }else{
            for(j=0;j<s2.size();j++){
                s.pb(s2[j]);
            }
            c2=1;
        }
    }
    if(c1==1){
        j=0;
        for(i=0;i<s.size();i++){
            if(s[i]!=s2[j]){
                cout<<"-1"<<endl;return;
            }
            if(j==s2.size()-1){j=0;}
            else{j++;}
        }
        cout<<s<<endl;
    }else{
        j=0;
        for(i=0;i<s.size();i++){
            if(s[i]!=s1[j]){
                cout<<"-1"<<endl;return;
            }
            if(j==s1.size()-1){j=0;}
            else{j++;}
        }
        cout<<s<<endl;
    }
    
}
 
int main()
{
    Khopdi_tod_saale_ki;
    lli t;
    t=1;
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}