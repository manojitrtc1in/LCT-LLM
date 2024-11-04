import java.util.*;
import java.io.*;
public class Test {
	public static void main(String[] args) throws IOException {
	   Scanner sc = new Scanner(System.in);
	   PrintWriter pw = new PrintWriter(System.out);
	   int t = sc.nextInt();
	    fact = new long [(int)(2*1e5)+7] ;
	     mod = 998244353;
	    fact[0] = 1;
	    fact [1]= 1;
	    for (int i = 2;i<fact.length;i++) {
	    	fact[i] = ((i)*fact[i-1])%mod;
	    }
	   while(t-->0) {
		   int n = sc.nextInt();
		   Long [] arr =new Long[n];
		   for(int i = 0;i<n;i++) {
			   arr[i] = sc.nextLong();
		   }
		   Arrays.sort(arr);
		   boolean can = true;
		   int numOfsecLargest = 0;
		   int numOfLargest = 0;
		   if(arr[n-1]-arr[n-2]>1) {
			   can = false;
		   }
		   long max = arr[n-1];
			  

			   for (int i = n-1;i>=0;i-- ) {
				  if (arr[i]==max) {
					  numOfLargest++;
				  }
				  else if (arr[i]==max-1) {
					  numOfsecLargest++;
				  }
			   }
			   if (!can) {
				   System.out.println(0);
			   }
			   else {
				   long ans = 0;
				   if (numOfLargest>1) {
					   System.out.println(fact[n]);
				   }
				   else {
					   

					   int rest = n-1-numOfsecLargest;
					   
					   for (int i = numOfsecLargest;i<n;i++) {
						   long sub = fact[n-1-i];
						  

						   sub = (sub * nCrModPFermat(rest, i-numOfsecLargest,mod))%mod;
						   sub = (sub *fact[i]*1l)%mod;
						   ans = (ans +sub)%mod;
						  

					   }
					  
					   ans = ((fact[n] -ans)%mod+mod)%mod;
					   System.out.println(ans);
				   }
			   }
			   
		   
		  

	   }
	
	     
	  }
	static long nCrModPFermat(int n, int r,
            long p) {

if (n < r)
 return 0;


if (r == 0)
 return 1;







return (fact[n] * modInverse(fact[r], p)
     % p * modInverse(fact[n - r], p)
     % p)
     % p;
}
	static int numOfSubArrays (int [] nums) {
		 int n = nums.length;
		 int ans = 0;
		for(int i = 0;i<n;i++) {
			

			HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
			hm.put(nums[i], 1);
			int count = 1;
			for(int j = i+1;j<n;j++) {
				if (!hm.containsKey(nums[j])) {
					count ++;
					hm.put(nums[j],1);
				}
				else if (hm.get(nums[j])==1) {
					count --;
					hm.remove(nums[j]);
					hm.put(nums[j],2);
				}
				if (count == 0) {
					ans++;
				}
			}
		}
		return ans;
	}
	static void bfs(int s) {
		
	    parent[s]=-1;
	    Queue<Integer> q = new LinkedList<Integer>();
		q.add(s);
		visited[s] = true;
		while(!q.isEmpty()) {
			int u = q.poll();
			
			

			for(int v : adjList[u]) {
				


				if(!visited[v]) {
					q.add(v);
					parent[v] = u;
					distance[v] = 1+distance[u];
					visited[v]=true;
					if(v==n-1) {
						return;
					}
				}
				
			}}
		
		
		
		

		
	}static ArrayList<Integer> ans;
	static int d1;
		   static class triple {
	            int u;
	            int v;
	            int z;
	 
	            public triple(int u, int v, int z) {
	                this.u = u;
	                this.v = v;
	                this.z = z;
	            }
	 
	            public String toString() {
	                return "triple{" +
	                        "u=" + u +
	                        ", v=" + v +
	                        ", z=" + z +
	                        '}';
	            }
	 
