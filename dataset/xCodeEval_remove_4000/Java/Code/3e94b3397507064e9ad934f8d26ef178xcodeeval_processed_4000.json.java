

import java.io.*;
import java.util.*;

public class id1 {

    
	   static final int MAX1 = 1000000+10;
	   static final int MAX2 = 1000001;
	   static final long MOD = 1000000007;
	   static int phiSum[] = new int[MAX1];
	   static int phi[] = new int[MAX1];
	   static long[] res=new long[MAX1];
	   static int arr[];
	   static long BIT[];
	   static int n,m,k;
	   static boolean[] b;
	   static int[][] pascal;
           static long[][] dp;
           static boolean[] visit;
           static LinkedList<Integer> list[];
           static LinkedList<Integer> l;
           static TreeSet<Integer> ts;
           static int[][] g;
           static int[] size;
	    public static void main(String[] args) throws IOException{
	       
	        InputReader in = new InputReader(System.in);
               

	        PrintWriter pw = new PrintWriter(System.out,true);
               
                n=in.ii();
                m=in.ii();
                k=in.ii();
              arr=new int[k];
              for(int i=0;i<k;i++)arr[i]=in.ii()-1;
              DSU dsu=new DSU(n);
              for(int i=0;i<m;i++)
              {
              int u=in.ii()-1;
              int v=in.ii()-1;
              dsu.unite(u, v);
              }
              int iso=0;
              for(int i=0;i<n;i++)
              {
                 boolean is=true;
                 for(int j=0;j<k;j++)
                 {
                  if(dsu.same(i, arr[j])||i==arr[j])
                  {
                    is=false; break;
                  }
                 }
              if(is)iso++;
              }
             

             int[] size = new int[k];
		for (int i = 0; i < k; i++) {
			size[i] = dsu.getSize(arr[i]);
		}
		Arrays.sort(size);
		size[k-1] += iso;
		
		long res = 0;
		for (int i = 0; i < k; i++) 
                {
			res += ((long)(size[i] - 1) * size[i]) / 2;
		}
                pw.println(res-m);
               

	      pw.close();
	    }
        static   class DSU {
		int[] parent;
		int[] size;
		
		public DSU(int n) {
			parent = new int[n];
			size = new int[n];
			init();
		}
		
		public void init() {
			for (int i = 0; i < parent.length; i++) {
				parent[i] = i;
				size[i] = 1;
			}
		}
		
		public int find(int x) {
			if (parent[x] == x) return x;
			return parent[x] = find(parent[x]);
		}
		
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		
		public void unite(int x, int y) {
			int xx = find(x), yy = find(y);
			if (xx == yy) return;
			parent[xx] = yy;
			size[yy] += size[xx];
		}

		public int getSize(int x) {
			return size[find(x)];
		}
		
		public String toString() {
			String res = "";
			res += Arrays.toString(parent) + "\n";
			res += Arrays.toString(size);
			return res;
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
    boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
        {
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) 
                        {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        }
        return false;
     }

	    public static long nCr(long total, long choose)
		{
			if(total < choose)
				return 0;
			if(choose == 0 || choose == total)
				return 1;
			return nCr(total-1,choose-1)+nCr(total-1,choose);
		}
	    static void compute() {
	    		for (int i = 0; i < MAX1; i++) {
	    			phi[i] = 0;
	    		}
	          phi[1]=1;
	    		for (int i = 2; i < MAX1; i++) {
	    			if (phi[i] == 0) {
	    				phi[i] = i - 1;
	     
	    				for (int j = 2 * i; j < MAX1; j += i) {
	    					 if(phi[j]==0) phi[j] = j ;
	    					phi[j] -= (phi[j]/i);
	    				}
	    			}
	    		}
	     
	    		for (int i = 1; i < MAX1; i++) {
	    			for (int j = i, k = 1; j < MAX1; j += i,k++) {
	    				phiSum[j] += i * phi[k];
	    			}
	    		}
	    		

                
	    		
	    		for(int i=1;i<MAX1;i++)
	    		{
	    			for(int j=i+i;j<MAX1;j+=i)
	    			{
	    			   res[j]=res[j]+1L*i*phi[j/i];
	    			}
	    		}
	    		for(int i=1;i<=1000000;i++)
	    			res[i]=res[i]+res[i-1];
	    	

	    						
	    		
	    		
	    }
	    public static void Seive()
		{
			l=new LinkedList<>();
			 b=new boolean[80001];
			Arrays.fill(b, true);
			b[0]=false;
			b[1]=false;
			
			for(int i=2;i<=(80000);i++)
			{
				if(b[i])
				{
					l.add(i);
				 for(int j=i*2;j<=80000;j+=i)
					{
						     b[j]=false;
						
					}
				}
				
			}
			
		}
	    static int pascal(int i1,int j1)
	    {
	  	  pascal=new int[101][101];
	  	  for(int i=0;i<=100;i++)
	  	  {
	  		  pascal[i][0]=1;
	  		  for(int j=1;j<=i;j++)
	  		  {
	  			  pascal[i][j]=(int) ((pascal[i-1][j]+pascal[i-1][j-1])%MOD);
	  		  }
	  	  }
	  	  return pascal[i1][j1];
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
		public int compareTo(Edge e)
		  {
			return this.getW() - e.getW();
		}
		@Override
		public String toString() {
			return "Edge [u=" + u + ", v=" + v + ", w=" + w + "]";
		}
		@Override
		public int compare(Edge arg0, Edge arg1) {
			

			return 0;
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
	 
		static class InputReader
		{
			private InputStream stream;
			private byte[] buf = new byte[1024];
			private int curChar;
			private int numChars;
			private id2 filter;
			
			public InputReader(InputStream stream)
			{
				this.stream = stream;
			}
			
			public int read()
			{
				if (numChars==-1) 
					throw new InputMismatchException();
				
				if (curChar >= numChars)
				{
					curChar = 0;
					try 
					{
						numChars = stream.read(buf);
					}
					catch (IOException e)
					{
						throw new InputMismatchException();
					}
					
					if(numChars <= 0)				
						return -1;
				}
				return buf[curChar++];
			}
		 
			public String nextLine()
			{
				BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
				String str = "";
	            try
	            {
	                str = br.readLine();
	            }
	            catch (IOException e)
	            {
	                e.printStackTrace();
	            }
	            return str;
			}
			public int ii()
			{
				int c = read();
				
				while(id0(c)) 
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
					if(c<'0'||c>'9') 
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				while (!id0(c)); 
				
				return res * sgn;
			}
			
			public long il() 
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
				long res = 0;
				
				do 
				{
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				while (!id0(c));
					return res * sgn;
			}
			
			public double nextDouble() 
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
				double res = 0;
				while (!id0(c) && c != '.') 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, ii());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = read();
				}
				if (c == '.') 
				{
					c = read();
					double m = 1;
					while (!id0(c)) 
					{
						if (c == 'e' || c == 'E')
							return res * Math.pow(10, ii());
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						m /= 10;
						res += (c - '0') * m;
						c = read();
					}
				}
				return res * sgn;
			}
			
			public String readString() 
			{
				int c = read();
				while (id0(c))
					c = read();
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = read();
				} 
				while (!id0(c));
				
				return res.toString();
			}
		 
			public boolean id0(int c) 
			{
				if (filter != null)
					return filter.id0(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
		 
			public String next() 
			{
				return readString();
			}
			
			public interface id2 
			{
				public boolean id0(int ch);
			}
		}
	}
