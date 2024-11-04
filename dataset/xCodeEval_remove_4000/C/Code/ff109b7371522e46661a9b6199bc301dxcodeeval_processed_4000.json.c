

char maze[55][55];
char str[105];
int is,ie,js,je;
int len;
int m,n;
int check1()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check2()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check3()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check4()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check5()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check6()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='0') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check7()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check8()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check9()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check10()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check11()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check12()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='1') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check13()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check14()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check15()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check16()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check17()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}	
int check18()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='2') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='3') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check19()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check21()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check22()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check23()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check24()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int check20()
{
	int A=is;
	int B=js;
	int i;
	int flag=1;
	for(i=0;i<len;i++)
	{
		if(str[i]=='3') 

		{
			A++;
			if(A>n-1)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='2') 

		{
			B--;
			if(B<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='1') 

		{
			A--;
			if(A<0)
			{
				flag=1;
				break;
			}
		}
		if(str[i]=='0') 

		{
			B++;
			if(B>m-1)
			{
				flag=1;
				break;
			}
		}
		if(maze[A][B]=='
			{
				flag=1;
				break;
			}
		if(maze[A][B]=='E')
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&maze[i][j]);
			if(maze[i][j]=='S')
			{
				is=i;
				js=j;
			}
			if(maze[i][j]=='E')
			{
				ie=i;
				je=i;
			}
		}
	}
	scanf("%s",str);
	len=strlen(str);


	int ans=check1()+check2()+check3()+check4()+check5()+check6()+check7()+check8()+check9()+check10()+check11()+check12()+check13()+check14()+check15()+check16()+check17()+check18()+check19()+check20()+check21()+check22()+check23()+check24();
	printf("%d\n",ans );
	return 0;
}