
import java.io.*;
import java.util.*;



public class cp {
	static int mod=(int)1e9+7;
	


	static FastReader sc=new FastReader(System.in);
	static int[] sp;
	static int size=(int)1e6;
	static int[] arInt;
	static long[] arLong;
	public static void main(String[] args) throws IOException { 




			int tc=1;








			while(tc-->0)
			{
				int n=sc.nextInt();
				long arr[]=new long[n];
				for (int i = 0; i < arr.length; i++) {
					arr[i]=sc.nextLong();
				}
				sparseTable tt=new sparseTable();
				tt.buildTable(arr);
				int maxr=-1;
				int ans=0,pt=0;
				for(int i=0;i<n;i++)
				{
					while(pt<i && tt.maxQuery(pt, i)<i-pt+1)pt++;
					if(tt.maxQuery(pt, i)==i-pt+1)
					{
						if(pt>maxr)
						{
							maxr=i;
							ans++;
						}
					}
					out.print(ans+" ");
				}
				
			}
				
				
				
			
			
			
				
			
			
			out.flush();
			out.close();
			System.gc();
	
	}
	
	
	


	
	
	
	static class Node{
		int x;
		int y;
		ArrayList<Integer> edges;
		public Node(int x,int y) {
			

			this.x=x;
			this.y=y;
			this.edges=new ArrayList<>();
		}
	}
	
	
	static int lis(int arr[],int n)
	{
		int ans=0;
		
		int dp[]=new int[n+1];
		Arrays.fill(dp, int_max);
		dp[0]=int_min;
		for(int i=0;i<n;i++)
		{
			int j=UpperBound(dp,arr[i]);
			if(dp[j-1]<=arr[i] && arr[i]<dp[j])
				dp[j]=arr[i];
			
		}
		
		for(int i=0;i<=n;i++)
		{
			if(dp[i]<int_max)
				ans=i;
		}
		
		return ans;
	}
	
	static long get(long n)
	{
		return n*(n+1)/2L;
	}
	
	static boolean go(String s)
	{
		int i=0,j=s.length()-1;
		while(i<=j) {
			if(s.charAt(i)==s.charAt(j))
			{
				i++;
				j--;
				
			}
			else {
				return false;
			}
			
		}
		return true;
	}
	
	static String revString(String s)
	{
		char arr[]=s.toCharArray();
		int n=s.length();
		for(int i=0;i<n/2;i++)
		{
			char temp=arr[i];
			arr[i]=arr[n-i-1];
			arr[n-i-1]=temp;
		}
		
		return String.valueOf(arr);
	}
	
	static void dfs(Graph gp,boolean[] vis,int node,int[] dp)
	{
		vis[node]=true;
		dp[node]=0;
		for(Integer child:gp.list[node])
		{
			if(!vis[child])
			{
				dfs(gp, vis, child, dp);
			}
			dp[node]=Math.max(dp[node], 1+dp[child]);
		}
	}
	


	static int SetBits(int n)
	{
		int cnt=0;
		while(n>0)
		{
			if((n&1)==1)
			{
				cnt++;
				
			}
			n=n>>1;
			
		}
		
		return cnt;
	}
	
	
	
	
	static boolean isPowerOfTwo(int n)
    {
        return (int)(Math.ceil((Math.log(n) / Math.log(2))))
            == (int)(Math.floor(((Math.log(n) / Math.log(2)))));
    }
	
	
	
	
	static void arrInt(int n) throws IOException
	{
		arInt=new int[n];
		for (int i = 0; i < arInt.length; i++) {
			arInt[i]=sc.nextInt();
		}
	}
	
	static void arrLong(int n) throws IOException
	{
		arLong=new long[n];
		for (int i = 0; i < arLong.length; i++) {
			arLong[i]=sc.nextLong();
		}
	}
	
	
	
	static ArrayList<Integer> add(int id,int c)
	{
		ArrayList<Integer> newArr=new ArrayList<>();
		for(int i=0;i<id;i++)
			newArr.add(arInt[i]);
		newArr.add(c);
		for(int i=id;i<arInt.length;i++)
		{
			newArr.add(arInt[i]);
		}
		
		
		return newArr;
	}

	    

