


import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;






public class id1 {
	static int mod=(int)1e9+7;
	
		

	   static FastReader sc=new FastReader(System.in);
	 
	
	public static void main(String[] args) throws IOException {
		

		

			
			
		int t=sc.nextInt();
		while(t-->0)
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
			
			out.flush();
			out.close();
			System.gc();
	
	}
	
	
	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	static void swap(int arr[],int i,int j)
	{
		int temp=arr[i];
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
	
	static boolean check(char arr[][], int i,int j)
	{
		int cnt=0;
		for(int k=i;k<i+2;k++)
		{
			for(int l=j;l<j+2;l++)
			{
				if(arr[k][l]=='
					cnt++;
			}
		}
		
		if(cnt!=2)
			return true;
		return false;
		
		
	}
	
	static void flag(boolean flag)
	   {
	       out.println(flag ? "YES" : "NO");
	       out.flush();
	   }
	   
	static ArrayList<Long> luckNums;
	static void id2(long x,long p10)
	{
		luckNums.add(x);
		if(x>(long)1e10)
			return;
		id2(x+4*p10, p10*10);
		id2(x+7*p10, p10*10);
		
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
	
	
	  
	 static class Pair
	    {
	       int x,y;
	       Pair(int x,int y)
	        {
	           this.x=x;
	           this.y=y;
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
	 static long modInverse(long a, long m)
		    {
		        long g = gcd(a, m);
		       
		          return   power(a, m - 2, m);
		        
		    }
	static long power(long x, long y, long m)
		    {
		        if (y == 0)
		            return 1;
		        long p = power(x, y / 2, m) % m;
		        p = (int)((p * (long)p) % m);
		        if (y % 2 == 0)
		            return p;
		        else
		            return (int)((x * (long)p) % m);
		    }
	static long gcd(long a, long b) 
	    { 
	        if (a == 0) 
	            return b; 
	          
	        return gcd(b%a, a); 
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




