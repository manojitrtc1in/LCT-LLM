import java.io.*;
import java.util.*;


import java.math.*;
import java.math.BigInteger;


public final class A
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	static ArrayList<Integer> g[];
	static long mod=(long) 998244353,INF=Long.MAX_VALUE;
	

	static int par[],col[],D[];
	static long A[];
	static int seg[];
	static int dp[][];
	static HashSet<Integer> set[];
	public static void main(String args[])throws IOException
	{	
		
		int T=i();while(T-->0)
		{
		int N=i();
		if(N%2!=0)
		{
			ans.append("Bob\n");
		}
		else
		{
			int c=0;
			while(N%2==0)
			{
				c++;
				N/=2;
			}
			if(N!=1 || c%2==0)
			{
				ans.append("Alice\n");
			}
			else ans.append("Bob\n");
		}
		}
		out.println(ans);
		out.close();
	}	
	static StringBuilder sb;
	static int count;
	static void dfs(int n,HashSet<Integer> not_visited)
	{
		count++;
		sb.append(n+" ");
		HashSet<Integer> st=new HashSet<>();
		for(int a:not_visited)
		{
			if(set[n].contains(a)==false)
			{
				st.add(a);
				

			}
		}
		for(int a:st)
		{
			not_visited.remove(a);
		}
		for(int a:st)dfs(a,not_visited);
	}
	static boolean f(int n,int p,int min[])
	{

		par[n]=p;
		boolean f=true;
		for(int c:g[n])
		{
			if(c!=p)
			{
				if(!f(c,n,min))return false;
				if(min[c]<min[n])
				{
					return  false;
				}				
				min[n]=Math.min(min[n],min[c]);
			}
		}
		return f;
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
	public static HashSet<Integer> st;
	public static int i=0;
	public static HashMap<Integer,Integer> mp=new HashMap<>();
	public static  TreeNode buildTree(int[] preorder, int[] inorder) {
		for(int i=0; i<preorder.length; i++)mp.put(inorder[i],i);
		TreeNode head=new TreeNode();
		f(preorder,inorder,0,inorder.length-1,head);
		return head;
	}
	public static void f(int pre[],int in[],int l,int r,TreeNode root)
	{
		

		root.val=pre[i];
		int it=mp.get(pre[i++]);

		

		if(it-1>=l)
		{
			TreeNode left=new TreeNode();
			root.left=left;
			f(pre,in,l,it-1,left);
		}
		if(it+1<=r)
		{

			TreeNode right=new TreeNode();
			root.right=right;
			f(pre,in,it+1,r,right);
		}
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
	static boolean f(int i,int j,long last,boolean win[])
	{
		if(i>j)return false;
		if(A[i]<=last && A[j]<=last)return false;
		long a=A[i],b=A[j];
		

		if(a==b)
		{
			return win[i] | win[j];
		}
		else if(a>b)
		{
			boolean f=false;
			if(b>last)f=!f(i,j-1,b,win);
			return win[i] | f;
		}
		else
		{
			boolean f=false;
			if(a>last)f=!f(i+1,j,a,win);
			return win[j] | f;
		}
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
		D=new int[N+1];
		g=new ArrayList[N+1];
		

		col=new int[N+1];
		for(int i=0; i<=N; i++)
		{
			col[i]=-1;
			g[i]=new ArrayList<>();		
			

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