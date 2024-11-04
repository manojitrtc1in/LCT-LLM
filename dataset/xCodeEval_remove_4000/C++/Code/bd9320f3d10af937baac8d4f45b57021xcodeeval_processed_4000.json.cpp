



using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;


























































const int N = int(2e5)+1;

const int INF = 2*int(1e9);
VI graph[N];
VI tree[N];
int n,m,q;
int visited[N];
int U[N],V[N],W[N];
int arrTime[N];
int Time=0;
stack<int> S;
int numComp;
bool isArtic[N];
int compNo[N];	

		

		

		

set<int> compNodes[N];	

multiset<int> CompWeight[N];	







void showStack()
{
	stack<int> temp;
	while(!S.empty())
	{
		temp.push(S.top());
		S.pop();
	}
	while(!temp.empty())
	{
		cout<<temp.top()+1<<(temp.size()==1?"\n":"-->");
		S.push(temp.top());
		temp.pop();
	}
}

void showGraph(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : ";
		for(int j=0;j<SZ(graph[i]);j++)
			cout<<(U[graph[i][j]]==i?V[graph[i][j]]+1:U[graph[i][j]]+1)<<" ";
		cout<<endl;

	}
}

void showTree()
{

	for(int i=0;i<numComp;i++)
	{
		cout<<i+1<<" : ";
		for(int j=0;j<SZ(tree[i]);j++)
			cout<<1+tree[i][j]<<" ";
		cout<<endl;

	}
}


int dfs(int u,int p)
{
	arrTime[u] = Time++;
	visited[u]=1;
	int dbe=arrTime[u];
	int dfsChild=0;

	for(int i=0;i<SZ(graph[u]);i++)
	{
		int e = graph[u][i];
		int w  = (U[e]==u?V[e]:U[e]);
		if(!visited[w])
		{
			S.push(e);
			dfsChild++;
			int wbe = dfs(w,u);	

			dbe = min(dbe , wbe);

			if((arrTime[u]==0 && dfsChild>1) || (wbe >= arrTime[u] && arrTime[u]>0))
			{
				

				isArtic[u]=true;
				if(compNo[u]==-1)
				{
					compNo[u]=numComp;
					compNodes[numComp].insert(u);
					numComp++;
				}
				

				while(S.top()!=e)
				{
					compNodes[numComp].insert(U[S.top()]);
					compNodes[numComp].insert(V[S.top()]);
					S.pop();
				}
				compNodes[numComp].insert(U[S.top()]);
				compNodes[numComp].insert(V[S.top()]);

				S.pop();

				for(set<int>::iterator it=compNodes[numComp].begin();it!=compNodes[numComp].end();it++)
					if(isArtic[*it])
					{
						tree[numComp].PB(compNo[*it]);
						tree[compNo[*it]].PB(numComp);
					}
					else
						compNo[*it]=numComp;
				numComp++;
			}

		}
		
		else if(w!=p && arrTime[w]<dbe ) 
		{
			dbe = min(dbe,arrTime[w]);
			S.push(e);
		}

	}
	return dbe;
}

void buildTree()
{
	SET(compNo,-1);
	dfs(0,0);
	if(!S.empty())
	{
		

		while(!S.empty())
		{
			compNodes[numComp].insert(U[S.top()]);
			compNodes[numComp].insert(V[S.top()]);
			S.pop();
		}
		


		for(set<int>::iterator it = compNodes[numComp].begin();it!=compNodes[numComp].end();it++)
			if(isArtic[*it])
			{
				tree[numComp].PB(compNo[*it]);
				tree[compNo[*it]].PB(numComp);
			}
			else
				compNo[*it]=numComp;

		numComp++;
	}
}






const int LOGN = 18;
int stCount[N];
int level[N];
int DP[N][LOGN];

int baseArray[N];	

int chainHead[N];	

int chainParent[N];	

int posInBaseArray[N];	

int chainNum[N];	

int len;		

int root;
int ST[6*N];	



void id5()
{
	cout<<"Base array is  :  ";
	for(int i=0;i<len;i++)
		printf("(%d , %d)",i,baseArray[i]);
	cout<<endl;
}

void id6()
{
	for(int i=0;i<numComp;i++)
		trace2(i+1,posInBaseArray[i]);
}

void id2()
{
	for(int i=0;i<numComp;i++)
		trace2(i+1,chainNum[i]);
}

void id7()
{
	trace1(numComp);
	for(int i=0;i<numComp;i++)
	{
		cout<<"Nodes in Component "<<i+1<<" : ";
		for(set<int>::iterator it = compNodes[i].begin();it!=compNodes[i].end();it++)
			cout<<*it+1<<" ";
		cout<<endl;
	}
}
bool id3(int u)
{
	return SZ(compNodes[u])==1 && isArtic[*compNodes[u].begin()];
}

void dfs2(int u)
{
	visited[u]=1;
	stCount[u]=1;
	
	if(id3(u))	

	{
		CompWeight[u].insert(W[*compNodes[u].begin()]);
	}
	else 		

	{
		for(set<int>::iterator it = compNodes[u].begin();it!=compNodes[u].end();it++)
			if(!(isArtic[*it] && compNo[*it] == DP[u][0]))	

				CompWeight[u].insert(W[*it]);	

		
		

		

		

		

		

		


	}
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w])
		{	
			level[w]=level[u]+1;
			DP[w][0]=u;
			dfs2(w);
			stCount[u]+=stCount[w];
		}

	}

}




