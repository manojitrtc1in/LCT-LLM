


import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

 public class ANUMLA {
  
    static int[] a;
   
    static long[] sum;
   public static int mod=1000000007;
   static int[][] dp;
   static boolean[][] isPalin;
   static int max1=5000+10;
   static int[][] g;
   static int ver;
   static int n,k,m,x;
   static boolean[] visit,isprime;
   static LinkedList<Pair> l[];
   static int ans=0,max_len=8;
   static int[] color,log,st[],lpf;
   static String[] S;static TreeSet<Integer> ts;
   static LinkedList<Integer> al[];
  public static void main(String[] args) throws Exception
   {
   	InputReader in = new InputReader(System.in);
       

     

   	PrintWriter pw=new PrintWriter(System.out);
      n=in.ii();
      a=in.iia(n);
      char[] s=in.is().toCharArray();
      boolean b=true;
      int mx=0;
      for(int i=0;i<n-1;i++)
      {
        mx=Math.max(mx,a[i]);
        if(s[i]=='0'&&mx!=i+1)
        {
          b=false; break;
        }
      }
      pw.println(b==true?"YES":"NO");
      
   	pw.close();
   }
public static double calculateAngle(double x1, double y1, double x2, double y2)
{
    double angle = Math.toDegrees(Math.atan2(x2 - x1, y2 - y1));
    

    angle = angle + Math.ceil( -angle / 360 ) * 360;

    return angle;
}
static void seive()
{
    isprime=new boolean[1000005];
    Arrays.fill(isprime, true);
    isprime[0]=false;
    isprime[1]=false;
    lpf=new int[1000005];
    for(int i=1;i<=1000000;i++)lpf[i]=i;
   
    for(int i=2;i<=1000;i++)
    {
      if(lpf[i]!=i)continue;
      int j=i+i;
      while(j<=1000000)
      {
        lpf[j]=i;
        j+=i;
      }
      
    }
  
}
  static BigInteger power(BigInteger x, BigInteger y, BigInteger m)
			{
			    if (y.equals(new BigInteger("0")))
			        return (new BigInteger("1"));
			    BigInteger p = power(x, y.divide(new BigInteger("2")), m).mod(m);
			    p = (p.multiply(p)).mod(m);

			    return (y.mod(new BigInteger("2")).equals(new BigInteger("0")))? p : (p.multiply(x)).mod(m);
		        }

  static char[][] trans(char[][] s)
  {
    int n=s.length;
    int m=s[0].length;
   char[][] trans=new char[m][n];
    for(int i=0;i<m;i++)
    {
     for(int j=0;j<n;j++)
     {
       trans[i][j]=s[j][i];
     }
    }
  return trans;
  }
  public static String toBase26(int n)
  {
		StringBuffer ret = new StringBuffer();
		while(n>0)
                {
			--n;
			ret.append((char)('A' + n%26));
			n/=26;
		}
		return ret.reverse().toString();
	}
  static int get(int a,int b,int c)
  {
    int j=0;
    int i=0;
    int cnt=0;
    while(true)
    {
        if(i==c||j==c)return cnt;
       if(i==0)
       {
         i=a;
         cnt++;
         continue;
       }
       if(j==b)
       {
         j=0;
        cnt++;
        continue;
       }
       if(i!=0)
       {
        int temp=i;
        i=Math.max(0,i-(b-j));
        j=Math.min(b,temp+j);
        cnt++;
        continue;
       }
        
    }
    

  }
 static void log()
 {
   log[1]=0;
   for(int i=2;i<=n;i++)
   {
    log[i]=log[i/2]+1;
   }
 }

  private static class DSU{
		int[] parent;
		int[] rank;
		int cnt;
		public DSU(int n){
			parent=new int[n];
			rank=new int[n];
			for(int i=0;i<n;i++){
				parent[i]=i;
				rank[i]=1;
			}
			cnt=n;
		}
		int find(int i){
	        while(parent[i] !=i){
	        	parent[i]=parent[parent[i]];
	        	i=parent[i];
	        }
	        return i;
	    }
		int Union(int x, int y){
	        int xset = find(x);
	        int yset = find(y);
	        if(xset!=yset)
	        	cnt--;
	        if(rank[xset]<rank[yset]){
	        	parent[xset] = yset;
		        rank[yset]+=rank[xset];
		        rank[xset]=0;
		        return yset;
	        }else{
	        	parent[yset]=xset;
	        	rank[xset]+=rank[yset];
	        	rank[yset]=0;
	        	return xset;
	        }
	    }
	}
  public static int[][] packU(int n, int[] from, int[] to, int max) {
	    
	    int[][] g = new int[n][];
	    int[] p = new int[n];
	    for (int i = 0; i < max; i++) p[from[i]]++;
	    for (int i = 0; i < max; i++) p[to[i]]++;
	    for (int i = 0; i < n; i++) g[i] = new int[p[i]];
	    for (int i = 0; i < max; i++) {
	        g[from[i]][--p[from[i]]] = to[i];
	        g[to[i]][--p[to[i]]] = from[i];
	    }
	    return g;
	}
	public static int[][] parents3(int[][] g, int root) {
	    int n = g.length;
	    int[] par = new int[n];
	    Arrays.fill(par, -1);
 
	    int[] depth = new int[n];
	    depth[0] = 0;
 
	    int[] q = new int[n];
	    q[0] = root;
	    for (int p = 0, r = 1; p < r; p++) {
	        int cur = q[p];
	        for (int nex : g[cur]) {
	            if (par[cur] != nex) {
	                q[r++] = nex;
	                par[nex] = cur;
	                depth[nex] = depth[cur] + 1;
	            }
	        }
	    }
	    return new int[][]{par, q, depth};
	}
	public static int lower_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low] == target ? low : -1;
    }
 
    public static int upper_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high + 1 - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid;
        }
        return nums[low] == target ? low : -1;
    }
  public static boolean palin(String s)
	{
	   int i=0;
	   int j=s.length()-1;
	   while(i<j)
	   {
		   if(s.charAt(i)==s.charAt(j))
		   {
			   i++;
			   j--;
		   }
		   else return false;     
	   }
	   return true;
	}
	
    static boolean CountPs(String s,int n)
       {
    	boolean b=false;
    	     char[] S=s.toCharArray();
	       int[][] dp=new int[n][n];
	       boolean[][] p=new boolean[n][n];
	       for(int i=0;i<n;i++)p[i][i]=true;
	     
	       for(int i=0;i<n-1;i++)
	       {
	    	   if(S[i]==S[i+1])
	    	   {
	    		p[i][i+1]=true;
	    		dp[i][i+1]=1;
	    		b=true;
	    	   }
	       }
	    
	       for(int gap=2;gap<n;gap++)
	       {
	    	   for(int i=0;i<n-gap;i++)
	    	   {
	    		   int j=gap+i;
	    		   if(S[i]==S[j]&&p[i+1][j-1]){p[i][j]=true;}
	    		  
	    		  if(p[i][j])
	    			   dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
	    		   
	    		   else  dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
	    		  
	    		   if(dp[i][j]>=1){b=true;}
	    	   }
	       }
	      
	    return b; 
   

	       
    }
  
  
  
 
 
