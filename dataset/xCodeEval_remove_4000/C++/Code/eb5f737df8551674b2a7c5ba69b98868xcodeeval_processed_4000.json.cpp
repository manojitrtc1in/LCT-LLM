



FILE *in = stdin;
FILE *out = stdout;

std::vector<int> board[4000004];
int n,m;
char table[1004][1004];

int checkend(int a,int b)
{
	if (a == b || a == b + 1000000 || a == b + 2000000 || a == b + 3000000) return true;
	return false;
}
int check(int a, int b)
{
	if ((a + 3000000) % 4000000 == b)return true;
	int i;
	for (i = 0; i < board[a].size(); i++)
	{
		if (board[a][i] == b) return true;
	}
	return false;
}
struct _pairr
{
	int w, c;

};

int orm(_pairr a, _pairr b)
{
	if (a.c > b.c)return true;
	return false;
}

_pairr heap[4000004];
int hcount;
int sy, sx;
int ey, ex;

int visit[4000004];

void linkboard(int yy,int xx,int ty,int tx,int plus)
{
	if (0 <= ty&&ty < n&&0<=tx&&tx<m)
	{
		board[yy * 1000 + xx+plus].push_back(ty * 1000 + tx+plus);


	}
}

int main()
{
	int i, j, k;
	fscanf(in, "%d%d", &n,&m);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%s", table[i]);
		for (j = 0; j < m; j++)
		{
			board[i * 1000 + j].push_back(i * 1000 + j + 1000000);
			board[i * 1000 + j + 1000000].push_back(i * 1000 + j + 2000000);
			board[i * 1000 + j + 2000000].push_back(i * 1000 + j + 3000000);
			board[i * 1000 + j + 3000000].push_back(i * 1000 + j);

			if (table[i][j] == '+')
			{
				linkboard(i, j, i - 1, j, 0);
				linkboard(i, j, i, j - 1, 0);
				linkboard(i, j, i + 1, j, 0);
				linkboard(i, j, i, j + 1, 0);
				linkboard(i, j, i - 1, j, 1000000);
				linkboard(i, j, i, j - 1, 1000000);
				linkboard(i, j, i + 1, j, 1000000);
				linkboard(i, j, i, j + 1, 1000000);
				linkboard(i, j, i - 1, j, 2000000);
				linkboard(i, j, i, j - 1, 2000000);
				linkboard(i, j, i + 1, j, 2000000);
				linkboard(i, j, i, j + 1, 2000000);
				linkboard(i, j, i - 1, j, 3000000);
				linkboard(i, j, i, j - 1, 3000000);
				linkboard(i, j, i + 1, j, 3000000);
				linkboard(i, j, i, j + 1, 3000000);
			}
			else if (table[i][j] == '-')
			{
				linkboard(i, j, i + 1, j, 1000000);
				linkboard(i, j, i - 1, j, 1000000);
				linkboard(i, j, i, j + 1, 0);
				linkboard(i, j, i, j - 1, 0);
				linkboard(i, j, i + 1, j, 3000000);
				linkboard(i, j, i - 1, j, 3000000);
				linkboard(i, j, i, j + 1, 2000000);
				linkboard(i, j, i, j - 1, 2000000);
			}
			else if (table[i][j] == '|')
			{
				linkboard(i, j, i + 1, j, 0);
				linkboard(i, j, i - 1, j, 0);
				linkboard(i, j, i, j + 1, 1000000);
				linkboard(i, j, i, j - 1, 1000000);
				linkboard(i, j, i + 1, j, 2000000);
				linkboard(i, j, i - 1, j, 2000000);
				linkboard(i, j, i, j + 1, 3000000);
				linkboard(i, j, i, j - 1, 3000000);
			}
			else if (table[i][j] == '^')
			{
				linkboard(i, j, i - 1, j, 0);
				linkboard(i, j, i, j + 1, 1000000);
				linkboard(i, j, i + 1, j, 2000000);
				linkboard(i, j, i, j - 1, 3000000);
			}
			else if (table[i][j] == '>')
			{
				linkboard(i, j, i - 1, j, 3000000);
				linkboard(i, j, i, j + 1, 0);
				linkboard(i, j, i + 1, j, 1000000);
				linkboard(i, j, i, j - 1, 2000000);
			}
			else if (table[i][j] == '<')
			{
				linkboard(i, j, i - 1, j, 1000000);
				linkboard(i, j, i, j + 1, 2000000);
				linkboard(i, j, i + 1, j, 3000000);
				linkboard(i, j, i, j - 1, 0);
			}
			else if (table[i][j] == 'v')
			{
				linkboard(i, j, i - 1, j, 2000000);
				linkboard(i, j, i, j + 1, 3000000);
				linkboard(i, j, i + 1, j, 0);
				linkboard(i, j, i, j - 1, 1000000);
			}
			if (table[i][j] == 'L')
			{
				linkboard(i, j, i - 1, j, 0);


				linkboard(i, j, i + 1, j, 0);
				linkboard(i, j, i, j + 1, 0);
	

				linkboard(i, j, i, j - 1, 1000000);
				linkboard(i, j, i + 1, j, 1000000);
				linkboard(i, j, i, j + 1, 1000000);
				linkboard(i, j, i - 1, j, 2000000);
				linkboard(i, j, i, j - 1, 2000000);
				linkboard(i, j, i + 1, j, 2000000);


				linkboard(i, j, i - 1, j, 3000000);
				linkboard(i, j, i, j - 1, 3000000);
	

				linkboard(i, j, i, j + 1, 3000000);
			}
			if (table[i][j] == 'R')
			{
				linkboard(i, j, i - 1, j, 0);
				linkboard(i, j, i, j - 1, 0);
				linkboard(i, j, i + 1, j, 0);


				linkboard(i, j, i - 1, j, 1000000);
				linkboard(i, j, i, j - 1, 1000000);


				linkboard(i, j, i, j + 1, 1000000);
				linkboard(i, j, i - 1, j, 2000000);


				linkboard(i, j, i + 1, j, 2000000);
				linkboard(i, j, i, j + 1, 2000000);


				linkboard(i, j, i, j - 1, 3000000);
				linkboard(i, j, i + 1, j, 3000000);
				linkboard(i, j, i, j + 1, 3000000);
			}
			if (table[i][j] == 'U')
			{


				linkboard(i, j, i, j - 1, 0);
				linkboard(i, j, i + 1, j, 0);
				linkboard(i, j, i, j + 1, 0);
				linkboard(i, j, i - 1, j, 1000000);
				linkboard(i, j, i, j - 1, 1000000);
				linkboard(i, j, i + 1, j, 1000000);


				linkboard(i, j, i - 1, j, 2000000);
				linkboard(i, j, i, j - 1, 2000000);


				linkboard(i, j, i, j + 1, 2000000);
				linkboard(i, j, i - 1, j, 3000000);


				linkboard(i, j, i + 1, j, 3000000);
				linkboard(i, j, i, j + 1, 3000000);
			}
			if (table[i][j] == 'D')
			{
				linkboard(i, j, i - 1, j, 0);
				linkboard(i, j, i, j - 1, 0);


				linkboard(i, j, i, j + 1, 0);
				linkboard(i, j, i - 1, j, 1000000);


				linkboard(i, j, i + 1, j, 1000000);
				linkboard(i, j, i, j + 1, 1000000);


				linkboard(i, j, i, j - 1, 2000000);
				linkboard(i, j, i + 1, j, 2000000);
				linkboard(i, j, i, j + 1, 2000000);
				linkboard(i, j, i - 1, j, 3000000);
				linkboard(i, j, i, j - 1, 3000000);
				linkboard(i, j, i + 1, j, 3000000);


			}
		}
	}
	fscanf(in, "%d %d", &sy, &sx);
	sy--; sx--;
	fscanf(in, "%d %d", &ey, &ex);
	ey--; ex--;
	for (i = 0; i < 4000004; i++) visit[i] = 999999999;
	heap[0].w=1000*sy+sx; 

	visit[heap[0].w] = 0;
	hcount++;
	int end = 1000 * ey + ex;
	for (;;)
	{
		if (checkend(heap[0].w, end))
		{
			fprintf(out, "%d", heap[0].c); return 0;
		}
		if (hcount == 0)break;
		if(visit[heap[0].w]==heap[0].c)
		{
			for (i = 0; i < board[heap[0].w].size(); i++)
			{
				if (visit[board[heap[0].w][i]]>heap[0].c + 1)
				{
					if (check(board[heap[0].w][i],heap[0].w) == true)
					{
						if (hcount > 4000000) hcount--;
						visit[board[heap[0].w][i]] = heap[0].c + 1;
						heap[hcount].w = board[heap[0].w][i];
						heap[hcount++].c = heap[0].c + 1;
						std::push_heap(heap, heap + hcount, orm);
					}
				}
			}
		}
		std::pop_heap(heap, heap + hcount--, orm);
	}
	fprintf(out, "-1");
	return 0;
}


