

char Map[1005][1005],New[1005][1005];
bool f[1005][1005],g[1005][1005];
bool F[1005][1005],G[1005][1005];
int p[5];
int i,j,I,J,N,M,Num,s1,s2;
struct node
{
	int x,y;
}Q[10];
int A[10];
bool Right()
{
	int i;
	if(Q[A[1]].x>Q[A[2]].x-2) return 0;
	if(Q[A[1]].y>Q[A[2]].y-2) return 0;
	for(i=Q[A[1]].x;i<=Q[A[2]].x;++i)
	{
		if(Map[i][Q[A[1]].y]!='
		if(Map[i][Q[A[2]].y]!='
	}
	for(i=Q[A[1]].y;i<=Q[A[2]].y;++i)
	{
		if(Map[Q[A[1]].x][i]!='
		if(Map[Q[A[2]].x][i]!='
	}
	return 1;
}
bool Check()
{
	int i,j;
	if(Q[A[1]].x>Q[A[2]].x-2) return 0;
	if(Q[A[1]].y>Q[A[2]].y-2) return 0;
	if(Q[A[3]].x>Q[A[4]].x-2) return 0;
	if(Q[A[3]].y>Q[A[4]].y-2) return 0;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			New[i][j]='.';
	for(i=Q[A[1]].x;i<=Q[A[2]].x;++i) New[i][Q[A[1]].y]=New[i][Q[A[2]].y]='
	for(i=Q[A[1]].y;i<=Q[A[2]].y;++i) New[Q[A[1]].x][i]=New[Q[A[2]].x][i]='
	for(i=Q[A[3]].x;i<=Q[A[4]].x;++i) New[i][Q[A[3]].y]=New[i][Q[A[4]].y]='
	for(i=Q[A[3]].y;i<=Q[A[4]].y;++i) New[Q[A[3]].x][i]=New[Q[A[4]].x][i]='
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(New[i][j]!=Map[i][j])
				return 0;
	printf("YES\n");
	printf("%d %d %d %d\n",Q[A[1]].x+1,Q[A[1]].y+1,Q[A[2]].x+1,Q[A[2]].y+1);
	printf("%d %d %d %d\n",Q[A[3]].x+1,Q[A[3]].y+1,Q[A[4]].x+1,Q[A[4]].y+1);
	return 1;
}
bool Ok(int x,int y)
{
	if(x!=0&&x!=N-1)
	{
		if(Map[x-1][y]!='
	}
	else return 1;
	if(y!=0&&y!=M-1)
	{
		if(Map[x][y-1]!='
	}
	else return 1;
	return 0;
}
bool Special()
{
	int i,j,s1=0,s2=0,s;
	s=0;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
				if(!Ok(i,j))
				{
					++s;
					Q[3].x=i,Q[3].y=Q[2].y;
					Q[4].x=Q[1].x,Q[4].y=j;
				}
	if(s==1)
	{
		A[1]=1,A[2]=3,A[3]=4,A[4]=2;
		if(Check()) return 1;
	}
	s=0;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
				if(!Ok(i,j))
				{
					++s;
					Q[3].x=Q[2].x,Q[3].y=j;
					Q[4].x=i,Q[4].y=Q[1].y;
				}
	if(s==1)
	{
		A[1]=1,A[2]=3,A[3]=4,A[4]=2;
		if(Check()) return 1;
	}
	Num=0;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(f[i][j])
			{
				++s1;
				if(s1>2) return 0;
				else Q[++Num].x=i,Q[Num].y=j;
			}
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(g[i][j])
			{
				++s2;
				if(s2>2) return 0;
				else Q[++Num].x=i,Q[Num].y=j;
			}
	if(s1==2&&s2==2)
	{
		A[1]=1,A[2]=3,A[3]=2,A[4]=4;
		if(Check()) return 1;
		A[1]=1,A[2]=4,A[3]=2,A[4]=3;
		if(Check()) return 1;
	}
	return 0;
}
bool Get(int x,int y,int p)
{
	if(p==1)
	{
		if(x+3>=N) return 0;
		return Map[x+3][y]=='
	}
	if(p==2)
	{
		if(y+3>=M) return 0;
		return Map[x][y+3]=='
	}
	if(p==3)
	{
		if(x-3<0) return 0;
		return Map[x-3][y]=='
	}
	if(p==4)
	{
		if(y-3<0) return 0;
		return Map[x][y-3]=='
	}
}
bool DoRD(int t1,int t2,int t3)
{
	int s=0;
	A[1]=t1,A[2]=t3;
	if(!Right()) return 0;
	if(Q[t1].x>Q[t2].x-2) return 0;
	if(Q[t1].y>Q[t2].y-2) return 0;
	Num=3;
	for(i=Q[t1].x+1;i<Q[t2].x&&i<Q[t3].x;++i)
		if(f[i][Q[t1].y]&&(Q[t3].y!=Q[t1].y+2||Get(i,Q[t1].y,2)))
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=i,Q[Num].y=Q[t1].y;
		}
	for(i=Q[t1].y+1;i<Q[t2].y&&i<Q[t3].y;++i)
		if(f[Q[t1].x][i]&&(Q[t3].x!=Q[t1].x+2||Get(Q[t1].x,i,1)))
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=Q[t1].x,Q[Num].y=i;
		}
	A[1]=t1,A[2]=t3,A[4]=t2;
	if(!s) A[3]=t1;
	else A[3]=4;
	if(Check()) return 1;
	A[3]=4;
	Q[4].x=Q[t3].x,Q[4].y=Q[t1].y;
	if(Check()) return 1;
	Q[4].x=Q[t1].x,Q[4].y=Q[t3].y;
	if(Check()) return 1;
	Num=3;
	for(i=Q[t1].x+1;i<Q[t2].x&&i<Q[t3].x;++i)
		if(f[i][Q[t3].y])
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=i,Q[Num].y=Q[t3].y;
		}
	for(i=Q[t1].y+1;i<Q[t2].y&&i<Q[t3].y;++i)
		if(f[Q[t3].x][i])
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=Q[t3].x,Q[Num].y=i;
		}
	A[1]=t1,A[2]=t3,A[4]=t2;
	if(!s) A[3]=t1;
	else A[3]=4;
	if(Check()) return 1;
	A[3]=4;
	Q[4].x=Q[t3].x,Q[4].y=Q[t1].y;
	if(Check()) return 1;
	Q[4].x=Q[t1].x,Q[4].y=Q[t3].y;
	if(Check()) return 1;
	return 0;
}
bool DoLU(int t1,int t2,int t3)
{
	int s=0;
	A[1]=t1,A[2]=t3;
	if(!Right()) return 0;
	if(Q[t2].x>Q[t3].x-2) return 0;
	if(Q[t2].y>Q[t3].y-2) return 0;
	Num=3;
	for(i=Q[t3].x-1;i>Q[t2].x&&i>Q[t1].x;--i)
		if(g[i][Q[t3].y]&&(Q[t3].y!=Q[t1].y+2||Get(i,Q[t1].y,4)))
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=i,Q[Num].y=Q[t3].y;
		}
	for(i=Q[t3].y-1;i>Q[t2].y&&i>Q[t1].y;--i)
		if(g[Q[t3].x][i]&&(Q[t3].x!=Q[t1].x+2||Get(i,Q[t1].y,3)))
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=Q[t3].x,Q[Num].y=i;
		}
	A[1]=t1,A[2]=t3,A[3]=t2;
	if(!s) A[4]=t3;
	else A[4]=4;
	if(Check()) return 1;
	A[4]=4;
	Q[4].x=Q[t1].x,Q[4].y=Q[t3].y;
	if(Check()) return 1;
	Q[4].x=Q[t3].x,Q[4].y=Q[t1].y;
	if(Check()) return 1;
	Num=3;
	for(i=Q[t3].x-1;i>Q[t2].x&&i>Q[t1].x;--i)
		if(g[i][Q[t1].y])
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=i,Q[Num].y=Q[t1].y;
		}
	for(i=Q[t3].y-1;i>Q[t2].y&&i>Q[t1].y;--i)
		if(g[Q[t1].x][i])
		{
			++s;
			if(s>1) return 0;
			else Q[++Num].x=Q[t1].x,Q[Num].y=i;
		}
	A[1]=t1,A[2]=t3,A[3]=t2;
	if(!s) A[4]=t3;
	else A[4]=4;
	if(Check()) return 1;
	A[4]=4;
	Q[4].x=Q[t1].x,Q[4].y=Q[t3].y;
	if(Check()) return 1;
	Q[4].x=Q[t3].x,Q[4].y=Q[t1].y;
	if(Check()) return 1;
	return 0;
}
bool Prepare(int t1,int t2)
{
	int i,s1=0,s2=0;
	A[1]=t1,A[2]=t2;
	if(!Right()) return 0;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			New[i][j]=Map[i][j];
	for(i=Q[t1].x;i<=Q[t2].x;++i)
	{
		if(Ok(i,Q[t1].y)) New[i][Q[t1].y]='.';
		if(Ok(i,Q[t2].y)) New[i][Q[t2].y]='.';
	}
	for(i=Q[t1].y;i<=Q[t2].y;++i)
	{
		if(Ok(Q[t1].x,i)) New[Q[t1].x][i]='.';
		if(Ok(Q[t2].x,i)) New[Q[t2].x][i]='.';
	}
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
				if(i+2<N&&j+2<M)
					if(New[i+1][j]=='
						Q[8].x=i,Q[8].y=j,++s1;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
				if(i-2>=0&&j-2>=0)
					if(New[i-1][j]=='
						Q[9].x=i,Q[9].y=j,++s2;
	if(s1!=1||s2!=1) return 0;
	A[1]=t1,A[2]=t2,A[3]=8,A[4]=9;
	return Check();
}
bool DoS()
{
	int i,s=0;
	for(i=Q[1].x+1;i<Q[2].x;++i)
		if(f[i][Q[1].y]||g[i][Q[2].y])
		{
			++s;
			if(s>1) return 0;
			else
			{
				Q[++Num].x=i,Q[Num].y=Q[1].y;
				Q[++Num].x=i,Q[Num].y=Q[2].y;
			}
		}
	for(i=Q[1].y+1;i<Q[2].y;++i)
		if(f[Q[1].x][i]||g[Q[2].x][i])
		{
			++s;
			if(s>1) return 0;
			else
			{
				Q[++Num].x=Q[1].x,Q[Num].y=i;
				Q[++Num].x=Q[2].x,Q[Num].y=i;
			}
		}
	A[1]=1,A[2]=2;
	if(!s) A[3]=1,A[4]=2;
	else A[3]=1,A[4]=4;
	if(Check()) return 1;
	if(!s) A[3]=1,A[4]=2;
	else A[3]=3,A[4]=2;
	if(Check()) return 1;
	return 0;
}
bool DoB()
{
	int i,s;
	Num=2;
	s=0;
	for(i=Q[1].x+1;i<Q[2].x;++i)
		if(f[i][Q[1].y]||g[i][Q[2].y])
		{
			++s;
			if(s>2) break;
			else
			{
				Q[++Num].x=i,Q[Num].y=Q[1].y;
				Q[++Num].x=i,Q[Num].y=Q[2].y;
			}
		}
	if(s==2)
	{
		A[1]=1,A[2]=6,A[3]=3,A[4]=2;
		if(Check()) return 1;
	}
	Num=2;
	s=0;
	for(i=Q[1].y+1;i<Q[2].y;++i)
		if(f[Q[1].x][i]||g[Q[2].x][i])
		{
			++s;
			if(s>2) break;
			else
			{
				Q[++Num].x=Q[1].x,Q[Num].y=i;
				Q[++Num].x=Q[2].x,Q[Num].y=i;
			}
		}
	if(s==2)
	{
		A[1]=1,A[2]=6,A[3]=3,A[4]=2;
		if(Check()) return 1;
	}
	Num-=s*2;
	return 0;
}
bool DoI()
{
	Q[3].x=Q[1].x+1,Q[3].y=Q[1].y+1;
	Q[4].x=Q[2].x-1,Q[4].y=Q[2].y-1;
	A[1]=1,A[2]=2,A[3]=3,A[4]=4;
	return Check();
}
int main()
{
	scanf("%d%d",&N,&M);
	for(i=0;i<N;++i) scanf("%s",Map[i]);
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
			{
				if(i+2<N&&j+2<M)
					f[i][j]=Map[i+1][j]=='
				if(i+2<N)
					F[i][j]|=Map[i+1][j]=='
				if(j+2<M)
					F[i][j]|=Map[i][j+1]=='
			}
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(Map[i][j]=='
			{
				if(i-2>=0&&j-2>=0)
					g[i][j]=Map[i-1][j]=='
				if(i-2>=0)
					G[i][j]|=Map[i-1][j]=='
				if(j-2>=0)
					G[i][j]|=Map[i][j-1]=='
			}
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(f[i][j]&&!G[i][j])
			{
				if(i>0&&f[i-1][j]&&!G[i-1][j]) continue;
				if(j>0&&f[i][j-1]&&!G[i][j-1]) continue;
				++s1;
				Q[++Num].x=i,Q[Num].y=j;
			}
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(!F[i][j]&&g[i][j])
			{
				if(i<N-1&&g[i+1][j]&&!F[i+1][j]) continue;
				if(j<M-1&&g[i][j+1]&&!F[i][j+1]) continue;
				++s2;
				Q[++Num].x=i,Q[Num].y=j;
			}
	if(s1>2||s2>2)
	{
		printf("NO\n");
		return 0;
	}
	if(s1==2&&s2==2)
	{
		for(i=0;i<2;++i) if(Q[A[2]].x+i<N)
			for(j=0;j<2;++j) if(Q[A[2]].y+j<M)
				for(I=0;J<2;++I) if(Q[A[3]].x-I>=0)
					for(J=0;J<2;++J) if(Q[A[3]].y-J>=0)
					{
						Q[A[2]].x+=i,Q[A[2]].y+=j;
						Q[A[3]].x+=I,Q[A[3]].y+=J;
						A[1]=1,A[2]=3,A[3]=2,A[4]=4;
						if(Check()) return 0;
						A[1]=1,A[2]=4,A[3]=2,A[4]=3;
						if(Check()) return 0;
						Q[A[2]].x-=i,Q[A[2]].y-=j;
						Q[A[3]].x-=I,Q[A[3]].y-=J;
					}
		printf("NO\n");
		return 0;
	}
	if(s1+s2==3)
	{
		if(Prepare(1,3)) return 0;
		if(s1==1&&s2==2)
			if(Prepare(1,2)) return 0;
		if(s1==2&&s2==1)
			if(Prepare(2,3)) return 0;
		if(s1==1&&s2==2)
		{
			if(DoRD(1,2,3)) return 0;
			if(DoRD(1,3,2)) return 0;
		}
		if(s1==2&&s2==1)
		{
			if(DoLU(1,2,3)) return 0;
			if(DoLU(2,1,3)) return 0;
		}
		Q[2]=Q[3];
		if(!DoB()) printf("NO\n");
		return 0;
	}
	if(s1+s2==2)
	{
		A[1]=1,A[2]=2;
		if(!Right())
		{
			if(!Special()) printf("NO\n");
			return 0;
		}
		if(!DoS()&&!DoB()&&!DoI()) printf("NO\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}
