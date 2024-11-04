


import java.io.*;
import java.util.*;




public class id1 {
	static int mod=(int)1e9+7;
	


	static FastReader sc=new FastReader(System.in);
	static int[] sp;
	static int size=(int)1e6;
	public static void main(String[] args) throws IOException {
		long tc=sc.nextLong();




			




			while(tc-->0)
			{
				

				
				int n=sc.nextInt();
				int arr[]=new int[n];
				HashSet<Integer> ans=new HashSet<Integer>();
				for(int i=0;i<n;i++)
				{
					arr[i]=sc.nextInt();
					ans.add(i+1);
				}
				int c[]=new int[32];
				for(int i=0;i<n;i++)
				{
					int x=arr[i];
					for(int j=0;j<32;j++)
					{
						c[j]+=(x&1);
						x=x>>1;
					}
				}
				
				for(int i=0;i<32;i++)
				{
					if(c[i]==0) continue;
					HashSet<Integer> temp=factors(c[i]);
					ans.retainAll(temp);
				}
				ArrayList<Integer> a=new ArrayList<Integer>();
				for(int i: ans)
				a.add(i);
				Collections.sort(a);
				for(int i:a)
				out.print(i+" ");
				out.println();
				

				
			}
				
				
			
			
			out.flush();
			out.close();
			System.gc();
	
	}
	
	
	


	

	
	
	static HashSet<Integer> factors(int x)
	{
		HashSet<Integer> a=new HashSet<Integer>();
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				a.add(i);
				a.add(x/i);
			}
		}
		return a;
	}

	
static class Node
{
	int vertex;
	HashSet<Node> adj;
	boolean rem;
	Node(int ver)
	{
		vertex=ver;
		rem=false;
		adj=new HashSet<Node>();
	}
	@Override
	public String toString()
	{
		return vertex+" ";
	}
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

	

	static HashSet<Integer> findFactors(int n)
	{
		HashSet<Integer> ans=new HashSet<Integer>();
		if(n%2==0)
		{
			ans.add(2);
			while((n&1)==0)
				n=n>>1;
		}
		for(int i=3;i*i<=n;i+=2)
		{
			if(n%i==0)
			{
				ans.add(i);
				while(n%i==0)
					n=n/i;
			}
		}
		if(n!=1)
			ans.add(n);
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

	
	
	
	
	
	

	static int id4(long n)
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
 
	
	
	static int id5(long n)
    {
        return (int)((Math.log10(n & -n)) / Math.log10(2)) + 1;
    }
	
	
	static ArrayList<Integer> primes;
	static HashSet<Integer> primeSet;
	static boolean prime[];
	static void id3(int n)
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
               primeSet.add(i);
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
	  
	static void id2(boolean condition)
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
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] >= x)
                h = mid - 1;
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
	 
	 
	 
	 static class id0
	 {
	    int[] rank, parent;
	    int n;
	    

	    public id0(int n)
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
	static void DFS(Graph g, boolean[] visited, int u)
		{
	        visited[u]=true;
	        
	        for(int i=0;i<g.list[u].size();i++)
	        {
	            int v=g.list[u].get(i);
	            
	            if(!visited[v])
	            {
	            	cnt=cnt*2;
	            	DFS(g, visited, v);
	            
	            }
	            
	        }
	       

	  } 
	
	
	  
	 static class Pair implements Comparable<Pair>
	    {
	       int x,y;
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