    static int upper(ArrayList<Integer> arr, int n, int x)
    {
    	int l = 0, h = n - 1;
        while (h-l>1)
        {
            int mid = (l + h) / 2;
            if (arr.get(mid) <= x)
                l=mid+1;
            else
            {
            	h=mid;
            }
        }
        if(arr.get(l)>x)
        {
        	return l;
        }
        if(arr.get(h)>x)
        	return h;
        return -1;
    }
    static int upper(ArrayList<Long> arr, int n, long x)
    {
    	int l = 0, h = n - 1;
    	while (h-l>1)
    	{
    		int mid = (l + h) / 2;
    		if (arr.get(mid) <= x)
    			l=mid+1;
    		else
    		{
    			h=mid;
    		}
    	}
    	if(arr.get(l)>x)
    	{
    		return l;
    	}
    	if(arr.get(h)>x)
    		return h;
    	return -1;
    }
     
	
	
	static int lower(ArrayList<Integer> arr, int n, int x)
    {
        int l = 0, h = n - 1;
        while (h-l>1)
        {
            int mid = (l + h) / 2;
            if (arr.get(mid) < x)
                l=mid+1;
            else
            {
            	h=mid;
            }
        }
        if(arr.get(l)>=x)
        {
        	return l;
        }
        if(arr.get(h)>=x)
        	return h;
        return -1;
    }
          
	
	
	
	
	static int N = 501; 
	 
	

	static long[] factorialNumInverse = new long[N + 1];
	 
	

	static long[] naturalNumInverse = new long[N + 1];
	 
	

	static long[] fact = new long[N + 1];
	 
	

	public static void InverseofNumber(int p)
	{
	    naturalNumInverse[0] = naturalNumInverse[1] = 1;
	     
	    for(int i = 2; i <= N; i++)
	        naturalNumInverse[i] = naturalNumInverse[p % i] *
	                                 (long)(p - p / i) % p;
	}
	 
	

	public static void InverseofFactorial(int p)
	{
	    factorialNumInverse[0] = factorialNumInverse[1] = 1;
	 
	    

	    for(int i = 2; i <= N; i++)
	        factorialNumInverse[i] = (naturalNumInverse[i] *
	                           factorialNumInverse[i - 1]) % p;
	}
	 
	

	public static void factorial(int p)
	{
	    fact[0] = 1;
	 
	    

	    for(int i = 1; i <= N; i++)
	    {
	        fact[i] = (fact[i - 1] * (long)i) % p;
	    }
	}
	 
	

	public static long Binomial(int N, int R, int p)
	{
	     
	    

	    long ans = ((fact[N] * factorialNumInverse[R]) %
	                       p * factorialNumInverse[N - R]) % p;
	     
	    return ans;
	}
	
	
	static String tr(String s)
	{
		int now = 0;
		while (now + 1 < s.length() && s.charAt(now)== '0')
			++now;
		return s.substring(now);
	}
	
	 static ArrayList<Integer> ans;
	static void dfs(int node,Graph gg,int cnt,int k,ArrayList<Integer> temp)
	{
		if(cnt==k)
			return;
		
		for(Integer each:gg.list[node])
		{
			if(each==0)
			{
				temp.add(each);
				ans=new ArrayList<>(temp);
				temp.remove(temp.size()-1);
				continue;
			}
			temp.add(each);
			dfs(each,gg,cnt+1,k,temp);
			temp.remove(temp.size()-1);
			
		}
		
		return;
	}
	
	
	static boolean isPrime(long n)
    {
        

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
	
	
	static ArrayList<Integer> commDiv(int a, int b)
    {
        

        int n = gcd(a, b);
 
        

        ArrayList<Integer> Div=new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            

            if (n % i == 0) {
                

                if (n / i == i)
                    Div.add(i);
                else
                {
                	Div.add(i);
                	Div.add(n/i);
                }
            }
        }
        return Div;
    }
	
