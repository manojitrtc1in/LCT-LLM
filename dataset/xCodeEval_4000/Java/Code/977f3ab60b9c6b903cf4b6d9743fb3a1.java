import java.io.*;
import java.util.*;

public class Practice
{


	static int mod=1000000007;
	static final int size=1001;
	static FastReader sc=new FastReader(System.in);


	static  PrintWriter out=new PrintWriter(System.out);
	static long[] factorialNumInverse;
	static long[] naturalNumInverse;	
	static long[] fact;
	public static void main(String[] args) throws IOException
	{
















		int t=1;
		t=sc.nextInt();
		while(t-->0)
		{
			solve();


		}


		out.close();
		out.flush();
	}
	static void solve() throws IOException
	{
		int n=sc.nextInt(),m=sc.nextInt();
		int arr[][]=new int[n][m];
		TreeMap<Integer,Integer> map=new TreeMap<Integer, Integer>();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				arr[i][j]=sc.nextInt();
				map.put(arr[i][j], map.getOrDefault(arr[i][j], 0)+1);
			}
		

		int pos[][]=new int[n][m];
		int i=0,j=0;
		



		HashMap<Integer,TreeMap<Integer,Stack<Integer>>> lastpos=new HashMap<Integer, TreeMap<Integer,Stack<Integer>>>();
		for(Map.Entry<Integer, Integer> e: map.entrySet())
		{
			int count=e.getValue();
			while(count-->0)
			{
				pos[i][j]=e.getKey();
				j++;
				if(j==m)
				{
					j=0;
					i++;
				}
			}
			lastpos.put(e.getKey(), new TreeMap<Integer, Stack<Integer>>());
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				lastpos.get(pos[i][j]).putIfAbsent(i, new Stack<Integer>());
				lastpos.get(pos[i][j]).get(i).push(j);
			}
		}


		long ans=0;
		segment s=new segment(n*m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int sight=arr[i][j];
				Map.Entry<Integer, Stack<Integer>> position=lastpos.get(sight).firstEntry();
				int col=position.getValue().pop();




				ans+=s.find(position.getKey()*m, position.getKey()*m+col);
				s.doUP(position.getKey()*m+col);
				if(position.getValue().isEmpty())
					lastpos.get(sight).remove(position.getKey());
			}
		}
		out.println(ans);
	}
	static class segment
	{
		public int st[];
		private int n;
		segment(int size)
		{
			n=1<<(int)Math.ceil(Math.log(size)/Math.log(2));
			st=new int[n<<1];
		}
		void doUP(int index)
		{
			update(1, 0, n-1,index);
		}
		int find(int start,int end)
		{
			return query(1, 0, n-1, start, end);
		}
		void update(int v,int vl,int vr,int x)
		{
			if(x<vl || x>vr)
				return;
			if(vl==x && vr==x)
				st[v]=1;
			else
			{
				int mid=(vl+vr)>>1;
				update(v<<1, vl, mid,x);
				update((v<<1)|1, mid+1,vr,x);				
				st[v]=st[v<<1]+st[(v<<1)|1];
			}
		}
		int query(int v,int vl,int vr,int l,int r)
		{
			if(vl>r || vr<l)
				return 0;
			if(vl==l && vr==l)
				return st[v];
			else
			{
				int mid=(vl+vr)>>1;
				return query(v<<1, vl, mid, l, Math.min(r, mid))+query((v<<1)|1, mid+1, vr, Math.max(l, mid+1), r);
			}
		}
		void printSegment()
		{
			for(int i=0;i<n;i++)
				out.print(st[i]+" ");
			out.println();
		}
	}
	static class Pair implements Cloneable
	{
		int x,y;
		Pair(int a,int b)
		{
			this.x=a;
			this.y=b;
		}
		@Override
		public String toString() 
		{
			return "("+x+","+(y)+")";
		}
		@Override
		protected Pair clone() throws CloneNotSupportedException {
			return new Pair(this.x,this.y);
		}
	}
	static class Tuple implements Cloneable
	{
		int x,y,z;
		Tuple(int a,int b,int c)
		{
			this.x=a;
			this.y=b;
			this.z=c;
		}
		@Override
		public String toString() 
		{
			return "("+x+","+y+","+z+")";
		}
		@Override
		protected Tuple clone() throws CloneNotSupportedException {
			return new Tuple(this.x,this.y,this.z);
		}
	}
	static void arraySort(int arr[])
	{
		ArrayList<Integer> a=new ArrayList<Integer>();
		for (int i = 0; i < arr.length; i++) {
			a.add(arr[i]);
		}
		Collections.sort(a);
		for (int i = 0; i < arr.length; i++) {
			arr[i]=a.get(i);
		}
	}
	static void arraySort(long arr[])
	{
		ArrayList<Long> a=new ArrayList<Long>();
		for (int i = 0; i < arr.length; i++) {
			a.add(arr[i]);
		}
		Collections.sort(a);
		for (int i = 0; i < arr.length; i++) {
			arr[i]=a.get(i);
		}
	}
	public static void InverseofNumber(int p)
	{
	    naturalNumInverse[0] = naturalNumInverse[1] = 1;
	    for(int i = 2; i < size; i++)
	        naturalNumInverse[i] = naturalNumInverse[p % i] * (long)(p - p / i) % p;
	}
	

	public static void InverseofFactorial(int p)
	{
	    factorialNumInverse[0] = factorialNumInverse[1] = 1;
	    

	    for(int i = 2; i < size; i++)
	        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
	}
	

	public static void factorial(int p)
	{
	    fact[0] = 1;
	    for(int i = 1; i < size; i++)
	        fact[i] = (fact[i - 1] * (long)i) % p;
	}
	 
	

	public static long Binomial(int N, int R, int p)
	{
	     
	    

	    long ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
	     
	    return ans;
	}
	static int findXOR(int x)	

	{
		if(x<0)
			return 0;
		if(x%4==0)
			return x;
		if(x%4==1)
			return 1;
		if(x%4==2)
			return x+1;
		return 0;
	}
	static boolean isPrime(long x)
	{
		if(x==1)
			return false;
		if(x<=3)
			return true;
		if(x%2==0 || x%3==0)
			return false;
		for(int i=5;i<=Math.sqrt(x);i+=2)
			if(x%i==0)
				return false;
		return true;
	}
	static long gcd(long a,long b)
	{
		return (b==0)?a:gcd(b,a%b);
	}
	static int gcd(int a,int b)
	{
		return (b==0)?a:gcd(b,a%b);
	}
	static class UnionFind
	{
		  private int size;
		  private int[] sz;
		  private int[] parent;
		  private int numComponents;
		  public UnionFind(int size) 
		  {
		    if (size <= 0) throw new IllegalArgumentException("Size <= 0 is not allowed");
		    this.size = numComponents = size;
		    sz = new int[size];
		    parent = new int[size];
		    for (int i = 0; i < size; i++) 
		    {
		      parent[i] = i; 									

		      sz[i] = 1;								

		    }
		  }
		  public int find(int p) 
		  {
		    int root = p;
		    while (root != parent[root])
		    	root = parent[root];
		    while (p != root)
		    {
		      int next = parent[p];
		      parent[p] = root;
		      p = next;
		    }
		    return root;
		  }
		  public void makeParent(int p,int u)
		  {
			  parent[p]=u;
		  }
		  public boolean isConnected(int p, int q) 
		  {
		    return find(p) == find(q);
		  }
		  public int componentSize(int x) 
		  {
		    return sz[find(x)];
		  }
		  public int size() 
		  {
		    return size;
		  }
		  public int components() 
		  {
		    return numComponents;
		  }
		  public void unify(int p, int q) 
		  {
		    int root1 = find(p);
		    int root2 = find(q);
		    if(root1==root2)
		    {
		    	return;
		    }
		    else if (sz[root1] < sz[root2]) 
		    {
		    	parent[root1] = root2;
		    	sz[root2] += sz[root1];
		    	sz[root1] = 0;
		  } 
		    else 
		    {
		    	parent[root2] = root1;
		    	sz[root1] += sz[root2];
		    	sz[root2] = 0;
		    }
		    numComponents--;
		  }
		  void calc()
		  {
			  for(int i=0;i<size;i++)
				  find(i);
			  
		  }
	}
	static class Node
	{
		int vertex,dp;
		ArrayList<Edge> adj;
		ArrayList<Node> parent;
		Node(int v)
		{
			vertex=v;
			adj=new ArrayList<Edge>();
			parent=new ArrayList<Node>();
			dp=0;
		}
		@Override
		public String toString() 
		{
			return vertex+" ";
		}
	}
	static class Edge
	{
		Node to;
		int cost;
		Edge(Node t,int c)
		{
			this.to=t;
			this.cost=c;
		}
		@Override
		public String toString() {
			return "("+to.vertex+","+cost+") ";
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
	static long binomialCoeff(long n, long k)
    {
        long res = 1;




        

        if (k > n - k)
            k = n - k;
 
        

        

        for (long i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
 
        return res;
    }
	static class FastReader
	{
        byte[] buf = new byte[2048];
        int index, total;
        InputStream in;
 
        FastReader(InputStream is) 
        {
            in = is;
        }
 
        int scan() throws IOException 
        {
            if (index >= total) {
                index = 0;
                total = in.read(buf);
                if (total <= 0) {
                    return -1;
                }
            }
            return buf[index++];
        }
 
        String next() throws IOException 
        {
            int c;
            for (c = scan(); c <= 32; c = scan());
            StringBuilder sb = new StringBuilder();
            for (; c > 32; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        int nextInt() throws IOException 
        {
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
 
        long nextLong() throws IOException 
        {
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
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
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
            } while ((c = read()) >= '0' && c <= '9');
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
            } while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
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
        public void printarray(int arr[])
        {
        	for (int i = 0; i < arr.length; i++)
				System.out.print(arr[i]+" ");
        	System.out.println();
        }
    }
}





































































