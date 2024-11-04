












 




















template<typename T> 
void vec_in(std::vector<T> &v,ll n){
    if(v.size() == 0){
        T input;
        for(ll i=0;i<n;i++){
            in(input);
            v.push_back(input);    
        }
    }
    else{
        for(ll i=0;i<n;i++) std::cin>>v[i];
    }
}  
template<typename T> 
void vec_out(std::vector<T> &v){
    for(T x : v){
        std::cout<<x<<" ";
    }
    std::cout<<'\n';
}
 
template<typename T> 
void vec_out(std::vector<T> && v){
    for(T x : v){
        std::cout<<x<<" ";
    }
    std::cout<<'\n';
}
 
 


 
 
 



 


 






 
bool id3(std::vector< std::vector<int> > &adjacent, std::vector<int>& des, int node,std::list<int>&id4){
 
    des[node] = 0;
    
    

 
    for(int  x: adjacent[node]){
        

        if(des[x] == 0) return false;
 
        else if(des[x] == -1){
            if(id3(adjacent,des,x,id4) ==false){
               

                return false;
            }
        }
    } 
 
    id4.push_front(node);
 
    des[node] =1;
 
    return true ;
 
}
 
bool dfs(std::vector< std::vector<int> > &adjacent,std::list<int>&id4){
     
    
    int n = adjacent.size();
 
    std::vector<int>des(n); for(int i=0;i<n;i++) des[i] = -1;
 
    for(int i=0;i<n;i++){
        if(des[i]== -1){
            if(id3(adjacent,des,i,id4) == false) return false;
        }
    }
 
    return true;
 
 
 
}
 
void flatten(vec< vec<ll> >& adj,vec< pair<ll,ll> >& flat,vec<ll> & time,ll node,vec<bool>des){  

 
    flat[node].first = time.size();
 
    time.push_back(node);
 
    

 
    des[node] = true;
 
    for(ll x : adj[node]){
        
        if(des[x] == false){
 
            flatten(adj,flat,time,x,des);
 
        }
        
 
 
    }
 
    flat[node].second = time.size();
 
    

 
    time.pb(node);
 
    return;
 
}
 
void gra_in(vec< vec<ll> >& adj,ll edj){
 
     if(adj.size() != edj+1){
        adj.clear(); 
        adj = vec< vec<ll> >(edj+1);
     } 
    
     for(ll k=0;k<edj;k++){
         ll i,j; in(i); in(j);
 
         adj[i-1].pb(j-1);
 
         adj[j-1].pb(i-1);
 
     } 
 
 
 
}
 




constexpr ll max_number = 100000;

ll fac[max_number];

long long int  gcd(long long int  a,long long int  b) {
 
        a = a >=0 ? a: -a;
 
        b = b >=0 ? b: -b;
 
        

        
        if(b==0) return a;
        else return gcd(b,a%b);
}
 
 long long int  lcm(long long int  a,long long int  b) {
    
        return (a/gcd(a,b))*b;
 
 }
 
 long long int  mod_exp(long long int  a,long long int b,long long int mod){
     
     long long int  pro = 1;
 
     a%=mod;
 
     while(b>0){
         
         if(b%2){
            pro *= a;
 
            pro%= mod;
 
            pro = (pro+mod)%mod;
         }
 
         a*=a;
         
         a%=mod;
 
         a= (a+mod)%mod;
 
         b>>=1;
 
 
     }
 
     return pro;
 
 }
 
long long int  inverse(long long int  a,long long int b){
 
    return mod_exp(a,b-2,b);
 }
 
bool id6(ll x){
    

    ll index = 0;
    while(index<40 && (1<<index)!= x) index++;
    if(index==40) return false;
    else return true;
 }

void fac_init(ll p){

    fac[0] = 1;
    
    for (int i=1 ; i<max_number; i++) 
            fac[i] = fac[i-1]*i%p;

}

ll nCr(ll n, ll r, ll mod){ 
   if (r==0) 
      return 1;
   else if(n >= r){   
        return (fac[n]* inverse(fac[r], mod) % mod * 
            inverse(fac[n-r], mod) % mod) % mod;
    }
    else{
        return 0;
    } 
}
 


 


 
string g_query(ll x,ll y){
    

    g_out2(x,0); g_out2(y,1);
    

    string answer; in(answer);
    if(answer == "WRONG"){
        exit(0);
    }
    else{
        return answer;
    }
 }
 
