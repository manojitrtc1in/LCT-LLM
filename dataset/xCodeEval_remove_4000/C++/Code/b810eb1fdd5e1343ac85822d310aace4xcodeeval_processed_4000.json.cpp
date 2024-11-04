









int h, w, t;
double pix[N][N];
double tmp[N][N];	

struct Graph
{
	

	int id7;
	

	double dis[maxVex][maxVex];
	
	

	void reset() 
	{
		
		for (int i=1;i<=id7;i++)
			for (int j=1;j<=id7;j++)
				dis[i][j] = 0;
		id7 = 0;
		
		return ;	
	}
}G, idGraph;

struct TSPsolution
{
	

	int id7;
	

	double len;
	

	int path[maxVex];
	
	

	void reset() 
	{
		
		for (int i=1;i<=id7;i++)
			path[i] = 0;
		len = 0;
		id7 = 0;
		
		return ;	
	} 
}id5;



int max(int a, int b) 
{
	return a > b ? a : b;
}


int min(int a, int b)
{
	return a > b ? b : a;
}
 


void init() 
{
	memset(pix, 0, sizeof(pix));
	memset(tmp, 0, sizeof(tmp));
	scanf("%d%d%d", &h, &w, &t);
	
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++)
			scanf("%lf", &pix[i][j]);
	
	return ;
}


Graph CreateGraph() 
{
	Graph ret = idGraph;

	

	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++) 
		{
			

			int cnt = 0;
			

			int num = (i-1) / (h/t);
			
			

			int up = max(num*h/t+1, i-1);
			int down = min((num+1)*h/t, i+1);
			int left = max(1, j-1);
			int right = min(w, j+1);
	
			
			for (int p=up;p<=down;p++)
				for (int q=left;q<=right;q++)
				{
					tmp[i][j] += pix[p][q];
					++cnt;
				}
			tmp[i][j] /= cnt;
			
		}


	

	ret.id7 = t;
	for (int i=0;i<t;i++)
		for (int j=0;j<t;j++)
		{
			double cur = 0;
			int a = (i+1) * h / t;
			int b = j * h / t + 1;
			for (int k=1;k<=w;k++)
				cur += fabs(tmp[a][k] - tmp[b][k]);
			ret.dis[i][j] = cur;


		}
	




	

	return ret;
}



double id6(TSPsolution &x, Graph &G) 
{
	double sum = 0;
	for (int i=1;i<x.id7;i++)
	{
		int u = x.path[i];
		int v = x.path[i+1];
		sum += G.dis[u][v];
	}
	return sum;
}



void id2(TSPsolution &x, int i, int j) 
{
	int t;
	t = x.path[i];
	x.path[i] = x.path[j];
	x.path[j] = t;
	return ;
}


void id4(TSPsolution &x) {
	int n = x.id7;
	for (int i=1;i<=n/2;i++) 
	{
		int t;
		t = x.path[i];
		x.path[i] = x.path[n-i+1];
		x.path[n-i+1] = t;
	}
	return ;
}


void id1(TSPsolution &x, int l, int r) 
{
	if (l > r)
	{
		int t;
		t = l;
		l = r;
		r = t;	
	}
	
	int tmp = x.path[r];
	for (int i=r;i>l;i--) x.path[i] = x.path[i-1];
	x.path[l] = tmp;
	return ;
}

void id3(TSPsolution &x, int l, int r) {
	int a[20], tot = 0, n = x.id7;
	for (int i=l;i<=r;i++) a[++tot] = x.path[i];
	for (int i=1;i<=n;i++)
		if (i<l || i>r)
			a[++tot] = x.path[i];
	for (int i=1;i<=n;i++) x.path[i] = a[i];
} 

 
TSPsolution NewSolution(Graph &G, TSPsolution bestSol) 
{
	TSPsolution ret = id5;
	
	int i = rand() % G.id7 + 1;
	int j = rand() % G.id7 + 1;
	
	if (i > j) 
	{
		int t;
		t = i;
		i = j;
		j = t;
	}
	
	if (i == j) 
	{
		ret = bestSol;
		return ret;	
	}
	
	int cmd = rand() % 3;
	if (cmd == 0) 
	{
		id2(bestSol, i, j); 
		bestSol.len = id6(bestSol, G);
		


	}
	
	if (cmd == 1) 
	{
		

		if (j == G.id7)

		{
			ret = bestSol;
			return ret;
		}
		id1(bestSol, i, j);
		bestSol.len = id6(bestSol, G);
	}
	
	if (cmd == 2) {
		id3(bestSol, i, j);
		bestSol.len = id6(bestSol, G);
	}
	
	ret = bestSol;
	return ret;
}












 
TSPsolution id0(Graph G) 
{
	const double inf = 1e20;

	const double speed = 0.9998;

	const double initTem = 1e12;

	const double minTem = 0.000001;

	const int T = 1;


	
	int n = G.id7;
	TSPsolution bestSol = id5;

	TSPsolution curSol = id5;




	bestSol.len = inf;
	bestSol.id7 = n;
	for (int i=1;i<=n;i++)
		bestSol.path[i] = i-1;
	
	double curTem = initTem;
	int cnt = 0;	

		
	while (curTem > minTem) 
	{
		
		++cnt;
		

		for (int i=1;i<=T;i++)
		{
			curSol = NewSolution(G, bestSol);

			if (curSol.len <= bestSol.len) 
			{
				bestSol = curSol;	
			} 
			else
			{
				

				double diff = bestSol.len - curSol.len;
				int t1 = rand() % RAND_MAX;
				int t2 = RAND_MAX;
				double r = (double)t1 / (double)t2; 

				double x = exp(diff / curTem);				
				
				if (x > r)
				{
					bestSol = curSol;


				}

			}
		} 
		curTem = curTem * speed;

	} 
		


	return bestSol;
}

 
void print(TSPsolution ans) 
{
	
	int res[N];
	
	for (int i=1;i<=ans.id7;i++)
		res[ ans.path[i]+1 ] = i;
	
	for (int i=1;i<=ans.id7;i++)
		printf("%d%c", res[i], i==ans.id7 ? '\n' : ' ');
	return ;
}


void solve() 
{
	Graph G;
	TSPsolution ans;

	init();
	G = CreateGraph();
	ans = id0(G);
	print(ans);

	return ;
}


int main() 
{
	srand(time(0));
	
	int T = 0;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
		
	return 0;
}