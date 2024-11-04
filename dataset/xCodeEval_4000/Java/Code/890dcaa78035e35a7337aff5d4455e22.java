
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.*;
import java.util.*;
 
import java.math.*;
import java.math.BigInteger;
 
 
public final class Template
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	static int g[][];
	static long mod=(long) 998244353,INF=Long.MAX_VALUE;
	

	static int max=0;
	static int lca[][];
	static int par[],col[],D[];
	static long dp[][][],fact[];
	static int seg[],size[],N;
	static int dp1[][],dp2[][];
	static HashSet<Integer> set[];
	public static void main(String args[])throws IOException
	{	
		
		int T=i();
		
		
		while(T-->0)
		{
			long a = l();
			long s = l();
			
			ArrayList<Long> lst = new ArrayList<>();
			boolean flag = true;
			
			while(s>0) {
				long x = a % 10;
				long y = s % 10;
				
				if(x <= y) {
					lst.add(y-x);
				} else {
					s /= 10;
					y += 10 * (s%10);
					
					if(y-x>=0 && y-x<=9) {
						lst.add(y-x);
					} else {
						ans.append("-1\n");
						flag = false;
						break;
					}
				}
				a /= 10;
				s /= 10;
			}
			if(!flag) continue;
				
			if(a>0) {
				ans.append("-1\n");
			} else {
				int i=lst.size()-1;
				while(lst.get(i) == 0) {
					i--;
				}
				for(; i>=0; --i) {
					ans.append(lst.get(i));
				}
				ans.append("\n");
			}
		}
 


		out.println(ans);
		out.close();
	}
 
	static  int distance(int a,int b)
	{
		int d=D[a]+D[b];
		int l=LCA(a,b);
		l=2*D[l];
		return d-l;
	}
	static int LCA(int a,int b)
	{
		if(D[a]<D[b])
		{
			int t=a;
			a=b;
			b=t;
		}
		int d=D[a]-D[b];
		int p=1;
		for(int i=0; i>=0 && p<=d; i++)
		{
			if((p&d)!=0)
			{
				a=lca[a][i];
			}
			p<<=1;
		}
		if(a==b)return a;
		for(int i=max-1; i>=0; i--)
		{
			if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
			{
				a=lca[a][i];
				b=lca[b][i];
			}
		}
		return lca[a][0];
 
	}
 
	static void dfs(int n,int p)
	{
		lca[n][0]=p;
		if(p!=-1)D[n]=D[p]+1;
		for(int c:g[n])
		{
			if(c!=p)
			{
 
				dfs(c,n);
 
			}
		}
	}
	static int[] rev(int A[],int N)
	{
		int B[]=new int[N];
		int j=N-1;
		for(int i=0; i<N; i++)B[i]=A[j--];
		return B;
	}
	static int[] last(int A[],int N)	
	{
		int last[]=new int[N+5];
		Arrays.fill(last, -1);
		for(int i=N-1; i>=0; i--)
		{
			int a=A[i];
			if(last[a]==-1)last[a]=i;
		}
		return last;
	}
	static int f(int A[],int last[])
	{
		int N=A.length;
		int c=0;
		int i=0;
		int pre[]=new int[N+5];
		while(i<N && last[A[i]]==i)
		{
			i++;
		}			
		int from=i;
		int counter=0;
		while(i<N)
		{
			int r=last[A[i]];
			pre[i+1]+=1;
			pre[r]-=1;
			int max=0,index=0;
 
			for(int j=i+1; j<r; j++)
			{
				if(last[A[j]]>r)
				{
					max=Math.max(max, last[A[j]]);
					if(max==last[A[j]])index=j;	
				}
			}
			

			if(max==0)
			{
				i=r+1;
				while(i<N && last[A[i]]==i)i++;
			}
			else
			{
				i=index;
				counter++;
			}
			

		}
		for( i=1; i<=N; i++)pre[i]+=pre[i-1];
		for(int a:pre)if(a>0)c++;
		c-=counter;
		return c;
	}
	static void dfs2(int n,int p,int k)
	{
		if(p!=-1)
		{
			

			for(int i=1; i<=k; i++)
			{
				dp2[n][i]+=dp1[n][i];
				int from_par=0;
				if(i-2>=0)from_par=dp2[p][i-1]-dp1[n][i-2];
				else from_par=1;
				

				dp2[n][i]+=from_par;
			}
		}
		for(int c:g[n])
		{
			if(c!=p)
				dfs2(c,n,k);			
		}
 
	}
	static void dfs(int n,int p,int k)
	{
		dp1[n][0]=1;
		for(int c:g[n])
		{
			if(c!=p)
			{
				dfs(c,n,k);
				for(int i=1; i<=k; i++)
				{
					dp1[n][i]+=dp1[c][i-1];
				}
			}
		}
 
	}
	static int[] prefix_function(char X[])

	{
		int N=X.length;
		int pre[]=new int[N];
		for(int i=1; i<N; i++)
		{
			int j=pre[i-1];
			while(j>0 && X[i]!=X[j])
				j=pre[j-1];
			if(X[i]==X[j])j++;
			pre[i]=j;
		}
		return pre;
	}
 
 
	static TreeNode start;
	public static void f(TreeNode root,TreeNode p,int r)
	{
		if(root==null)return;
		if(p!=null)
		{
			root.par=p;
		}
		if(root.val==r)start=root;
		f(root.left,root,r);
		f(root.right,root,r);
	}
 
 
	static int right(int A[],int Limit,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<Limit)l=m;
			else r=m;
		}
		return l;
	}
	static int left(int A[],int a,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<a)l=m;
			else r=m;
		}
		return l;
	}
	static int f(int k,int x,int N)
	{
		int l=x-1,r=N;
		while(r-l>1)
		{
			int m=(l+r)/2;
			int a=ask(1,0,N-1,x,m);
			if(a<k)
			{				
				l=m;
			}
			else r=m;
		}
		

		if(r==N)return -1;
		return r;
	}
	static void build(int v,int tl,int tr,int A[])
	{
		if(tl==tr)
		{
			seg[v]=A[tl];
			return;
		}
		int tm=(tl+tr)/2;
		build(v*2,tl,tm,A);
		build(v*2+1,tm+1,tr,A);
		seg[v]=Math.max(seg[v*2],seg[v*2+1]);
	}
	static void update(int v,int tl,int tr,int index,int a)
	{
		if(index==tl && tl==tr)
			seg[v]=a;
		else
		{
			int tm=(tl+tr)/2;
			if(index<=tm)update(2*v,tl,tm,index,a);
			else update(2*v+1,tm+1,tr,index,a);
			seg[v]=Math.max(seg[v*2],seg[v*2+1]);
		}
	}
	static int ask(int v,int tl,int tr,int l,int r)
	{
		if(l>r)return -1;
		if(l==tl && tr==r)return seg[v];
		int tm=(tl+tr)/2;
		return Math.max(ask(v*2,tl,tm,l,Math.min(tm, r)),ask(2*v+1,tm+1,tr,Math.max(tm+1, l),r));
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	static boolean f(long A[],long m,int N)
	{
		long B[]=new long[N];
		for(int i=0; i<N; i++)
		{
			B[i]=A[i];
		}
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<m)return false;
			if(i>=2)
			{
				long extra=Math.min(B[i]-m, A[i]);
				long x=extra/3L;
				B[i-2]+=2L*x;
				B[i-1]+=x;
			}
		}
		return true;
	}
	static int f(int l,int r,long A[],long x)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]>=x)l=m;
			else r=m;
		}
		return r;
 
	}
	static boolean f(long m,long H,long A[],int N)
	{
		long s=m;
		for(int i=0; i<N-1;i++)
		{
			s+=Math.min(m, A[i+1]-A[i]);
		}
		return s>=H;
	}
 
	static long ask(long l,long r)
	{
		System.out.println("? "+l+" "+r);
		return l();
	}
	static long f(long N,long M)
	{
		long s=0;
		if(N%3==0)
		{
			N/=3;
			s=N*M;
		}
		else
		{
			long b=N%3;
			N/=3;
			N++;
			s=N*M;
			N--;
			long a=N*M;
			if(M%3==0)
			{
				M/=3;
				a+=(b*M);
			}
			else
			{
				M/=3;
				M++;
				a+=(b*M);
			}
			s=Math.min(s, a);
		}
		return s;
	}
	static int ask(StringBuilder sb,int a)
	{
		System.out.println(sb+""+a);
		return i();
	}
	static void swap(char X[],int i,int j)
	{
		char x=X[i];
		X[i]=X[j];
		X[j]=x;
	}
	static int min(int a,int b,int c)
	{
		return Math.min(Math.min(a, b), c);
	}
 
 
	static long and(int i,int j)
	{
		System.out.println("and "+i+" "+j);
		return l();
	}
	static long or(int i,int j)
	{
		System.out.println("or "+i+" "+j);
		return l();
	}
	static int len=0,number=0;
	static void f(char X[],int i,int num,int l)
	{
		if(i==X.length)
		{
			if(num==0)return;
			

			if(isPrime(num))return;
			if(l<len)
			{
				len=l;
				number=num;				
			}
			return;
		}
		int a=X[i]-'0';
		f(X,i+1,num*10+a,l+1);
		f(X,i+1,num,l);
	}
	static boolean is_Sorted(int A[])
	{
		int N=A.length;
		for(int i=1; i<=N; i++)if(A[i-1]!=i)return false;
		return true;
	}
	static boolean f(StringBuilder sb,String Y,String order)
	{
		StringBuilder res=new StringBuilder(sb.toString());
		HashSet<Character> set=new HashSet<>();
		for(char ch:order.toCharArray())
		{
			set.add(ch);
			for(int i=0; i<sb.length(); i++)
			{
				char x=sb.charAt(i);
				if(set.contains(x))continue;
				res.append(x);
			}
		}
 
		String str=res.toString();
		return str.equals(Y);
	}
	static boolean all_Zero(int f[])
	{
		for(int a:f)if(a!=0)return false;
		return true;
	}
	static long form(int a,int l)
	{
		long x=0;
		while(l-->0)
		{
			x*=10;
			x+=a;
		}
		return x;
	}
	static int count(String X)
	{
		HashSet<Integer> set=new HashSet<>();
		for(char x:X.toCharArray())set.add(x-'0');
		return set.size();
	}
 
	static int f(long K)
	{
		long l=0,r=K;
		while(r-l>1)
		{
			long m=(l+r)/2;
			if(m*m<K)l=m;
			else r=m;
		}
		return (int)l;
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

 
	static int [] sub(int A[],int B[])
	{
		int N=A.length;
		int f[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<A[i])
			{
				B[i]+=26;
				B[i-1]-=1;
			}
			f[i]=B[i]-A[i];
		}
		for(int i=0; i<N; i++)
		{
			if(f[i]%2!=0)f[i+1]+=26;
			f[i]/=2;
		}
		return f;
	}
	static int[] f(int  N)
	{
		char X[]=in.next().toCharArray();
		int A[]=new int[N];
		for(int i=0; i<N; i++)A[i]=X[i]-'a';
		return A;
	}
 
 
 
 
	static int max(int a ,int b,int c,int d)
	{
		a=Math.max(a, b);
		c=Math.max(c,d);
		return Math.max(a, c);
	}
	static int min(int a ,int b,int c,int d)
	{
		a=Math.min(a, b);
		c=Math.min(c,d);
		return Math.min(a, c);
	}
 
 
 
	static HashMap<Integer,Integer> Hash(int A[])
	{
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int a:A)
		{
			int f=mp.getOrDefault(a,0)+1;
			mp.put(a, f);
		}
		return mp;
	}
	static long mul(long a, long b)
	{
		return ( a %mod * 1L * b%mod )%mod;
	}
	static void swap(int A[],int a,int b)
	{
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}
 
 
	static int find(int a)
	{
		if(par[a]<0)return a;
		return par[a]=find(par[a]);
	}
	static void union(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			if(par[a]>par[b]) 

			{
				int t=b;
				b=a;
				a=t;
			}
			par[a]+=par[b];
			par[b]=a;
		}
	}
	static boolean isSorted(int A[])
	{
		for(int i=1; i<A.length; i++)
		{
			if(A[i]<A[i-1])return false;
		}
		return true;
	}
 
	static boolean isDivisible(StringBuilder X,int i,long num)
	{
		long r=0;
		for(; i<X.length(); i++)
		{
			r=r*10+(X.charAt(i)-'0');
			r=r%num;
		}
		return r==0;
	}    
 
 
 
	static int lower_Bound(int A[],int low,int high, int x) 
	{ 
		if (low > high) 
			if (x >= A[high]) 
				return A[high]; 
 
		int mid = (low + high) / 2; 
 
		if (A[mid] == x) 
			return A[mid]; 
 
		if (mid > 0 && A[mid - 1] <= x && x < A[mid]) 
			return A[mid - 1]; 
 
		if (x < A[mid]) 
			return lower_Bound( A, low, mid - 1, x); 
 
		return lower_Bound(A, mid + 1, high, x); 
	} 
 
	static String f(String A)
	{
		String X="";
		for(int i=A.length()-1; i>=0; i--)
		{
			int c=A.charAt(i)-'0';
			X+=(c+1)%2;
		}
		return X;
	}
 
	static void sort(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
 
	static String swap(String X,int i,int j)
	{
		char ch[]=X.toCharArray();
		char a=ch[i];
		ch[i]=ch[j];
		ch[j]=a;
		return new String(ch);
	}
 
	static int sD(long n)  
	{  
 
		if (n % 2 == 0 )  
			return 2;  
 
		for (int i = 3; i * i <= n; i += 2) {  
			if (n % i == 0 )  
				return i;  
		}  
 
		return (int)n;  
	}  
 
	static void setGraph(int N)
	{
		par=new int[N+1];
		

		

		

		col=new int[N+1];
		for(int i=0; i<=N; i++)
		{
			col[i]=-1;
			

			

		}
	}
 
 
 
	static  long pow(long a,long b)
	{
		

		long pow=1;
		long x=a;
		while(b!=0)
		{
			if((b&1)!=0)pow=(pow*x)%mod;
			x=(x*x)%mod;
			b/=2;
		}
		return pow;
	}
 
	static long toggleBits(long x)

	{
		int n=(int)(Math.floor(Math.log(x)/Math.log(2)))+1;
 
		return ((1<<n)-1)^x;
	}
 
	static int countBits(long a)
	{
		return (int)(Math.log(a)/Math.log(2)+1);
	}
 
	static long fact(long N)
	{ 
		long n=2; 
		if(N<=1)return 1;
		else
		{
			for(int i=3; i<=N; i++)n=(n*i)%mod;
		}
		return n;
	}
 
	static int kadane(int A[])
	{
		int lsum=A[0],gsum=A[0];
		for(int i=1; i<A.length; i++)
		{
			lsum=Math.max(lsum+A[i],A[i]);
			gsum=Math.max(gsum,lsum);
		}
		return gsum;
	}
 
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
 
	static boolean isPrime(long N)
	{
		if (N<=1)  return false; 
		if (N<=3)  return true; 
		if (N%2 == 0 || N%3 == 0) return false; 
		for (int i=5; i*i<=N; i=i+6) 
			if (N%i == 0 || N%(i+2) == 0) 
				return false; 
		return true; 
	}
	static void print(char A[])
	{
		for(char c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(boolean A[])
	{
		for(boolean c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(int A[])
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();	
	}
	static void print(long A[])
	{
		for(long i:A)System.out.print(i+ " ");
		System.out.println();
 
	}
	static void print(boolean A[][])
	{
		for(boolean a[]:A)print(a);
	}
	static void print(long A[][])
	{
		for(long a[]:A)print(a);
	}
	static void print(int A[][])
	{
		for(int a[]:A)print(a);
	}
	static void print(ArrayList<Integer> A)
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();
	}
 
	static int i()
	{
		return in.nextInt();
	}
 
	static long l()
	{
		return in.nextLong();
	}
 
	static int[] input(int N){
		int A[]=new int[N];
		for(int i=0; i<N; i++)
		{
			A[i]=in.nextInt();
		}
		return A;
	}
 
	static long[] inputLong(int N)     {
		long A[]=new long[N];
		for(int i=0; i<A.length; i++)A[i]=in.nextLong();
		return A;
	}
 
	static long GCD(long a,long b) 
	{
		if(b==0)
		{
			return a;
		}
		else return GCD(b,a%b );
	}
 
}
class segNode 
{
	long pref,suff,sum,max;
	segNode(long a,long b,long c,long d)
	{
		pref=a;
		suff=b;
		sum=c;
		max=d;
	}
}






























class post implements Comparable<post>
{
	long x,y,d,t;
	post(long a,long b,long c)
	{
		x=a;
		y=b;
		d=c;
	}
	public int compareTo(post X)
	{
		if(X.t==this.t)
		{
			return 0;
		}
		else
		{
			long xt=this.t-X.t;
			if(xt>0)return 1;
			return -1;
		}
	}
}
class TreeNode
{
	int val;
	TreeNode left, right,par;
	TreeNode() {}
	TreeNode(int item)
	{
		val = item;
		left =null;
		right = null;
		par=null;
	}
}
class edge
{
	int a,wt;
	edge(int a,int w)
	{
		this.a=a;
		wt=w;
	}
}








class FastReader
{
	BufferedReader br;
	StringTokenizer st;
	public FastReader()
	{
		br=new BufferedReader(new InputStreamReader(System.in));
	}
 
	String next()
	{
		while(st==null || !st.hasMoreElements())
		{
			try
			{
				st=new StringTokenizer(br.readLine());
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}
 
	int nextInt()
	{
		return Integer.parseInt(next());
	}
 
	long nextLong()
	{
		return Long.parseLong(next());
	}
 
	double nextDouble()
	{
		return Double.parseDouble(next());
	}
 
	String nextLine()
	{
		String str="";
		try
		{
			str=br.readLine();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return str;
	}
 
}
