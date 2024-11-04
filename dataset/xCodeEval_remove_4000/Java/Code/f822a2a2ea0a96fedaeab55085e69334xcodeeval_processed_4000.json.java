

import java.awt.Point;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public  class point2 {
    

   public  static int[] S,a;
   public  static long[] sum;
   public  static long mod=1000000007;
   public  static int[][] dp;
   public  static boolean[][] id6;
   public  static int max1=5000+10;
   public  static int[][] g;
   public  static LinkedList<Pair> l[];
   public  static int n,m,q,k,t,b,c,di,dj,val[];
   public static ArrayList<Integer> adj[],al;
   public static TreeSet<Integer> ts;
   public  static   char[][] s;
   public  static int depth,mini,maxi;
   public  static long ans,V[],low,high;
   public  static boolean visit[][],isPrime[],used[];
   public  static int[][] dist;
   public static int[]prime=new int[1000005];
   public static ArrayList<Integer> divisor[]=new ArrayList[1500005];
   static  int[][] subtree;
   public static LongPoint[] p;
  public static void main(String[] args) throws Exception
   {
   	InputReader in = new InputReader(System.in);
    PrintWriter pw=new PrintWriter(System.out);
    n=in.ii();
    m=in.ii();
    ArrayList<Point> all=new ArrayList<>();
    
    for(int x=0;x<Math.min(4,n+1);x++)
    {
        for(int y=0;y<Math.min(4,m+1);y++)
        {
             int x1=x;
             int y1=y;
             int x2=n-x1;
             int y2=m-y1;

             all.add(new Point(x1,y1));
             all.add(new Point(x1,y2));
             all.add(new Point(x2,y2));
             all.add(new Point(x2,y1));
        }
    }
    double maxDist = 0;
    Point[] ans = null;

    for (Point p1 : all) {
        for (Point p2 : all) {
            for (Point p3 : all) {
                for (Point p4 : all) {
                    if (p1.compareTo(p2) == 0 || p1.compareTo(p3) == 0
                            || p1.compareTo(p4) == 0
                            || p2.compareTo(p3) == 0
                            || p2.compareTo(p4) == 0
                            || p3.compareTo(p4) == 0) {
                        continue;
                    }
                    double cand = p1.dist(p2) + p2.dist(p3) + p3.dist(p4);
                    if (cand > maxDist) {
                        maxDist = cand;
                        ans = new Point[] { p1, p2, p3, p4 };
                    }
                }
            }
        }
    }
 for(Point p:ans)
 {
     pw.println(p.x+" "+p.y);
 }
    
     
   	 pw.close();
   }
static class Point implements Comparable<Point>
{
    int x, y;
    public Point(int xx, int yy)
    {
        x = xx; y = yy;
    }
    long dist(Point p)
    {
        return ((long)x - p.x)*(x - p.x)+ ((long)y-p.y)*(y - p.y); 
    }
    @Override
    public int compareTo(Point o) {
        if (x != o.x) {
            return x < o.x ? -1 : 1;
        }
        return Integer.compare(y, o.y);
    }
}
public static long id5(Point[] p)
{
    int n=p.length;
    if(n<=1)return Long.MAX_VALUE;

    int mid=n>>1;
    Point[] left=new Point[mid];
    Point[] right=new Point[n-mid];
     
    for(int i=0;i<mid;i++)
    left[i]=p[i];

    for(int i=0,j=mid;j<n;j++,i++)
    {
        right[i]=p[j];
    }

     ans=Math.min(id5(left),id5(right));

     ArrayList<Point> al=new ArrayList<Point>();
     
     for(int i=mid;i>=0;i--)
     {
         if((p[mid].x-p[i].x)*1L*(p[mid].x-p[i].x)>ans)
         break;
         al.add(p[i]);
     }
     for(int i=mid+1;i<n;i++)
     {
         if((p[mid].x-p[i].x)*1L*(p[mid].x-p[i].x)>ans)
         break;
         al.add(p[i]);
     }

   Collections.sort(al,new id4());
  int size=al.size();

     for(int i=0;i<size;i++)
     {
         for(int j=i+1;j<size;j++)
         {
             int a=al.get(i).y;
             int b=al.get(j).y;

             if((a-b)*1L*(a-b)>ans)
             break;
             ans=Math.min(ans,id1(al.get(i), al.get(j)));
         }
     }

  return ans;

}

   static long id1(Point a,Point b){
    return (a.x - b.x) * 1L * (a.x - b.x) + (a.y - b.y) * 1L * (a.y - b.y);
    }
    static class id4 implements Comparator<Point>{
		public int compare(Point a,Point b){
			if(a.y != b.y)
				return Integer.compare(a.y, b.y);
			return Integer.compare(a.x,b.x);
		}
	}
   public static boolean intersect(Line a,Line b,boolean k)
   {
	   if(k)
	   {
		   return a.s.x==b.e.x||a.e.x==b.e.x;
	   }
	  else 
	  return a.s.y==b.e.y||a.e.y==b.e.y;

   }
  
    static class Line {
	Point s, e;

	Line(Point i, Point j) {
		s = i;
		e = j;
	}
}
  static class LongPoint {
        public long x;
        public long y;

        public LongPoint(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public LongPoint subtract(LongPoint o) {
            return new LongPoint(x - o.x, y - o.y);
        }

        public long cross(LongPoint o) {
            return x * o.y - y * o.x;
        }

    }
  static long crossProduct(LongPoint a,LongPoint b)
  {
      return a.x*b.y-a.y*b.x;
  }
  static boolean check2(LongPoint a,LongPoint b)
  {
       used=new boolean[n];
      LongPoint x=new LongPoint(b.x-a.x,b.y-a.y);
      for(int i=0;i<n;i++)
      {
          LongPoint y=new LongPoint(p[i].x-a.x,p[i].y-a.y);
          if(crossProduct(x,y)==0)
              used[i]=true;
      }
      return check();
  }
  static boolean check()
  {
      int i1=-1;
      int i2=-1;
      
      for(int i=0;i<n;i++)
      {
          if(used[i])continue;
          if(i1==-1)
              i1=i;
          else if(i2==-1)
              i2=i;
      }
      
      if(i2==-1)
          return true;
      LongPoint x=new LongPoint(p[i2].x-p[i1].x,p[i2].y-p[i1].y);
      for(int i=0;i<n;i++)
      {
          if(used[i])continue;
          LongPoint y=new LongPoint(p[i].x-p[i1].x,p[i].y-p[i1].y);
          
          if(crossProduct(x,y)!=0)
              return false;
          
      }
      return true;
  }
          
    static int CountPs(String s,int n)
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
	    		dp[i][i+1]=0;
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
	    		   
	    		   else if(!p[i][j]) dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
	    		  
	    		   

                             

	    	   }
	       }
	      
	   

    return dp[0][n-1];
	       
    }
  
  
  static void Seive()
  {
      isPrime=new boolean[1500005];
      Arrays.fill(isPrime,true);
     for(int i=0;i<1500005;i++){divisor[i]=new ArrayList<>();}
      for(int i=2;i<1500005;i++)
      {
          if(isPrime[i])
          {
              for(int j=i;j<1500005;j+=i)
              {
                  
                  divisor[j].add(i);
                  
                  isPrime[j]=false;
              }
         
              
          }
      }
      
  }
  static long id3(long a,long b)
  {
      return (a+b-1)/b;
  }
  static long root(int pow, long x) {
        long candidate = (long)Math.exp(Math.log(x)/pow);
        candidate = Math.max(1, candidate);
        while (pow(candidate, pow) <= x) {
            candidate++;
        }
        return candidate-1;
    }
    
    static long pow(long x, int pow)
    {
        long result = 1;
        long p = x;
        while (pow > 0) {
            if ((pow&1) == 1) {
                if (result > Long.MAX_VALUE/p) return Long.MAX_VALUE;
                result *= p;
            }
            pow >>>= 1;
            if (pow > 0 && p >= 4294967296L) return Long.MAX_VALUE;
            p *= p;
        }
        return result;
    }
  
  static boolean valid(int i,int j)
  {
	  if(i>=0&&i<n&&j>=0&&j<m)return true;
	  return false;
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
	private int u;
	private int v;
	private long w;
	public Edge() {
	}
	public Edge(int u, int v, long w) {
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
	public long getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	      }
	public long compareTo(Edge e)
	  {
		return (this.getW() - e.getW());
	}

        @Override
        public int compare(Edge o1, Edge o2) {
            throw new UnsupportedOperationException("Not supported yet."); 

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

	public int compareTo(Pair o) {
		

		if(this.a!=o.a)
		return -Integer.compare(this.a,o.a);
		else
			return -Integer.compare(this.b, o.b);
		

	}
	public boolean equals(Object o) {
       if (o instanceof Pair) {
           Pair p = (Pair)o;
           return p.a == a && p.b == b;
       }
       return false;
   }
   public int hashCode() {
       return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
   }
}

static  class InputReader
{
   private InputStream stream;
   private byte[] buf = new byte[1024];

   private id7 filter;
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
       while (id0(c))
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
       } while (!id0(c));
       return res * sgn;
   }

   String is() {
	        int b = skip();
	        StringBuilder sb = new StringBuilder();
	        while (!(id0(b))) 

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
   
	    boolean id0(int c) {
	        return (!(c >= 33 && c <= 126));
	       }

	      int skip()
	        {
	        int b;
	        while ((b = readByte()) != -1 && id0(b)) ;
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
       while (id0(c))
           c = read();
       StringBuilder res = new StringBuilder();
       do {
           res.appendCodePoint(c);
           c = read();
       } while (!id2(c));
       return res.toString();
   }

   public interface id7
   {
       public boolean id0(int ch);
   }
   public boolean id2(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}

}
