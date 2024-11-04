



using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;



























































































































































 






















 










 




























































 


















































 

























vector<int>seg;

void build(int ind, int low, int high, vector<int>&t){
    

    if(high == low){
        

        seg[ind] = t[high];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,t);
    build(2*ind+2,mid+1,high,t);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind, int low, int high, int l, int r){
    if(low>=l and high <= r){
        return seg[ind];
    }
    if(high<l or low>r){
        return 0;
    }
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return left+right;
}

void update(int ind, int low, int high, int node, int val){
    if(low==high){
        seg[ind]=val;
    }else{
        int mid = (high+low)/2;
        if(node<=mid and node>=low){
            update(2*ind+1,low,mid,node,val);
        }else{
            update(2*ind+2,mid+1,high,node,val);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
}

void solve(){
    seg.clear();
    int n,m,q;cin>>n>>m>>q;
    vector<vector<char>>v(n,vector<char>(m));
    seg.resize(4*n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    string s="";
    vector<int>t;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[j][i]=='.')t.push_back(0);
            else t.push_back(1);
        }
    }
    

    build(0,0,n*m-1,t);
    

    

    

    

    

    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        int x=b*n+a;
        if(t[x]==1){
            t[x]=0;
            update(0,0,n*m-1,x,0);
        }else{
            t[x]=1;
            update(0,0,n*m-1,x,1);
        }
        int c=query(0,0,n*m-1,0,n*m-1);
        

        int d=query(0,0,n*m-1,0,c-1);
        

        cout<<c-d<<endl;

    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t=1;
    while(t--){
        solve();
    }
    

}








