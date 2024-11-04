
























































































































using namespace std;

const int INFI = (int)1e7;

int dfs(int s, int n, vector<int>*G, int *link, bool *vset)	

{
	int i= 0, t = 0;
	for (i=0; i<G[s].size(); i++)
	{
		t = G[s].at(i);							

		if (!vset[t-n])							

		{
			vset[t-n] = true;						

			if (link[t]==-1 || dfs(link[t],n,G,link,vset))	

			{
				link[t] = s;
				link[s] = t;
				return 1;
			}
		}
	}
	return 0;
}

int match(int n, int m, vector<int>*G, int *link, bool *vset)
{
	int result = 0, i = 0, j = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			vset[j] = false;
		}
		result += dfs(i,n,G,link,vset);			

	}
	return result;
}


int main()
{

	ifstream fin("data.txt");
	int n,i,capa,j,tmp;
	

	fin >> n;							

	vector<int> *G = new vector<int>[2*n];			

	for (i=0; i<2*n; i++)
	{
		G[i].clear();
	}
	vector<int> price;					

	vector<int> posPrice;				

	vector<int> negPrice;				

	for (i=0; i<n; i++)
	{
		fin >> capa;
		for (j=0; j<capa; j++)
		{
			fin >> tmp;
			tmp--;						

			G[i].push_back(tmp+n);
			G[n+tmp].push_back(i);
		}
	}
	int *link = new int[2*n];						

	for (i=0; i<2*n; i++)
	{
		link[i] = -1;								

	}
	bool *vset = new bool[n];						

	for (i=0; i<n; i++)
	{
		vset[i] = false;
	}
	

	int ans = match(n,n,G,link,vset);
	
	int setnum = 0;
	int TOT = 0;						

	for (i=0; i<n; i++)
	{
		fin >> tmp;
		if (tmp >= 0)
		{
			negPrice.push_back(i);		

		}
		else
		{
			posPrice.push_back(i);		

			TOT += -tmp;
		}
		price.push_back(-tmp);			

	}
	fin.close();
	

	int **mat = new int*[n+2];			

	for (i=0; i<n+2; i++)
	{
		mat[i] = new int[n+2]();		
	}
	for (i=0; i<n; i++)
	{
		vector<int> eleset = G[i];
		if (eleset.size()>1)
		{
			for (j=0; j<eleset.size(); j++)
			{
				if (i != link[eleset.at(j)])
				{
					mat[i][link[eleset.at(j)]] = INFI;	

				}
			}
		}
	}
	for (i=0; i<posPrice.size(); i++)
	{
		mat[n][posPrice.at(i)] = price.at((posPrice.at(i)));	

	}
	for (i=0; i<negPrice.size(); i++)
	{
		mat[negPrice.at(i)][n+1] = -price.at((negPrice.at(i)));	

	}
	delete[] G;
	

	int **flow = new int*[n+2];									

	for (i=0; i<n+2; i++)
	{
		flow[i] = new int[n+2]();								

	}
	int *pre = new int[n+2];									

	int *delta = new int[n+2]();								

	bool *posorneg = new bool[n+2]();							

	for (i=0; i<n+2; i++)
	{
		pre[i] = -2;											

	}
	int u = n;													

	bool id1 = false;									

	bool isend = false;											

	deque<int> id0;											

	int Delta = 0;												

	int w = 0;													

	while(1)
	{
		id0.clear();											

		id1 = false;
		isend = true;
		for (i=0; i<n+2; i++)
		{
			pre[i] = -2;
			delta[i] = 0;
		}

		u = n;													

		pre[n] = -1;											

		delta[n] = INFI;										

		for (i=0; i<n+2; i++)
		{
			if (mat[n][i] != 0 && pre[i] == -2 && flow[n][i]<mat[n][i])					
				

			{
				id1 = true;
				pre[i] = n;
				posorneg[i] = true;
				delta[i] = mat[n][i] - flow[n][i];
				id0.push_back(i);
			}
			if (mat[i][n] != 0 && pre[i] == -2 && flow[i][n] > 0)
				

			{
				id1 = true;
				pre[i] = n;
				posorneg[i] = false;
				delta[i] = flow[i][n];
				id0.push_back(i);
			}
		}
		if (!id1)										

		{
			break;												

		}
		while (!id0.empty())
		{
			u = id0.front();
			id0.pop_front();
			if (u == n+1)										

			{
				isend = false;									

				break;											

			}
			for (i=0; i<n+2; i++)
			{
				if (mat[u][i] != 0 && pre[i] == -2 && flow[u][i]<mat[u][i])					
					

				{
					id1 = true;
					pre[i] = u;
					posorneg[i] = true;
					delta[i] = min(mat[u][i] - flow[u][i],delta[u]);
					id0.push_back(i);
				}
				if (mat[i][u] != 0 && pre[i] == -2 && flow[i][u] > 0)
					

				{
					id1 = true;
					pre[i] = u;
					posorneg[i] = false;
					delta[i] = min(flow[i][u],delta[u]);
					id0.push_back(i);
				}
			}
		}
		if (isend)
		{
			break;
		}
		else
		{
			

			u = n+1;			

			Delta = delta[n+1];
			while(u!=n)
			{
				if (posorneg[u])
				{
					flow[pre[u]][u] += Delta;
				}
				else
				{
					flow[u][pre[u]] -= Delta;
				}
				u = pre[u];
			}
			w += Delta;
		}
	}
	cout << -(TOT - w);			


	delete[] link;
	delete[] vset;
	delete[] pre;
	delete[] delta;
	delete[] posorneg;
	for (i=0; i<n+2; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;


	int n,i,capa,j,tmp;
	

	cin >> n;							

	vector<int> *G = new vector<int>[2*n];			

	for (i=0; i<2*n; i++)
	{
		G[i].clear();
	}
	vector<int> price;					

	vector<int> posPrice;				

	vector<int> negPrice;				

	for (i=0; i<n; i++)
	{
		cin >> capa;
		for (j=0; j<capa; j++)
		{
			cin >> tmp;
			tmp--;						

			G[i].push_back(tmp+n);
			G[n+tmp].push_back(i);
		}
	}
	int *link = new int[2*n];						

	for (i=0; i<2*n; i++)
	{
		link[i] = -1;								

	}
	bool *vset = new bool[n];						

	for (i=0; i<n; i++)
	{
		vset[i] = false;
	}
	

	int ans = match(n,n,G,link,vset);
	
	int setnum = 0;
	int TOT = 0;						

	for (i=0; i<n; i++)
	{
		cin >> tmp;
		if (tmp >= 0)
		{
			negPrice.push_back(i);		

		}
		else
		{
			posPrice.push_back(i);		

			TOT += -tmp;
		}
		price.push_back(-tmp);			

	}
	

	int **mat = new int*[n+2];			

	for (i=0; i<n+2; i++)
	{
		mat[i] = new int[n+2]();		
	}
	for (i=0; i<n; i++)
	{
		vector<int> eleset = G[i];
		if (eleset.size()>1)
		{
			for (j=0; j<eleset.size(); j++)
			{
				if (i != link[eleset.at(j)])
				{
					mat[i][link[eleset.at(j)]] = INFI;	

				}
			}
		}
	}
	for (i=0; i<posPrice.size(); i++)
	{
		mat[n][posPrice.at(i)] = price.at((posPrice.at(i)));	

	}
	for (i=0; i<negPrice.size(); i++)
	{
		mat[negPrice.at(i)][n+1] = -price.at((negPrice.at(i)));	

	}
	delete[] G;
	

	int **flow = new int*[n+2];									

	for (i=0; i<n+2; i++)
	{
		flow[i] = new int[n+2]();								

	}
	int *pre = new int[n+2];									

	int *delta = new int[n+2]();								

	bool *posorneg = new bool[n+2]();							

	for (i=0; i<n+2; i++)
	{
		pre[i] = -2;											

	}
	int u = n;													

	bool id1 = false;									

	bool isend = false;											

	deque<int> id0;											

	int Delta = 0;												

	int w = 0;													

	while(1)
	{
		id0.clear();											

		id1 = false;
		isend = true;
		for (i=0; i<n+2; i++)
		{
			pre[i] = -2;
			delta[i] = 0;
		}

		u = n;													

		pre[n] = -1;											

		delta[n] = INFI;										

		for (i=0; i<n+2; i++)
		{
			if (mat[n][i] != 0 && pre[i] == -2 && flow[n][i]<mat[n][i])					
				

			{
				id1 = true;
				pre[i] = n;
				posorneg[i] = true;
				delta[i] = mat[n][i] - flow[n][i];
				id0.push_back(i);
			}
			if (mat[i][n] != 0 && pre[i] == -2 && flow[i][n] > 0)
				

			{
				id1 = true;
				pre[i] = n;
				posorneg[i] = false;
				delta[i] = flow[i][n];
				id0.push_back(i);
			}
		}
		if (!id1)										

		{
			break;												

		}
		while (!id0.empty())
		{
			u = id0.front();
			id0.pop_front();
			if (u == n+1)										

			{
				isend = false;									

				break;											

			}
			for (i=0; i<n+2; i++)
			{
				if (mat[u][i] != 0 && pre[i] == -2 && flow[u][i]<mat[u][i])					
					

				{
					id1 = true;
					pre[i] = u;
					posorneg[i] = true;
					delta[i] = min(mat[u][i] - flow[u][i],delta[u]);
					id0.push_back(i);
				}
				if (mat[i][u] != 0 && pre[i] == -2 && flow[i][u] > 0)
					

				{
					id1 = true;
					pre[i] = u;
					posorneg[i] = false;
					delta[i] = min(flow[i][u],delta[u]);
					id0.push_back(i);
				}
			}
		}
		if (isend)
		{
			break;
		}
		else
		{
			

			u = n+1;			

			Delta = delta[n+1];
			while(u!=n)
			{
				if (posorneg[u])
				{
					flow[pre[u]][u] += Delta;
				}
				else
				{
					flow[u][pre[u]] -= Delta;
				}
				u = pre[u];
			}
			w += Delta;
		}
	}
	cout << -(TOT - w);			


	delete[] link;
	delete[] vset;
	delete[] pre;
	delete[] delta;
	delete[] posorneg;
	for (i=0; i<n+2; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;

}
