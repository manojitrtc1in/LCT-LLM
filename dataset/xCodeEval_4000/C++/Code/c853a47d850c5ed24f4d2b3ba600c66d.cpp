#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x);cerr<<endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void input(vector<ll> &v){for(ll i=0;i<v.size();i++) cin>>v[i];}
void print(vector<ll> &v){for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    string str;
    cin>>str;
    ll count_a=0;
    ll n=a+b+2*c+2*d;
    for(ll i=0;i<n;i++){
        if(str[i]=='A'){
            count_a++;
        }
    }
    if(count_a!=a+c+d){
        cout<<"NO"<<endl;
        return ;
    }
    ll grp_a=0;
    ll grp_b=0;
    ll grp_aba=0;
    ll grp_bab=0;
    vector<ll> break_points;
    break_points.push_back(-1);
    for(ll i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            break_points.push_back(i);
        }
    }
    break_points.push_back(n-1);
    vector<ll> grp_ab;
    vector<ll> grp_ba;
    for(ll i=0;i<break_points.size()-1;i++){
        ll len_string=break_points[i+1]-break_points[i];
        if(len_string==1){
            if(str[break_points[i]+1]=='A'){
                grp_a++;
            }
            else{
                grp_b++;
            }
        }
        else if(len_string>1&&len_string%2==0){
            if(str[break_points[i]+1]=='A'){
                grp_ab.push_back(len_string);
            }
            else{
                grp_ba.push_back(len_string); 
            }
        }
        else if(len_string>1&&len_string%2==1){
            if(str[break_points[i]+1]=='A'){
                grp_aba=grp_aba+len_string-1;
                grp_a++;
            }
            else{
                grp_bab=grp_bab+len_string-1;
                grp_b++;
            }
        }
    }
    sort(grp_ab.begin(),grp_ab.end(),greater<int>());
    sort(grp_ba.begin(),grp_ba.end(),greater<int>());
    ll grp_aba_s=grp_aba;
    ll grp_bab_s=grp_bab;
    vector<ll> grp_ab_s=grp_ab;
    vector<ll> grp_ba_s=grp_ba;
    debug(grp_a);
    debug(grp_b);
    debug(grp_aba);
    debug(grp_bab);
    debug(grp_ab);
    debug(grp_ba);
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    if(1){
        ll save_d=d;
        ll save_c=c;
        ll flag=0;
        if(d>0){
            if(d>0){
                for(ll i=0;i<grp_ba.size();i++){
                    if(grp_ba[i]>=2*d){
                        grp_ba[i]=grp_ba[i]-2*d;
                        d=0;
                    }
                    else{
                        d=d-grp_ba[i]/2;
                        grp_ba[i]=0;
                    }
                    if(d==0){
                        break ; 
                    }
                }
            }
            if(d>0){
                if(grp_aba>=2*d){
                    grp_aba=grp_aba-2*d;
                    d=0;
                }
                else{
                    d=d-grp_aba/2;
                    grp_aba=0;
                }
            }
            if(d>0){
                if(grp_bab>=2*d){
                    grp_bab=grp_bab-2*d;
                    d=0;
                }
                else{
                    d=d-grp_bab/2;
                    grp_bab=0;
                }
            }
            if(d>0){
                for(ll i=0;i<grp_ab.size();i++){
                    if(grp_ab[i]>=2*(d+1)){
                        grp_ab[i]=grp_ab[i]-2*(d+1);
                        d=0;
                    }
                    else if(grp_ab[i]>2){
                        d=d-(grp_ab[i]-2)/2;
                        grp_ab[i]=0;
                    }
                    if(d==0){
                        break ; 
                    }
                }
            }
            debug(d);
            debug(c);
            if(d>0){
                flag=1;
            }
        }
        if(c>0){
            if(c>0){
                for(ll i=0;i<grp_ab.size();i++){
                    if(grp_ab[i]>=2*c){
                        grp_ab[i]=grp_ab[i]-2*c;
                        c=0;
                    }
                    else{
                        c=c-grp_ab[i]/2;
                        grp_ab[i]=0;
                    }
                    if(c==0){
                        break ;
                    }
                }
            }
            if(c>0){
                if(grp_aba>=2*c){
                    grp_aba=grp_aba-2*c;
                    c=0;
                }
                else{
                    c=c-grp_aba/2;
                    grp_aba=0;
                }
            }
            if(c>0){
                if(grp_bab>=2*c){
                    grp_bab=grp_bab-2*c;
                    c=0;
                }
                else{
                    c=c-grp_bab/2;
                    grp_bab=0;
                }
            }
            if(c>0){
                for(ll i=0;i<grp_ba.size();i++){
                    if(grp_ba[i]>=2*(c+1)){
                        grp_ba[i]=grp_ba[i]-2*(c+1);
                        c=0;
                    }
                    else if(grp_ba[i]>2){
                        c=c-(grp_ba[i]-2)/2;
                        grp_ba[i]=0;
                    }
                    if(c==0){
                        break ;
                    }
                }
            }
        }
        if(c>0){
            flag=1;
        }
        if(flag==0){
            cout<<"YES"<<endl;
            return ;
        }
        c=save_c;
        d=save_d;
        flag=0;
        grp_ab=grp_ab_s;
        grp_ba=grp_ba_s;
        grp_aba=grp_aba_s;
        grp_bab=grp_bab_s;
        if(c>0){
            if(c>0){
                for(ll i=0;i<grp_ab.size();i++){
                    if(grp_ab[i]>=2*c){
                        grp_ab[i]=grp_ab[i]-2*c;
                        c=0;
                    }
                    else{
                        c=c-grp_ab[i]/2;
                        grp_ab[i]=0;
                    }
                    if(c==0){
                        break ;
                    }   
                }
            }
            if(c>0){
                if(grp_aba>=2*c){
                    grp_aba=grp_aba-2*c;
                    c=0;
                }
                else{
                    c=c-grp_aba/2;
                    grp_aba=0;
                }
            }
            if(c>0){
                if(grp_bab>=2*c){
                    grp_bab=grp_bab-2*c;
                    c=0;
                }
                else{
                    c=c-grp_bab/2;
                    grp_bab=0;
                }
            }
            if(c>0){
                for(ll i=0;i<grp_ba.size();i++){
                    if(grp_ba[i]>=2*(c+1)){
                        grp_ba[i]=grp_ba[i]-2*(c+1);
                        c=0;
                    }
                    else if(grp_ba[i]>2){
                        c=c-(grp_ba[i]-2)/2;
                        grp_ba[i]=0;
                    }
                    if(c==0){
                        break ;
                    }
                }
            }
        }
        if(c>0){
            flag=1;
        }
        if(d>0){
            if(d>0){
                for(ll i=0;i<grp_ba.size();i++){
                    if(grp_ba[i]>=2*d){
                        grp_ba[i]=grp_ba[i]-2*d;
                        d=0;
                    }
                    else{
                        d=d-grp_ba[i]/2;
                        grp_ba[i]=0;
                    }
                    if(d==0){
                        break ; 
                    }
                }
            }
            if(d>0){
                if(grp_aba>=2*d){
                    grp_aba=grp_aba-2*d;
                    d=0;
                }
                else{
                    d=d-grp_aba/2;
                    grp_aba=0;
                }
            }
            if(d>0){
                if(grp_bab>=2*d){
                    grp_bab=grp_bab-2*d;
                    d=0;
                }
                else{
                    d=d-grp_bab/2;
                    grp_bab=0;
                }
            }
            if(d>0){
                for(ll i=0;i<grp_ab.size();i++){
                    if(grp_ab[i]>=2*(d+1)){
                        grp_ab[i]=grp_ab[i]-2*(d+1);
                        d=0;
                    }
                    else if(grp_ab[i]>2){
                        d=d-(grp_ab[i]-2)/2;
                        grp_ab[i]=0;
                    }
                    if(d==0){
                        break ;
                    }
                }
            }
            if(d>0){
                flag=1;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
            return ;
        }
        else{
            cout<<"NO"<<endl;
            return ;
        }
    }
    if(c==0&&d==0){
        cout<<"YES"<<endl;
    }
}
int main(){ 
    ios_base::sync_with_stdio(false);  
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}