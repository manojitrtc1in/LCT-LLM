
	
	    
	     
	            
	    import java.io.*;
	    import java.math.*;
	    import java.util.*;
	    import javax.print.attribute.SetOfIntegerSyntax;
	     
	    public class CodeMonk_Graph{
	    	private static InputStream stream;
	    	private static byte[] buf = new byte[1024];
	    	private static int curChar;
	    	private static int numChars;
	    	private static SpaceCharFilter filter;
	    	private static PrintWriter pw;
	    	private static long count = 0,mod=1000000007;
	    	private static TreeSet<Integer>ts[]=new TreeSet[200000];
	    	private static HashSet hs=new HashSet();
	     
	        public static void main(String[] args) {
	        	InputReader(System.in);
	    		pw = new PrintWriter(System.out); 
	            new Thread(null ,new Runnable(){
	               public void run(){
	                   try{
	                       soln();
	                       pw.close();
	                   } catch(Exception e){
	                       e.printStackTrace();
	                   }
	               }
	           },"1",1<<26).start();
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
	     
	    		
	     
	    	public static int[] radixSort(int[] f) {
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
	     
	    	public static int nextPowerOf2(final int a) {
	    		int b = 1;
	    		while (b < a) {
	    			b = b << 1;
	    		}
	    		return b;
	    	}
	     
	    	public static boolean PointInTriangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
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
	    	public static boolean isSubSequence(String large, String small, int largeLen, int smallLen) {
	    		

	    		if (largeLen == 0)
	    			return false;
	    		if (smallLen == 0)
	    			return true;
	    		

	    		if (large.charAt(largeLen - 1) == small.charAt(smallLen - 1))
	    			isSubSequence(large, small, largeLen - 1, smallLen - 1);
	    		

	    		return isSubSequence(large, small, largeLen - 1, smallLen);
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
	     
	    	private static int[][] next2dArray(int n, int m) {
	    		int[][] arr = new int[n][m];
	    		for (int i = 0; i < n; i++) {
	    			for (int j = 0; j < m; j++) {
	    				arr[i][j] = nextInt();
	    			}
	    		}
	    		return arr;
	    	}
	    	private static char[][] nextCharArray(int n,int m){
	    		char [][]c=new char[n][m];
	    		for(int i=0;i<n;i++){
	    			String s=nextLine();
	    			for(int j=0;j<s.length();j++){
	    				c[i][j]=s.charAt(j);
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
	
		

	    	private static void soln() {
	    		

	  
	    		int n=nextInt();
	    		int a[]=new int [n+1];
	    		int parent_mat=-1;
	    		for(int i=1;i<=n;i++){
	    			a[i]=nextInt();
	    			if(i==a[i])
	    				parent_mat=i;
	    		}
	    	
	    		HashSet<Integer> usable =new HashSet();
	    		Dsu d=new Dsu(n);
	    		for(int i=1;i<=n;i++){
	    			if(d.find(i)==d.find(a[i]) && i!=parent_mat && a[i]!=parent_mat){
	    				usable.add(i);
	    			}else
	    			d.union(i, a[i]);
	    		}
	    		
	    		HashSet<Integer> hs=new HashSet<Integer>();
	    		for(int i=1;i<=n;i++){
	    			int pa=d.find(i);
	    		

	    			
	    			hs.add(pa);
	    		}
	    	
	    		ArrayList<Integer> elements_in_par[]=new ArrayList[n+1];
	    		for(int i=1;i<=n;i++)
	    			elements_in_par[i]=new ArrayList<Integer>();
	    		for(int i=1;i<=n;i++){
	    			elements_in_par[d.find(i)].add(i);
	    		}
	    		
	    		long c=0;
	    		if(parent_mat!=-1){
	    			for(int x:hs){
	    				if(!elements_in_par[x].contains(parent_mat)){
	    				for(int i=0;i<elements_in_par[x].size();i++){
	    					if(usable.contains(elements_in_par[x].get(i))){
	    						a[elements_in_par[x].get(i)]=parent_mat;
	    						break;
	    					}
	    				}
	    				c++;}
	    			}
	    		
	    		
	    		}else{
	    			for(int x:hs){
	    			for(int i=0;i<elements_in_par[x].size();i++){
	    				if(usable.contains(elements_in_par[x].get(i))){
	    				parent_mat=elements_in_par[x].get(i);
	    				a[parent_mat]=parent_mat;
	    				c++;
	    				break;
	    				}
	    			}
	    			break;
	    			}
	    			for(int x:hs){
	    				if(!elements_in_par[x].contains(parent_mat)){
	    				for(int i=0;i<elements_in_par[x].size();i++){
	    					if(usable.contains(elements_in_par[x].get(i))){
	    						a[elements_in_par[x].get(i)]=parent_mat;
	    						break;
	    					}
	    				}
	    				c++;}
	    		}
	    		
	    	}	    	
	    
	    pw.println(c);
	    		for(int i=1;i<=n;i++){
	    			pw.print(a[i]+" ");
	    		}
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
				

			

return len-o.len;
			}
		
		}
	        class Graph{
	        	private static int V,level[][],count=-1,lev_dfs[],degree=0,no_vert_conn_comp=0;
	        	private Stack <Integer>st=new Stack();
	        	private static LinkedList<Integer > adj[];
	        	private boolean[][] Visite;
	        	private static boolean [] Visited;
	        	private static HashSet<Integer> Vis=new HashSet();
	        	private static Stack<Integer> topo_sort=new Stack<>();
	        	private static HashMap<String,Integer> hm=new HashMap<>();
	  
		    
		    	
	    Graph(int V){
	    V++;
	    this.V=(V);
	    adj=new LinkedList[V];
	    Visite=new boolean[100][100];
	    
 	    Visited=new boolean[V];
	    level=new int[100][100];
	    lev_dfs=new int[V]; 
	   for(int i=0;i<V;i++)
		   adj[i]=new LinkedList<Integer>();
	
	    }
	    void setup(int n,int m){
	    	

    		int co=1;
	    	for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				String s="";
    				s+=(i)+" "+(j);
    				hm.put(s, co);
    			co++;
    			}
    		}
	    }
	   void addEdge(int v,int w){
	    	
	    	if(adj[v]==null){
	    		adj[v]=new LinkedList();
	    	}
	    	adj[v].add(w);
	     
	    	
	    }
	  
	 public static void top_ans(){
	while(topo_sort.size()!=0)
{
	System.out.print(hm.get(topo_sort.peek()));
topo_sort.pop();
}
	
	 }
	 public static void topoSort(int startVert){
		 if(!Vis.contains(startVert)){
			 topoSortUtil(startVert);
		 }
	 }
	    public static void topoSortUtil(int curr_Vert){
	    	Vis.add(curr_Vert);
	    	Iterator<Integer> it=adj[curr_Vert].listIterator();
	    	
	    	while(it.hasNext()){
	    		int n=it.next();
	   

	    		if(!Vis.contains(n)){
	    			topoSortUtil(n);
	    		}
	    		
	    	}
	    	topo_sort.push(curr_Vert);
	    }
	    
	    public static int BFS2(int startVert){
	    	Visited=new boolean[V];
	    	for(int i=1;i<V;i++){
	    		lev_dfs[i]=-1;
	    	}
	    

	    	Queue<Integer> q=new LinkedList<Integer>();
	    	q.add(startVert);
	    	
	    	lev_dfs[startVert]=0;
	    	while(!q.isEmpty()){
	    		int top=q.poll();
	    		
	    		Iterator<Integer> i= adj[top].listIterator();
	    		while(i.hasNext()){
	    			int n=i.next();
	    	

	    			if(!Visited[n]){
	    				q.add(n);
	    				Visited[n]=true;
	    				lev_dfs[n]=lev_dfs[top]+1;
	    			
	    			}
	    		}
	    	}
	    
	    

	    	return -1;
	    }
	    public static int getAn(int end){
	    	return lev_dfs[end];
	    }
	    public int getEd(){
	    	return degree/2;
	    }
	    public void get(int from,int to){
	    	int h=lev_dfs[from]-lev_dfs[to];
	    	if(h<=0){
	    		System.out.println(-1);
	    	}else{
	    		System.out.println(h-1);
	    	}
	    }
	    private static boolean check(int x,int y,char c[][]){
		
			if((x>=0 && y>=0) && (x<c.length && y<c[0].length) && c[x][y]!='#'){
				
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
	    	lev_dfs[startVertex]=0;
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
	    					lev_dfs[n]=lev_dfs[top]+1;
	    					if(n==end){
	    	    				return lev_dfs[n];	
	    	    				}
	    		 }
	         }
	 }
	 

	    if(lev_dfs[temp]+(end-temp)<=0){
	    	return end-startVertex;
	    }
	    return Math.min(end-startVertex, lev_dfs[temp]+(end-temp));
	    	
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
	    	
	    	public static void build_max_heap(long []a,int size){
	    		
	    		for(int i=size/2;i>0;i--){
	    			max_heapify(a, i,size);
	    		}
	    		
	    			}
	    	private static void max_heapify(long[] a,int i,int size){
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
	    			max_heapify(a, largest,size);
	    		}
	    	}
	    	private static void min_heapify(int[] a,int i){
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
	    			min_heapify(a, largest);
	    		}
	    	}
	    	public static void extract_max(int size,long a[]){
	    		if(a.length>1){
	    			long max=a[1];
	    			a[1]=a[a.length-1];
	    			size--;
	    			max_heapify(a, 1,a.length-1);
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