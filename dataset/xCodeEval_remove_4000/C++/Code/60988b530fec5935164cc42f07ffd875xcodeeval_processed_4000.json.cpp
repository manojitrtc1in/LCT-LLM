







using namespace std;



































const int inf=0x3f3f3f3f;
const long double pi=acos(-1.0);



const string debug_line="yolo";

const double PI=4*atan(1);




typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;

ll dp[100001][3];
ll a[100001];
vi Adj[100001];
ll dp1[100001][3];
bool visited[100001];
vi e[100001];
ll answer1=0;

void DFS(int u,int p){
	visited[u]=true;
	bool isleaf=true;

	rep(t1,Adj[u]){
		if(!visited[t1] && t1!=p){
			isleaf=false;
			e[u].pb(t1);
			DFS(t1,u);
		}
	}

	if(isleaf){
		answer1=max(answer1,a[u]);
		dp[u][0]=dp[u][1]=dp[u][2]=a[u];
		return ;
	}

	if(e[u].size()==1){
		dp[u][0]=dp[e[u][0]][0]+a[u];
		dp[u][1]=max(dp[u][0],max(a[u],dp[e[u][0]][1]));
		dp[u][2]=max(dp[e[u][0]][0]+a[u],max(dp[e[u][0]][2]+a[u],dp[e[u][0]][1]+a[u]));
		answer1=max(answer1,max(max(dp[u][0],dp[u][1]),dp[u][2]));
	}
	else{
		

		

		rep(t1,e[u]){
			dp[u][0]=max(dp[u][0],dp[t1][0]+a[u]);
		}
		
		

		rep(t1,e[u]){
			dp[u][1]=max(dp[u][1],dp[t1][1]);
		}
		vector<ll> temp1;
		rep(t1,e[u]){
			temp1.pb(dp[t1][0]);
		}
		sort(all(temp1));
		reverse(all(temp1));
		if(temp1.size()>=2){
			dp[u][1]=max(dp[u][1],temp1[0]+temp1[1]+a[u]);
		}
		dp[u][1]=max(dp[u][1],dp[u][0]);

		

		rep(t1,e[u]){
			dp[u][2]=max(dp[u][2],dp[t1][2]+a[u]);
		}
		int counter1=0;
		ll dp1[2][3]={0};
		For(i,0,2){
			For(j,0,3){
				dp1[i][j]=-10000000000000000LL;
			}
		}

		For(i,0,e[u].size()){
			For(j,0,3){
				dp1[i%2][j]=-10000000000000000LL;
			}
			dp1[i%2][0]=max(dp1[((i-1)%2+2)%2][0],dp[e[u][i]][0]);
			dp1[i%2][1]=max(dp1[((i-1)%2+2)%2][1],dp[e[u][i]][1]);
			dp1[i%2][2]=max(dp1[((i-1)%2+2)%2][2],max(dp1[((i-1)%2+2)%2][1]+dp[e[u][i]][0],dp1[((i-1)%2+2)%2][0]+dp[e[u][i]][1]));
		}
		For(j,0,3){
			dp[u][2]=max(dp[u][2],dp1[(e[u].size()-1)%2][j]+a[u]);
		}
		vector<pair<pair<ll,int>,int> >temp2;
		rep(t1,e[u]){
			

			temp2.pb(mp(mp(dp[t1][1],1),t1));
			temp2.pb(mp(mp(dp[t1][0],0),t1));
		}
		sort(all(temp2));
		reverse(all(temp2));
		int count1=0;
		int count2=0;
		ll tempa=0;
		set<int> s1;

		rep(t1,temp2){
			

			if(s1.find(t1.y)==s1.end()){
				if(t1.x.y==0){
					if(count1==0){
						count1++;
						s1.insert(t1.y);
						tempa+=t1.x.x;
						

					}
				}
				else if(t1.x.y==1){
					if(count2==0){
						count2++;
						s1.insert(t1.y);
						

						tempa+=t1.x.x;
					}
				}
			}
		}
		rep(t1,temp2){
			if(t1.x.y==1){
				dp[u][2]=max(dp[u][2],t1.x.x+a[u]);
				break;
			}
		}
		dp[u][2]=max(max(dp[u][2],tempa+a[u]),max(dp[u][1],dp[u][0]));
		answer1=max(answer1,max(max(dp[u][0],dp[u][1]),dp[u][2]));
	}

	

	

	vector<ll> temp;
	answer1=max(answer1,max(max(dp[u][0],dp[u][1]),dp[u][2]));
	vector<pair<pair<ll,int>,int> >v1;
	rep(t1,e[u]){
		temp.pb(dp[t1][0]);
	}
	sort(all(temp));
	reverse(all(temp));
	if(temp.size()>=1){
		

		answer1=max(answer1,temp[0]+a[u]);
	}
	if(temp.size()>=2){
		answer1=max(answer1,temp[0]+temp[1]+a[u]);
	}
	if(temp.size()>=3){
		

		answer1=max(answer1,temp[0]+temp[1]+temp[2]+a[u]);
	}
	

	



	vector<pair<pair<ll,int>,int> >temp2;
	set<int> s1;
	ll dp1[2][3];
	ll tempa=0;
	For(i,0,2){
		For(j,0,3){
			dp1[i][j]=-10000000000000000LL;
		}
	}
	For(i,0,e[u].size()){
		For(j,0,3){
			dp1[i%2][j]=-10000000000000000LL;
		}
		For(j,0,3){
			dp1[i%2][0]=max(dp1[((i-1)%2+2)%2][0],dp[e[u][i]][0]);
			dp1[i%2][1]=max(dp1[((i-1)%2+2)%2][1],dp[e[u][i]][2]);
			dp1[i%2][2]=max(dp1[((i-1)%2+2)%2][2],max(dp1[((i-1)%2+2)%2][0]+dp[e[u][i]][2],dp1[((i-1)%2+2)%2][1]+dp[e[u][i]][0]));
		}
	}
	For(j,0,3){
		answer1=max(answer1,dp1[(e[u].size()-1)%2][j]+a[u]);
	}
	

	rep(t1,e[u]){
		temp2.pb(mp(mp(dp[t1][2],2),t1));
		temp2.pb(mp(mp(dp[t1][0],0),t1));
	}
	sort(all(temp2));
	reverse(all(temp2));
	s1.clear();
	int count1=0;
	int count2=0;
	tempa=0;
	rep(t1,temp2){
		if(t1.x.y==0){
			if(s1.find(t1.y)==s1.end() && count1==0){
				count1++;
				tempa+=t1.x.x;
				s1.insert(t1.y);
			}
		}
		else if(t1.x.y==2){
			if(s1.find(t1.y)==s1.end() && count2==0){
				count2++;
				tempa+=t1.x.x;
				s1.insert(t1.y);
			}
		}
	}
	if(count1==1 && count2==1){
		answer1=max(answer1,tempa+a[u]);
	}

	


	temp2.clear();
	s1.clear();
	count1=0;
	count2=0;
	tempa=0;
	For(i,0,2){
		For(j,0,3){
			dp1[i][j]=-10000000000000000LL;
		}
	}
	For(i,0,e[u].size()){
		For(j,0,3){
			dp1[i%2][j]=-10000000000000000LL;
		}
		For(j,0,3){
			dp1[i%2][0]=max(dp1[((i-1)%2+2)%2][0],dp[e[u][i]][0]);
			dp1[i%2][1]=max(dp1[((i-1)%2+2)%2][1],dp[e[u][i]][1]);
			dp1[i%2][2]=max(dp1[((i-1)%2+2)%2][2],max(dp1[((i-1)%2+2)%2][0]+dp[e[u][i]][1],dp1[((i-1)%2+2)%2][1]+dp[e[u][i]][0]));
		}
	}
	For(j,0,3){
		answer1=max(answer1,dp1[(e[u].size()-1)%2][j]+a[u]);
	}
	

	rep(t1,e[u]){
		temp2.pb(mp(mp(dp[t1][1],1),t1));
		temp2.pb(mp(mp(dp[t1][0],0),t1));
	}

	sort(all(temp2));
	reverse(all(temp2));

	rep(t1,temp2){
		if(t1.x.y==0){
			if(s1.find(t1.y)==s1.end() && count1==0){
				count1++;
				tempa+=t1.x.x;
				s1.insert(t1.y);
			}
		}
		else if(t1.x.y==1){
			if(s1.find(t1.y)==s1.end() && count2==0){
				count2++;
				tempa+=t1.x.x;
				s1.insert(t1.y);
			}
		}
	}
	if(count1==1 && count2==1){
		answer1=max(answer1,tempa+a[u]);
	}

	


	temp2.clear();
	count1=0;
	count2=0;
	tempa=0;
	s1.clear();
	rep(t1,e[u]){
		temp2.pb(mp(mp(dp[t1][1],1),t1));
	}
	sort(all(temp2));
	reverse(all(temp2));

	rep(t1,temp2){
		if(s1.find(t1.y)==s1.end()){
			if(count2<2){
				count2++;
				s1.insert(t1.y);
				tempa+=t1.x.x;
				

			}
		}
	}
	if(count2==2){
		answer1=max(answer1,tempa);
	}

	


	temp2.clear();
	s1.clear();
	count1=0;
	count2=0;
	tempa=0;
	rep(t1,e[u]){
		temp2.pb(mp(mp(dp[t1][1],1),t1));
		temp2.pb(mp(mp(dp[t1][0],0),t1));
	}
	sort(all(temp2));
	reverse(all(temp2));
	

	ll dp2[3][8];
	tempa=0;
	For(i,0,2){
		For(j,0,8){
			dp2[i][j]=-10000000000000000LL;
		}
	}
	For(i,0,e[u].size()){
		For(j,0,8){
			dp2[i%2][j]=-10000000000000000LL;
		}
		dp2[i%2][0]=0;
		For(j,0,8){
			For(k,0,8){
				if(j==0){
					dp2[i%2][1]=max(dp[e[u][i]][1],dp2[((i-1)%2+2)%2][1]);
					dp2[i%2][2]=max(dp[e[u][i]][0],dp2[((i-1)%2+2)%2][2]);
					dp2[i%2][4]=max(dp[e[u][i]][0],dp2[((i-1)%2+2)%2][4]);
				}
				else if(j==1){
					dp2[i%2][3]=max(dp2[i%2][3],max(max(dp2[((i-1)%2+2)%2][1],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][3]));
					dp2[i%2][5]=max(dp2[i%2][5],max(max(dp2[((i-1)%2+2)%2][1],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][5]));
				}
				else if(j==2){
					dp2[i%2][3]=max(dp2[i%2][3],max(max(dp2[((i-1)%2+2)%2][2],0LL)+dp[e[u][i]][1],dp2[((i-1)%2+2)%2][3]));
					dp2[i%2][6]=max(dp2[i%2][6],max(max(dp2[((i-1)%2+2)%2][2],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][6]));
				}
				else if(j==3){
					dp2[i%2][7]=max(dp2[i%2][7],max(max(dp2[((i-1)%2+2)%2][3],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][7]));
				}
				else if(j==4){
					dp2[i%2][5]=max(dp2[i%2][5],max(max(dp2[((i-1)%2+2)%2][4],0LL)+dp[e[u][i]][1],dp2[((i-1)%2+2)%2][5]));
					dp2[i%2][6]=max(dp2[i%2][6],max(max(dp2[((i-1)%2+2)%2][4],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][6]));
				}
				else if(j==5){
					dp2[i%2][7]=max(dp2[i%2][7],max(max(dp2[((i-1)%2+2)%2][5],0LL)+dp[e[u][i]][0],dp2[((i-1)%2+2)%2][7]));
				}
				else if(j==6){
					dp2[i%2][7]=max(dp2[i%2][7],max(max(dp2[((i-1)%2+2)%2][6],0LL)+dp[e[u][i]][1],dp2[((i-1)%2+2)%2][7]));
				}
			}
		}
	}
	For(j,0,8){
		answer1=max(answer1,dp2[(e[u].size()-1)%2][j]+a[u]);
	}


	rep(t1,temp2){
		if(s1.find(t1.y)==s1.end()){
			if(t1.x.y==0){
				if(count1<2){
					count1++;
					s1.insert(t1.y);
					tempa+=t1.x.x;
				}
			}
			else if(t1.x.y==1){
				if(count2<1){
					count2++;
					s1.insert(t1.y);
					tempa+=t1.x.x;
				}
			}
		}
	}
	if(count1==2 && count2==1){
		answer1=max(answer1,tempa+a[u]);
	}
	

}

int main(){
	int n;
	scanf("%d",&n);
	vector<pii> v1;

	For(i,1,n+1){
		int temp;
		scanf("%d",&temp);
		a[i]=temp;
		v1.pb(mp(temp,i));
	}

	sort(all(v1));
	

	

	

	


	For(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		Adj[a].pb(b);
		Adj[b].pb(a);
	}

	DFS(1,0);

	For(i,1,n+1){
		

		For(j,0,3){
			

			answer1=max(answer1,dp[i][j]);
		}
		

	}

	printf("%lld\n",answer1);
return 0;}