public static int gcd(int a,int b)
{
	int res=1;
	while(a>0)
	{
		res=a;
		a=b%a;
		b=res;
	}
	return res;
}
 
 
public static long pow(long n,long p,long m)
{
	 long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    if(result>=m)
	    result%=m;
	    p >>=1;
	    n*=n;
	    if(n>=m)
	    n%=m;
	}
	return result;
}
public static long pow(long n,long p)
{
	long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    p >>=1;
	    n*=n;
	}
	return result;
 
}
 
 
 
 
static class Edge implements Comparator<Edge> {
	public int u;
	public int v;
	public int w;
	public Edge() {
	}
	public Edge(int u, int v, int w) {
		this.u=u;
		this.v=v;
		this.w=w;
	}
	public int getU() {
		return u;
	}
	public void setU(int u) {
		this.u = u;
	}
	public int getV() {
		return v;
	}
	public void setV(int v) {
		this.v = v;
	}
	public int getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	      }
	
	@Override
	public int compare(Edge e1, Edge e2) {
		return  e2.w-e1.w;
	}
}
 
 
 
static class Pair implements Comparable<Pair>
{
	int a,b;
	Pair (int a,int b)
	{
		this.a=a;
		this.b=b;
	}

        @Override
        public int compareTo(Pair o) {
            

          
           return this.b-o.b;
        }
 
}
 
