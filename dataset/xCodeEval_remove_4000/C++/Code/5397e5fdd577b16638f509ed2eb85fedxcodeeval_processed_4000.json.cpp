


using namespace std;

typedef long long int ll ;
typedef vector<long long int> vll;
typedef vector<int> vi;
typedef  unordered_map<int,int> umap;












class edges{
public:
    int s ,d , w ;
    edges(int s ,int d , int w){
        this->s=s;
        this->d=d;
        this->w=w;
    }
};



class GraphAM{

public :
    bool* visited;
    int** edges;
    queue<int> q;
    int n ;
    int num_comp ;
    GraphAM(int n){
        this->n = n ;
        num_comp= 0 ;
    }
    void reset(){
        for(int i =0 ; i< n ;i++){
            visited[i] = false;
        }
    }
    void DFS(int sv ){
        cout<<sv<<" ";
        visited[sv] = true ;
        for(int i = 0 ; i<n ; i ++){
            if( i == sv ) continue;
            if(visited[i]){
                continue;
            }
            if(edges[sv][i])
            DFS(i);
        }
    }
    void BFS(int sv){
        visited[sv] = true ;
        q.push(sv);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cout<<v<<" ";

            for(int i = 0 ; i< n ; i++){
                if(visited[i] ){
                    continue;
                }
                if(edges[v][i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void connectedComponents(){
        for(int i = 0 ; i < n ; i ++){
            if( !visited[i] ){
                num_comp++;
                BFS(i) ;
                cout<<endl;
            }
        }
    }
    bool breadthSearch(int s , int e ){
         visited[s] = true;
         for(int i =0 ; i<n ; i++ ){
            if(edges[s][i] && !visited[i]){
                if( i==e ){
                    return true ;
                }
                else{
                    if( breadthSearch(i ,e)){
                        return true ;
                    }
               }
            }

         }
         return false ;
    }
    bool has_path(int s , int e ){
        reset();
        if(s==e){
            return true ;
        }
        return breadthSearch(s ,e );

    }
    vector<int>* get_pathDFS( int s , int e ){
        visited[s] = true ;
        if( s==e ){
            vector<int> * v = new vector<int>();
            v->pb( e);

            return v ;
        }
        int all =1 ;
        vector<int> * v  ;
        for(int i = 0 ; i < n ; i++){

            if( edges[s][i] && !visited[i]){
                all = 0 ;
                v = get_pathDFS(i , e) ;
                if( v != NULL ){
                    v->pb(s);

                    

                    return v ;
                }
            }
        }

        return NULL ;
    }
    unordered_map<int , int> * get_pathBFS(int s , int e ){
        visited[s] = true ;
        queue<int> q ;
        q.push(s) ;
        unordered_map<int,int> * path = new unordered_map<int,int>();
        while( !q.empty()){
            int v = q.front();
            q.pop() ;
            for(int i =0 ; i< n ; i++){
               if( edges[v][i] && !visited[i]){
                    if( i == e ){

                        (*path)[i] = v ;
                        return path;
                    }
                    else{
                        (*path)[i] = v ;
                    }
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return NULL ;
    }

};


bool id0(edges * a , edges * b ){
    return a->w < b->w ;
}
vector<int> ** mst( edges ** edges , int n , int e){ 


        sort(edges , edges + e , id0);
        vector< int > ** MST = new vector<int>*[n] ;

        int parent[n];
        int num_edges =0 ;
        for(int i =0 ;i < n ; i++){
            MST[i] = new vector<int>();
            parent[i] = i ;
        }
        for(int i = 0 ; i < e ;i ++){
            int ps = parent[edges[i]->s];
            int pd = parent[edges[i]->d];

            while( ps != parent[ps]){
                ps= parent[ps];
            }
            while( pd != parent[pd]){
                pd= parent[pd];
            }
            if( ps != pd ){
                MST[edges[i]->s]->pb(edges[i]->d);
                MST[edges[i]->d]->pb(edges[i]->s);
                parent[pd] = ps ;
               

                num_edges++;

            }
            if(num_edges==n-1) break;
        }
        cout<<endl;
        return MST ;

}








map< int , vector<int> > * id2 (GraphAM g  ){
   int weight[g.n] ;
   int parent[g.n] ;
   for(int i = 0;i < g.n ; i++){
    weight[i] = INF ;
    parent[i] = -1;
   }

   parent[0] =-1 ;
   weight[0] = 0;

   int id3 = 0 ;
   int s =0 ;
   while(!id3){
    id3 = 1;
    int min = INF ;
    g.visited[s] =true ;
    for(int i=0 ; i<g.n ; i++){
        if(g.edges[s][i] && weight[i] >g.edges[s][i] && !g.visited[i] ){
            weight[i] = g.edges[s][i] ;
            parent[i] = s ;
        }
    }
    for(int i =0 ; i< g.n ; i++){
        if(min > weight[i] &&!g.visited[i]){
            s = i ;
            min = weight[i] ;
            id3 = 0 ;
        }
    }
   }
   map< int , vector<int> >* mst = new map< int , vector<int> >();

   for(int i = 1 ; i < g.n ; i++){
    (*mst)[parent[i]] . pb ( i );
   }
   return mst;
}



int* dijkstra(GraphAM g , int source ){  

    int * distance= new int[g.n] ;
    int parent[g.n] ;
    for(int i = 0;i < g.n ; i++){
        distance[i] = INF ;
        parent[i] = -1;
    }
    distance[source] = 0 ;
    parent[source] = -1 ;
    int id3 = 0 ;
    while(!id3 ){
        g.visited[source] = true ;
        id3 =1 ;
        int min = INF;
        for(int i =0 ; i< g.n ; i++){
            if(g.edges[source][i] && !g.visited[i] && distance[i]>g.edges[source][i] + distance[source]){
                distance[i] = g.edges[source][i] + distance[source] ;
            }
        }
        int fsource = -1 ;
        for(int i =0 ;i < g.n ; i++){
            if(min > distance[i] && g.edges[i][source]&&!g.visited[i]){
                min = distance[i] ;
                fsource = i ;
                id3 = 0 ;
            }
        }
        source = fsource ;
    }
    return distance ;
}





ll ft[lim+1];



bool great1(pair<ll ,int > a  , pair<ll , int > b ){
    return a.first > b.first ;
}
bool great2(pair<ll ,int > a  , pair<ll , int > b ){
    return a.second < b.second ;
}
bool great(int a , int b ){
    return a> b ;
}



ll binpow( ll a, ll b  )
    {
        a %= MOD;
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res%MOD;
    }
ll modInverse(ll a, ll p)
{
    return (ll)binpow(a, p - 2);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void buildFact()
{
    ft[0]=1;
    ll result = 1;
    for (ll i = 1; i <= lim; i++)
        {
            result = (result * i) % MOD;
            ft[i]=(ll)result;
        }
}
int prime(int a){
    for(int i =2;i<a/2;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
ll nCr(ll n,ll r)
{
    ll ans=ft[n];
    ans=(ans*modInverse(ft[n-r],MOD))%MOD;
    ans=(ans*modInverse(ft[r],MOD))%MOD;
    return ans%MOD;
}
bool isPrime(ll n)
{
    

    if (n <= 1)  return false;
    if (n <= 3)  return true;

    

    

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}



int binsearch(int * a , int s , int e , int v ){
    int l=s , u= e;
    int m ;
    while(l<=u){
        m = (l+u)/2;
        

        if(a[m]>v){
            u=m-1;
        }
        else if(a[m]<v){
            l=m+1;
        }
        else{
            break ;
        }
    }
    

    if(a[m] == v){
        return m ;
    }
    else{
        return -1 ;
    }
}


int ** LCS(string s , string t ){
   int ** a = new int*[s.length()+1] ;
   for(int i = 0 ; i <s.length()+1 ; i++){
        a[i] = new int[t.length()+1];
        for(int j =0 ; j< t.length()+1 ; j++){
            a[i][j] = -1 ;
        }
   }
   for(int i = 0 ; i < s.length() +1 ; i++){
        for(int j = 0 ; j < t.length()+1 ; j++){
            if(i==0 || j==0){
                a[i][j] = 0 ;
            }
            else if( s[s.length()-i] == t[t.length()-j]){
                a[i][j] = 1 + a[i-1][j-1];
            }
            else {
                a[i][j] =max(a[i-1][j] , a[i][j-1] ) ;
            }
        }
   }
   return a ;
}
int minEdit( string s , string t){

    if( s.length() == 0 || t.length() == 0 ){
        return max(t.length(),s.length());
    }
    if(s[0] == t[0]){
        return minEdit(s.substr(1),t.substr(1));
    }
    else{
        int a = minEdit(s.substr(1) , t); 

        int b = minEdit(s,t.substr(1));

       


        return 1+ min(a,b);
    }
}
int maxVal( int *weights , int* values , int W , int n   ){
    if( n == 0 ){
        return 0 ;
    }
    int a  = 0;
    if( weights[0] <=   W )
    a = values[0] + maxVal( weights +1 , values +1 , W-weights[0] , n-1 );
    int b = maxVal(weights + 1 , values+1, W , n-1 );
    return max(a,b) ;

}
bool id1( pair<int , int > a , pair<int , int> b ){
    return a.second <b.second ;
}


void buildSeg( int * a , ll  * t, int v , int l , int  r ) {
    

    

    if(l == r ){
        t[v] = a[l] ;
        return ;
    }
    int m = (l+r)/2 ;
    buildSeg(a , t , 2*v   , l  , m );

    buildSeg(a , t , 2*v+1 , m+1, r );

    

    t[v] = t[2*v] + t[2*v +1 ] ;
}

ll sumQuery( ll * t ,int v  ,int tl , int tr, int l ,int r ){
    

    

    if( l > r){
        return 0 ;
    }
    if( tl == l &&  tr ==r  ){
        return t[v] ;
    }
    else{
        int tm = (tl + tr)/2 ;
        if( tl <= l && l <= tm && tl <= r && r <= tm  ){
            

            return  sumQuery(t, 2*v   , tl    , tm , l ,r ) ;
        }
        else if( tm < l && l <= tr && tm < r && r <= tr ){
            return  sumQuery(t, 2*v +1 , tm+1  , tr , l ,r );
        }
        else{
            ll s1 = sumQuery(t, 2*v   ,  tl     , tm , l , tm ) ;
            ll s2 = sumQuery(t, 2*v+1 , tm +1 , tr , tm+1 ,r ) ;
            return  s1+s2 ;
        }
    }
}
void updateQuery(ll * t , int v , int i , int l , int r , int u ){
    if( l == i && r == i  ){
        t[v] = u ;
        

        return ;
    }
    int  m = (l+r) /2 ;
    if( i <= m ){
        updateQuery(t, 2*v , i , l , m , u  ) ;

    }else{
        updateQuery(t,2*v+1 , i , m+1, r , u ) ;
    }
    t[v] = t[2*v] + t[2*v +1] ;

}


pair<int, int> tmax[400004];
pair<int,int> tmin[400004];
int a[100001];
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build( int v, int tl, int tr) {
    if (tl == tr) {
        tmax[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        tmax[v] = combine(tmax[v*2], tmax[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {

    if (l > r || v < 1  )
        return make_pair(-INF, 0);
    if (l == tl && r == tr )
        return tmax[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)),
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

pair<int, int> combine1(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first  )
        return a;
    else if (b.first < a.first )
        return b;

    return make_pair(a.first, a.second + b.second);
}

void build1( int v, int tl, int tr) {
    if (tl == tr) {
        tmin[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build1( v*2, tl, tm);
        build1( v*2+1, tm+1, tr);
        tmin[v] = combine1(tmin[v*2], tmin[v*2+1]);

    }
}

pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
   

    if (l > r  || v < 1  )
        return make_pair(INF+1, 0);
    if (l == tl && r == tr)
        return tmin[v];
    int tm = (tl + tr) / 2;
    return combine1(get_min(v*2, tl, tm, l, min(r, tm)),
                   get_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int n ; cin >> n;
    int  u = n , l = 1 ;
    int m = (l+u)/2;
    int s0 , s1 , s2 ;
    cout<<"? "<<l << " "<<u <<endl;;
    cin >> s0 ;

    while( 1 ){



        if( u-l == 1 ){
            if( s0 == l ){
                cout <<"! "<<u <<endl;exit(0);
            }
            else{
                cout <<"! "<<l <<endl;exit(0);
            }
        }

       if( s0 > m ){
         cout<< "? "<<m<<" "<<u <<endl;
         cin >> s1 ;
         if( s1 == s0 ){
            l = m ;
            s0 = s1 ;
         }
         else{
            cout<< "? "<<l<<" "<<(l+u)/2 <<endl;
            cin >> s0 ;
            u = m ;
         }
       }
      else{
        cout<< "? "<<l<<" "<<m <<endl;
         cin >> s1 ;
         if( s1 == s0 ){
            u = m ;
            s0 = s1 ;
         }
         else{
            cout<< "? "<<(l+u)/2<<" "<<u <<endl;
            cin >> s0 ;
            l = m  ;
         }
      }
        m = (l+u)/2;
    }




    return 0;
}

