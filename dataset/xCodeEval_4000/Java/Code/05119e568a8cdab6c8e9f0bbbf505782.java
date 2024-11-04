
import java.util.*;
import java.io.*;
import java.math.*;




public class CF1

{
	 static FastReader sc=new FastReader(); 
	







	 static long oset[];
	 static int oset_p;
	 static long mod=1000000007;
	

	

	 

	 

	 

	 

	 
	

	

	


	

	 

	   static PrintWriter out=new PrintWriter(System.out);
	   
	   static int msg[];
	   
	  public static void main(String[] args)
	  {
		 

		
		 
		  int ttt=1;
		   ttt =i();
		      
		     
		       int cccc=1;
	        outer :while (ttt-- > 0) 
	        {
	        	int n=i();
	        	int m=i();
	        	
	        	
	        	int arr[][]=input(n,m);
	        	
	        	
	        	if((n+m-1)%2==1)
	        	{
	        		out.println("NO");
	        		continue outer;
	        	}
	        	
	        	
	        	int dpmin[][]=new int[n][m];
	        	int dpmax[][]=new int[n][m];
	        	
	        	
	        	
	        	
	        	
	        	for(int i=0;i<n;i++)
	        	{
	        		for(int j=0;j<m;j++)
	        		{
	        			
	        			if(i==0&&j==0)
	        			{
	        				dpmin[i][j]=arr[i][j];
	        				dpmax[i][j]=arr[i][j];
	        			}
	        			else
	        				if(i==0)
	        				{
	        					dpmin[i][j]=dpmin[i][j-1]+arr[i][j];
	        					dpmax[i][j]=dpmax[i][j-1]+arr[i][j];
	        				}
	        				else
	        					if(j==0)
	        					{
	        						dpmin[i][j]=dpmin[i-1][j]+arr[i][j];
	        						dpmax[i][j]=dpmax[i-1][j]+arr[i][j];
	        						
	        					}
	        					else {
	        			
	        			dpmin[i][j]=arr[i][j]+min(dpmin[i-1][j],dpmin[i][j-1]);
	        			dpmax[i][j]=arr[i][j]+max(dpmax[i-1][j],dpmax[i][j-1]);
	        					}
	        		}
	        	}
	        	
	        

	        	
	        	if(dpmin[n-1][m-1]<=0&&0<=dpmax[n-1][m-1])out.println("YES");
				else out.println("NO");
	        }
	        
		     out.close();
	         
    }
	  
	  static boolean helper(int arr[][],int row,int col,int n,int m,boolean dp[][],int sum)
	  {
		  if(row<0||row>=n||col<0||col>=m)
			  return false;
		  
		  if(row==n-1&&col==m-1)
		  {
			  sum+=arr[row][col];
			  
			  if(sum==0)
				  return true;
			  
			  return false;
		  }
		  
		  if(dp[row][col])
			  return false;
		  
		  if(helper(arr,row+1,col,n,m,dp,sum+arr[row][col]))
			  return true;
		  
		  if(helper(arr,row,col+1,n,m,dp,sum+arr[row][col]))
			  return true;
		  
		  dp[row][col]=true;
		  
		  return false;
		  
	  }
	  
	 static int setBit(int n)
	  {
		 

		  
		  for(int i=31;i>=0;i--)
		  {
			  if((n&(1<<i))!=0)
			  {
				  return (i+1);
			  }
		  }
		  
		  return 0;
	  }
	  
	  
	 static int dfs(ArrayList<ArrayList<Integer>>adj,boolean visited[],int i,int dp[])
	 {
		 int ans=0;
		 
		 for(int it:adj.get(i))
		 {
			 if(!visited[it])
			 {
				 visited[it]=true;
				 ans+=dfs(adj,visited,it,dp);
			 }
		 }
		 
		 ans++;
		 
		 dp[i]=ans;
		 return ans;
	 }
	  
	  static int findPar(int par[],int x)
	  {
		  if(par[x]==x)
			  return x;
		  
		  return par[x]=findPar(par,par[x]);
	  }
	  
	  static void union(int rank[],int par[],int cost[],int u,int v)
	  {
		  
		  
		  
		  int x=findPar(par,u);
		  int y=findPar(par,v);
		  
		

		  if(x==y)
			  return;
		  
		

		  if(rank[x]>rank[y])
		  {
			  par[y]=x;
			  msg[x]=min(msg[x],cost[y]);
		  }
		  else
			  if(rank[y]>rank[x])
			  {
				  par[x]=y;
				  msg[y]=min(msg[y],cost[y]);
			  }
			  else
			  {
				  par[y]=x;
				  rank[x]++;

				  
				  
				  msg[x]=min(msg[x],cost[y]);
				 

			  }
	  }
	
static class Pair implements Comparable<Pair>
     {
    	 int x;
    	 int y;


