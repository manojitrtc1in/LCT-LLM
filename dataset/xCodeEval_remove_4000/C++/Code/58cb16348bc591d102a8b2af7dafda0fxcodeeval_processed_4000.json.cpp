

using namespace std;
typedef long long int lli;
typedef unsigned long long int uli;
typedef long double Lf;
typedef pair<int,int> pii;
typedef vector<int> vi;

















inline lli modadd(lli n,lli m,lli p=mod){
    return ((n+m)%p+p)%p;
}

inline lli modsub(lli n,lli m,lli p=mod){
    return ((n-m+p)%p+p)%p;
}

inline lli modpro(lli n,lli m,lli p=mod){
    return (((n%p)*(m%p))%p+p)%p;
}

uli powe(lli x,lli y){
    uli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

lli modpow(lli x,lli y,lli p=mod){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x, p);
        y = y >> 1;
        x = modpro(x , x, p);
    }
    return res;
}

inline lli modInverse(lli n, lli p=mod)
{
    if(n==1) return 1;
    return modpow(n, p-2, p);
}

inline lli moddiv(lli n,lli m,lli p=mod){
    return modpro(n,modInverse(m,p),p);
}

inline lli id0(lli x, lli y, lli z,lli p=mod){
    return modadd(modadd(x,y,p),z,p);
}

inline lli id1(lli x, lli y, lli z, lli w,lli p=mod){
    return modadd(modadd(x,y,p),modadd(z,w,p),p);
}

inline lli id2(lli fac[], int n, int r, lli p=mod)
{
    if (r==0) return 1;
    return modpro(fac[n],modInverse(modpro(fac[r],fac[n-r],p),p),p);
}

template <typename T>
inline T max3(T x, T y, T z){
    return max(max(x,y),z);
}

template <typename T>
inline T max4(T x, T y, T z, T w){
    return max(max3(x,y,w),z);
}

template <typename T>
inline T min3(T x, T y, T z){
    return min(min(x,y),z);
}

template <typename T>
inline T min4(T x, T y, T z, T w){
    return min(min3(x,y,w),z);
}

template <typename T>
void printArr(T *arr, int s, int n){
    for(int i=s;i<=n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;
}


































































































































































































































































































































































































































































































































































































vector<int> parent, rank_;

void makeSet(int x){
	parent[x]=x;
	rank_[x]=0;
}

int findSet(int x){
	if(x!=parent[x])
		parent[x]=findSet(parent[x]);

	return parent[x];
}

void unionSets(int x, int y){
	int px = findSet(x);
	int py = findSet(y);
    if(px==py) return;
	if(rank_[px]<rank_[py]){
		parent[px]=py;
	}
	else if(rank_[py]<rank_[px]){
		parent[py]=px;
	}
	else{
		parent[py]=px;
		rank_[px]++;
	}

}
int col;
vi adj[N], adjt[N];
bool a[NN][NN], b[NN][NN], c[N];
int tim,ft[N], scc[N], val[N];
bool vis[N];
void dfs(int x) {
    vis[x]=1;
    for(int u: adj[x]){
        if(vis[u]) continue;
        dfs(u);
    }
    ft[tim++]=x;
}
void dfst(int x) {
    vis[x]=1;
    scc[x]=col;
    for(int u: adjt[x]){
        if(vis[u]) continue;
        dfst(u);
    }


}int main(){
    fastIO;
    int erer=1;


    loop(erer2,1,erer+1){
        int n;
        cin>>n;
        char x;




        loop(i,0,n) loop(j,0,n) {cin>>x; a[i][j]=(x-'0');}
        loop(i,0,n) loop(j,0,n) {cin>>x; b[i][j]=(x-'0');}

        loop(i,0,n) {  cin>>x; c[i]=(x-'0');}
        memset(val,-1,sizeof(val));
        loop(i,0,n) loop(j,0,n){
            if(a[i][j]==b[i][j]){
                if(c[i]==1 && c[j]==1) {
                    adj[4*j].pb(4*i+2);
                    adj[4*j+1].pb(4*i+3);
                    adj[4*i+2].pb(4*j);
                    adj[4*i+3].pb(4*j+1);
                }
                else if(c[i]==0 && c[j]==1) {
                    if(val[4*i+2]==1 || val[4*i+3]==0) {cout<<-1;r0;}
                    val[4*i+2]=0;
                    val[4*i+3]=1;
                }
                else if(c[i]==1 && c[j]==0) {
                    if(val[4*j]==1 || val[4*j+1]==0) {cout<<-1;r0;}
                    val[4*j]=0;
                    val[4*j+1]=1;
                }
            }
            else {
                if(c[i]==1 && c[j]==1) {
                    adj[4*j].pb(4*i+3);
                    adj[4*j+1].pb(4*i+2);
                    adj[4*i+2].pb(4*j+1);
                    adj[4*i+3].pb(4*j);
                }
                else if(c[i]==0 && c[j]==1) {
                    if(val[4*i+2]==0 || val[4*i+3]==1) {cout<<-1;r0;}


                    val[4*i+2]=1;
                    val[4*i+3]=0;
                }
                else if(c[i]==1 && c[j]==0) {
                    if(val[4*j]==0 || val[4*j+1]==1) {cout<<-1;r0;}
                    val[4*j]=1;
                    val[4*j+1]=0;
                }
                else {
                    cout<<-1;r0;
                }
            }
        }



        loop(i,0,4*n) for(int x: adj[i]) adjt[x].pb(i);

        for(int i=0;i<4*n;i+=2) {
            if(val[i]==1 || val[i]==-1){
                if(!vis[i]) dfs(i);
                if(!vis[i+1]) dfs(i+1);
            }
            else {
                if(!vis[i+1]) dfs(i+1);
                if(!vis[i]) dfs(i);
            }
        }

        loop(i,0,4*n) vis[i]=0;

        loopr(i,4*n,0) if(!vis[ft[i]]){
            dfst(ft[i]);
            col++;
        }


        loop(i,0,n){
            int j=i;


            if(scc[4*i] == scc[4*i+1] || scc[4*j+2] == scc[4*j+3]) {cout<<-1;r0;}




            if(scc[4*i]< scc[4*i+1]) { if(val[4*i]==1 || val[4*i+1]==0) {cout<<-1;r0;} else { val[4*i]=0;
                    val[4*i+1]=1; } }
            else {
                if(val[4*i]==0 || val[4*i+1]==1) {cout<<-1;r0;}
                    val[4*i]=1;
                    val[4*i+1]=0;
            }
            if(scc[4*j+2]< scc[4*j+3]) {
                if(val[4*j+2]==1 || val[4*j+3]==0) {cout<<-1;r0;}
                    val[4*j+2]=0;
                    val[4*j+3]=1;
            }
            else {
                if(val[4*j+2]==0 || val[4*j+3]==1) {cout<<-1;r0;}
                    val[4*j+2]=1;
                    val[4*j+3]=0;
            }
        }
        int c=0;
        loop(i,0,n){
            if(val[4*i]) c++;
            if(val[4*i+2]) c++;
        }
        cout<<c<<endl;
        loop(i,0,n){
            if(val[4*i+2]) o2("row", i);
            if(val[4*i]) o2("col", i);

        }
    }
    return 0;
}
