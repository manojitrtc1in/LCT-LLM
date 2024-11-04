














using namespace std;



































li dp[MAX][bit(MAX-1)];
string base[200005];

li cost(string str0,string str1){
	for(li i=sz(str0);i;i--){
		if(str0.substr(sz(str0)-i,i)==str1.substr(0,i)) return sz(str0)-i;
	}
	return sz(str0);
}

li cost(li t0,li t1,li len){
	for(li i=len;i;i--){
		if((t0>>(len-i))==t1%bit(i)) return len-i;
	}
	return len;
}

li con(string str){
	li res=0;
	rep(i,sz(str))if(str[i]=='1') res|=bit(i);
	return res;
}

int main(){
	li n;
	cin>>n;
	rep(i,n) cin>>base[i];
	rep(i,MAX)rep(j,bit(MAX-1)) dp[i][j]=INF;
	dp[0][0]=0;
	li len=sz(base[0]);
	li all=len;
	rep(pos,n)if(pos){
		li num0=0,num1=0;
		rep(i,len)if(base[pos][i]=='1') num0|=bit(i);
		rep(i,len)if(base[pos-1][i]=='1') num1|=bit(i);
		li C=cost(num1,num0,len);
		all+=C;
		li best=INF;
		for(li i=0;i<=len;i++){
			best=min(best,dp[i][num0%bit(i)]+(len-i)-C);
		}
		for(li i=0;i<=len;i++){	
			dp[i][num1>>(len-i)]=min(dp[i][num1>>(len-i)],best);
		}
	}
	li res=all;
	rep(i,MAX)rep(j,bit(MAX-1)) res=min(res,all+dp[i][j]);
	cout<<res<<endl;
}
