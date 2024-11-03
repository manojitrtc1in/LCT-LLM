































		




		





















using namespace std;




int max_like,min_diff;
map<string,int> name;
int num[3];
int man[10];
int like[10][10];
int score[3];
void init()
{
	name["Anka"]=0;
	name["Chapay"]=1;
	name["Cleo"]=2;
	name["Troll"]=3;
	name["Dracul"]=4;
	name["Snowy"]=5;
	name["Hexadecimal"]=6;	
}
void dfs(int cur)
{
	int i,j;	
	if(cur==7)
	{
		int min_d=0,max_l=0;
		

		memset(num,0,sizeof(num));
		for(i=0;i<7;i++)
			num[man[i]]++;
		for(i=0;i<3;i++)
			if(num[i]==0)return ;
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
				{
					if(i==j)continue;
					int a=int(score[i]/num[i]);
					int b=int(score[j]/num[j]);
					if(abs(a-b) > min_d)
						min_d=abs(a-b);
				}
				for(i=0;i<7;i++)
					for(j=0;j<7;j++)
						if(like[i][j] && man[i]==man[j])
							max_l++;
				if(min_d < min_diff )
				{
					min_diff=min_d;
					max_like=max_l;
				}
				else
				if(min_d==min_diff && max_l>max_like)
				{
						max_like=max_l;
				}
					return ;
	}
	for(i=0;i<3;i++)
	{
		man[cur]=i;
		dfs(cur+1);
	}
}
int main()
{
	

	string s1,s2,likes;
	int n;
	init();
	while(cin>>n)
	{
		memset(like,0,sizeof(like));
		min_diff=INF,max_like=0;
		while(n--)
		{
			cin>>s1>>likes>>s2;
			like[name[s1]][name[s2]]=1;
						
		}
		cin>>score[0]>>score[1]>>score[2];
			dfs(0);
			cout<<min_diff<<" "<<max_like<<endl;
	}
	return 0;
}

