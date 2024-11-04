#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define vvi vector<vi>
#define vvll vector<vll>
#define ff first
#define ss second
#define pb push_back
#define vpi vector<pi>
#define vpll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(),x.end()
#define fr(i,j,n) for(int i=j;i<n;++i)
#define rfr(i,j,n) for(int i=j; i>=n;--i)
#define MOD 1000000007
#define INF INT_MAX
#define LLINF LONG_LONG_MAX
#define mp make_pair
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void func1(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i+1,j+1));
    r1.pb(mp(i+1,j));
    r2.pb(mp(i,j));
    r3.pb(mp(i,j+1));
    r1.pb(mp(i+1,j+1));
    r2.pb(mp(i+1,j));
    r3.pb(mp(i,j));
}
void func2(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j+1));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i+1,j));
    r1.pb(mp(i,j));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i+1,j+1));
    r1.pb(mp(i+1,j));
    r2.pb(mp(i,j));
    r3.pb(mp(i,j+1));
}
void func3(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j));
    r2.pb(mp(i,j));
    r3.pb(mp(i,j+1));
    r1.pb(mp(i+1,j+1));
    r2.pb(mp(i+1,j));
    r3.pb(mp(i,j));
    r1.pb(mp(i,j+1));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i+1,j));
}
void func4(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j+1));
    r2.pb(mp(i+1,j));
    r3.pb(mp(i,j));
    r1.pb(mp(i,j+1));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i+1,j));
    r1.pb(mp(i,j));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i+1,j+1));
}
void func11(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j+1));
    r2.pb(mp(i,j));
    r3.pb(mp(i+1,j));
}
void func12(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j));
    r2.pb(mp(i+1,j));
    r3.pb(mp(i+1,j+1));
}
void func13(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i,j+1));
}
void func14(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j+1));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i,j));
}
void func5(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j));
    r2.pb(mp(i+1,j));
    r3.pb(mp(i+1,j+1));
    func13(i,j,r1,r2,r3);
}
void func6(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i,j+1));
    func14(i,j,r1,r2,r3);
}
void func7(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j+1));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i,j));
    func11(i,j,r1,r2,r3);
}
void func8(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j+1));
    r2.pb(mp(i,j));
    r3.pb(mp(i+1,j));
    func12(i,j,r1,r2,r3);
}

void func9(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j+1));
    r2.pb(mp(i,j));
    r3.pb(mp(i+1,j));
    func13(i,j,r1,r2,r3);
}
void func10(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i,j));
    r2.pb(mp(i,j+1));
    r3.pb(mp(i+1,j+1));
    func12(i,j,r1,r2,r3);
}

void func15(int i,int j,vpi& r1,vpi& r2,vpi& r3){
    r1.pb(mp(i+1,j));
    r2.pb(mp(i+1,j+1));
    r3.pb(mp(i,j+1));
    func1(i,j,r1,r2,r3);
}

void flip(string arr[],int i,int j){
    if(arr[i][j] == '1')
        arr[i][j] = '0';
    else
        arr[i][j] = '1';
}

void pre() {
    int n,m;
    cin>>n>>m;
    string arr[n];
    fr(i,0,n){
        cin>>arr[i];
    }
    vpi r1,r2,r3;
    fr(i,0,n-1){
        fr(j,0,m-2){
            if(arr[i][j] == '0' && arr[i+1][j] == '0')
                continue;
            if(arr[i][j] == '1' && arr[i+1][j] == '0'){
                r1.pb(mp(i,j));
                r2.pb(mp(i,j+1));
                r3.pb(mp(i+1,j+1));
                flip(arr,i,j);
                flip(arr,i,j+1);
                flip(arr,i+1,j+1);
            }
            if(arr[i][j] == '0' && arr[i+1][j] == '1'){
                r1.pb(mp(i+1,j));
                r2.pb(mp(i+1,j+1));
                r3.pb(mp(i,j+1));
                flip(arr,i+1,j);
                flip(arr,i+1,j+1);
                flip(arr,i,j+1);
            }
            if(arr[i][j] == '1' && arr[i+1][j] == '1'){
                r1.pb(mp(i,j));
                r2.pb(mp(i+1,j));
                r3.pb(mp(i+1,j+1));
                flip(arr,i,j);
                flip(arr,i+1,j);
                flip(arr,i+1,j+1);
            }  
        }
    }
    fr(i,0,n-2){
        fr(j,m-2,m-1){
            if(arr[i][j] == '0' && arr[i][j+1] == '0')
                continue;
            if(arr[i][j] == '1' && arr[i][j+1] == '0'){
                r1.pb(mp(i,j));
                r2.pb(mp(i+1,j));
                r3.pb(mp(i+1,j+1));
                flip(arr,i,j);
                flip(arr,i+1,j);
                flip(arr,i+1,j+1);
            }
            if(arr[i][j] == '0' && arr[i][j+1] == '1'){
                r1.pb(mp(i,j+1));
                r2.pb(mp(i+1,j+1));
                r3.pb(mp(i+1,j));
                flip(arr,i,j+1);
                flip(arr,i+1,j+1);
                flip(arr,i+1,j);
            }
            if(arr[i][j] == '1' && arr[i][j+1] == '1'){
                r1.pb(mp(i,j));
                r2.pb(mp(i,j+1));
                r3.pb(mp(i+1,j+1));
                flip(arr,i,j);
                flip(arr,i,j+1);
                flip(arr,i+1,j+1);
            }  
        }
    }
    int i,j;
    i=n-2,j=m-2;
            if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
                
            }
            

            else if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
                func1(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
                func2(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
                func3(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
                func4(i,j,r1,r2,r3);
            }
            

            else if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
                func5(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
                func6(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
                func7(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '0'&& arr[i+1][j+1] == '1'){
                func8(i,j,r1,r2,r3);
            }
            

            else if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
                func9(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
                func10(i,j,r1,r2,r3);
            }
            

            else if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
                func11(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
                func12(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
                func13(i,j,r1,r2,r3);
            }
            else if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
                func14(i,j,r1,r2,r3);
            }
            else{
                func15(i,j,r1,r2,r3);
            }
    
    int res = r1.size();
    cout<<res<<endl;
    fr(i,0,res){
        cout<<r1[i].ff+1<<" "<<r1[i].ss+1<<" "<<r2[i].ff+1<<" "<<r2[i].ss+1<<" "<<r3[i].ff+1<<" "<<r3[i].ss+1<<endl;
    }
}

int main() {
	fastIO; 
	

	

	

	

    int t;
    cin>>t;
    while(t--)
	    pre();
	return 0; 
	
}
