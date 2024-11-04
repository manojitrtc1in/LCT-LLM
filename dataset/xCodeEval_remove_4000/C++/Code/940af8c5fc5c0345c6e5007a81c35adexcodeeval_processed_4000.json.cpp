
















































































using namespace std;
const int Maxn=5005;
ll dist[Maxn][Maxn];
ll buff1[Maxn],buff2[Maxn],buff3[Maxn],buff4[Maxn],buff5[Maxn];
bool vis[Maxn][Maxn];
bool used[Maxn];
vector<int> Que;
int n,s,e;
void id4(){
	cerr<<"F@ck y@@ djq_cpp."<<endl;
	cerr<<"B@tch!"<<endl;
	cerr<<"QAQ .^.^."<<endl;
	cerr<<"MINIONSSSSSSSSSSS"<<endl;
}
void id0(int loc,int val,vector<int> &V){
	V.push_back(0);
	Rep(i,V.size()-2,loc+1){
		swap(V[i],V[i+1]);
	}
	V[loc+1]=val;
	return;
}
void id3(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (!(i==j)){
				dist[i][j]=abs(buff1[i]-buff1[j]);
				if (i>j){
					dist[i][j]+=buff4[i]+buff3[j];
				}
				else{
					dist[i][j]+=buff5[i]+buff2[j];
				}
			}
			

		}
		

	}
	return;
}
void id1(vector<int> ans){
	ll totdist=0;
	rep(i,ans.size()-1){
		totdist+=dist[ans[i]][ans[i+1]];
	}
	printf("%I64d\n",totdist);
	return;
}
void id2(ll &md,int &l,vi &Q,int loc,int val){
	ll ad=dist[Q[loc]][val]+dist[val][Q[loc+1]]-dist[Q[loc]][Q[loc+1]];
	

	if (ad<md){
		md=ad;
		l=loc;
	}
}
int main(){
	scanf("%d %d %d",&n,&s,&e);
	s--,e--;
	rep(i,n){
		scanf("%I64d",&buff1[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff2[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff3[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff4[i]);
	}
	rep(i,n){
		scanf("%I64d",&buff5[i]);
	}
	id3();
	Que.clear();
	Que.pb(s);
	Que.pb(e);
	rep(bufff,n){
		if (bufff==s || bufff==e) continue;
		ll md=1e18;
		int id5;
		rep(i,Que.size()-1){
			id2(md,id5,Que,i,bufff);
		}
		id0(id5,bufff,Que);
		
	}
	id1(Que);
	return 0;
}
