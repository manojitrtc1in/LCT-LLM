
using namespace std;
const int A=3e5+10;


struct E{
	int u,v,w;
};
bool C(E a,E b){
	return a.w>b.w;
}
E e[A];
int n,m,D[A],K[A],I=1,M=0;
vector<int>B[A];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    F(int i=1;i<=m;i++){
    	cin>>e[i].u>>e[i].v>>e[i].w;
    	B[e[i].u].P(e[i].v);
    	B[e[i].v].P(e[i].u);
    }
    sort(e+1,e+m+1,C);
    F(int i=1;i<=m;i++){
    	D[i]=K[e[i].v]+1;
    	if(e[i+1].w!=e[i].w)
    		F(int j=I;j<=i;j++)
    			K[e[j].u]=max(K[e[j].u],D[j]),I=i+1;
    	M=max(M,D[i]);
    }
    cout<<M;
}