	            public boolean equals(Object o) {
	                if (this == o) return true;
	                if (o == null || getClass() != o.getClass()) return false;
	                triple triple = (triple) o;
	                return u == triple.u &&
	                        v == triple.v &&
	                        z == triple.z;
	            }
	 
	            public int hashCode() {
	                return Objects.hash(u, v, z);
	            }}
	 

	static int [] distance; 
	static  ArrayList<Integer> [] adjList ;
	
	static HashMap<Pair,Integer> hm;
	static boolean [] visited;
	static int [] parent;
	public static boolean check (int a) {
		if(a==2) {
			return true;
		}
		ArrayList <Integer> indices = new ArrayList<Integer>();
		for (int i = 0;i<arr.length;i++) {
			if (arr[i] <= a) {
				indices.add(i);
			}}
		boolean first = false;
		ArrayList<Integer> jumps = new ArrayList<Integer>();
		for(int i = 0;i<indices.size()-1;i++) {
			

			if (indices.get(i+1)-indices.get(i)>1) {
				jumps.add(indices.get(i+1)-indices.get(i));
				
				
			}
		}
		
		if (jumps.size()==0||(jumps.size()==2&&jumps.get(0)==2)||(jumps.size()==2&&jumps.get(1)==2)||(jumps.size()==1&&jumps.get(0)==2)||(jumps.size()==1&&a==3)){
			return true;
		}
		else {
			return false;
		}
		
			
	}
	static class Edge {
		int u ;
		int v ;
		boolean visited = false;
		ArrayList<Edge> adjList;
		public Edge  (int u , int v) {
			this.u = u;
			this.v = v;
			this.adjList = new ArrayList<Edge>();
		}
		public void add(Edge e) {
			this.adjList.add(e);
		}
	}
	static int [] arr;
	static long mod;
	public static double solve(int currTrial, int lampsMask) {
		if(lampsMask ==0 || currTrial==101) {
			return (currTrial-1);
		}
		if(dp[currTrial][lampsMask]!=-1) {
			return dp[currTrial][lampsMask];
		}
		double tot = 0;
		for(int i = 0;i<m;i++) {
			tot += (solve(currTrial+1,lampsMask^switchMask[i])/m);
		}
	    
		return dp[currTrial][lampsMask] = (tot);
		
	}
	static double [][] dp ;
	static double probFactor;
	static int m;
	static int [] switchMask;
    static int lcs(char[] X, char[] Y, int m, int n)
     {
         if (m == 0 || n == 0)
             return 0;
         if (X[m - 1] == Y[n - 1])
             return 1 + lcs(X, Y, m - 1, n - 1);
         else
             return Math.max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
     }
	    public static void dfs1(int node) {
	    	visited1[node] = true;
	    	for(int v :adjLists1[node]) {
	    		if(!visited1[v]) {
	    			dfs1(v);
	    		}
	    	}
	    	
	    }
	   static int maxSubsequenceSubstring(char[] X,char[] Y,int n,int m)
	    {
	        

	        if (n==0 || m==0) return 0;
	        
	        

	        
	        

	        if(X[n-1] == Y[m-1])
	        {
	            return  1 + maxSubsequenceSubstring(X,Y,n-1,m-1);
	        }
	        
	        

	        else
	        {
	            return maxSubsequenceSubstring(X,Y,n-1,m);    
	        }
	    }
	    public static void dfs2(int node) {
	    	visited2[node] = true;
	    	for(int v :adjLists2[node]) {
	    		if(!visited2[v]) {
	    			dfs2(v);
	    		}
	    	}
	    }
	    static class Picture implements Comparable{
	    	char [][] pixels;
	    	int numOFOnes;
	    	int idx;
	    	public Picture(char [][] pixels, int numOfOnes, int idx) {
	    		this.pixels = pixels;
	    		this.numOFOnes = numOfOnes;
	    		this.idx = idx;
	    	}
			@Override
			public int compareTo(Object arg0) {
				Picture p = (Picture) arg0;
				return numOFOnes - p.numOFOnes;
			}
	    	
	    }
	    long nCr(int n, int r)
	    {
	        return fact[n] / (fact[r] * fact[n - r]);
	    }
	    static long fact[];
	    static  ArrayList<Integer> [] adjLists1;
	    static ArrayList<Integer> [] adjLists2;
	    static boolean []visited1;
	    static boolean [] visited2;
		

