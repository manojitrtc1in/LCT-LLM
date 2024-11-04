

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 100050

#define ll long long
#define ld long double
#define lli long int

#define pb emplace_back
#define INF 1000000000
#define mod 1000000007
#define MOD 1000000007



#define PI acos(-1) 

#define dsin(degree) sin(degree*(PI/180.0))
#define dcos(degree) cos(degree*(PI/180.0))
#define dtan(degree) tan(degree*(PI/180.0))

#define rsin(radian) sin(radian)
#define rcos(radian) cos(radian)
#define rtan(radian) tan(radian)

#define loop(i,n) for (lli i = 0; i < n; i++)
#define loopitr(xt,vec) for (auto xt : vec)
#define FOR(i,a,b) for (lli i = a; i < b; i+=1)
#define loop_rev(i,n) for (lli i = n-1; i >= 0; i--)
#define FOR_REV(i,a,b) for (lli i = a; i >= b; i--)
#define itr :: iterator it
#define WL(t) while(t --)

#define all(v) v.begin(),v.end()
#define sz(x) int(x.size())
#define F first
#define S second

#define mii map<lli,lli>
#define vi vector<lli>
#define seti set<lli>
#define pii pair<lli,lli>

#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (a/gcd(a,b))*b
#define abs(x) ((x < 0)?-(x):x)

#define print(x) printf("%lli\n",x);
#define print2(x,y) printf("%lli %lli\n",x,y);
#define print3(x,y,z) printf("%lli %lli %lli\n",x,y,z);

#define scanarr(a,n) for(lli i=0;i<n;i++)    cin>>a[i];
#define scanvector(a,n) for(lli i=0;i<n;i++){ lli x ; cin>>x; a.push_back(x);}

#define printarr(a,n) for(lli i=0;i<n;i++)   printf("%lli ",a[i]); printf("\n");
#define printvector(vec) for(auto xt : vec) cout<<xt<<" ";    cout<<"\n";
#define printset(st) for(auto xt : st) cout<<xt<<" ";    cout<<"\n";

#define FD(N) fixed<<setprecision(N)

#define endl '\n'

#define deb(x) cout<<#x<<" "<<x<<endl;






bool prime[MAX+1];

void sieve1(){ 

    for(int i=0;i<=MAX;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for(lli i=4;i<=MAX;i+=2) prime[i]=0;
    for (int p=3; p*p<=MAX; p+=2){
        if (prime[p] == 1)
            for (int i=p*2; i<=MAX; i += p){
                prime[i] = 0;
}}}


bool ispali(string &s){
string q = s;
reverse(q.begin(),q.end());
return(s==q);
}


bool isvowel(char v) { return (0x208222>>(v&0x1f))&1; }

lli mceil(lli a,lli b){
    if(a%b==0) return(a/b);
    else return(a/b  +1);
}
lli mfloor(lli a,lli b){
    return(a/b);
}


ll modmul(ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
}

ll modadd(ll a , ll b){
    return((a%mod)+(b%mod)+mod)%mod;
}

ll modsub(ll a , ll b){
    return((a%mod) - (b%mod) + mod)%mod;
}

lli fastexpo(lli a,lli b){
    a = a%mod;
    lli ans=1;
    while(b){
        if(b&1)
            ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b=b/2;
        }
    return ans;
 }



lli cntbits(lli n){
    lli cnt=0;
    while(n){
        cnt++;
        n/=2;
    }
    return cnt;
}


 
#define maxlen 1000005 

lli pow_p[maxlen]; 

lli p_inv[maxlen]; 

                   

void precompute_power(){
    lli p=4793;
    pow_p[0]=1;
    p_inv[0]=1;
    lli pinv = fastexpo(p,mod-2);
    for(lli i=1;i<maxlen;i++){
        pow_p[i] = modmul(pow_p[i-1],p);
        p_inv[i] = modmul(p_inv[i-1],pinv);
    }
}

struct Hash{
        

        

        lli prehash[maxlen];
        

        

        void precomputehash(string &s){
            lli p=4793;
            prehash[0]=(s[0]-'a')+1;
            for (lli i=1;i<s.size();i++) {
                prehash[i]= modadd(prehash[i-1] , modmul((s[i]-'a'+1),pow_p[i]));
            }
        }
        

        lli gethash(lli l, lli r){
            if(l==0)
                return(prehash[r]%mod);
            else{
                lli ans = modsub(prehash[r],prehash[l-1]);
                ans = modmul(ans, p_inv[l]);
                return ans;
            }
        }

        

        lli totalhash(string &s){
            return(prehash[sz(s)-1]%mod);
        }
};





string maxpaindrome(string &s){
    Hash ss;
    ss.precomputehash(s);
    
    string rev = s;
    reverse(all(rev));
    Hash revs;
    revs.precomputehash(rev);
    
    lli n=sz(s);
    lli maxi1=0;
    
    for(lli i=0;i<n;i++){
        if(ss.gethash(0,i) == revs.gethash(n-i-1,n-1))
            maxi1 = i;
    }
    

    string ans1 = s.substr(0,maxi1+1);
    
    lli maxi2=0;
    for(lli i=0;i<n;i++){
        if(revs.gethash(0,i) == ss.gethash(n-i-1,n-1))
            maxi2 = i;
    }
    string ans2 = rev.substr(0,maxi2+1);
   

    if(sz(ans1)>=sz(ans2))
        return ans1;
    else
        {
            reverse(all(ans2));
            return ans2;
        }
}




void chandan1(){int y=1;return;}
void chandan2(){
        loop(i,10){
        lli x=1;
    }
    return(chandan1());
}

int main(){
fastio
precompute_power();
lli t=1;
cin>>t;
chandan2();
while(t--) {
    string s;
    cin>>s;
    lli i=0;
    lli j=sz(s)-1;
    while(i<j and s[i]==s[j]){
        i++;
        j--;
    }
    if(i>=j){ 

        cout<<s<<endl;
        continue;
    }
    else{
      

     

     string lefthalf =s.substr(0,i);
     string righthalf = lefthalf;
     reverse(all(righthalf));
     
     string required = s.substr(i,j-i+1);
     

     string ans  =  maxpaindrome(required);
     
     cout<<lefthalf<<ans<<righthalf<<endl;
     
    }
  }
return 0;
}
