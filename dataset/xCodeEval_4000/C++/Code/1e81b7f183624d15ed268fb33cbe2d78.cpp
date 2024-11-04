 


 
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
 
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

 











 


 

#define N 1000000007
lli power(lli n,lli a){ lli res=1; while(a){ if(n%2) res*=n,a--; else	n*=n,a/=2;} return res;}
lli modpower(lli n,lli a) { lli res=1; while(a){ if(a%2) res= ((res*n)%N) ,a--; else	n=((n*n)%N),a/=2;} return res;}
lli binmodpower(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    lli n,m,i,j,ct=0,id1=1000000000000,id2=1000000000000,ct1=0,k;
    cin>>n>>m;
    vector<vector<lli>> a(n,vector<lli>(m));
    f(i,0,n){f(j,0,m){cin>>a[i][j];}}
    if(m==1){cout<<"1 "<<"1"<<endl;return;}
    f(i,0,n){
        f(j,0,m-1){
            if(a[i][j]>a[i][j+1]){
                ct1=1;
                vl v=a[i];
                sort(all(v));
                f(k,0,v.size()){
                    if(a[i][k]!=v[k]){
                        if(ct==0){
                            id1=k;
                        
                        }
                        if(ct==1){
                            id2=k;
                        
                        }
                        if(ct==2){cout<<"-1"<<endl;return;}
                        ct++;
                    }
                }
                break;
            }        
        }
        if(ct1==1){break;}
    }
    if(ct1==0){cout<<"1 "<<"1"<<endl;return;}
    f(i,0,n){
        swap(a[i][id1],a[i][id2]);
    }

    f(i,0,n){
        f(j,0,m-1){
            if(a[i][j]>a[i][j+1]){
                cout<<"-1"<<endl;return;
            }
        }
    }
    cout<<id1+1<<" "<<id2+1<<endl;

}
 
int main()
{
    fast;
    lli t;
    t=1;
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}