		static int d [] ;
		
	   static  HashSet<Long> hs = new HashSet<Long>();
	  
	public static int idxOf(String s,char c) {
		int idx = -2;
		for(int i = 0;i<s.length();i++) {
			if(s.charAt(i)==c) {
				return i;
			}
		}
		return idx;
	}
	static ArrayList<Long >start;
	static ArrayList<Long> end;
	public static void dfs (int idx) {
		can[idx] = true;
		for(int i = 0;i<start.size();i++) {
			if((start.get(i)<start.get(idx)&& end.get(i)>start.get(idx)||(start.get(i)<end.get(idx)&& end.get(i)>end.get(idx)))){
				if(!can[i]) {
				dfs(i);
			}}
		}
	}
	static boolean [] can ; 
	static int n;
	
	static int [] [] sol;
	static int [] g;
	public static void constructSol() {
		for(int i = 1;i<sol.length;i++) {
			for(int j = 1;j<10;j++) {
				if(g[i] == j) {
					sol[i][j] = sol[i-1][j]+1;
				}
				else {
					sol[i][j] = sol[i-1][j];
				}
			}
		}
	}
	public static void prod() {
		for(int i=1;i<g.length;i++) {
			int n = i;
		if(n<10) {
			g[ n] = n;
		    continue;
		}
		int prod = 1;
		while(n>0) {
			if(n%10!=0) {
				prod*= (n%10);
				
			}
			n/=10;
		}
		

		g[i] = g[prod];
	
	}}
	public static  boolean isPalindrome(String s) {
		
		for(int i = 0;i<=s.length()/2;i++) {
			if(s.charAt(i)!=s.charAt(s.length()-1-i)) {
				return false;
			}
		}
		return true;
	}
	public static long logBase2(long n) {
		long ans = 0;
		while(n>1) {
			ans ++;
			n/=2;
		}
		return ans;
	}
	public static double getmostLeft(ArrayList<Circle> list) {
	        double min = Double.MAX_VALUE;
	        for (Circle c: list) {
	            min = Math.min(min, c.x - c.r);
	        }
	        return min;
	    }
 
