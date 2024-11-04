
                                                                        

using namespace std;













typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int, int> Author;
vector<pair<string, int> > VP; 


int n;
int a[2001],b[2001];
int dp[2002][10][10][10][10][2];	

int Solve(int ind,int x1, int x2, int x3, int x4, int y){
    if(dp[ind][x1][x2][x3][x4][y] != -1) return dp[ind][x1][x2][x3][x4][y];
    int ans=32000, c1 = ind, c2 = x4, cur;
    if(y==1){
        cur=a[ind];
        x4=b[ind];
        ind++;
    }
    else{
        cur=x4;
        x4=0;
    }
    if(ind>n && x1==0 && x2==0 && x3==0 && x4==0)
        return 0;
    if(x1!=0)
        ans=min(ans,Solve(ind,x2,x3,x4,x1,0)+max(cur-x1,x1-cur)+1);
    if(x2!=0)
        ans=min(ans,Solve(ind,x1,x3,x4,x2,0)+max(cur-x2,x2-cur)+1);
    if(x3!=0)
        ans=min(ans,Solve(ind,x1,x2,x4,x3,0)+max(cur-x3,x3-cur)+1);
    if(x4!=0)
        ans=min(ans,Solve(ind,x1,x2,x3,x4,0)+max(cur-x4,x4-cur)+1);
    if(x1==0 && ind<=n)
        ans=min(ans,Solve(ind,x2,x3,x4,x1,1)+max(cur-a[ind],a[ind]-cur)+1);
    else if(x2==0 && ind<=n)
        ans=min(ans,Solve(ind,x1,x3,x4,x2,1)+max(cur-a[ind],a[ind]-cur)+1);
    else if(x3==0 && ind<=n)
        ans=min(ans,Solve(ind,x1,x2,x4,x3,1)+max(cur-a[ind],a[ind]-cur)+1);
    else if(x4==0 && ind<=n)
        ans=min(ans,Solve(ind,x1,x2,x3,x4,1)+max(cur-a[ind],a[ind]-cur)+1);
    return dp[c1][x1][x2][x3][c2][y]=ans;
}
int main(void){
	
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin>> n;
    for(int i = 1;i <= n + 1; i++){
        if(i <= n) cin>>a[i]>>b[i];
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k <= 9; k++)
                for(int x = 0; x <= 9; x++)
                    for(int y = 0; y <= 9; y++)
                        for(int z = 0; z <= 1; z++)
                            dp[i][j][k][x][y][z] = -1;
	}
	cout<<Solve(1, 0, 0, 0, 0, 1) + a[1]<<endl;
	return EXIT_SUCCESS;
}