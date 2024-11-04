



using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;









  
  
  
  
  

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}





 
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



























































































































































































































            
            


 










    


 
int expo(int m,int n){
    if(n<=0)return 1;
    if(n==1)return m;
    int x=expo(m,n/2);
    if(n%2==0){
        return x*x;
    }else{
        return x*x*m;
    }
}
























































































































 





















void solve(){
    int n,h;cin>>n>>h;
    vector<int>v(n);
    int hh=h;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int fans=0;
    sort(v.begin(),v.end());
    int ans=0;
    int b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(b==1){
                h=h*3;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==2){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==1){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        
    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(b==1){
                h=h*3;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==2){
                h=h*4;
                g--;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        

    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2){
                h=h*4;
                g--;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(b==1){
                h=h*3;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        
    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(b==1){
                h=h*3;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==1){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        

    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
     b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==1){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
             if(b==1){
                h=h*3;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        

    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2 and b==1){
                h=h*6;
                g--;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==1){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        
    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2){
                h=h*2;
                g--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
            if(g==1 and b==1){
                h=h*6;
                g--;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        
    }
    debug(ans)
    fans=max(fans,ans);
    ans=0;
    h=hh;
    b=1,g=2;
    for(int i=0;i<n;i++){
        debug(h)
        if(v[i]<h){
            h+=v[i]/2;
            ans++;
        }else{
            if(g==2 and b==1){
                h=h*12;
                g--;
                g--;
                b--;
                if(v[i]<h){
                    h+=v[i]/2;
                    ans++;
                    continue;
                }
            }
        }
        
    }
    debug(ans)
    fans=max(fans,ans);
    cout<<fans<<endl;
}



 

  
    
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     
     freopen("Error.txt", "w", stderr);
     
    int t;cin>>t;
    


    for(int i=1;i<=t;i++)solve();
    

}







