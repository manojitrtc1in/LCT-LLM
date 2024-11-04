import java.io.*;
import java.util.*;


import java.math.*;
import java.math.BigInteger;


public final class B
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	static ArrayList<Integer> g[],G[];
	static long mod=(long)998244353,INF=Long.MAX_VALUE;
	

	static int par[],partial[];
	static int Days[],P[][];
	static int sum=0,size[];
	static int seg[],col[];
	

	static char X[][];
	static boolean set[][];
	static int D[],min[],A[][];
	static long dp[][];
	

	

	

	

	public static void main(String args[])throws IOException
	{	
		
		int T=i();
		outer:while(T-->0)
		{
				int N=i();
				int A[]=input(N);
			

				int mex[]=new int[N+1];
				int j=0;
				boolean set[]=new boolean[N+5];
				for(int i=N-1; i>=0; i--)
				{
					set[A[i]]=true;
					while(j<=N+1 && set[j])j++;
					mex[i]=j;
				}


				int x=0;
				StringBuilder sb=new StringBuilder();
				int a=mex[0];
				HashSet<Integer> st=new HashSet<>();
				for(int i=0; i<N; i++)
				{
					if(A[i]<a)
					{
						st.add(A[i]);
						

						
					}
					if(st.size()==a)
					{
						sb.append(a+" ");
						a=mex[i+1];
						x++;							
						st=new HashSet<>();
						

					}
				}
				ans.append(x+"\n");
				if(x>0)ans.append(sb+"\n");
		}
		out.println(ans);
		out.close();
	}
	
	
	
	static boolean compare(char A[],char B[])
	{
		for(int i=0; i<A.length; i++)
		{
			if(A[i]<B[i]) {
				

				return true;
			}
			if(A[i]>B[i]) {
				

				return false;
			}
		}
		return false;
	}
	static int ask(int a)
	{
		System.out.println("? "+a);
		

		return i();
	}
	static boolean f(String A,String B)
	{
		char X[]=A.toCharArray(),Y[]=B.toCharArray();
		if(X[X.length-1]=='0' && A.length()==B.length())
		{
			return A.equals(B);
		}
		else 
			if(X[X.length-1]=='0')
			{
				for(int i=0; i<Y.length-X.length; i++)
				{
					boolean f=true;
					for(int j=0; j<X.length; j++)
					{
						if(X[j]!=Y[i+j])
						{
							f=false;
						}
					}
					if(f)
					{
						for(int j=0; j<i; j++)
						{
							if(Y[j]=='0')f=false;
						}
						for(int j=i+X.length; j<Y.length; j++)
						{
							if(Y[j]=='0')f=false;
						}
						if(f) {
							

							return true;
						}
					}
				}

				return false;
			}
			else
			{
				for(int i=0; i<=Y.length-X.length; i++)
				{
					boolean f=true;
					for(int j=0; j<X.length; j++)
					{
						if(X[j]!=Y[i+j])
						{
							f=false;
						}
					}
					if(f)
					{
						for(int j=0; j<i; j++)
						{
							if(Y[j]=='0')f=false;
						}
						for(int j=i+X.length; j<Y.length; j++)
						{
							if(Y[j]=='0')f=false;
						}
						if(f) {
							

							return true;
						}
					}
				}

				return false;
			}
	}
	static String reverse (String X)
	{
		StringBuilder sb=new StringBuilder(X);
		return sb.reverse().toString();
	}
	static String binary(long x)
	{
		String str="";
		long p=1L;
		while(p<=x)
		{
			if((p&x)!=0)str="1"+str;
			else str="0"+str;
			p<<=1;
		}
		return str;
	}

	static boolean id1(Trie root,boolean t)
	{
		if(root==null)return true; 

		int cnt=0;
		for(Trie x:root.A)
		{
			if(x!=null)
			{
				cnt++;
				if(!id1(x,t^true)) 
				{
					

					return true;
				}
			}
		}
		if(cnt==0)return true;
		return false;
	}
	static boolean f(Trie root)
	{
		if(root==null)return false;		
		

		for(Trie x:root.A)
		{
			if(x!=null)
			{
				

				if(!f(x))
				{

					return true;
				}
			}
		}	
		return false;
	}
	static void insert(String X,Trie head)
	{
		Trie root=head;
		for(char x:X.toCharArray())
		{
			int a=x-'a';
			if(root.A[a]==null)root.A[a]=new Trie();
			root=root.A[a];
			root.ch=x;
		}
		root.ends=true;        
	}
	static boolean search(String X,Trie head)
	{
		Trie root=head;
		for(char x:X.toCharArray()) {
			int a=x-'a';
			if(root.A[a]==null)return false;
			root=root.A[a];
		}
		return root.ends;

	}
	static boolean starts_with(String X,Trie head)
	{
		Trie root=head;
		for(char x:X.toCharArray()) {
			int a=x-'a';
			if(root.A[a]==null)return false;
			root=root.A[a];
		}
		return true;
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
		seg[v]=seg[v*2]+seg[v*2+1];
	}
	static int ask(int v,int tl,int tr,int l,int r)
	{

		if(l>r)return 0;
		if(tl==l && tr==r)return seg[v];
		int tm=(tl+tr)/2;
		int a=ask(v*2,tl,tm,l,Math.min(tm, r));
		int b=ask(v*2+1,tm+1,tr,Math.max(l, tm+1),r);
		return a+b;
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
	static boolean id2(int A[])
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
	static boolean id0(int f[])
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

	static boolean id3(StringBuilder X,int i,long num)
	{
		long r=0;
		for(; i<X.length(); i++)
		{
			r=r*10+(X.charAt(i)-'0');
			r=r%num;
		}
		return r==0;
	}    



	static int id4(int A[],int low,int high, int x) 
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
			return id4( A, low, mid - 1, x); 

		return id4(A, mid + 1, high, x); 
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
	static void sort(char[] a) 

	{
		ArrayList<Character> l=new ArrayList<>();
		for (char i:a) l.add(i);
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
class edge1 implements Comparable<edge1>
{
	int a,b,c;
	edge1(int to,int wt)
	{
		a=to;
		c=wt;
	}
	edge1(int a,int b,int c)
	{
		this.a=a;
		this.b=b;
		this.c=c;
	}
	public int compareTo(edge1 x)
	{
		return this.c-x.c;
	}
}
class Trie
{
	char ch;
	Trie A[];
	boolean ends;
	Trie()
	{
		ch='*';
		A=new Trie[26];
		ends=false;
	}
}

class ram implements Comparable<ram>
{
	int a,b;
	ram(int i,int j)
	{
		a=i;
		b=j;
	}
	public int compareTo(ram x)
	{
		return this.a-x.a;
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