









int h, w, t;
double pix[N][N];
double tmp[N][N];	

struct Graph
{
	

	int vexNum;
	

	double dis[id6][id6];
};
struct Graph G, idGraph;

struct TSPsolution
{
	

	int vexNum;
	

	double len;
	

	int path[id6];
};
struct TSPsolution id7;



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


struct Graph CreateGraph() 
{
	struct Graph ret = idGraph;

	

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


	

	ret.vexNum = t;
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


double id8(struct TSPsolution *x, struct Graph *G) 
{
	double sum = 0;
	int n = x->vexNum; 
	for (int i=1;i<n;i++)
	{
		int u = x->path[i];
		int v = x->path[i+1];
		sum += G->dis[u][v];
	}
	return sum;
}



void id2(struct TSPsolution *x, int i, int j) 
{
	int t;
	t = x->path[i];
	x->path[i] = x->path[j];
	x->path[j] = t;
	return ;
}


void id5(struct TSPsolution *x) {
	int n = x->vexNum;
	for (int i=1;i<=n/2;i++) 
	{
		int t;
		t = x->path[i];
		x->path[i] = x->path[n-i+1];
		x->path[n-i+1] = t;
	}
	return ;
}


void id1(struct TSPsolution *x, int l, int r) 
{
	if (l > r)
	{
		int t;
		t = l;
		l = r;
		r = t;	
	}
	
	int tmp = x->path[r];
	for (int i=r;i>l;i--)
		x->path[i] = x->path[i-1];
	x->path[l] = tmp;
	return ;
}


void id3(struct TSPsolution *x, int l, int r) {
	int a[20], tot = 0, n = x->vexNum;
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i>r)
			a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l)
			a[++tot] = x->path[i];
			
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 

void id9(struct TSPsolution *x, int l, int r) {
	int a[20], tot = 0, n = x->vexNum;
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x->path[i];
	
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 

void id4(struct TSPsolution *x, int l, int r) {
	int a[20], tot = 0, n = x->vexNum;
	
	for (int i=1;i<=n;i++)
		if (i<l || i > r)
			a[++tot] = x->path[i];
			
	for (int i=l;i<=r;i++) a[++tot] = x->path[i];
			
	for (int i=1;i<=n;i++) x->path[i] = a[i];
} 


 
struct TSPsolution NewSolution(struct Graph *G, struct TSPsolution bestSol) 
{
	struct TSPsolution ret = id7;
	
	int i = rand() % G->vexNum + 1;
	int j = rand() % G->vexNum + 1;
	
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
		id2(&bestSol, i, j); 
		bestSol.len = id8(&bestSol, G);
		


	}
	
	if (cmd == 1) 
	{
		

		if (j == G->vexNum)

		{
			ret = bestSol;
			return ret;
		}
		id1(&bestSol, i, j);
		bestSol.len = id8(&bestSol, G);
	}
	
	if (cmd == 2) 
	{
		id3(&bestSol, i, j);
		bestSol.len = id8(&bestSol, G);
	}
	
	if (cmd == 3) 
	{
		if (i == 1) 
		{
			ret = bestSol;
			return ret;
		}
		id9(&bestSol, i, j);
		bestSol.len = id8(&bestSol, G);
	}
	
	if (cmd == 4) 
	{
		if (i == 1)
		{
			ret = bestSol;
			return ret;
		}
		id4(&bestSol, i, j);
		bestSol.len = id8(&bestSol, G);
	}
	
	ret = bestSol;
	return ret;
}


struct TSPsolution RandomSolution(int n, struct Graph G) {
	int a[20], b[20];
	struct TSPsolution ret = id7;
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
	
	ret.vexNum = n;
	
	for (int i=1;i<=n;i++)
		ret.path[i] = a[i] - 1;
	
	ret.len = id8(&ret, &G);
	
	return ret;	
}

 
struct TSPsolution id0(struct Graph G) 
{
	const double speed = 0.998;

	const double initTem = 1e9;

	const double minTem = 0.000001;

	const int T = 1;


	
	int n = G.vexNum;
	struct TSPsolution bestSol = id7;

	struct TSPsolution curSol = id7;


	bestSol = RandomSolution(n, G);
	
	double curTem = initTem;
	int cnt = 0;	

		
	while (curTem > minTem) 
	{
		
		++cnt;
		

		for (int i=1;i<=T;i++)
		{
			curSol = NewSolution(&G, bestSol);

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

 
void print(struct TSPsolution ans) 
{
	
	int res[N];
	
	for (int i=1;i<=ans.vexNum;i++)
		res[ ans.path[i]+1 ] = i;
	
	for (int i=1;i<=ans.vexNum;i++)
		printf("%d%c", res[i], i==ans.vexNum ? '\n' : ' ');
	return ;
}


void solve() 
{
	struct Graph G;
	struct TSPsolution ans;

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