ll id0(ll start,ll end,bool x){  
     
     double mid2 = ((double)(start+end))/2;
 
     ll mid = floor(mid2)-start < ceil(mid2)-start ? floor(mid2) : ceil(mid2);
 
     while(mid != start && mid != end){
         
         string ans; 
 
         if(x){
            ans = g_query(mid,0);
         }
         else{
            ans = g_query(0,mid);
         }
 
         if(ans != "CENTER"){
 
            if(ans == "HIT"){
                
                 return id0(mid,end,x);
 
             }
             else{
 
                 return id0(start,mid,x);
 
             }
         }
         else{
            return big;
         }
 
    }
 
    return start;
 
}
 






int* tree;
 
void build(vec<ll>& arr,ll node, ll start, ll end)
{

    if(start == end)
    {

        tree[node] = arr[start];

    }

    else
    {
        ll mid = (start + end) / 2;
 
        build(arr,2*node, start, mid);
        
        build(arr,2*node+1, mid+1, end);
        
        for(ll i=0;i<40;i++){
            
            tree[node] = tree[2*node] + tree[2*node + 1];

        }
 
        
         
    }
}
 
void update(vec<ll>& arr,ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        arr[idx] += val;

        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(arr,2*node, start, mid, idx, val);
        }
        else
        {
            update(arr,2*node+1, mid+1, end, idx, val);
        }
 
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
 
void rangeUpdate(vec<ll>& tree,vec<ll>& lazy,ll node, ll start, ll end, ll l,ll r,ll value)
{
    if(r < start or end < l)
    {
        return;
    }
 
    else if(l <= start and end <= r)
    {    
 
         lazy[node] +=  value;
 
         if(start == end){
            
            tree[node] += lazy[node];
 
            lazy[node] = 0;
 
         }
 
 
    }
    else{
 
        if(lazy[node] != 0){
            
            lazy[2*node] += lazy[node];
 
            lazy[2*node  + 1] += lazy[node];
 
            lazy[node] = 0;
 
        }
       
        ll mid = (start + end) / 2;
 
        rangeUpdate(tree,lazy,2*node, start, mid, l, r,value);
 
        rangeUpdate(tree,lazy,2*node+1, mid+1, end, l, r,value);
        
 
        tree[node] = (tree[2*node]+lazy[2*node])  + (tree[2*node +1] + lazy[2*node +1]);
 
 
    }
    
}
 
ll lazy_query(vec<ll>& tree,vec<ll>& lazy,int node, int start, int end, int l, int r)
{
 
    if(r < start or end < l)
    {
        return 0;
    }
 
    else if(l <= start and end <= r)
    {
        if(lazy[node] != 0){
 
            if(start == end){
                
                tree[node] += lazy[node];
 
                lazy[node] = 0;
 
                return tree[node];
 
               
            }
            else{
 
                lazy[2*node] += lazy[node];
 
                lazy[2*node  + 1] += lazy[node];
 
                lazy[node] = 0;
                
                tree[node] = (tree[2*node]+lazy[2*node])  + (tree[2*node +1] + lazy[2*node +1]);
 
                return tree[node];
 
            }
            
 
 
        }
        else{
 
          return tree[node];
        } 
 
        
    }
    else{
 
        if(lazy[node] != 0){
            
            lazy[2*node] += lazy[node];
 
            lazy[2*node  + 1] += lazy[node];
 
            lazy[node] = 0;
 
 
        }
    
        ll mid = (start + end) / 2;
 
        ll p1 = lazy_query(tree,lazy,2*node, start, mid, l, r);
 
        ll p2 = lazy_query(tree,lazy,2*node+1, mid+1, end, l, r);
        
        tree[node] = (tree[2*node]+lazy[2*node])  + (tree[2*node +1] + lazy[2*node +1]); 
 
        

 
        return (p1+p2);
    }
}
 
ll query(int node, int start, int end, int l, int r)
{
 
    if(r < start or end < l)
    {
        return 0;
    }
 

    else if(l <= start and end <= r)
    {
        
        return tree[node]; 
        
    }
    else{
    
        ll mid = (start + end) / 2;
 
        ll p1 = query(2*node, start, mid, l, r);
 
        ll p2 = query(2*node+1, mid+1, end, l, r);
 
        return p1+p2;
    }
}

