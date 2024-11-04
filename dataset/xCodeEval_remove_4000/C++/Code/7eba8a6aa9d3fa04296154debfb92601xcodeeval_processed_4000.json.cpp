
using namespace std;


int n;
string cmd[35];
int num[35];

string id0(int x){
	string ans="eax";
	ans[1]+=x;
	return ans;
}

bool dfs(int maxx,int now){
	if(now==maxx){
		if(num[now]!=n){
			return 0;
		}
		cout<<maxx<<'\n';
		for(int i=0;i<maxx;i++){
			cout<<cmd[i]<<'\n';
		}
		return 1;
	}
	for(int i=0;i<=now;i++){
		for(int j=1;j<=8;j<<=1){
			num[now+1]=num[i]*j;
			if(num[now+1]>n){
				continue;
			}
			if(now+1==maxx&&num[now+1]!=n){
				continue;
			}
			cmd[now]="lea "+id0(now+1)+", ["+char('0'+j)+"*"+id0(i)+"]";
			if(dfs(maxx,now+1)){
				return 1;
			}
		}
	}
	for(int i=0;i<=now;i++){
		for(int ii=0;ii<=now;ii++){
			for(int j=1;j<=8;j<<=1){
				num[now+1]=num[ii]+num[i]*j;
				if(num[now+1]>n){
					continue;
				}
				if(now+1==maxx&&num[now+1]!=n){
					continue;
				}
				cmd[now]="lea "+id0(now+1)+", ["+id0(ii)+" + "+char('0'+j)+"*"+id0(i)+"]";
				if(dfs(maxx,now+1)){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		puts("0");
		return 0;
	}
	num[0]=1;
	for(int i=1;i<30;i++){
		if(dfs(i,0)){
			return 0;
		}
	}
	return 0;
}