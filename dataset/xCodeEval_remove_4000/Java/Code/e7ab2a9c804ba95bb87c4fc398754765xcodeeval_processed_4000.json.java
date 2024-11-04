

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class id3 {



  static int[] A;
    static int[] S;
    static long[] sum;
    static boolean[] b;
   public static int mod=1000000007;
   static LinkedHashMap<Long,Long> memo;
  static int[][] g;
  static int[][] dp;
 

  

  static int n;
  public static int BIT[];
  public static void main(String[] args) throws Exception
   {
   	InputReader in = new InputReader(System.in);
   	PrintWriter out=new PrintWriter(System.out);
   	int n=in.ii();
   	int k=in.ii();
   	int[] a=in.iia(n);
   	if(k==1)
   	{
   		int ans=Integer.MAX_VALUE;
   		for(int i=0;i<n;i++)ans=Math.min(ans,a[i]);
   			out.println(ans);
   	}
   	else if(k>=3)
   	{
   		int ans=Integer.MIN_VALUE;
   		for(int i=0;i<n;i++)ans=Math.max(ans, a[i]);
   		out.println(ans);
   	}
   	else if(k==2)
   	{
   		out.println(Math.max(a[0], a[n-1]));
   	}
   	out.close();
   }
  public static void update(int x,int val,int n)
  {
	   for(;x<=n;x+=x&-x)
	   {
		   BIT[x]+=val;
	   }
	   
  }
 public static  int query(int x)
  {
       int sum = 0;
       for(; x > 0; x -= x&-x)
          sum += BIT[x];
       return sum;
  }

  static int bfs(int u,int v)
  {
	 boolean[]  visit=new boolean[n];
	  int[] d=new int[n];
	  Queue<Integer> q=new LinkedList<Integer>();
	  q.add(u);
	  visit[u]=true;
	  d[u]=0;
	  while(!q.isEmpty())
	  {
		  int x=q.poll();
		  for(int p:g[x])
		  {
			  if(visit[p])continue;
			  d[p]=d[x]+1;
			  visit[p]=true;
			  q.add(p);
		  }
	  }
	return d[v];  
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
   static int p(int n,int k)
   {
	   if(k<=0||n<=0)return 0;
	   if(n==k)return 1;
	   return p(n-k,k)+p(n-1,k-1);
   }
  static void su(int[] A)
  {
	  sum=new long[1000001];
	  for(int i=1;i<=A.length-1;i++)
	  {
		  sum[i]=sum[i-1]+A[i];
	  }
  }
  private  static long dist(int x1, int y1, int x2, int y2) {
      return (x2 - x1) * 1L * (x2 - x1) + (y2 - y1) * 1L * (y2 - y1);
  }

  private static boolean id1(int x1, int y1, int x2, int y2, int x3, int y3) {
      return (x1 * 1L * (y2 - y3) + x2 * 1L * (y3 - y1) + x3 * 1L * (y1 - y2)) == 0 ? true : false;
  }
  public static void Seive()
	{
		
		 b=new boolean[10000001];
		Arrays.fill(b, true);
		b[0]=false;
		b[1]=false;
		
		for(int i=2;i<=Math.sqrt(10000000);i++)
		{
			if(b[i])
			{
				
			 for(int j=i*2;j<=10000000;j+=i)
				{
					     b[j]=false;
					
				}
			}
			
		}
		

	}
  public static  long grundy(long a) {
      if (a <= 2) return a;
      boolean[] tmpArr = new boolean[35];
      Long tmp = memo.get(a);
      if (tmp != null) return tmp;
      for (int j = 0; j < 35; j++) {
          if (a < (1L << j)) break;
          long next = ((1L << j) - 1) & a;
          next |= a >>> (j + 1);
          tmpArr[(int) grundy(next)] = true;
      }
      for (int j = 0; j < 35; j++) {
          if (!tmpArr[j]) {
              memo.put(a, (long) j);
              return j;
          }
      }
      return 0;
  }
  
  public class id5 {
		
		int[] id4;
		int[] lowDiv;
		int[] p;
		int N;
		
		public id5(int N) {
			this.N = N;
			p = new int[(int)(N / Math.log(N))];
			id4 = new int[N + 1];
			lowDiv = new int[N + 1];
			Arrays.fill(id4, -1);
			int pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (id4[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					id4[i] = pCnt;
					lowDiv[i] = i;
					p[pCnt++] = i;	
				}
				int toJ = Math.min(pCnt, id4[i] + 1);
				for (int j = 0; j < toJ; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					id4[x] = j;
					lowDiv[x] = p[j];
				}
			}
			p = Arrays.copyOf(p, pCnt); 
		}
		
		int[] divCount() {
			int[] ret = new int[N + 1];
			int[] tmp = new int[N + 1];
			ret[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p == lowDiv[j]) {
					int k = tmp[j];
					ret[i] = ret[j] / k * (k + 1);
					tmp[i] = k + 1;
				} else {
					ret[i] = ret[j] * 2;
					tmp[i] = 2;
				}
			}
			return ret;
		}
		
		List<Integer> id2(int x) {
			List<Integer> ret = new ArrayList<Integer>(0);
			ret.add(1);
			while (x > 1) {
				int sz = ret.size();
				int pr = lowDiv[x];
				while (lowDiv[x] == pr) {
					int to = ret.size();
					for (int i = ret.size() - sz; i < to; i++) {
						ret.add(ret.get(i) * pr);
					}
					x /= pr;
				}
			}
			return ret;
		}

		int[] id8() {
			int[] mu = new int[N + 1];
			mu[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p != lowDiv[j]) {
					mu[i] = -mu[j];
				}
			}
			return mu;
		}

		int[] id9() {
			int[] phi = new int[N + 1];
			phi[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				phi[i] = phi[j] * (p != lowDiv[j] ? p - 1 : p);
			}
			return phi;
		}
	}

  public static int id7(int a,int b)
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


public static int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
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


static class Edge implements Comparator<Edge> {
	private int u;
	private int v;
	private int w;
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
	public int compare(Edge o1, Edge o2)
	  {
		return o2.getW() - o1.getW();
	}
	@Override
	public String toString() {
		return "Edge [u=" + u + ", v=" + v + ", w=" + w + "]";
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

   private id10 filter;
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
	        long a[] = new long[n+1];
	        for (int i = 1; i <=n; i++) a[i] = il();
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
       } while (!id6(c));
       return res.toString();
   }

   public interface id10
   {
       public boolean id0(int ch);
   }
   public boolean id6(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}

}