void find(vec<ll>&arr,ll node, ll start,ll end,ll val){

    if(start == end){

        arr[start] -=1;

        tree[node] -= 1;

        return ;

    }
    
    ll mid = (start + end) / 2;

    if(tree[2*node] >= val){

       find(arr,2*node,start,mid,val);

       tree[node] = tree[2*node] + tree[2*node + 1]; 

    }
    else{

       find(arr,2*node + 1,mid+1,end,val-tree[2*node]);

       tree[node] = tree[2*node] + tree[2*node + 1];

    }

    return ;


}





class Trie{

public:
    char c;
    ll count;
    vec<Trie*> next;
public:
    Trie() : c(0),count(0){

    }
public:
    static void insert(Trie* root,string arg,int index= 0){

       ll n = arg.size();

        for(Trie* x : root->next){
             
             if(x->c == arg[index]){

                if(index < n-1){

                    return insert(x,arg,index + 1);
                }
                else{

                    x->count += 1;

                    return;

                }
                
             }

        }

        Trie* node = new Trie[1];

        node->c = arg[index]; node->count = 0;

        (root->next).push_back(node);

        if(index == n-1){
           
            node->count = 1;

            return ;

        }
        else{

            return insert(node,arg,index + 1);

        }

    }
    

public:
    static void print(Trie* root){

        


       for(auto x: root->next){
          
          g_out2(x->c,0); g_out2(x->count,0);              
          
       }

       out("");

       for(auto x : root->next){
          print(x);
       }

    }


};

void id2(ll number, string str,vec< vec<char> >&ans){
      
   vec<ll>dig;

   while(number){
      
      dig.push_back(number%10);
      
      number /=10;

   }

   if(str.size() == dig.size()){ 
          
      ans[dig[dig.size()-1]].push_back(str[0]);

      return ;

   }
   else{
     return ;
   }


}

ll id7(vec<ll>& arr,ll st,ll en){
     
     ll id5 = arr[0];

     for(ll i=st;i<en;i++) id5 = gcd(id5,arr[i]);

    return id5;

}

bool check_size(vec< vec<ll> >& freq,ll size){
     
    int n = freq.size();

    for(ll i = 0;i<n-size+1;i++){

        bool cool = true;

        for(ll j =0;j<3;j++){

           if(i==0 && freq[i+size-1][j] == 0 ){

              cool = false;
              break;
           }

           if(i!=0 && freq[i+size-1][j] - freq[i-1][j] == 0){
             cool = false;
             break;
           }

        }

        if(cool){
            return true;
        }

          

    }
    return false;

}


ll bit[(ll)(1e6+1)];

ll query_bit(ll index){

    ll sum = 0;

    while(index){

        sum += bit[index];

        index -= index&(-index); 

    }

    return sum;   

}

void update_bit(ll index,ll val,ll n){

     while(index < n){

         bit[index] += val;

         index += index&(-index);

     }

     return;

}
int find(ll mask,ll tar,ll index,ll n){

     if(index <0 || tar == 0){
         
         return mask;

     }

     


     if((mask|(1<<index)) < n && tar > bit[mask|(1<<index)] ){

        return find(mask|(1<<index),tar-bit[mask|(1<<index)],index -1,n);         

     } 
     else{
        

        return find(mask,tar,index -1,n);



     }


}

ll id0(ll start,ll end,ll des,bool id1 = true){
 
     while(start - end > 1){

         ll mid = end + (start - end)/2;  
     
         mid = (start - end)%2 ? mid + 1 : mid ;

         ll ans = query_bit(mid);
 
         if(ans >= des){
           
           start = mid;
            
         }
         else{

           end=mid; 
            
         }
 
    }
 
    return start;
 
}

int main(){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    ll test_case = 1;
    

 
    while(test_case--){
 
        ll n; in(n);
 
        std::fill(bit,bit+n+1,0);
 
        ll q; in(q);
 
        for(ll i =0;i<n;i++){
 
            ll input; in(input);
            
            update_bit(input,1,n+1);
 
 
        }

        ll index1  = 0;

        ll n1 = n; while(n1){ n1>>=1; index1+=1;}
 
        while(q--){
 
            ll type; in(type);
 
            if(type > 0){
 
                update_bit(type,1,n+1);
 
 
            }
            else{
 
                ll index = find(0,-type,index1-1,n+1);

                


                update_bit(index+1,-1,n+1);
 
            }
 
 
        }
 
        if(query_bit(n) > 0){
 
             out(id0(n,0,1,true));
         }
        else{
            out(0);
        }
 
 
 
 
        
 
 
 
 
 
 
   
    }
 
 
 
 
 
}