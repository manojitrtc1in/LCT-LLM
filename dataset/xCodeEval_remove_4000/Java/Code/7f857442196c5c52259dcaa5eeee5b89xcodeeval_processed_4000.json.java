import java.io.*;
import java.util.*;


public class Practice
{


	static int mod=1000000007;
	static int size=101;
	static FastReader sc=new FastReader(System.in);




	static  PrintWriter out=new PrintWriter(System.out);
	static long[] id3;
	static long[] id4;	
	static int[] sp;
	static long[] fact;
	static ArrayList<Integer> pr;
	public static void main(String[] args) throws IOException, CloneNotSupportedException
	{












		int t=1;
		t=sc.nextInt();
		for(int i=1;i<=t;i++)
			solve(i);
		out.close();
		out.flush();




	}
	static void solve(int CASENO) throws IOException, CloneNotSupportedException
	{
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		ArrayList<Integer> x=new ArrayList<Integer>();
		ArrayList<Integer> y=new ArrayList<Integer>();
		for(int i=0;i<n;i++)
			x.add(sc.nextInt());
		for(int i=0;i<m;i++)
			y.add(sc.nextInt());
		ArrayList<Pair> point=new ArrayList<Pair>();
		for(int i=0;i<k;i++)
			point.add(new Pair(sc.nextInt(),sc.nextInt()));
		Collections.sort(point,new Comparator<Pair>() {
			@Override
			public int compare(Practice.Pair o1, Practice.Pair o2) {
				return o1.x-o2.x;
			}
		});
		long ans=0;
		for(int i=0,pt=0;i<n-1;i++)
		{
			int st=x.get(i),end=x.get(i+1);
			while(pt<k && point.get(pt).x==st)
				pt++;
			long cnt=0;
			HashMap<Integer,Integer> map=new HashMap<Integer, Integer>();
			while(pt<k && point.get(pt).x>st && point.get(pt).x<end)
			{
				map.put(point.get(pt).y, map.getOrDefault(point.get(pt).y, 0)+1);
				cnt++;
				pt++;
			}
			ans+=cnt*cnt;
			for(int v: map.keySet())
				ans-=map.get(v)*1L*map.get(v);
			if(pt==k)
				break;
		}
		Collections.sort(point,new Comparator<Pair>() {
			@Override
			public int compare(Practice.Pair o1, Practice.Pair o2) {
				return o1.y-o2.y;
			}
		});
		for(int i=0,pt=0;i<m-1;i++)
		{
			int st=y.get(i),end=y.get(i+1);
			while(pt<k && point.get(pt).y==st)
				pt++;
			long cnt=0;
			HashMap<Integer,Integer> map=new HashMap<Integer, Integer>();
			while(pt<k && point.get(pt).y>st && point.get(pt).y<end)
			{
				map.put(point.get(pt).x, map.getOrDefault(point.get(pt).x, 0)+1);
				cnt++;
				pt++;
			}
			ans+=cnt*cnt;
			for(int v: map.keySet())
				ans-=map.get(v)*1L*map.get(v);
			if(pt==k)
				break;
		}
		out.println(ans>>1);	
	}
	static class Pair implements Cloneable, Comparable<Pair>
	{
		int x,y;
		Pair(int a,int b)
		{
			this.x=a;
			this.y=b;
		}
		@Override
		public boolean equals(Object obj) 
		{
			if(obj instanceof  Pair)
			{
				Pair p=(Pair)obj;
				return p.x==this.x && p.y==this.y;
			}
			return false;
		}
		@Override
		public int hashCode() 
		{
			return (int)Math.abs(x)+500*Math.abs(y);
		}
		@Override
		public String toString() 
		{
			return "("+x+" "+y+")";
		}
		@Override
		protected Pair clone() throws CloneNotSupportedException {
			return new Pair(this.x,this.y);
		}
		@Override
		public int compareTo(Pair a)
		{
			long t=(this.x-a.x);
			if(t!=0)
				return t>0?1:-1;
			else
				return (int)(this.y-a.y);
		}
		public void swap()
		{
			this.y=this.y+this.x;
			this.x=this.y-this.x;
			this.y=this.y-this.x;			
		}
	}
	static class Tuple implements Cloneable, Comparable<Tuple>
	{
		int x,y,z;
		Tuple(int a,int b,int c)
		{
			this.x=a;
			this.y=b;
			this.z=c;
		}
		public boolean equals(Object obj) 
		{
			if(obj instanceof  Tuple)
			{
				Tuple p=(Tuple)obj;
				return p.x==this.x && p.y==this.y && p.z==this.z;
			}
			return false;
		}
		@Override
		public int hashCode() 
		{
			return (this.x+501*this.y);
		}
		@Override
		public String toString() 
		{
			return "("+x+","+y+" "+z+")";
		}
		@Override
		protected Tuple clone() throws CloneNotSupportedException {
			return new Tuple(this.x,this.y,this.z);
		}
		@Override
		public int compareTo(Tuple a) 
		{
			int x=this.y-a.y;
			if(x!=0)
				return x;
			int X= this.x-a.x;
			return X;
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
	static HashSet<Integer> primeFactors(int n)
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
	static ArrayList<Integer> id2(int n)
	{
		ArrayList<Integer> ans=new ArrayList<Integer>();
		for(int i=1;i*i<=n;i++)
		{			
			ans.add(i);
			if(n!=i*i)
				ans.add(n/i);				
			
		}
		return ans;
	}
	static class id8{
		int n;
		int[][]dp;
		int log2[];
		int P;
		void buildTable(int[] arr)
		{
			n=arr.length;
			P=(int)Math.floor(Math.log(n)/Math.log(2));
			
			log2=new int[n+1];
			log2[0]=log2[1]=0;
			for(int i=2;i<=n;i++)
				log2[i]=log2[i/2]+1;
			
			
			dp=new int[P+1][n];
			for(int i=0;i<n;i++)
				dp[0][i]=arr[i];
			
			for(int p=1;p<=P;p++)
			{
				for(int i=0;i+(1<<p)<=n;i++)
				{
					int left=dp[p-1][i];
					int right=dp[p-1][i+(1<<(p-1))];
					dp[p][i]=Math.min(left, right);
				}
			}
		}
		int maxQuery(int l,int r)
		{
			int len=r-l+1;
			int p=(int)Math.floor(log2[len]);
			int left=dp[p][l];
			int right=dp[p][r-(1<<p)+1];
			return Math.min(left,right);
		}
	}
	static void id1()
	{
		sp=new int[size];
		pr=new ArrayList<Integer>();
		for (int i=2; i<size; ++i) {
		    if (sp[i] == 0) {
		        sp[i] = i;
		        pr.add(i);
		    }
		    for (int j=0; j<(int)pr.size() && pr.get(j)<=sp[i] && i*pr.get(j)<size; ++j)
		        sp[i * pr.get(j)] = pr.get(j);
		}
	}
	public static void id0(int p)
	{
		id4=new long[size];
	    id4[0] = id4[1] = 1;
	    for(int i = 2; i < size; i++)
	        id4[i] = id4[p % i] * (long)(p - p / i) % p;
	}
	

	public static void id5(int p)
	{
		id3=new long[size];
	    id3[0] = id3[1] = 1;
	    

	    for(int i = 2; i < size; i++)
	        id3[i] = (id4[i] * id3[i - 1]) % p;
	}
	

	public static void factorial(int p)
	{
		fact=new long[size];
	    fact[0] = 1;
	    for(int i = 1; i < size; i++)
	        fact[i] = (fact[i - 1] * (long)i) % p;
	}
	 
	

	public static long Binomial(int N, int R)
	{
		if(R<0)
			return 1;
	    

	    long ans = ((fact[N] * id3[R]) % mod * id3[N - R]) % mod;
	    return ans;
	}
	static int id6(int x)	

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
	static class Node
	{
		int vertex,ind;
		ArrayList<Node> adj;
		Node(int ver)
		{
			vertex=ver;
			ind=0;
			adj=new ArrayList<Node>();
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
		if(x<=0)
			return 1;
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
	    return res%mod;
	  }
	static long id7(long n, long k)
    {
		if(n<k)
			return 0;
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
        public void printarray(int arr[])
        {
        	for (int i = 0; i < arr.length; i++)
				System.out.print(arr[i]+" ");
        	System.out.println();
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






