















using namespace std;

typedef long long int num;
typedef num arr[444444];

inline void SHIT(num i)
{ printf("SHIT %I64d\n",i); exit(0); }

inline void err()
{ printf("0\n"); exit(0); }

inline num Abs(num a)
{ return a<0?-a:a; }

int jiancha;
num san,ans,n;
arr fir,sa,next,tar,rk,md;
arr f0,f1,f2,f3,g,h0,h1;
arr md0,md1,q,rd,fa;
arr sfir,srd,snext,star,sdis;

num id4=1500,id12=500;
void shuchar(char g)
{
	id4--;
	if (id4<0) putchar(g);
	if (id4+id12<=0) exit(0);
}

char st[1111];
void id1(num a)
{
	sprintf(st,"%I64d",a);
	int i;
	for (i=0;st[i]!='\0';i++)
	{	shuchar(st[i]); st[i]='\0';	}
}

void debugerr()
{
	num i;
	printf("%I64d\n",san);
	id1(rk[0]);
	shuchar(' ');
	for (i=1;i<=san;i++)
	{
		if (md[i]!=-1) id1(md[i]);
		else {
			id1(md0[i]);
			shuchar(',');
			id1(md1[i]); }
		shuchar(' ');
		id1(rk[i]);
		shuchar(' ');
	}
}

void id3()
{
	num i;
	printf("%I64d",san);
	for (i=0;i<=san;i++)
	{
		if (i%30==0)
			printf("\n");
		printf("%I64d ",rk[i]);
	}
	printf("\n");
	for (i=1;i<=san;i++)
	{
		if (i%30==1)
			printf("\n");
		if (md[i]!=-1) printf("%I64d ",md[i]);
		else printf("%I64d+%I64d ",md0[i],md1[i]);
	}
	printf("\n\n");
}

void id10(num b,num c)
{
	num F,G;
	F=(b-2?b-2:b);
	G=(c-2?c-2:c);
	printf("%I64d\n",(F*c+G*b+b*c)%mod);
	exit(0);
}

void id11(num a,num b,num c)
{
	num F,G;
	F=Abs(a-b);
	F+=(F==1);
	G=Abs(a-c);
	G+=(G==1);
	printf("%I64d\n",((F*c+G*b)*2)%mod);
	exit(0);
}

void San1()
{
	num a,b,c;
	a=fir[sa[0]];
	b=next[a];
	c=next[b];
	a=g[tar[a]];
	b=g[tar[b]];
	c=g[tar[c]];
	if (c&1) swap(b,c);
	if (c&1)
		if (jiancha) SHIT(1); else err();
	if (b&1) swap(a,b);
	
	if (a==1) id10(b,c);
	else id11(a,b,c);
}

num III()
{
	num F,G,a,b,c,d;
	a=rk[0]; b=md[1];
	c=rk[2]; d=md[2];
	num ret=0;
	if ((~a^c)&1)
	{
		F=Abs(a-c)/2;
		G=Abs(b-d)/2;
		ret+=(F+(F==0))*(G+(G==0));
	}
	if ((~a^d)&1)
	{
		F=Abs(a-d)/2;
		G=Abs(b-c)/2;
		ret+=(F+(F==0))*(G+(G==0));
	}
	return -ret;
}

