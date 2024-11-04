import java.awt.Checkbox;
import java.awt.Point;
import java.io.*;
                    import java.math.*;
                    import java.util.*;
import java.util.Map.Entry;

import javax.print.attribute.SetOfIntegerSyntax;
import javax.swing.plaf.FontUIResource;




             
                    public class CODE2{
                      private static InputStream stream;
                        private static byte[] buf = new byte[1024];
                        private static int curChar,MAX;
                        private static int numChars;
                        private static id10 filter;
                        private static PrintWriter pw;
                        private static long count = 0,mod=1000000007;
                        static int BIT[];
                        private static boolean primer[];
                    

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
    
     

        static LinkedList<node> adj[];
        static boolean Visited[];
        static HashSet<Integer> exc;
        static long id5[]=new long[1000001];
        static long co=0,ans=0;
        static int parent[];
        static int size[],color[],res[],k;
        static ArrayList<Integer> al[];
        static long MOD = (long)1e9 + 7;
          
       
        static int[] levl,dist;
        static int[] eat;
      

        static int price[];
        

   static  boolean check(char c)
    {
    	if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' )
    		return true;
    	else
    		return false;
    }
   static int nm = 1000007;
   static boolean divisor[];
   static void sprime()
   {
	   spf=new int[nm+1];
	   for(int i=2;i<nm;i++)
	   {
		   if(spf[i]!=0)
			   continue;
		   for(int j=i;j<nm;j+=i)
		   {
			   spf[j] = i;
		   }
	   }
   }
        public static void solve(){
        
        int n = nextInt();
        long a[] = new long[n];
        
        a = id11(n);
        
      
        HashMap<Long,Integer> hm = new HashMap<>();
        int minus = 0;
        for(int i=0;i<n;)
        {
        	if(hm.containsKey(a[i]))
        	{
        		 a[hm.get(a[i])]=-1;
        		
        		 hm.remove(a[i]);
        		 a[i]= 2 * a[i];
        		 
        		 minus++;
        	
        	}
        	else
        	{
        		hm.put(a[i],i++);
        		
        	}
        }
        pw.println(n-minus);
        for(long ele:a)
        {
        	if(ele!=-1)
        		pw.print(ele+" ");
        }
        
        
        
        	
      }
        static class pa implements Comparable<pa>
    	{
    		long ele;int i;
    		
    		pa(long ele,int i)
    		{
    			this.ele = ele;
    			this.i = i; 
    		}
    		
    		public int compareTo(pa other)
    		{
    			return (int)(this.i-other.i);
    					
    		}
    	}
        static class node implements Comparable<node>
    	{
    		int u;long w;
    		
    		node(int u,long w)
    		{
    			this.u = u;
    			this.w = w; 
    		}
    		
    		public int compareTo(node other)
    		{
    			return (int)(this.w-other.w);
    					
    		}
    	}
        static long calculate(long p)
        {
        	long mod2 = 500000004;
        	p=((p%MOD)*(p+1)%MOD)%MOD;
        	p = (p * (mod2)%MOD)%MOD;
        	return p;
        }
        static String decrypt(int x)
        {
        	if(x<4)
        		return "NO";
        	ArrayList<Integer> factors = new ArrayList<>();
        	int backup = x;
        	while(x!=1)
        	{
        		int sp = spf[x];
        		factors.add(sp);
        		while(x%sp ==0)
        		x = x / sp;
        		
        	}
        	for(int i=0;i<factors.size();i++)
        	{
        		for(int j=0;j<factors.size();j++)
        		{
        			
        			if(backup % (factors.get(i)*factors.get(j)) == 0 )
        			{
        				int tt = backup / (factors.get(i)*factors.get(j));
        				
        				if(tt==1 || divisor[tt])
        					return "YES";
        					
        			}
        		}
        	}
        	return "NO";
        }
        
       static  long id0(int a[], int size)
        {
           long id3 = a[0];
           long curr_max = a[0];
         
           for (int i = 1; i < size; i++)
           {
                curr_max = Math.max(a[i], curr_max+a[i]);
                id3 = Math.max(id3, curr_max);
           }
           return id3;
        }
        
        static void id7(int n)
        {
        	primer=new boolean[n+1];
        	Arrays.fill(primer,true);
        	primer[0]=false;
        	primer[1]=false;
        	primer[2]=true;
        	
        	for(int i=2;i*i<=n;i++)
        	{
        		if(primer[i])
        		{
        			for(int j=2*i;j<=n;j=j+i)
        			{
        				primer[j]=false;
        			}
        		}
        	}
        }
       
        
     
     
        static int BITsum(int x)
        		{
        	int sum=0;
        	while(x>0)
        	{
        		sum+=BIT[x];
        		x-= (x & -x);
        	}
        		return sum;
        		}
  
        static boolean union(int x,int y)
        {
        	int xr=find(x);
        	int yr=find(y);
        	if(xr==yr)
        		return false;
        	if(size[xr]<size[yr])
        	{
        		size[yr]+=size[xr];
        		parent[xr]=yr;
        	}
        	else
        	{
        		size[xr]+=size[yr];
        		parent[yr]=xr;
        		
        	}
        	return true;
        	
        }
        static int  find(int x)
        {
        	if(parent[x]==x)
        		return x;
        	else
        	{
        		parent[x]=find(parent[x]);
        		return parent[x];
        	}
        	
        }
        public static class Edge implements Comparable<Edge>
        {
        	int u, v;
			public Edge(int u, int v) 
			{
				this.u = u;
				this.v = v;
				

			}
			public int hashCode() 
			{
				return Objects.hash();
			}
			public int compareTo(Edge other) 
			{
			return (Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)):(Integer.compare(v, other.v)));
				

				

			}
			public String toString()
			{
				return this.u + " " + this.v;
			}
        }
       
        static int col[];
    public static boolean id2(char c){
        if(c=='a' || c=='e'||c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
static int no_vert=0;

  
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
                        
                    
                    for(int i=2;i*i<=n;i++){
                        if(prime[i]){
                            spf[i]=i;
                            for(int j=2*i;j<=n;j+=i){
                                
                                prime[j]=false;
                           
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
                            String s=nextLine();
                            for(int j=0;j<s.length();j++){
                                c[i][j]=s.charAt(j);
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
 
                    private static boolean id1(int c) {
                        if (filter != null)
                            return filter.id1(c);
                        return isWhitespace(c);
                    }
 
                    private interface id10 {
                        public boolean id1(int ch);
                    }
                    

}