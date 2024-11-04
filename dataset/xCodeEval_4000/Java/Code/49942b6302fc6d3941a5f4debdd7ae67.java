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
	static long mod=(long)998244353,INF=Long.MAX_VALUE;
	

	static int par[],partial[];
	static int Days[],P[][];
	static int sum=0,size[];
	static int seg[],col[];
	

	static char X[][];
	static boolean set[][];
	static int D[],min[],A[];
	static long dp[][];
	

	

	

	

	public static void main(String args[])throws IOException
	{	
				
		long pow[]=new long[(int)(5e5)+5];
		pow[0]=1L;
		for(int i=1; i<=5e5; i++)
		{

			pow[i]=(pow[i-1]*2L)%mod;
		}
		

		int T=i();
		while(T-->0)
		{
			int N=i();
	        int A[]=input(N);
	        long s=0;
			long dp[][]=new long[N+5][2];
			dp[0][0]=1L; 

			for(int x:A)
			{
				if(x>0)
				{
					dp[x-1][1]+=(dp[x-1][0]+dp[x-1][1])%mod;
					dp[x-1][1]%=mod;
				}
				dp[x+1][1]+=dp[x+1][1];
				dp[x+1][0]+=(dp[x][0]+dp[x+1][0])%mod;
				dp[x+1][1]%=mod;
				dp[x+1][0]%=mod;
			}
			for(int i=0; i<=N; i++)
			{
				s+=(dp[i][0]+dp[i][1])%mod;
				s%=mod;
			}
			s=(s+mod-1L)%mod;
			ans.append(s+"\n");
		}
		out.println(ans);
		out.close();
	}
	static int lower(ArrayList<Integer>A,int i)
	{
		int l=-1,r=A.size();
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A.get(m)>i)r=m;
			else l=m;
		}		
		return r;
	}
	static int upper(ArrayList<Integer>A,int i)
	{
		int l=-1,r=A.size();
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A.get(m)<i)l=m;
			else l=m;
		}		
		return l;
	}
	static String f()
	{
		StringBuilder X=new StringBuilder(i()+"");int p=i();
		while(p-->0)X.append("0");
		return X.toString();
	}
	static long f(int i,int g,int x,int left)
	{
		if(x<=1)return left;
		if(i<0 || g==1)return left;
		

		if(dp[i][g]==0)
		{
			int next=min[i];
			int new_gcd=(int)GCD(g,x);
			

			long s=0;
			int c=0;
			for(int j=next+1; j<=i; j++)
			{
				if(A[i]%new_gcd==0)
				{
					s+=new_gcd;
					c--;
				}
			}
			long a=0,b=0;
			a=f(i,g,x-1,left);
			b=s+f(next,new_gcd,x-1,left-c);
			dp[i][g]=Math.max(a, b);
		}
		return dp[i][g];
	}
	static boolean f(int A[],int B[],int x)
	{
		int c=0;
		int N=A.length;
		int l=0,r=x-1;
		for(int i=0; i<N; i++)
		{
			if(A[i]>=r && B[i]>=l)
			{
				r--;
				l++;
				c++;				
			}
			if(c>=x)return true;
		}
		return false;
	}
	static boolean isPalindrome(int A[])
	{
		int i=0,j=A.length-1;
		while(i<j)
		{
			if(A[i]!=A[j])return false;
			i++;
			j--;
		}
		return true;
	}
	static boolean isPalindrome(int A[],int x)
	{
		int i=0,j=A.length-1;
		while(i<j)
		{
			if(A[i]!=A[j])
			{
				if(A[i]==x)i++;
				else if(A[j]==x)j--;
				else return false;
			}
			else
			{
				i++;
				j--;
			}
		}
		return true;
	}
	static long fact[];
	static double nCr(int a,int b)
	{
		double x=fact[a], y=fact[b]*fact[a-b];
		return x/y;
	}
	static int f(ArrayList<Integer> A,int x)
	{
		int l=-1,r=A.size();
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A.get(m)<x)l=m;
			else r=m;
		}
		return r;
	}
	static boolean f(long a,long b,long x)
	{
		if(b==0)
		{
			return (x==a || x==b);
		}
		if(a<x)return false;
		else
		{
			if(a%b==x%b)return true;
			return f(b,a%b,x);
		}
	}

	static void dfs(int n,int p)
	{
		if(p!=-1)D[n]=D[p]+1;
		for(int c:g[n])
		{
			if(c!=p)
				dfs(c,n);
		}
	}
	static long f(long a,long A[])
	{
		int l=-1,r=A.length;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<=a)l=m;
			else r=m;
		}
		return A[l];
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
		seg[v]=Math.min(seg[v*2], seg[v*2+1]);
	}
	static void update(int v,int tl,int tr,int index,int x)
	{
		if(tl==tr && tl==index)
		{
			seg[v]=x;
			return;
		}		
		int tm=(tl+tr)/2;
		if(index<=tm)update(v*2,tl,tm,index,x);
		else update(v*2+1,tm+1,tr,index,x);
		seg[v]=Math.min(seg[v*2], seg[v*2+1]);
	}
	static int ask(int v,int tl,int tr,int l,int r)
	{
		

		

		if(l>r)return Integer.MAX_VALUE;
		if(tl==l && tr==r)return seg[v];
		int tm=(tl+tr)/2;
		int a=ask(v*2,tl,tm,l,Math.min(tm, r));
		

		int b=ask(v*2+1,tm+1,tr,Math.max(l, tm+1),r);
		return Math.min(a, b);
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
			par[a]+=par[b];
			par[b]=a;
		}
	}
	static int ask(int a,int b)
	{
		System.out.println("? "+a+" "+b);
		return i();
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
		

		partial=new int[N+1];
		Days=new int[N+1];
		P=new int[N+1][(int)(Math.log(N)+10)];
		

		g=new ArrayList[N+1];
		D=new int[N+1];
		for(int i=0; i<=N; i++)
		{

			g[i]=new ArrayList<>();		
			Days[i]=-1;
			D[i]=Integer.MAX_VALUE;
			

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
		else return GCD(b,a%b);
	}

}
class pair1 implements Comparable<pair1>
{
	int a, index;
	pair1(int b,int i)
	{
		a=b;
		index=i;
	}
	public int compareTo(pair1 x)
	{
		return x.a-this.a;
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