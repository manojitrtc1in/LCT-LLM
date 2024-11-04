



using namespace std;





































































bool prime[MAX+1];

void id9(){ 

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


bool id6(char v) { return (0x208222>>(v&0x1f))&1; }

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

lli id10(lli a,lli b){
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


 


lli pow_p[maxlen]; 

lli p_inv[maxlen]; 

                   

void id1(){
    lli p=4793;
    pow_p[0]=1;
    p_inv[0]=1;
    lli pinv = id10(p,mod-2);
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





string id3(string &s){
    Hash ss;
    ss.precomputehash(s);
    
    string rev = s;
    reverse(all(rev));
    Hash revs;
    revs.precomputehash(rev);
    
    lli n=sz(s);
    lli id0=0;
    lli id7=0;
    
    for(lli i=0;i<n;i++){
        if(ss.gethash(0,i) == revs.gethash(n-i-1,n-1))
            id0 = i;
        if(revs.gethash(0,i) == ss.gethash(n-i-1,n-1))
            id7 = i;
    }
    

    string ans1 = s.substr(0,id0+1);
    string ans2 = rev.substr(0,id7+1);
   

    if(sz(ans1)>=sz(ans2))
        return ans1;
    else
        {
            reverse(all(ans2));
            return ans2;
        }
}




void id5(){int y=1;return;}
void id2(){
        loop(i,10){
        lli x=1;
    }
    return(id5());
}

int main(){
fastio
id1();
lli t=1;
cin>>t;
id2();
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
      

     

     string id8 =s.substr(0,i);
     string id4 = id8;
     reverse(all(id4));
     
     string required = s.substr(i,j-i+1);
     

     string ans  =  id3(required);
     
     cout<<id8<<ans<<id4<<endl;
     
    }
  }
return 0;
}
