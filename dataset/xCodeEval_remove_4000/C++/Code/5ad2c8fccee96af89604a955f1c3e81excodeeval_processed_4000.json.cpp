











using namespace std ;
typedef long long ll;


ll b[17] ;
bool vis[17] ;
ll a[200001]  ; 

bool cmp(pair<int ,int >p1 , pair<int ,int > p2 ){

    if(p1.second < p2.second)return true ; 
    else return false ; 
}
bool comper(char c1 , char c2 ) {


    if ((c1 >='A' && c1 <= 'Z' && c2 >='A' && c2 <= 'Z') ||(c1 >='a' && c1 <= 'z' && c2 >='a' && c2 <= 'z'))
        return c1 < c2 ;
    else if (c1 >='A' && c1 <= 'Z' && c2 >='a' && c2 <= 'z'){
        char upper = toupper(c2);
        if (c1 == upper )
            return c2>c1 ; 
        else {
            char c = tolower(c1);
            return  c <= c2 ;
        }
    }
    else if (c1 >='a' && c1 <= 'z' && c2 >='A' && c2 <= 'Z'){
        char upper = toupper(c1);
        if (c2 == upper )
            return c1 <c2 ;  
        else {
            char c = tolower(c2);
            return  c > c1 ;
        }
    }

}

void id0(string p ){
    ll j = -1 ,i = 0 ; b[0] = -1 ; 
    while (i<p.size())
    {
        while(j >= 0 && p[j] != p[i] ) j = b[j] ; 
        i++; j++ ; 
        p[i] = j ; 
    }
}

bool id1(string t,string p ){

    ll i = 0 ,j= 0 ; 
    while(i<t.size()){

        while( j >= 0 && t[i] != p[j] ) j = b[j] ;
        i++ ; j++ ; 
        if (j == p.size()){
            return true ; 
        }
    }
    return false ;
}

bool BT(ll sum , int i  ,int n ,ll val){

    if (i == n-1) {
        if (sum == val) 
            return true; 
    }
    else 
    {
        return BT(sum + b[i+1],i+1,n,val) ||
            BT(sum - b[i+1],i+1,n,val); 
    }
    return false ;

}

int main (){
    ios::sync_with_stdio(false);

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    



    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    
    


    string s ; cin>>s ; 
    ll n ; cin>>n ; 
    
    REP(i,0,200000)
        a[i] = 0 ;
    REP(i,0,n){
        ll x ; cin>>x ; 
        a[x-1] ++ ; 
    }
    a[0] %= 2 ;
    if (a[0] == 1 ) 
            swap(s[0] ,s[s.size()-1  ]);
    REP(i,1,(s.size()/2)){
        a[i] += a[i-1] ; 
        a[i]  = a[i] % 2 ; 
        if (a[i] == 1 ) 
            swap(s[i] ,s[s.size()-1 -i ]);
    }
    cout<<s<<endl;

}