    	 Pair(int x,int y){
    		 this.x=x;
    		 this.y=y;


    		 
    	 }
		@Override
		public int compareTo(Pair o) {
			if(this.x>o.x)
				return 1;
			else if(this.x<o.x)
				return -1;
			else {
				if(this.y>o.y)
					return 1;
				else if(this.y<o.y)
					return -1;
				else
					return 0;
			}
		}
		public int hashCode() 
		{ 
			final int temp = 14; 
			int ans = 1; 
			ans =x*31+y*13; 
			return ans; 
		} 
		@Override
		public boolean equals(Object o) 
		{ 
			if (this == o) { 
				return true; 
			} 
			if (o == null) { 
				return false; 
			} 
			if (this.getClass() != o.getClass()) { 
				return false; 
			} 
			Pair other = (Pair)o; 
			if (this.x != other.x || this.y!=other.y) { 
				return false; 
			} 
			return true; 
		} 	


		
		






























		
     }

static ArrayList<Long> gL()
{
	return new ArrayList<>();
}

static int find(int A[],int a) {
	  if(A[a]==a)
		  return a;
	  return A[a]=find(A, A[a]);
}












static class BIT{
    int bit[];
    BIT(int n){
        bit=new int[n+1];
    }
    int lowbit(int i){
        return i&(-i);
    }
    int query(int i){
        int res=0;
        while(i>0){
            res+=bit[i];
            i-=lowbit(i);
        }
        return res;
    }
    void update(int i,int val){
        while(i<bit.length){
            bit[i]+=val;
            i+=lowbit(i);
        }
    }
}


static long summation(long A[],int si,int ei)
{
	long ans=0;
	for(int i=si;i<=ei;i++)
		ans+=A[i];
	
	return ans;
}
static void add(long v,Map<Long,Long>mp) {
	if(!mp.containsKey(v)) {
		mp.put(v, (long)1);
	}
	else {
		mp.put(v, mp.get(v)+(long)1);
	}
}
static void remove(long v,Map<Long,Long>mp) {
	if(mp.containsKey(v)) {
		mp.put(v, mp.get(v)-(long)1);
		if(mp.get(v)==0)
			mp.remove(v);
	}
}
public static int upper(long A[],long k,int si,int ei)
{
	int l=si;
	int u=ei;
	int ans=-1;
	while(l<=u) {
		int mid=(l+u)/2;
		if(A[mid]<=k) {
			ans=mid;
			l=mid+1;
		}
		else {
			u=mid-1;
		}
	}
	return ans;
}
public static int lower(long A[],long k,int si,int ei)
{
	int l=si;
	int u=ei;
	int ans=-1;
	while(l<=u) {
		int mid=(l+u)/2;
		if(A[mid]<=k) {
			l=mid+1;
		}
		else {
			ans=mid;
			u=mid-1;
		}
	}
	return ans;
	
    
}
static int[] copy(int A[]) {
	int B[]=new int[A.length];
	for(int i=0;i<A.length;i++) {
		B[i]=A[i];
	}
	return B;
}
static long[] copy(long A[]) {
	long B[]=new long[A.length];
	for(int i=0;i<A.length;i++) {
		B[i]=A[i];
	}
	return B;
}
static int[] input(int n) {
	int A[]=new int[n];
	   for(int i=0;i<n;i++) {
		   A[i]=sc.nextInt();
	   }
	   return A;
   }
static long[] inputL(int n) {
	long A[]=new long[n];
	   for(int i=0;i<n;i++) {
		   A[i]=sc.nextLong();
	   }
	   return A;
   }
static String[] inputS(int n) {
	String A[]=new String[n];
	   for(int i=0;i<n;i++) {
		   A[i]=sc.next();
	   }
	   return A;
   }
static long sum(int A[]) {
	long sum=0;
	for(int i : A) {
		sum+=i;
	}
	return sum;
}
static long sum(long A[]) {
	long sum=0;
	for(long i : A) {
		sum+=i;
	}
	return sum;
}
static void reverse(long A[]) {
	int n=A.length;
	long B[]=new long[n];
	for(int i=0;i<n;i++) {
		B[i]=A[n-i-1];
	}
	for(int i=0;i<n;i++)
		A[i]=B[i];
	
}
static void reverse(int A[]) {
	int n=A.length;
	int B[]=new int[n];
	for(int i=0;i<n;i++) {
		B[i]=A[n-i-1];
	}
	for(int i=0;i<n;i++)
		A[i]=B[i];
	
}
static void input(int A[],int B[]) {
	   for(int i=0;i<A.length;i++) {
		   A[i]=sc.nextInt();
		   B[i]=sc.nextInt();
	   }
}
static long[][] inputL(int n,int m){
	long A[][]=new long[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			A[i][j]=l();
		}
	}
	return A;
}