	   public static double getmostRight(ArrayList<Circle> list) {
	        double max = Double.MIN_VALUE;
	        for (Circle c: list) {
	            max = Math.max(max, c.x + c.r);
	        }
	        return max;
	    }
	static class Circle{
		double x ;
		double y ;
		double r;
		int id;
		public Circle(double x, double y, double r) {
			this.x = x;
			this.y = y;
			this.r = r;
			
		}
		public String toString () {
			return x +" "+y+" "+r;
		}
		public boolean intersect(Circle o) {
			double dist = Math.sqrt((y-o.y)*(y-o.y)+(x-o.x)*(x-o.x));
			if(dist<=r+o.r) {
				return true;
			}
			return false;
		}
		public  Circle combine( Circle o) {
			double dist = Math.sqrt((y-o.y)*(y-o.y)+(x-o.x)*(x-o.x));
		    if(Math.abs(r-o.r)>=dist) {
		    	if(r>=o.r) {
		    		return this;
		    	}
		    	else {
		    		return o;
		    	}
		    }
 
			double cx = (x+o.x)/2.0;
			double cy = (y+o.y)/2.0;
			double rad = (dist +r +this.r)/2.0;
			return new Circle (cx, cy, rad);
		}
	}
	static class Pair {
		int x;
		int y;
		public Pair (int x, int y) {
			this.x = x;
			this.y = y;
			
		}
		public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair triple = (Pair) o;
            return x == triple.x &&
                    y == triple.y ;
        }
	}static long modPow(long a, long x, long p) {
	    

	    long res = 1;
	    while(x > 0) {
	        if( x % 2 != 0) {
	            res = (res * a) % p;
	        }
	        a = (a * a) % p;
	        x /= 2;
	    }
	    return res;
	}
 
	static long modInverse(long a, long p) {
	    

	    

	    return modPow(a, p-2, p);
	}
	static long nCr1(int n, int r)
	{ 

	   long numerator = fact[n]%mod;
	  

	   long deno = ((fact[r]%mod)*(fact[n-r]%mod))%mod;
	
	    return (numerator*modInverse(deno,mod))%mod;
	}
	public static String solve (String s) {
		Stack <String> st = new Stack<String>();
		for(int i = 0;i<s.length();i++) {
			if(s.charAt(i)==']') {
				String toEncode = "";
				while(!st.isEmpty()&&!st.peek().equals("[")) {
					toEncode = st.pop()+ toEncode;
				}
				st.pop();
				String toPush = "";
				int freq = Integer.parseInt(st.pop());
				while(freq-->0) {
					toPush+=toEncode;
				}
				st.push(toPush);
			}
			else {
				st.push(s.charAt(i)+"");
			}
			
		}
		String res = "";
		while(!st.isEmpty()) {
			res = st.pop() +res;
		}
		return res;
	}
	static String alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
	static String s;
	static ArrayList <Integer> prime;
	 static void simpleSieve(int limit)
	    {   
	        

	        

	        

	        boolean mark[] = new boolean[limit+1];
	         
	        for (int i = 0; i < mark.length; i++)
	            mark[i] = true;
	      
	        for (int p=2; p*p<limit; p++)
	        {
	            

	            if (mark[p] == true)
	            {
	                

	                for (int i=p*p; i<limit; i+=p)
	                    mark[i] = false;
	            }
	        }
	      
	        

	        for (int p=2; p<limit; p++)
	        {
	            if (mark[p] == true)
	            {
	                prime.add(p);
	               

	            }
	        }
	    }
 
	 
	 public static long gcd (long a, long b ) {
		 if(b==0) {
			 return a;
		 }
		 else {
			 return gcd (b, a%b);
		 }
	 }
	 
 static class Scanner {
 		StringTokenizer st;
 		BufferedReader br;
  
 		public Scanner(InputStream s) {
 			br = new BufferedReader(new InputStreamReader(s));
 		}
        public Scanner(FileReader r) {
        	br = new BufferedReader(r);
        }
 		public boolean hasNext() {
 			

 			return false;
 		}
  
 		public String next() throws IOException {
 			while (st == null || !st.hasMoreTokens())
 				st = new StringTokenizer(br.readLine());
 			return st.nextToken();
 		}
  
 		public int nextInt() throws IOException {
 			return Integer.parseInt(next());
 		}
  
 		public long nextLong() throws IOException {
 			return Long.parseLong(next());
 		}
  
 		public String nextLine() throws IOException {
 			return br.readLine();
 		}
  
 		public double nextDouble() throws IOException {
 			String x = next();
 			StringBuilder sb = new StringBuilder("0");
 			double res = 0, f = 1;
 			boolean dec = false, neg = false;
 			int start = 0;
 			if (x.charAt(0) == '-') {
 				neg = true;
 				start++;
 			}
 			for (int i = start; i < x.length(); i++)
 				if (x.charAt(i) == '.') {
 					res = Long.parseLong(sb.toString());
 					sb = new StringBuilder("0");
 					dec = true;
 				} else {
 					sb.append(x.charAt(i));
 					if (dec)
 						f *= 10;
 				}
 			res += Long.parseLong(sb.toString()) / f;
 			return res * (neg ? -1 : 1);
 		}
  
 		public boolean ready() throws IOException {
 			return br.ready();
 		}
  
 	}
}