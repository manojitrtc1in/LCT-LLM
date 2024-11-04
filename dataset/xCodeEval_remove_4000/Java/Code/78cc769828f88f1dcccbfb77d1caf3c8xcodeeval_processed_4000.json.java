		
		
		 
		    	        			
		     
		     
		        		    import java.awt.Checkbox;
		import java.awt.Point;
		import java.awt.event.PaintEvent;
		import java.io.*;
		        		    import java.math.*;
		        		    import java.util.*;
		import java.util.Map.Entry;
	import java.util.concurrent.ArrayBlockingQueue;
	
	import javax.print.attribute.SetOfIntegerSyntax;
		import javax.swing.plaf.FontUIResource;
		    	     
		        		    public class Practice{
		        		  	private static InputStream stream;
		        		    	private static byte[] buf = new byte[1024];
		        		    	private static int curChar;
		        		    	private static int numChars;
		        		    	private static id11 filter;
		        		    	private static PrintWriter pw;
		        		    	private static long count = 0;
								static long mod=1000000007;
		        		    

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
		    public static void test(){
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
			
		        static LinkedList<Integer> adj[];
		        static boolean Visited[];
		        static HashSet<Integer> exc;
		        static long id6[]=new long[1000001];
		        static long co=0,ans=0;
		    
		    	private static void buildgraph(int n){
		    		adj=new LinkedList[n+1];
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
				id9(A,M);
				return (x%M+M)%M;    

				}
				static void id9(long A, long B) {
				if(B == 0) {
				d = A;
				x = 1;
				y = 0;
				}
				else {
				id9(B, A%B);
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
		    public static boolean id4(char c){
		    	if(c=='a' || c=='e'||c=='i' || c=='o' || c=='u')
		    		return true;
		    	return false;
		    }
		static Stack<Integer> st[];
		static Queue<Integer> q[];
		static long cost[];    
		 static final String S="0123456789";
	
		static long arr[];
		static ArrayList<String> ar;
		public static void solve(){

			
			HashMap<Long,Long> id2=new HashMap();
	    	long fina=0;
			int n=nextInt();
	    	int x=nextInt();
	    	int k=nextInt();
	    	long a[]=id12(n);
	    	sort(a);
	    	int prime[]=new int[2000];
	    	int index=0;
	    	for(int i=0;i<2000;i++)
	    	{
	    		for(int j=0;j<200;j++)
	    		{
	    			int c=i*j;
	    			c+=4;
	    			prime[i]=c;
	    		}
	    	}
	    	
	    	while(index<n)
	    	{
	    		long lodo=a[index];
	    		long count=0;
	    		for(int j=0;j<5;j++)
	    		{
	    		

	    		}
	    		while(index<n&&lodo==a[index])
	    		{
	    			long tmp=a[index]-1;
	    			tmp/=x;
	    			if(!id2.containsKey(tmp))
	    				id2.put(tmp,(long)1);
	    			else
	    				id2.put(tmp,id2.get(tmp)+1);
	    			index++;
	    			count++;
	    		}
	    		for(int j=0;j<3;j++)
	    		{
	    		

	    		}
	    		long madar=lodo/x;
	    		madar-=k;
	    		if(id2.containsKey(madar))
	    			fina+=((id2.get(madar))*(long)count);
	    		else{
	    			
	    		}
	    	}
	    	pw.println(fina);
		}
		 static int id0(String str) {
		        int maxLength = 1; 

		 
		        int start = 0;
		        int len = str.length();
		 
		        int low, high;
		 
		        

		        

		        for (int i = 1; i < len; ++i) 
		        {
		            

		            

		            low = i - 1;
		            high = i;
		            while (low >= 0 && high < len
		                    && str.charAt(low) == str.charAt(high)) {
		                if (high - low + 1 > maxLength) {
		                    start = low;
		                    maxLength = high - low + 1;
		                }
		                --low;
		                ++high;
		            }
		 
		            

		            

		            low = i - 1;
		            high = i + 1;
		            while (low >= 0 && high < len
		                    && str.charAt(low) == str.charAt(high)) {
		                if (high - low + 1 > maxLength) {
		                    start = low;
		                    maxLength = high - low + 1;
		                }
		                --low;
		                ++high;
		            }
		        }
		 
		       
		        return maxLength;
		    }
		 
		   

	    public  static void perm1(String s) { perm1("", s); }
	    private static void perm1(String prefix, String s) {
	        int n = s.length();
	        if (n == 0) ar.add(prefix);
	        else {
	            for (int i = 0; i < n; i++)
	               perm1(prefix + s.charAt(i), s.substring(0, i) + s.substring(i+1, n));
	        }
	
	    }
	    private static void swap(char[] a, int i, int j) {
	        char c = a[i];
	        a[i] = a[j];
	        a[j] = c;
	    }
	
		private static long binomial(final int N, final int K) {
	
			BigInteger ret = BigInteger.ONE;
			for (int k = 0; k < K; k++) {
			    ret = ret.multiply(BigInteger.valueOf(N-k))
			             .divide(BigInteger.valueOf(k+1));
			}
			BigInteger mod2 = ret.mod(BigInteger.valueOf(mod));
			return mod2.longValue();
	
			}
		static long s_dynamic(int n,int k) {
		    int maxj = n-k;
	
		    arr = new long[maxj+1];
	
		    for (int i = 0; i <= maxj; ++i)
		        arr[i] = 1;
	
		    for (int i = 1; i <= k; ++i)
		        for(int j = 1; j <= maxj; ++j)
		            {
		        	arr[j] =(arr[j]%mod)+ (i%mod*(arr[j-1]%mod))%mod;
		        	arr[j]%=mod;
		            }
	
		    return arr[maxj];
		}
		 public static long factorial(long n) {
		        long a = 1;
		        for (long i = 1; i <= n; i++) a = (a%mod*i%mod)%mod;
		        return a;
		    }
		private static int  id3(int j){
			String s=String.valueOf(j);
		int cnt=0;
			for(int i=0;i<s.length();i++){
				cnt+=(s.charAt(i)-'0');
			}
			return cnt;
			
		}
		static int no_vert=0;
		private static void dfs2(int s){
			Visited[s]=true;
			no_vert++;
			sb.append(s+" ");
			for(int x:pri[s]){
				if(!Visited[x]){
				
					dfs2(x);
				}
				
			}
		}
		
		private static void dfs4(int s){
			Visited[s]=true;
			no_vert++;
			sb.append(s+" ");
			for(int x:pri2[s]){
				if(!Visited[x]){
				
					dfs4(x);
				}
				
			}
		}
		
		    private static boolean Check(int x,int y,int n){
				if(x>=0 && x<n && y>=0 && y<n)
					return true;
				return false;
			}
		    
		    static long dp[],dp2[];
		    static ArrayList<Integer> pri[],pri2[];
		  private static void dfs(int curr,int par,int co){
			 Visited[curr]=true;
			 for(int x:adj[curr]){
				 if(!Visited[x]){
					 dfs(x,curr,co);
				 }
			 }
			 if(col[curr]==0){
				 dp[curr]++;
			 }else{
				 dp[curr]--;
			 }
			 if(dp[curr]>0){
				 pri[par].add(curr);
			 dp[par]+=dp[curr];
			 }
		  }
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
								prime[i]=false;
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
		 
		    		    	private static boolean id8(int c) {
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
		    		    		while (id1(c))
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
		    		    		} while (!id1(c));
		    		    		return res * sgn;
		    		    	}
		 
		    		    	private static long nextLong() {
		    		    		int c = read();
		    		    		while (id1(c))
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
		    		    		} while (!id1(c));
		    		    		return res * sgn;
		    		    	}
		 
		    		    	private static String nextToken() {
		    		    		int c = read();
		    		    		while (id1(c))
		    		    			c = read();
		    		    		StringBuilder res = new StringBuilder();
		    		    		do {
		    		    			res.appendCodePoint(c);
		    		    			c = read();
		    		    		} while (!id1(c));
		    		    		return res.toString();
		    		    	}
		 
		    		    	private static String nextLine() {
		    		    		int c = read();
		    		    		while (id1(c))
		    		    			c = read();
		    		    		StringBuilder res = new StringBuilder();
		    		    		do {
		    		    			res.appendCodePoint(c);
		    		    			c = read();
		    		    		} while (!id8(c));
		    		    		return res.toString();
		    		    	}
		 
		    		    	private static int[] id5(int n) {
		    		    		int[] arr = new int[n];
		    		    		for (int i = 0; i < n; i++) {
		    		    			arr[i] = nextInt();
		    		    		}
		    		    		return arr;
		    		    	}
		 
		    		    	private static long[][] id10(int n, int m) {
		    		    		long[][] arr = new long[n][m];
		    		    		for (int i = 0; i < n; i++) {
		    		    			for (int j = 0; j < m; j++) {
		    		    				arr[i][j] = nextLong();
		    		    			}
		    		    		}
		    		    		return arr;
		    		    	}
		    		    	private static char[][] id7(int n,int m){
		    		    		char [][]c=new char[n][m];
		    		    		for(int i=0;i<n;i++){
		    		    			String s[]=nextLine().split(" ");
		    		    			for(int j=0;j<s.length;j++){
		    		    				c[i][j]=s[j].charAt(0);
		    		    			}
		    		    		}
		    		    		return c;
		    		    	}
		 
		    		    	private static long[] id12(int n) {
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
		 
		    		    	private static boolean id1(int c) {
		    		    		if (filter != null)
		    		    			return filter.id1(c);
		    		    		return isWhitespace(c);
		    		    	}
		 
		    		    	private interface id11 {
		    		    		public boolean id1(int ch);
		    		    	}
		    		    	
		
		}
		
		    		
		