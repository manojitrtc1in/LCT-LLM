

 
    	        			
     
     
        		    import java.awt.Checkbox;
import java.awt.Point;
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
        		    	private static id6 filter;
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
        static long id2[]=new long[1000001];
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
        

    public static void solve(){

    	int n=nextInt();
    	int m=nextInt();
    	int k[]=new int[m];
    	int f[]=new int[m];
    	for(int i=0;i<m;i++)

    	{
    	k[i]=nextInt();f[i]=nextInt();
    	}
    	int ans=0;
    	int fuck=-1;
    	HashSet<Integer> set=new HashSet();
    	for(int i=1;i<=100;i++)
    	{
    	int curr=1;
    	ArrayList<Integer> ar[]=new ArrayList[101];
    	for(int j=1;j<=100;j++)
    	ar[j]=new ArrayList();
    	for(int j=1;j<=100;j++)
    	{
    	for(int l=1;l<=i;l++)
    	{
    	ar[j].add(curr++);
    	}
    	}
    	boolean bool=true;
    	for(int j=0;j<m;j++)
    	{
    	if(!ar[f[j]].contains(k[j]))
    	{
    	bool=false;
    	break;
    	}
    	}
    	if(bool)
    	{
    	for(int j=1;j<=100;j++)
    	{
    	if(ar[j].contains(n))
    	{
    	set.add(j);
    	break;
    	}
    	}
    	}
    	}
    	if(m==0)
    	{
    	if(n==1)
    	System.out.println(1);
    	else
    	System.out.println(-1);
    	return;
    	}
    	if(set.size()>1)
    	{
    	System.out.println(-1);
    	return;
    	}
    	for(int x:set)
    	System.out.println(x);
    	
    }
    
static int no_vert=0;

  private static void dfs(int start,int cake){
	  Visited[start]=true;
	  no_vert++;
	  eat[start]=cake;
	  for(int i:adj[start]){
		  if(!Visited[i])
			  {
			

			  dfs(i,cake);
			  }
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
 
    		    	private static boolean id4(int c) {
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
    		    		} while (!id4(c));
    		    		return res.toString();
    		    	}
 
    		    	private static int[] id1(int n) {
    		    		int[] arr = new int[n];
    		    		for (int i = 0; i < n; i++) {
    		    			arr[i] = nextInt();
    		    		}
    		    		return arr;
    		    	}
 
    		    	private static long[][] id5(int n, int m) {
    		    		long[][] arr = new long[n][m];
    		    		for (int i = 0; i < n; i++) {
    		    			for (int j = 0; j < m; j++) {
    		    				arr[i][j] = nextLong();
    		    			}
    		    		}
    		    		return arr;
    		    	}
    		    	private static char[][] id3(int n,int m){
    		    		char [][]c=new char[n][m];
    		    		for(int i=0;i<n;i++){
    		    			String s=nextLine();
    		    			for(int j=0;j<s.length();j++){
    		    				c[i][j]=s.charAt(j);
    		    			}
    		    		}
    		    		return c;
    		    	}
 
    		    	private static long[] id7(int n) {
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
 
    		    	private interface id6 {
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
 
 
							
