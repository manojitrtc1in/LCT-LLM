
import java.awt.List;
import java.io.*;
import java.util.*;







public class Main {
	FastScanner in;
	PrintWriter out;

	static ArrayList[] adj;
	static int n;
	static int x;
	static int visited[][];
	static int Ad[];
	static int Bd[];
 
	static int brr[][];
	static int a;
	static int b;
	static int parent[];
	static int size[];
	long mod = (long)1e9+7;


	static int arr[];	
	static int d[];
	static int h;



	class Segment{
	  private  int Lazy[];
	 
	    void ans(){
	   
	    	
	     int x = (int) (Math.ceil(Math.log(100000) / Math.log(2)));
	        int max_size = 2 * (int) Math.pow(2, x) - 1;
	        int SegTree[][] = new int[max_size][3]; 

	        Lazy = new int[max_size];
	        
	       String s = in.next();
	       n = s.length();
	        
	        int q=in.nextInt();
	        

	        build_ST(0, 0, n - 1,SegTree,s);
	  
	        for(int i = 0;i<2*n;i++){
	        	System.out.println(SegTree[i][0] + " " + SegTree[i][1] + " " + SegTree[i][2] + " " + (i+n));
	        }
	        
	        while(q-->0)
	        {
	          int a = in.nextInt();
	          int b = in.nextInt();
	          
	          int d = id4(0, n-1, a-1, b-1, 0,SegTree);
	          System.out.println(d);
	        }
	    }
	    
	    
	 void build_ST(int node, int start, int end,int SegTree[][],String s) 
	   {
	    if(start > end) return; 
	  	if(start == end) { 
	  		System.out.println(start + " " + node);
	  		if(s.charAt(start) == '('){
	  			SegTree[node][1] = 1;
	  		}else{
	  			SegTree[node][2] = 1;
	  		}
	  		
			return;
		}
		int mid=(start + end) >> 1;
		build_ST(node*2+1, start, mid, SegTree,s); 

		build_ST(node*2+2, 1+mid, end,SegTree,s); 

		
		

		
		int t = Math.min(SegTree[2*node + 1][1], SegTree[2*node+2][2]);
		
		SegTree[node][0] = SegTree[2*node+1][0] + SegTree[2*node+2][0] + 2*t;
		SegTree[node][1] = SegTree[2*node+1][1] + SegTree[2*node+2][1] - t;
		SegTree[node][2] = SegTree[2*node+1][2] + SegTree[2*node+2][2] - t;
		
		
	}




































































	      int id4(int start, int end, int l, int r, int node,int SegTree[][])
	    {


























	        if (l <= start && r >= end)
	            return SegTree[node][0];
	         if (end < l || start > r)
	            return 0;
	        int mid = (start + end) >> 1;
	        return id4(start, mid, l, r, 2 * node + 1,SegTree)+id4(mid + 1, end, l, r, 2 * node + 2,SegTree);
	    }
	      
	}
	
	static class Pair implements Comparable<Pair>
    {
        int x;
        int y;
        
        Pair(int l, int m) {
            this.x = l;
            this.y = m;
        }
        
        public int compareTo(Pair p) {
            if (this.x == p.x) {
                return (int)(this.y-p.y);
            }
            return (int)(this.x - p.x);
        }
        
        public String toString(){
        	return x + " " + y;
        }
        
        public boolean equals(Object o){
        	if(o instanceof Pair){
        		Pair a = (Pair)o;
        		
        		return this.x == a.x && this.y == a.y;
        	}
        	
        	return false;
        }
        
        public int hashCode(){
        	return new Long(x).hashCode()*31 + new Long(y).hashCode();
        }
    
    }
    
	
	public static int gcd(int a, int b) {
		if (b == 0) return a;
		return gcd(b, a%b);
	}
	
	public static int find(int i){
		if(parent[i] != i){
			return find(parent[i]);
		}
		
		return i;
	}
	
	
	public static void union(int a,int b){
		int ra = find(a);
		int rb = find(b);

		if(ra!= rb){
			if(size[ra] > size[rb]){
				parent[rb] =ra;
				size[ra] += size[rb];
			}else{
				parent[ra] = rb;
				size[rb] += size[ra];
			}
		}
		
	}