inline void tuiff(num gg)
{
	if ((rk[gg]^md[gg+1])&1&&rk[gg]+1>=md[gg+1])
		add(f0[gg+1],f0[gg]+f2[gg]);
	if ((rk[gg]^md[gg+1])&1&&rk[gg]-1>=md[gg+1])
		add(f2[gg+1],f0[gg]+f2[gg]);
	
	if ((md[gg]^rk[gg])&1&&rk[gg]+1>=md[gg])
	{	add(f1[gg+1],f1[gg]);
		add(f3[gg+1],f1[gg]);	}
	if ((md[gg]^rk[gg])&1&&rk[gg]-1>=md[gg])
	{	add(f1[gg+1],f3[gg]);
		add(f3[gg+1],f3[gg]);	}
	
	if (~rk[gg]&1)
	{	add(f1[gg+1],f0[gg]+f2[gg]);
		add(f3[gg+1],f0[gg]+f2[gg]);	}
	
	if ((~md[gg]^rk[gg]^md[gg+1])&1&&rk[gg]+2>=md[gg]+md[gg+1])
		add(f0[gg+1],f1[gg]);
	if ((~md[gg]^rk[gg]^md[gg+1])&1&&rk[gg]>=md[gg]+md[gg+1])
	{	add(f2[gg+1],f1[gg]);
		add(f0[gg+1],f3[gg]);	}
	if ((~md[gg]^rk[gg]^md[gg+1])&1&&rk[gg]-2>=md[gg]+md[gg+1])
		add(f2[gg+1],f3[gg]);
}

inline void id5(num gg)
{
	if ((~rk[gg]^md0[gg+1])&1&&rk[gg]>=md0[gg+1])
		add(h0[gg+1],f0[gg]+f2[gg]);
	if ((md[gg]^rk[gg]^md0[gg+1])&1&&rk[gg]+1>=md[gg]+md0[gg+1])
		add(h0[gg+1],f1[gg]);
	if ((md[gg]^rk[gg]^md0[gg+1])&1&&rk[gg]-1>=md[gg]+md0[gg+1])
		add(h0[gg+1],f3[gg]);
	
	if ((~rk[gg]^md1[gg+1])&1&&rk[gg]>=md1[gg+1])
		add(h1[gg+1],f0[gg]+f2[gg]);
	if ((md[gg]^rk[gg]^md1[gg+1])&1&&rk[gg]+1>=md[gg]+md1[gg+1])
		add(h1[gg+1],f1[gg]);
	if ((md[gg]^rk[gg]^md1[gg+1])&1&&rk[gg]-1>=md[gg]+md1[gg+1])
		add(h1[gg+1],f3[gg]);
}

inline void id15(num gg)
{
	if (rk[gg]!=0&&rk[gg+1]==0&&rk[gg+2]!=0)
	{	if ((~rk[gg]^md[gg+2])&1&&rk[gg]>=md[gg+2])
			add(g[gg+1],f0[gg]+f2[gg]);
		if ((md[gg]^rk[gg]^md[gg+2])&1&&rk[gg]+1>=md[gg]+md[gg+2])
			add(g[gg+1],f1[gg]);
		if ((md[gg]^rk[gg]^md[gg+2])&1&&rk[gg]-1>=md[gg]+md[gg+2])
			add(g[gg+1],f3[gg]);	}
	
	if (rk[gg-1]!=0&&rk[gg]==0&&rk[gg+1]!=0)
	{	if ((~md[gg]^rk[gg+1])&1&&rk[gg+1]>=md[gg])
		{	add(f1[gg+2],g[gg]);
			add(f3[gg+2],g[gg]);	}
		if ((md[gg]^rk[gg+1]^md[gg+2])&1&&rk[gg+1]+1>=md[gg]+md[gg+2])
			add(f0[gg+2],g[gg]);
		if ((md[gg]^rk[gg+1]^md[gg+2])&1&&rk[gg+1]-1>=md[gg]+md[gg+2])
			add(f2[gg+2],g[gg]);	}
}

inline void tuigg(num gg)
{
	if (rk[gg-1]!=0&&rk[gg]==0&&rk[gg+2]==0&&rk[gg+3]!=0)
	if ((~md[gg]^rk[gg+1]^md[gg+3])&1&&rk[gg+1]>=md[gg]+md[gg+3])
		add(g[gg+2],g[gg]);
}