	static HashSet<Integer> factors(int x)
	{
		HashSet<Integer> a=new HashSet<Integer>();
		for(int i=2;i*i<=x;i++)
		{
			if(x%i==0)
			{
				a.add(i);
				a.add(x/i);
			}
		}
		return a;
	}
	static void primeFactors(int n,HashSet<Integer> factors)
    {
        

        while (n%2==0)
        {
            factors.add(2);
            n /= 2;
        }

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            while (n%i == 0)
            {
               factors.add(i);
                n /= i;
            }
        }

        

        

        if (n > 2)
            factors.add(n);
    }
		
	



































	static class Tuple{
		int a;
		int b;
		int c;
		public Tuple(int a,int b,int c) {
			this.a=a;
			this.b=b;
			this.c=c;
		}
		
	}

	

	static HashMap<Long,Long> findFactors(long n2)
	{
		HashMap<Long,Long> ans=new HashMap<>();
		if(n2%2==0)
		{
			ans.put(2L, 0L);


			while((n2&1)==0)
			{
				n2=n2>>1;
				ans.put(2L, ans.get(2L)+1);


			}
				
		}
		for(long i=3;i*i<=n2;i+=2)
		{
			if(n2%i==0)
			{
				ans.put((long)i, 0L);


				while(n2%i==0)
				{
					n2=n2/i;
					ans.put((long)i, ans.get((long)i)+1);
					
				}
			}
		}
		if(n2!=1)
		{
			ans.put(n2, ans.getOrDefault(n2, (long) 0)+1);
			
		}
			
		return ans;
	}
	

	

	static class fwt
	{
		int n;
		long BITree[];
		fwt(int n)
		{
			this.n=n;
			BITree=new long[n+1];
		}
		
		fwt(int arr[], int n)
		{
			this.n=n;
			BITree=new long[n+1];
			for(int i = 0; i < n; i++)
			updateBIT(n, i, arr[i]);
		 }
		
		   long getSum(int index)
		   {
		       long sum = 0;
		       index = index + 1;
		       while(index>0)
		       {
		           sum += BITree[index];
		           index -= index & (-index);
		       }
		       return sum;
		   }
		   void updateBIT(int n, int index,int val)
		   {
		       index = index + 1;
		       while(index <= n)
		       {
		       BITree[index] += val;
		       index += index & (-index);
		       }
		   }
		   void print()
		   {
			    for(int i=0;i<n;i++)
			    out.print(getSum(i)+" ");
			    out.println();
		   }
	}

	
	static class sparseTable{
	int n;
	long[][]dp;
	int log2[];
	int P;
	
	void buildTable(long[] arr)
	{
		n=arr.length;
		P=(int)Math.floor(Math.log(n)/Math.log(2));
		
		log2=new int[n+1];
		log2[0]=log2[1]=0;
		for(int i=2;i<=n;i++)
		{
			log2[i]=log2[i/2]+1;
		}
		dp=new long[P+1][n];
		for(int i=0;i<n;i++)
		{
			dp[0][i]=arr[i];
		}
		
		for(int p=1;p<=P;p++)
		{
			for(int i=0;i+(1<<p)<=n;i++)
			{
				long left=dp[p-1][i];
				long right=dp[p-1][i+(1<<(p-1))];
				dp[p][i]=gcd(left, right);
			}
		}
	}
	
	
	long maxQuery(int l,int r)
	{
		int len=r-l+1;
		int p=(int)Math.floor(log2[len]);
		long left=dp[p][l];
		long right=dp[p][r-(1<<p)+1];
		return gcd(left, right);
	}
}

	
	
	
	

	static int setBitNumber(long n)
    {
        if (n == 0)
            return 0;
 
        int msb = 0;
        n = n / 2;
 
        while (n != 0) {
            n = n / 2;
            msb++;
        }
 
        return msb;
    }
 
	
	
	static int getFirstSetBitPos(long n)
    {
        return (int)((Math.log10(n & -n)) / Math.log10(2)) + 1;
    }
	
	
	static ArrayList<Integer> primes;
	static HashSet<Integer> primeSet;
	static boolean prime[];
	static int primeCnt[];
	static void sieveOfEratosthenes(int n)
    {
        

        

        

        

        

        

        

       prime= new boolean[n + 1];
        for (int i = 2; i <= n; i++)
            prime[i] = true;
        
        for (int p = 2; p * p <= n; p++)
        {
            

            

            if (prime[p] == true)
            {
                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        

        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
               primeCnt[i]=primeCnt[i-1]+1;
        }
    }
	
	
	
	static long mod(long a, long b) {
		  long c = a % b;
		  return (c < 0) ? c + b : c;
		}
	
	static void swap(long arr[],int i,int j)
	{
		long temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}

	
	
	static boolean util(int a,int b,int c)
	{
		if(b>a)util(b, a, c);
		
		while(c>=a)
		{
			c-=a;
			if(c%b==0)
				return true;
		}
		
		
		return (c%b==0);
	}
	
	
	
	static void flag(boolean flag)
	   {
	       out.println(flag ? "YES" : "NO");
	       out.flush();
	   }
	  
	
	static void print(int a[])
	  {
	     int n=a.length;
	     for(int i=0;i<n;i++)
	       {
	          out.print(a[i]+" ");
	       }
	     out.println();
	     out.flush();
	  }
	static void print(long a[])
	  {
	     int n=a.length;
	     for(int i=0;i<n;i++)
	       {
	          out.print(a[i]+" ");
	       }
	     out.println();
	     out.flush();
	  } 
	static void print_int(ArrayList<Integer> al)
	  {
	     int si=al.size();
	     for(int i=0;i<si;i++)
	       {
	          out.print(al.get(i)+" ");
	       }
	     out.println();
	     out.flush();
	  }
	static void print_long(ArrayList<Long> al)
	  {
	     int si=al.size();
	     for(int i=0;i<si;i++)
	       {
	          out.print(al.get(i)+" ");
	       }
	     out.println();
	     out.flush();
	  }
	  
	static void printYesNo(boolean condition)
	{
		if (condition) {
			out.println("YES");
		}
		else {
			out.println("NO");
		}
	}
	
	
	static int LowerBound(int a[], int x) 
	 { 

	  int l=-1,r=a.length;
	  while(l+1<r) {
	    int m=(l+r)>>>1;
	    if(a[m]>=x) r=m;
	    else l=m;
	  }
	  return r;
	}
	
	
	static int lowerIndex(int arr[], int n, int x)
    {
        int l = 0, h = n - 1;
        while (l<=h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] >= x)
                h = mid -1 ;
            else
                l = mid + 1;
        }
        return l;
    }
	
	
	    

    static int upperIndex(int arr[], int n, int y)
    {
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] <= y)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h;
    }
    static int upperIndex(long arr[], int n, long y)
    {
    	int l = 0, h = n - 1;
    	while (l <= h)
    	{
    		int mid = (l + h) / 2;
    		if (arr[mid] <= y)
    			l = mid + 1;
    		else
    			h = mid - 1;
    	}
    	return h;
    }
     
	
	 static int UpperBound(int a[], int x)
	  {

	    int l=-1,r=a.length;
	    while(l+1<r) {
	       int m=(l+r)>>>1;
	       if(a[m]<=x) l=m;
	       else r=m;
	    }
	    return l+1;
	 }
	 static int UpperBound(long a[], long x)
	 {

		 int l=-1,r=a.length;
		 while(l+1<r) {
			 int m=(l+r)>>>1;
	       if(a[m]<=x) l=m;
	       else r=m;
		 }
		 return l+1;
	 }
	
	 
	 static class DisjointUnionSets
	 {
	    int[] rank, parent;
	    int n;
	    

	    public DisjointUnionSets(int n)
	    {
	        rank = new int[n];
	        parent = new int[n];
	        this.n = n;
	        makeSet();
	    }
	    

	    void makeSet()
	    {
	        for (int i = 0; i < n; i++)
	            parent[i] = i;
	    }
	    int find(int x)
	    {
	        if (parent[x] != x) {
	            parent[x] = find(parent[x]);
	        }
	        return parent[x];
	    }
	    

	    

	    void union(int x, int y)
	    {
	        int xRoot = find(x), yRoot = find(y);
	        if (xRoot == yRoot)
	            return;
	        if (rank[xRoot] < rank[yRoot])
	            parent[xRoot] = yRoot;
	        else if (rank[yRoot] < rank[xRoot])
	         parent[yRoot] = xRoot;
	        else 

	        {
	         parent[yRoot] = xRoot;
	            rank[xRoot] = rank[xRoot] + 1;
	        }
	        




	    }
	    
	    int connectedComponents()
	    {
	    	int cnt=0;
	    	for(int i=0;i<n;i++)
	    	{
	    		if(parent[i]==i)
	    			cnt++;
	    	}
	    	return cnt;
	    }
	 }

	 

	 
	 
	static class Graph
	  {
	        int v;
	        ArrayList<Integer> list[];
	        Graph(int v)
	        {
	            this.v=v;
	            list=new ArrayList[v+1];
	            for(int i=1;i<=v;i++)
	                list[i]=new ArrayList<Integer>();
	        }
	        void addEdge(int a, int b)
	        {
	            this.list[a].add(b);
	        }
	    }
	
	
	




































































	static double sum[];
	static long cnt;






































	
	
	  
	 static class Pair implements Comparable<Pair>
	    {
	       int x;
	       int y;
	       Pair(int x,int y)
	        {
	           this.x=x;
	           this.y=y;
	          
	        }
		@Override
		public int compareTo(Pair o) {
			

			return this.x-o.x;
		}
	       
	       
	       
	    }
	   
	static long sum_array(int a[])
	 {
	    int n=a.length;
	    long sum=0;
	    for(int i=0;i<n;i++)
	     sum+=a[i];
	    return sum;
	 }
	static long sum_array(long a[])
	 {
	    int n=a.length;
	    long sum=0;
	    for(int i=0;i<n;i++)
	     sum+=a[i];
	    return sum;
	 }

	 static void sort(int[] a) 
	   {
			ArrayList<Integer> l=new ArrayList<>();
			for (int i:a) l.add(i);
			Collections.sort(l);
			for (int i=0; i<a.length; i++) a[i]=l.get(i);
		}
	static void sort(long[] a) 
	   {
			ArrayList<Long> l=new ArrayList<>();
			for (long i:a) l.add(i);
			Collections.sort(l);
			for (int i=0; i<a.length; i++) a[i]=l.get(i);
		}

	static void reverse_array(int a[])
	 {
	    int n=a.length;
	    int i,t; 
	    for (i = 0; i < n / 2; i++) { 
	            t = a[i]; 
	            a[i] = a[n - i - 1]; 
	            a[n - i - 1] = t; 
	        } 
	 }
	static void reverse_array(long a[])
	 {
	    int n=a.length;
	    int i; long t; 
	    for (i = 0; i < n / 2; i++) { 
	            t = a[i]; 
	            a[i] = a[n - i - 1]; 
	            a[n - i - 1] = t; 
	        } 
	 }














	static long power(long x, long y)
	 {
	   long res = 1;
	   x = x % mod;
	   if (x == 0)
	     return 0;
	   while (y > 0)
	   {
	    if ((y & 1) != 0)
	    res = (res * x) % mod;
	   
	    y = y >> 1; 

	    x = (x * x) % mod;
	   }
	   return res;
	 }
	static int power(int x, int y)
	{
		int res = 1;
		x = x % mod;
		if (x == 0)
			return 0;
		while (y > 0)
		{
			if ((y & 1) != 0)
				res = (res * x) % mod;
			
			y = y >> 1; 

	    x = (x * x) % mod;
		}
		return res;
	}
	static long gcd(long a, long b) 
	    { 
			
	        if (a == 0) 
	            return b; 
	         

	        return gcd(b%a,a); 
	    } 
	static int gcd(int a, int b) 
	    { 
	        if (a == 0) 
	            return b; 
	          
	        return gcd(b%a, a); 
	    } 

	   static class FastReader{
	 
	        byte[] buf = new byte[2048];
	        int index, total;
	        InputStream in;
	 
	        FastReader(InputStream is) {
	            in = is;
	        }
	 
	        int scan() throws IOException {
	            if (index >= total) {
	                index = 0;
	                total = in.read(buf);
	                if (total <= 0) {
	                    return -1;
	                }
	            }
	            return buf[index++];
	        }
	 
	        String next() throws IOException {
	            int c;
	            for (c = scan(); c <= 32; c = scan());
	            StringBuilder sb = new StringBuilder();
	            for (; c > 32; c = scan()) {
	                sb.append((char) c);
	            }
	            return sb.toString();
	        }
	 
	        int nextInt() throws IOException {
	            int c, val = 0;
	            for (c = scan(); c <= 32; c = scan());
	            boolean neg = c == '-';
	            if (c == '-' || c == '+') {
	                c = scan();
	            }
	            for (; c >= '0' && c <= '9'; c = scan()) {
	                val = (val << 3) + (val << 1) + (c & 15);
	            }
	            return neg ? -val : val;
	        }
	 
	        long nextLong() throws IOException {
	            int c;
	            long val = 0;
	            for (c = scan(); c <= 32; c = scan());
	            boolean neg = c == '-';
	            if (c == '-' || c == '+') {
	                c = scan();
	            }
	            for (; c >= '0' && c <= '9'; c = scan()) {
	                val = (val << 3) + (val << 1) + (c & 15);
	            }
	            return neg ? -val : val;
	        }
	    }
	   
	    static class Reader 
	    { 
	        final private int BUFFER_SIZE = 1 << 16; 
	        private DataInputStream din; 
	        private byte[] buffer; 
	        private int bufferPointer, bytesRead; 
	  
	        public Reader() 
	        { 
	            din = new DataInputStream(System.in); 
	            buffer = new byte[BUFFER_SIZE]; 
	            bufferPointer = bytesRead = 0; 
	        } 
	  
	        public Reader(String file_name) throws IOException 
	        { 
	            din = new DataInputStream(new FileInputStream(file_name)); 
	            buffer = new byte[BUFFER_SIZE]; 
	            bufferPointer = bytesRead = 0; 
	        } 
	  
	        public String readLine() throws IOException 
	        { 
	            byte[] buf = new byte[64]; 

	            int cnt = 0, c; 
	            while ((c = read()) != -1) 
	            { 
	                if (c == '\n') 
	                    break; 
	                buf[cnt++] = (byte) c; 
	            } 
	            return new String(buf, 0, cnt); 
	        } 
	  
	        public int nextInt() throws IOException 
	        { 
	            int ret = 0; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	            do
	            { 
	                ret = ret * 10 + c - '0'; 
	            }  while ((c = read()) >= '0' && c <= '9'); 
	  
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        public long nextLong() throws IOException 
	        { 
	            long ret = 0; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	            do { 
	                ret = ret * 10 + c - '0'; 
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        public double nextDouble() throws IOException 
	        { 
	            double ret = 0, div = 1; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	  
	            do { 
	                ret = ret * 10 + c - '0'; 
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
	  
	            if (c == '.') 
	            { 
	                while ((c = read()) >= '0' && c <= '9') 
	                { 
	                    ret += (c - '0') / (div *= 10); 
	                } 
	            } 
	  
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        private void fillBuffer() throws IOException 
	        { 
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
	            if (bytesRead == -1) 
	                buffer[0] = -1; 
	        } 
	  
	        private byte read() throws IOException 
	        { 
	            if (bufferPointer == bytesRead) 
	                fillBuffer(); 
	            return buffer[bufferPointer++]; 
	        } 
	  
	        public void close() throws IOException 
	        { 
	            if (din == null) 
	                return; 
	            din.close(); 
	        } 
	    }
	  static  PrintWriter out=new PrintWriter(System.out);
	  static int int_max=Integer.MAX_VALUE;
	  static int int_min=Integer.MIN_VALUE;
	  static long long_max=Long.MAX_VALUE;
	  static long long_min=Long.MIN_VALUE;

}