	public static void apply(int p,int value){
		arr[p] += value;
		
		if(p < n){
			d[p] += value;
		}
	}
	
	public static void push(int p){
		
		for(int s = h;s>0;s--){
			int i = p >> s;
			
			if(d[i] != 0){
				apply(i<<1,d[i]);
				apply(i<<1|1,d[i]);
				d[i] = 0;
			}		
		}		
	}
	
	public static void lazybuild(int p){
		while(p > 1){
			p>>=1;
			arr[p] = Math.max(arr[p<<1], arr[p<<1|1]) + d[p];
		}
	}
	
	public static void lazyupdate(int l,int r,int value){
		l += n; r += n+1;		
		int l0 = l;int r0 = r;
		for(;l<r; l>>=1,r>>=1){
			if((l&1) == 1){
				apply(l++,value);
			}
			
			if((r&1) == 1){
				apply(--r,value);
			}
		}
		lazybuild(l0);
		lazybuild(r0-1);
			
	}
	
	public static int lazyquery(int l,int r){
		l += n;r += n+1;
		push(l);push(r-1);
		int res = (int)-2e9;
		
		for(;l<r;l>>=1,r>>=1){
			if((l&1) == 1){
				res = Math.max(arr[l++], res);
			}
			
			if((r&1) == 1){
				res = Math.max(arr[--r], res);
			}
		}
		
		return res;
	}
	
	public static void build(){
		
		for(int i = n-1;i>0;i--){
			arr[i] = Math.max(arr[i<<1], arr[i<<1|1]);
		}
		
	}
	
	public static void update(int p,int v){
		
		for(arr[p += n] = v; p>0; p>>=1 ){
			arr[p>>1] = Math.max(arr[p], arr[p^1]);
		}
		
	}
	
	public static int query(int l,int r){
		
		r++;
		int max = 0;
		for(l +=n,r +=n;l<r; l>>=1,r>>=1 ){
			
		
			
			if((l&1) == 1){
				max = Math.max(max, arr[l++]);
			}
			
			if((r&1) == 1){
				max = Math.max(max, arr[--r]);
			}
		}
		
		return max;
	}
	
	void multiply(long a[][], long b[][])
	{
	    
	    long mul[][] = new long[3][3];
	    for (int i = 0; i < 3; i++)
	    {
	        for (int j = 0; j < 3; j++)
	        {
	            mul[i][j] = 0;
	            for (int k = 0; k < 3; k++)
	                mul[i][j] = (int) ((mul[i][j] + (a[i][k]*b[k][j])%mod)%mod);
	        }
	    }
	 
	  
	    for (int i=0; i<3; i++)
	        for (int j=0; j<3; j++)
	            a[i][j] = mul[i][j];  
	}
	
	long power(long F[][], long n)
	{
	    long M[][] = {{1,1,0}, {1,0,0}, {0,1,0}};
	 
	    if (n==1)
	        return (long) ((F[0][0] + F[0][1])%mod);
	 
	    power(F, n/2);
	 
	    multiply(F, F);
	 
	    if (n%2 != 0)
	        multiply(F, M);
	 
	    return (long) ((F[0][0] + F[0][1])%mod) ;
	}
	 
	
	long id1(long n)
	{
	    long[][] F = {{1,1,0}, {1,0,0}, {0,1,0}} ;
	 
	    return power(F, n);
	}
	 
	
    void solve() throws NumberFormatException, IOException {
 
    	Scanner in = new Scanner(System.in);
   






    	


















    	
    	int n = in.nextInt();
    	int k = in.nextInt();
    	
    	in.nextLine();
    	
    	int dp[][][] = new int[2][505][505];
    	
    	dp[0][0][0] = 1;
    	
    	for(int i = 1;i<=n;i++){
    		
    		int x = in.nextInt();
    		
    		int next = i%2;
    		int cur = 1-next;
    		
    		for(int j = 0;j<=k;j++){
    			
    			for(int l = 0;l<=j;l++){
    				
    				dp[next][j][l] = dp[cur][j][l];
    				
    				if(j>=x){
    					dp[next][j][l] |= dp[cur][j-x][l];
    				
    					if(l>=x){
        					dp[next][j][l] |= dp[cur][j-x][l-x];
        				}
        				
    				
    				}
    				
    				
    			}
    			
    		}
    		
    	}
    	
    	ArrayList<Integer> list = new ArrayList();
    	
    	for(int i = 0;i<=k;i++){
    		if(dp[n%2][k][i] == 1){
    			list.add(i);
    		}
    	}
    	
    	System.out.println(list.size());
    	
    	
    	for(Integer s:list){
    		System.out.print(s + " ");
    	}
    	
    	
    	














































































}
    