static  class InputReader
{
   private InputStream stream;
   private byte[] buf = new byte[1024];
 
   private SpaceCharFilter filter;
    byte inbuffer[] = new byte[1024];
   int lenbuffer = 0, ptrbuffer = 0;
    final int M = (int) 1e9 + 7;
   int md=(int)(1e7+1);
    int[] SMP=new int[md];
   final double eps = 1e-6;
   final double pi = Math.PI;
 
	PrintWriter out;
   String check = "";
 InputStream   obj = check.isEmpty() ? System.in : new ByteArrayInputStream(check.getBytes());
   public InputReader(InputStream stream)
   {
       this.stream = stream;
   }
 
    int readByte() {
	        if (lenbuffer == -1) throw new InputMismatchException();
	        if (ptrbuffer >= lenbuffer) {
	            ptrbuffer = 0;
	            try {
	                lenbuffer = obj.read(inbuffer);
	            } catch (IOException e) {
	                throw new InputMismatchException();
	            }
	        }
	        if (lenbuffer <= 0) return -1;
	        return inbuffer[ptrbuffer++];
   }
 
   public  int read()
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
 
   String is() {
	        int b = skip();
	        StringBuilder sb = new StringBuilder();
	        while (!(isSpaceChar(b))) 

	        {
	            sb.appendCodePoint(b);
	            b = readByte();
	        }
	        return sb.toString();
   }
   public   int ii() {
	        int num = 0, b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
 public   long il() {
	        long num = 0;
	        int b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
   
	    boolean isSpaceChar(int c) {
	        return (!(c >= 33 && c <= 126));
	       }
 
	      int skip()
	        {
	        int b;
	        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
	        return b;
	        }
 
	    float nf() {
	        return Float.parseFloat(is());
	    }
 
	    double id() {
	        return Double.parseDouble(is());
	    }
 
	    char ic() {
	        return (char) skip();
	    }
 
	    int[] iia(int n) {
	        int a[] = new int[n];
	        for (int i = 0; i<n; i++) a[i] = ii();
	        return a;
	    }
 
	    long[] ila(int n) {
	        long a[] = new long[n];
	        for (int i = 0; i <n; i++) a[i] = il();
	        return a;
	    }
 
	    String[] isa(int n) {
	        String a[] = new String[n];
	        for (int i = 0; i < n; i++) a[i] = is();
	        return a;
	    }
 
 
		 long mul(long a, long b) { return a * b % M; }
 
			long div(long a, long b)
				 {
					return mul(a, pow(b, M - 2));
 
		           }
 
 
 
	    double[][] idm(int n, int m) {
	        double a[][] = new double[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = id();
	        return a;
	        }
 
	    int[][] iim(int n, int m) {
	        int a[][] = new int[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j <m; j++) a[i][j] = ii();
	        return a;
          }
 
 
   public String readLine() {
       int c = read();
       while (isSpaceChar(c))
           c = read();
       StringBuilder res = new StringBuilder();
       do {
           res.appendCodePoint(c);
           c = read();
       } while (!isEndOfLine(c));
       return res.toString();
   }
 
   public interface SpaceCharFilter
   {
       public boolean isSpaceChar(int ch);
   }
   public boolean isEndOfLine(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}
 
}
 