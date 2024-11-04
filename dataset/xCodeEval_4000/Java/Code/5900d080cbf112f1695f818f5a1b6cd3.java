		     
		import java.io.*;
		        		    import java.math.*;
		        		    import java.util.*;
	import java.util.regex.Pattern;
	
	import javafx.scene.shape.Line;
		    	     
		        		    public class Main{
		        		  	private static InputStream stream;
		        		    	private static byte[] buf = new byte[1024];
		        		    	private static int curChar;
		        		    	private static int numChars;
		        		    	private static SpaceCharFilter filter;
		        		    	private static PrintWriter pw;
		        		    	private static long count = 0,mod=(long)1e9+7;
		        		    

		public final static int INF = (int) 1E9;
		
		public static void main(String args[]) {
	    	
			InputReader(System.in);
			pw = new PrintWriter(System.out); 
		    new Thread(null ,new Runnable(){
		       public void run(){
		           try{
		        		
		               solve();
	
		               pw.close();
		           } catch(Exception e){
		               e.printStackTrace();
		           }
		       }
		   },"1",1<<26).start();
		   	   }
		    static StringBuilder sb;
		    public static void test() throws IOException{
		    	 sb=new StringBuilder();
		    	int t=nextInt();
		    	

		    	 while(t-->0){
		    		
		    		solve();
		    		

		    		

		    	}
		    	pw.println(sb);
		    }
		    
		    public static long pow(long n, long p,long mod) {
				if(p==0)
					return 1;
				if(p==1)
					return n%mod;
				if(p%2==0){
					long temp=pow(n, p/2,mod);
				return (temp*temp)%mod;
				}else{
					 	long temp=pow(n,p/2,mod);
					 	temp=(temp*temp)%mod;
					 	return(temp*n)%mod;
					 	
				}
			}
		    public static long pow(long n, long p) {
				if(p==0)
					return 1;
				if(p==1)
					return n;
				if(p%2==0){
					long temp=pow(n, p/2);
				return (temp*temp);
				}else{
					 	long temp=pow(n,p/2);
					 	temp=(temp*temp);
					 	return(temp*n);
					 	
				}
			}
		    public static void Merge(long a[],int p,int r){
		        if(p<r){
		            int q = (p+r)/2;
		            Merge(a,p,q);
		            Merge(a,q+1,r);
		            Merge_Array(a,p,q,r);
		        }
		    }
		    public static void Merge_Array(long a[],int p,int q,int r){
		       long b[] = new long[q-p+1];
		        long c[] = new long[r-q];
		        for(int i=0;i<b.length;i++)
		            b[i] = a[p+i];
		        for(int i=0;i<c.length;i++)
		            c[i] = a[q+i+1];
		        int i = 0,j = 0;
		        for(int k=p;k<=r;k++){
		            if(i==b.length){
		                a[k] = c[j];
		                j++;
		            }
		            else if(j==c.length){
		                a[k] = b[i];
		                i++;
		            }
		            else if(b[i]<c[j]){
		                a[k] = b[i];
		                i++;
		            }
		            else{
		                a[k] = c[j];
		                j++;
		            }
		        }
		    }
		    
		  
			public static long gcd(long x, long y) {
				if (x == 0)
					return y;
				else
					return gcd( y % x,x);
			}	
			
			public static boolean isPrime(int n) {
				if (n <= 1)
					return false;
				if (n <= 3)
					return true;
		 
				if (n % 2 == 0 || n % 3 == 0)
					return false;
		 
				for (int i = 5; i * i <= n; i = i + 6)
					if (n % i == 0 || n % (i + 2) == 0)
						return false;
		 
				return true;
			}
			
		        static LinkedList<Integer> adj[],adj2[];
		        static boolean Visited[];
		        static HashSet<Integer> exc;
		        static long oddsum[]=new long[1000001];
		        static long co=0;
		    
		    	private static void buildgraph(int n){
		    		adj=new LinkedList[n+1];
		    		adj2=new LinkedList[n+1];
		    		Visited=new boolean[n+1];
		    		levl=new int[n+1];
		    		
		    		for(int i=0;i<=n;i++){
		    			adj[i]=new LinkedList<Integer>();
		    		
		    		}
		
		
		    	}
		      
		       
		        static int[] levl;
		        static int[] eat;
		        static int n,m;
		        static int price[];
		        

		    
		        
		        static long d,x,y;
				static long modInverse(long A, long M)
				{
				extendedEuclid(A,M);
				return (x%M+M)%M;    

				}
				static void extendedEuclid(long A, long B) {
				if(B == 0) {
				d = A;
				x = 1;
				y = 0;
				}
				else {
				extendedEuclid(B, A%B);
				long temp = x;
				x = y;
				y = temp - (A/B)*y;
				}
				}
		        static double distance(int x1,int y1,int x2,int y2){
		        	return Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		        }
		        static double area(int x1, int y1, int x2, int y2, int x3, int y3)
		        {
		           return Math.abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
		        }
		        static boolean isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
		        {   
		           double A = area (x1, y1, x2, y2, x3, y3);
		         
		           double A1 = area (x, y, x2, y2, x3, y3);
		         
		           double A2 = area (x1, y1, x, y, x3, y3);
		         
		           double A3 = area (x1, y1, x2, y2, x, y);
		           
		          return (A == A1 + A2 + A3);
		        }
		      
				static int col[];
		    public static boolean isVowel(char c){
		    	if(c=='a' || c=='e'||c=='i' || c=='o' || c=='u')
		    		return true;
		    	return false;
		    }
		static long arr[], lazy[],ans[];
		static int c[];
		public static void solve() throws IOException{
		
			int n=nextInt();
			int m=nextInt();
			
			TreeSet<Integer> ts=new TreeSet<Integer>();
			ts.add(2);
			for(int i=3;i<=1000000;i++){
				if(isPrime(i))
					ts.add(i);
			}
			pw.println(ts.higher(n-2)+" "+ts.higher(n-2));
			for(int i=0;i<n-2;i++){	
				pw.println((i+1)+" "+(i+2)+" "+1);
				m--;
			}
			int get =ts.higher(n-2)-n+2;
			pw.println((n-1)+ " "+n+" "+get);
			int deg[]=new int[n+1];
			Arrays.fill(deg, 2);
			deg[1]=1;
			deg[n]=1;
			m--;
			int start=1;
			int end=3;
			
			 while (m>0){
			        for(int i=start+2;i<=n&&m>0;i++,m--){
			            pw.println(start+" "+i+" "+1000000000+"\n");
			        }
			        start++;
			    }
		}
	
	
		   static void DFS(int cyc,int n, int vert, int start) {
	    
	   

	   vis[vert] = true;
	    
	   

	   if (cyc == 0) {
	        
	       

	       

	      vis[vert] = false;
	        
	       

	       

	       if (adj[vert].contains(start)) {
	           count++;
	           return;
	       } else
	           return;
	   }
	    
	   

	   

	   for (int i = 0; i < n; i++)
	       if (!vis[i] && adj[vert].contains(i))
	        
	           

	           

	           DFS(cyc-1,n, i, start);
	    
	   

	   

	   vis[vert] = false;
	}
	
		static int cnt=0;
		
		static int dista[];
		private static void dfs2(int curr,int dist){
			Visited[curr]=true;
			dista[curr]=dist;
			for(int i:adj[curr]){
				if(!Visited[i]){
					dfs2(i,dist+1);
				}
			}
		}
		static long tot=0;
		static int par[]=new int[1000001];
		static long size[]=new long[1000001];
		static boolean vis[]=new boolean[1000001];
		public static void dfs1(int curr)
		{
			vis[curr]=true;
			size[curr]=1;
			for(int x:adj[curr])
			{
				if(!vis[x])
				{
					par[x]=curr;
					dfs1(x);
					size[curr]+=size[x];
				}
			}
		}
		
	  
	  static boolean getString (char[][] matrix, int x, int y, char[] target) {
	      if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
	          return false;
	      }
	      
	      if (target == null || target.length == 0) {
	          return false;
	      }
	      
	      if (matrix[x][y] != target[0]) {
	          return false;
	      }
	      
	      int row = matrix.length;
	      int column = matrix[0].length;
	      
	      int[] dirx = {0, 0, 1, -1, 1, 1, -1, -1}; 

	      int[] diry = {1, -1, 0, 0, 1, -1, 1, -1}; 

	      
	      for (int i = 0; i < 8; i++) {
	          int nextx = x;  

	          int nexty = y;  

	          int k = 1;
	          while (k < target.length) {
	              nextx += dirx[i];
	              nexty += diry[i];
	              
	              if (nextx < 0 || nexty < 0 || nextx >= row || nexty >= column) {
	                  break;
	              }
	              
	              if (matrix[nextx][nexty] != target[k]) {
	                  break;
	              }
	              k++;
	          }
	          
	          if (k == target.length) {
	              return true;
	          }
	      }
	      
	      return false;
	  }
		
		
		
		static int no_vert=0,timer=1;
		
		private static void dfs(int s,int lev){
			Visited[s]=true;
			
			for(int x:adj[s]){
				if(!Visited[x]){
				
					dfs(x,lev+1);
				}
				
			}
			

			no_vert=Math.max(no_vert, lev);
		}
		
		
		    private static boolean Check(int x,int y,int n){
				if(x>=0 && x<n && y>=0 && y<n)
					return true;
				return false;
			}
		    
		    static long[][] dp;
			static long dp2[];
		    static ArrayList<Integer> pri[],pri2[];
		
		  private static void dfs3(int curr,int par,int co){
				 Visited[curr]=true;
				 for(int x:adj[curr]){
					 if(!Visited[x]){
						 dfs3(x,curr,co);
					 }
				 }
				 if(col[curr]==1){
					 dp2[curr]++;
				 }else{
					 dp2[curr]--;
				 }
				 if(dp2[curr]>0){
					 pri2[par].add(curr);
				 dp2[par]+=dp2[curr];
				 }
			  }
		    public static String reverseString(String s) {
				StringBuilder sb = new StringBuilder(s);
				sb.reverse();
				return (sb.toString());
			}
		    
		  
			
		
		
		
		    		      static int indeg[];
		    		   
		    		        static HashSet<Integer> hs;
		    		       
		    		     
		    		     	static boolean prime[];
							static int spf[];
							public static void sieve(int n){
								prime=new boolean[n+1];
								spf=new int[n+1];
								
								Arrays.fill(spf, 1);
								Arrays.fill(prime, true);
							prime[1]=false;
								spf[2]=2;
								
							for(int i=4;i<=n;i+=2){
								spf[i]=2;
							}
							for(int i=3;i<=n;i+=2){
								if(prime[i]){
									spf[i]=i;
									for(int j=2*i;j<=n;j+=i){
										
										prime[j]=false;
									if(spf[j]==1){
										spf[j]=i;
									}
									}
								}
							}
							
								
							}
		    		     	
		    		    	

		

		 
		    		     	public static void sort(long a[]){
		    		     		Merge(a, 0, a.length-1);
		    		     	}
		    		    	public static void InputReader(InputStream stream1) {
		    		    		stream = stream1;
		    		    	}
		 
		    		    	private static boolean isWhitespace(int c) {
		    		    		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		    		    	}
		 
		    		    	private static boolean isEndOfLine(int c) {
		    		    		return c == '\n' || c == '\r' || c == -1;
		    		    	}
		 
		    		    	private static int read() {
		    		    		if (numChars == -1)
		    		    			throw new InputMismatchException();
		    		    		if (curChar >= numChars) {
		    		    			curChar = 0;
		    		    			try {
		    		    				numChars = stream.read(buf);
		    		    			} catch (IOException e) {
		    		    				throw new InputMismatchException();
		    		    			}
		    		    			if (numChars <= 0)
		    		    				return -1;
		    		    		}
		    		    		return buf[curChar++];
		    		    	}
		 
		    		    	private static int nextInt() {
		    		    		int c = read();
		    		    		while (isSpaceChar(c))
		    		    			c = read();
		    		    		int sgn = 1;
		    		    		if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
		    		    			c = read();
		    		    		} while (!isSpaceChar(c));
		    		    		return res * sgn;
		    		    	}
		 
		    		    	private static long nextLong() {
		    		    		int c = read();
		    		    		while (isSpaceChar(c))
		    		    			c = read();
		    		    		int sgn = 1;
		    		    		if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
		    		    			c = read();
		    		    		} while (!isSpaceChar(c));
		    		    		return res * sgn;
		    		    	}
		 
		    		    	private static String nextToken() {
		    		    		int c = read();
		    		    		while (isSpaceChar(c))
		    		    			c = read();
		    		    		StringBuilder res = new StringBuilder();
		    		    		do {
		    		    			res.appendCodePoint(c);
		    		    			c = read();
		    		    		} while (!isSpaceChar(c));
		    		    		return res.toString();
		    		    	}
		 
		    		    	private static String nextLine() {
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
		 
		    		    	private static int[] nextIntArray(int n) {
		    		    		int[] arr = new int[n];
		    		    		for (int i = 0; i < n; i++) {
		    		    			arr[i] = nextInt();
		    		    		}
		    		    		return arr;
		    		    	}
		 
		    		    	private static long[][] next2dArray(int n, int m) {
		    		    		long[][] arr = new long[n][m];
		    		    		for (int i = 0; i < n; i++) {
		    		    			for (int j = 0; j < m; j++) {
		    		    				arr[i][j] = nextLong();
		    		    			}
		    		    		}
		    		    		return arr;
		    		    	}
		    		    	private static char[][] nextCharArray(int n,int m){
		    		    		char [][]c=new char[n][m];
		    		    		for(int i=0;i<n;i++){
		    		    			String s[]=nextLine().split(" ");
		    		    			for(int j=0;j<s.length;j++){
		    		    				c[i][j]=s[j].charAt(0);
		    		    			}
		    		    		}
		    		    		return c;
		    		    	}
		 
		    		    	private static long[] nextLongArray(int n) {
		    		    		long[] arr = new long[n];
		    		    		for (int i = 0; i < n; i++) {
		    		    			arr[i] = nextLong();
		    		    		}
		    		    		return arr;
		    		    	}
		 
		    		    	private static void pArray(int[] arr) {
		    		    		for (int i = 0; i < arr.length; i++) {
		    		    			pw.print(arr[i] + " ");
		    		    		}
		    		    		pw.println();
		    		    		return;
		    		    	}
		 
		    		    	private static void pArray(long[] arr) {
		    		    		for (int i = 0; i < arr.length; i++) {
		    		    			pw.print(arr[i] + " ");
		    		    		}
		    		    		pw.println();
		    		    		return;
		    		    	}
		 
		    		    	private static void pArray(boolean[] arr) {
		    		    		for (int i = 0; i < arr.length; i++) {
		    		    			pw.print(arr[i] + " ");
		    		    		}
		    		    		pw.println();
		    		    		return;
		    		    	}
		 
		    		    	private static boolean isSpaceChar(int c) {
		    		    		if (filter != null)
		    		    			return filter.isSpaceChar(c);
		    		    		return isWhitespace(c);
		    		    	}
		 
		    		    	private interface SpaceCharFilter {
		    		    		public boolean isSpaceChar(int ch);
		    		    	}
		    		    	
		
		}
		    		    
		    		        class Node{
		    		    	int to;
		    		    	long dist;
		    		    	Node(int to,long dist){
		    		    		this.to=to;
		    		    		this.dist=dist;
		    		    	}
		    		    	
		    		    }
		    		        class Qu{
		    		    		long a0,a1,a2,a3;
		    		    		public Qu(long a0,long a1,long a2,long a3) {
		    		    			this.a0=a0;
		    		    			this.a1=a1;
		    		    			this.a2=a2;
		    		    			this.a3=a3;
		    		    		}
		    		    }
		    		
		class Dsu{
		private int rank[], parent[] ,n;
		long str[],si[],larg[];
		long max=0;
		int cnt=0;
		private static int[] parent1;
		Dsu(int size){
			this.n=size+1;
			rank=new int[n];
			cnt=n-1;
			

		    		    		    		parent=new int[n];
		    		    		    		str=new long[n];
		    		    		    		si=new long[n];
		    		    		
		    		    		    		larg=new long[n];
		    		    		    		makeSet();
		    		    		
		    		    		    	}
		    		    		    	
		    		    		    	void makeSet(){
		    		    		    		for(int i=0;i<n;i++){
		    		    		    			parent[i]=i;
		    		    		    			si[i]=1;
		    		    		    		}
		    		    		    	}
		    		    		    	
		    		    		    	int find(int x){
		    		    		    		if(parent[x]!=x){
		    		    		    			
		    		    		    			parent[x]=find(parent[x]);
		    		    		    		}
		    		    		    		return parent[x];
		    		    		    	}
		    		    		    	
		    		    		    	void join(int ind,long val){
		    		    		    		if(str[ind]==0){
		    		    		    			str[ind]=val;
		    		    		    			larg[ind]=val;
		    		    		    			max=Math.max(max, str[ind]);
		    		    		    		}
		    		    		    		int prev_ind=(ind-1);
		    		    		    		int next_ind=(ind+1);
		    		    		    		if(prev_ind>0 && larg[prev_ind]!=0){
		    		    		    			union(prev_ind,ind);
		    		    		    		}
		    		    		    		if(next_ind<n && larg[next_ind]!=0){
		    		    		    			union(next_ind,ind);
		    		    		    		}
		    		    		    		
		    		    		    	}
		    		    		    
		    		    		    	
		    		    		    	boolean union(int x,int y){
		    		    		    		int xRoot=find(x);
		    		    		    		int yRoot=find(y);
		    		    		    
		    		    		    	
		    		    		    		if(xRoot==yRoot)
		    		    		    			return false;
		    		    		    		if(rank[xRoot]<rank[yRoot]){
		    		    		    		parent[xRoot]=yRoot;
		    		    		    		
		    		    		    		larg[yRoot]=Math.max(larg[xRoot], larg[yRoot]);
		    		    		    		
		    		    		    		si[yRoot]+=si[xRoot];
		    		    		    		str[yRoot]=larg[yRoot]*si[yRoot];
		    		    		    			max=Math.max(str[yRoot], max);
		    		    		    		}else if(rank[yRoot]<rank[xRoot]){
		    		    		    			parent[yRoot]=xRoot;
		     
		    		    		    			larg[xRoot]=Math.max(larg[xRoot], larg[yRoot]);
		        		    		    		
		        		    		    		si[xRoot]+=si[yRoot];
		        		    		    		str[xRoot]=larg[xRoot]*si[xRoot];
		    			    		    		max=Math.max(str[xRoot], max);
		    		    		    		}else{
		    		    		    			parent[yRoot]=xRoot;
		    		    		    			rank[xRoot]++;
		     
		    		    		    			larg[xRoot]=Math.max(larg[xRoot], larg[yRoot]);
		        		    		    		
		        		    		    		si[xRoot]+=si[yRoot];
		        		    		    		str[xRoot]=larg[xRoot]*si[xRoot];
		    			    		    		max=Math.max(str[xRoot], max);
		    		    		    		
		    		    		    		}
		    		    		    		cnt--;
		    		    		    		return true;
		    		    		    	}
		    	
		    		    		     
		    		    		    }
	class Pair1 implements Comparable<Pair1>{
			int ind;
			String v;
			@Override
			public int compareTo(Pair1 arg0) {
				if(v==arg0.v)
					return 1;
				return this.v.compareTo(arg0.v);
				
			}
		
		
		}
		  
		