    public static String[] reverse(String arr[]){
    	
    	
    	for(int i = 0;i<arr.length/2;i++){
    		String temp = arr[i];
    		arr[i] = arr[arr.length-i-1];
    		arr[arr.length-1-i] = temp;
    	}
    	
    	return arr;
    	
    }
	
	
    
  
    private static long ans(long n){
        if(n==1) return 2;
        n+=1;
        int cnt=-1;
        while(n%2==0){
            n/=2;
            cnt++;
        }
        if(n==1){
            return (int)Math.pow(2,cnt)-1;
        }
        return -1;
    }
    public static long sum(long x){
    	return x<10?x:x%10 + sum(x/10);
    }
	
	public static long gcd(long x, long y) {
		if (x == 0)
			return y;
		else
			return gcd( y % x,x);
	}
	public static long pow(long n,long p,long m){
        long  result = 1;
         if(p==0)
           return 1;
       if (p==1)
           return n;
       while(p!=0)
       {
           if(p%2==1)
               result *= n;
           if(result>=m)
           result%=m;
           p >>=1;
           n*=n;
           if(n>=m)
           n%=m;
       }
       return result;
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
	

	void run() throws NumberFormatException, IOException {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(in.br.readLine());
				} catch (IOException e) {
					

					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	
	class Tri{
		
		Tri[] arr;
		
		public Tri(){
			arr = new Tri[27];
		}
		
	}
	
	
 

	public static void main(String[] args) throws NumberFormatException, IOException {
		new Main().run();
	}
}


class id2
{
    long st[]; 

 
    

    long minVal(long x, long y) {
        return (x < y) ? y : x;
    }
 
    

    

    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }
 
    
    long id3(int ss, int se, int qs, int qe, int index)
    {
        

        

        if (qs <= ss && qe >= se)
            return st[index];
 
        

        if (se < qs || ss > qe)
            return 0;
 
        

        int mid = getMid(ss, se);
        return minVal(id3(ss, mid, qs, qe, 2 * index + 1),
                id3(mid + 1, se, qs, qe, 2 * index + 2));
    }
 
    

    

    long RMQ(int n, int qs, int qe)
    {
        

        if (qs < 0 || qe > n - 1 || qs > qe) {
         

            return -1;
        }
 
        return id3(0, n - 1, qs, qe, 0);
    }
 
    

    

    long id0(long arr[], int ss, int se, int si)
    {
        

        

        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
 
        

        

        int mid = getMid(ss, se);
        st[si] = minVal(id0(arr, ss, mid, si * 2 + 1),
                id0(arr, mid + 1, se, si * 2 + 2));
        return st[si];
    }
 
    
    void constructST(long arr[], int n)
    {
        

 
        

        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
 
        

        int max_size = 2 * (int) Math.pow(2, x) - 1;
        st = new long[max_size]; 

 
        

        id0(arr, 0, n - 1, 0);
    }
 
   
       
}

class Node{
	int a;
	int b;
	int c;
}

class MyComp implements Comparator<Node>{
    
	@Override
	public int compare(Node a,Node b) {
		
		

		
		if(a.a < b.a){
			return -1;
		}else if(a.a > b.a){
			return 1;
		}else{
			return 0;
		}
		
		
	}
}