inline void tuigh(num gg)
{
	if (rk[gg-1]!=0&&rk[gg]==0&&rk[gg+1]!=0)
	{	if ((~md[gg]^rk[gg+1]^md0[gg+2])&1&&rk[gg+1]>=md[gg]+md0[gg+2])
			add(h0[gg+2],g[gg]);
		if ((~md[gg]^rk[gg+1]^md1[gg+2])&1&&rk[gg+1]>=md[gg]+md1[gg+2])
			add(h1[gg+2],g[gg]);	}
}

inline void id14(num gg)
{
	if ((~md1[gg]^rk[gg])&1&&rk[gg]>=md1[gg])
	{	add(f1[gg+1],h0[gg]);
		add(f3[gg+1],h0[gg]);	}
	if ((md1[gg]^rk[gg]^md[gg+1])&1&&rk[gg]+1>=md1[gg]+md[gg+1])
		add(f0[gg+1],h0[gg]);
	if ((md1[gg]^rk[gg]^md[gg+1])&1&&rk[gg]-1>=md1[gg]+md[gg+1])
		add(f2[gg+1],h0[gg]);
	
	if ((~md0[gg]^rk[gg])&1&&rk[gg]>=md0[gg])
	{	add(f1[gg+1],h1[gg]);
		add(f3[gg+1],h1[gg]);	}
	if ((md0[gg]^rk[gg]^md[gg+1])&1&&rk[gg]+1>=md0[gg]+md[gg+1])
		add(f0[gg+1],h1[gg]);
	if ((md0[gg]^rk[gg]^md[gg+1])&1&&rk[gg]-1>=md0[gg]+md[gg+1])
		add(f2[gg+1],h1[gg]);
}

void id0(num gg)
{
	if (rk[gg]!=0&&rk[gg+1]==0&&rk[gg+2]!=0)
	{	if ((~md1[gg]^rk[gg]^md[gg+2])&1&&rk[gg]>=md1[gg]+md[gg+2])
			add(g[gg+1],h0[gg]);
		if ((~md0[gg]^rk[gg]^md[gg+2])&1&&rk[gg]>=md0[gg]+md[gg+2])
			add(g[gg+1],h1[gg]);	}
}

void id6(num gg)
{
	if ((~md1[gg]^rk[gg]^md0[gg+1])&1&&rk[gg]>=md1[gg]+md0[gg+1])
		add(h0[gg+1],h0[gg]);
	if ((~md1[gg]^rk[gg]^md1[gg+1])&1&&rk[gg]>=md1[gg]+md1[gg+1])
		add(h1[gg+1],h0[gg]);
	if ((~md0[gg]^rk[gg]^md0[gg+1])&1&&rk[gg]>=md0[gg]+md0[gg+1])
		add(h0[gg+1],h1[gg]);
	if ((~md0[gg]^rk[gg]^md1[gg+1])&1&&rk[gg]>=md0[gg]+md1[gg+1])
		add(h1[gg+1],h1[gg]);
}

void dp()
{
	num i,j,k;
	memset(f0,0,sizeof(f0));
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	memset(g,0,sizeof(g));
	memset(h0,0,sizeof(h0));
	memset(h1,0,sizeof(h1));
	
	if ((rk[0]^md[1])&1)
	{	i=Abs(rk[0]-md[1]+1)/2;
		f0[1]=i+(i==0);	}
	if (~rk[0]&1)
		f1[1]=f3[1]=rk[0]/2;
	if (rk[1]==0&&md[2]!=-1&&rk[2]!=0&&(~rk[0]^md[2])&1)
	{	i=Abs(rk[0]-md[2])/2;
		g[1]=i+(i==0);	}
	
	for (i=1;i<san;i++)
	{
		if (md[i]==1)
			f1[i]=0;
		
		if (md[i]!=-1)
			if (md[i+1]!=-1)
			{	tuiff(i);
				if (i<san-1)
					if (md[i+2]!=-1)
					{	id15(i);
						if (i<san-2&&md[i+3]!=-1)
							tuigg(i);	}
					else
						tuigh(i);	}
			else
				id5(i);
		else
			if (md[i+1]!=-1)
			{	id14(i);
				if (i<san-1&&md[i+2]!=-1)
				id0(i);	}
			else
				id6(i);
	}
	
	if (md[san]==1)
		f1[san]=0;
	
	if ((rk[san]^md[san])&1)
	{	i=Abs(rk[san]-md[san]+1)/2;
		ans=(ans+f1[san]*(i+(i==0)))%mod;	}
	if (~rk[san]&1)
		ans=(ans+(f0[san]+f2[san])*rk[san]/2%mod)%mod;
	if (rk[san-1]==0&&md[san-1]!=-1&&rk[san-2]!=0&&(~rk[san]^md[san-1])&1)
	{	i=Abs(rk[san]-md[san-1])/2;
		ans=(ans+g[san-1]*(i+(i==0)))%mod;	}
}

