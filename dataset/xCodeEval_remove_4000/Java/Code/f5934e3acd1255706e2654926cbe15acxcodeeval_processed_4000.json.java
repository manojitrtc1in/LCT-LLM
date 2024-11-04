



		     
		            
		    import java.io.*;
		    import java.math.*;
		    import java.util.*;
		    import javax.print.attribute.SetOfIntegerSyntax;
		     
		    public class TR {
		    	private static InputStream stream;
		    	private static byte[] buf = new byte[1024];
		    	private static int curChar;
		    	private static int numChars;
		    	private static id18 filter;
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
		     
		    		
		     
		    	public static int[] id19(int[] f) {
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
		     
		    	public static int id21(final int a) {
		    		int b = 1;
		    		while (b < a) {
		    			b = b << 1;
		    		}
		    		return b;
		    	}
		     
		    	public static boolean id17(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
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
		     
		    	

		     
		    	static long sort1(int a[])
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
		    	public static boolean id6(String large, String small, int largeLen, int smallLen) {
		    		

		    		if (largeLen == 0)
		    			return false;
		    		if (smallLen == 0)
		    			return true;
		    		

		    		if (large.charAt(largeLen - 1) == small.charAt(smallLen - 1))
		    			id6(large, small, largeLen - 1, smallLen - 1);
		    		

		    		return id6(large, small, largeLen - 1, smallLen);
		    	}
		     
		    	

		    	

		     
		    	public static void InputReader(InputStream stream1) {
		    		stream = stream1;
		    	}
		     
		    	private static boolean isWhitespace(int c) {
		    		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		    	}
		     
		    	private static boolean id9(int c) {
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
		    		} while (!id9(c));
		    		return res.toString();
		    	}
		     
		    	private static int[] id3(int n) {
		    		int[] arr = new int[n];
		    		for (int i = 0; i < n; i++) {
		    			arr[i] = nextInt();
		    		}
		    		return arr;
		    	}
		     
		    	private static int[][] id14(int n, int m) {
		    		int[][] arr = new int[n][m];
		    		for (int i = 0; i < n; i++) {
		    			for (int j = 0; j < m; j++) {
		    				arr[i][j] = nextInt();
		    			}
		    		}
		    		return arr;
		    	}
		    	private static char[][] id8(int n,int m){
		    		char [][]c=new char[n][m];
		    		for(int i=0;i<n;i++){
		    			String s=nextLine();
		    			for(int j=0;j<s.length();j++){
		    				c[i][j]=s.charAt(j);
		    			}
		    		}
		    		return c;
		    	}
		     
		    	private static long[] id20(int n) {
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
		     
		    	private interface id18 {
		    		public boolean id1(int ch);
		    	}
		     
		    	   
			    public static int find(int parent[], int i)
			    {
			        if (parent[i] == -1)
			            return i;
			        return find(parent, parent[i]);
			    }
			     
			    

			    public static void Union(int parent[], int x, int y)
			    {
			        int xset = find(parent, x);
			        int yset = find(parent, y);
			        parent[xset] = yset;
			    }
		    	

		
	 
		    
				private static void soln() {
		    	
					Scanner in = new Scanner(System.in);
			    
					int n = in.nextInt();
					in.nextLine();
					long arr[] = new long[n];
					for(int i = 0;i<n;i++){
						arr[i] = in.nextLong();
					}
					
					long s = 0;
					
					for(int i = 0;i<n;i++){
						s += (arr[i]-1)*(i+1) + 1;
					}
					
					pw.println(s);
					
					
		    	}


				
				
				
		    	public static boolean compq(Queue<Integer> q1,Queue<Integer> q2){
		    		
		    		
		    		
		    		if(q1.size() != q2.size())
		    			return false;
		    		
		    		Queue<Integer> c1 = new LinkedList<Integer>();
		    		Queue<Integer> c2 = new LinkedList<Integer>();
		    		
		    		for(int i = 0;i<q1.size();i++){
		    			int a =q1.remove();
		    			c1.add(a);
		    			q1.add(a);
		    			int b = q2.remove();
		    			c2.add(b);
		    			q2.add(b);
		    		

		    		}
		    		
		    		int n =q1.size();
		    		
		    		for(int i = 0;i<n;i++){
		    			if(q1.peek() != q2.peek()){
		    				q1 =c1;
		    				q2 =c2;
		    				return false;
		    			}else{
		    				q1.remove();
		    				q2.remove();
		    			}
		    		}
		    		
		    		q1 =c1;
		    		q2 =c2;
		    		return true;
		    	} 
		    	
		    	public static BigInteger min(BigInteger a,BigInteger b){
		    		if(a.compareTo(b) == -1){
		    			return a;
		    		}else{
		    			return b;
		    		}
		    	}
		    	
		    	public static BigInteger max(BigInteger a,BigInteger b){
		    		if(a.compareTo(b) == -1){
		    			return b;
		    		}else{
		    			return a;
		    		}
		    	}
		    	 public static int toDecimal(String str) {
		    		    int decimal = 0;
		    		    int base0 = (int)'0';
		    		    char ch;
		    		    for (int i = 0; i < str.length(); i++) {
		    		      ch = str.charAt(i);
		    		      if (id15(ch)) {
		    		        return 0;
		    		      }
		    		      decimal = decimal * 2 + ((int)str.charAt(i) - base0);
		    		    }
		    		    return decimal;
		    		  }
		    	 
		    	 private static boolean id15(char ch) {
		    		    return '1' < ch || ch < '0';
		    		  }
		 }
		   
		   
		    class point{
		    	int x;
		    	int y;
		    }
		    
		    
		    class Trie{
		    	
		    	int val;
		    	Trie[] arr = new Trie[2];
		    	
		    	public Trie(){
		    		arr[0] = null;
		    		arr[1] = null;
		    	}
		    	public static void insert(Trie t, int pre){
		    		
		    		Trie temp = t;
		    		
		    		for(int i = Integer.SIZE - 1;i>=0;i--){
		    			int b = pre & (1<<i);
		    			
		    			

		    			if(temp.arr[b] == null){
		    				Trie y = new Trie();
		    				y.val = 0;
		    				y.arr[0] = null;
		    				y.arr[1] = null;
		    				
		    				temp = y;
		    			}
		    			
		    			temp = temp.arr[b];
		    		}
		    		
		    		temp.val = pre;
		    	}
		    	
		    	public static int query(Trie root, int pre){
		    		Trie temp = root;
		    	    for (int i=Integer.SIZE-1; i>=0; i--)
		    	    {
		    	        

		    	        int val = pre & (1<<i);
		    	 
		    	        

		    	        

		    	        if (temp.arr[1-val]!=null)
		    	            temp = temp.arr[1-val];
		    	 
		    	        

		    	        

		    	        else if (temp.arr[val] != null)
		    	            temp = temp.arr[val];
		    	    }
		    	    return pre^(temp.val);
		    	}
		    	
		    	public static int id10(int arr[], int n)
		    	{
		    	    

		    	    Trie root;
		    	    root = new Trie();
    				root.val = 0;
    				
		    	    insert(root, 0);
		    	 
		    	    

		    	    int result = Integer.MIN_VALUE, id12 =0;
		    	 
		    	    

		    	    for (int i=0; i<n; i++)
		    	    {
		    	        

		    	        id12 = id12^arr[i];
		    	        insert(root, id12);
		    	 
		    	        

		    	        

		    	        result = Math.max(result, query(root, id12));
		    	    }
		    	    return result;
		    	}
		    	
		    }
		    
			class Pair implements Comparable<Pair>{
			    long id; 
				long w;
				long h;
				Pair(long id,long w,long h){
					this.id=id;
					this.w=w;
					this.h=h;
				}
				@Override
				public int compareTo(Pair o) {
					

				

	 
					if(w>o.w)
						return 1;
					else if(w<o.w)
						return -1;
					else{
						if(h>o.h){
							return 1;
						}else if(o.h>h)
							return -1;
						else return 0;
					}
					
				}
			
			}
		        class Graph{
		        	private static int V,level[][],count=-1,id11[],degree=0,id7=0;
		        	private Stack <Integer>st=new Stack();
		        	private static LinkedList<Integer > adj[];
		        	private boolean[][] Visite;
		        	private static boolean [] Visited;
		        	private static TreeSet<Integer> ts=new TreeSet();
		    Graph(int V){
		    V++;
		    this.V=(V);
		    adj=new LinkedList[V];
		    Visite=new boolean[100][100];
	 
	 	   Visited=new boolean[V];
		    level=new int[100][100];
		   id11=new int[V]; 
		   for(int i=0;i<V;i++)
			   adj[i]=new LinkedList<Integer>();
		    }
		     
		    void addEdge(int v,int w){
		    	
		    	if(adj[v]==null){
		    		adj[v]=new LinkedList();
		    	}
		    	if(adj[w] == null){
		    		adj[w] = new LinkedList();
		    	}
		    	adj[v].add(w);
		    
		    	
		    }
		    
		    
		    public static int conCop(int startVert){
		    	Visited=new boolean[V];
		    	int totalcon = 1;
		    	Queue<Integer> q=new LinkedList<Integer>();
		    	q.add(startVert);
		    	Visited[startVert] = true;
		    	
		    	while(!q.isEmpty()){
		    		int top=q.poll();
		    		
		    		Iterator<Integer> i= adj[top].listIterator();
		    		while(i.hasNext()){
		    			int n=i.next();
		    			if(!Visited[n]){
		    				q.add(n);
		    				Visited[n]=true;
		    				totalcon++;	    			
		    			}
		    		}
		    	}
		    	q.clear();
		    	return totalcon;
		    }
		    
		    
		    public static int id2(int startVert){
		    	Visited=new boolean[V];
		    
		    	Queue<Integer> q=new LinkedList<Integer>();
		    	q.add(startVert);
		    	Visited[startVert] = true;
		    	long ed = adj[startVert].size();
		    	while(!q.isEmpty()){
		    		int top=q.poll();
		    		
		    		Iterator<Integer> i= adj[top].listIterator();
		    		while(i.hasNext()){
		    			int n=i.next();
		    			if(!Visited[n]){
		    				q.add(n);
		    				Visited[n]=true;
		    				ed+= adj[n].size();
		    			}
		    		}
		    	}
		    	q.clear();
		    	return (int)ed/2;
		    }
		 
		    public static int id0(int startVert){
		    	Visited=new boolean[V];
		    	for(int i=0;i<V;i++){
		    		id11[i]=-1;
		    	}
		    	Queue<Integer> q=new LinkedList<Integer>();
		    	q.add(startVert);
		    	
		    	id11[startVert]=0;
		    	while(!q.isEmpty()){
		    		int top=q.poll();
		    		
		    		Iterator<Integer> i= adj[top].listIterator();
		    		while(i.hasNext()){
		    			int n=i.next();
		    			if(!Visited[n]){
		    				q.add(n);
		    				Visited[n]=true;
		    				id11[n]=id11[top]+1;
		    				

		    			}
		    		}
		    	}
		    	q.clear();
		    	
		    	int mx = 0;
		    	for(int i = 0;i<V;i++){
		    		mx = Math.max(mx, id11[i]);
		    	}
		    	return mx;
		    }
		    public int getEd(){
		    	return degree/2;
		    }
		    public void get(int from,int to){
		    	int h=id11[from]-id11[to];
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
		            

		            

		            
		            c[x][y]='M';
		      

		         count++;
		     	if(count==k)
		         {
		         	for(int i=0;i<c.length;i++){
		         		for(int j=0;j<c[0].length;j++){
		         			if(c[i][j]=='M'){
		         				System.out.print(".");
		         			}
		         			else if(c[i][j]=='.')
		         				System.out.print("X");
		         			else
		         				System.out.print(c[i][j]);
		         		}
		         		System.out.println();
		         	}
		         System.exit(0);
		         }
		     	
		         

		           

		           
		        }
		        return V;
		    }
		    
		    private void getAns(int startVertex){
		    	for(int i=0;i<adj[startVertex].size();i++){
		    		int ch=adj[startVertex].get(i);
		    		for(int j=0;j<adj[ch].size();j++){
		    			int ch2=adj[ch].get(j);
		    			if(adj[ch2].contains(startVertex)){
		    				System.out.println(startVertex+" "+ch+" "+ch2);
		    				System.exit(0);
		    			}
		    		}
		    	}
		    }
		    
		     public long dfs(int startVertex){
		    

		    	 
		    	 if(!Visited[startVertex])  {
		    
		   return dfsUtil(startVertex,Visited);
		    	

		    	}
		    	 
		    
		     
		    return 0;
		    	}
		 private long dfsUtil(int startVertex, boolean[] Visited) {

		 
			 int c=1;
			 long cout=0;
		      degree=0;
		    	Visited[startVertex]=true;
		    	id11[startVertex]=1;
		      st.push(startVertex);
		    while(!st.isEmpty()){
		    	
		    	int top=st.pop();
		    int child=adj[top].size();
		    if(top!=startVertex)
		    	child--;
		    
		    	ts.add(top);
		    	Iterator<Integer> i=adj[top].listIterator();
		     degree+=adj[top].size();
		     
		    while(i.hasNext()){
		    
		    	int n=i.next();
		     if( !Visited[n]){
		    				Visited[n]=true;
		    					st.push(n);
		    					if(adj[n].size()-1>child)
		    					cout++;	
		    				c++;
		    					id11[n]=id11[top]+1;
		    			
		    		 }
		         }
		 }
		    return cout;
		    	
		    		
		    
		  

		   

		    	
		    
		    
		    
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
		    	private static void id13(int[] a,int i){
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
		    			id13(a, largest);
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
		    class Node{
		    	int d;
		    	int b;
		    	int i;
		    }
		    class MyComp implements Comparator<Node>{
		        
				@Override
				public int compare(Node o1, Node o2) {
					if(o1.d>o2.d){
						return 1;
					}else if(o1.d<o2.d){
						return -1;
					}else{
						return 0;
						
					}
					
					
				}
		    }
	
		    
		    class id16 implements Comparator<Node>{
		        
				@Override
				public int compare(Node o1, Node o2) {
					if(o1.b>o2.b){
						return 1;
					}else if(o1.b<o2.b){
						return -1;
					}else{
						return 0;
						
						
					}
					
					
				}
		    }