static int[][] input(int n,int m){
	int A[][]=new int[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			A[i][j]=i();
		}
	}
	return A;
}

static char[][] charinput(int n,int m){
	char A[][]=new char[n][m];
	for(int i=0;i<n;i++) {
		String s=s();
		for(int j=0;j<m;j++) {
			A[i][j]=s.charAt(j);
		}
	}
	return A;
}
static int nextPowerOf2(int n)
{
	if(n==0)
		return 1;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
     
    return n;
}
static int highestPowerof2(int x)
{
   
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
     
    return x ^ (x >> 1); 
 
}
static long highestPowerof2(long x)
{
   
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1); 
 
}

static int max(int A[]) {
	int max=Integer.MIN_VALUE;
	for(int i=0;i<A.length;i++) {
		max=Math.max(max, A[i]);
	}
	return max;
}
static int min(int A[]) {
	int min=Integer.MAX_VALUE;
	for(int i=0;i<A.length;i++) {
		min=Math.min(min, A[i]);
	}
	return min;
}
static long max(long A[]) {
	long max=Long.MIN_VALUE;
	for(int i=0;i<A.length;i++) {
		max=Math.max(max, A[i]);
	}
	return max;
}
static long min(long A[]) {
	long min=Long.MAX_VALUE;
	for(int i=0;i<A.length;i++) {
		min=Math.min(min, A[i]);
	}
	return min;
}
static long [] prefix(long A[]) {
	long p[]=new long[A.length];
	p[0]=A[0];
	for(int i=1;i<A.length;i++)
		p[i]=p[i-1]+A[i];
	return p;
}
static long [] prefix(int A[]) {
	long p[]=new long[A.length];
	p[0]=A[0];
	for(int i=1;i<A.length;i++)
		p[i]=p[i-1]+A[i];
	return p;
}
static long [] suffix(long A[]) {
	long p[]=new long[A.length];
	p[A.length-1]=A[A.length-1];
	for(int i=A.length-2;i>=0;i--)
		p[i]=p[i+1]+A[i];
	return p;
}
static long [] suffix(int A[]) {
	long p[]=new long[A.length];
	p[A.length-1]=A[A.length-1];
	for(int i=A.length-2;i>=0;i--)
		p[i]=p[i+1]+A[i];
	return p;
}
static void fill(int dp[]) {
	Arrays.fill(dp, -1);
}
static void fill(int dp[][]) {
	for(int i=0;i<dp.length;i++)
	Arrays.fill(dp[i], -1);
}
static void fill(int dp[][][]) {
	for(int i=0;i<dp.length;i++) {
		for(int j=0;j<dp[0].length;j++) {
			Arrays.fill(dp[i][j],-1);
		}
	}
}
static void fill(int dp[][][][]) {
	for(int i=0;i<dp.length;i++) {
		for(int j=0;j<dp[0].length;j++) {
			for(int k=0;k<dp[0][0].length;k++) {
			Arrays.fill(dp[i][j][k],-1);
			}
		}
	}
}
static void fill(long dp[]) {
	Arrays.fill(dp, -1);
}
static void fill(long dp[][]) {
	for(int i=0;i<dp.length;i++)
	Arrays.fill(dp[i], -1);
}
static void fill(long dp[][][]) {
	for(int i=0;i<dp.length;i++) {
		for(int j=0;j<dp[0].length;j++) {
			Arrays.fill(dp[i][j],-1);
		}
	}
}
static void fill(long dp[][][][]) {
	for(int i=0;i<dp.length;i++) {
		for(int j=0;j<dp[0].length;j++) {
			for(int k=0;k<dp[0][0].length;k++) {
			Arrays.fill(dp[i][j][k],-1);
			}
		}
	}
}
static int min(int a,int b) {
	return Math.min(a, b);
}
static int min(int a,int b,int c) {
	return Math.min(a, Math.min(b, c));
}
static int min(int a,int b,int c,int d) {
	return Math.min(a, Math.min(b, Math.min(c, d)));
}
static int max(int a,int b) {
	return Math.max(a, b);
}
static int max(int a,int b,int c) {
	return Math.max(a, Math.max(b, c));
}
static int max(int a,int b,int c,int d) {
	return Math.max(a, Math.max(b, Math.max(c, d)));
}
static long min(long a,long b) {
	return Math.min(a, b);
}
static long min(long a,long b,long c) {
	return Math.min(a, Math.min(b, c));
}
static long min(long a,long b,long c,long d) {
	return Math.min(a, Math.min(b, Math.min(c, d)));
}
static long max(long a,long b) {
	return Math.max(a, b);
}
static long max(long a,long b,long c) {
	return Math.max(a, Math.max(b, c));
}
static long max(long a,long b,long c,long d) {
	return Math.max(a, Math.max(b, Math.max(c, d)));
}

