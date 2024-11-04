









int h, w, t;
double pix[N][N];
double tmp[N][N];	

struct Graph
{
	

	int id9;
	

	double dis[maxVex][maxVex];
	
	

	void reset() 
	{
		
		for (int i=1;i<=id9;i++)
			for (int j=1;j<=id9;j++)
				dis[i][j] = 0;
		id9 = 0;
		
		return ;	
	}
}G, idGraph;

struct TSPsolution
{
	

	int id9;
	

	double len;
	

	int path[maxVex];
	
	

	void reset() 
	{
		
		for (int i=1;i<=id9;i++)
			path[i] = 0;
		len = 0;
		id9 = 0;
		
		return ;	
	} 
}id6;



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


	

	ret.id9 = t;
	for (int i=0;i<t;i++)
	{
		for (int j=0;j<t;j++)
		{
			double sum = 0;
			int div = 10;
			for (int k=0;k<w/div;k++) {
				double s1 = 0, s2 = 0;
				for (int u = k * div+1; u <= (k + 1)*div; u++)
				{
					int x = (i + 1) * (h / t);
					int y = j * (h / t) + 1;
					s1 += tmp[x][u];
					s2 += tmp[y][u];
				}
				sum += abs(s1 - s2);
			}
			ret.dis[i][j] = sum;
		}

	}
	




	

	return ret;
}


double id7(TSPsolution &x, Graph &G) 
{
	double sum = 0;
	for (int i=1;i<x.id9;i++)
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


void id5(TSPsolution &x) {
	int n = x.id9;
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
	int a[20], tot = 0, n = x.id9;
	for (int i=l;i<=r;i++) a[++tot] = x.path[i];
	
	for (int i=1;i<=n;i++)
		if (i>r)
			a[++tot] = x.path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l)
			a[++tot] = x.path[i];
			
	for (int i=1;i<=n;i++) x.path[i] = a[i];
} 

void id8(TSPsolution &x, int l, int r) {
	int a[20], tot = 0, n = x.id9;
	for (int i=l;i<=r;i++) a[++tot] = x.path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x.path[i];
	
	for (int i=1;i<=n;i++) x.path[i] = a[i];
} 

void id4(TSPsolution &x, int l, int r) {
	int a[20], tot = 0, n = x.id9;
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x.path[i];
			
	for (int i=l;i<=r;i++) a[++tot] = x.path[i];
			
	for (int i=1;i<=n;i++) x.path[i] = a[i];
} 


 
TSPsolution NewSolution(Graph &G, TSPsolution bestSol) 
{
	TSPsolution ret = id6;
	
	int i = rand() % G.id9 + 1;
	int j = rand() % G.id9 + 1;
	
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
	
	int cmd = rand() % 5;
	if (cmd == 0) 
	{
		id2(bestSol, i, j); 
		bestSol.len = id7(bestSol, G);
		


	}
	
	if (cmd == 1) 
	{
		

		if (j == G.id9)

		{
			ret = bestSol;
			return ret;
		}
		id1(bestSol, i, j);
		bestSol.len = id7(bestSol, G);
	}
	
	if (cmd == 2) 
	{
		id3(bestSol, i, j);
		bestSol.len = id7(bestSol, G);
	}
	
	if (cmd == 3) 
	{
		if (i == 1) 
		{
			ret = bestSol;
			return ret;
		}
		id8(bestSol, i, j);
		bestSol.len = id7(bestSol, G);
	}
	
	if (cmd == 4) 
	{
		if (i == 1)
		{
			ret = bestSol;
			return ret;
		}
		id4(bestSol, i, j);
		bestSol.len = id7(bestSol, G);
	}
	
	ret = bestSol;
	return ret;
}


TSPsolution RandomSolution(int n, Graph &G) {
	int a[20], b[20];
	TSPsolution ret = id6;
	for (int i=1;i<=n;i++) a[i] = i;
	for (int i=1;i<=n;i++) b[i] = rand();
	
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (b[ a[i] ] > b[ a[j] ])
			{
				int tmp;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
	
	ret.id9 = n;
	
	for (int i=1;i<=n;i++)
		ret.path[i] = a[i] - 1;
	
	ret.len = id7(ret, G);
	
	return ret;	
}

 
TSPsolution id0(Graph G) 
{
	const double speed = 0.998;

	const double initTem = 1e9;

	const double minTem = 0.000001;

	const int T = 1;


	
	int n = G.id9;
	TSPsolution bestSol = id6;

	TSPsolution curSol = id6;


	bestSol = RandomSolution(n, G);
	
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
	
	for (int i=1;i<=ans.id9;i++)
		res[ ans.path[i]+1 ] = i;
	
	for (int i=1;i<=ans.id9;i++)
		printf("%d%c", res[i], i==ans.id9 ? '\n' : ' ');
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