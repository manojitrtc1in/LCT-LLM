

 
    	        			
     
     
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
	}	public static boolean isPrime(int n) {
	

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
        static long co=0,ans=Integer.MAX_VALUE;
    
     
      
       
        static int[] levl;
        static int[] no;
        static int n,m;
        
        

    public static void solve(){
    
    	int n=nextInt();
    	long a[]=id7(n);
        long b[]=new long[n+2];
        b[0]=0;
        b[n+1]=0;
        for(int i=1;i<=n;i++)
        	b[i]=a[i-1];
        long suff[]=new long[n+2];
        long pref[]=new long[n+2];
        pref[0]=b[0];
        for(int i=1;i<=(n+1);i++)
        {
        	pref[i]+=pref[i-1];
        	pref[i]+=b[i];
        }
        suff[n+1]=b[n+1];
        for(int i=n;i>=0;i--)
        {
        	suff[i]=suff[i+1]+b[i];
        }
        long ans=Long.MIN_VALUE;
        String fina="";
        int pos=0;
        int neg=0;
        for(int i=1;i<=n;i++)
        {
        	if(b[i]>=0)
        		pos++;
        	if(b[i]<=0)
        		neg++;
        	long sum=0;
        	long sumR=Long.MIN_VALUE;
        	int third=i;
        	int fourth=n+1;
        	for(int j=i;j<=n;j++)
        	{
        		sum+=b[j];
        		long temp=suff[j+1];
        		long curr=(sum)+(-temp);
        		if(sumR<curr)
        		{
        			sumR=curr;
        			fourth=j+1;
        		}
        	}
        	int second=i;
        	sum=0;
        	long sumL=Long.MIN_VALUE;
        	for(int j=i-1;j>=1;j--)
        	{
        		sum+=b[j];
        		long temp=pref[j-1];
        		long curr=(-sum)+(temp);
        		if(sumL<curr)
        		{
        			sumL=curr;
        			second=j;
        		}
        	}
        	
       

        	sumL+=sumR;
        	
        	if(ans<sumL)
        	{
        		second--;third--;fourth--;
        		fina=second+" "+third+" "+fourth;
        		ans=sumL;
        	}
        }
        if(pos==n)
        {
        	pw.print(n+" "+n+" "+n);
        	return;
        }
        if(neg==n)
        {
        	pw.println(0+" "+n+" "+n);
        	return;
        }
        if(n==1)
        {
        	if(a[0]<0)
        		pw.println(0+" "+0+" "+0);
        	else
        		pw.println(n+" "+n+" "+n);
        	return;
        }
        pw.println(fina);

    }
    
    
  static int deg=0;

  
  private static void dfs(int start){
	  Visited[start]=true;
	  deg+=adj[start].size();
	  no_vert++;
	  for(int i:adj[start]){
		  if(!Visited[i])
			  dfs(i);
	  }
  }
    
    public static String reverseString(String s) {
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return (sb.toString());
	}
    
    
   private static void BFS(int sou){
    	Queue<Integer> q=new LinkedList<Integer>();
    	q.add(sou);
    	Visited[sou]=true;
    	levl[sou]=0;
    	while(!q.isEmpty()){
    		int top=q.poll();
    		
    		for(int i:adj[top]){
    			

			if(!Visited[i])
			{
				
				q.add(i);
				levl[i]=levl[top]+1;
			}
			
			Visited[i]=true;
			
			}
		}
	}
	

private static long ncr(int n,int k){
	if (k < 0 || k > n) return 0;
    if (n-k < k) k = n-k;

    BigInteger x = BigInteger.ONE;
    for (int i = 1; i <= k; i++) {
        x = x.multiply(new BigInteger(""+(n-i+1)));
        x = x.divide(new BigInteger(""+i));
				        }
			
				return x.longValue();
				    }
    		       private  static long fact(long count){
    		        	long ans=1;
    		        	for(int i=1;i<=count;i++){
    		        		ans*=i;
    		        	}
    		        	return ans;
    		        }
    		        
    		        
    		        static int state=1;
    		        static long no_exc=0,no_vert=0;
    		      static Stack<Integer> st;
    		      static HashSet<Integer> inset;
    		        private static void topo(int curr){
    		        	
    		        	Visited[curr]=true;
    		        	inset.add(curr);
    		        	for(int x:adj[curr]){
    		        		if(adj[x].contains(curr) || inset.contains(x)){
    		        			state=0;
    		        			return;
    		        		}
    		        		if(state==0)
    		        			return;
    		        		
    		        	}
    		        	st.push(curr);
    		        	
    		        	inset.remove(curr);
    		        }
    		        static HashSet<Integer> hs;
    		       
    		     	private static void buildgraph(int n){
    		    		adj=new LinkedList[n+1];
    		    		Visited=new boolean[n+1];
    		    		levl=new int[n+1];
    		    		no=new int[n+1];
    		    		for(int i=0;i<=n;i++){
    		    			adj[i]=new LinkedList<Integer>();
    		    		
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
    		    	
    		    	private static void merge_sort(int a[],int p,int q){
    		    		if(p>q)
    		    			return;
    		    		int mid=(p+q)/2;
    		    		int l[]=new int[mid];
    		    		int r[]=new int[a.length - mid];
    		    		for(int i=0;i<mid;i++){
    		    			l[i]=a[i];
    		    		}
    		    		for(int i=mid;i<a.length;i++)
    		    			r[i]=a[i];
    		    		merge_sort(l,p,mid);
    		    		merge_sort(r,mid+1,q);
    		    		merge(l,r,a);
    		    	}
    		    	private static void merge(int l[],int r[],int a[]){
    		    		int i=0,j=0,k=0;
    		    		int nl=l.length;
    		    		int nr=r.length;
    		    		while(i<nl && j<nr){
    		    			if(l[i]<r[j]){
    		    				a[k]=l[i];
    		    				k++;
    		    				i++;  
    		    			}else {
    		    				a[k]=r[j];
    		    				k++;
    		    				j++;
    		    			}
    		    				
    		    			}
    		    		while(i<nl){
    		    			a[k]=l[i];
    		    			i++;
    		    			k++;
    		    		}
    		    		while(j<nr){
    		    			a[k]=r[j];
    		    			j++;
    		    			k++;
    		    		}
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
int str[];
private static int[] parent1;
Dsu(int size){
	this.n=size+1;
	rank=new int[n];
	

    		    		    		parent=new int[n];
    		    		    		str=new int[n];
    		    		    	makeSet();
    		    		
    		    		    	}
    		    		    	
    		    		    	void makeSet(){
    		    		    		for(int i=0;i<n;i++){
    		    		    			parent[i]=i;
    		    		    			str[i]=i;
    		    		    		}
    		    		    	}
    		    		    	
    		    		    	int find(int x){
    		    		    		if(parent[x]!=x){
    		    		    			
    		    		    			parent[x]=find(parent[x]);
    		    		    		}
    		    		    		return parent[x];
    		    		    	}
    		    		    
    		    		    	
    		    		    	boolean union(int x,int y){
    		    		    		int xRoot=find(x);
    		    		    		int yRoot=find(y);
    		    		    		
    		    		    		if(xRoot==yRoot)
    		    		    			return false;
    		    		    		if(rank[xRoot]<rank[yRoot]){
    		    		    		parent[xRoot]=yRoot;
    		    		    		str[yRoot]=Math.max(Math.max(str[xRoot], str[yRoot]), Math.max(x, y));
    		    		    		}else if(rank[yRoot]<rank[xRoot]){
    		    		    			parent[yRoot]=xRoot;
     
    			    		    		str[xRoot]=Math.max(Math.max(str[xRoot], str[yRoot]), Math.max(x, y));
    		    		    			
    		    		    		}else{
    		    		    			parent[yRoot]=xRoot;
    		    		    			rank[xRoot]++;
     
    			    		    		str[xRoot]=Math.max(Math.max(str[xRoot],str[yRoot]), Math.max(x, y));
    		    		    		}
    		    		    		return true;
    		    		    	}
    	
    		    		     
    		    		    }
 
 
							