static long power(long x, long y, long p)
{

	if(y==0)
		return 1;
	if(x==0)
		return 0;
    long res = 1;
    x = x % p;

    while (y > 0) {

        if (y % 2 == 1)
            res = (res * x) % p;

        y = y >> 1; 
        x = (x * x) % p;
    }

    return res;
}
static long power(long x, long y)
{

	if(y==0)
		return 1;
	if(x==0)
		return 0;
    long res = 1;

    while (y > 0) {

        if (y % 2 == 1)
            res = (res * x);

        y = y >> 1; 
        x = (x * x);
    }

    return res;
}

static void dln(String s)
{
	out.println(s);
}

static void d(String s)
{
	out.print(s);
}

static void print(int A[]) {
	for(int i : A) {
		out.print(i+" ");
	}
	out.println();
}
static void print(long A[]) {
	for(long i : A) {
		System.out.print(i+" ");
	}
	System.out.println();
}
static long mod(long x) {
	  return ((x%mod + mod)%mod);
}
static String reverse(String s) {
	StringBuffer p=new StringBuffer(s);
	p.reverse();
	return p.toString();
}

     static int i() {
    	 return sc.nextInt();
     }
     static String s() {
    	 return sc.next();
     }
     static long l() {
    	 return sc.nextLong();
     }  
     static void sort(int[] A){
        int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            int tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
     }
     static void sort(long[] A){
	        int n = A.length;
	        Random rnd = new Random();
	        for(int i=0; i<n; ++i){
	            long tmp = A[i];
	            int randomPos = i + rnd.nextInt(n-i);
	            A[i] = A[randomPos];
	            A[randomPos] = tmp;
	        }
	        Arrays.sort(A);
	     }
  static String sort(String s) {
 	 Character ch[]=new Character[s.length()];
 	 for(int i=0;i<s.length();i++) {
 		 ch[i]=s.charAt(i);
 	 }
 	 Arrays.sort(ch);
 	 StringBuffer st=new StringBuffer("");
 	 for(int i=0;i<s.length();i++) {
 		 st.append(ch[i]);
 	 }
 	 return st.toString();
  }
  static HashMap<Integer,Long> hash(int A[]){
	  HashMap<Integer,Long> map=new HashMap<Integer, Long>();
	  for(int i : A) {
		  if(map.containsKey(i)) {
			  map.put(i, map.get(i)+(long)1);
		  }
		  else {
			  map.put(i, (long)1);
		  }
	  }
	  return map;
  }
  static HashMap<Long,Long> hash(long A[]){
	  HashMap<Long,Long> map=new HashMap<Long, Long>();
	  for(long i : A) {
		  if(map.containsKey(i)) {
			  map.put(i, map.get(i)+(long)1);
		  }
		  else {
			  map.put(i, (long)1);
		  }
	  }
	  return map;
  }
  static TreeMap<Integer,Integer> tree(int A[]){
	  TreeMap<Integer,Integer> map=new TreeMap<Integer, Integer>();
	  for(int i : A) {
		  if(map.containsKey(i)) {
			  map.put(i, map.get(i)+1);
		  }
		  else {
			  map.put(i, 1);
		  }
	  }
	  return map;
  }
  static TreeMap<Long,Integer> tree(long A[]){
	  TreeMap<Long,Integer> map=new TreeMap<Long, Integer>();
	  for(long i : A) {
		  if(map.containsKey(i)) {
			  map.put(i, map.get(i)+1);
		  }
		  else {
			  map.put(i, 1);
		  }
	  }
	  return map;
  }
     static boolean prime(int n) 
	    { 
	        if (n <= 1) 
	            return false; 
	        if (n <= 3) 
	            return true; 
	        if (n % 2 == 0 || n % 3 == 0) 
	            return false; 
	        double sq=Math.sqrt(n);
	  
	        for (int i = 5; i <= sq; i = i + 6) 
	            if (n % i == 0 || n % (i + 2) == 0) 
	                return false; 
	        return true; 
	    } 
     static boolean prime(long n) 
	    { 
	        if (n <= 1) 
	            return false; 
	        if (n <= 3) 
	            return true; 
	        if (n % 2 == 0 || n % 3 == 0) 
	            return false; 
	        double sq=Math.sqrt(n);
	  
	        for (int i = 5; i <= sq; i = i + 6) 
	            if (n % i == 0 || n % (i + 2) == 0) 
	                return false; 
	        return true; 
	    } 
     static int gcd(int a, int b) 
     { 
         if (a == 0) 
             return b; 
         return gcd(b % a, a); 
     } 
     static long gcd(long a, long b) 
     { 
         if (a == 0) 
             return b; 
         return gcd(b % a, a); 
     } 
     
        
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }

	
} 


