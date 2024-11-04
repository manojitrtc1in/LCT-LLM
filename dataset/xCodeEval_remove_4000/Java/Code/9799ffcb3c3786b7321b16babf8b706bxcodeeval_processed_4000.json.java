		
			
			    
			     
			            
			    import java.io.*;
			    import java.math.*;
			    import java.util.*;
			    import javax.print.attribute.SetOfIntegerSyntax;
			     
			    public class Graph1 {
			    	private static InputStream stream;
			    	private static byte[] buf = new byte[1024];
			    	private static int curChar;
			    	private static int numChars;
			    	private static id19 filter;
			    	private static PrintWriter pw;
			    	private static long count = 0,mod=1000000007;
			    	private static TreeSet<Integer>ts[]=new TreeSet[200000];
			    	private static HashSet hs=new HashSet();
			     
			    	public static void main(String args[]) throws Exception {
			    		InputReader(System.in);
			    		pw = new PrintWriter(System.out);
			    		

			    		soln();
			    		pw.close();
			    	}
			     
			    	public static long gcd(long x, long y) {
			    		if (x == 0)
			    			return y;
			    		else
			    			return gcd( y % x,x);
			    	}
			    	
			    	private static int BinarySearch(int a[], int low, int high, int target) {
			    		if (low > high)
			    			return -1;
			    		int mid = low + (high - low) / 2;
			    		if (a[mid] == target)
			    			return mid;
			    		if (a[mid] > target)
			    			high = mid - 1;
			    		if (a[mid] < target)
			    			low = mid + 1;
			    		return BinarySearch(a, low, high, target);
			    	}
			    	
			    	public static String reverseString(String s) {
			    		StringBuilder sb = new StringBuilder(s);
			    		sb.reverse();
			    		return (sb.toString());
			    	}
			    	
			    	public static long pow(long n, long p) {
			    		if(p==0)
			    			return 1;
			    		if(p==1)
			    			return n%mod;
			    		if(p%2==0){
			    			long temp=pow(n, p/2);
			    		return (temp*temp)%mod;
			    		}else{
			    			 	long temp=pow(n,p/2);
			    			 	temp=(temp*temp)%mod;
			    			 	return(temp*n)%mod;
			    			 	
			    		}
			    	}
			     
			    		
			     
			    	public static int[] id20(int[] f) {
			    		int[] to = new int[f.length];
			    		{
			    			int[] b = new int[65537];
			    			for (int i = 0; i < f.length; i++)
			    				b[1 + (f[i] & 0xffff)]++;
			    			for (int i = 1; i <= 65536; i++)
			    				b[i] += b[i - 1];
			    			for (int i = 0; i < f.length; i++)
			    				to[b[f[i] & 0xffff]++] = f[i];
			    			int[] d = f;
			    			f = to;
			    			to = d;
			    		}
			    		{
			    			int[] b = new int[65537];
			    			for (int i = 0; i < f.length; i++)
			    				b[1 + (f[i] >>> 16)]++;
			    			for (int i = 1; i <= 65536; i++)
			    				b[i] += b[i - 1];
			    			for (int i = 0; i < f.length; i++)
			    				to[b[f[i] >>> 16]++] = f[i];
			    			int[] d = f;
			    			f = to;
			    			to = d;
			    		}
			    		return f;
			    	}
			     
			    	public static int id23(final int a) {
			    		int b = 1;
			    		while (b < a) {
			    			b = b << 1;
			    		}
			    		return b;
			    	}
			     
			    	public static boolean id18(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
			    		int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
			    		int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;
			     
			    		if ((s < 0) != (t < 0))
			    			return false;
			     
			    		int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
			    		if (A < 0.0) {
			    			s = -s;
			    			t = -t;
			    			A = -A;
			    		}
			    		return s > 0 && t > 0 && (s + t) <= A;
			    	}
			     
			    	public static float area(int x1, int y1, int x2, int y2, int x3, int y3) {
			    		return (float) Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
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
			     
			    	

			     
			    	static long sort(int a[])
			    	{  int n=a.length;
			    		int b[]=new int[n];	
			    		return mergeSort(a,b,0,n-1);}
			    	static long mergeSort(int a[],int b[],long left,long right)
			    	{ long c=0;if(left<right)
			    	 {   long mid=left+(right-left)/2;
			    		 c= mergeSort(a,b,left,mid);
			    		 c+=mergeSort(a,b,mid+1,right);
			    		 c+=merge(a,b,left,mid+1,right); }	
			    		return c;	 }
			    	static long merge(int a[],int  b[],long left,long mid,long right)
			    	{long c=0;int i=(int)left;int j=(int)mid; int k=(int)left;
			    	while(i<=(int)mid-1&&j<=(int)right)
			    	{ if(a[i]>a[j]) {b[k++]=a[i++]; }
			    	else	{ b[k++]=a[j++];c+=mid-i;}}
			    	while (i <= (int)mid - 1)   b[k++] = a[i++]; 
			    	while (j <= (int)right) b[k++] = a[j++];
			    	for (i=(int)left; i <= (int)right; i++) 
			    		a[i] = b[i];  return c;  }
			    	public static boolean id7(String large, String small, int largeLen, int smallLen) {
			    		

			    		if (largeLen == 0)
			    			return false;
			    		if (smallLen == 0)
			    			return true;
			    		

			    		if (large.charAt(largeLen - 1) == small.charAt(smallLen - 1))
			    			id7(large, small, largeLen - 1, smallLen - 1);
			    		

			    		return id7(large, small, largeLen - 1, smallLen);
			    	}
			     
			    	

			    	

			     
			    	public static void InputReader(InputStream stream1) {
			    		stream = stream1;
			    	}
			     
			    	private static boolean isWhitespace(int c) {
			    		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			    	}
			     
			    	private static boolean id11(int c) {
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
			    		} while (!id11(c));
			    		return res.toString();
			    	}
			     
			    	private static int[] id3(int n) {
			    		int[] arr = new int[n];
			    		for (int i = 0; i < n; i++) {
			    			arr[i] = nextInt();
			    		}
			    		return arr;
			    	}
			     
			    	private static int[][] id16(int n, int m) {
			    		int[][] arr = new int[n][m];
			    		for (int i = 0; i < n; i++) {
			    			for (int j = 0; j < m; j++) {
			    				arr[i][j] = nextInt();
			    			}
			    		}
			    		return arr;
			    	}
			    	private static char[][] id10(int n,int m){
			    		char [][]c=new char[n][m];
			    		for(int i=0;i<n;i++){
			    			String s=nextLine();
			    			for(int j=0;j<s.length();j++){
			    				c[i][j]=s.charAt(j);
			    			}
			    		}
			    		return c;
			    	}
			     
			    	private static long[] id22(int n) {
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
			     
			    	private interface id19 {
			    		public boolean id1(int ch);
			    	}
			
			    	

			    	static int[] ht, lev,indeg,sub_size;
			    	static boolean visited[];
			    	
			    	static LinkedList<Integer> adj[];
			    	
			    	private static void id2(){
			    		Queue <Integer> q=new LinkedList<Integer>();
			    		for(int i=1;i<indeg.length;i++){
			    			if(indeg[i]==0){
			    				q.add(i);
			    		for(int j=0;j<adj[i].size();j++){
			    			indeg[adj[i].get(j)]--;
			    		}
			    			}
			    		}
			    		q.add(-1);
			    		while(q.size()>2){
			    			int temp=q.poll();
			    			if(temp==-1){
			    				q.add(temp);
			    			}else{
			    				for(int j=0;j<adj[temp].size();j++){
					    			indeg[adj[temp].get(j)]--;
					    		if(indeg[adj[temp].get(j)]==0)
					    			q.add(adj[temp].get(j));
			    				}
			    				
			    			}
			    		}
			    		int ele1=q.poll();
			    		if(ele1==-1){
			    			pw.println("center "+q.poll());
			    		}else{
			    			pw.println("Center-1 "+q.poll() +"\n Center-2 "+q.poll());
			    		}
			    		
			    	}
			    	
			    	private static void height (int par,int curr){
			    		visited[curr]=true;
			    		for(int x:adj[curr]){
			    			if(!visited[x]){
			    				height(curr,x);
			    			}
			    		}
			    		ht[par]=Math.max(ht[par], ht[curr]+1);
			    	

			    	sub_size[par]+=sub_size[curr];
			    	}
			    	private static int BFS(int st){
			    		
			    		Arrays.fill(lev, 0);
			    		visited[st]=true;
			    		Queue<Integer> q=new LinkedList<Integer>();
			    		q.add(st);
			    		int far=-1;
			    		while(!q.isEmpty()){
			    			int top=q.poll();
			    			far=top;
			    			for(int x:adj[top]){
			    				if(!visited[x])
			    				{
			    					q.add(x);
			    					lev[x]=(lev[top]+1);
			    				visited[x]=true;	
			    				}
			    			}
			    		}
				    	return far;
			    	}
			    	private static void soln() {
			    	
			    		int n=nextInt();
			    		int a[]=id3(n);
			    		HashSet<Integer> hs=new HashSet<Integer>();
			    		HashMap<Integer,Integer> hm=new HashMap<>();
			    		int start=1,end=-1;
			    		long c=0;
			    		Pair p[]=new Pair[300001];
			    		int ind=0;
			    		for(int i=0;i<n;i++){
			    			if(hs.contains(a[i])){
			    				end=i+1;
			    				c++;
			    			p[ind]=new Pair(start,end);
			    				

			    			ind++;
			    			start=i+2;
			    				hs.clear();
			    			}else{
			    				hs.add(a[i]);
			    			}
			    		}
			    		if(end==-1){
			    			System.out.println(-1);
			    			System.exit(0);
			    		}
			    		if(end!=n){
			    			p[ind-1].len=n;
			    		

			    		c++;
			    		
			    		}
			    		
			    		System.out.println(ind);
			    		for(int i=0;i<ind;i++){
			    			pw.println(p[i].ind+" "+p[i].len);
			    		}
			    	}
			    	
			    		

			   		    
			    
			 }
			    class Hashing {
					 
					  static final int multiplier = 43;
					  static final Random rnd = new Random();
					  static final int mod1 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
					  static final int mod2 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
					  static final int id13 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod1)).intValue();
					  static final int id6 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod2)).intValue();
			 
					  long[] hash1, hash2;
					  long[] inv1, inv2;
					  int n;
			 
					  public Hashing(String s) {
					    n = s.length();
					    hash1 = new long[n + 1];
					    hash2 = new long[n + 1];
					    inv1 = new long[n + 1];
					    inv2 = new long[n + 1];
					    inv1[0] = 1;
					    inv2[0] = 1;
			 
					    long p1 = 1;
					    long p2 = 1;
					    for (int i = 0; i < n; i++) {
					      hash1[i + 1] = (hash1[i] + s.charAt(i) * p1) % mod1;
					      p1 = p1 * multiplier % mod1;
					      inv1[i + 1] = inv1[i] * id13 % mod1;
					      hash2[i + 1] = (hash2[i] + s.charAt(i) * p2) % mod2;
					      p2 = p2 * multiplier % mod2;
					      inv2[i + 1] = inv2[i] * id6 % mod2;
					    }
					  }
			 
					  public long getHash(int i, int r) {
						  i--;
					    return (((hash1[r] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
					        + (hash2[r] - hash2[i] + mod2) * inv2[i] % mod2;
					  }
				}
			   
			    
				class Pair implements Comparable<Pair>{
				   
					int ind;
					int len;
					Pair(int ind,int len){
						this.ind=ind;
						this.len=len;
					}
					@Override
					public int compareTo(Pair o) {
						

					

						
		return ind-o.ind;
					}
				
				}
			        class Graph{
			        	private static int V,level[][],count=-1,id14[],degree=0,id8=0;
			        	private Stack <Integer>st=new Stack();
			        	private static LinkedList<Integer > adj[];
			        	private boolean[][] Visite;
			        	private static boolean [] Visited;
			        	private static HashSet<Integer> Vis=new HashSet();
			        	private static Stack<Integer> id9=new Stack<>();
			        	private static HashMap<String,Integer> hm=new HashMap<>();
			        	private static int ht[];
			  
				    
				    	
			    Graph(int V){
			    V++;
			    this.V=(V);
			    adj=new LinkedList[V];
			    Visite=new boolean[100][100];
			    ht=new int[V];
		 	    Visited=new boolean[V];
			    level=new int[100][100];
			    id14=new int[V]; 
			   for(int i=0;i<V;i++)
				   adj[i]=new LinkedList<Integer>();
			
			    }
			    
			   void addEdge(int v,int w){
			    	
			    	if(adj[v]==null){
			    		adj[v]=new LinkedList();
			    	}
			    	adj[v].add(w);
			     
			    	
			    }
			   
			   private static void height (int par,int curr){
		    		Visited[curr]=true;
		    		for(int x:adj[curr]){
		    			if(!Visited[x]){
		    				height(curr,x);
		    			}
		    		}
		    		ht[par]=Math.max(ht[par], ht[curr]+1);
		    	}
			  
			 public static void top_ans(){
			while(id9.size()!=0)
		{
			System.out.print(hm.get(id9.peek()));
		id9.pop();
		}
			
			 }
			 public static void id21(int startVert){
				 if(!Vis.contains(startVert)){
					 id17(startVert);
				 }
			 }
			    public static void id17(int id12){
			    	Vis.add(id12);
			    	Iterator<Integer> it=adj[id12].listIterator();
			    	
			    	while(it.hasNext()){
			    		int n=it.next();
			   

			    		if(!Vis.contains(n)){
			    			id17(n);
			    		}
			    		
			    	}
			    	id9.push(id12);
			    }
			    
			    public static int id0(int startVert){
			    	Visited=new boolean[V];
			    	for(int i=1;i<V;i++){
			    		id14[i]=-1;
			    	}
			    

			    	Queue<Integer> q=new LinkedList<Integer>();
			    	q.add(startVert);
			    	
			    	id14[startVert]=0;
			    	while(!q.isEmpty()){
			    		int top=q.poll();
			    		
			    		Iterator<Integer> i= adj[top].listIterator();
			    		while(i.hasNext()){
			    			int n=i.next();
			    	

			    			if(!Visited[n]){
			    				q.add(n);
			    				Visited[n]=true;
			    				id14[n]=id14[top]+1;
			    			
			    			}
			    		}
			    	}
			    
			    

			    	return -1;
			    }
			    public static int getAn(int end){
			    	return id14[end];
			    }
			    public int getEd(){
			    	return degree/2;
			    }
			    public void get(int from,int to){
			    	int h=id14[from]-id14[to];
			    	if(h<=0){
			    		System.out.println(-1);
			    	}else{
			    		System.out.println(h-1);
			    	}
			    }
			    private static boolean check(int x,int y,char c[][]){
				
					if((x>=0 && y>=0) && (x<c.length && y<c[0].length) && c[x][y]!='
						
						return true;
					}
					return false;
				}
			    public int BFS(int x,int y,int k,char[][] c)
			    {
			    	 LinkedList<Pair> queue = new LinkedList<Pair>();
			        

			   

			       int count=0;
			   level[x][y]=-1;
			   c[x][y]='M';
			        while (!queue.isEmpty())
			        {
			            Pair temp = queue.poll();
			        
			            
			        }
			        return V;
			    }
			    
			   
			    
			     public long dfs(int startVertex,int end){
			    

			    	 Visited=new boolean[V];
			    	 if(!Visited[startVertex])  {
			    
			   return dfsUtil(startVertex,end);
			    	

			    	}
			    	 
			    
			     
			    return 0;
			    	}
			 private long dfsUtil(int startVertex,int end) {

				 int c=1;
			
				 long cout=0;
			      degree=0;
			    	Visited[startVertex]=true;
			    	id14[startVertex]=0;
			      st.push(startVertex);
			      int temp=-1;
			      
			    while(!st.isEmpty()){
			    	
			    	int top=st.pop();
			    temp=Math.max(temp, top);
			    

			    	Iterator<Integer> i=adj[top].listIterator();
			     
			    while(i.hasNext()){
			    

			    	int n=i.next();
			     if( !Visited[n]){
			    				Visited[n]=true;
			    				
			    			

			    				c++;
			    				st.push(n);
			    					id14[n]=id14[top]+1;
			    					if(n==end){
			    	    				return id14[n];	
			    	    				}
			    		 }
			         }
			 }
			 

			    if(id14[temp]+(end-temp)<=0){
			    	return end-startVertex;
			    }
			    return Math.min(end-startVertex, id14[temp]+(end-temp));
			    	
			    }
			        
			        }     
			       	        
			    class Dsu{
			    	private int rank[], parent[] ,n;
			    	
			    	Dsu(int size){
			    		this.n=size+1;
			    		rank=new int[n];
			    		parent=new int[n];
			    	makeSet();
			    	}
			    	
			    	void makeSet(){
			    		for(int i=0;i<n;i++){
			    			parent[i]=i;
			    		}
			    	}
			    	
			    	int find(int x){
			    		if(parent[x]!=x){
			    			
			    			parent[x]=find(parent[x]);
			    		}
			    		return parent[x];
			    	}	
			    	
			    	void union(int x,int y){
			    		int xRoot=find(x);
			    		int yRoot=find(y);
			    		
			    		if(xRoot==yRoot)
			    			return;
			    		if(rank[xRoot]<rank[yRoot]){
			    		parent[xRoot]=yRoot;	
			    		}else if(rank[yRoot]<rank[xRoot]){
			    			parent[yRoot]=xRoot;
			    		}else{
			    			parent[yRoot]=xRoot;
			    			rank[xRoot]++;
			    		}
			    		
			    	}
			     
			    }
			    class Heap{
			    	
			    	public static void id5(long []a,int size){
			    		
			    		for(int i=size/2;i>0;i--){
			    			id4(a, i,size);
			    		}
			    		
			    			}
			    	private static void id4(long[] a,int i,int size){
			    		int left_child=2*i;
			    		int right_child=(2*i+1);
			    		int largest=0;
			    		
			    		if(left_child<size && a[left_child]>a[i]){
			    			largest=left_child;
			    		}else{
			    			largest=i;
			    		}
			    		
			    		if(right_child<size && a[right_child]>a[largest]){
			    			largest=right_child;
			    		}
			    		if(largest!=i){
			    			long temp=a[largest];
			    			a[largest]=a[i];
			    			a[i]=temp;
			    			id4(a, largest,size);
			    		}
			    	}
			    	private static void id15(int[] a,int i){
			    		int left_child=2*i;
			    		int right_child=(2*i+1);
			    		int largest=0;
			    		
			    		if(left_child<a.length && a[left_child]<a[i]){
			    			largest=left_child;
			    		}else{
			    			largest=i;
			    		}
			    		
			    		if(right_child<a.length && a[right_child]<a[largest]){
			    			largest=right_child;
			    		}
			    		if(largest!=i){
			    			int temp=a[largest];
			    			a[largest]=a[i];
			    			a[i]=temp;
			    			id15(a, largest);
			    		}
			    	}
			    	public static void extract_max(int size,long a[]){
			    		if(a.length>1){
			    			long max=a[1];
			    			a[1]=a[a.length-1];
			    			size--;
			    			id4(a, 1,a.length-1);
			    		}
			    	}
			    }
			    
			    class MyComp implements Comparator<Long>{
			        
					@Override
					public int compare(Long o1, Long o2) {
						if(o1<o2){
							return 1;
						}else if(o1>o2){
							return -1;
						}
						return 0;
						
					}
			    }
	
	 
	 
