	
	
	 
	    	        			
	     
	     
	        		    import java.awt.Checkbox;
	import java.awt.Point;
	import java.awt.event.PaintEvent;
	import java.io.*;
	        		    import java.math.*;
	        		    import java.util.*;
	import java.util.Map.Entry;
	
	import javax.print.attribute.SetOfIntegerSyntax;
	import javax.swing.plaf.FontUIResource;
	    	     
	        		    public class Main{
	        		  	private static InputStream stream;
	        		    	private static byte[] buf = new byte[1024];
	        		    	private static int curChar;
	        		    	private static int numChars;
	        		    	private static id10 filter;
	        		    	private static PrintWriter pw;
	        		    	private static long count = 0,mod=1000000007;
	        		    

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
	        static long id5[]=new long[1000001];
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
			id8(A,M);
			return (x%M+M)%M;    

			}
			static void id8(long A, long B) {
			if(B == 0) {
			d = A;
			x = 1;
			y = 0;
			}
			else {
			id8(B, A%B);
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
	    public static boolean id2(char c){
	    	if(c=='a' || c=='e'||c=='i' || c=='o' || c=='u')
	    		return true;
	    	return false;
	    }
	static Stack<Integer> st[];
	static Queue<Integer> q[];
	static long cost[];    
	public static void solve(){

		
	int n=nextInt();
	int k=nextInt();
	int a[]=id4(n);
	if(k==1){
		int min=a[0];
		for(int i=0;i<n;i++){
			min=Math.min(min, a[i]);
		}
		pw.println(min);
		return;
	}
	if(k==2){
		int min_pref[]=new int[n];
		int id3[]=new int[n];
		min_pref[0]=a[0];
		for(int i=1;i<n;i++){
			min_pref[i]=Math.min(min_pref[i-1], a[i]);
		}
		id3[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--){
			id3[i]=Math.min(id3[i+1], a[i]);
		}
		int max=Integer.MIN_VALUE;
		for(int  i=0;i<n-1;i++){
		

			max=Math.max(max,Math.max(min_pref[i], id3[i+1]));
		}
		pw.println(max);
		return;
	}
	int max=a[0];
	for(int i=0;i<n;i++){
		max=Math.max(max, a[i]);
	}
	pw.println(max);
	
	
	}
    
 
	static int id1(int m, int n)
    {
        

        

        int count[][] = new int[m][n];
  
        

        

        for (int i = 0; i < m; i++)
            count[i][0] = 1;
  
        

        

        for (int j = 0; j < n; j++)
            count[0][j] = 1;
  
        

        

        

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
  
            

            

            

            count[i][j] = count[i-1][j] + count[i][j-1]; 

  
        }
        return count[m-1][n-1];
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
	 
	    		    	private static boolean id7(int c) {
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
	    		    		while (id0(c))
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
	    		    		} while (!id0(c));
	    		    		return res * sgn;
	    		    	}
	 
	    		    	private static long nextLong() {
	    		    		int c = read();
	    		    		while (id0(c))
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
	    		    		} while (!id0(c));
	    		    		return res * sgn;
	    		    	}
	 
	    		    	private static String nextToken() {
	    		    		int c = read();
	    		    		while (id0(c))
	    		    			c = read();
	    		    		StringBuilder res = new StringBuilder();
	    		    		do {
	    		    			res.appendCodePoint(c);
	    		    			c = read();
	    		    		} while (!id0(c));
	    		    		return res.toString();
	    		    	}
	 
	    		    	private static String nextLine() {
	    		    		int c = read();
	    		    		while (id0(c))
	    		    			c = read();
	    		    		StringBuilder res = new StringBuilder();
	    		    		do {
	    		    			res.appendCodePoint(c);
	    		    			c = read();
	    		    		} while (!id7(c));
	    		    		return res.toString();
	    		    	}
	 
	    		    	private static int[] id4(int n) {
	    		    		int[] arr = new int[n];
	    		    		for (int i = 0; i < n; i++) {
	    		    			arr[i] = nextInt();
	    		    		}
	    		    		return arr;
	    		    	}
	 
	    		    	private static long[][] id9(int n, int m) {
	    		    		long[][] arr = new long[n][m];
	    		    		for (int i = 0; i < n; i++) {
	    		    			for (int j = 0; j < m; j++) {
	    		    				arr[i][j] = nextLong();
	    		    			}
	    		    		}
	    		    		return arr;
	    		    	}
	    		    	private static char[][] id6(int n,int m){
	    		    		char [][]c=new char[n][m];
	    		    		for(int i=0;i<n;i++){
	    		    			String s[]=nextLine().split(" ");
	    		    			for(int j=0;j<s.length;j++){
	    		    				c[i][j]=s[j].charAt(0);
	    		    			}
	    		    		}
	    		    		return c;
	    		    	}
	 
	    		    	private static long[] id11(int n) {
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
	 
	    		    	private static boolean id0(int c) {
	    		    		if (filter != null)
	    		    			return filter.id0(c);
	    		    		return isWhitespace(c);
	    		    	}
	 
	    		    	private interface id10 {
	    		    		public boolean id0(int ch);
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
	class Pair implements Comparable<Pair>{
		int x,y,w;
		Pair(int x,int y){
			this.x=x;
			this.y=y;
		}
	
		@Override
		public int compareTo(Pair o) {
			

			return 0;
		}
	}
	  
								