void id1(int node=1,int l=0,int r=len)
{
	if(l==r-1)
	{
		ST[node]=baseArray[l];
		return ;
	}
	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;


	id1(leftChild,l,mid);
	id1(rightChild,mid,r);

	ST[node] = min(ST[leftChild],ST[rightChild]);
}




void id4(int pos,int val,int node=1,int l=0,int r=len)
{
	if(l>pos || r<=pos) 
		return;
	if(l == pos && l == r-1)
	{
		ST[node]=val;
		baseArray[l]=val;
		return;
	}

	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;

	id4(pos,val,leftChild,l,mid);
	id4(pos,val,rightChild,mid,r);

	ST[node] = min(ST[leftChild],ST[rightChild]);
}








int id0(int L,int R,int node=1,int l=0,int r=len)
{
	if(l>=R || r<=L)
		return INF;
	if(l >= L &&  r<=R)
	{
		return ST[node];
	}

	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;

	int leftAns = id0(L,R,leftChild,l,mid);
	int rightAns = id0(L,R,rightChild,mid,r);

	return min(leftAns,rightAns);

}




int query_up(int u,int p)
{
	int ans = *CompWeight[u].begin();

	while(chainNum[u]!=chainNum[p])
	{

		ans = min(ans,id0(posInBaseArray[chainHead[chainNum[u]]],posInBaseArray[u]+1));

		

		u = chainParent[chainNum[u]];
	}
	

	

	ans = min(ans,id0(posInBaseArray[p],posInBaseArray[u]+1));	
	return ans;

}




int chainNo;
void HLD(int u)
{

	visited[u]=1;	

	posInBaseArray[u]=len;
	baseArray[len++]= *CompWeight[u].begin();
	chainNum[u]=chainNo;

	int sc=-1;
	

	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w])
		{
			if(sc==-1)
				sc = w;
			else if(stCount[sc]<stCount[w])
				sc = w;
		}
	}

	

	if(sc!=-1)
		HLD(sc);

	

	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w])
		{
			chainNo++;
			chainHead[chainNo]=w;
			chainParent[chainNo]=u;
			HLD(w);
		}
	}
}

int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);


	int d = level[b]-level[a];
	for(int i=0;(1<<i)<=d;i++)
		if(d & (1<<i))
			b = DP[b][i];

	if(a == b)
		return a;

	int msb=0;
	for(int i=0;i<LOGN;i++)
		if(DP[a][i]!=DP[b][i])
			msb = i;
		else
			break;

	for(int i=msb;i>=0;i--)
		if(DP[a][i]!=DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}

	return DP[a][0];
}



void processTree()
{
	

	root=0;
	level[root]=0;
	DP[root][0]=0;
	SET(visited,0);
	dfs2(root);
	
	

	len=0;
	chainNo=0;
	SET(visited,0);
	SET(chainHead,-1);
	chainHead[0]=0;
	chainParent[0]=-1;
	HLD(0);

	

	id1();

	

	for(int i=1;i<LOGN;i++)
		for(int j=0;j<numComp;j++)
			DP[j][i] = DP[DP[j][i-1]][i-1];

}





int travel(int a,int b)
{
	if(a==b)
		return W[a];

	int A = compNo[a];
	int B = compNo[b];

	int LCA = lca(A,B);
	

	

	

	if(!id3(LCA))	

		return min(min(query_up(A,LCA),query_up(B,LCA)),*CompWeight[DP[LCA][0]].begin());
	else				

		return min(query_up(A,LCA),query_up(B,LCA));
}


void update(int x,int w)	

{

	if(isArtic[x])
	{
		int node = compNo[x];
		

		

		CompWeight[node].erase(CompWeight[node].find(W[x]));
		CompWeight[node].insert(w);
		id4(posInBaseArray[node],*CompWeight[node].begin());
		

		if(node!=root)
		{
			CompWeight[DP[node][0]].erase(CompWeight[DP[node][0]].find(W[x]));
			CompWeight[DP[node][0]].insert(w);
			id4(posInBaseArray[DP[node][0]],*CompWeight[DP[node][0]].begin());
		}
	}
	else
	{
		int node = compNo[x];
		CompWeight[node].erase(CompWeight[node].find(W[x]));
		CompWeight[node].insert(w);
		id4(posInBaseArray[node],*CompWeight[node].begin());
	}	
	W[x]=w;
}

int main()
{
	ios::sync_with_stdio(true);

	si(n);si(m);si(q);
	for(int i=0;i<n;i++)
		si(W[i]);

	for(int i=0;i<m;i++)
	{
		int u,v;
		si(u);si(v);
		U[i]=u-1;V[i]=v-1;
		graph[u-1].PB(i);
		graph[v-1].PB(i);
	}

	buildTree();
	

	

	

	processTree();
	

	

	

	

	

	for(int i=0;i<q;i++)
	{
		

		

		

		

		char c;
		int a,b;
		cin>>c>>a>>b;
		if(c=='A')
			dout(travel(a-1,b-1));
		else
			update(a-1,b);
	}

	return 0;
}