void id16()
{
	num h,t,u,v,pt,i;
	t=0;
	for (i=1;i<=n;i++)
		if (rd[i]==1)
		{ q[t++]=i; g[i]=1; }
	for (h=0;h<t;h++)
	{
		u=q[h];
		for (pt=fir[u];pt!=0;pt=next[pt])
		{
			v=tar[pt];
			if (rd[v]==3)
				g[v]--;
			if (g[v]) continue;
			if (rd[v]==2)
			{
				rd[v]=1;
				g[v]=g[u]+1;
				q[t++]=v;
			}
		}
	}
	if (san==1)
		San1();
}
void id9()
{
	num h,t,u,v,pt,i;
	q[0]=sa[1]; t=1; san=1;
	rd[q[0]]=-1; fa[q[0]]=0;
	for (h=0;h<t;h++)
	{
		u=q[h];
		for (pt=fir[u];pt!=0;pt=next[pt])
		{
			v=tar[pt];
			if (rd[v]>1)
			{
				if (rd[v]!=3) rd[v]=1;
				else { rd[v]=-1; sa[++san]=v; }
				q[t++]=v; fa[v]=u;
			}
		}
	}
	
	t=2;
	for (i=2;i<=san;i++)
	{
		u=sa[i];
		for (h=0,v=fa[u];rd[v]!=-1;h++,v=fa[v]);
		srd[u]++; srd[v]++;
		snext[t]=sfir[u]; sdis[t]=h;
		sfir[u]=t;	star[t]=v;
		t++;
		snext[t]=sfir[v]; sdis[t]=h;
		sfir[v]=t;	star[t]=u;
		t++;
	}
}

inline void id2(num a,num &b,num &c)
{
	a=fir[a]; b=next[a]; c=next[b];
	b=g[tar[b]]<=0?g[tar[a]]:g[tar[b]];
	c=g[tar[c]]<=0?g[tar[a]]:g[tar[c]];
}

