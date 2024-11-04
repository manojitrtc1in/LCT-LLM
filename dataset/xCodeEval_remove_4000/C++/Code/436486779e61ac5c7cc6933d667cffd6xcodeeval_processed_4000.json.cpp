





























































































































































































using namespace std;
typedef pair<int,int> P;
struct does{
	int x,y,c;
};
int n,m;
int a[1002][1002];
int b[1002][1002];
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
queue<P>s;
stack<does>ss;
int op=0;
int judge_block(int x,int y){
	int t=0;
	for(int i=y;i<=y+1;i++){
		for(int j=x;j<=x+1;j++){
			if(a[i][j]==-1)continue;
			if(t==0){
				

				t=a[i][j];
			}
			else if(a[i][j]!=t){
				return 0;
			}
		}
	}
	return t;
}
void fill_c(int x,int y,int c){
	for(int i=y;i<=y+1;i++){
		for(int j=x;j<=x+1;j++){
			a[i][j]=c;
		}
	}
}

int bfs(){
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j+1]&&a[i][j]==a[i+1][j]){
				ss.push({j,i,a[i][j]});
				op++;
				a[i][j]=a[i][j+1]=a[i+1][j+1]=a[i+1][j]=-1;
				for(int k=0;k<8;k++){
					int y=i+dy[k],x=j+dx[k];
					

					if(x>m-1||x<1||y>n-1||y<1)continue;
					

					s.push({x,y});
					
				}
			}
		}
	}
	while(!s.empty()){
		
		P p=s.front();
		s.pop();
		

		int res=judge_block(p.first,p.second);
		if(res){
			op++;
			ss.push({p.first,p.second,res});
			fill_c(p.first,p.second,-1);
			for(int k=0;k<8;k++){
				int y=p.second+dy[k],x=p.first+dx[k];
				if(x>m-1||x<1||y>n-1||y<1)continue;
				s.push({x,y});
				
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=-1){
				return 0;
			}
		

		}
		

	}
	return 1;
} 
int main(){
	

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(bfs()){
		printf("%d\n",op);
		while(!ss.empty()){
			auto x=ss.top();
			ss.pop();
			printf("%d %d %d\n",x.y,x.x,x.c);
		}
	}
	else{
		printf("-1");
	}
	return 0;
}