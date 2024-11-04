




using namespace std;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int lu;
typedef vector< int > vi;
typedef vector < ll > vl;
typedef set <ll> sl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< ll,ll > il;



















 
set <ll> st[100005];
ll d[100005];
 
vector<char> prime (100000+1, true);
void sieve(ll n)
{   
    

    prime[0] = prime[1] = false;
    for (ll i=2; i<=n; ++i)
    {
        if (prime[i])
        {
            st[i].insert(i);            
            for (ll j=2*i; j<=n; j+=i)
            {
                prime[j] = false;
                st[j].insert(i);
            }
        }
    }
}




 


typedef ll LT;
typedef pair<LT,LT> LP;
struct CHT {
  deque<LP> d;
  LT get(LT x) {
    while (sz(d) >= 2) {
      LT a = d[0].fi*x + d[0].se;
      LT b = d[1].fi*x + d[1].se;
      if (a <= b) break; 

      d.pop_front();
    }
    return d[0].fi*x + d[0].se;
  }
  void add(LP x) { 

    while (sz(d) >= 2) {
      LP y = d[sz(d) - 1];
      LP z = d[sz(d) - 2];
      if ((x.se-y.se)*(z.fi-y.fi) >= (y.fi-x.fi)*(y.se-z.se)) break; 

      d.pop_back();
    }
    d.pb(x);
  }
};


 















ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll id1(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = id1(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
ll fastpow(ll a, ll p){ if(p==0) return 1; ll z = fastpow(a,p/2); z = (z*z); if(p%2) z = (z*a); return z; }


ll search1(ll a[], ll f,ll n)
{
    ll left=1;
    ll right=n+1;
    while(right-left>1)
    {
        ll mid = left + (right-left)/2;
        if(a[mid]<f)
        {
            left=mid;
        }
        else right=mid;
    }
    return a[left];
}
 
const ll INF = 1e18;
vector<ll> lazy;
vector<ll> tree;
 
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        

        tree[node] += ( + 1) * lazy[node];    

        if(start != end)
        {
            lazy[node*2] += lazy[node];                  

            lazy[node*2+1] += lazy[node];                

        }
        lazy[node] = 0;                                  

    }
    if(start > end or start > r or end < l)              

        return;
    if(start >= l and end <= r)
    {
        

        lazy[node] += ( + 1) * val;
        if(start != end)
        {
            

            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node]+=lazy[node];
        lazy[node]=0;
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        

    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

    tree[node] = max(tree[node*2],tree[node*2+1]);        

}
 
ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(lazy[node] != 0)
    {
        

        tree[node] += ( 1) * lazy[node];            

        if(start != end)
        {
            lazy[node*2] += lazy[node];         

            lazy[node*2+1] += lazy[node];    

        }
        lazy[node] = 0;                 

    }
 
    if(start > end or start > r or end < l)
        return -INF;         

 
    if(start >= l and end <= r)             

        return tree[node];
    ll mid = (start + end) / 2;
    if(r<=mid)return queryRange(node*2, start, mid, l, r);
    else if(l>=mid+1) return queryRange(node*2 + 1, mid + 1, end, l, r);
    ll p1 = queryRange(node*2, start, mid, l, r);         

    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 

    

    return max(p1,p2);
}

void convert_reduce(ll arr[], ll n) 
{ 
    vector <pair<ll, ll> > v; 
    for (ll i = 0; i < n; i++)v.push_back(make_pair(arr[i], i)); 
    sort(v.begin(), v.end());
    ll cnt = 0; 
    for (ll i=0; i<n; i++)
    {
        arr[v[i].second] = cnt;
        ll j = i;
        while(j<n && v[j].fi==v[i].fi)arr[v[j++].second] = cnt;
        i=j-1;
        cnt++;
    } 
}






struct Point 
{ 
    ll x, y; 
};
vector<Point> vp;

  




Point p0; 
  


Point id0(stack<Point> &S) 
{ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 
  


void swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  




ll distSq(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
  










int orientation(Point p, Point q, Point r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == (ll)0) return (int)0;  

    return (val > (ll)0)? (int)1: (int)2; 

} 
  




int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   

   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
  


void id2(Point points[], ll n) 
{ 
   

   ll ymin = points[0].y, min = 0; 
   for (ll i = 1; i < n; i++) 
   { 
     ll y = points[i].y; 
  
     

     

     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   

   swap(points[0], points[min]); 
  
   

   

   

   

   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   

   

   

   

   

   ll m = 1; 

   for (int i=1; i<n; i++) 
   { 
       

       

       while (i < n-1 && orientation(p0, points[i], 
                                    points[i+1]) == 0) 
          i++; 
  
  
       points[m] = points[i]; 
       m++;  

   } 
  
   

   

   if (m < 3) return; 
  
   

   

   stack<Point> S; 
   S.push(points[0]); 
   S.push(points[1]); 
   S.push(points[2]); 
  
   

   for (ll i = 3; i < m; i++) 
   { 
      

      

      

      while (orientation(id0(S), S.top(), points[i]) != 2) 
         S.pop(); 
      S.push(points[i]); 
   } 
  
   

   while (!S.empty()) 
   { 
       Point p = S.top(); 
       vp.pb(p); 
       S.pop(); 
   } 
} 


ld area(Point A,Point B,Point C)
{
    ld darea = (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
    darea/=2;
    if(darea<0.0)return (-darea);
    else return darea;
}

 
int main(){
    fastio;
    ll n,i,j,k;
    cin >> n;
    ll S;
    cin >> S;
    Point points[n];
    rep(i,0,n)
    {
        ll x,y;
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    id2(points,n);
    ll m = sz(vp);
    rep(i,0,m)
    {
        vp.pb(vp[i]);
    }
    ld maxval=0;
    Point p[3];
    rep(i,0,m)
    {
        ld maxs = 0;
        j = i+1;
        k = i+2;
        while(k<i+m)
        { 
            ll ki = k;
            ll ji = j;
            while(k<i+m && area(vp[i],vp[j],vp[k])>=maxs)
            {
                maxs = area(vp[i],vp[j],vp[k]);
                if(maxval<maxs)
                {
                    p[0]=vp[i];
                    p[1]=vp[j];
                    p[2]=vp[k];
                    maxval = maxs;
                }
                k++;
            }
            

            k--;
            while(j<k && area(vp[i],vp[j],vp[k])>=maxs)
            {
                maxs = area(vp[i],vp[j],vp[k]);
                if(maxval<maxs)
                {
                    p[0]=vp[i];
                    p[1]=vp[j];
                    p[2]=vp[k];
                    maxval = maxs;
                }
                j++;
            }
            

            j--;
            if(ki==k && ji==j)break;
        }
    }
    cout << p[0].x+p[1].x-p[2].x << " "<<p[0].y+p[1].y-p[2].y<<endl;
    cout<<p[0].x+p[2].x-p[1].x<<" "<<p[0].y+p[2].y-p[1].y<<endl;
    cout<<p[1].x+p[2].x-p[0].x<<" "<<p[1].y+p[2].y-p[0].y<<endl;
    return 0;
}