void id8()
{
	num h,t,u,v,pt,i;
	num J1,j2,j3;
	memset(fa,0,sizeof(fa));
	q[0]=sa[1]; t=1; fa[sa[1]]=-1;
	for (h=0;h<t;h++)
	{
		u=q[h];
		for (pt=sfir[u];pt!=0;pt=snext[pt])
		{
			v=star[pt];
			if (fa[v]==0)
			{ q[t++]=v; fa[v]=u; }
		}
	}
	
	memset(fa,0,sizeof(fa));
	q[0]=q[t-1]; t=1; fa[q[0]]=-1;
	for (h=0;h<t;h++)
	{
		u=q[h];
		for (pt=sfir[u];pt!=0;pt=snext[pt])
		{
			v=star[pt];
			if (fa[v]==0)
			{ q[t++]=v; fa[v]=pt^1; }
		}
	}
	
	sa[1]=q[t-1]; san=1;
	for (san=1;sa[san]!=q[0];san++)
	{
		pt=fa[sa[san]];
		sa[san+1]=star[pt];
		rk[san]=sdis[pt];
	}
	
	for (i=2;i<san;i++)
	{
		u=sa[i];
		if (srd[u]==3)
		{
			for (pt=sfir[u];pt!=0;pt=snext[pt])
				if (star[pt]!=sa[i-1]&&star[pt]!=sa[i+1])
					break;
			if (pt==0)
				if (jiancha) SHIT(4); else err();
			
			v=star[pt];
			if (srd[v]>1)
				if (jiancha) SHIT(5); else err();
			
			t=sdis[pt];
			if (i==2	&&t!=0&&rk[1]==0) { swap(rk[1],t); swap(sa[i-1],v); }
			if (i==san-1&&t!=0&&rk[i]==0) { swap(rk[i],t); swap(sa[i+1],v); }
			if (t!=0||rk[i-1]==0||rk[i]==0)
				if (jiancha) SHIT(2); else err();
			
			md[i]=-1;
			id2(v,md0[i],md1[i]);
		}
		else
			for (pt=fir[u];pt!=0;pt=next[pt])
				if (g[tar[pt]]>0) md[i]=g[tar[pt]];
	}
	
	id2(sa[1],rk[0],md[1]);
	id2(sa[san],rk[san],md[san]);
}

inline void fileopen()
{
	freopen("251E.in","r",stdin);
	freopen("251E.out","w",stdout);
}

char G_ch;
num Gret;
num getnum()
{
	for (G_ch=0;G_ch< '0'||G_ch> '9';G_ch=getchar());
	for (Gret=0;G_ch>='0'&&G_ch<='9';G_ch=getchar()) Gret=Gret*10+(G_ch&15);
	return Gret;
}
num getnum(num &gg)
{
	for (G_ch=0;G_ch< '0'||G_ch> '9';G_ch=getchar());
	for (Gret=0;G_ch>='0'&&G_ch<='9';G_ch=getchar()) Gret=Gret*10+(G_ch&15);
	if (G_ch==',') G_ch=getchar();
	for (gg=0;G_ch>='0'&&G_ch<='9';G_ch=getchar()) gg=gg*10+(G_ch&15);
	return Gret;
}

void id13()
{
	n=getnum();
	num n2=n;
	n*=2;
	san=0;
	
	if (n==2)
	{ printf("2\n"); exit(0); }
	
	num i,u=0,v=0;
	
	jiancha=0;
	
	for (i=1;i<n;i++)
	{
		u=getnum();
		v=getnum();
		




		
		next[i]=fir[u];
		fir[u]=i;
		tar[i]=v;
		next[i+n]=fir[v];
		fir[v]=i+n;
		tar[i+n]=u;
		
		if (rd[u]<rd[v]) swap(u,v);
		rd[u]++;
		rd[v]++;
		if (rd[u]==4)
			if (jiancha) SHIT(3); else err();
		if (rd[u]==3)
		{
			sa[san++]=u;
			if (rd[v]==3) sa[san++]=v;
		}
	}
	
	if (san==0)
	{
		printf("%I64d",2*(n2*(n2-1)+2)%mod);
		exit(0);
	}
}

void id7()
{
	int i;
	san=getnum();
	rk[0]=getnum();
	for (i=1;i<=san;i++)
	{
		md0[i]=getnum(md1[i]);
		if (md1[i]!=0) md[i]=-1;
		else { md[i]=md0[i]; md0[i]=0; }
		rk[i]=getnum();
	}
}

int main()
{

	fileopen();

	

	id13();
	id16();
	id9();
	id8();

	id7();



	if (jiancha==1)
		debugerr();                                                              

	if (jiancha==2)
		id3();
	
	if (san!=2||rk[1]!=0) ans=0;  

	else ans=III();
	
	dp();
	swap(rk[0],md[1]);
	dp();
	swap(rk[san],md[san]);
	dp();
	swap(rk[0],md[1]);
	dp();
	printf("%I64d\n",ans*4%mod);
	






	
	return 0;
}

