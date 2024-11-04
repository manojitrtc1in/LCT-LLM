

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









deque<int> dq[505];
int len=0;
ll sum[505][5];
inline void add(int x){
	for(int i=1;i<=len;++i){
		if(dq[i].size()<SQ||x<dq[i].back()){
			dq[i].insert(lower_bound(dq[i].begin(),dq[i].end(),x),x);
			if(dq[i].size()>SQ){
				x=dq[i].back();
				dq[i].pop_back();
			}else x=0;
			sum[i][0]=0;sum[i][1]=0;sum[i][2]=0;sum[i][3]=0;sum[i][4]=0;
			for(int j=0;j<dq[i].size();++j) sum[i][j%5]+=dq[i][j];
			for(int j=i+1;j<=len;++j){
				sum[j][4]+=x;
				dq[j].push_front(x);
				if(dq[j].size()>SQ){
					x=dq[j].back();
					dq[j].pop_back();
					sum[j][4]-=x;
				}else x=0;
				swap(sum[j][4],sum[j][0]);
				swap(sum[j][3],sum[j][4]);
				swap(sum[j][2],sum[j][3]);
				swap(sum[j][1],sum[j][2]);
			}
			break;
		}
		
	}
	if(x){
		++len;
		dq[len].push_front(x);
		sum[len][0]+=x;
	}
	
}
inline void del(int x){
	for(int i=1;i<=len;++i){
		if(x<=dq[i].back()){
			dq[i].erase(lower_bound(dq[i].begin(),dq[i].end(),x));
			if(i<len){
				x=dq[i+1].front();
				dq[i].push_back(x);
			}
			sum[i][0]=0;sum[i][1]=0;sum[i][2]=0;sum[i][3]=0;sum[i][4]=0;
			for(int j=0;j<dq[i].size();++j) sum[i][j%5]+=dq[i][j];
			for(int j=i+1;j<=len;++j){
				sum[j][0]-=x;
				dq[j].pop_front();
				if(j<len){
					x=dq[j+1].front();
					dq[j].push_back(x);
					sum[j][0]+=x;
				}
				swap(sum[j][0],sum[j][1]);
				swap(sum[j][1],sum[j][2]);
				swap(sum[j][2],sum[j][3]);
				swap(sum[j][3],sum[j][4]);
			}
			break;
		}
	}
	if(dq[len].empty()) --len;
	
}
int main(){
	char op[5];
	int n,x;
	ll ans=0;
	scanf("%d",&n);
	while(n--){
		scanf("%s",op);
		if(op[0]=='a'){
			scanf("%d",&x);
			add(x);
		}else if(op[0]=='d'){
			scanf("%d",&x);
			del(x);
		}else if(op[0]=='s'){
			ans=0;
			for(int i=1;i<=len;++i) ans+=sum[i][2];
			printf("%I64d\n",ans);
		}else assert(0);
	}
	return 0;
}