import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class MainA
{
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	private static long mod = 1000000000 + 7;
	static double ans=0;
	public static double dfs(int visited[],ArrayList<Integer> adj[],int v)
	{
		visited[v]=1;int count=0;double tem=0;
		for(int i=0;i<adj[v].size();i++)
		{
			if(visited[adj[v].get(i)]==0)
			{
				double d=dfs(visited,adj,adj[v].get(i));
				count++;
				tem+=d+1;
			}
		}
		
		double var=0;
		if(count!=0)var=tem/count;
		

		ans=ans+var;
		return var;
		
	}
	
	public static int find(Pair subsets[], int i)
	{
	    

	    if (subsets[i].x != i)
	        subsets[i].x = find(subsets, subsets[i].x);
	 
	    return subsets[i].x;
	}
	 
	

	

	public static void Union(Pair subsets[], int x, int y)
	{
	    int xroot = find(subsets, x);
	    int yroot = find(subsets, y);
	 
	    

	    

	    if (subsets[xroot].y < subsets[yroot].y)
	        subsets[xroot].x = yroot;
	    else if (subsets[xroot].y> subsets[yroot].y)
	        subsets[yroot].x = xroot;
	 
	    

	    

	    else
	    {
	        subsets[yroot].x = xroot;
	        subsets[xroot].y++;
	    }
	}
	 
	

	public static int isCycle(int v1, int e1,String s1,String s2)
	{
	    int V = v1;
	    int E = e1;
	 
	    

	    Pair subsets[]=new Pair[V];
	 
	    for (int v = 0; v < V; ++v)
	    {
	    	subsets[v]=new Pair(v,0);
	        
	    }
	 
	    

	    

	    

	    int count=0;
	    ArrayList<String> arr=new ArrayList();
	    for(int e = 0; e < E; ++e)
	    {
	        int x = find(subsets, s1.charAt(e)-'a');
	        int y = find(subsets, s2.charAt(e)-'a');
	 
	        if (x != y)
	        {  
	        	count++;
	        	arr.add(s1.charAt(e)+" "+s2.charAt(e));
	        	Union(subsets, x, y);
	        }
	    }
	    pw.println(count);
	    for(int i=0;i<count;i++)
	    {
	    	pw.println(arr.get(i));
	    }
	    return 0;
	}
	 
	private static void soln()
	{
		int n=nextInt();
		int a=nextInt();
		int b=nextInt();
		
		for(int i=0;i<=n/a;i++)
		{
			double tem=(double)(n-a*i)/b;
			if(tem==Math.ceil(tem))
			{
				int te=(int)tem;int start=1;
				for(int j=1;j<=i;j++,start+=a)
				{
					for(int k=start+1;k<start+a;k++)
					{
						pw.print(k+" ");
					}
					pw.print(start+" ");
				}
				for(int j=0;j<te;j++,start+=b)
				{
					for(int k=start+1;k<start+b;k++)
					{
						pw.print(k+" ");
					}
					pw.print(start+" ");
				}
				return;
			}
		}
		
		pw.println(-1);
	}
	public static double teSe(int n,double a[],double max,double pr[])
	{
		int l=0;int r=n-2;double result=0;
		if(n==1)
		{
			return pr[0];
		}
		double f1=0,f2=0;
		while(r >= l)
		{
		        int mid1 = l+(r-l)/3;
		        int mid2 = r-(r-l)/3;
		        f1=(pr[mid1]+max)/(mid1+2);
		        f2=(pr[mid2]+max)/(mid2+2);
		        

		        if (f1<=f2) {r=mid2-1;}
		        else {l=mid1+1;}	        
		 }
		return Math.min(f1,f2);
	}

	static class Pair implements Comparable<Pair>
    {

        int x,y,i;
        
        Pair (int x, int y)
        {
        		this.x = x;
                this.y = y;
                
        }
	
	public int compareTo(Pair o) {
                return -Integer.compare(this.y,o.y);
	}

        public boolean equals(Object o)
        {
            if (o instanceof Pair)
            {
                Pair p = (Pair)o;
                return p.x == x && p.y==y;
            }
            return false;
        }

        @Override
        public String toString()
        {
            return x + " "+ y;
        }
        
        public int hashCode()
        {
            return new Long(x).hashCode() * 31 + new Long(y).hashCode();
        }
    
    } 

	
	public static int biSe(int x,int n)
	{
		int y=n*n-x;
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			

			if(f(mid,n)==y)
			{
				return mid;
			}
			else if(f(mid,n)<y)
			{
				r=mid-1;
			}
			else l=mid+1;
		}
		return -1;
	}
	
	public static int f(int x,int n)
	{
		return (n/x)*(n/x);
	}
	public static class Segment 
	{
		private int[] tree;
		private boolean[] lazy;
		private int size;
		private int n;
		private class node
		{
			private int a;
			private int b;
			private int c;
			public node(int x,int y,int z)
			{
				a=x;
				b=y;
				c=z;
			}
		}
		public Segment(int n)
		{
			

			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
	        size = 2 * (int) Math.pow(2, x) - 1;
			tree=new int[size];
			lazy=new boolean[size];
			this.n=n;
			build(0,0,n-1);
		}
		public void build(int id,int l,int r)
		{
			if(l==r)
			{
				return;
			}
			int mid=(l+r)/2;
			build(2*id+1,l,mid);
			build(2*id+2,mid+1,r);
			tree[id]=tree[2*id+1]+tree[2*id+2];
		}
		public int query(int l,int r)
		{
			return queryUtil(l,r,0,0,n-1);
		}
		private int queryUtil(int x,int y,int id,int l,int r)
		{
			if(l>y || x>r) 
				return 0;
			if(x <= l && r<=y) 
			{
				

					return tree[id];
				

				

			}
			int mid=l+(r-l)/2;
			shift(id);
			return queryUtil(x,y,2*id+1,l,mid)+queryUtil(x,y,2*id+2,mid+1,r);
		}
		public void update(int x,int y,int colour,int id,int l,int r)
		{
			

			if(x>r || y<l)
				return;
			if(x <= l && r<=y)
			{
				
				return;
			}
			int mid=l+(r-l)/2;
			shift(id);
			update(x,y,colour,2*id+1,l,mid);
			update(x,y,colour,2*id+2,mid+1,r);
			tree[id]=tree[2*id+1]+tree[2*id+2];
		}
		public void shift(int id)
		{
			
		}
	}

	public static void fft(double[] a, double[] b, boolean invert)
	{
		int count = a.length;
		for (int i = 1, j = 0; i < count; i++) {
			int bit = count >> 1;
			for (; j >= bit; bit >>= 1) j -= bit;
			j += bit;
			if (i < j) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
		for (int len = 2; len <= count; len <<= 1) {
			int halfLen = len >> 1;
			double angle = 2 * Math.PI / len;
			if (invert) angle = -angle;
			double wLenA = Math.cos(angle), wLenB = Math.sin(angle);
			for (int i = 0; i < count; i += len) {
				double wA = 1, wB = 0;
				for (int j = 0; j < halfLen; j++) {
					double uA = a[i + j], uB = b[i + j];
					double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
					double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
					a[i + j] = uA + vA;
					b[i + j] = uB + vB;
					a[i + j + halfLen] = uA - vA;
					b[i + j + halfLen] = uB - vB;
					double nextWA = wA * wLenA - wB * wLenB;
					wB = wA * wLenB + wB * wLenA;
					wA = nextWA;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < count; i++) {
				a[i] /= count;
				b[i] /= count;
			}
		}
	}
	static void multiply(long[][] a, long[][] b, long m)
	{
		int n = a.length;
		long[][] mul = new long[n][n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mul[i][j] = 0;
				for (int k = 0; k < n; k++)
					mul[i][j] = (mul[i][j] + (a[i][k] * b[k][j]) % m) % m;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = mul[i][j];
	}

	private static long pow(long a, long b, long c)
	{
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}

	private static long gcd(long n, long l)
	{
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}
	public static void main(String[] args) throws Exception
	{










































		
		
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		
		soln();
		pw.close();
	}

	public static void InputReader(InputStream stream1)
	{
		stream = stream1;
	}

	private static boolean isWhitespace(int c)
	{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean isEndOfLine(int c)
	{
		return c == '\n' || c == '\r' || c == -1;
	}

	private static int read()
	{
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars)
		{
			curChar = 0;
			try
			{
				numChars = stream.read(buf);
			} catch (IOException e)
			{
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	private static int nextInt()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-')
		{
			sgn = -1;
			c = read();
		}
		int res = 0;
		do
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static long nextLong()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-')
		{
			sgn = -1;
			c = read();
		}
		long res = 0;
		do
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static String nextToken()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private static String nextLine()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}

	private static int[] nextIntArray(int n)
	{
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextInt();
		}
		return arr;
	}

	private static long[] nextLongArray(int n)
	{
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean isSpaceChar(int c)
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	private static char nextChar()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		char c1 = (char) c;
		while (!isSpaceChar(c))
			c = read();
		return c1;
	}

	private interface SpaceCharFilter
	{
		public boolean isSpaceChar(int ch);
	}
}