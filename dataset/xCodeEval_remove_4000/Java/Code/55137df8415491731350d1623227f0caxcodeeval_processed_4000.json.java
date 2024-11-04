    	
    		

    		    
    		     
    		            
    		    import java.io.*;
    		    import java.math.*;
    		    import java.util.*;
    		    import javax.print.attribute.SetOfIntegerSyntax;


    		     
    		    public class Practice{
    		    	private static InputStream stream;
    		    	private static byte[] buf = new byte[1024];
    		    	private static int curChar;
    		    	private static int numChars;
    		    	private static id12 filter;
    		    	private static PrintWriter pw;
    		    	private static long count = 0,mod=1000000007;
    		    

    		    
    		        public static void main(String[] args) {
    		        	InputReader(System.in);
    		    		pw = new PrintWriter(System.out); 
    		            new Thread(null ,new Runnable(){
    		               public void run(){
    		                   try{
    		                       id8();
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
    		     
    		    	private static int[] id2(int n) {
    		    		int[] arr = new int[n];
    		    		for (int i = 0; i < n; i++) {
    		    			arr[i] = nextInt();
    		    		}
    		    		return arr;
    		    	}
    		     
    		    	private static int[][] id11(int n, int m) {
    		    		int[][] arr = new int[n][m];
    		    		for (int i = 0; i < n; i++) {
    		    			for (int j = 0; j < m; j++) {
    		    				arr[i][j] = nextInt();
    		    			}
    		    		}
    		    		return arr;
    		    	}
    		    	private static char[][] id7(int n,int m){
    		    		char [][]c=new char[n][m];
    		    		for(int i=0;i<n;i++){
    		    			String s=nextLine();
    		    			for(int j=0;j<s.length();j++){
    		    				c[i][j]=s.charAt(j);
    		    			}
    		    		}
    		    		return c;
    		    	}
    		     
    		    	private static long[] id13(int n) {
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
    		     
    		    	private interface id12 {
    		    		public boolean id1(int ch);
    		    	}

    		    	static LinkedList<Integer> adj[];
    		    	static boolean Visited[];
    		    	static int[] level,startt,endt;
    		    	static  ArrayList<Integer> [] id3,id5;
    		    	private static void id8(){

    
    		    		int n=nextInt();
    		    		long k=nextLong();
    		    		long a[]=id13(n);
    		    		long b[]=id13(n);
    		    		long low=0,high=(long)3e9,ans=0;
    		    		while(low<=high){
    		    			long mid=(low+high)/2;
    		    			long pow=k;
    		    			boolean bo=true;
    		    			for(int i=0;i<n;i++){
    		    				long req=(mid*a[i]);
    		    				long ava=b[i];
    		    				if(ava<req){
    		    					long diff=req-ava;
    		    					if(pow<diff){
    		    						bo=false;
    		    						break;
    		    					}else{
    		    						pow-=diff;
    		    					}
    		    				}
    		    				
    		    			}
    		    			if(bo){
    		    				low=mid+1;
    		    				ans=mid;
    		    			}else{
    		    				high=mid-1;
    		    			}
    		    			
    		    		}
    		    		pw.println(ans);
    		    	}
    		    	static int timer=1;
    		    	public static void dfs2(int startVertex){
    		    		Visited[startVertex]=true;
    		    		startt[startVertex]=timer++;
    		    		
    		    		for(int n:adj[startVertex]){
    		    			if(!Visited[n]){
    		    				dfs2(n);
    		    			}
    		    		}
    		    		endt[startVertex]=timer++;
    		    	}
    		    	private static void buildgraph(int n){
    		    		adj=new LinkedList[n+1];
    		    		Visited=new boolean[n+1];
    		    		level=new int[n+1];
    		    		startt=new int[n+1];
    		    		endt=new int[n+1];
    		    		for(int i=0;i<=n;i++){
    		    			adj[i]=new LinkedList<Integer>();
    		    		}
    		    	}
    		    	private static void BFS(int startv){
    		    		Queue<Integer> q=new LinkedList<Integer>();
    		    		q.add(startv);
    		    		Visited[startv]=true;
    		    		while(!q.isEmpty()){
    		    			int top=q.poll();
    		    			for(int i:adj[top]){
    		    				if(!Visited[i]){
    		    					Visited[i]=true;
    		    					level[i]=level[top]+1;
    		    					q.add(i);
    		    				}
    		    			}
    		    		}
    		    	}
    		    }
    		    	class Pair implements Comparable<Pair>{
 	     			   
               	    	
        				long day,height;
        				Pair(long a,long b){
        				day=a;
        				height=b;
        				}
    					@Override
    					public int compareTo(Pair o) {
    						
  
    						return (int)(day-o.day);


    					}
               		
        		    
    			
    		    	}
    		        class Graph{
    		        	private static int V,level[][],count=-1,id10[],degree=0,id4=0;
    		        	private Stack <Integer>st=new Stack();
    		        	private static LinkedList<Integer > adj[];
    		        	private boolean[][] Visite;
    		        	private static boolean [] Visited;
    		        	private static HashSet<Integer> Vis=new HashSet();
    		        	private static Stack<Integer> id6=new Stack<>();
    		        	private static HashMap<String,Integer> hm=new HashMap<>();
    		  private static HashSet<String> hs=new HashSet();
    		private static HashSet<String > exist=new HashSet();
    		private static int a[];

    		
    		    Graph(int V){
    		    V++;
    		    this.V=(V);
    		    adj=new LinkedList[V];
    		    Visite=new boolean[100][100];
    		    
    	 	    Visited=new boolean[V];
    		    level=new int[100][100];
    		    id10=new int[V]; 
    		   for(int i=0;i<V;i++)
    			   adj[i]=new LinkedList<Integer>();
    		a=new int[V+1];
    		    }
    		   
    		    void setup(int d[]){
  
    		    	a=Arrays.copyOf(d, d.length);
    		    	
    		    }
    		    void ans(){
    		    	StringBuilder sb=new StringBuilder();
    		    	for(int i=1;i<a.length;i++){
    		    		sb.append(a[i]+" ");
    		    	}
    		    	System.out.println(sb);
    		    }
    		   void addEdge(int v,int w){
    		    
    		    	if(adj[v]==null){
    		    		adj[v]=new LinkedList();
    		    	}
    		    	adj[v].add(w);
    		    
    		    	
    		    
    		    	  	
    		    }
    		  
    		    public static int id0(int startVert){
    		    	Visited=new boolean[V];
    		    	for(int i=1;i<V;i++){
    		    		id10[i]=-1;
    		    	}
    		    

    		    	Queue<Integer> q=new LinkedList<Integer>();
    		    	q.add(startVert);
    		    	
    		    	id10[startVert]=0;
    		    	while(!q.isEmpty()){
    		    		int top=q.poll();
    		    		
    		    		Iterator<Integer> i= adj[top].listIterator();
    		    		while(i.hasNext()){
    		    			int n=i.next();
    		    	

    		    			if(!Visited[n]){
    		    				q.add(n);
    		    				Visited[n]=true;
    		    				id10[n]=id10[top]+1;
    		    			
    		    			}
    		    		}
    		    	}
    		    
    		    

    		    	return -1;
    		    }
    		    public static int getAn(){
    		    	if(ans==Long.MAX_VALUE)
    		    		ans=-1;
    		    	return 0;
    		    }
    		    public int getEd(){
    		    	return degree/2;
    		    }
    		    public void get(int from,int to){
    		    	int h=id10[from]-id10[to];
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
    		    static long ans=Long.MAX_VALUE;
    		    
    		   public static void dfs2(int startVert,int endVert,long need){
    			Visited[startVert]=true;
    			

    			   for(int x:adj[startVert]){
    				if(x==endVert ){
    					String to="";
    					to+=startVert+" "+x;
    					
    					if(hs.contains(to) && startVert!=x)
    					ans=Math.min(need+1, ans);
    					else
    						ans=Math.min(need, ans);
    				}
    				else{
    					String to="";
    					to+=startVert+" "+x;
    					boolean tmp=false;
    					if(hs.contains(to) )
    						tmp=true;
    					if(!Visited[x])
    					{
    					if(tmp)
    						dfs2(x, endVert, need+1);
    					else{
    						dfs2(x, endVert, need);
    					}
    					}
    					}
    			}
    			   
    			   
    		   }
    		     public long dfs(int startVertex){
    		    

    		    	 if(!Visited[startVertex])  {
    		    	
    		   return dfsUtil(startVertex);
    		  
    		    	

    		    	}
    		    	 
    		    
    		     
    		    return 0;
    		    	}
    		 private long dfsUtil(int startVertex) {

    			 int c=1;
    		TreeSet<Integer> index=new TreeSet();
    		TreeSet<Integer> ele=new TreeSet(Collections.reverseOrder());
    			 long cout=0;
    		      degree=0;
    		    	Visited[startVertex]=true;
    		    	id10[startVertex]=0;
    		      st.push(startVertex);
    		      int temp=-1;
    		    	    while(!st.isEmpty()){
    		    	
    		    	int top=st.pop();
    		    

    		    	Iterator<Integer> i=adj[top].listIterator();

      		      index.add(top);
      		      ele.add(a[top]);
    		    while(i.hasNext()){
    		    

    		    	int n=i.next();
    		     if( !Visited[n]){
    		    				Visited[n]=true;
    		    				st.push(n);
    		    c++;
    		     }
    		         }
    		 }
    		    	   for(int x:index){
    		    		   a[x]=ele.first();
    		    		   ele.remove(ele.first());
    		    	  }
    		 
    		 

    		    return 0;
    		    }
    		        
    		        }     
    		       	        
    		    class Dsu{
    		    	private int rank[], parent[] ,n;
    		    	private static int[] parent1;
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
    			